/*
                AUTHOR : 2125_ANKIT
                PROGRAM: STACK USING LINKED LIST
                DATE CREATED: SEPT 2021
                DATE MODIFIED: SEPT 2021
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"stack.h"
int main()
{
    printf("\n Program for stack using array");
    int choice,size;
    eleType input,popped_ele, peeked_ele,display;
    char c;
    
    stackType s =createStack();
    do
    {
        printf("\nPlease Choose:-\n(1)push\n(2)pop\n(3)peak\n(4)EXIT\n");
        if(scanf("%d%c",&choice,&c) !=2 || c !='\n')  //Input Validation
        {
            printf("Invalid input please select any Integer between 1-4");
            return 0;
        }
        else
        {
            switch (choice)
            {
                case 1: //Push
                        if(!isFull(s))
                        {
                            printf(" Enter a value to be pushed:");
                            if(scanf("%d%c",&input,&c) !=2 || c !='\n') //Input validation
                            {
                                printf("please Provide Integer to be pushed\n\n");
                                return 0;
                            }
                            else
                            {
                                if(push(input, &s)==true)
                                printf("Element Added to the stack");
                            }
                            if(push(input, &s)==true)
                                printf("Element Added to the stack");
                        }
                        else
                            printf("\n Overflow");
                        break;
                case 2: //POP
                        if(!isEmpty(s))
                        {
                            popped_ele= pop(&s);
                            printf("\n Popped element: %d",popped_ele);
                        }
                        else
                            printf("\n UNDERFLOW");
                        break;
                case 3: //Peek
                        if(!isEmpty(s))
                        {
                            peeked_ele=peek(s);
                            printf("\n peeked element :%d",peeked_ele);
                        }
                        else
                        {
                            printf("\n UNDERFLOW");
                        }
                        break;
                case 4:
                    printf("EXIT");
                    break;

                default:
                    printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
        }
        

    } while (choice != 4);
    destroyStack(&s);
    
    printf("\n%d",s.top);

	
	
	
	
    return 0;
    

}
