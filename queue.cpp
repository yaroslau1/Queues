#include <iostream>
#include <stdint.h>
#include "queue.h"

void queueInit(struct Queue* queue) {
	queue->first = 0;
	queue->last = 0;
}

void queueInsert(struct Queue* queue, uint32_t value) {
	if (queue->first < QUEUE_MAX_SIZE) {		
		queue->queue[queue->last] = value;
		queue->last++;
	}
	else {
		printf("Queue is full.\n");
	}
} 

uint8_t queueIsEmpty(struct Queue* queue) {
	uint8_t isEmpty = 0;
	if (queue->last == 0 && queue->first == 0) {
		isEmpty = 1;
	}
	return isEmpty;
}

void queuePrint(struct Queue* queue) {
	uint8_t queueCounter;
	if (queueIsEmpty(queue)) {
		printf("empty.\n");
	}
	else {
		for (queueCounter = queue->first; queueCounter < queue->last; queueCounter++) {
			printf("%d ", queue->queue[queueCounter]);
		}
		printf("\n");
	}
}

uint8_t queueSize(struct Queue* queue) {
	return queue->last - queue->first;
}

uint32_t queueRemove(struct Queue* queue) {
	uint32_t value;
	uint8_t queueCounter;
	value = queue->queue[queue->first];
	for (queueCounter = queue->first; queueCounter < queue->last; queueCounter++) {
		queue->queue[queueCounter] = queue->queue[queueCounter + 1];
	}
	queue->last--;
	return value;
}

void queueSearch(struct Queue* queue, uint8_t number) {
	uint8_t queueCounter;
	for (queueCounter = queue->first; queueCounter < queue->last; queueCounter++) {
		if ((queue->queue[queueCounter] >> number) & 1) {
			printf("%d ", queue->queue[queueCounter]);
		}
	}
	printf("\n");
}

void mQueueInit(struct MergedQueue* queue) {
	queue->first = 0;
	queue->last = 0;
}

void mQueueInsert(struct MergedQueue* queue, uint32_t value) {
	if (queue->first < MERGED_QUEUE_MAX_SIZE) {
		queue->queue[queue->last] = value;
		queue->last++;
	}
	else {
		printf("Merged queue is full.\n");
	}
}

uint8_t mQueueIsEmpty(struct MergedQueue* queue) {
	uint8_t isEmpty = 0;
	if (queue->last == queue->first) {
		isEmpty = 1;
	}
	return isEmpty;
}

void mQueuePrint(struct MergedQueue* queue) {
	uint8_t queueCounter;
	if (mQueueIsEmpty(queue)) {
		printf("empty.\n");
	}
	else {
		for (queueCounter = queue->first; queueCounter < queue->last; queueCounter++) {
			printf("%d ", queue->queue[queueCounter]);
		}
		printf("\n");
	}
}