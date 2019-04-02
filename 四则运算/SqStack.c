#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"


//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
	s->base = (ElemType*)malloc(sizes*sizeof(ElemType));
	if(!s->base) return ERROR;
	s->top = s->base;
	s->size = STACK_INIT_SIZE;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	return s->top == s->base;
}
Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if(s->top == s->base||s->base == NULL)return ERROR;
	*e = *(s->top-1);
	return SUCCESS;
}
Status clearStack(SqStack *s)   //���ջ
{
	s->top = s->base;
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //����ջ
{
	int i,len;
	len = s->size;
	for(i=0;i<len;i++)
	{
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->size = 0;
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //���ջ����
{
	*length = s->top - s->base;
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	if (s->top - s->base >= s->size)
	{
		//���ջ�� 
		s->base = (ElemType*)realloc(s->base,(s->size + STACKINCREMENT) * sizeof(ElemType));
		if(s->base == NULL)return ERROR;
		s->top = s->base + s->size;//realloc֮��ָ��仯
		s->size += STACKINCREMENT; 
	} 
	*(s->top) = data;
	s->top++;
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	if(s->top == s->base)return ERROR;//ջ��
	*data = *--(s->top);
	return SUCCESS;  
}

