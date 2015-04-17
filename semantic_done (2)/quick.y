%{
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

#include <string>
using namespace std;
	    stack < string > S;
	    //stack <  pair <  pair<string , string > , double >  >;


//               name  			type/return type        is function/macro/array , limit/number of argument 
map   <   		   string , pair   <  string   ,   pair < string , double > > > Table ;

set < string > variables;
#include "header.h"


extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int yylineno ;
void yyerror(const char *  error_message ); 
bool Table_check(string name);
void Table_insert(string name,string type ,string what_is_this, double limit);
void check_array_declaration_recursive(string type, Syntax_Tree * p);
void check_declaration_recursive(string type, Syntax_Tree * p);
string TAC(Syntax_Tree * p);
int sizeof_array(map   <  string , pair   <  string   ,   pair < string , double > > > Table ,string array_name);
//int arguments ;
Syntax_Tree * dummy;
Syntax_Tree * dummy2;
Syntax_Tree * dummy3,*dummy56;
Syntax_Tree * root;

%}

%union 
{
	double NUMBERR;
	char CHARACTER;
	char *  STRINGG;
	struct Syntax_Tree * parag;
	//class Tree * node;
	//bool BOOLL;
}
%token MACRO BOOL INT CHAR PLUS_PLUS MINUS_MINUS NULL1 FORWARD BACKWARD HEY
%token IF ELSE FOR ASD	EQUAL_EQUAL NOT_EQUAL LESS_THAN_EQUAL GREATER_THAN_EQUAL
%token TRUE FALSE  RETURN AND_AND OR_OR COMMA 
%token QUICKIN QUICKOUT
%token MAIN H N POINTER
//%type <NUMBERR> data_type 
%token <STRINGG> STRING INCLUDE //DATA_TYPE_INT DATA_TYPE_STRING
%token <NUMBERR> VALUE
%left '/' '*' '+' '-'

%token <parag>DATA_TYPE_INT DATA_TYPE_STRING CB OB 


%type <parag> program function_declaration main_function inside_content
%type <parag> header_by_user macro_statement  

%type <parag> data_type function_name
%type <parag> function_statements function_arguments
%type <parag> input_output_statement return_type
%type <parag> remaining_statement_in //array_initialisation_recursive
%type <parag> remaining_statement_out array_statement
%type <parag> quote  loop_statement array_declaration_recursive
%type <parag> assignment_statement array_initialisation
%type <parag> increment_operator loop_initialisation
%type <parag> declaration_expression declaration_statement
%type <parag> declaration_assignment_expression
%type <parag> expression loop_update loop_condition
%type <parag> variable_or_value_or_function_call loop_content
%type <parag> function_call_variables  inside_if_expression if_expression 
%type <parag> function_calling_newline conditional_statement
%%

// cannot assign string and char while declaring ..... assign it seperately 
// note - -> stands for pass by reference ... function cannot return pointer
/*parag comments :



have to add - is_syntax_error
node name has to be exact and check


check duplicates 
if declared or not

*/
program : function_declaration main_function
	{
		$$ = make_node_parent("program -> function_declaration main_function");
		//cout<<"sdjghosdhglad";
		$$->child = $1;
		$1->last = 0;
		$1->next = $2;
		$2->last = 1;
		//PreOrderTraversal($$);
		cout<<endl;
		root = $$;

		//TAC($$);
		//PreOrderTraversalSimulate($$);
	}


;


header_by_user  : 
	header_by_user INCLUDE STRING H N 
			{
						$$ = make_node_parent("header_by_user -> header_by_user INCLUDE STRING H N"); 
						Syntax_Tree * p2 = make_terminal_node(" include ",$3," .h "," ; ",NULL,4);
						$1->last = 0;
						$1->next = p2;
						$$->child = $1;
			}						

|				  {
								$$ = make_node_parent("header_by_user");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
								$$->child = parent;
							} 		
| error                  	{
								$$ = make_node_parent("header_by_user");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
								$$->child = parent;
							} 	
;

macro_statement :  
 	macro_statement MACRO STRING STRING N 	
 			{
						$$ = make_node_parent("macro_statement -> macro_statement MACRO STRING STRING N"); 
						Syntax_Tree * p2 = make_terminal_node(" Macro ",$3,$4," ; ",NULL,4);
						$1->last = 0;
						$1->next = p2;
						$$->child = $1;

						if(Table_check($3)){cout<<"Found duplicate : "<<$3<<endl;}
							else {Table_insert($3,"string","macro",0);}
							//cout<<$3<<"int\n";

			}
| 	macro_statement MACRO STRING VALUE N 				//%prec "function_declaration"
			{
						$$ = make_node_parent("macro_statement ->"); 
						Syntax_Tree * p2 = make_terminal_node(" Macro ",$3," value "," ; ",NULL,4);
						$1->last = 0;
						$1->next = p2;
						$$->child = $1;
						if(Table_check($3)){cout<<"Found duplicate : "<<$3<<endl;}
							else {Table_insert($3,"int","macro",0);
									//cout<<$3<<"int\n";
						}
			}
