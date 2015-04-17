#include <bits/stdc++.h>
using namespace std;
int arguments;
typedef struct Syntax_Tree
 {
            int my_type;   /// 0 non-terminal 1 terminal
	    int last;		///1 for last
            const   char * data;
	    int has_child;
	    	int type; // 0 is int 1 is char
            double constant;
             Syntax_Tree * next;
            Syntax_Tree* child;
            int val;

            const   char * node_name;
} Syntax_Tree;


int sizeof_array(map   <  string , pair   <  string   ,   pair < string , double > > > Table ,string array_name)
{
	if(Table[array_name].first == "int"){return 8;}
	else {return 1;}
}

string new_var()
{
	static int count=0;
	stringstream ss;
	ss<<++count;
	variables.insert("temp" + ss.str());
	return string("temp"+ss.str());
}

string new_label()
{
	static int c=0;
	stringstream ss;
	ss<<++c;

	return string("Label"+ss.str());
}

string  TAC(Syntax_Tree * temp)
{
	if(temp->node_name == "assignment_statement -> string = expression")
	{
		cout<<TAC(temp->child) << " = "<< TAC(temp->child->next->next);
		cout<<" ;"<<endl;
		return "";
	}

	if(temp->node_name == "expression -> variable_or_value_or_function_call")
	{
		return TAC(temp->child);
	}
	if(temp->node_name == "variable_or_value_or_function_call -> VALUE")
	{
		int Number = temp->child->val;
		string Result;
		stringstream convert;
		convert << Number;
		Result = convert.str();
		string t0 = new_var();
		cout<<t0 << " = "<<Result << " ; \n"; 
		return t0;//Result;
		//return Result;

	}
	if(temp->node_name == "string")
	{
		return temp->data;
	}
	if(temp->node_name == "variable_or_value_or_function_call -> STRING [ VALUE ]")
	{
/*		string arr,num,a1,a2;
		int Number = temp->child->next->next->val;
		string Result;
		stringstream convert;
		convert << Number;
		Result = convert.str();
		num = Result;
		a1 = "[";
		a2 = "]";
		arr = temp->child->data + a1 + num + a2 ;
		return arr;
*/


			//TAC(temp->child);
		string sz; 
		string val_string = temp->child->data;
		if(sizeof_array(Table,val_string)== 8){sz = " 8";}
		else{sz = " 1";}

		string t1 = new_var();
		string t2 = new_var();
		string t3 = new_var();

		cout<< t1 << " = "<< temp->child->next->next->val << " * " <<sz<<"; \n";
		cout<< t2 << " = "<< val_string << " + "<< t1 << " ; \n";
		cout<< t3 << " = "<<"* ( "<< t2 << " )"<< " ;\n";
		return t3;


			
	}
	if(temp->node_name == "variable_or_value_or_function_call -> STRING [ STRING ]")
	{
		/*
		string arr,a1,a2,a3,a4;
		a1 = temp->child->data;
		a2 = "[";
		a3 = temp->child->next->next->data ;
		a4 = "]";
		arr = a1 + a2 + a3 + a4 ;
		return arr;
			*/

			string sz; 
		string val_string = temp->child->data;
		if(sizeof_array(Table,val_string)== 8){sz = " 8";}
		else{sz = " 1";}

		string t1 = new_var();
		string t2 = new_var();
		string t3 = new_var();

		cout<< t1 << " = "<< temp->child->next->next->data << " * " <<sz<<"; \n";
		cout<< t2 << " = "<< val_string << " + "<< t1 << " ; \n";
		cout<< t3 << " = "<<"* ( "<< t2 << " )"<< " ;\n";
		return t3;

	}

	if(temp->node_name == "variable_or_value_or_function_call -> STRING")
	{
		variables.insert(temp->child->data);
		return temp->child->data;
	}

	if(temp->data == "expression -> expression / expression")
	{
		string t0 = new_var();
		string t1 = new_var();
		string result = new_var();

		cout<<t0<< " = "<<TAC(temp->child)<< " ; \n" ;
		cout<<t1<< " = "<<TAC(temp->child->next->next)<< " ; \n";

		cout<<result << " = "<< t0 << " / "<< t1<< " ; \n";
		return result;
		

	}

if(temp->data == "expression -> expression * expression")
	{
		string t0 = new_var();
		string t1 = new_var();
		string result = new_var();

		cout<<t0<< " = "<<TAC(temp->child)<< " ; \n" ;
		cout<<t1<< " = "<<TAC(temp->child->next->next)<< " ; \n";

		cout<<result << " = "<< t0 << " * "<< t1<< " ; \n";
		return result;
	}
	if(temp->data == "expression -> expression + expression")
	{
		string t0 = new_var();
		string t1 = new_var();
		string result = new_var();

		cout<<t0<< " = "<<TAC(temp->child)<< " ; \n" ;
		cout<<t1<< " = "<<TAC(temp->child->next->next)<< " ; \n";

		cout<<result << " = "<< t0 << " + "<< t1<< " ; \n";
		return result;
	}
	if(temp->data == "expression -> expression - expression")
	{
		string t0 = new_var();
		string t1 = new_var();
		string result = new_var();

		cout<<t0<< " = "<<TAC(temp->child)<< " ; \n" ;
		cout<<t1<< " = "<<TAC(temp->child->next->next)<< " ; \n";

		cout<<result << " = "<< t0 << " - "<< t1<< " ; \n";
		return result;
	}
	if(temp->data == "expression -> ( expression )")
	{
		string result = new_var();

		cout<<result<< " = "<<TAC(temp->child->next)<< " ; \n" ;
		return result;
	}
//upto this given to soham

	if(temp->node_name == "conditional_statement -> IF ( if_expression ) { inside_content }")
	{
		string l1 = new_label();
		string l2 = new_label();
		string l3 = new_label();
		string t = TAC(temp->child->next->next);
		if(t=="")
			{
				string n = new_var();
				cout<< n << " = 1;\n";//<< 
				t = n;
			}
		cout<<"if "<< t << " goto " << l1 <<" if False goto "<<l2 <<" ;"<<endl;
		cout<< l1 << ": ";TAC(temp->child->next->next->next->next->next);
		cout<<"goto "<<l3<<";\n";
		cout<< l2 << " : ";cout<<"goto "<<l3<<";\n";
		cout<<l3<<" :\n";
		return "";

	}

//i expect that i will return a<b from if_expression
	if(temp->node_name == "conditional_statement -> IF ( if_expression ) { inside_content } ELSE { inside_content }")
	{
	
		string l1 = new_label();
		string l2 = new_label();
		string l3 = new_label();
		string t = TAC(temp->child->next->next);


		if(t=="")
			{
				string n = new_var();
				cout<< n << " = 1;\n";//<< 
				t = n;
			}

		cout<<"if "<< t << " goto " << l1 <<" if False goto "<<l2 <<" ;"<<endl;
		cout<< l1 << ": ";TAC(temp->child->next->next->next->next->next);
		cout<<"goto "<<l3<<";\n";
		cout<< l2 << " : ";
		cout<<TAC(temp->child->next->next->next->next->next->next->next->next->next);
		cout<<"goto "<<l3<<";\n";
		cout<<l3<<" :\n";
		return "";
	}
	if(temp->node_name == "if_expression -> inside_if_expression")
	{
		return TAC(temp->child);
	}

	if(temp->node_name == "if_expression -> inside_if_expression  AND_AND  inside_if_expression")
	{
		string t0 = new_var();		
		string t1 = new_var();
		string t2 = new_var();	


		cout<< t0 << " = "<< TAC(temp->child)<< " ;\n";
		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " ;\n";
		cout<< t2 << " = "<< t0 << " && " << t1<< " ;" <<endl; 
		return t2;
	}


	if(temp->node_name == "if_expression -> inside_if_expression  OR_OR  inside_if_expression")
	{
		string t0 = new_var();		
		string t1 = new_var();
		string t2 = new_var();	


		cout<< t0 << " = "<< TAC(temp->child)<< " ;\n";
		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " ;\n";
		cout<< t2 << " = "<< t0 << " || " << t1 << " ;" <<endl; 
		return t2;
	}
	
	if(temp->node_name == "if_expression -> ( inside_if_expression CB")
	{
		return TAC(temp->child->next);
	}

	if(temp->node_name == "inside_if_expression -> expression EQUAL_EQUAL expression")
	{
		string t0 = new_var();		
		string t1 = new_var();
		string t2 = new_var();	


		cout<< t0 << " = "<< TAC(temp->child)<< " ;\n";
		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " ;\n";
		cout<< t2 << " = "<< t0 << " == " << t1 << " ;" <<endl; 
		return t2;
	}


	if(temp->node_name == "inside_if_expression -> expression NOT_EQUAL expression")
	{
		string t0 = new_var();		
		string t1 = new_var();
		string t2 = new_var();	


		cout<< t0 << " = "<< TAC(temp->child)<< " ;\n";
		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " ;\n";
		cout<< t2 << " = "<< t0 << " != " << t1 << " ;" <<endl; 
		return t2;
	}

	if(temp->node_name == "inside_if_expression -> expression LESS_THAN_EQUAL expression")
	{
		string t0 = new_var();		
		string t1 = new_var();
		string t2 = new_var();	


		cout<< t0 << " = "<< TAC(temp->child)<< " ;\n";
		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " ;\n";
		cout<< t2 << " = "<< t0 << " =< " << t1 << " ;" <<endl; 
		return t2;
	}


	if(temp->node_name == "expression GREATER_THAN_EQUAL expression")
	{
		string t0 = new_var();		
		string t1 = new_var();
		string t2 = new_var();	


		cout<< t0 << " = "<< TAC(temp->child)<< " ;\n";
		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " ;\n";
		cout<< t2 << " = "<< t0 << " >= " << t1 << " ;" <<endl; 
		return t2;
	}
	if(temp->node_name == "inside_if_expression -> expression < expression")
	{
		string t0 = new_var();		
		string t1 = new_var();
		string t2 = new_var();	


		cout<< t0 << " = "<< TAC(temp->child)<< " ;\n";
		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " ;\n";
		cout<< t2 << " = "<< t0 << " < " << t1 << " ;" <<endl; 
		return t2;
	}

	if(temp->node_name == "inside_if_expression -> expression > expression")
	{
		string t0 = new_var();		
		string t1 = new_var();
		string t2 = new_var();	


		cout<< t0 << " = "<< TAC(temp->child)<< " ;\n";
		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " ;\n";
		cout<< t2 << " = "<< t0 << " > " << t1 << " ;" <<endl; 
		return t2;
	}
	if(temp->node_name == "inside_if_expression -> ! expression")
	{
		string t0 = new_var();		
		string t1 = new_var();

		cout<< t0 << " = "<< TAC(temp->child->next)<< " ;\n";
		cout<< t1 << " = ! "<< t0 << " ;" <<endl; 
		return t1;
	}	
	if(temp->node_name == "inside_if_expression -> expression")
	{
		string t0 = new_var();		
		string t1 = new_var();

		cout<< t0 << " = "<< TAC(temp->child)<< " ;\n";
		cout<< t1 << " = "<< t0 <<" ;"<<endl; 
		return t1;
	}

if(temp->node_name == "function_statement -> function_statements declaration_statement N")
	{
		TAC(temp->child);
		TAC(temp->child->next);
	}
if(temp->node_name == "function_statement -> function_statements assignment_statement N")
	{
		TAC(temp->child);
		TAC(temp->child->next);
	}
if(temp->node_name == "function_statement -> function_statements input_output_statement")
	{
		TAC(temp->child);
		TAC(temp->child->next);
	}
if(temp->node_name == "function_statement -> function_statements function_calling_newline")
	{
		TAC(temp->child);
		TAC(temp->child->next);
	}
if(temp->node_name == "function_statement -> function_statements conditional_statement")
	{
		TAC(temp->child);
		TAC(temp->child->next);
	}
if(temp->node_name == "function_statement -> function_statements loop_statement")
	{
		TAC(temp->child);
		TAC(temp->child->next);
	}

if(temp->node_name == "function_statement -> function_statements array_statement N")
	{
		TAC(temp->child);
		TAC(temp->child->next);
	}




if(temp->node_name == "array_statement -> data_type array_declaration_recursive")
	{
		return TAC(temp->child->next);
	}
if(temp->node_name == "array_statement -> array_initialisation")
	{
		return TAC(temp->child);
		//TAC(temp->child->next);
	}
if(temp->node_name == "array_declaration_recursive -> STRING [ expression ]")
	{
		variables.insert(temp->child->data);
		return "";
		/*
		string sz; 
		string val_string = temp->child->data;
		if(sizeof_array(Table,val_string)== 8){sz = " 8";}
		else{sz = " 1";}

		string t1 = new_var();
		string t2 = new_var();
		string t3 = new_var();

		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " * " <<sz<<"; \n";
		cout<< t2 << " = "<< val_string << " + "<< t1 << " ; \n";
		cout<< t3 << " = "<< " * ( "<< t2 << " ) ;\n";*/
	}


if(temp->node_name == "array_declaration_recursive -> array_declaration_recursive , STRING [ expression ]")
	{
		variables.insert(temp->child->next->next->data);
		return "";
	}

if(temp->node_name == "array_initialisation -> STRING [ expression ] = expression")
	{
		//TAC(temp->child);
		string sz; 
		string val_string = temp->child->data;
		if(sizeof_array(Table,val_string)== 8){sz = " 8";}
		else{sz = " 1";}

		string t1 = new_var();
		string t2 = new_var();
		string t3 = new_var();
		
variables.insert(temp->child->data);
		cout<< t1 << " = "<< TAC(temp->child->next->next)<< " * " <<sz<<"; \n";
		cout<< t2 << " = "<< val_string << " + "<< t1 << " ; \n";
		cout<< "* ( "<< t2 << " ) = "<<TAC(temp->child->next->next->next->next->next)<< " ;\n";

	}
//sizeof_array(Table,"ab")



if(temp->node_name == "loop_statement -> FOR ( loop_initialisation N loop_condition N loop_update ) { loop_content }")
{
	//string init  =
	 cout<<TAC(temp->child->next->next);

	//string cond = TAC(temp->child->next->next->next->next);	
	//string update = TAC(temp->child->next->next->next->next->next->next);	
	//string content = TAC(temp->child->next->next->next->next->next->next->next->next->next);			//init done 

	string l1 = new_label();
	string l2 = new_label();
	string l3 = new_label();
	//if(cond == ""){cond  = "1";}

	cout<<l1<<" :\n";
	string cond = TAC(temp->child->next->next->next->next) ;

	if(cond=="")
			{
				string n = new_var();
				cout<< n << " = 1;\n";//<< 
				cond = n;
			}

	cout << "if "<<cond<< " goto "<<l2 << " if False goto "<< l3 << " ;" << endl;
	
	cout<< l2 << " : ";
	cout<<TAC(temp->child->next->next->next->next->next->next->next->next->next);
	
	cout<< TAC(temp->child->next->next->next->next->next->next);
	
	cout<< "goto "<< l1<< " ;" <<endl;
	
	cout<< l3 <<" : ";


}


if(temp->node_name == "loop_initialisation -> declaration_statement")
{
	return TAC(temp->child);
}

if(temp->node_name == "loop_initialisation -> assignment_statement")
{
	return TAC(temp->child);
}
if(temp->node_name == "loop_condition -> loop_condition , if_expression")
{
	TAC(temp->child);
	TAC(temp->child->next->next);
}

if(temp->node_name == "loop_update -> loop_update , assignment_statement")
{
	return TAC(temp->child);TAC(temp->child->next->next);
}
if(temp->node_name == "loop_content -> function_statements")
{
	return TAC(temp->child);
}

if(temp->node_name == "inside_content -> function_statements")
{
	return TAC(temp->child);
}


if(temp->node_name == "assignment_statement -> increment_operator")
{
	return TAC(temp->child);
}

if(temp->node_name == "increment_operator -> STRING PLUS_PLUS")
{
	string val = temp->child->data;
	variables.insert(temp->child->data);
	string a = new_var();
	cout<<a<< " =  1;\n";//<<
	cout<< val << " = "<< val << " + "<<a<<" ; \n"; 
}

if(temp->node_name == "increment_operator -> STRING MINUS_MINUS")
{
	string val = temp->child->data;
	variables.insert(temp->child->data);
	cout<< val << " = "<< val << " - 1 ; \n"; 
}

if(temp->node_name == "declaration_assignment_expression -> STRING = expression")
{
	variables.insert(temp->child->data);
	cout<< temp->child->data << " = "<< TAC(temp->child->next->next)<< " ;\n";
}


if(temp->node_name== "main_function -> MAIN { function_statements }")
{
	cout<<endl<<endl;
	//cout<<"\n#Main : \n";
	//cout<< "\n#begin_function : \n";
	TAC(temp->child->next->next);
	//cout<< "\n#end_function\n";
}
if(temp->node_name== "program -> function_declaration main_function")
{	
	TAC(temp->child);
	 TAC(temp->child->next);
}

if(temp->node_name =="declaration_statement -> data_type declaration_expression")
{
	return TAC(temp->child->next);
}


if(temp->node_name == "declaration_expression -> STRING")
{
	variables.insert(temp->child->data);
	return "";
}


if(temp->node_name == "declaration_expression -> declaration_expression , STRING")
{
	variables.insert(temp->child->next->next->data);
	return TAC(temp->child);
}

if(temp->node_name == "declaration_expression -> declaration_assignment_expression")
{
	return TAC(temp->child);
}
if(temp->node_name == "declaration_expression -> declaration_expression , declaration_assignment_expression")
{
	TAC(temp->child);
	TAC(temp->child->next->next);
}

if(temp->node_name == "loop_condition -> if_expression")
{
	return TAC(temp->child);
}


if(temp->node_name == "loop_update -> assignment_statement")
{
	return TAC(temp->child);
}

/*
if(temp->node_name == "header_by_user -> header_by_user INCLUDE STRING H N")
{
	return TAC(temp->child);
	//TAC(temp->child->next)
}

if(temp->node_name == "macro_statement -> macro_statement MACRO STRING STRING N")
{
	return TAC(temp->child);
}
*/

if(temp->node_name == "function_declaration -> function_declaration function_name ( function_arguments ) { function_statements RETURN return_type N }")
{
	TAC(temp->child);

	string args = TAC(temp->child->next->next->next);
	Table[temp->child->next->child->next->data].second.second = arguments ; 

	cout<<"Func Begin "<<temp->child->next->child->next->data<<" "<<arguments<<":\n";
	cout<<args;



	cout<<TAC(       temp->child->next->next->next->next->next->next);
	
	string aaa  = TAC(temp->child->next->next->next->next->next->next->next->next);
	
	
	arguments = 0 ;
	cout<<"Return "<<aaa<<";\n";
	
	cout<<"Func End;\n";
}



if(temp->node_name == "function_declaration -> function_declaration data_type  STRING N")
{
	TAC(temp->child);

	variables.insert(temp->child->next->next->data);
	return "";
}

if(temp->node_name == "function_declaration -> function_declaration data_type  STRING '[' VALUE ']' N")
{
	TAC(temp->child);
	variables.insert(temp->child->next->next->data);
	return "";
}

if(temp->node_name == "function_name -> data_type STRING")
{
	//variables.insert(temp->child->next->next->data);
	return "";
}
if(temp->node_name == "function_arguments -> data_type STRING")
{
	variables.insert(temp->child->next->data);
	arguments ++;
	string name =  temp->child->next->data ;
	return "Recp " + name + ";\n";
	//return "";
}

if(temp->node_name == "function_arguments -> function_arguments ',' data_type STRING")
{
	variables.insert(temp->child->next->next->next->data);
	arguments ++;
	string name = temp->child->next->next->next->data;
	return TAC(temp->child) + "Recp " + name  + ";\n";
	//return "";
}


if(temp->node_name == "function_arguments -> data_type POINTER STRING")
{
	variables.insert(temp->child->next->next->data);
	return "";
}


if(temp->node_name == "function_arguments -> function_arguments ',' data_type POINTER STRING")
{
	variables.insert(temp->child->next->next->next->next->data);
	return "";
}







if(temp->node_name == "function_arguments -> data_type STRING '[' VALUE ']'")
{
	variables.insert(temp->child->next->data);
	return "";
}

if(temp->node_name == "function_arguments -> function_arguments ',' data_type STRING '[' VALUE ']'")
{
	variables.insert(temp->child->next->next->next->data);
	return "";
}

if(temp->node_name == "return_type -> variable_or_value_or_function_call")
{								
	
	//variables.insert(temp->child->next->next->next->next->data);
		//cout<<"here";
	return TAC(temp->child);
}


if(temp->node_name == "variable_or_value_or_function_call -> STRING '(' function_call_variables ')'")
{				
	
	//variables.insert(temp->child->next->next->next->next->data);
		//cout<<"here";
	cout<<TAC(temp->child->next->next);
	string ret = new_var();
	cout<<ret << " = Call ";
	cout<<temp->child->data<<","<<Table[temp->child->data].second.second;
	cout<<";\n";
	return ret;
}



if(temp->node_name == "function_calling_newline -> STRING '(' function_call_variables ')' N")
{				
	
	//variables.insert(temp->child->next->next->next->next->data);
	//cout<<"here";
	cout<<TAC(temp->child->next->next);
	string ret = new_var();
	cout<<ret << " = Call ";
	cout<<temp->child->data<<" , "<<Table[temp->child->data].second.second;
	cout<<";\n";
	return ret;


}if(temp->node_name == "function_calling_newline -> STRING '=' STRING '(' function_call_variables ')' ';'")
{				
	
	//variables.insert(temp->child->next->next->next->next->data);
	//	cout<<"here";
	cout<<TAC(temp->child->next->next);
	cout<<"Call "<<temp->child->data<<" , "<<temp->child->data<<";\n";
}



if(temp->node_name == "function_call_variable -> expression")
{				
	
	//variables.insert(temp->child->next->next->next->next->data);
	//	cout<<"here";
	cout<<"Push "<<TAC(temp->child)<<";\n";
	//cout<<"call "<<temp->child->data<<";\n";
}

if(temp->node_name == "function_call_variable -> function_call_variables , expression")
{				
	
	//variables.insert(temp->child->next->next->next->next->data);
	//	cout<<"here";
	TAC(temp->child);
	cout<<"Push "<<TAC(temp->child->next->next)<<";\n";
	//cout<<"call "<<temp->child->data<<";\n";
}

if(temp->node_name == "input_output_statement -> QUICKOUT BACKWARD remaining_statement_out N")
{				
	
	cout<<"Print "<<TAC(temp->child->next->next)<<";\n";
}


if(temp->node_name == "remaining_statement_out -> expression")
{				
	
	return TAC(temp->child);
}
if(temp->node_name == "remaining_statement_out -> remaining_statement_out  BACKWARD expression")
{				
	
	TAC(temp->child);
	return TAC(temp->child->next->next);
}


if(temp->node_name == "function_statement -> function_statements RETURN return_type N")
{				
	
	
	cout<< TAC(temp->child) + "Return " + TAC(temp->child->next->next)<<";\n";
}





	return "";
}







