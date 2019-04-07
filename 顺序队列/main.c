#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	AQueue Q; int a;
	do                      
	{
		printf("****************\n");
		printf("\t1--��ʼ������\n");
		printf("\t2--�����Ƿ���\n");
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
					InitAQueue(&Q);
					break;
				}
			case 2:if(IsFullAQueue(&Q))
				{
					printf("Ϊ��\n");
				} 
				else printf("��Ϊ��\n");
				break; 	   
			case 3:
				if(IsEmptyAQueue(&Q))
				{
					printf("Ϊ��\n");
				} 
				else printf("��Ϊ��\n");
				break; 	   
			case 4:
				{
				void* e = NULL;
				GetHeadAQueue(&Q, &e); 
				APrint(&e);
				break;
				}
			case 5:
				printf("���г���Ϊ%d\n",LengthAQueue(&Q)); 
				break;
			case 6:
				{
					void* data; 
					while(scanf("%d",&data) != 1) printf("�������");
					EnAQueue(&Q, &data);
					break;
				}
			case 7:
			{
				DeAQueue(&Q);
				break;
			}
			case 8:
				{
					ClearAQueue(&Q);
				}
			case 9:
				{
					TraverseAQueue(&Q, APrint);
				 } 
			default:
				exit(0);
		}
	}while(a!=0);
	return 0; 
} 
