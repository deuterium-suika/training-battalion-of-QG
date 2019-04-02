#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
#include "Transform.h"
#include "calculate.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	printf("输入中缀表达式，负数使用（0-正数）表示，注意不要使用中文输入法括号\n");
	printf("%d\n",calculate());
	return 0;
}
