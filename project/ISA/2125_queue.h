/*
AUTHOR: Ankit Mishra
ROLL NO: 2125
PROGRAM: QUEUE USING LINKED LIST LIB HEADER FILE
DATE CREATED: DEC 2021
DATE MODIFIED: DEC 2021
*/
// DS designer
#ifndef _QUEUE_H
	#define _QUEUE_H
	// Data
  typedef struct data1{
    char name[20];
    char CNo[10];
    char email[30];
    char size[10];
    char color[15];
    char theme[15];
  }eleType;

	struct queue{	
		struct queue_node * start;
		struct queue_node * rear;
		int count;
	};
	typedef struct queue queueType;
	struct queue_node{
		eleType data;
		struct queue_node *next;
	};
	typedef struct queue_node node;
	// ProtoTypes
	// Function:Create a new empty queue
	// Input:None
	// Precondition:None
	// Output:queueType
	// Postcondition:An empty queue is created
	queueType createQueue();
	// Function:Check if queue is empty
	// Input:queueType
	// Precondition:None
	// Output:True if queue is empty and False if queue isnot empty
	// Postcondition:None
	_Bool isempty(queueType);
	// Function:Check if queue is full
	// Input:queueType
	// Precondition:None
	// Output:True if full and False if not full
	// Postcondition:None
	_Bool isfull(queueType);
	// Function:Insert an element at top
	// Input:*queueType,eleType
	// Precondition:queue is not full
	// Output:True if insertion is successful and false if insertion is unsuccessfull
	// Postcondition:A new element is inserted
    _Bool enqueue(eleType ,queueType *s1);
   	// Function:remove an ele from top of the queue
	// Input:*queueType
	// Precondition:queue is not empty
	// Output:ele from the top of the queue is deleted
	// Postcondition:element at top is deleted
   	eleType dequeue(queueType *);
   	// Function:Destroys the queue
	// Input:*queueType
	// Precondition:None
	// Output:None
	// Postcondition:Delete all elements and free memory
   	void destroyQueue(queueType *);
	// Function:Displays the elements in the queue
	// Input:queueType
	// Precondition:queue is not empty
	// Output:All elements present in the queue
	// Postcondition:None
	void displayQueue(queueType *);
#endif
