#include <stdio.h>

typedef struct stack
{
    int data[20];
    int top;
}stack;

//初始化栈
void initStack(stack *s)
{
    s->top = -1;
}

//压入函数
void push(stack *s,int n)
{
    s->data[++(s->top)] = n;
}

//弹出函数
int pop(stack *s)
{
    if(s->top == -1)
        return EOF;
    else
        return s->data[s->top--];
}

int main() {
    stack s;
    int n;
    initStack(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    for(int i = 0;i<=s.top;i++)
        printf("%d ",s.data[i]);
    while(1)
    {
        n = pop(&s);
        if(n != EOF)
        {
            printf("%d ",n);
        }
        else
        {
            printf("弹出失败");
            break;
        }
    }
    return 0;
}
