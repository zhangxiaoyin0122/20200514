#include "sort.h"
#include "stack.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void Swap(int* array, int l, int r) {
	int tmp = array[l];
	array[l] = array[r];
	array[r] = tmp;
}
int GetMid(int* array, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	if (array[begin] < array[mid]) {
		if (array[mid] < array[end])
			return mid;
		else {
			if (array[begin] > array[end])
				return begin;
			else
				return end;
		}
	}
	else {
		if (array[mid] > array[end])
			return mid;
		else {
			if (array[begin] > array[end])
				return end;
			else
				return begin;
		}
	}
}

int partion(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	Swap(array, begin, mid);
	int prev = begin;
	int cur = prev + 1;
	int key = array[begin];
	while (cur <= end) {
		if (array[cur] < key && ++prev != cur) {
			Swap(array, prev, cur);
		}
		cur++;
	}
	Swap(array, begin, prev);
	return prev;
}
//借助栈实现
void quickSort1(int* array, int n) {
	Stack sk;
	StackInit(&sk, 10);
	if (n > 1) {
		StackPush(&sk, n - 1);
		StackPush(&sk, 0);
	}
	while (StackEmpty(&sk) != 1) {
		int begin = StackTop(&sk);
		StackPop(&sk);
		int end = StackTop(&sk);
		StackPop(&sk);
		int keypos = partion(array, begin, end);
		if (keypos + 1 < end) {
			StackPush(&sk, end);
			StackPush(&sk, keypos + 1);
		}
		if (keypos - 1 > begin) {
			StackPush(&sk, keypos-1);
			StackPush(&sk, begin);
		}
	}
}
//借助队列实现
void quickSort2(int* array, int n) {
	Queue q;
	QueueInit(&q);
	if (n > 1) {
		QueuePush(&q, 0);
		QueuePush(&q, n - 1);
	}
	while (QueueEmpty(&q) != 1) {
		int begin = QueueFront(&q);
		QueuePop(&q);
		int end = QueueFront(&q);
		QueuePop(&q);
		int keypos = partion(array, begin, end);
		if (keypos - 1 > begin) {
			QueuePushBack(&q, begin);
			QueuePushBack(&q, keypos - 1);
		}
		if (keypos + 1 < end) {
			QueuePushBack(&q, keypos + 1);
			QueuePushBack(&q, end);
	}
}

