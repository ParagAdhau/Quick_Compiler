%{

#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

#include <string>
using namespace std;
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int yylineno ;
void yyerror(const char *  error_message ); 
map <string , int > Table;

static int counter, temp, counter1;
//extern char *yytext ;
bool Table_check(string name);
int return_entry(string name);
bool parse(string name);
%}

%union 
{
	double NUMBERR;
	//char CHARACTER;
	char *  STRINGG;
	//struct Syntax_Tree * parag;
	//class Tree * node;
	//bool BOOLL;
}

%token  OP N LE GE OB CB EE C GOTO IF FALSE  FUNC  BEGIN1 PARAM RETURN CALL COMMA  END  RECIEVEPARAM  EQUAL  NAYA  PRINT
%token <STRINGG> STRING LABEL   VALUE 
//%token <NUMBERR> VALUE

%type <STRINGG> identifier 


%%

Program : 
	Program expression
|
;

expression :   
	identifier '=' identifier '+' identifier  N
												{												
													cout<<"lw $s0 , "<<$3<<endl;
													cout<<"lw $t0 , "<<$5<<endl;
													cout<<"add $s0 , $s0 , $t0"<<endl;
													cout<<"sw $s0 "<<$1<<endl;	                                           
                                              	}
|	identifier '=' identifier '-' identifier  N 
												{
													cout<<"lw $s0 , "<<$3<<endl;
													cout<<"lw $t0 , "<<$5<<endl;
													cout<<"sub $s0 , $s0 , $t0"<<endl;
													cout<<"sw $s0 "<<$1<<endl;	                                           
                                              	}
|	identifier '=' identifier '/' identifier  N
												{
													cout<<"lw $s0 , "<<$3<<endl;
													cout<<"lw $t0 , "<<$5<<endl;
													cout<<"div $s0 , $t0"<<endl;
													cout<<"mflo $s0\n";
													cout<<"sw $s0 "<<$1<<endl;	                                           
                                              	}
|	identifier '=' identifier '*' identifier  N
												{												
													cout<<"lw $s0 , "<<$3<<endl;
													cout<<"lw $t0 , "<<$5<<endl;
													cout<<"mul $s0 , $s0 , $t0"<<endl;
													cout<<"sw $s0 "<<$1<<endl;	                                           
                                              	}
|	identifier '=' identifier '>' identifier  N
												{												
													cout<<"lw $s0 , "<<$3<<endl;
													cout<<"lw $t0 , "<<$5<<endl;
													cout<<"slt $s0 , $t0 , $s0"<<endl;
													cout<<"sw $s0 "<<$1<<endl;
                                              	}
|	identifier '=' identifier '<' identifier  N
												{												
													cout<<"lw $s0 , "<<$3<<endl;
													cout<<"lw $t0 , "<<$5<<endl;
													cout<<"slt $s0 , $s0 , $t0"<<endl;
													cout<<"sw $s0 "<<$1<<endl;	                                           
                                              	}
|	identifier '=' identifier LE identifier  N
												{												
													cout<<"lw $s0 , "<<$3<<endl;
													cout<<"lw $t0 , "<<$5<<endl;
													cout<<"slt $s0 , $t0, $s0 "<<endl;
													cout<<"xori $s0 , $s0 , 1"<<endl;
													cout<<"sw $s0 "<<$1<<endl;	                                           
                                              	}
|	identifier '=' identifier GE identifier  N
												{												
													cout<<"lw $s0 , "<<$3<<endl;
													cout<<"lw $t0 , "<<$5<<endl;
													cout<<"slt $s0 , $s0, $t0 "<<endl;
													cout<<"xori $s0 , $s0 , 1"<<endl;
													cout<<"sw $s0 "<<$1<<endl;	                                           
                                              	}