string Print_data (Syntax_Tree * p)
{
	//cout<<"here 4444444444444444444444444444444444444444444444444";cout<<p->data;
	return p->child->data;
}
///at least I have to pass one
Syntax_Tree * make_node ( const char * data)
{
	Syntax_Tree * one = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
	one->data = data;
	one->node_name  = data;
	return one;
}
Syntax_Tree * make_node_parent (const  char * data)
{
	Syntax_Tree * one = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
	one->last=1;
	one->has_child=1;
	one->data = data;
	one->node_name  = data;
	return one;
}

Syntax_Tree * make_terminal_node_new ( const char * data1, const  char * data2, const  char * data3,const   char * data4, const  char * data5 , int which_is_last ,const char *  _1,const char *  _2,const char *  _3,const char *  _4,const char *  _5,int val)
{
	//cout<<"asda";
	//cout<<data1<<" "<<data2<<" "<<data3<<" "<<data4<<" "<<data5<<" "<<endl;
	//if(data2 == NULL){cout<<"uck0ff";}
		Syntax_Tree * one = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		Syntax_Tree * two = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		Syntax_Tree * three = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		Syntax_Tree * four = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		Syntax_Tree * five = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		one->has_child = 0 ;
		two->has_child = 0 ;
		three->has_child = 0 ;
		four->has_child = 0 ;
		five->has_child = 0 ;


		one->node_name  = _1;
		two->node_name  = _2;
		three->node_name  = _3;
		four->node_name  = _4;
		five->node_name  = _5 ;

		one->val  = val;
		two->val  = val;
		three->val  = val;
		four->val = val;
		five->val  = val;

	if(data1 != NULL)
	{
		which_is_last --;

		one->my_type = 1 ;
		one->data = data1;
		//cout<<one->data;
		if(which_is_last > 0)
			{one->last = 0;}
		else {one->last  = 1;}
	}
	if(data2 != NULL)
	{
		which_is_last --;

		two->my_type = 1 ;
		two->data = data2;
		one->next = two;
		//cout<<two->data;
		if(which_is_last > 0){two->last = 0;}
		else {two->last  = 1;}
	}
	if(data3 != NULL)
	{
		which_is_last --;

		three->my_type = 1 ;
		three->data = data3;
		two->next = three;
		//cout<<three->data;
		if(which_is_last > 0){three->last = 0;}
		else {three->last  = 1;}
	}
	if(data4 != NULL)
	{
		which_is_last --;

		four->my_type = 1 ;
		four->data = data4;
		three->next = four;
		//cout<<four->data;
		if(which_is_last > 0)
			{four->last = 0;}
		else {four->last  = 1;}
	}
	if(data5 != NULL)
	{
		which_is_last --;

		five->my_type = 1 ;
		five->data = data5;
		four->next = five;
		//cout<<five->data;
		if(which_is_last > 0){five->last = 0;}
		else {five->last  = 1;}
	}
	//cout<<endl<<endl<<endl<<endl;
	return one;
}


