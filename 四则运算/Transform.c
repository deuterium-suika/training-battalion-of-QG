#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "SqStack.h"
Status Transform(SqStack *s1,SqStack *s2)
{
	//s1为中缀表达式，s2储存转化的后缀表达式 
	char c,data;
	printf("输入中缀表达式，以#为结束标志");	
	scanf("%c",&c);
	while(c != '#') 
	{
		if(isdigit(c))
		{
			//如果为数字压栈s2 
			pushStack(&s2,c);
		}
		else if(c == ')')
		{
			popStack(&s1,&data);
			while(data != '(')
			{
				pushStack(&s2,data);
				popStack(&s1,&data);
			}
		}
		else if('+' || '-')
		{
			//'+''-'优先级低
			if(isEmptyStack(&s1)) 
			{
				//如果为空 
				pushStack(&s2,c);
			}
			else
			{
				do
				{
					popStack(&s1,&data);
					if(data == '(')
					{
						pushStack(&s1,c);
					}
					else
					{
						pushStack(&s2,data);
					}
				}while(isEmptyStack(&s1)|| data == '(');
				pushStack(&s1,c);
			}
		}
		else if(c == '*'||c=='/'||c=='(')
		{
			pushStack(&s1,c);
		}
		else
		{
			printf("出错");
			return ERROR; 
		}
	}
}
