Best Viewd in Raw form
---------------------------------------------The_Quick_Compiler-----------------------------------------

Group Members : Parag Adhau     ( paragadhau1803@gmail.com)
                Soham Kondalkar ( sohamk94@gmail.com)
             	Gaurav Madhuker
             
Our language : Quick can be said to a subset of C.
It supports :  
1.Including Macros and header files
2.Various function definations (every function should have a return type also function can return another function )
3.Global declarations of variables (all integeres intialised to 0 )
4.Nested looping (we have implemented the same for loop as C )
5.Conditinal statements (if and if-else statements)
6.Passsing variables by values and reference
7.There are 2 supported data types = string ( char ) and integeres ( int )
8.Input-Output statements : quickin>>variable and quickout<<variable_or_complex_epression
9.Arrays are also supported (Only One-dimensional arrays are supported)


------------------------------------------------------------------------------------------------------------------
Work Flow
Input should be placed in input.txt in the semantic_done(2) folder.
After that run :
$flex quick.l
$bison quick.y -d -v
$g++ quick.tab.c lex.yy.cc -lfl -std=c++11
$./a.out



By running the above commands you just did the lexical and semantic checking and generated the three address code for 
your input file.If any error occurs then it will shown on the terminal.
Also we just built the syntax tree for the particular input. This tree can be viewed by calling the PreOrderTraversal 
function (by uncommenting 102nd line in the quick.y file) . The tree is self explanatory.

You have to make sure that you specify the correct path for the output TAC file (see the quick.y main function)

If all the things are correct then a input_mips.txt  file should be created in the mips folder.
Now goto the mips folder and run :
After that run :
$flex mips.l
$bison mips.y -d -v
$g++ mips.tab.c lex.yy.cc -lfl -std=c++11
$./a.out

---------------------------------------------------------------------------------------------------------------
Simulation : 
This should output the Mips code on the terminal.
You can run this mips code on a mips simulator. We used Qtspim. It can be found here : 
http://ecs-network.serv.pacific.edu/ecpe-170/tutorials/qtspim-tutorial
