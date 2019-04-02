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
	pushStack(&yunSuanfu,'\n');//还行符压入运算符栈底
	c = getchar();//c得到用户输入 
	getTopStack(&yunSuanfu,&e);//栈顶赋给e
	while(c!='\n'||e!='\n')
	{
		//c得到的输入未换行  
		if(In(c))//c是运算符
			switch(priority(e,c))//判断e和c优先级
			{
				case'<':pushStack(&yunSuanfu,c);//运算符栈顶e优先级低于c,c入栈
				c = getchar();
				break;
				
				case'=':popStack(&yunSuanfu,&e);//e='('c=')'
						c = getchar();
						break;
				case'>':popStack(&yunSuanfu,&e);//e优先级高 
						popStack(&yunSuanshu,&b);//运算数弹出计算 
						popStack(&yunSuanshu,&a);
						pushStack(&yunSuanshu,Operate(a,e,b));
			}
		else if(c>='0'&&c<='9')
		{
			//c为操作数
			d = 0;
			while(c>='0'&&c<='9')
			{
				//c为连续数字 
				d =d * 10 + c - '0';
				c = getchar();
			 } 
			 pushStack(&yunSuanshu,d);
		}
		else //非法输入 
		{
			printf("非法输入");
			exit(0); 
		}	        
		 getTopStack(&yunSuanfu,&e);//栈顶运算符给e                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	 } 
	 popStack(&yunSuanshu,&e);//弹出运算数
	 return e;
}
