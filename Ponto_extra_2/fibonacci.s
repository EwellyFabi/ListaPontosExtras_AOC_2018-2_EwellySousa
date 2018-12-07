#Title:	Fibonacci									Filename: 
#Author: Ewelly Sousa								Date: 29/08/2018
#Description: O programa recebe um valor e retorna o fibonacci equivalente ao número
#Input: integer
#Output: integer

######################## Data segment ##################
.data
prompt:		.ascii "Digite um valor: "


######################## Code segment ##################
.text
.globl main
main:

	la $a0,prompt	#display prompt string
	li $v0,4
	syscall

	li $v0, 5		#read integer
	syscall
	
	move $a0, $v0
	jal fibo		#call funct fact
	
	move $a0, $a1
	
	li $v0, 1		#print integer
	syscall
	
	li	 $v0,10		#exit
	syscall


	fibo: 	bne		$a0,1,salto1
			li		$v0,0						# $v0 = 1
			move 	$a1, $v0
			jr		$ra							# return to caller
			
	salto1:	bne		$a0,2,salto2
			li		$v0,1
			move 	$a1, $v0
			jr		$ra


	salto2:	addiu 	$s1,$0,1          			# atribui 1 ao register $s1
			add		$s0,$0,$0					# atribui 0 ao register $s2
			add		$a1,$0,$0					# atribui 0 ao register $a1
			add		$t1,$0,1					# atribui 2 ao register $t1
	
	fib:	add		$a1,$s1,$s0			 
			move	$s0,$s1
			move	$s1,$a1
			addi	$t1,$t1,1
			bne		$t1,$a0,fib
			
			jr		$ra	
						
					
	

