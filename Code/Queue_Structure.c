#include <stdio.h>

#define MaxSize 10

typedef struct queue {
    int data[MaxSize];
    int head;
    int tail;
} queue;

//初始化队列
void initQueue(queue *q) {
    q->head = q->tail = 0;
}

//入队函数
int enqueue(queue *q, int n) {
    if ((q->tail + 1) % MaxSize == q->head)
        return 0;
    q->data[q->tail] = n;
    q->tail = (q->tail + 1) % MaxSize;
    return 1;
}

//出队函数
int dequeue(queue *q) {
    if (q->head == q->tail)
        return EOF;
    int x = q->head;
    q->head = (q->head + 1) % MaxSize;
    return q->data[x];
}

int main() {
    queue q;
    initQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    dequeue(&q);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    enqueue(&q,70);
    dequeue(&q);
    enqueue(&q,80);
    enqueue(&q,90);
    enqueue(&q,100);
    enqueue(&q,110);
    int i = q.head;
    while(i!=q.tail)
    {
        if(i % MaxSize == 0)
            i = 0;
        printf("%d ",q.data[i++]);
    }
    return 0;
}
