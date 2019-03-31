#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> 
#include "SqStack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SqStack s; int a=0; 
	do                      
	{
		printf("****************\n");
		printf("\t1--初始化\n");
		printf("\t2--是否为空\n");
		printf("\t3--得到栈顶元素\n");
		printf("\t4--清空栈\n");
		printf("\t5--销毁栈\n");
		printf("\t6--检测栈的长度\n");
		printf("\t7--入栈\n");
		printf("\t8--出栈\n");
		printf("\t0--退出\n");
		printf("****************\n");
		printf("请选择你要进行的操作：");
		scanf("%d",&a);
		getchar();
		switch(a){
			case 1:
				{
					int n=0;
					printf("创建栈大小为：\n");
					scanf("%d",&n);
					initStack(&s,n);
					break;
				}
			case 2:if(isEmptyStack(&s))
				{
					printf("为空\n");
				} 
				else printf("不为空\n");
				break; 	   
			case 3:
				{
					int e = 0; 
					getTopStack(&s,&e);
					printf("栈顶元素为%d\n",e);
					break; 
				}
			case 4:
				clearStack(&s); 
				break;
			case 5:
				destroyStack(&s);
				break;
			case 6:
				{
					int length=0; 
					stackLength(&s,&length);
					printf("栈的长度为%d\n",length);
					break;
				}
			case 7:
			{
				int add = 0;
				printf("请输入压栈的数据:\n");
				scanf("%d",&add);
				pushStack(&s,add);
				break;
			}
			case 8:
				{
					int pop;
					popStack(&s,&pop);
					printf("出栈数据为:%d\n",pop);
					break;
				}
			default:
				exit(0);
		}
	}while(a!=0);
	return 0;
}

