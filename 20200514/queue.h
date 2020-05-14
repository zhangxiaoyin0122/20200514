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
//���г�ʼ��
void QueueInit(Queue* q);
//�����½��
QNode* CreatNode(QDataType data);
//�������
void QueuePush(Queue* q, QDataType data);
//���г���
void QueuePop(Queue* q);
//����Ԫ�ظ���
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
void QueueDesity(Queue* q);


