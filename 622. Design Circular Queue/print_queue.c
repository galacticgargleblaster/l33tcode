#include <stdio.h>
#include "queue.h"

#define LSADDR(p) ((unsigned int)((unsigned long)p &0xffff))

void print_queue(MyCircularQueue *queue)
{
	element_t	*tmp;
	char		beyond_front = 0;

	printf("front: %x\n", LSADDR(queue->front));
	printf("rear: %x\n", LSADDR(queue->rear));
	tmp = queue->rear;
	do
	{
		if (tmp == queue->front)
			beyond_front = 1;
		if (beyond_front)
			printf("addr: %x\tprev: %x\tnext: %x\tvalue: %d\n", LSADDR(tmp), LSADDR(tmp->prev), LSADDR(tmp->next), tmp->value);
		else
			printf("addr: %x\tprev: %x\tnext: %x\tvalue: EMPTY\n", LSADDR(tmp), LSADDR(tmp->prev), LSADDR(tmp->next));

		tmp = tmp->next;
	} while (tmp != queue->rear);
}