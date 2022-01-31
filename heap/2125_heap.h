/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: HEADER FILE OF HEAP
                DATE CREATED: NOV 2021
                DATE MODIFIED: DEC 2021       
                
 */
#include<stdbool.h>
#ifndef _HEAP_H
    #define _HEAP_H

        struct Heap{
            int *arr;
            int count;
            // int heap_type; // for min heap , 1 for max heap
        };
        typedef struct Heap Heap;
        //Function :  creates a new empty heap space
            //precondition : none
            //input: none
            //output: Heap
            //postCondition : an Empty heap space is created
        Heap *CreateHeap();
        // Function: inserts an element in array
            // Precondition: array is not full
            // Input: Heap *h, int key
            // output: inserted all elements 
            // Postcondition: new elements is inserted
        void insert(Heap *h, int key);
        //Function: displays the elements of the array(heap)
            //Precondition: array heap is not empty
            //Input: Heap *h
            //output: displays the elements of the array (heap) in an increasing order
            //Postcondition: none
        void print(Heap *h);
        //Function: If Maxchild < node value swap between maxChild & node value (max heap)
            //Precondition: heap is not empty
            //Input: Heap *h,int index
            //output: displays the elements of the array (heap) in Decreasing order
            //Postcondition: re_Heap_up is successfull
        void re_Heap_up(Heap *h,int index);
        //Function: If node < maxChild value swap between node value & maxChild(min heap)
            //Precondition: heap is not empty
            //Input: Heap *h,int parent_node
            //output: displays the elements of the array (heap) in increasing order
            //Postcondition: re_heap_down is successfull
        void re_Heap_down(Heap *h, int parent_node);
        //Function: pop min element & display updated the elements of the array(heap)
            //Precondition: array heap is not empty
            //Input: Heap *h
            //output: displays the elements of the array (heap) in increasing order
            //Postcondition: none
        int PopMin(Heap *h);
        /*Function: Search Element if there is any
            input: Heap and *h
            precondition : heap has been destroyed
            output: none
            postcondition : heap destroyed successfully */
        void destroyHeap(Heap *); 
#endif