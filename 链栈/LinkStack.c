#include "LinkStack.h" 
#include "stdio.h"
#include "stddef.h"

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!s->top)return ERROR;
	s->count = 0;
	s->top == NULL;
	return SUCCESS;
}
Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	return (s->top == NULL);
}
Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
	if(s)
	*e = s->top->data;
	return SUCCESS;
}
Status clearLStack(LinkStack *s)   //清空栈
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
Status destroyLStack(LinkStack *s)   //销毁栈
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
Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	*length = s->count;
	return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
	LinkStackPtr add = (LinkStackPtr)malloc(sizeof(StackNode)); 
	add->data = data;
	add->next = s->top;
	s->top = add;
	s->count++;
	return SUCCESS;
} 
Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
	LinkStackPtr p;
	if(!s->count) return ERROR;//空栈
	*data = s->top->data;
	p = s->top;
	s->top = p->next;
	free(p);
	s->count--;
	return SUCCESS; 
} 
