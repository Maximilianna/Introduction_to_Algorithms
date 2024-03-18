#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�������ڵ�ṹ��
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* up;
}Node;

//�����½ڵ�
Node* newNode(int e)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->left = newNode->right = newNode->up = NULL;
	return newNode;
}

//���������в���ڵ�
Node* insertBinaryTree(Node* root, int e)
{
	if (root == NULL)
	{
		root = newNode(e);
		return root;
	}
	if (root->data > e)
	{
		root->left = insertBinaryTree(root->left, e);
		root->left->up = root;
	}
	else
	{
		root->right = insertBinaryTree(root->right, e);
		root->right->up = root;
	}
	return root;
}

//����������
Node* createBinaryTree(int* arr, int n)
{
	//�������ڵ�
	Node* root = NULL;
	for (int i = 0; i < n; i++)
		root = insertBinaryTree(root, arr[i]);
	return root;
}

//�޸Ķ�����Ԫ��
void searchBinaryTree(Node* root, int x, int newData)
{
	if (root == NULL)
		return;
	if (root->data == x)
		root->data = newData;
	searchBinaryTree(root->left, x, newData);
	searchBinaryTree(root->right, x, newData);
}

//�������
void preOrderBinary(Node* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preOrderBinary(root->left);
	preOrderBinary(root->right);
}

//�������
void inOrderBinary(Node* root)
{
	if (root == NULL)
		return;
	inOrderBinary(root->left);
	printf("%d ", root->data);
	inOrderBinary(root->right);
}

//�������
void postOrderBinary(Node* root)
{
	if (root == NULL)
		return;
	postOrderBinary(root->left);
	postOrderBinary(root->right);
	printf("%d ", root->data);
}

int main()
{
	int a;
	Node* Tree = NULL;
	printf("������Ҫ��ӵ�������������(-1����):");
	scanf("%d", &a);
	while (a != -1)
	{
		Tree = insertBinaryTree(Tree, a);
		printf("������Ҫ��ӵ�������������(-1����):");
		scanf("%d", &a);
	}
	
	//ǰ�����
	preOrderBinary(Tree);
	//�������
	inOrderBinary(Tree);
	//�������
	postOrderBinary(Tree);
	return 0;
}