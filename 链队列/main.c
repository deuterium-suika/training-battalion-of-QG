#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
LQueue Q; int a;
	do                      
	{
		printf("****************\n");
		printf("\t1--初始化队列\n");
		printf("\t2--销毁队列\n");
		printf("\t3--是否为空\n");
		printf("\t4--得到队头元素\n");
		printf("\t5--得到队列长度\n");
		printf("\t6--入队\n");
		printf("\t7--出队\n");
		printf("\t8--清空队列\n");
		printf("\t9--遍历队列\n");
		printf("\t0--退出\n");
		printf("****************\n");
		printf("请选择你要进行的操作：");
		scanf("%d",&a);
		getchar();
		switch(a){
			case 1:
				{
					InitLQueue(&Q); 
					break;
				}
			case 2:
				DestoryLQueue(&Q); 
				break; 	   
			case 3:
				if(IsEmptyLQueue(&Q))
				{
					printf("为空\n");
				} 
				else printf("不为空\n");
				break; 	   
			case 4:
				{
				void* e = NULL;
				GetHeadLQueue(&Q, &e); 
				LPrint(&e);
				break;
				}
			case 5:
				printf("队列长度为%d\n",LengthLQueue(&Q)); 
				break;
			case 6:
				{
					void* data; 
					while(scanf("%d",&data) != 1) printf("输入错误");
					EnLQueue(&Q, &data);
					break;
				}
			case 7:
			{
				DeLQueue(&Q);
				break;
			}
			case 8:
				{
					ClearLQueue(&Q);
				}
			case 9:
				{
					TraverseLQueue(&Q, LPrint);
				 } 
			default:
				exit(0);
		}
	}while(a!=0);
	return 0; 
}
