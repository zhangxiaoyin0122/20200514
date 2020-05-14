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
//尾插
void StackPush(Stack* sk, Type data);
//尾删
void StackPop(Stack* sk);
//获取栈顶元素
Type StackTop(Stack* sk);
//获取栈顶元素个数
size_t StackSize(Stack* sk);
//判断栈是否为空
int StackEmpty(Stack* sk);
//栈的销毁
void StackDestory(Stack* sk);


