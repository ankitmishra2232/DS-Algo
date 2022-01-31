/*
                AUTHOR : 2125_ANKIT
                ROLL NO : 2125
                PROGRAM: Application of queue and stack 
                DATE CREATED: oct 2021
                DATE MODIFIED: oct 2021
                FUTURE WORK: needs more improvement like in case of discount.
                Improvement and bugs ; when displaying not completed task starts infinite loop and some exit condition fault need to change.
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2125_queue.h"
int main()
{
    printf("\n++++++++++WELCOME TO D'SOUZA INTERIOR DESIGNER++++++++++++++++\n");
    int choice,amount,spend,profit,temp,temp2,total_profit=0;
    char c;
    qType home_q=createQueue();  //creating queue for home renovation
    qType shop_q=createQueue();  //creating queue for shop renovation
    qType home_detail=createQueue(); //creating queue for home renovation
    qType shop_detail=createQueue();  //creating queue for shop renovation
    qType completed_home=createQueue();  //it stores the completed task of home
    qType completed_shop=createQueue();  //it stores the completed task of shop
    qType incompleted_home=createQueue();  //it stores the incompleted task of home
    qType incompleted_shop=createQueue();  //it stores the incompleted task of shop
    qType completed_home_q=createQueue();
    qType completed_shop_q=createQueue();
    printf("Please select who you are\n1>CUSTOMER\n2>ADMIN\n3>EXIT");
    do
    {
        /* code */
    
    
    if(scanf("%d%c",&choice,&c) !=2 || c !='\n' || choice<0)  //Input Validations that takes int value only.
        {   
            while(getchar()!='\n')
                printf("Invalid input please select any Integer between 1,2 or 3");
                printf("\n");
                continue;                                      
        }
        else
        {   
          
            switch (choice)
            {
            case 1:
                do
                { //For costmer
                    printf("\n WELCOME TO D'SOUZA \n");
                    printf("\n1>For Home Renovation\n2>For Shop Renovation\n3>EXIT\n");
                    if(scanf("%d%c",&choice,&c) !=2 || c !='\n' || choice<0)  //Input Validations that takes int value only.
                    {
                        while(getchar()!='\n')
                            printf("Invalid input please select any Integer between 1,2 or 3");
                            printf("\n");
                            continue; 
                    }
                    else
                    {
                        switch (choice)
                        {
                        case 1:
                            do
                            {
                                printf("\n 1. home offer 1\n\t price :- 50,000\n2. home offer 2\n\tprice :- 55,000\n3. home offer 3\n\tprice :- 60,000\n4. EXIT to previous menu\n");
                                if(scanf("%d%c",&choice,&c)!=2||c!='\n'||choice<0)
                                {
                                    while(getchar()!='\n')
                                        printf("Invalid input please select any Integer between 1, 2, 3 or 4");
                                        printf("\n");
                                        continue; 
                                }
                                else
                                {
                                switch (choice)
                                {
                                case 1:
                                    printf("\nHOME-RENOVATION\n=====offer 1 added=====\n ");
                                    enqueue(50000,&home_q);
                                    enqueue(01,&home_detail);                    
                                    break;
                                case 2:
                                    printf("\nHOME-RENOVATION\n=====offer 2 added===== \n");
                                    enqueue(55000,&home_q);
                                    enqueue(02,&home_detail);
                                    break;
                                case 3 :
                                    printf("\nHOME-RENOVATION\n=====offer 3 added===== \n");
                                    enqueue(60000,&home_q);
                                    enqueue(03,&home_detail);
                                    break;
                                case 4:
                                    printf("\n-----------EXIT---------\n");
                                    break;
                                default:
                                    printf("\n Please input valid choice 1/2/3.");
                                    break;
                                }}
                            } while (choice !=4);
                            break;
                        case 2 :
                            do
                            {
                                printf("\n1. Shop offer 1\n\t price :- 1,00,000\n2. Shop offer 2\n\tprice :- 1,05,000\n3. Shop offer 3\n\tprice :- 1,60,000\n4.EXIT to previous menu\n");
                                if(scanf("%d%c",&choice,&c)!=2||c!='\n'||choice<0)
                                {
                                    while(getchar()!='\n')
                                        printf("Invalid input please select any Integer between 1, 2, 3 or 4");
                                        printf("\n");
                                        continue; 
                                }
                                else
                                {
                                switch (choice)
                                {
                                case 1:
                                    printf("\nSHOP-RENOVATION\n=====offer 1 added=====\n ");
                                    enqueue(100000,&shop_q);
                                    enqueue(01,&shop_detail);
                                    break;
                                case 2:
                                    printf("\nSHOP-RENOVATION\n=====offer 2 added===== \n");
                                    enqueue(105000,&shop_q);
                                    enqueue(02,&shop_detail);
                                    break;
                                case 3 :
                                    printf("\nSHOP-RENOVATION\n=====offer 3 added===== \n");
                                    enqueue(1060000,&shop_q);
                                    enqueue(03,&shop_detail);
                                    break;
                                case 4:
                                    printf("\n-----------EXIT-----------\n");
                                    break;
                                default:
                                    printf("\n Please input valid choice 1/2/3.");                
                                } }
                        }while (choice!=4);                 
                        break;
                    case 3 :
                        printf("\n----------EXIT-------\n");
                        break;
                    default:
                        printf("\n please provide input in '1', '2'or'3'");
                        }
                    }
                }while (choice != 3);
                printf("\n ===============THANKS FOR VISITING D'SOUZA========\n\n");
                //break;
            case 2:
                printf("\n\n\n_________________This is for office staffs only_____________");
                printf("\nIf you are not staff please exit from this program");
                // staff indetification FUTURE WORK+
                printf("\n1>HOME Renovation\n2>SHOP renovation\n3>EXIT");
                if(scanf("%d%c",&choice,&c)!=2||c!='\n'||choice<0)
                {
                    while(getchar()!='\n')
                        printf("Invalid input please select any Integer between 1, 2, 3 or 4");
                        printf("\n");
                        continue; 
                }
                else
                {
                    switch (choice)
                    {
                    case 1:
                        do
                        {
                            temp=dequeue(&home_detail);
                            temp2=dequeue(&home_q);
                            printf("\nIf %d is completed press 0 \nIf %d is Incomplete press 1\n",temp,temp);
                            if(scanf("%d%c",&choice,&c)!=2||c!='\n'||choice<0)
                            {
                                while(getchar()!='\n')
                                    printf("Invalid input please select any Integer between 1, 2, 3 or 4");
                                    printf("\n");
                                    continue; 
                            }
                            else
                            {
                                switch (choice)
                                {
                                case 0:
                                    enqueue(temp,&completed_home);
                                    enqueue(temp2,&completed_home_q);
                                    break;
                                case 1:
                                    enqueue(temp,&incompleted_home);
                                    //enqueue(temp2,&incompleted_home_q);
                                    break;
                                default:printf("\n please provide 0 and 1 only");
                                    break;
                                }
                            }
                        } while (!isEmpty(home_detail));
                        do{
                        printf("\n1>For completed Offers\n2>For Incompleted Offers\n3>EXIT");
                        if(scanf("%d%c",&choice,&c)!=2||c!='\n'||choice<0)
                            {
                                while(getchar()!='\n')
                                    printf("Invalid input please select any Integer between 1, 2, 3 or 4");
                                    printf("\n");
                                    continue;
                            }
                            else
                            {
                                do{
                                switch (choice)
                                {
                                case 1:
                                do
                                {
                                    printf("\n 1> Display completed offers\n2> Calculate Profits\n3>Exit from this menu");
                                    if(scanf("%d%c",&choice,&c)!=2||c!='\n'||choice<0)
                                    {
                                        while(getchar()!='\n')
                                            printf("Invalid input please select any Integer between 1, 2, 3 or 4");
                                            printf("\n");
                                            continue;
                                    }
                                    else
                                    {
                                        switch (choice)
                                        {                             
                                        case 1:
                                            printf("\n Completed Tasks");
                                            display_q(&completed_home); //infinite loop
                                            break;
                                        case 2 :
                                            do
                                            {
                                                if (!isEmpty(completed_home))
                                                {
                                                    amount=dequeue(&completed_home_q);
                                                    printf("\nplease provide amount spend by company to calculate profit\n");
                                                    if(scanf("%d",&spend)){
                                                        profit = amount-spend;
                                                        printf("profit : %d",profit);
                                                        total_profit+=profit;}
                                                    else
                                                    {
                                                        printf("No task completed");
                                                    }
                                                }
                                            } while (!isEmpty(completed_home_q));
                                            printf("\n Total profit=%d",total_profit);
                                            break;
                                        case 3:
                                            printf("\nEXIT");
                                            break;
                                        default:printf("\n please choose between 1 ,2 or 3");
                                            break;
                                        }                                    
                                    }    }while(choice!=3);
                                    break;
                                case 2:
                                    if(!isEmpty(incompleted_home))
                                    {
                                        printf("\nNew Tasks:--");
                                        display_q(&incompleted_home);
                                        break;
                                    }
                                    else
                                        break;
                                    break;
                                case 3:
                                    printf("\nEXIT");
                                    break;                               
                                default:printf("\nPlease select 1 or 2");
                                    break;
                                }
                                }while(choice!=3);
                            }
                        }while(choice!=1);
                        break;
                    case 2:
                        do
                        {
                            temp=dequeue(&shop_detail);
                            temp2=dequeue(&shop_q);
                            printf("\nIf %d is completed press 0 \nIf %d is Incomplete press 1\n",temp,temp);
                            if(scanf("%d%c",&choice,&c)!=2||c!='\n'||choice<0)
                            {
                                while(getchar()!='\n')
                                    printf("Invalid input please select any Integer between 1, 2, 3 or 4");
                                    printf("\n");
                                    continue; 
                            }
                            else
                            {
                                switch (choice)
                                {
                                case 0:
                                    enqueue(temp,&completed_shop);
                                    enqueue(temp2,&completed_shop_q);
                                    break;
                                case 1:
                                    enqueue(temp,&incompleted_shop);
                                    //enqueue(temp2,&incompleted_home_q);
                                    break;
                                default:printf("\n please provide 0 and 1 only");
                                    break;
                                }
                            }
                        } while (!isEmpty(shop_detail));
                        do{
                        printf("\n1>For completed Offers\n2>For Incompleted Offers\n3>EXIT");
                        if(scanf("%d%c",&choice,&c)!=2||c!='\n'||choice<0)
                            {
                                while(getchar()!='\n')
                                    printf("Invalid input please select any Integer between 1, 2, 3 or 4");
                                    printf("\n");
                                    continue;
                            }
                            else
                            {
                                do{
                                switch (choice)
                                {
                                case 1:
                                do
                                {
                                    printf("\n 1> Display completed offers\n2> Calculate Profits\n3>Exit from this menu");
                                    if(scanf("%d%c",&choice,&c)!=2||c!='\n'||choice<0)
                                    {
                                        while(getchar()!='\n')
                                            printf("Invalid input please select any Integer between 1, 2, 3 or 4");
                                            printf("\n");
                                            continue;
                                    }
                                    else
                                    {
                                        switch (choice)
                                        {                             
                                        case 1:
                                            printf("\n Completed Tasks");
                                            display_q(&completed_shop); //infinite loop
                                            break;
                                        case 2 :
                                            do
                                            {
                                                if (!isEmpty(completed_shop))
                                                {
                                                    amount=dequeue(&completed_shop_q);
                                                    printf("\nplease provide amount spend by company to calculate profit\n");
                                                    if(scanf("%d",&spend)){
                                                        profit = amount-spend;
                                                        printf("profit : %d",profit);
                                                        total_profit+=profit;}
                                                    else
                                                    {
                                                        printf("No task completed");
                                                    }
                                                }
                                            } while (!isEmpty(completed_shop_q));
                                            printf("\n Total profit=%d",total_profit);
                                            break;
                                        case 3:
                                            printf("\nEXIT");
                                            break;
                                        default:printf("\n please choose between 1 ,2 or 3");
                                            break;
                                        }                                    
                                    }    }while(choice!=3);
                                    break;
                                case 2:
                                    if(!isEmpty(incompleted_shop))
                                    {
                                        printf("\nNew Tasks:--");
                                        display_q(&incompleted_shop);
                                        break;
                                    }
                                    else
                                        break;
                                    break;
                                case 3:
                                    printf("\nEXIT");
                                    break;                               
                                default:printf("\nPlease select 1 or 2");
                                    break;
                                }
                                }while(choice!=3);
                            }
                        }while(choice!=1);
                        break;
                    case 3:
                        printf("\n _______EXIT______________");

                    default: printf("\n Please select between given optioins");
                        break;
                    }
                }
                break;
            case 3:
                printf("\n ===============THANKS FOR VISITING D'SOUZA========\n\n");

                break;

            default:
                break;
            }
        }

    } while (choice!=3);
    destroyQueue(&home_detail);
    destroyQueue(&home_q);
    destroyQueue(&completed_home);
    destroyQueue(&incompleted_home);
    destroyQueue(&completed_home_q);
    destroyQueue(&shop_detail);
    destroyQueue(&shop_q);
    destroyQueue(&completed_shop);
    destroyQueue(&incompleted_shop);
    destroyQueue(&completed_shop_q);

}