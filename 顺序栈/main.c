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
		printf("\t1--��ʼ��\n");
		printf("\t2--�Ƿ�Ϊ��\n");
		printf("\t3--�õ�ջ��Ԫ��\n");
		printf("\t4--���ջ\n");
		printf("\t5--����ջ\n");
		printf("\t6--���ջ�ĳ���\n");
		printf("\t7--��ջ\n");
		printf("\t8--��ջ\n");
		printf("\t0--�˳�\n");
		printf("****************\n");
		printf("��ѡ����Ҫ���еĲ�����");
		scanf("%d",&a);
		getchar();
		switch(a){
			case 1:
				{
					int n=0;
					printf("����ջ��СΪ��\n");
					scanf("%d",&n);
					initStack(&s,n);
					break;
				}
			case 2:if(isEmptyStack(&s))
				{
					printf("Ϊ��\n");
				} 
				else printf("��Ϊ��\n");
				break; 	   
			case 3:
				{
					int e = 0; 
					getTopStack(&s,&e);
					printf("ջ��Ԫ��Ϊ%d\n",e);
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
					printf("ջ�ĳ���Ϊ%d\n",length);
					break;
				}
			case 7:
			{
				int add = 0;
				printf("������ѹջ������:\n");
				scanf("%d",&add);
				pushStack(&s,add);
				break;
			}
			case 8:
				{
					int pop;
					popStack(&s,&pop);
					printf("��ջ����Ϊ:%d\n",pop);
					break;
				}
			default:
				exit(0);
		}
	}while(a!=0);
	return 0;
}

