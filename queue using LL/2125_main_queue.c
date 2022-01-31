/*
AUTHOR: ANKIT KUMAR MISHRA
ROLL_NO: 2125
PROGRAM: QUEUE USING LINKED LIST
DATE CREATED: oct 2021
DATE MODIFIED: oct 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2125_queue.h"
int main(){
	printf("This program make a queue using linkedlist");
    	int choice;
    	char c;
   	eleType input,popped_ele;
    	qType q = createQueue();
    	do{
        	printf("\n1>Enqueue\n2>Dequeue\n3>Display\n4>Exit\n");
        	if(scanf("%d%c",&choice,&c) !=2 || c !='\n')
			{
            	printf("\nInvalid input please select between 1-4");
            	return 0;		
        	}
        	else{
                switch (choice)
				{
                	case 1: //Enqueue
                        if(!isFull(q))
						{
                            printf("\nEnter a value to be pushed to the queue:");
                            if(scanf("%d%c",&input,&c) !=2 || c !='\n')
							{
                               	printf("\nInvalid input!.Enter Integer value to be pushed");
                               	return 0;
                           	}
                            	else
								{
                               		if(enqueue(input, &q)==true)
                                		printf("Element %d Added to the queue",input);
                            	}
                        }
                        	else
                            	printf("\nOVERFLOW!!!!"); 
                        		break;

                		case 2: //dequeue
                        	if(!isEmpty(q))
							{
                            		popped_ele = dequeue(&q);
                            		printf("\nPopped element: %d",popped_ele);
                        	}
                        	else
                            		printf("\nUNDERFLOW!!!!");
                        		break;
				
                		case 3: //Display
                        	if(!isEmpty(q))
							{
                            	printf("\nQueue is displayed.");
								display(&q);
                        	}
                        	else
                            		printf("\nQueue is Empty.");
                            		break;
                		case 4://Exit
                    			break;
                    		
                		default:
                    			printf ("\nEnter a Valid INPUT between 1-4");
                	}
       	}
    	} while (choice != 4 );
    	
    		destroyQueue(&q);
    		printf("\n%d",q.front);
    		
     return 0;
     
}
