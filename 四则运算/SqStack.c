#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"


//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
	s->base = (ElemType*)malloc(sizes*sizeof(ElemType));
	if(!s->base) return ERROR;
	s->top = s->base;
	s->size = STACK_INIT_SIZE;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	return s->top == s->base;
}
Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if(s->top == s->base||s->base == NULL)return ERROR;
	*e = *(s->top-1);
	return SUCCESS;
}
Status clearStack(SqStack *s)   //清空栈
{
	s->top = s->base;
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //销毁栈
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
Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	*length = s->top - s->base;
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if (s->top - s->base >= s->size)
	{
		//如果栈满 
		s->base = (ElemType*)realloc(s->base,(s->size + STACKINCREMENT) * sizeof(ElemType));
		if(s->base == NULL)return ERROR;
		s->top = s->base + s->size;//realloc之后指针变化
		s->size += STACKINCREMENT; 
	} 
	*(s->top) = data;
	s->top++;
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //出栈
{
	if(s->top == s->base)return ERROR;//栈空
	*data = *--(s->top);
	return SUCCESS;  
}

