#include"2125_stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

    eleType_s peek(stackType s1) //It checks top element of stack and print the element only
    {
        return s1.top->data;  //if precondition was not there then stack is empty then throw the underflow error
    }

    eleType_s pop(stackType *s1) // It removes top element and display popped element
    {   
        s1->count--;
        snode *temp=s1->top;
        //case1 stack is empty(we do not handle since it is created already)
        //case2 non empty stack
        //case 2a deleting only top element
        s1->top =s1->top->next;
         eleType_s poppedEle =temp->data;
            free(temp);
            return (poppedEle);
    }
    
    void destroyStack(stackType *s1) //It destroy stack and free the allocated dynamic memory
    { 
        while(s1->top!=NULL)
        {s1->count--;
        snode *temp =s1->top;
        s1->top =s1->top->next;
        free(temp);
        }
    }
 
    bool push(eleType_s ip_data, stackType *s1) // It pushes the element into the stack at the top position 
    {   //Allocating memory
        snode *newDataNode =(snode *) malloc(1* sizeof(snode));
        if(newDataNode ==NULL)
            return false;
        else
        {
            newDataNode ->data=ip_data;
            newDataNode->next=s1->top; //it can cover if else statement  ie. in when stack is empty and not empty
            s1->top = newDataNode;
            s1->count++;
            return true;
        }
    }
    
    bool isFulls(stackType s1) // checks the memory of the sys is full or not
    {
        return false; //if malloc return false so it is not able to allocate extra memory 
                      // in that case isFull returns true.
    }
    
    bool isEmptys(stackType s1) //check is there something into the stack or not
    {
        if(s1.top==NULL)
        {
            return true;
        }
        return false;
    }

    stackType createStack() // creates the stack in Linkedlist.
    {
        stackType s;
        s.count=0;
        s.top=NULL;
        return s;
    }
    