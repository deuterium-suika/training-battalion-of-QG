#include "LinkStack.h" 
#include "stdio.h"
#include "stddef.h"

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!s->top)return ERROR;
	s->count = 0;
	s->top == NULL;
	return SUCCESS;
}
Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	return (s->top == NULL);
}
Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
	if(s)
	*e = s->top->data;
	return SUCCESS;
}
Status clearLStack(LinkStack *s)   //���ջ
{
	LinkStackPtr q,p;
	p = s->top->next;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);	
	}
} 
Status destroyLStack(LinkStack *s)   //����ջ
{
	LinkStackPtr q,p;
	p = s->top;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
	*length = s->count;
	return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	LinkStackPtr add = (LinkStackPtr)malloc(sizeof(StackNode)); 
	add->data = data;
	add->next = s->top;
	s->top = add;
	s->count++;
	return SUCCESS;
} 
Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
	LinkStackPtr p;
	if(!s->count) return ERROR;//��ջ
	*data = s->top->data;
	p = s->top;
	s->top = p->next;
	free(p);
	s->count--;
	return SUCCESS; 
} 