|	header_by_user
					{//cout<<"macro to header    ";
				    	$$ = make_node_parent("macro_statement->"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;//cout<<"macro to header    ";
    				}
;

///ALSO GLOBAL VARIABLES ARE DEFINED HERE
// function has to have datatype defined and has to reuturn a value

function_declaration :
	function_declaration function_name '(' function_arguments ')'   '{'  function_statements  RETURN  return_type N '}' 	
		{//cout<<"declaration    ";
			$$ = make_node_parent("function_declaration -> function_declaration function_name ( function_arguments ) { function_statements RETURN return_type N }");
			
			//$$->last = 0 ;
			Syntax_Tree * p1 = make_terminal_node(" ( ",NULL,NULL,NULL,NULL,1);
			Syntax_Tree * p2 = make_terminal_node(" ) "," { ",NULL,NULL,NULL,2);
			Syntax_Tree * p3 = make_terminal_node("return",NULL,NULL,NULL,NULL,1);
			Syntax_Tree * p4 = make_terminal_node(" ; "," } ",NULL,NULL,NULL,2);

			$1->last = 0;
			$1->next = $2;

			$2->last = 0;
			$2->next = p1;

			p1->last = 0;
			p1->next = $4;
			
			$4->last = 0;
			$4->next = p2;
			
			p2->next->last = 0;
			p2->next->next = $7;
			
			$7->last = 0;
			$7->next = p3;
			p3->last = 0;
			p3->next = $9;			
			$9->last = 0;
			$9->next = p4;
			$$->child = $1;
			
		}
|	function_declaration data_type  STRING N  			//global declaration not assignment
			{
						$$ = make_node_parent("function_declaration -> function_declaration data_type  STRING N"); 
						Syntax_Tree * p2 = make_terminal_node($3," ; ",NULL,NULL,NULL,2);
						$1->last = 0;
						$1->next = $2;
						$2->last = 0;
						$2->next = p2;
						$$->child = $1;
						if(Table_check($3)){cout<<"Found duplicate : "<<$3<<endl;}
							else {Table_insert($3,Print_data($2),"normal",0);}
			}
|	function_declaration data_type  STRING '[' VALUE ']' N  	//global declaration
			{
						$$ = make_node_parent("function_declaration -> function_declaration data_type  STRING '[' VALUE ']' N"); 
						Syntax_Tree * p2 = make_terminal_node($3," [ "," value "," ] "," ; ",5);
						$1->last = 0;
						$1->next = $2;
						$2->last = 0;
						$2->next = p2;
						$$->child = $1;
							//cout<<"bbbbbbbbbbbb"<<$5<<"aaaaaaaaaaaaa";
						if(Table_check($3)){cout<<"Found duplicate : "<<$3<<endl;}
							else {Table_insert($3,Print_data($2),"array",$5);}
			}
|	macro_statement
					{//cout<<"macro    ";
				    	$$ = make_node_parent("function_declaration->"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;//cout<<"macro    ";
    				}
;

function_name : 
	 data_type STRING 
					{
						$$ = make_node_parent("function_name -> data_type STRING"); 
						Syntax_Tree * p1 = make_terminal_node($2,NULL,NULL,NULL,NULL,1);

						$1->last = 0;
						$1->next = p1;

						$$->child = $1;

						if(Table_check($2)){cout<<"Found duplicate : "<<$2<<endl;}
							else {Table_insert($2,Print_data($1),"func",0);}
					}	
;


function_arguments :
	data_type STRING
			{
								$$ = make_node_parent("function_arguments -> data_type STRING"); 
								Syntax_Tree * p1 = make_terminal_node($2,  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
								if(Table_check($2)){cout<<"Found duplicate : "<<$2<<endl;}
									else {Table_insert($2,Print_data($1),"normal",0);}
			}
|	function_arguments ',' data_type STRING
					{
						$$ = make_node_parent("function_arguments -> function_arguments ',' data_type STRING"); 
						$$->child = $1;
						$1->last = 0;

						Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p2 = make_terminal_node($4, NULL, NULL,NULL,NULL,1);
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 0 ;
						
						$3->next = p2;

								if(Table_check($4)){cout<<"Found duplicate : "<<$4<<endl;}
									else {Table_insert($4,Print_data($3),"normal",0);}


					}
|	data_type POINTER STRING
		{
						$$ = make_node_parent("function_arguments -> data_type POINTER STRING"); 
						Syntax_Tree * p1 = make_terminal_node(" pointer(->) ",$3,NULL,NULL,NULL,2);
						$1->last = 0;
						$1->next = p1;
						$$->child = $1;

								if(Table_check($3)){cout<<"Found duplicate : "<<$3<<endl;}
									else {Table_insert($3,Print_data($1),"point",0);}
		}
|	function_arguments ',' data_type POINTER STRING
		{
						$$ = make_node_parent("function_arguments -> function_arguments ',' data_type POINTER STRING"); 
						$$->child = $1;
						$1->last = 0;

						Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p2 = make_terminal_node(" -> ", $5, NULL,NULL,NULL,2);
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 0 ;
						
						$3->next = p2;


						if(Table_check($5)){cout<<"Found duplicate : "<<$5<<endl;}
									else {Table_insert($5,Print_data($3),"point",0);}
					}
|	data_type STRING '[' VALUE ']'
			{
						$$ = make_node_parent("function_arguments -> data_type STRING '[' VALUE ']'"); 
						Syntax_Tree * p1 = make_terminal_node($2," [ "," value "," ] ",NULL,4);
						$1->last = 0;
						$1->next = p1;
						$$->child = $1;

						if(Table_check($2)){cout<<"Found duplicate : "<<$2<<endl;}
									else {Table_insert($2,Print_data($1),"array",$4);}
			}
|	function_arguments ',' data_type STRING '[' VALUE ']'
					{
						$$ = make_node_parent("function_arguments -> function_arguments ',' data_type STRING '[' VALUE ']'"); 
						$$->child = $1;
						$1->last = 0;

						Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p2 = make_terminal_node( $4, " [ "," value "," ] ",NULL,4);
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 0 ;
						$3->next = p2;

						if(Table_check($4)){cout<<"Found duplicate : "<<$4<<endl;}
									else {Table_insert($4,Print_data($3),"array",$6);}
					}
|
							{
								$$ = make_node_parent("function_arguments ->");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
								$$->child = parent;
							}

| error               {
	                     $$ = make_node_parent("function_arguments");
								                      //$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
								$$->child = parent;
					  } 							
;

return_type :
	variable_or_value_or_function_call
					{
				    	$$ = make_node_parent("return_type -> variable_or_value_or_function_call"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}
| error                     {
						$$ = make_node_parent("return_type");
						//$$->last = 0 ;
						Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						$$->child = parent;
					             }    				
//|	POINTER STRING
;
data_type : 
	DATA_TYPE_INT	
			{
						$$ = make_node_parent("data_type ->"); 
						$1 = make_terminal_node("int",NULL,NULL,NULL,NULL,1);
						$$->child = $1;

			}		
|	DATA_TYPE_STRING
			{
						$$ = make_node_parent("data_type ->"); 
						$1 = make_terminal_node("string",NULL,NULL,NULL,NULL,1);
						$$->child = $1;
			}		
;

main_function : 
	MAIN '{' function_statements '}'
					{
								$$ = make_node_parent("main_function -> MAIN { function_statements }"); 
								Syntax_Tree * p1 = make_terminal_node("Main"," { ",NULL,NULL,NULL,2);
								p1->next->last = 0;
								Syntax_Tree * p2 = make_terminal_node(" } ",  NULL,NULL,NULL,NULL,1);
								p1->next->next = $3;
								$3->last = 0;
								$3->next = p2;

								$$->child = p1;
								dummy3 = $3;
							}
| MAIN error    {
						$$ = make_node_parent("main_function");
						//$$->last = 0 ;
						Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						$$->child = parent;
					             } 							
;

function_statements :
	function_statements RETURN  return_type N
							{
								$$ = make_node_parent("function_statement -> function_statements RETURN return_type N");
								$$->child = $1;

								$1->last = 0;

								Syntax_Tree * p1 = make_terminal_node (" RETURN ",NULL,NULL,NULL,NULL,1);
								$1->next = p1;
								p1->last = 0;
								p1->next = $3;
								Syntax_Tree * p2 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
								$3->last = 0;
								$3->next = p2;

							}
|	function_statements declaration_statement N	   //N ka node bana  (bana diya)
							{
								$$ = make_node_parent("function_statement -> function_statements declaration_statement N");
								$$->child = $1;
								$1->last = 0;
								$1->next = $2;
								$2->last = 0;
								
								Syntax_Tree * p1 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
								$2->next = p1;
							}
|	function_statements assignment_statement N
							{
								$$ = make_node_parent("function_statement -> function_statements assignment_statement N");
								$$->child = $1;
								$1->last = 0;
								$1->next = $2;
								$2->last = 0;
								
								Syntax_Tree * p1 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
								$2->next = p1;

							}
|	function_statements input_output_statement
							{
								$$ = make_node_parent("function_statement -> function_statements input_output_statement");
								$$->child = $1;
								$1->last = 0;
								$1->next = $2;
								$2->last = 1;
							}
|   function_statements function_calling_newline {
								$$ = make_node_parent("function_statement -> function_statements function_calling_newline");
								$$->child = $1;
								$1->last = 0;
								$1->next = $2;
								$2->last = 1;
							}
|	function_statements conditional_statement {
								$$ = make_node_parent("function_statement -> function_statements conditional_statement");
								$$->child = $1;
								$1->last = 0;
								$1->next = $2;
								$2->last = 1;
							}
|	function_statements loop_statement  {
								$$ = make_node_parent("function_statement -> function_statements loop_statement");
								$$->child = $1;
								$1->last = 0;
								$1->next = $2;
								$2->last = 1;
							}
|	function_statements array_statement N  {
								$$ = make_node_parent("function_statement -> function_statements array_statement N");
								$$->child = $1;
								$1->last = 0;
								$1->next = $2;
								$2->last = 0;
								
								Syntax_Tree * p1 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
								$2->next = p1;
							}
|   		/* epsilon */	{
								$$ = make_node_parent("function_statement ->");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
								$$->child = parent;
							} 

;


// cannot initialise array like this -> a[5] = {1,2,3,4,5}; ..... instead use loop and initialise each element
array_statement :
	data_type  array_declaration_recursive  {
								$$ = make_node_parent("array_statement -> data_type array_declaration_recursive");
								$$->child = $1;
								$1->last = 0;
								$1->next = $2;
								$2->last = 1;
								check_array_declaration_recursive(Print_data($1), $2);
								//if(Table_check(Print_data($2))){cout<<"Found duplicate : "<<Print_data($2)<<endl;}
									//else {Table_insert(Print_data($1),Print_data($2),"array",0);}
							}
|	array_initialisation  {
				    	$$ = make_node_parent("array_statement -> array_initialisation"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}
 | error                {
						$$ = make_node_parent("array_statement");
						//$$->last = 0 ;
						Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						$$->child = parent;
					             }    				
;



array_declaration_recursive :
	STRING '['  expression  ']'  
					{
						$$ = make_node_parent("array_declaration_recursive -> STRING [ expression ]"); 
						Syntax_Tree * p1 = make_terminal_node($1," [ ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						Syntax_Tree * p2 = make_terminal_node(" ] ",  NULL,NULL,NULL,NULL,1);
						p1->next->next = $3;
						$3->last = 0;
						$3->next = p2;
						$$->child = p1;
									if ($3->type == 0)
									{}
									else 
									{
										cout<<"require integer index for array \n";
									}
					}
|	array_declaration_recursive  ','  STRING '['  expression  ']' 
					{
						$$ = make_node_parent("array_declaration_recursive -> array_declaration_recursive , STRING [ expression ]"); 
						$$->child = $1;
						$1->last = 0;

						Syntax_Tree * p1 = make_terminal_node(" , ", $3, " [ ",NULL,NULL,3);
						$1->next = p1;
						p1->next->next->last = 0;
						p1->next->next->next = $5;
						$5->last = 0 ;
						Syntax_Tree * p2 = make_terminal_node(" ] ",NULL,NULL,NULL,NULL,1);
						$5->next = p2;
									if ($5->type == 0)
										{}
									else 
									{
										cout<<"require integer index for array \n";
									}
					}

;


array_initialisation :
	STRING '['  expression  ']'  '='  expression
			{
						$$ = make_node_parent("array_initialisation -> STRING [ expression ] = expression"); 
						Syntax_Tree * p1 = make_terminal_node($1," [ ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						Syntax_Tree * p2 = make_terminal_node(" ] ",  " = ",NULL,NULL,NULL,2);
						p2->next->last = 0;
						p2->next->next = $6;
						$6->last = 1;
						p1->next->next = $3;
						$3->last = 0;
						$3->next = p2;
						$$->child = p1;
							if ($3->type == 0)
										{}
									else 
									{
										cout<<"require integer index for array \n";
									}
							int t;
							if(Table_check($1))
							{
								if (strcmp (Table[$1].second.first.c_str() , "array")== 0  )
								{
									if (strcmp (Table[$1].first.c_str() , "int")== 0  )
										{t  = 0;}
									else 
									{
										t=1;
										//cout<<"Invalid operation \n";
									}
									if (t==$6->type)
									{}
									else
									{cout<<"Invalid operation \n";}
								}
								else
								{
									cout<<"its not an array ,invalid access\n";
									$$->type = -1;
								}
							}
							else
							{
								cout<<"Variable undefined \n";
							}
			}
;


//loop_initialisation : of the form - (int a,b,c=8)     datatype only once
loop_statement :
	FOR  '('  loop_initialisation   N  loop_condition  N  loop_update  ')'      '{'     loop_content     '}'
					{
						$$ = make_node_parent("loop_statement -> FOR ( loop_initialisation N loop_condition N loop_update ) { loop_content }"); 
						Syntax_Tree * p1 = make_terminal_node(" for "," ( ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						p1->next->next = $3;
						
						Syntax_Tree * p2 = make_terminal_node(" ; ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p3 = make_terminal_node(" ; ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p4 = make_terminal_node(" ) ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p5 = make_terminal_node(" { ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p6 = make_terminal_node(" } ", NULL,NULL,NULL,NULL,1);
						p2->last = 0;p3->last = 0;p4->last = 0;p5->last = 0;

						$3->last = 0;
						$3->next = p2;
						p2->next = $5;
						$5->last = 0;
						$5->next = p3;
						p3->next = $7;

						$7->last = 0;
						$7->next = p4;
						p4->next = p5;

						p5->next = $10;
						$10->last = 0;
						$10->next = p6;

						$$->child = p1;
						dummy56 = $$;
					}
;

loop_initialisation:
	declaration_statement  {
				    	$$ = make_node_parent("loop_initialisation -> declaration_statement"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}
|	assignment_statement  {
				    	$$ = make_node_parent("loop_initialisation -> assignment_statement"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}    				
|	
	{
		$$ = make_node_parent("loop_initialisation ->");
		//$$->last = 0 ;
		Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
		$$->child = parent;
		
	}
| error                       {
						       $$ = make_node_parent("loop_intialisation");
						          //$$->last = 0 ;
						            Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						            $$->child = parent;
					             } 	

;

loop_condition:
	if_expression  {
				    	$$ = make_node_parent("loop_condition -> if_expression"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}
|	loop_condition  ','  if_expression
		{
									$$ = make_node_parent("loop_condition -> loop_condition , if_expression"); 
									$$->child = $1;
									$1->last = 0;
									Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
									$1->next = p1;
									p1->last = 0;
									p1->next = $3;
									$3->last = 1;
								 }
|
	{
		$$ = make_node_parent("loop_condition ->");
		//$$->last = 0 ;
		Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
		$$->child = parent;
		
	}

| error                       {
						       $$ = make_node_parent("loop_condition");
						          //$$->last = 0 ;
						            Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						            $$->child = parent;
					             } 		
;

loop_update:
	assignment_statement  {
				    	$$ = make_node_parent("loop_update -> assignment_statement"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}
|	loop_update  ','  assignment_statement
			{
									$$ = make_node_parent("loop_update -> loop_update , assignment_statement"); 
									$$->child = $1;
									$1->last = 0;
									Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
									$1->next = p1;
									p1->last = 0;
									p1->next = $3;
									$3->last = 1;
								 }
|
	{
		$$ = make_node_parent("loop_condition ->");
		//$$->last = 0 ;
		Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
		$$->child = parent;
		
	}

| error                       
								{
						       $$ = make_node_parent("loop_update");
						          //$$->last = 0 ;
						            Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						            $$->child = parent;
					             } 		

;

loop_content: 
	function_statements  {
				    	$$ = make_node_parent("loop_content -> function_statements"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}

;


// cannot do else if    and    brackets are compulsory for if-else statements
conditional_statement :
	IF  '(' if_expression ')'    '{'     inside_content     '}'
					{
						$$ = make_node_parent("conditional_statement -> IF ( if_expression ) { inside_content }"); 
						Syntax_Tree * p1 = make_terminal_node(" if "," ( ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						p1->next->next = $3;
						
						Syntax_Tree * p2 = make_terminal_node(" ) ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p3 = make_terminal_node(" { ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p6 = make_terminal_node(" } ", NULL,NULL,NULL,NULL,1);
						p2->last = 0;p3->last = 0;

						$3->last = 0;
						$3->next = p2;
						p2->next = p3;
						p3->next = $6;
						$6->last = 0;
						$6->next = p6;
						

						$$->child = p1;
						dummy = $$;
					}

|	IF  '(' if_expression ')'    '{'     inside_content     '}'  ELSE  '{'     inside_content     '}'
					{
						$$ = make_node_parent("conditional_statement -> IF ( if_expression ) { inside_content } ELSE { inside_content }"); 
						Syntax_Tree * p1 = make_terminal_node(" if "," ( ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						p1->next->next = $3;
						
						Syntax_Tree * p2 = make_terminal_node(" ) ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p3 = make_terminal_node(" { ", NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p4 = make_terminal_node(" } ", " else "," { ",NULL,NULL,3);
						Syntax_Tree * p6 = make_terminal_node(" } ", NULL,NULL,NULL,NULL,1);
						p2->last = 0;p3->last = 0;p4->next->next->last = 0;

						$3->last = 0;
						$3->next = p2;
						p2->next = p3;
						p3->next = $6;
						$6->last = 0;
						$6->next = p4;
						p4->next->next->next = $10;

						$10->last = 0;
						$10->next = p6;
						
						$$->child = p1;
						dummy2 = $$;
					}
| error                       	{
						       $$ = make_node_parent("conditional_statement");
						          //$$->last = 0 ;
						            Syntax_Tree * parent = make_terminal_node("error",NULL,NULL,NULL,NULL,1);
						            $$->child = parent;
					            } 						
;


if_expression :
	inside_if_expression 
		{
				    	$$ = make_node_parent("if_expression -> inside_if_expression"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    	}
|	inside_if_expression  AND_AND  inside_if_expression
					{
				    	$$ = make_node_parent("if_expression -> inside_if_expression  AND_AND  inside_if_expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" && ",NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 0;
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 1;
    				}
|	inside_if_expression  OR_OR  inside_if_expression 
			{
				    	$$ = make_node_parent("if_expression -> inside_if_expression  OR_OR  inside_if_expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" || ",NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 0;
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 1;
    				}
|	'('  inside_if_expression  CB 
		{
									$$ = make_node_parent("if_expression -> ( inside_if_expression CB"); 
									Syntax_Tree * p1 = make_terminal_node(" ( ",NULL,NULL,NULL,NULL,1);
									Syntax_Tree * p2 = make_terminal_node(" ) ",NULL,NULL,NULL,NULL,1);
									$$->child = p1;
									p1->last = 0;
									p1->next = $2;
									$2->last = 0 ;
									$2->next = p2;
									p2->last = 1;
								 }
;

inside_if_expression :
	expression   EQUAL_EQUAL  expression
					{
				    	$$ = make_node_parent("inside_if_expression -> expression EQUAL_EQUAL expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" == ",NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 0;
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 1;

							int t;
						if ($1->type == $3->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}    				}
|	expression   NOT_EQUAL  expression
					{
				    	$$ = make_node_parent("inside_if_expression -> expression NOT_EQUAL expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" != ",NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 0;
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 1;
						int t;
						if ($1->type == $3->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
|	expression   LESS_THAN_EQUAL  expression
					{
				    	$$ = make_node_parent("inside_if_expression -> expression LESS_THAN_EQUAL expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" <= ",NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 0;
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 1;
						int t;
						if ($1->type == $3->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
|	expression   GREATER_THAN_EQUAL  expression
					{
				    	$$ = make_node_parent("expression GREATER_THAN_EQUAL expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" >= ",NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 0;
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 1;
						int t;
						if ($1->type == $3->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
|	expression   '<'  expression
					{
				    	$$ = make_node_parent("inside_if_expression -> expression < expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" < ",NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 0;
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 1;
						int t;
						if ($1->type == $3->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
|	expression   '>'  expression 
					{
				    	$$ = make_node_parent("inside_if_expression -> expression > expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" > ",NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 0;
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 1;int t;
						if ($1->type == $3->type)
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
|	'!'  expression {
				    	$$ = make_node_parent("inside_if_expression -> ! expression"); 
				    	Syntax_Tree * p1 = make_terminal_node(" ! ",NULL,NULL,NULL,NULL,1);
						$$->child = p1;
						p1->last = 0;
						p1->next = $2;
						$2->last = 1;
						int t;
						if ($2->type == 0  )
								{t  = 0;}
							else 
							{
								t=1;
								cout<<"Invalid operation \n";
							}
    				}
|	expression      {
				    	$$ = make_node_parent("inside_if_expression -> expression"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}
;

inside_content :
	function_statements
					{
				    	$$ = make_node_parent("inside_content -> function_statements"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}

;


function_calling_newline :
	STRING '(' function_call_variables ')' N
		{
						$$ = make_node_parent("function_calling_newline -> STRING '(' function_call_variables ')' N"); 
						Syntax_Tree * p1 = make_terminal_node($1," ( ",NULL,NULL,NULL,2);
						p1->next->last = 0;
						Syntax_Tree * p2 = make_terminal_node(" ) ",  " ; ",NULL,NULL,NULL,2);
						p1->next->next = $3;
						$3->last = 0;
						$3->next = p2;
						$$->child = p1;

						if(Table_check($1))// && Table_check($3)) 
									{

											if(strcmp (Table[$1].second.first.c_str() , "func")!= 0  )
											{	
												cout<<"its not an function ,invalid access\n";
												$$->type = -1;
											}
										else{

											}
									}
									else
										{
											cout<<"Variable undefined \n";
										}

		}
|	STRING '=' STRING '(' function_call_variables ')' ';'
		{
						$$ = make_node_parent("function_calling_newline -> STRING '=' STRING '(' function_call_variables ')' ';'"); 
						Syntax_Tree * p1 = make_terminal_node($1," = ",$3," ( ",NULL,4);
						p1->next->next->next->last = 0;
						Syntax_Tree * p2 = make_terminal_node(" ) ",  " ; ",NULL,NULL,NULL,2);
						p1->next->next->next->next = $5;
						$5->last = 0;
						$5->next = p2;
						int t;
						$$->child = p1;

							if(Table_check($3))
							{}
							else
							{
								cout<<"Variable undefined \n";
							}
							if(Table_check($1))
							{}
							else
							{
								cout<<"Variable undefined \n";
							}
							if ((strcmp (Table[$1].second.first.c_str() , "normal")== 0  ) && (strcmp (Table[$3].second.first.c_str() , "func")== 0  ))
								{
									if (strcmp (Table[$1].first.c_str() , Table[$3].first.c_str())== 0  )
										{t  = 0;}
									else 
									{
										t=1;
										cout<<"type mismatch \n";
									}
								}
								else
								{
									cout<<"invalid operation\n";
									$$->type = -1;
								}
							
		}

;





input_output_statement :
    QUICKIN  FORWARD  remaining_statement_in  N
			{
				$$ = make_node_parent("I/O statement ->"); 
				Syntax_Tree * p1 = make_terminal_node("quickIn"," >> ",NULL,NULL,NULL,2);
				p1->next->last = 0;
				Syntax_Tree * p2 = make_terminal_node(" ; ",  NULL,NULL,NULL,NULL,1);
				p1->next->next = $3;
				$3->last = 0;
				$3->next = p2;

				$$->child = p1;
			}
|   QUICKOUT  BACKWARD  remaining_statement_out  N
			{
				$$ = make_node_parent("input_output_statement -> QUICKOUT BACKWARD remaining_statement_out N"); 
				Syntax_Tree * p1 = make_terminal_node("quickOut"," << ",NULL,NULL,NULL,2);
				p1->next->last = 0;
				Syntax_Tree * p2 = make_terminal_node(" ; ",  NULL,NULL,NULL,NULL,1);
				p1->next->next = $3;
				$3->last = 0;
				$3->next = p2;

				$$->child = p1;
			}
;

remaining_statement_in :
    STRING	
	{
    	$$ = make_node_parent("remaining_statement -> string"); 
    	Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
		$$->child = p1;
    }
|   remaining_statement_in  FORWARD  STRING
	{
		$$ = make_node_parent("remaining_statement_in ->"); 
		Syntax_Tree * p1 = make_terminal_node(" >> ",$3,NULL,NULL,NULL,2);
		$1->last = 0;
		$1->next = p1;
		$$->child = $1;
	}
;

// added afterwards  remaining statement -> expression

remaining_statement_out :
	expression
				{
				    	$$ = make_node_parent("remaining_statement_out -> expression"); 
				    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
						$$->child = $1;
						$1->last = 1;
    				}
|	remaining_statement_out  BACKWARD expression
					{
						$$ = make_node_parent("remaining_statement_out -> remaining_statement_out  BACKWARD expression"); 
						$$->child = $1;
						Syntax_Tree * p1 = make_terminal_node(" << ",NULL,NULL,NULL,NULL,1);
						$1->next = p1;
						p1->last = 0;
						p1->next = $3;
						$3->last = 1 ;
					}

|   	'#' quote '#' 
					{
						$$ = make_node_parent("remaining_statement_out ->"); 
						Syntax_Tree * p1 = make_terminal_node(" # ",NULL,NULL,NULL,NULL,1);
						Syntax_Tree * p2 = make_terminal_node(" # ",NULL,NULL,NULL,NULL,1);
						p1->last = 0;
						p1->next = $2;
						$2->last = 0;
						$2->next = p2;
						$$->child = p1;
					}
|   	remaining_statement_out  BACKWARD  '#' quote '#'
					{
						$$ = make_node_parent("remaining_statement_out ->"); 
						$$->child = $1;
						Syntax_Tree * p1 = make_terminal_node(" << "," # ",NULL,NULL,NULL,2);
						$1->next = p1;
						p1->next->last = 0;
						p1->next->next = $4;
						$4->last = 0 ;
						Syntax_Tree * p2 = make_terminal_node(" # ",NULL,NULL,NULL,NULL,1);
						$4->next = p2;
				}
;


quote :
  quote STRING{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node($2,  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote VALUE {
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node("value",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '~'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ~ ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '`'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ` ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '@'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" @ ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '$'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" $ ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '^'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ^ ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote ':'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" : ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '.'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" . ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '?'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ? ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '!'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ! ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '&'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" & ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '*'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" * ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '('{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ( ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote ')'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ) ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '-'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" - ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '='{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" = ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '+'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" + ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '{'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" { ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '}'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" } ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote ';'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ; ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '/'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" / ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '>'{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" > ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote '<' {
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" < ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote ',' {
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" , ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote PLUS_PLUS {
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" ++ " ,  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote MINUS_MINUS {
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" -- ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote FORWARD {
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" >> ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}
| quote BACKWARD{
								$$ = make_node_parent("quote ->"); 
								Syntax_Tree * p1 = make_terminal_node(" << ",  NULL,NULL,NULL,NULL,1);
								$$->child = $1;
								$1->last = 0;
								$1->next = p1;
			}

//| quote '%'
|		// epsilon	
						{
								$$ = make_node_parent("quote ->");
								//$$->last = 0 ;
								Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
								$$->child = parent;
						} 
;


assignment_statement :  
    STRING '=' expression  	{
								$$ = make_node_parent("assignment_statement -> string = expression"); 
								Syntax_Tree * p1 = make_terminal_node_new($1," = ",NULL,NULL,NULL,2,"string",NULL,NULL,NULL,NULL,0);
								p1->next->last = 0;
								p1->next->next = $3;
								$3->last = 1;
								$$->child = p1;


									int t;
									if(Table_check($1))
									{
										if (strcmp (Table[$1].second.first.c_str() , "normal")== 0  )
										{
											if (strcmp (Table[$1].first.c_str() , "int")== 0  )
												{t  = 0;}
											else 
											{
												t=1;
											}
											if ($3->type == t)
											{}
											else
											{
												cout<<"Invalid operation \n";
											}
										}
										else
										{
											cout<<"its not an array ,invalid access\n";
											$$->type = -1;
										}
									}
									else
									{
										cout<<"Variable undefined \n";
									}

									//dummy = $$;
							}
|   increment_operator  	{
								$$ = make_node_parent("assignment_statement -> increment_operator"); 
								//$1 = make_terminal_node_new("increment_operator",NULL,NULL,NULL,NULL,1,"increment_operator",NULL,NULL,NULL,NULL,0);
								$$->child = $1;
								$1->last = 1;
							}
|   STRING '='  '#'  quote  '#' { //not done
									$$ = make_node_parent("assignment_statement ->"); 
									Syntax_Tree * p1 = make_terminal_node($1," = "," # ",NULL,NULL,3);
									p1->next->next->last = 0;
									Syntax_Tree * p2 = make_terminal_node(" # ",  NULL,NULL,NULL,NULL,1);
									p1->next->next->next = $4;
									$4->last = 0;
									$4->next = p2;

									$$->child = p1;
								}
|   STRING '=' NULL1  			{ //not done
							    	$$ = make_node_parent("assignment_statement ->"); 
							    	Syntax_Tree * p1 = make_terminal_node($1," = "," NULL ",NULL,NULL,3);
									$$->child = p1;
									if (strcmp (Table[$1].second.first.c_str() , "normal")== 0  )
										{}
									else 
										{cout<<"Invalid operation \n";}
									if (strcmp (Table[$1].first.c_str() , "int")== 0  )
										{cout<<"Invalid operation \n";}
									else 
										{}
							    }
;

increment_operator :
    STRING PLUS_PLUS 			{
							    	$$ = make_node_parent("increment_operator -> STRING PLUS_PLUS"); 
							    	Syntax_Tree * p1 = make_terminal_node($1," ++ ",NULL,NULL,NULL,2);
									$$->child = p1;

									int t;
									if(Table_check($1))
									{
										if (strcmp (Table[$1].second.first.c_str() , "array")== 0  )
										{
												cout<<"its not an array ,invalid access\n";
												$$->type = -1;
										}
										else{
										if (strcmp (Table[$1].first.c_str() , "int")== 0  ){t  = 0;}
										else 
											{
												cout<<"Invalid operation \n";
											}}
									}
									else
									{
										cout<<"Variable undefined \n";
									}
							    }
|   STRING MINUS_MINUS   		{
							    	$$ = make_node_parent("increment_operator -> STRING MINUS_MINUS"); 
							    	Syntax_Tree * p1 = make_terminal_node($1," -- ",NULL,NULL,NULL,2);
									$$->child = p1;
									int t;
									if(Table_check($1))
									{

										if (strcmp (Table[$1].second.first.c_str() , "array")== 0  )
										{
												cout<<"its not an array ,invalid access\n";
												$$->type = -1;
										}
										else{
										if (strcmp (Table[$1].first.c_str() , "int")== 0  ){t  = 0;}
										else 
											{
												cout<<"Invalid operation \n";
											}}
									}
									else
									{
										cout<<"Variable undefined \n";
									}
							    }
;


declaration_statement :
	data_type declaration_expression	 
			{
										$$ = make_node_parent("declaration_statement -> data_type declaration_expression");
										$$->child = $1;
										$1->last = 0;
										$1->next = $2;
										$2->last = 1;
										//Syntax_Tree * p1 = make_terminal_node (" ; ",NULL,NULL,NULL,NULL,1);
										//$2->next = p1;
										//cout<<$1->data<<endl;
										//cout<<Print_data($1)<<endl;
										//cout<<$2->data<<endl;

										check_declaration_recursive(Print_data($1), $2);
			}
;

declaration_expression :
	
	STRING
								{
									$$ = make_node_parent("declaration_expression -> STRING"); 
							    	Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
									$$->child = p1;
								}
|	declaration_expression ',' STRING
								{
									$$ = make_node_parent("declaration_expression -> declaration_expression , STRING"); 
							    	Syntax_Tree * p1 = make_terminal_node(" , ",$3,NULL,NULL,NULL,2);
									$$->child = $1;
									$1->last = 0;
									$1->next = p1;
								}
|	declaration_assignment_expression			{
									$$ = make_node_parent("declaration_expression -> declaration_assignment_expression"); 
							    	//Syntax_Tree * p1 = make_terminal_node($1,NULL,NULL,NULL,NULL,1);
									$$->child = $1;
								}
| 	declaration_expression ',' declaration_assignment_expression 
								{
									$$ = make_node_parent("declaration_expression -> declaration_expression , declaration_assignment_expression"); 
							    	Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
									$$->child = $1;
									$1->last = 0;
									$1->next = p1;
									p1->last = 0;
									p1->next = $3;
								}
;


declaration_assignment_expression:
	STRING '=' expression
			{
									$$ = make_node_parent("declaration_assignment_expression -> STRING = expression"); 
							    	Syntax_Tree * p1 = make_terminal_node($1," = ",NULL,NULL,NULL,2);
							    	$$->child = p1;
									p1->next->last = 0;
									p1->next->next = $3;
									$3->last = 1;


									
								}
|	STRING '=' '#' quote '#'		
				{
									$$ = make_node_parent("declaration_assignment_expression -> STRING = # quote #"); 
									Syntax_Tree * p1 = make_terminal_node($1," = "," # ",NULL,NULL,3);
									p1->next->next->last = 0;
									Syntax_Tree * p2 = make_terminal_node(" # ",  NULL,NULL,NULL,NULL,1);
									p1->next->next->next = $4;
									$4->last = 0;
									$4->next = p2;

									$$->child = p1;
				}
;


expression :
	variable_or_value_or_function_call
			{
									$$ = make_node_parent("expression -> variable_or_value_or_function_call"); 
									$$->child = $1;
									$1->last = 1;
									$$->type  = $1->type;
									
			}
|   expression   '/'   expression
								{
									$$ = make_node_parent("expression -> expression / expression"); 
									$$->child = $1;
									$1->last = 0;
									Syntax_Tree * p1 = make_terminal_node_new(" / ",NULL,NULL,NULL,NULL,1," / ",NULL,NULL,NULL,NULL,0);
									$1->next = p1;
									p1->last = 0;
									p1->next = $3;
									$3->last = 1;
									if($1->type == $3->type){$$->type  = $1->type;}
									else
									{
										cout<<"Syntax errro : type mismatch \n";
									}
								 }
|   expression   '*'   expression			{
									$$ = make_node_parent("expression -> expression * expression"); 
									$$->child = $1;
									$1->last = 0;
									Syntax_Tree * p1 = make_terminal_node_new(" * ",NULL,NULL,NULL,NULL,1," * ",NULL,NULL,NULL,NULL,0);
									$1->next = p1;
									p1->last = 0;
									p1->next = $3;
									$3->last = 1;


									if($1->type == $3->type){$$->type  = $1->type;}
									else
									{
										cout<<"Syntax errro : type mismatch \n";
									}
								 }
|   expression   '+'   expression			{
									$$ = make_node_parent("expression -> expression + expression"); 
									$$->child = $1;
									$1->last = 0;
									Syntax_Tree * p1 = make_terminal_node_new(" + ",NULL,NULL,NULL,NULL,1," + ",NULL,NULL,NULL,NULL,0);
									$1->next = p1;
									p1->last = 0;
									p1->next = $3;
									$3->last = 1;


									if($1->type == $3->type){$$->type  = $1->type;}
									else
									{
										cout<<"Syntax errro : type mismatch \n";
									}
								 }
|   expression   '-'   expression				
								{
									$$ = make_node_parent("expression -> expression - expression"); 
									$$->child = $1;
									$1->last = 0;
									Syntax_Tree * p1 = make_terminal_node_new(" - ",NULL,NULL,NULL,NULL,1," - ",NULL,NULL,NULL,NULL,0);
									$1->next = p1;
									p1->last = 0;
									p1->next = $3;
									$3->last = 1;

									if($1->type == $3->type){$$->type  = $1->type;}
									else
									{
										cout<<"Syntax errro : type mismatch \n";
									}
								 }
|   '('  expression  ')'					{
									$$ = make_node_parent("expression -> ( expression )"); 
									Syntax_Tree * p1 = make_terminal_node_new(" ( ",NULL,NULL,NULL,NULL,1," ( ",NULL,NULL,NULL,NULL,0);
									Syntax_Tree * p2 = make_terminal_node_new(" ) ",NULL,NULL,NULL,NULL,1," ) ",NULL,NULL,NULL,NULL,0);
									$$->child = p1;
									p1->last = 0;
									p1->next = $2;
									$2->last = 0 ;
									$2->next = p2;
									p2->last = 1;



									$$->type  = $2->type;
								 }
;

variable_or_value_or_function_call:

	STRING						{
									$$ = make_node_parent("variable_or_value_or_function_call -> STRING"); 
							    	Syntax_Tree * p1 = make_terminal_node_new($1,NULL,NULL,NULL,NULL,1,"string",NULL,NULL,NULL,NULL,0);
									$$->child = p1;

									//$$->type  = 

									if(Table_check($1))
									{
											if(strcmp (Table[$1].second.first.c_str() , "array")== 0  )
											{	
												cout<<"its a array ,invalid access\n";
												$$->type = -1;
											}
											else{
											if (strcmp (Table[$1].first.c_str() , "int")== 0  ){$$->type  = 0;}
											else {$$->type  = 1;}}
									}
									else
									{
										cout<<"Variable undefined \n";
									}
								}
|	STRING '[' VALUE ']'				{
									$$ = make_node_parent("variable_or_value_or_function_call -> STRING [ VALUE ]"); 
							    	Syntax_Tree * p1 = make_terminal_node_new($1," [ ","value"," ] ",NULL,4,"STRING","[","VALUE","]",NULL,$3);
									$$->child = p1;

									if(Table_check($1))
									{

											if(strcmp (Table[$1].second.first.c_str() , "array")!= 0  )
											{	
												cout<<"its not an array ,invalid access\n";
												$$->type = -1;
											}
										else{
										if (strcmp (Table[$1].first.c_str() , "int")== 0  )
											{
												$$->type  = 0;
											}
										else 
											{
												$$->type  = 1;
											}}
									}
									else
										{
											cout<<"Variable undefined \n";
										}
								}
|	STRING '[' STRING ']'				{
									$$ = make_node_parent("variable_or_value_or_function_call -> STRING [ STRING ]"); 
							    	Syntax_Tree * p1 = make_terminal_node_new($1," [ ",$3," ] ",NULL,4,"STRING","[","STRING","]",NULL,0);
									$$->child = p1;


									if(Table_check($1) && Table_check($3)) 
									{

											if(strcmp (Table[$1].second.first.c_str() , "array")!= 0  )
											{	
												cout<<"its not an array ,invalid access\n";
												$$->type = -1;
											}
										else{

												if (strcmp (Table[$1].first.c_str() , "int")== 0  )
													{
														$$->type  = 0;
													}
												else 
													{
														$$->type  = 1;
													}
											}
									}
									else
										{
											cout<<"Variable undefined \n";
										}
								}
|	VALUE						{
									$$ = make_node_parent("variable_or_value_or_function_call -> VALUE"); 
							    	Syntax_Tree * p1 = make_terminal_node_new("VALUE",NULL,NULL,NULL,NULL,1,"VALUE",NULL,NULL,NULL,NULL,$1);
									$$->child = p1;

									$$->type  = 0;

									//dummy = p1;
								}
//|	function_call_statement //function_call_variables ')'
|	STRING '(' function_call_variables ')'		{
									$$ = make_node_parent("variable_or_value_or_function_call -> STRING '(' function_call_variables ')'"); 
							    	Syntax_Tree * p1 = make_terminal_node($1," ( ",NULL,NULL,NULL,2);
							    	$$->child = p1;
									p1->next->last = 0;
									p1->next->next = $3;
									$3->last = 0;
									Syntax_Tree * p2 = make_terminal_node(" ) ",NULL,NULL,NULL,NULL,1);
									$3->next = p2;
									$3->last = 1;


									if(Table_check($1))// && Table_check($3)) 
									{

											if(strcmp (Table[$1].second.first.c_str() , "func")!= 0  )
											{	
												cout<<"its not an function ,invalid access\n";
												$$->type = -1;
											}
										else{

											}
									}
									else
										{
											cout<<"Variable  undefined \n";
										}

								}
;

function_call_variables ://not done
	expression				{
									$$ = make_node_parent("function_call_variable -> expression"); 
									$$->child = $1;
									$1->last = 1;
								}
|	function_call_variables ',' expression		{
									$$ = make_node_parent("function_call_variable -> function_call_variables , expression"); 
									$$->child = $1;
									$1->last = 0;
									Syntax_Tree * p1 = make_terminal_node(" , ",NULL,NULL,NULL,NULL,1);
									$1->next = p1;
									p1->last = 0;
									p1->next = $3;
									$3->last = 1;
								 }
|	POINTER STRING				{
									$$ = make_node_parent("function_call_variable ->pointer string"); 
							    	Syntax_Tree * p1 = make_terminal_node(" pointer (->)",$2,NULL,NULL,NULL,2);
									$$->child = p1;
								}
|	function_call_variables ',' POINTER STRING		{
								$$ = make_node_parent("function_call_variable ->"); 
								$$->child = $1;
								$1->last = 0;
								Syntax_Tree * p1 = make_terminal_node(" , "," pointer (->)",$4,NULL,NULL,3);
								$1->next = p1;
								 }
|	{
		$$ = make_node_parent("function_call_varialbe ->");
		//$$->last = 0 ;
		Syntax_Tree * parent = make_terminal_node("epsilon",NULL,NULL,NULL,NULL,1);
		$$->child = parent;
		
	}
;

%%



int main()
{

	FILE *myfile = fopen("input.txt", "r");
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;


	do {
		yyparse();
	} while (!feof(yyin));


freopen("/home/parag/Videos/mips/input_mips.txt","w",stdout);
//cout<<"here";
//cout<<"space: .asciiz \" \\n \" \n";
	//TAC(dummy56);
	//cout<<"sss"  <<endl;
	TAC(root);
	//cout<<endl<<sizeof_array(Table,"ab");

freopen("/home/parag/Videos/mips/variables.txt","w",stdout);
//cout<<"here";

	for(string i : variables)
	{
		cout<<i<<endl;	
	}
}


void yyerror(const char *  error_message)
{
	//cout<<"Oops we ran into an Error"<<endl;
	cout<<"The Error : "<<error_message<<"error on line  "<<yylineno<<endl;
	//exit(-1);


}

