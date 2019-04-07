#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
LQueue Q; int a;
	do                      
	{
		printf("****************\n");
		printf("\t1--��ʼ������\n");
		printf("\t2--���ٶ���\n");
		printf("\t3--�Ƿ�Ϊ��\n");
		printf("\t4--�õ���ͷԪ��\n");
		printf("\t5--�õ����г���\n");
		printf("\t6--���\n");
		printf("\t7--����\n");
		printf("\t8--��ն���\n");
		printf("\t9--��������\n");
		printf("\t0--�˳�\n");
		printf("****************\n");
		printf("��ѡ����Ҫ���еĲ�����");
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
					printf("Ϊ��\n");
				} 
				else printf("��Ϊ��\n");
				break; 	   
			case 4:
				{
				void* e = NULL;
				GetHeadLQueue(&Q, &e); 
				LPrint(&e);
				break;
				}
			case 5:
				printf("���г���Ϊ%d\n",LengthLQueue(&Q)); 
				break;
			case 6:
				{
					void* data; 
					while(scanf("%d",&data) != 1) printf("�������");
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
