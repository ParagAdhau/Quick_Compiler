.data  # Tells assembler we're in the data segment
space: .asciiz "\n " 
a : .word  0
aaaa : .word  0
aaaab : .word  0
ab : .word  0
e : .word  0
eb : .word  0
i : .word  0
je : .word  0
mn : .word  0
mnn : .word  0
mnnn : .word  0
p : .word  0
temp1 : .word  0
temp10 : .word  0
temp11 : .word  0
temp12 : .word  0
temp13 : .word  0
temp14 : .word  0
temp15 : .word  0
temp16 : .word  0
temp17 : .word  0
temp18 : .word  0
temp19 : .word  0
temp2 : .word  0
temp20 : .word  0
temp21 : .word  0
temp22 : .word  0
temp23 : .word  0
temp24 : .word  0
temp25 : .word  0
temp26 : .word  0
temp27 : .word  0
temp28 : .word  0
temp29 : .word  0
temp3 : .word  0
temp30 : .word  0
temp31 : .word  0
temp32 : .word  0
temp33 : .word  0
temp34 : .word  0
temp35 : .word  0
temp36 : .word  0
temp37 : .word  0
temp38 : .word  0
temp39 : .word  0
temp4 : .word  0
temp40 : .word  0
temp41 : .word  0
temp42 : .word  0
temp43 : .word  0
temp44 : .word  0
temp45 : .word  0
temp46 : .word  0
temp47 : .word  0
temp48 : .word  0
temp49 : .word  0
temp5 : .word  0
temp50 : .word  0
temp6 : .word  0
temp7 : .word  0
temp8 : .word  0
temp9 : .word  0
v : .word  0
vvv : .word  0
x : .word  0
y : .word  0
z : .word  0
.text
main:
j end0
addfunc : 
addi $sp, $sp, -4 
sw $s0 , 0($sp) 
addi $sp, $sp, -4 
sw $t0 , 0($sp) 
addi $sp, $sp, -4 
sw $t1 , 0($sp) 
addi $sp, $sp, -4 
sw $t2 , 0($sp) 

lw $s0, 24($sp) 
sw $s0 a

lw $s0, 20($sp) 
sw $s0 e

lw $s0 a
sw $s0 temp1

lw $s0 e
sw $s0 temp2

lw $s0 , temp1
lw $t0 , temp2
add $s0 , $s0 , $t0
sw $s0 temp3

lw $s0 temp3
sw $s0 aaaa

lw $t1 , aaaa
move $v0 , $t1 
lw $s0 , 0($sp) 
addi $sp, $sp, 4 
lw $t0 , 0($sp) 
addi $sp, $sp, 4 
lw $t1 , 0($sp) 
addi $sp, $sp, 4 
lw $t2 , 0($sp) 
addi $sp, $sp, 4 
jr $ra 

end0 :

j end1
addfunction : 
addi $sp, $sp, -4 
sw $s0 , 0($sp) 
addi $sp, $sp, -4 
sw $t0 , 0($sp) 
addi $sp, $sp, -4 
sw $t1 , 0($sp) 
addi $sp, $sp, -4 
sw $t2 , 0($sp) 

lw $s0, 28($sp) 
sw $s0 ab

lw $s0, 24($sp) 
sw $s0 eb

lw $s0, 20($sp) 
sw $s0 y

lw $s0 ab
sw $s0 temp7

lw $s0 eb
sw $s0 temp8

lw $s0 , temp7
lw $t0 , temp8
mul $s0 , $s0 , $t0
sw $s0 temp9

lw $s0 temp9
sw $s0 temp4

lw $s0 y
sw $s0 temp5

lw $s0 , temp4
lw $t0 , temp5
mul $s0 , $s0 , $t0
sw $s0 temp6

lw $s0 temp6
sw $s0 aaaab

lw $t1 , aaaab
move $v0 , $t1 
lw $s0 , 0($sp) 
addi $sp, $sp, 4 
lw $t0 , 0($sp) 
addi $sp, $sp, 4 
lw $t1 , 0($sp) 
addi $sp, $sp, 4 
lw $t2 , 0($sp) 
addi $sp, $sp, 4 
jr $ra 

end1 :

j end2
heythere : 
addi $sp, $sp, -4 
sw $s0 , 0($sp) 
addi $sp, $sp, -4 
sw $t0 , 0($sp) 
addi $sp, $sp, -4 
sw $t1 , 0($sp) 
addi $sp, $sp, -4 
sw $t2 , 0($sp) 

lw $s0, 28($sp) 
sw $s0 mn

lw $s0, 24($sp) 
sw $s0 mnn

lw $s0, 20($sp) 
sw $s0 mnnn

lw $s0 mn
sw $s0 temp16

lw $s0 mnn
sw $s0 temp17

lw $s0 , temp16
lw $t0 , temp17
add $s0 , $s0 , $t0
sw $s0 temp18

lw $s0 temp18
sw $s0 temp13

lw $s0 mnnn
sw $s0 temp14

lw $s0 , temp13
lw $t0 , temp14
add $s0 , $s0 , $t0
sw $s0 temp15

lw $s0 temp15
sw $s0 temp10

