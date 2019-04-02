#include "fun.h"
char priority(ElemType a,ElemType b)
{
	//判断a b的优先级，优先级由高到低 （*/+-)# 
	char result;
	switch(b)
	{
		case'+':
		case'-':if(a == '('||a == '\n')//b为'+''-'优先级 
					result='<';//a<b
				else
					result='>';//a>b
				break;
		case'*':
		case'/':if(a == '*'||a == '/'||a ==')')
					result = '>';//a>b
				else
					result = '<';//a<b
				break;
		case'(':if(a == ')')
					{
						printf("ERROR\n");
						exit(0);
					 } 
				else
				result = '<';//a<b
				break;
		case')':switch(a)
				{
					case '(': result = '=';//a = b
							  break;
					case '\n':printf("缺左括号\n");
							  exit(0);
					default: result ='>'; //a>b
				} 
				break;
		case '\n' :switch(a)
					{
						case '\n' :result = '=';//a = b
									break;
						case '(' :printf ("缺左括号\n");
								  exit(0);
						default :result='>';//a>b
					}
					
	 } 
	 return result;
}

Status In(ElemType a)
{
	//判断是否为运算符
	switch(a)
	{
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'\n':return SUCCESS;
		default: return ERROR;
	}
}

ElemType Operate(ElemType a,ElemType yunSuan,ElemType b)
{
	//a 运算b x为运算符
	switch(yunSuan)
	{
		case'+':return a + b;
		case'-':return a - b;
		case'*':return a * b;
	 } 
	 return a/b;
}