Syntax_Tree * make_terminal_node ( const char * data1, const  char * data2, const  char * data3,const   char * data4, const  char * data5 , int which_is_last )
{
	//cout<<"asda";
	//cout<<data1<<" "<<data2<<" "<<data3<<" "<<data4<<" "<<data5<<" "<<endl;
	//if(data2 == NULL){cout<<"uck0ff";}
		Syntax_Tree * one = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		Syntax_Tree * two = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		Syntax_Tree * three = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		Syntax_Tree * four = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		Syntax_Tree * five = (Syntax_Tree*) malloc (sizeof(Syntax_Tree));
		one->has_child = 0 ;
		two->has_child = 0 ;
		three->has_child = 0 ;
		four->has_child = 0 ;
		five->has_child = 0 ;
	if(data1 != NULL)
	{
		which_is_last --;

		one->my_type = 1 ;
		one->data = data1;
		//cout<<one->data;
		if(which_is_last > 0)
			{one->last = 0;}
		else {one->last  = 1;}
	}
	if(data2 != NULL)
	{
		which_is_last --;

		two->my_type = 1 ;
		two->data = data2;
		one->next = two;
		//cout<<two->data;
		if(which_is_last > 0){two->last = 0;}
		else {two->last  = 1;}
	}
	if(data3 != NULL)
	{
		which_is_last --;

		three->my_type = 1 ;
		three->data = data3;
		two->next = three;
		//cout<<three->data;
		if(which_is_last > 0){three->last = 0;}
		else {three->last  = 1;}
	}
	if(data4 != NULL)
	{
		which_is_last --;

		four->my_type = 1 ;
		four->data = data4;
		three->next = four;
		//cout<<four->data;
		if(which_is_last > 0)
			{four->last = 0;}
		else {four->last  = 1;}
	}
	if(data5 != NULL)
	{
		which_is_last --;

		five->my_type = 1 ;
		five->data = data5;
		four->next = five;
		//cout<<five->data;
		if(which_is_last > 0){five->last = 0;}
		else {five->last  = 1;}
	}
	//cout<<endl<<endl<<endl<<endl;
	return one;
}

