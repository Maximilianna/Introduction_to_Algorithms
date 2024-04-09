#include <stdio.h>

#define DATATYPE int
#define MAXSIZE 20

typedef struct stack
{
    DATATYPE data[MAXSIZE];
    int top;
}stack;

//初始化栈
void initStack(stack *s)
{
    s->top = -1;
}

//压入函数
int push(stack *s,DATATYPE n)
{
	if(s->top == MAXSIZE - 1)
		return 0;
    s->data[++(s->top)] = n;
	return 1;
}

//弹出函数
int pop(stack *s,DATATYPE *x)
{
    if (s->top == -1)
        return 0;
	*x = s->data[(s->top)--];
    return 1;
}

//获取栈顶元素
int gettop(stack s,DATATYPE* x)
{
	if(s.top == -1)
		return 0;
	*x = s.data[s.top];
	return 1;
}

//栈置空
void clearStack(stack*s)
{
	s->top = -1;
}

//求栈中元素个数
int sizeStack(stack s)
{
	return s.top + 1;
}

int main() {
    stack s;
    initStack(&s);
    return 0;
}
