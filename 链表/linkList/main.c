#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../head/duLinkedList.h"
#include "../head/linkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	LinkedList L;ElemType e = 0;int a = 0;
	do
	{
		printf("****************\n");
		printf("\t1--��ʼ��\n");
		printf("\t2--ɾ��\n");
		printf("\t3--����\n");
		printf("\t4--��\n");
		printf("\t5--ת��\n");
		printf("\t6--�Ƿ�ɻ�\n");
		printf("\t7--ת��ż��\n");
		printf("\t0--�˳�\n");
		printf("****************\n");
		printf("��ѡ����Ҫ���еĲ�����");
		scanf("%d",&a);
		getchar();
		switch(a){
			case 1:InitList(L);
				int n=0,i,l;
				printf("����������Ϊ��");
				scanf("%d",&l);
				for (i=0;i<l;i++){
					LNode *p = NULL ;
					p=(LNode*)malloc(sizeof(LNode));
					printf("�������%d��������ݣ�\n",i+1);
					scanf("%d",&p->data);
					p->next = L->next;L->next = p;
				}
				break;
			case 2:DestroyList(L); break; 	   
			case 3:TraverseList(L, visit); 
			case 4:printf("������ҵ�ֵΪ��");
				   int e = 0;
				   scanf("%d",&e);
				   SearchList(L,e);
				   break;
			case 5:ReverseList(L);break;
			case 6:if(IsLoopList(L)){
				printf("�ɻ�");
				}else printf("���ɻ�"); 
				break;
			case 7:L = ReverseEvenList(L);break;
		}
	}while(a!=0);
	return 0;
}
