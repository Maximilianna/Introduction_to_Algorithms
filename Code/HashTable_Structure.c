#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_HASHTABLE 40

unsigned int Rand;

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct HashTable
{
	Node* arr;
	unsigned int size;
}HashTable;

//初始化哈希表
void init_HashTable(HashTable* H, int size)
{
	H->arr = (Node*)malloc(sizeof(Node) * size);
	if (H->arr == NULL)
	{
		printf("哈希表数组分配空间失败!\n");
		exit(0);
	}
	for (int i = 0; i < size; i++)
		H->arr[i].next = NULL;
	H->size = size;
}

//哈希函数
int hash(HashTable* H, int key)
{
	return (int)pow(key, 2) * Rand % H->size;
}

//插入哈希表
void insert_HashTable(HashTable* H, int key)
{
	int Hash = hash(H, key);
	if (H->arr[Hash].next == NULL)
	{
		H->arr[Hash].data = key;
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = H->arr[Hash].next;
		H->arr[Hash].next = newNode;
		return;
	}
	Node* tmp = &H->arr[Hash];
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->data = key;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = tmp->next;
	tmp->next = newNode;
}

//删除哈希表
void delete_HashTable(HashTable* H, int key)
{
	int Hash = hash(H, key);
	if (H->arr[Hash].data == key)
	{
		free(H->arr[Hash].next);
		H->arr[Hash].next = NULL;
		return;
	}
	Node* tmp = &H->arr[Hash];
	while (tmp->data != key)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

//打印哈希表
void print_HashTable(HashTable* H)
{
	for (int i = 0; i < H->size; i++)
	{
		if (H->arr[i].next == NULL)
		{
			printf("#\n");
			continue;
		}
		Node* tmp = &H->arr[i];
		while (tmp->next != NULL)
		{
			printf("%d -> ", tmp->data);
			tmp = tmp->next;
		}
		printf("null\n");
	}
}

int main()
{
	srand((unsigned)time(NULL));
	Rand = rand() % 10;
	HashTable H;
	int e, x;
	init_HashTable(&H,MAX_HASHTABLE);
	while (1)
	{
		printf("插入数据(1):\n");
		printf("删除数据(2):\n");
		printf("打印数据(3):\n");
		printf("退出(4):\n");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("请输入要插入散列表的数据：");
			scanf("%d", &e);
			insert_HashTable(&H, e);
			system("pause");
			system("cls");
			break;
		case 2:
			printf("请输入要删除的数据：");
			scanf("%d", &e);
			delete_HashTable(&H, e);
			system("pause");
			system("cls");
			break;
		case 3:
			printf("散列表数据如下：\n");
			print_HashTable(&H);
			system("pause");
			system("cls");
			break;
		case 4:
			printf("已退出");
			system("pause");
			exit(0);
			break;
		default:
			printf("输入错误，请重新输入");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}