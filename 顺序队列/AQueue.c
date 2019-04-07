#include "AQueue.h"
void InitAQueue(AQueue *Q)
{
	int i;
	for(i == 0; i < MAXQUEUE; i++)
	{
		Q->data[i] = (void*)malloc(sizeof(size_t));
	}
	Q->front = Q->rear = 0;
}

void DestoryAQueue(AQueue *Q)
{
	int i;
	for(i = 0; i < MAXQUEUE; i++)
	{
		free(Q->data[i]);
	}
}

Status IsFullAQueue(const AQueue *Q)
{
	return(Q->length == MAXQUEUE?TRUE:FALSE);
}

Status IsEmptyAQueue(const AQueue *Q)
{
	return(Q->front == Q->rear?TRUE:FALSE);
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(Q->front == Q->rear == 0) return FALSE;
	memcpy(e,Q->data[Q->front],sizeof(Q->data[Q->front]));
	return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	return(Q->length);
}

Status EnAQueue(AQueue *Q, void *data)
{
	if(Q->length == MAXQUEUE) return FALSE;
	memcpy(Q->data[Q->rear],data,sizeof(size_t));
	Q->rear++;
	return TRUE;
}

Status DeAQueue(AQueue *Q)
{
	if(Q->front == Q->rear) return FALSE;
	Q->front++;
	return TRUE;
}

void ClearAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	int i;
	if(Q->front == Q->rear) return FALSE;
	for(i = Q->front; i <= Q->rear; i++)
		foo(Q->data[i]);
	return TRUE;
}

void APrint(void *q)
{
	if(sizeof(q) == sizeof(double)) 
	printf("%ld",*(double*)q); //向那些未在原型中申明参数类型的函数传递参数时，float型会自动转为double型
	if(sizeof(q) == sizeof(int))
	printf("%d",*(int*)q);
	if(sizeof(q) == sizeof(char))
	printf("%c",*(char*)q);	
}