char * dtos(const double num)
{

	  stringstream to_return;
	  to_return << num;
	 register string temp_str = to_return.str();
	  char* to_ret = (char*) temp_str.c_str();
	  return to_ret;
	/*stringstream ss;
	ss<<num;
	char *  temp;
	temp=ss.str();





	/*char * to_return;
	int len = temp.length();
	for (int j=0;j<len;j++)
	{
		to_return[j] = temp[j];
		cout<<temp[j]<<" brrrrrrr"<<endl;
	}
	//to_return[len] = '\0';
	/*int i = 0;
	while(temp[i]!='\0')
	{
		cout<<temp[i]<<" brrrrrrr"<<endl;
		//to_return[i] = temp[i];
		i++;
	}*/
	//char * to_return = temp.c_str();
	//char* to_ret = to_return;*/
	//char to_return[15];
	//sprintf(to_return, "%lf", num);
//	char * to_return = "ciye";
	//return to_return;
}
void PreOrderTraversal(Syntax_Tree * temp)

{
    cout<<temp->has_child<<" "<<temp->last<<" ";
	cout<<temp->data<<endl;
	if(temp->has_child==1)
	{
		PreOrderTraversal(temp->child);
	}
	if(temp->last!=1)
	{	//cout<<endl;
		PreOrderTraversal(temp->next);
		//cout<<endl;
	}
}