|	identifier '=' identifier EE identifier  N
												{												
													cout<<"lw $s0 , "<<$3<<endl;
													cout<<"lw $t0 , "<<$5<<endl;
													cout<<"slt $t1 , $t0, $s0 "<<endl;
													cout<<"slt $t2 , $s0, $t0 "<<endl;
													cout<<"or $s0, $t1 , $t2"<<endl;
													cout<<"xori $s0 , $s0 , 1"<<endl;
													cout<<"sw $s0 "<<$1<<endl;	                                           
                                              	}
|	identifier '=' identifier  N            
											{
												int index = return_entry($3);
	                                               if(index == 0 )
	                                                	{cout<<"li $s0 "<<$3<<endl;}
	                                                else
	                                                	{cout<<"lw $s0 "<<$3<<endl;}
	                                                //index = return_entry($1);
													cout<<"sw $s0 "<<$1<<endl;
											}            
| 	STRING  C 					{cout<<$1 << " : \n";}
| 	GOTO  STRING  N				{cout<<"j " <<$2<< "\n";}
|   IF STRING GOTO STRING IF FALSE GOTO STRING N	
												{												
													cout<<"lw $s0 , "<<$2<<endl;
													cout<<"li $t3 , 1"<<endl;
													cout<<"li $t2 , 1"<<endl;
													cout<<"beq $t3 , $s0 , "<<$4<<endl;
													cout<<"j "<<$8<<endl;	                                           
                                              	}
|	FUNC  BEGIN1  STRING  VALUE  C  
						{
							counter = atoi($4);
							cout << "j end"<<counter1<<endl;
							cout << $3 <<" : \n";							
							cout << "addi $sp, $sp, -4 \n";
							cout << "sw $s0 , 0($sp) \n";
							cout << "addi $sp, $sp, -4 \n";
							cout << "sw $t0 , 0($sp) \n";
							cout << "addi $sp, $sp, -4 \n";
							cout << "sw $t1 , 0($sp) \n";
							cout << "addi $sp, $sp, -4 \n";
							cout << "sw $t2 , 0($sp) \n";
						}
|	FUNC  END N	
						{
							
							cout << "end"<<counter1<<" :\n";

							counter1++;

						}				
|	CALL  STRING COMMA  VALUE  N	
								{
									int va = atoi($4) * 4;
									counter = atoi($4);
									cout << "addi $sp, $sp, -4 \n";
									cout << "sw $ra , 0($sp) \n";
									cout<<"jal "<< $2<< "\n";
									cout<<"move	$s0 , $v0 \n";
									cout << "lw $ra , 0($sp) \n";
									cout << "addi $sp, $sp, 4 \n";

									cout << "addi $sp, $sp, "<<va<<endl;
								}
|	STRING  NAYA  STRING COMMA  VALUE  N	
								{	
									counter = atoi($5);
									int va = atoi($5) * 4;

									cout << "addi $sp, $sp, -4 \n";
									cout << "sw $ra , 0($sp) \n";

									cout<<"jal "<< $3<< "\n";
									cout<<"move	$s0 , $v0 \n";
									cout << "lw $ra , 0($sp) \n";
									cout << "addi $sp, $sp, 4 \n";
									cout<<"move	$s0 , $v0 "<<endl;
									cout<<"sw $s0 "<<$1<<endl;
									cout << "addi $sp, $sp, "<<va<<endl;
								}
|	RECIEVEPARAM  STRING  N
					{
						//cout << "				Counter "<< counter <<endl;
						temp = (16 + (counter * 4));
						cout<<"lw $s0, "<<temp<<"($sp) \n";
						cout<<"sw $s0 "<<$2<<endl;	
						counter-- ;
					}
|	PARAM  STRING  N
					{
						cout<<"lw $s0 , "<<$2<<endl;
						cout << "addi $sp, $sp, -4 \n";
						cout << "sw $s0 , 0($sp) \n";
					}
