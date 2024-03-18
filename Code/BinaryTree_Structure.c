#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//二叉树节点结构体
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* up;
}Node;

//创建新节点
Node* newNode(int e)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->left = newNode->right = newNode->up = NULL;
	return newNode;
}

//往二叉树中插入节点
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

//创建二叉树
Node* createBinaryTree(int* arr, int n)
{
	//创建根节点
	Node* root = NULL;
	for (int i = 0; i < n; i++)
		root = insertBinaryTree(root, arr[i]);
	return root;
}

//修改二叉树元素
void searchBinaryTree(Node* root, int x, int newData)
{
	if (root == NULL)
		return;
	if (root->data == x)
		root->data = newData;
	searchBinaryTree(root->left, x, newData);
	searchBinaryTree(root->right, x, newData);
}

//先序遍历
void preOrderBinary(Node* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preOrderBinary(root->left);
	preOrderBinary(root->right);
}

//中序遍历
void inOrderBinary(Node* root)
{
	if (root == NULL)
		return;
	inOrderBinary(root->left);
	printf("%d ", root->data);
	inOrderBinary(root->right);
}

//后序遍历
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
	printf("请输入要添加到二叉树的数据(-1结束):");
	scanf("%d", &a);
	while (a != -1)
	{
		Tree = insertBinaryTree(Tree, a);
		printf("请输入要添加到二叉树的数据(-1结束):");
		scanf("%d", &a);
	}
	
	//前序遍历
	preOrderBinary(Tree);
	//中序遍历
	inOrderBinary(Tree);
	//后序遍历
	postOrderBinary(Tree);
	return 0;
}