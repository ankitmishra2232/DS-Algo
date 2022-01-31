/*  C Program to implement priority queue using linked list  */


#include"priorityq.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


    eleType dequeue(queueType *s1) // It removes top element and display popped element
    {
      s1->count--;
      node *temp=s1->front;
      s1->front=s1->front->next;
      eleType dequeued=temp->data;
      if(s1->front==NULL){
        s1->rear=NULL;
      }
      free(temp);
      return (dequeued);
     
    }    
      
        

    void destroyQueue(queueType *s1) //It destroy stack and free the allocated dynamic memory
    { 
        while(s1->front!=NULL)
        {s1->count--;
        node *temp =s1->front;
        s1->front =s1->front->next;
        free(temp);
        }
    }

bool enqueue(eleType ele,eleType ele_priority,queueType *s1)
{
        node *tmp,*p;

        tmp=( node *)malloc(1*sizeof( node));
        if(tmp==NULL)
        {
                printf("\nMemory not available\n");
                return false;
        }
        tmp->data=ele;
        tmp->priority=ele_priority;
        //Queue is empty or item to be added has priority more than first element
        if( isEmpty(*s1) || ele_priority < s1->front->priority )
        {
                tmp->next=s1->front;
                s1->front=tmp;
        }
        else
        {
                p = s1->front;
                while( p->next!=NULL && p->next->priority<=ele_priority )
                        p=p->next;
                tmp->next=p->next;
                p->next=tmp;
        }
}


    bool isFull(queueType s1) // checks the memory of the sys is full or not
    {
        return false;
    }
    
    bool isEmpty(queueType s1) //check is there something into the stack or not
    {
        if(s1.front==NULL)
        {
            return true;
        }
        return false;
    }

    queueType createQueue() // creates the stack in Linkedlist.
    {
        queueType s;
        s.count=0;
        s.front=NULL;
        s.rear= NULL;
        return s;
    }


 void display(queueType *s1)  
{    
    node *ptr = s1->front;        
    if(s1->front == NULL)  
    {  
      printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nQueue is :\n");
        printf("\nPriority       Item\n"); 
        while(ptr != NULL)   
        {  
            printf("%5d        %5d\n",ptr->priority,ptr->data);  //%d for ptr->data
            ptr = ptr->next; 
        }  
    }  
}  