li $s0 1
sw $s0 temp19

lw $s0 , temp19
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 2
sw $s0 temp20

lw $s0 , temp20
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 2
sw $s0 temp21

lw $s0 , temp21
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

addi $sp, $sp, -4 
sw $ra , 0($sp) 
jal addfunction
move	$s0 , $v0 
lw $ra , 0($sp) 
addi $sp, $sp, 4 
move	$s0 , $v0 
sw $s0 temp22
addi $sp, $sp, 12

lw $s0 temp22
sw $s0 temp11

lw $s0 , temp10
lw $t0 , temp11
add $s0 , $s0 , $t0
sw $s0 temp12

lw $s0 temp12
sw $s0 vvv

lw $t1 , vvv
move $v0 , $t1 
lw $s0 , 0($sp) 
addi $sp, $sp, 4 
lw $t0 , 0($sp) 
addi $sp, $sp, 4 
lw $t1 , 0($sp) 
addi $sp, $sp, 4 
lw $t2 , 0($sp) 
addi $sp, $sp, 4 
jr $ra 

end2 :



li $s0 20
sw $s0 temp23

lw $s0 temp23
sw $s0 x

li $s0 5
sw $s0 temp24

lw $s0 , temp24
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 1
sw $s0 temp25

lw $s0 , temp25
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

addi $sp, $sp, -4 
sw $ra , 0($sp) 
jal addfunc
move	$s0 , $v0 
lw $ra , 0($sp) 
addi $sp, $sp, 4 
move	$s0 , $v0 
sw $s0 temp26
addi $sp, $sp, 8

lw $s0 temp26
sw $s0 p

li $s0 4
sw $s0 temp27

lw $s0 , temp27
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 1
sw $s0 temp28

lw $s0 , temp28
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 7
sw $s0 temp29

lw $s0 , temp29
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

addi $sp, $sp, -4 
sw $ra , 0($sp) 
jal addfunction
move	$s0 , $v0 
lw $ra , 0($sp) 
addi $sp, $sp, 4 
move	$s0 , $v0 
sw $s0 temp30
addi $sp, $sp, 12

lw $s0 temp30
sw $s0 je

li $v0 , 1
lw $a0 , p
syscall 
addi $v0 , $zero , 4
la $a0 , space
syscall 

li $v0 , 1
lw $a0 , je
syscall 
addi $v0 , $zero , 4
la $a0 , space
syscall 

li $s0 0
sw $s0 temp31

lw $s0 temp31
sw $s0 i

Label1 : 

lw $s0 i
sw $s0 temp32

li $s0 7
sw $s0 temp35

lw $s0 temp35
sw $s0 temp33

lw $s0 , temp32
lw $t0 , temp33
slt $s0 , $s0 , $t0
sw $s0 temp34

lw $s0 , temp34
li $t3 , 1
li $t2 , 1
beq $t3 , $s0 , Label2
j Label3

Label2 : 
li $v0 , 1
lw $a0 , i
syscall 
addi $v0 , $zero , 4
la $a0 , space
syscall 

li $s0 1
sw $s0 temp36

lw $s0 , i
lw $t0 , temp36
add $s0 , $s0 , $t0
sw $s0 i

j Label1

Label3 : 
li $s0 4
sw $s0 temp40

lw $s0 , temp40
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 1
sw $s0 temp41

lw $s0 , temp41
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 7
sw $s0 temp42

lw $s0 , temp42
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

addi $sp, $sp, -4 
sw $ra , 0($sp) 
jal addfunction
move	$s0 , $v0 
lw $ra , 0($sp) 
addi $sp, $sp, 4 
move	$s0 , $v0 
sw $s0 temp43
addi $sp, $sp, 12

lw $s0 temp43
sw $s0 temp37

li $s0 5
sw $s0 temp44

lw $s0 , temp44
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 1
sw $s0 temp45

lw $s0 , temp45
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

addi $sp, $sp, -4 
sw $ra , 0($sp) 
jal addfunc
move	$s0 , $v0 
lw $ra , 0($sp) 
addi $sp, $sp, 4 
move	$s0 , $v0 
sw $s0 temp46
addi $sp, $sp, 8

lw $s0 temp46
sw $s0 temp38

lw $s0 , temp37
lw $t0 , temp38
mul $s0 , $s0 , $t0
sw $s0 temp39

li $v0 , 1
lw $a0 , temp39
syscall 
addi $v0 , $zero , 4
la $a0 , space
syscall 

li $s0 4
sw $s0 temp47

lw $s0 , temp47
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 5
sw $s0 temp48

lw $s0 , temp48
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

li $s0 6
sw $s0 temp49

lw $s0 , temp49
addi $sp, $sp, -4 
sw $s0 , 0($sp) 

addi $sp, $sp, -4 
sw $ra , 0($sp) 
jal heythere
move	$s0 , $v0 
lw $ra , 0($sp) 
addi $sp, $sp, 4 
move	$s0 , $v0 
sw $s0 temp50
addi $sp, $sp, 12

li $v0 , 1
lw $a0 , temp50
syscall 
addi $v0 , $zero , 4
la $a0 , space
syscall 

jr $ra
