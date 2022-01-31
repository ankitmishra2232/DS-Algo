/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: HEADER FILE OF HEAP
                DATE CREATED: NOV 2021
                DATE MODIFIED: DEC
 */

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include"2125_heap.h"

  Heap *CreateHeap(){
    Heap *h = (Heap * ) malloc(sizeof(Heap)); //one is number of heap

    //check if memory allocation is fails
    if(h == NULL){
        printf("Memory Error!");
        return 0;
    }
    h->count=0;
    h->arr = (int *) malloc(1*sizeof(int)); 

    //check if allocation succeed
    if ( h->arr == NULL){
        printf("Memory Error!");
        return 0;
    }
    return h;
}

void insert(Heap *h, int key){
        h->arr[h->count] = key;
        re_Heap_up(h, h->count);
        h->count++;
}

void re_Heap_up(Heap *h,int index){//reheapup
    int temp;
    int parent_node = (index-1)/2;

    if(h->arr[parent_node] > h->arr[index]){
        //swap and recursive call
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        re_Heap_up(h,parent_node);
    }
}

void re_Heap_down(Heap *h, int parent_node){//reheapdown
    int left = parent_node*2+1;
    int right = parent_node*2+2;
    int min;
    int temp;

    if(left >= h->count || left <0)
        left = -1;
    if(right >= h->count || right <0)
        right = -1;

    if(left != -1 && h->arr[left] < h->arr[parent_node])
        min=left;
    else
        min =parent_node;
    if(right != -1 && h->arr[right] < h->arr[min])
        min = right;

    if(min != parent_node){
        temp = h->arr[min];
        h->arr[min] = h->arr[parent_node];
        h->arr[parent_node] = temp;

        // recursive  call
        re_Heap_down(h, min);
    }
}

int PopMin(Heap *h){
    int pop;
    if(h->count==0){
        printf("\n__Heap is Empty__\n");
        return -1;
    }
    // replace first node by last and delete last
    else{
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    re_Heap_down(h, 0);
    return pop;
    }
}
void print(Heap *h){
    int i;
    printf("____________Print Heap_____________\n");
    for(i=0;i< h->count;i++){
        printf("-> %d ",h->arr[i]);
    }
    printf("->\n");
}

void destroyHeap(Heap *h){
  while(h!=NULL){
    Heap *temp=h;
    free(temp);
  }
}

