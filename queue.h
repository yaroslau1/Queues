
#include <stdint.h>

#define QUEUE_MAX_SIZE 100
#define MERGED_QUEUE_MAX_SIZE 200

struct Queue {
    uint32_t queue[QUEUE_MAX_SIZE];
    uint8_t last, first;
};

struct MergedQueue {
    uint32_t queue[MERGED_QUEUE_MAX_SIZE];
    uint8_t last, first;
};

void queueInit(struct Queue* queue);
void queueInsert(struct Queue* queue, uint32_t value);
uint8_t queueIsEmpty(struct Queue* queue);
void queuePrint(struct Queue* queue);
uint8_t queueSize(struct Queue* queue);
uint32_t queueRemove(struct Queue* queue);
void queueSearch(struct Queue* queue, uint8_t number);

void mQueueInit(struct MergedQueue* queue);
void mQueueInsert(struct MergedQueue* queue, uint32_t value);
uint8_t mQueueIsEmpty(struct MergedQueue* queue);
void mQueuePrint(struct MergedQueue* queue);
