#
# Tiny Microassembler
#

import sys
import re
import getopt
import array
from enum import Enum

class TokenType(Enum):
    assign = 1
    id = 2
    label = 3
    int = 4
    string = 5
    comment = 6
    command = 7
    range = 8
    otherwise = 9

def s_assign(scanner, token): return (TokenType.assign, token)
def s_label(scanner, token): return (TokenType.label, token)
def s_command(scanner, token): return (TokenType.command, token)
def s_int(scanner, token): return (TokenType.int, int(token))
def s_range(scanner, token): return (TokenType.range, token)
def s_comment(scanner, token): return (TokenType.comment, token)
def s_string(scanner, token): return (TokenType.string, token)
def s_otherwise(scanner, token): return (TokenType.otherwise, token)
def s_id(scanner, token): return (TokenType.id, token)

expressions = re.Scanner([
    (r"\.[A-Za-z]+", s_command),
    (r"\w+\s*\=\s*\w+:\s*\w+", s_range),
    (r"\w+\s*\=\s*\w+", s_assign),
    (r"\w+:", s_label),
    (r"\w+", s_id),
    (r"\d+", s_int),
    (r"\s+", None),
    (r"(--|//).*?$", s_comment),
    (r"\/\*.+?\*\/", s_comment),
    (r'"(?:[^"\\]|\\.)*"', s_string),
    (r"'(?:[^'\\]|\\.)*'", s_string),
    (r"\$\$(?:[^\$\\]|\\.)*\$\$", s_string),
    (r"\n", s_otherwise),
    (r",", s_otherwise)
    ])

numeric = re.compile(r'\d+')

uPC = 0
uCode = array.array('Q')
fields = {}
names = {}
mode = None
linecount = 0
maxmsb = -1

def error(message):
    global linecount
    print(message, 'at line', linecount, file=sys.stderr)

def process_labels(tokens, linecount):
    global uPC, names
    for token in tokens:
        if token[0] == TokenType.assign:
                splitsville = token[1].split('=')
                if splitsville[0] == 'UBR':
                    uPC = uPC+1
        elif token[0] == TokenType.label:
                name = token[1].strip()
                names[name[:-1]] = uPC
        elif token[0] == TokenType.int: error('unexpected integer ' + token[1])
        elif token[0] == TokenType.string: error('unexpected string ' + token[1])
        else: pass
    return names

def print_labels():
    for name in names:
        print("    localparam %s = 8\'h%x;" % (name, names[name]))

def do_fields(left, right, linecount):
    if left in fields: error('already defined ' + left)
    else: fields[left] = right

def do_constant(left, right, linecount):
    if left in names: error('already defined ' + left)
    else: names[left] = int(right)

def bit(bitnumber, rhs):
    if rhs in names:
        bitvalue = names[rhs]
    elif isinstance(rhs, int):
        bitvalue = rhs
    elif numeric.match(rhs):
        bitvalue = int(rhs)
    else:
        error('constant name ' + rhs + ' not found')
        return 0
    return bitvalue << int(bitnumber)

def bitfield(bits, rhs):
    if rhs in names:
        bitvalue = names[rhs]
    elif type(rhs) is int: bitvalue = rhs
    else:
        error('constant name ' + rhs + ' not found')
        return 0
    splitsville = bits.split(':')
    msb = int(splitsville[0])
    lsb = int(splitsville[1])
    if len(bin(bitvalue)[:-2]) > (msb-lsb+1):
        error('bitfield ' + bits + ' is too small for ' + rhs)
    return bitvalue << lsb

def do_code(left, right, linecount):
    global uWord, maxmsb
    if left in fields:
        field = fields[left]
        msblsb = field.split(':')
        if len(msblsb) == 1: # single bit
            uWord |= bit(field, right)
        elif len(msblsb) == 2: # bit field
            uWord |= bitfield(field, right)
        else: error('strange bit field: ' + field)
    else: error('name ' + left + ' not found in assignment')

def process_again(tokens, linecount):
    global uPC, names, mode, uWord, uCode
    uWord = 0
    for token in tokens:
        if token[0] == TokenType.assign:
                splitsville = token[1].split('=')
                left = splitsville[0].strip()
                right = splitsville[1].strip()
                if mode == '.fields': do_fields(left, right, linecount)
                elif mode == '.constants': do_constant(left, right, linecount)
                elif mode == '.code': do_code(left, right, linecount)
                else: print('weirdness', mode)
        elif token[0] == TokenType.label: pass # been there, done that
        elif token[0] == TokenType.int: error('unexpected integer ' + token[1])
        elif token[0] == TokenType.string: error('unexpected string ' + token[1])
        elif token[0] == TokenType.command: mode = token[1]
        elif token[0] == TokenType.range:
                splitsville = token[1].split('=')
                left = splitsville[0].strip()
                right = splitsville[1].strip()
                if mode == '.fields': do_fields(left, right, linecount)
                else: error('unexpected range ' + left)
        elif token[0] == TokenType.otherwise: pass
        elif token[0] == TokenType.id: error('unexpected id ' + token[1])
        else: pass # probably a comment
    if (mode == ".code") & (uWord != 0):
        uCode.append(uWord)
        print('%010x' % uWord)
        uWord = 0

def readlines(f, fn):
    global linecount
    linecount = 0
    try:
        while True:
            line = next(f)
            linecount = linecount+1
            token = expressions.scan(line.strip())
            if len(token[0]) != 0:
                fn(token[0], linecount)
    except StopIteration:
        pass

def rewind(f):
    f.seek(0)

def usage():
    print('Usage:\t', sys.argv[0], 'filename -hod')
    sys.exit(1)

def main(filename):
    try:
        opts, args = getopt.getopt(sys.argv[1:], "hdo:v", ["help", "output="])
    except getopt.GetoptError as err:
        print('unrecognized option')
        usage()
        sys.exit(2)
    output = None
    verbose = False
    dmode = False
    for x, a in opts:
        if x == "-v":
            verbose = True
        elif x in ("-h", "--help"):
            usage()
            sys.exit()
        elif x in ("-o", "--output"):
            output = a
        elif x in ("-d", "--dispatch"):
            dmode = True
        else:
            assert False, "unhandled option"
    with open(filename) as f:
        readlines(f, process_labels)
        rewind(f)
        if dmode:
            print_labels()
        else:
            readlines(f, process_again)
    print(uPC, 'words long', file=sys.stderr)

if __name__ == "__main__":
    if len(sys.argv) > 1:
        main(sys.argv[-1])
    else:
        usage()