void PreOrderTraversalSimulate(Syntax_Tree * temp)
{
	cout<<"Traversal Begins here\n";
int inp,check;
check =0;	
Syntax_Tree * remember;
remember = temp;
Syntax_Tree * remember_previous;
cout<<" if has child == 1 -> the current node has a child\n";
cout<<" if Is last == 1 -> the current node is the last\n";
cout<<"has_child "<<temp->has_child<<" Is last  "<<temp->last<<" ";
cout<<temp->data<<endl;
	while(true)
	{

		while(true)
		{
			
			
			cout<<"Enter which node to go 1(child) or 2(sibling) or 3(previous)    8 to restart  and  9 to exit"<<endl;
			cin >> inp ;
			if(inp == 3)
			{
				temp = remember_previous;
				continue;
			}
			else if(inp ==9)
			{
				check = 0;
				break;
			}
			else if(inp ==8)
			{
				check = 1;
				break;
			}
			else if(inp == 1)
			{
				if(temp->has_child==1)
				{
					remember_previous = temp;
					cout<<"Going to child"<<endl;
					cout<<"has_child "<<temp->child->has_child<<" Is last  "<<temp->child->last<<"  ";
					cout<<temp->child->data<<endl;
					temp = temp->child;
				}
				else
				{
					cout<<"this node has no child "<<endl<<endl;
					continue;
				}
			}
			else if(inp == 2)
			{
				if(temp->last != 1)
				{
					remember_previous = temp;
					cout<<"Going to sibling"<<endl;
					cout<<"has_child "<<temp->next->has_child<<" Is last  "<<temp->next->last<<"  ";
					cout<<temp->next->data<<endl;
					temp = temp->next;
				}
				else
				{
					cout<<"this node has no sibling "<<endl<<endl;
					continue;
				}
			}
			else
			{
				cout << "please enter either 1 or 2";
				continue;
			}
			
		}
		if(check == 1)
		{
			temp = remember;
		}
		else if (check == 0)
		{
			break;
		}
		check=0;
	}	
}
void print_val(Syntax_Tree * temp)
{
	cout<<" last "<<temp->last;
	cout<<" child "<<temp->has_child<<endl;
}



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
void Table_insert(string name,string type ,string what_is_this, double limit)
{
	Table[name] = make_pair( type , make_pair(what_is_this, limit));
	//int_map[make_pair($2,$3)] = 0; cout<<$3<<endl;printf("value initialised \n");
}


