#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct Stack {
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;

void StackInit(Stack* sk, size_t n);
//β��
void StackPush(Stack* sk, Type data);
//βɾ
void StackPop(Stack* sk);
//��ȡջ��Ԫ��
Type StackTop(Stack* sk);
//��ȡջ��Ԫ�ظ���
size_t StackSize(Stack* sk);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* sk);
//ջ������
void StackDestory(Stack* sk);


