#include "fun.h"
char priority(ElemType a,ElemType b)
{
	//�ж�a b�����ȼ������ȼ��ɸߵ��� ��*/+-)# 
	char result;
	switch(b)
	{
		case'+':
		case'-':if(a == '('||a == '\n')//bΪ'+''-'���ȼ� 
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
					case '\n':printf("ȱ������\n");
							  exit(0);
					default: result ='>'; //a>b
				} 
				break;
		case '\n' :switch(a)
					{
						case '\n' :result = '=';//a = b
									break;
						case '(' :printf ("ȱ������\n");
								  exit(0);
						default :result='>';//a>b
					}
					
	 } 
	 return result;
}

Status In(ElemType a)
{
	//�ж��Ƿ�Ϊ�����
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
	//a ����b xΪ�����
	switch(yunSuan)
	{
		case'+':return a + b;
		case'-':return a - b;
		case'*':return a * b;
	 } 
	 return a/b;
}


