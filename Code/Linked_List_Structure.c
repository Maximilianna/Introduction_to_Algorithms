#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

//链表结构体
typedef struct Node {
    int data;           //数据域
    struct Node *prev;  //指向前一个元素的指针
    struct Node *next;  //指向后一个元素的指针
} Node;

//初始化双向链表，创建head节点
Node *initLink() {
    //创建head节点
    Node *LinkList = (Node *) malloc(sizeof(Node));
    //初始化
    LinkList->prev = NULL;
    LinkList->next = NULL;
    //返回head节点
    return LinkList;
}

//创建指定个数新节点
void creatNode(Node *LinkList, int len, int *arr) {
    //创建新节点
    Node *newNode;
    for (int i = 0; i < len; i++) {
        //为新节点分配空间
        newNode = (Node *) malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        //如果head节点指向NULL
        if (LinkList->next == NULL) {
            LinkList->next = newNode;
            newNode->prev = LinkList;
        } else {
            Node *tmp = LinkList->next;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = newNode;
            newNode->prev = tmp;
        }
    }
}

//获取当前链表长度
int getLength(Node *LinkList) {
    int length = 0;
    Node *tmp = LinkList;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        length++;
    }
    return length;
}

//插入节点到指定位置   1：插入成功     0：插入失败
int insertLinkList(Node *LinkList, int pos, int e) {
    //定义临时指针
    Node *tmp = LinkList;
    //如果指定位置大于当前节点数量或小于1，插入失败
    if (pos < 1 || pos > getLength(LinkList))
        return 0;
    //移动指针到指定位置前一个节点
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
    }
    //创建新节点
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = e;
    //新节点的next先连接到指定位置的节点
    newNode->next = tmp->next;
    //指定位置的节点的prev连接到新节点
    tmp->next->prev = newNode;
    //新节点的prev连接到临时节点
    newNode->prev = tmp;
    //临时节点的next连接到新节点
    tmp->next = newNode;
    return 1;
}

//删除指定位置节点    1：删除成功     0：删除失败
int deleteLinkList(Node *LinkList, int pos) {
    //定义临时指针
    Node *tmp1 = LinkList, *tmp2;
    //如果指定位置大于当前节点数量或小于1，插入失败
    if (pos < 1 || pos > getLength(LinkList))
        return 0;
    //移动指针到指定位置前一个节点
    for (int i = 1; i < pos; i++) {
        tmp1 = tmp1->next;
    }
    //删除指定节点
    tmp2 = tmp1->next;
    tmp1->next = tmp2->next;
    //只有不是尾节点的情况下，让tmp2->next的prev连接到tmp1
    if (tmp2->next != NULL)
        tmp2->next->prev = tmp1;
    free(tmp2);
    return 1;
}

//查找指定的元素，并返回位置，找不到返回零
int seachLinkList(Node *LinkList, int e) {
    int index = 0;
    Node *tmp = LinkList;
    while (index <= getLength(LinkList) && tmp->data != e) {
        index++;
        tmp = tmp->next;
    }
    if (index > getLength(LinkList))
        index = 0;
    return index;
}

int main() {
    Node *LinkList = initLink();
    int arr[MaxSize], length, index;
    for (int i = 0; i < MaxSize; i++)
        scanf("%d", &arr[i]);
    creatNode(LinkList, sizeof(arr) / sizeof(int), arr);
    length = getLength(LinkList);
    printf("%d ", length);
    insertLinkList(LinkList, 10, 11);
    length = getLength(LinkList);
    printf("%d ", length);
    deleteLinkList(LinkList, 1);
    deleteLinkList(LinkList, 10);
    length = getLength(LinkList);
    printf("%d ", length);
    index = seachLinkList(LinkList, 40);
    printf("%d ", index);
    index = seachLinkList(LinkList, 100);
    printf("%d ", index);
    free(LinkList);
    return 0;
}
