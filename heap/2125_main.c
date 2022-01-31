/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: HEADER FILE OF HEAP
                DATE CREATED: DEC 2021
                DATE MODIFIED: DEc 2021
 */
#include"2125_heap.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
    int i,n,hp[100],choice,k;//
    char term,c;

 printf("\n************ MIN HEAP ************\n");
    Heap *heap = CreateHeap(n/*HEAP_SIZE, 1*/); //Min Heap
    if( heap == NULL ){
        printf("__Memory Issue____\n");
        return -1;
    }

    // for(i =9;i>0;i--)//  for worst case
    //     insert(heap, i);//
		// scanf("%d",&i);
    do{
		while(i!=99999)
      	{
	    	printf("please insert an element and press ENTER\n After entering all your elements please type '99999': ");
		       if(scanf("%d%c",&i,&c) !=2 || c !='\n') //Input validation
            {
            printf("please Provide Integer values to construct min-heap\n\n");
            break;
            }
            else
            {
		    if(i!=99999)
		    	insert(heap,i);
      	}}

    printf("\nEnter Your Choice:\n1.Insert\n2.To Display\n3.Remove min-ele.\n4.Exit\n");
		if(scanf("%d%c",&choice,&c) !=2 || c !='\n' || choice<0)  //Input Validation
    {
      while(getchar()!='\n')
      printf("Invalid input please select any Integer between 1 to 5");
      continue;
      }
    else
      {
		switch(choice)
		{
      case 1://insert
            printf("please provide input as int to store");
            scanf("%d",&k);
            insert(heap,k);
            break;
      case 2://Display
            print(heap);
            break;
      case 3://Remove min
	  		if(PopMin(heap)!=-1)
			  {
				  printf(" Pop Minima that is : %d\n", PopMin(heap));
            	printf("After removing min element from heap the min heap will look like: \n");
	            print(heap);
			  }
			else
				printf("THERE is nothing to remove");
            
            break;
      case 4://exit
            printf("_____E__X__I__T____");
            exit(0);
            break;
      default:
            printf("enter a valid choice\n");
    }
    }}while(choice!=4);
    destroyHeap(heap);
    return 0;
    
}
