/*
 * Desc: Circular FIFO queues.
 * Author: Prangon Das (pcd3897@g.rit.edu)
 */

#include "TxRxQueues.h"

#define FAIL (0)
#define SUCCESS (1)

void init_Queue(struct qRecord *record, char *buffer, int capacity)
{
	record->inPointer = buffer;
	record->outPointer = buffer;
	record->bufferStart = buffer;
	record->bufferEnd = buffer + capacity;
	record->bufferSize = capacity;
	record->numEnqueued = 0;
}

int enqueue(char character, struct qRecord *record)
{
	if (record->numEnqueued < record->bufferSize) {
		*record->inPointer++ = character;
		if (record->inPointer >= record->bufferEnd) {
			record->inPointer = record->bufferStart;
		}
		record->numEnqueued++;
	} else {
		return FAIL;
	}
	return SUCCESS;
}

int dequeue(char *character, struct qRecord *record)
{
	if(record->numEnqueued != 0){
		*character = *record->outPointer++;
		if (record->outPointer >= record->bufferEnd) {
			record->outPointer = record->bufferStart;
		}
		record->numEnqueued--;
	}else{
		return FAIL;
	}
	return SUCCESS;
}
