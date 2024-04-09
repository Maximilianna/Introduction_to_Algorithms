#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define DATATYPE int

//节点结构体
typedef struct node
{
	DATATYPE data;
	struct node* prev;
	struct node* next;
}node;

//栈结构体
typedef struct stack
{
	//指向头节点
	node* head;
	//指向尾节点
	node* end;
}stack;

//初始化栈
void initStack(stack* s)
{
	s->head = NULL;
	s->end = NULL;
}

//判断栈是否为空
int Empty(stack* s)
{
	return s->head == NULL ? 1 : 0;
}

//压入元素
void push(stack* s, DATATYPE x)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (s->head == NULL)
	{
		s->head = newNode;
		s->end = newNode;
		return;
	}
	s->end->next = newNode;
	newNode->prev = s->end;
	s->end = newNode;
}

//弹出元素
int pop(stack* s, DATATYPE* x)
{
	if (s->head == NULL)
		return 0;
	*x = s->end->data;
	node* tmp = s->end;
	s->end = s->end->prev;
	free(tmp);
	if (s->end == NULL)
		s->head = NULL;
	return 1;
}

//获取栈顶元素
int gettop(stack s, DATATYPE* x)
{
	if (s.head == NULL)
		return 0;
	*x = s.end->data;
	return 1;
}

//清空栈
void clearStack(stack* s)
{
	while (s->end != NULL)
	{
		node* tmp = s->end;
		s->end = s->end->prev;
		free(tmp);
	}
	s->head = NULL;
}

//求栈中元素个数
int sizeStack(stack s)
{
	int count = 0;
	node* tmp = s.end;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->prev;
	}
	return count;
}

//遍历栈
void printStack(stack s)
{
	node* tmp = s.head;
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main()
{
	stack s;
	int e;
	DATATYPE x;
	initStack(&s);
	while (1)
	{
		printf("1.压入数据\n");
		printf("2.弹出数据\n");
		printf("3.获取栈顶元素\n");
		printf("4.清空栈\n");
		printf("5.打印栈中数据\n");
		printf("6.求栈中元素个数\n");
		printf("7.结束程序\n");
		printf("请选择功能:");
		scanf("%d", &e);
		switch (e)
		{
		case 1:
			printf("请输入数据：");
			scanf("%d", &x);
			push(&s, x);
			system("cls");
			break;
		case 2:
			if (pop(&s, &x))
				printf("弹出成功，弹出数据为：%d\n", x);
			else
				printf("弹出失败\n");
			system("pause");
			system("cls");
			break;
		case 3:
			if (gettop(s, &x))
				printf("获取成功，栈顶数据为：%d\n", x);
			else
				printf("获取失败\n");
			system("pause");
			system("cls");
			break;
		case 4:
			clearStack(&s);
			system("cls");
			break;
		case 5:
			printStack(s);
			system("pause");
			system("cls");
			break;
		case 6:
			e = sizeStack(s);
			printf("栈中元素数量为：%d\n", e);
			system("pause");
			system("cls");
			break;
		case 7:
			exit(0);
			break;
		default:
			system("cls");
			break;
		}
	}
	
	return 0;
}
