#include "queue.c"
#include "print_queue.c"
#include <assert.h>

#define QSIZE 3

int main()
{
	MyCircularQueue  *q = myCircularQueueCreate(QSIZE);
	print_queue(q);

	assert(myCircularQueueIsEmpty(q));

	#define FREINET 10
	#define MONTESSORI 11
	#define VYGOTSKY 12
	#define GAETAN 13

	assert(true == myCircularQueueEnQueue(q, FREINET));
	assert(!myCircularQueueIsEmpty(q));
	assert(!myCircularQueueIsFull(q));
	assert(myCircularQueueFront(q) == FREINET);
	assert(myCircularQueueRear(q) == FREINET);
	print_queue(q);
	
	assert(true == myCircularQueueEnQueue(q, MONTESSORI));
	assert(!myCircularQueueIsEmpty(q));
		print_queue(q);

	assert(!myCircularQueueIsFull(q));
	assert(myCircularQueueFront(q) == MONTESSORI);
	assert(myCircularQueueRear(q) == FREINET);

	assert(true == myCircularQueueEnQueue(q, VYGOTSKY));
	assert(!myCircularQueueIsEmpty(q));
	assert(myCircularQueueIsFull(q));
	assert(myCircularQueueFront(q) == VYGOTSKY);
	assert(myCircularQueueRear(q) == FREINET);

	assert(false == myCircularQueueEnQueue(q, GAETAN));  // Should be full
	assert(!myCircularQueueIsEmpty(q));
	assert(myCircularQueueIsFull(q));
	assert(myCircularQueueFront(q) == VYGOTSKY);
	assert(myCircularQueueRear(q) == FREINET);
	
	assert(true == myCircularQueueDeQueue(q));
	assert(!myCircularQueueIsEmpty(q));
	assert(!myCircularQueueIsFull(q));
	assert(myCircularQueueFront(q) == VYGOTSKY);
	assert(myCircularQueueRear(q) == MONTESSORI);
	assert(true == myCircularQueueDeQueue(q));
	assert(!myCircularQueueIsEmpty(q));
	assert(!myCircularQueueIsFull(q));
	assert(myCircularQueueFront(q) == VYGOTSKY);
	assert(myCircularQueueRear(q) == VYGOTSKY);
	assert(true == myCircularQueueDeQueue(q));
	assert(myCircularQueueIsEmpty(q));
	assert(!myCircularQueueIsFull(q));
	assert(false == myCircularQueueDeQueue(q));

	myCircularQueueFree(q);
}