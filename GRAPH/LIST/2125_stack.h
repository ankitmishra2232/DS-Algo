/*
                AUTHOR : 2125_ANKIT
                PROGRAM: HEADER FILE OF IMPLEMENTATION FILE for STACK USING LINKED LIST
                DATE CREATED: SEPT 2021
                DATE MODIFIED: SEPT 2021
 */
#include<stdbool.h>
#ifndef STACK_H
    #define STACK_H
    typedef char eleType_s;
    
    //DATA
    struct stack
    {
        struct stack_node *top;  
        int count;
    };
    typedef struct stack stackType;

    struct stack_node
    {
        eleType_s data;
        struct stack_node *next;

    };
    typedef struct stack_node snode;

//prototypes
    eleType_s peek(stackType s1);
    //Function:      Returns top element of the stack without deleting.
    //Input:         stackType
    //Precondition:  stack is not Empty
    //Output:        Element from top of the stack
    //Postcondition: none.
    eleType_s pop(stackType *s1);
    //Function:      removes Element from the top.
    //Input:         *StackType
    //Precondition:  stack is not empty
    //Output:        element from top of the stack 
    //Postcondition: element at the top deleted
    void destroyStack(stackType *);
    //Function:      Destroys the stak and free memory
    //Input:         *stackType
    //Precondition:  none
    //Output:        none
    //Postcondition: delete all memory and free memory
    stackType createStack();
    //Function:      creates a new empty stack
    //Input:         none
    //Precondition:  none
    //Output:        stackType
    //Postcondition: An empty stack is created
    _Bool push(eleType_s ele, stackType *s1);
    //Function:      insert an element on top
    //Input:         *stackType, elementType
    //Precondition:  stack is not full
    //Output:        true if successfull, false if unsuccessfull
    //Postcondition: new element is inserted
    _Bool isFulls(stackType s);
    //Function:      check if stack is full
    //Input:         stackType
    //Precondition:  none
    //Output:        true if full, false if not full
    //Postcondition: none
    _Bool isEmptys(stackType s);
    //Function:      check if stack is empty
    //Input:         stackType
    //Precondition:  none
    //Output:        true if empty, false if not empty
    //Postcondition: none
#endif