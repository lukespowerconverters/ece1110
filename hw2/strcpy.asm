# Source address in a0, destination address in a1

# Loop through string
beg:	# Get current character
	lb	t0, 0(a0)	# Load char from a0
	sb	t0, 0(a1)	# Store char in a1
	
	# Check for end of string
	beq	t0, zero, end	# Exit loop

	# Iterate to next char in string
	addi	a1, a1, 1	# Next byte in destination
	addi	a0, a0, 1	# Next char in source
	jal	zero, beg	# Go to beginning of loop
	
# Full string copied, return
end:	jalr	zero, 0(ra)	# Branch to ra