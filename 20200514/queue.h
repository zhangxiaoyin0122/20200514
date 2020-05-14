#pragma once

typedef int QDataType;

typedef struct QNode {
	struct QNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue {
	QNode* _front;
	QNode* _rear;
	int _size;
}Queue;
//队列初始化
void QueueInit(Queue* q);
//创建新结点
QNode* CreatNode(QDataType data);
//队列入队
void QueuePush(Queue* q, QDataType data);
//队列出队
void QueuePop(Queue* q);
//队列元素个数
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
void QueueDesity(Queue* q);