|	RETURN  STRING  N
					{

						cout<<"lw $t1 , "<<$2<<endl;
						cout << "move $v0 , $t1 \n";

						cout << "lw $s0 , 0($sp) \n";
							cout << "addi $sp, $sp, 4 \n";
							cout << "lw $t0 , 0($sp) \n";
							cout << "addi $sp, $sp, 4 \n";
							cout << "lw $t1 , 0($sp) \n";
							cout << "addi $sp, $sp, 4 \n";
							cout << "lw $t2 , 0($sp) \n";
							cout << "addi $sp, $sp, 4 \n";
							cout << "jr $ra \n";
					}
|	PRINT  STRING  N
					{
						cout<<"li $v0 , 1\n";
						cout<<"lw $a0 , "<<$2 <<endl;
						cout<<"syscall \n";

						cout<<"addi $v0 , $zero , 4\n";
						cout<<"la $a0 , space\n";
						cout<<"syscall \n";
					}
					
;

identifier : 
	STRING  
| 	VALUE   
;

   
%%


bool Table_check(string name)
{
	if(Table.find(name)!=Table.end())
		{
			return true;
			//cout<<"duplicate declaration \n";exit(-1);
		}
	else
		{
			return false;
			//int_map[make_pair($2,$3)] = 0; cout<<$3<<endl;printf("value initialised \n");
		}
}

int return_entry(string  name)
{
	//string name = name2;
	if(Table_check(name))
	{
		return Table[name];
	}
	else
	{
		return 0;
	}
}

bool parse(string name)
{

	if(97<=name[0]<=122){cout<<name[0];return true;}
	return false;

	/*if( name == "+" || 
		name == "-" || 
		name == "/" || 
		name == "*" || 		
		name == ">" || 
		name == "<" || 
		name == ">=" || 
		name == "<=" || 
		name == "==" || 		
		name == "!=" || 
		name == "!" ||
		name == ":" ||
		name == "goto" ||
		name == ";" )
	{
		return false;
	}
	else
	{	
		if(name.length() >= 6)
		{
			if(   (name[0] == 'l')&&(name[1] == 'a')&&(name[2] == 'b')&&(name[3] == 'e')&&(name[4] == 'l')   )
			{
				return false;
			}
			else 
			{
				return true;
			}
		}
		return true;
		
	}*/
}



int main () 
{


/*while(1){string s;
	cin>>s;
		if(parse(s)){cout<<"yeah\n";}else{cout<<"no\n";}}*/
	  fstream mips_in;
	  string code;
	  mips_in.open ("variables.txt");
	  int index = 0;

cout<<".data  # Tells assembler we're in the data segment\n";
cout<<"space: .asciiz \"\\n \" \n";
		while (mips_in >> code)
		{cout<<code<<" : .word  0"<<endl;
			//if(parse(code))
			{//cout<<"asd";
				if(!Table_check(code)){Table[code]= ++index;}	
			}
			
		}
	  mips_in.close();

//for (pair < string ,int > i : Table)
{
	//cout<<Table[i.first]<<endl;
}
//cout<<endl;


cout<<".text\nmain:\n";

	FILE *myfile = fopen("input_mips.txt", "r");
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	do {
		yyparse();
	} while (!feof(yyin));

cout<<"jr $ra\n";

/*cout<<"assign_1 : li $t2, 1\n";
//cout<<"move $v0, $t2\n";
cout<<"jr $ra\n";

cout<<"assign_0 : li $t2, 0\n";
//cout<<"move $v0, $t2\n";
cout<<"jr $ra\n";
*/

//cout<<"assign_1 :\nli $s0, 1\nli $v0 , 1 \nsyscall\njr $ra\nassign_0 :\nli $s0, 0\nli $v0 , 1 \nsyscall\njr $ra\n";
	fclose(myfile);

}



void yyerror(const char *  error_message)
{
	//cout<<"Oops we ran into an Error"<<endl;
	cout<<"The Error : "<<error_message<<"error on line  "<<yylineno<<endl;
	//exit(-1);


}
