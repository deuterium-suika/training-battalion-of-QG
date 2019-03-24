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
		printf("\t1--初始化\n");
		printf("\t2--删表\n");
		printf("\t3--遍历\n");
		printf("\t4--查\n");
		printf("\t5--转置\n");
		printf("\t6--是否成环\n");
		printf("\t7--转置偶数\n");
		printf("\t0--退出\n");
		printf("****************\n");
		printf("请选择你要进行的操作：");
		scanf("%d",&a);
		getchar();
		switch(a){
			case 1:InitList(L);
				int n=0,i,l;
				printf("创建链表长度为：");
				scanf("%d",&l);
				for (i=0;i<l;i++){
					LNode *p = NULL ;
					p=(LNode*)malloc(sizeof(LNode));
					printf("请输入第%d个结点数据：\n",i+1);
					scanf("%d",&p->data);
					p->next = L->next;L->next = p;
				}
				break;
			case 2:DestroyList(L); break; 	   
			case 3:TraverseList(L, visit); 
			case 4:printf("你想查找的值为：");
				   int e = 0;
				   scanf("%d",&e);
				   SearchList(L,e);
				   break;
			case 5:ReverseList(L);break;
			case 6:if(IsLoopList(L)){
				printf("成环");
				}else printf("不成环"); 
				break;
			case 7:L = ReverseEvenList(L);break;
		}
	}while(a!=0);
	return 0;
}
