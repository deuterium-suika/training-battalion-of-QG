#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "SqStack.h"
#include "calculate.h"
#include "fun.h"
Status calculate()
{
	SqStack yunSuanfu,yunSuanshu;
	ElemType a,b,d,e;
	char c;
	initStack(&yunSuanfu,100);
	initStack(&yunSuanshu,100);
	pushStack(&yunSuanfu,'\n');//���з�ѹ�������ջ��
	c = getchar();//c�õ��û����� 
	getTopStack(&yunSuanfu,&e);//ջ������e
	while(c!='\n'||e!='\n')
	{
		//c�õ�������δ����  
		if(In(c))//c�������
			switch(priority(e,c))//�ж�e��c���ȼ�
			{
				case'<':pushStack(&yunSuanfu,c);//�����ջ��e���ȼ�����c,c��ջ
				c = getchar();
				break;
				
				case'=':popStack(&yunSuanfu,&e);//e='('c=')'
						c = getchar();
						break;
				case'>':popStack(&yunSuanfu,&e);//e���ȼ��� 
						popStack(&yunSuanshu,&b);//�������������� 
						popStack(&yunSuanshu,&a);
						pushStack(&yunSuanshu,Operate(a,e,b));
			}
		else if(c>='0'&&c<='9')
		{
			//cΪ������
			d = 0;
			while(c>='0'&&c<='9')
			{
				//cΪ�������� 
				d =d * 10 + c - '0';
				c = getchar();
			 } 
			 pushStack(&yunSuanshu,d);
		}
		else //�Ƿ����� 
		{
			printf("�Ƿ�����");
			exit(0); 
		}	        
		 getTopStack(&yunSuanfu,&e);//ջ���������e                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	 } 
	 popStack(&yunSuanshu,&e);//����������
	 return e;
}
