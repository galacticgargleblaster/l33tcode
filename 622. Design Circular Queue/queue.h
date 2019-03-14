#ifndef QUEUE_H
# define QUEUE_H

typedef struct element_s {
	struct element_s	*next;
	struct element_s	*prev;
	int					value;
} element_t;

typedef struct {
	element_t		*front;
	element_t		*rear;
} MyCircularQueue;

#endif

