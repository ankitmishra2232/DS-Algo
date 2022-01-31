/*
AUTHOR: Ankit Mishra
ROLL NO: 2125
PROGRAM: QUEUE USING LINKED LIST LIB IMPLEMENTATION
DATE CREATED: DEC 2021
DATE MODIFIED: DEC 2021
*/
// DS DEVELOPER
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2125_queue.h"
_Bool isempty(queueType s1){ // Checks if queue is empty or not
	if(s1.start==NULL && s1.rear== NULL){
		return true;
	}
	return false;
}
_Bool isfull(queueType s1){ // Checks if queue is full or not
	return false;
}
queueType createQueue(){ // Creates the queue
	queueType s1;
	s1.count = 0;
	s1.start = NULL;
	s1.rear = NULL;
	return s1;
}

_Bool enqueue(eleType ip_data, queueType *s1){ // Adds elemens on top of the stack
	node* newDataNode = (node*)malloc(1* sizeof(node)); //memory accocation
    if(newDataNode==NULL)
        return false;
    else
    {
        newDataNode->data=ip_data;
        if(s1->start==NULL)
        {
            s1->start=newDataNode;
            s1->rear=newDataNode;
            s1->start->next=NULL;
            s1->rear->next=NULL;
        }
        else
        {
            s1->rear->next=newDataNode;
            s1->rear=newDataNode;
            s1->rear->next=NULL;

        }
    }	
}
eleType dequeue(queueType *s1){ // Removes the element from the top of the queue
    	s1->count--;
    	node *temp = s1->start;
    	s1->start = s1->start->next;
    	eleType poppedEle = temp->data;
		if(s1->start == NULL)	
    		s1->rear = NULL;
       	free(temp);
       	return(poppedEle);
}
void displayQueue(queueType *s1) { // Displays all the elements present n the queue
    node *temp = s1->start; 
    printf("\nName       	ContactNumber		Email			Size		Color		Theme");        
    while(temp != NULL){  
    	printf("\n%s     |%s             |%s             |%s             |%s             |%s",temp->data.name,temp->data.CNo,temp->data.email,temp->data.size,temp->data.color,temp->data.theme);  
    	temp = temp->next; 
    }    
} 
void destroyQueue(queueType *s1){ // Destroys the stack and free the space
	while(s1->start!=NULL){
		s1->count--;
		node *temp = s1->start;
		s1->start= s1->start->next;
		free(temp);
	}	
}
