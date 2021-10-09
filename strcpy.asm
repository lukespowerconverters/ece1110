.data
word1: .string "rachel"
word2: .string ""

.text
main:	la a0, word1	# Load address of ssource string into a0
	la a1, word2	# Load address of destination string into a1
	
# Iterate through each bit until full string is copied
loop:	lb t1, (a0)
	beqz t1, end	# Go to end if bit is 00 (termination value, end of source string)
	sb t1, (a1) 	# Store bit into memory
	addi a0,a0,1 	# Move to next bit
	addi a1,a1,1	
	jal loop	# Go to beginning of loop

end:	# strcpy completed
