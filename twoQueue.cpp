
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "queue.h"

//*** Variables ***//
int8_t cmd = -1;
struct Queue* firstQueue = (Queue*)malloc(sizeof(Queue));
struct Queue* secondQueue = (Queue*)malloc(sizeof(Queue));
struct MergedQueue* mergedQueue = (MergedQueue*)malloc(sizeof(MergedQueue));

//*** Functions ***//
void exit();
void firstQueueWork();
void secondQueueWork();
void queueWork(struct Queue* queue);
void mergeQueues();
void chessMergeQueues();
void fillRandomValues(struct Queue* queue);
void searchBitsEqualsOne(struct Queue* queue);

int main()
{
	queueInit(firstQueue);
	queueInit(secondQueue);
	mQueueInit(mergedQueue);
	printf("Hello, it's programm about two queues.\n");
	while (true) {
		printf("***********************\n");
		printf("Press 0 - to EXIT\n");
		printf("Press 1 - to work with first queue\n");
		printf("Press 2 - to work with second queue\n");
		printf("Press 3 - to merge queues\n");
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 0:
			exit();
			break;
		case 1:
			firstQueueWork();
			break;
		case 2:
			secondQueueWork();
			break;
		case 3:
			mergeQueues();
			break;
		default:
			printf("Unknown command try again.\n");
			break;
		}
	}
}

void exit() {
	free(firstQueue);
	free(secondQueue);
	free(mergedQueue);
	printf("Bye!\n");
	exit(0);
}

void firstQueueWork() {
	printf("***********************\n");
	printf("You are working with first queue.\n");
	queueWork(firstQueue);

}

void secondQueueWork() {
	printf("***********************\n");
	printf("You are working with second queue.\n");
	queueWork(secondQueue);
}

void queueWork(struct Queue* queue) {
	uint32_t value = 0;
	uint8_t size = 0;
	uint32_t number = 0;
	printf("Press 0 - to insert value into queue\n");
	printf("Press 1 - to read value from queue\n");
	printf("Press 2 - to get size of queue\n");
	printf("Press 3 - to print queue\n");
	printf("Press 4 - to fill queue with random values\n");
	printf("Press 5 - to output of queue elements in which each set of bits is equal to one\n");
	printf("Press any other digit - to exit main menu\n");
	scanf("%d", &cmd);
	switch (cmd)
	{
	case 0:
		printf("Enter value to insert into queue\n");
		scanf("%u", &value);
		queueInsert(queue, value);
		printf("value is %d\n", value);
		break;
	case 1:
		if (queueIsEmpty(queue)) {
			printf("Queue is empty\n");
		}
		else {
			value = queueRemove(queue);
			printf("Value %d read from queue\n", value);
		}
		break;
	case 2:
		size = queueSize(queue);
		printf("Queue size is %d\n", size);
		break;
	case 3:
		printf("Queue is ");
		queuePrint(queue);
		break;
	case 4:
		printf("Generating random values\n");
		fillRandomValues(queue);
		break;
	case 5:
		searchBitsEqualsOne(queue);
		break;
	default:
		break;
	}
}

void mergeQueues() {
	printf("First queue is ");
	queuePrint(firstQueue);
	printf("Second queue is ");
	queuePrint(secondQueue);
	chessMergeQueues();
	printf("Merged queue is ");
	mQueuePrint(mergedQueue);
}

void chessMergeQueues() {
	while (!queueIsEmpty(firstQueue) || !queueIsEmpty(secondQueue)) {
		if (!queueIsEmpty(firstQueue)) {
			mQueueInsert(mergedQueue, queueRemove(firstQueue));
		}
		if (!queueIsEmpty(secondQueue)) {
			mQueueInsert(mergedQueue, queueRemove(secondQueue));
		}

	}
}

void fillRandomValues(struct Queue* queue) {
	uint8_t queueCounter;
	srand(time(NULL));
	for (queueCounter = queue->first; queueCounter < 5; queueCounter++) {
		uint32_t value = rand() % 100;
		queueInsert(queue, value);
	}
}

void searchBitsEqualsOne(struct Queue* queue) {
	uint32_t number = 0;
	printf("Enter bit number\n");
	scanf("%u", &number);
	printf("Elements in which %d byte is equal to one :\n", number);
	queueSearch(queue, number);
}


