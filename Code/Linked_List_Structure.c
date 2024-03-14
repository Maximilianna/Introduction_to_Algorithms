#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

//����ṹ��
typedef struct Node {
    int data;           //������
    struct Node *prev;  //ָ��ǰһ��Ԫ�ص�ָ��
    struct Node *next;  //ָ���һ��Ԫ�ص�ָ��
} Node;

//��ʼ��˫����������head�ڵ�
Node *initLink() {
    //����head�ڵ�
    Node *LinkList = (Node *) malloc(sizeof(Node));
    //��ʼ��
    LinkList->prev = NULL;
    LinkList->next = NULL;
    //����head�ڵ�
    return LinkList;
}

//����ָ�������½ڵ�
void creatNode(Node *LinkList, int len, int *arr) {
    //�����½ڵ�
    Node *newNode;
    for (int i = 0; i < len; i++) {
        //Ϊ�½ڵ����ռ�
        newNode = (Node *) malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        //���head�ڵ�ָ��NULL
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

//��ȡ��ǰ������
int getLength(Node *LinkList) {
    int length = 0;
    Node *tmp = LinkList;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        length++;
    }
    return length;
}

//����ڵ㵽ָ��λ��   1������ɹ�     0������ʧ��
int insertLinkList(Node *LinkList, int pos, int e) {
    //������ʱָ��
    Node *tmp = LinkList;
    //���ָ��λ�ô��ڵ�ǰ�ڵ�������С��1������ʧ��
    if (pos < 1 || pos > getLength(LinkList))
        return 0;
    //�ƶ�ָ�뵽ָ��λ��ǰһ���ڵ�
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
    }
    //�����½ڵ�
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = e;
    //�½ڵ��next�����ӵ�ָ��λ�õĽڵ�
    newNode->next = tmp->next;
    //ָ��λ�õĽڵ��prev���ӵ��½ڵ�
    tmp->next->prev = newNode;
    //�½ڵ��prev���ӵ���ʱ�ڵ�
    newNode->prev = tmp;
    //��ʱ�ڵ��next���ӵ��½ڵ�
    tmp->next = newNode;
    return 1;
}

//ɾ��ָ��λ�ýڵ�    1��ɾ���ɹ�     0��ɾ��ʧ��
int deleteLinkList(Node *LinkList, int pos) {
    //������ʱָ��
    Node *tmp1 = LinkList, *tmp2;
    //���ָ��λ�ô��ڵ�ǰ�ڵ�������С��1������ʧ��
    if (pos < 1 || pos > getLength(LinkList))
        return 0;
    //�ƶ�ָ�뵽ָ��λ��ǰһ���ڵ�
    for (int i = 1; i < pos; i++) {
        tmp1 = tmp1->next;
    }
    //ɾ��ָ���ڵ�
    tmp2 = tmp1->next;
    tmp1->next = tmp2->next;
    //ֻ�в���β�ڵ������£���tmp2->next��prev���ӵ�tmp1
    if (tmp2->next != NULL)
        tmp2->next->prev = tmp1;
    free(tmp2);
    return 1;
}

//����ָ����Ԫ�أ�������λ�ã��Ҳ���������
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
