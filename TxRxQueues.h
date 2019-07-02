/* Header file for Transmit/Recieve Queues. */

#ifndef Tx_Rx_Queue
#define Tx_Rx_Queue
/* A structure representing a record for the transmit/receive queues made. */
struct qRecord{
	char *inPointer;
	char *outPointer;
	char *bufferStart;
	char *bufferEnd;
	int   bufferSize;
	int   numEnqueued;
};

void init_Queue(struct qRecord*, char*, int);
int enqueue(char character, struct qRecord*);
int dequeue(char*, struct qRecord*);

#endif Tx_Rx_Queue
