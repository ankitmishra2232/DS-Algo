/* 
                        AUTHOR : 2125_ANKIT 
                        PROGRAM: STACK USING ARRAY HEADER FILE
                        DATE CREATED: SEPT 2021 
                        DATE MODIFIED: SEPT 2021 
*/ 
#include<stdbool.h>
#ifndef STACK_H
#define STACK_H
    typedef int eleType;
    
    //DATA
    struct stack
    {
        eleType *stack_array;
        int max_size;
        int top;
        int value;
    };
    typedef struct stack stackType;

//prototypes
    eleType peek(stackType *s1);
    // Function: Returns the top element of the stack without deleting 
    // Input: Stack(*STACKTYPE)
    // Precondition: Stack is Not Empty
    // Output: Element from the top of the stack
    // Postcondition: none
    eleType pop(stackType *s1);
    // Function: Delete element from the top
    // Input: Stack(*STACKTYPE)
    // Precondition: The stack should not empty
    // Output: popped element
    // Postcondition: new top is now the element under it
    void destroyStack(stackType *);
    // Function: Destroys the stack
    // Input:Stack(STACKTYPE)
    // Precondition: None
    // Output: None
    // Postcondition: top is now at -1 position
    stackType createStack(int size);
    // Function: Create an empty stack
    // Input: SIZE(integer) 
    // Precondition: None
    // Output: Stack(STACKTYPE)
    // Postcondition: An Empty Stack is created 
    _Bool push(eleType ele, stackType *s1);
    // Function: Insert an element on the top of the stack
    // Input: Stack(*STACKTYPE), elementType
    // Precondition: The stack should not full
    // Output: True if inserted False if stack is full
    // Postcondition: none
    _Bool isFull(stackType s);
    // Function: Checks if the stack is full
    // Input: Stack(STACKTYPE)
    // Precondition: None
    // Output: True if Full and False if stack have minimum a free space
    // Postcondition: None
    _Bool isEmpty(stackType s);
    // Function: Checks if the stack is empty
    // Input: Stack(STACKTYPE)
    // Precondition: None
    // Output: True if stack is empty False if stack have some element
    // Postcondition: None
#endif