void check_array_declaration_recursive(string type, Syntax_Tree * p)
{
    if(p->child->has_child==0)
    {
        if(Table_check(p->child->data)){cout<<"Found duplicate : "<<p->child->data<<endl;}
		    else {Table_insert(p->child->data, type, "array", 0);}
    }
    else
    {
        if(Table_check(p->child->next->next->data)){cout<<"Found duplicate : "<<p->child->next->next->data<<endl;}
		    else {Table_insert(p->child->next->next->data, type, "array", 0);}
		check_array_declaration_recursive(type, p->child);
    }
}

void check_declaration_recursive(string type, Syntax_Tree * p)
{
	//cout<<"here 4444444444444444444444444444444444444444444444444";
    if(p->child->has_child == 0)
    {
    		//cout<<"11111111111111111111";
        if(Table_check(p->child->data)){cout<<"Found duplicate : "<<p->child->data<<endl;}
		    else {Table_insert(p->child->data, type, "normal", 0);}
    }
    else if(strcmp (p->data ,"declaration_expression -> declaration_assignment_expression") == 0) 
    {
    		//cout<<"22222222222222222222";
    	if(Table_check(p->child->child->data))
    		{cout<<"Found duplicate : "<<p->child->child->data<<endl;}
		else 
		{
			int t;
			if(strcmp(p->child->child->next->next->data, " # ") == 0)
			{
							if(type != "int")
							{
								Table_insert(p->child->child->data, type, "normal", 0);
							}
							else
							{
								cout<<"type mismatch"<<endl;
							}
			}
			else
			{


							if(type == "int")
							{
								t=0;
							}
							else
							{
								t=1;
							}
							if(p->child->child->next->next->type == t)
							{
								Table_insert(p->child->child->data, type, "normal", 0);
							}
							else
							{
								cout<<"type mismatch"<<endl;
							}


			}

		}

    }
    else if(strcmp(p->data , "declaration_expression -> declaration_expression , STRING") == 0) 
    {
    		//cout<<"333333333333333333333";
	        if(Table_check(p->child->next->next->data)){cout<<"Found duplicate : "<<p->child->next->next->data<<endl;}
			    else {Table_insert(p->child->next->next->data, type, "normal", 0);}
			check_declaration_recursive(type, p->child);
    }
    else if(strcmp(p->data , "declaration_expression -> declaration_expression , declaration_assignment_expression") == 0)
    {
    		//cout<<"4444444444444444444444";
    	if(Table_check(p->child->next->next->child->data))
    		{cout<<"Found duplicate : "<<p->child->next->next->child->data<<endl;}
		    else 
		    {
					    int t;
						if(strcmp(p->child->next->next->child->next->next->data, " # ") == 0)
						{
										if(type != "int")
										{
											Table_insert(p->child->next->next->child->data, type, "normal", 0);
										}
										else
										{
											cout<<"type mismatch"<<endl;
										}
						}
						else
						{


										if(type == "int")
										{
											t=0;
										}
										else
										{
											t=1;
										}
										if(p->child->next->next->child->next->next->type == t)
										{
											Table_insert(p->child->next->next->child->data, type, "normal", 0);
										}
										else
										{
											cout<<"type mismatch"<<endl;
										}


						}
			}

		check_declaration_recursive(type, p->child);
    }
    else
    	{cout << "something has gone wrong in check_declaration_recursive" << endl;
		cout << "child ka data is " << p->child->data << endl;
		}
	
}









