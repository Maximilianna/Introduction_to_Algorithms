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

//��ʼ����ϣ��
void init_HashTable(HashTable* H, int size)
{
	H->arr = (Node*)malloc(sizeof(Node) * size);
	if (H->arr == NULL)
	{
		printf("��ϣ���������ռ�ʧ��!\n");
		exit(0);
	}
	for (int i = 0; i < size; i++)
		H->arr[i].next = NULL;
	H->size = size;
}

//��ϣ����
int hash(HashTable* H, int key)
{
	return (int)pow(key, 2) * Rand % H->size;
}

//�����ϣ��
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

//ɾ����ϣ��
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

//��ӡ��ϣ��
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
		printf("��������(1):\n");
		printf("ɾ������(2):\n");
		printf("��ӡ����(3):\n");
		printf("�˳�(4):\n");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("������Ҫ����ɢ�б�����ݣ�");
			scanf("%d", &e);
			insert_HashTable(&H, e);
			system("pause");
			system("cls");
			break;
		case 2:
			printf("������Ҫɾ�������ݣ�");
			scanf("%d", &e);
			delete_HashTable(&H, e);
			system("pause");
			system("cls");
			break;
		case 3:
			printf("ɢ�б��������£�\n");
			print_HashTable(&H);
			system("pause");
			system("cls");
			break;
		case 4:
			printf("���˳�");
			system("pause");
			exit(0);
			break;
		default:
			printf("�����������������");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}