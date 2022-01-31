/*
AUTHOR: yasin
ROLL NO: 2121
PROGRAM: QUEUE USING LINKED LIST
DATE CREATED: OCT 2021
DATE MODIFIED: OCT 2021
NEEDS FUTHER IMPROVEMENT
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2121_queue.h"
int main()
{
    printf("\nWELCOME TO e quiltmaker designs\n");
    int choice;
    char ch;
    eleType insertL,insertO;
	  queueType local_orders = createQueue(); //queue for local orders 
    queueType out_of_state_orders =createQueue(); // queue for out of state order
    queueType mergedQueue=createQueue(); // queue for merge
    do
    {
      printf("\n1.Add new local orders\n2.Add new out-of-state orders\n3.Display all local orders\n4.Display all out-of-state orders\n5.merged Orders\n6.Exit\n");
      if(scanf("%d%c",&choice,&ch) !=2 || choice<0){ // input validation
            		while(getchar()!='\n')
                		printf("Invalid input Select Integer Between 1,2 And 6");
                		printf("\n");
                		continue;		
        	}
      else{
          switch(choice){
                case 1:
                   // local orders queue
                    printf("Enter the Customer Name, Contact NO, EmailId, Size, colour scheme,Design Theme to be inserted in Local Orders\n");
                    scanf("%s\t%s\t%s\t%s\t%s\t%s",insertL.name,insertL.CNo,insertL.email,insertL.size,insertL.color,insertL.theme);
                    enqueue(insertL, &local_orders);
                    printf("Data Added to the queue");
                    break;
                case 2:
                     //out of state oders 
                    printf("Enter the Customer Name, Contact NO, EmailId, Size, colour scheme,Desidn Theme to be inserted in out of state orders\n");
                    scanf("%s\t%s\t%s\t%s\t%s\t%s",insertO.name,insertO.CNo,insertO.email,insertO.size,insertO.color,insertO.theme);
                    enqueue(insertO, &out_of_state_orders);
                    printf("Element Added to the queue");
                    break;
                case 3:
                    if(!isempty(local_orders)){ // display for local_orders
                            		displayQueue(&local_orders);
                        	}
                        	else
                            		printf("\nthere is no  order in local ");
                            		break;
                case 4:
                    if(!isempty(out_of_state_orders)){ // display for out_of_state_orders
                            		displayQueue(&out_of_state_orders);
                        	}
                        	else
                            		printf("\nthere is no oder in out of state");
                            		break;
                case 5:
                    //merged both and display  not working properly need some changes
		  		        while(local_orders.count!=0&& out_of_state_orders.count!=0)
				          {
					          eleType x = dequeue(&local_orders);
                    if(!isempty(local_orders))
                      enqueue(x,&mergedQueue);
                    eleType y=dequeue(&out_of_state_orders);
                    if(!isempty(out_of_state_orders))
                      enqueue(y,&mergedQueue);
                  }
                displayQueue(&mergedQueue);

                case 6:
                    printf("exit");
                    break;
                default:
                  printf("Invalid Input enter betweeen 1-6 ");
              }
              printf("Thank YOU");
          }
    }while(choice!=6);
      destroyQueue(&local_orders);
      destroyQueue(&out_of_state_orders);
      destroyQueue(&mergedQueue);

}