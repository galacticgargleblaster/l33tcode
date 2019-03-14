#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return (obj->front == NULL);
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->front == obj->rear);
}

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
	if (k < 0)
		return (NULL);

    MyCircularQueue *queue;

	queue = malloc(sizeof(MyCircularQueue));
	queue->front = NULL;
	queue->rear = NULL;

	if (k)
	{
		queue->front = malloc(sizeof(element_t));
		queue->rear = queue->front;

		while (k > 1)
		{
			queue->front->next = malloc(sizeof(element_t));
			queue->front->next->prev = queue->front;
			queue->front = queue->front->next;
			k--;
		}
		queue->front->next = queue->rear;
		queue->rear->prev = queue->front;
		queue->front = NULL;
	}
	return (queue);
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return (false);
	else
	{
		if (myCircularQueueIsEmpty(obj))
			obj->front = obj->rear;
		obj->front->value = value;
		obj->front = obj->front->next;
		return (true);
	}
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return (false);
	else
	{
		obj->rear = obj->rear->next;
		if (obj->rear == obj->front)
			obj->front = NULL;
		return (true);
	}
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return (-1);
	else
		return (obj->front->prev->value);
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return(-1);
	else
		return (obj->rear->value);
}

void myCircularQueueFree(MyCircularQueue* obj) {
	element_t *tmp;

	while (!(myCircularQueueIsEmpty(obj)))
	{
		if (obj->front)
		{
			tmp = obj->front->next;
			free(obj->front);
			obj->front = tmp;
		}
	}   
	free (obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * struct MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 * bool param_2 = myCircularQueueDeQueue(obj);
 * int param_3 = myCircularQueueFront(obj);
 * int param_4 = myCircularQueueRear(obj);
 * bool param_5 = myCircularQueueIsEmpty(obj);
 * bool param_6 = myCircularQueueIsFull(obj);
 * myCircularQueueFree(obj);
 */
