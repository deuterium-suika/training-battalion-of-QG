#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "SqStack.h"
Status Transform(SqStack *s1,SqStack *s2)
{
	//s1Ϊ��׺���ʽ��s2����ת���ĺ�׺���ʽ 
	char c,data;
	printf("������׺���ʽ����#Ϊ������־");	
	scanf("%c",&c);
	while(c != '#') 
	{
		if(isdigit(c))
		{
			//���Ϊ����ѹջs2 
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
			//'+''-'���ȼ���
			if(isEmptyStack(&s1)) 
			{
				//���Ϊ�� 
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
			printf("����");
			return ERROR; 
		}
	}
}
