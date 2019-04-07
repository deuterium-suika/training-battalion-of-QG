#include "LQueue.h"
void InitLQueue(LQueue *Q)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if(!p) return FALSE;
	p->data == NULL;
	Q->front = p;
	Q->rear = p;
	return TRUE;
}

void DestoryLQueue(LQueue *Q)
{
	while(Q->front)
	{
		Q->rear =Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}

Status IsEmptyLQueue(const LQueue *Q)
{
	return (Q->front == Q->rear? TRUE: FALSE);
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front == Q->rear) return FALSE;
	memcpy(e, Q->front->data,sizeof(Q->front->data));
	return TRUE;
}

int LengthLQueue(LQueue *Q)
{
	int i = 0;
	Node* p = Q->front;
	while(p != Q->rear)
	{
		i++;
		p = p->next;
	}
	return i;	
}

Status EnLQueue(LQueue *Q, void *data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if(p == NULL) return FALSE;
	p->data = (void*)malloc(sizeof(size_t));
	memcpy(p->data, data,sizeof(size_t));
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

Status DeLQueue(LQueue *Q)
{
	if(Q->front == Q->rear) return FALSE;
	Node* p;
	p = Q->front->next;
	Q->front->next = p->next;
	if(p == Q->rear) Q->front = Q->rear;
	free(p);
	return TRUE;	
}

ClearLQueue(LQueue *Q)
{
	DestoryLQueue(Q);
	InitLQueue(Q);
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(Q->front == Q->rear) return FALSE;
	Node* p = Q->front->next;
	while(p)
	{
		foo(p->data);
		p = p->next;
	}
}

void LPrint(void *q)
{
	if(sizeof(q) == sizeof(double)) 
	printf("%ld",*(double*)q); 
	if(sizeof(q) == sizeof(int))
	printf("%d",*(int*)q);
	if(sizeof(q) == sizeof(char))
	printf("%c",*(char*)q);	
}
