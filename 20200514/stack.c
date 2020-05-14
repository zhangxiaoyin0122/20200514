#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct Stack {
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;

void StackInit(Stack* sk, size_t n) {
	sk->_array = (Type*)malloc(sizeof(Type)*n);
	sk->_capacity = n;
	sk->_size = 0;
}
//Î²²å
void StackPush(Stack* sk, Type data) {
	if (sk->_size == sk->_capacity) { //¿¼ÂÇÀ©ÈÝ
		sk->_capacity *= 2;
		sk->_array = (Type*)realloc(sk->_array, sk->_capacity * sizeof(Type));
	}
	sk->_array[sk->_size++] = data;
}
//Î²É¾
void StackPop(Stack* sk) {
	if (sk->_size)
		sk->_size--;
}
//»ñÈ¡Õ»¶¥ÔªËØ
Type StackTop(Stack* sk) {
	return sk->_array[sk->_size - 1];
}
//»ñÈ¡Õ»¶¥ÔªËØ¸öÊý
size_t StackSize(Stack* sk) {
	return sk->_size;
}
//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
int StackEmpty(Stack* sk) {
	if (sk->_size == 0) {
		return 0;
	}
	return 1;
}
//Õ»µÄÏú»Ù
void StackDestory(Stack* sk) {
	free(sk->_array);
	sk->_array = NULL;
	sk->_size = sk->_capacity = 0;
}