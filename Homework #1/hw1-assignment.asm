# Creating data used for the program
.data
h:	.float 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
x:	.float 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
y:	.float 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0

# Set length values M, L, and Y
ML:	.word 10
LL:	.word 10
YL:	.word 20

# Quick variables for a comma and new line
comma:	.string ", "
cr:	.string "\n"

# Variable for 0 (as a float)
fzero:	.float 0.0
.text
main:	jal conv	# Jump to conv, send return address to ra
	mv t0, zero	# Set register t0 to 0
	lw t1, YL #t1 = 20	
	la t2, y	# Load address of y into register t2

# Function to print values of y[n]	
prloop:	bge t0, t1, done	# Branch to done if t0 >= t1
	slli t3, t0, 2		# Set register t3 to contents of t0 shifted left by 2
	add t4, t2, t3		# Set register t4 to (t2 + t3)
	flw fa0, 0(t4)		# Load float value from t4 with 0 offset into fa0
	li a7, 2		# Load 2 (2-bit immediate) into register a7
	ecall			# Prints double precision float in fa0
	la a0, comma		# Load address of comma into register a0
	li a7, 4		# Load 4 (3-bit immediate) into register a7
	ecall			# Prints string in a0
	addi t0, t0, 1		# Store (contents(t0) + 1) in register t0
	b prloop		# Branch to prloop
	
done:	la a0, cr		# Load address of cr (new line variable) into register a0
	li a7, 4		# Load 4 (3-bit immediate) into register a7
	ecall			# Prints string in a0
	li a7, 10		# Load 10 (4-bit immediate) into register a7
	ecall			# Exits the program with code 0

# Convolve function
conv:	lw a2, ML #a2 = M = 10
	lw a3, LL #a3 = L = 10
	add a4, a2, a3 #a4 = M + L = 20
	mv t0, zero # t0 = n	# Set register t0 to 0
	mv s0, ra		# Set register s0 to contents(ra)

# Outer loop	
testn:	bge t0, a4, donen #n < L + M
	mv t3, t0 #t3 = n	# Set register t3 to value of t0
	sub t3, t3, a3 #t3 = n-L
	addi a1, t3, 1 #a1 = n-L+1
	mv a0, zero #max = 0	# Set register a0 to 0
	jal max			# Jump to max, set return address to ra
	mv t1, a0 #t1 = m = max(0, n-L+1)
	la t5, fzero		# Set register t5 to the address of fzero
	flw f5, 0(t5)		# Load contents(t5) with 0 offset into register f5

# Inner loop	
testm:	# nop			# No operation (yet)
# insert your code here
	bgt t1, a0, donem #m <= min(n, M-1)
	mv t3, t1 #t3 = m
	addi a1, a2, -1 #a1 = M - 1
	mv a0, t0 #a0 = n	# Set register a0 to contents(t0)
	jal min #a0 = min(n, M-1)
	la s3, h		# Load base address of h into a3
	la s4, x		# Load base address of x into a4
	la s5, y		# Load base address of y into a5	
	jal functiony		# Jump to functiony, set ra
	addi t1, t1, 1 #t1 = m = m + 1
	j testm			# Jump to testm

# Body of the loop
functiony:
	# Get next value in array h, shift address based upon value of m
	slli s6, t3, 2	#a6 = m * 4
	add s3, s3, s6 #a3 = a3 + (m*4)
	flw ft0, 0(s3) #ft0 = h[m]
	# Get value in array x at index [n-m]
	sub t3, t0, t3 #t3 = n-m
	slli s6, t3, 2 #a6 = (n-m) * 4
	add s4, s4, s6 #a4 = a4 + ((n-m) * 4)
	flw ft1, 0(s4) #ft1 = x[n-m]
	
	fmul.s ft1, ft0, ft1 #ft1 = h[m] * x[n-m]
	# Get value in array y at index [n]
	slli s6, t0, 2 #a6 = n * 4
	add s5, s5, s6 #a5 = a5 + (n*4)
	flw ft0, 0(s5) #ft0 = y[n]
	fadd.s ft0, ft0, ft1 #ft0 = y[n] + (h[m] * x[n-m])
	fsw ft0, 0(s5) 		# Store new value in the array index y[n]
	ret			# Return to ra
	
donem:	addi t0, t0, 1	#t0 = n = n + 1
	j testn			# Jump to testn
	
donen:	mv ra, s0		# Set ra to contents(s0), returns to top of testn
	ret			# Return		

# min(a0, a1) returns min in a0
min:	bgt a0, a1, a1min	# Branch to a1min if a0 > a1
	ret			# Return
a1min:	mv a0, a1		# Set register a0 to contents(a1)
	ret			# Return

# max(a0, a1) returns max in a0
max:	blt a0, a1, a1max	# Branch to a1max if a0 < a1
	ret			# Return
a1max:	mv a0, a1		# Set register a0 to contents(a1)
	ret			# Return

