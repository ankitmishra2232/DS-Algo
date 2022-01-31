#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"priorityq.h"
int main()
{
    printf("\n Program for priority queue using linkedlist");
    int choice;
    eleType input,dequeued_ele,displayele,ele,ele_priority;
    char c;
    
    queueType s =createQueue();
    do
        {
                printf("\n1.Enqueue\n");
                printf("2.Dequeue\n");
                printf("3.Display\n");
                printf("4.Quit\n");
                printf("\nEnter your choice : ");
                 if(scanf("%d%c",&choice,&c) !=2 || c !='\n' || choice<0)  //Input Validations that takes int value only.
                 {   
                 while(getchar()!='\n')
                   printf("Invalid input please select any Integer between 1-to-4");
                  printf("\n");
                  continue;                                      
                   }
                  else
                   {

                switch(choice)
                {
                 case 1:
                  if(!isFull(s))
                        {
                        printf("\nplease enter all integer numbers : ");
                        printf("\nInput the item to be added in the queue : ");
                         if(scanf("%d%c",&ele,&c) !=2 || c !='\n' || choice<0)  //Input Validations that takes int value only.
                        {   
                        while(getchar()!='\n')
                        printf("Invalid input please input any Integer value");
                        printf("\n");
                        continue;                                      
                        }
                        else
                        {
                        printf("\nEnter its priority : ");
                          if(scanf("%d%c",&ele_priority,&c) !=2 || c !='\n' || choice<0)  //Input Validations that takes int value only.
                        {   
                        while(getchar()!='\n')
                        printf("Invalid input please input any Integer value");
                        printf("\n");
                        continue;                                      
                        }
                        else
                        {
                        //scanf("%d",&ele_priority);
                        enqueue(ele, ele_priority,&s);
                         }}}
                        else
                            printf("\n Overflow");
                        break;
                 case 2:
                        if(!isEmpty(s))
                        {
                            dequeued_ele= dequeue(&s);
                            printf("\n dequeued element: %d",dequeued_ele);
                        }
                        else
                            printf("\n UNDERFLOW");
                        break;
                 case 3:
                               if(!isEmpty(s))
                    {
                        display(&s);

                    }
                    else
                    {
                        printf("queue is Empty");
                        printf("\n Press Next Choice:\t");
                    }
                    break;
                 case 4:
                        printf("\nEXITTED");
                        exit(1);
                 default :
                        printf("\nWrong choice\n");
                }/*End of switch*/
        }}/*End of while*/
        while(choice!=4);
        destroyQueue(&s);
        return 0;
}/*End of main()*/