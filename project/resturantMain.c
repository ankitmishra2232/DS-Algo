#include<stdio.h>
#include<time.h>
#include"resturant.h"
//#include "2125_queue.h"


node *head_admin;
//qType *q;
int main()
{
	
    head_admin = create_adm(head_admin,1,"Hot and Sour Soup",100);
    head_admin = create_adm(head_admin,2,"Manchow Soup",200);
    head_admin = create_adm(head_admin,3,"Manchurian Noodles",150);
    head_admin = create_adm(head_admin,4,"Fried Rice",180);
    head_admin = create_adm(head_admin,5,"Hakka Noodles",80);

    while(1)
    {
        mainmenu();
        int choice;
        scanf("%d",&choice);

        if(choice==3)
        {
            printf("\n\n\t\t\t\t\t\t\t**********Thank you!!**********\n");
            break;
        }

        switch (choice)
        {
            case 1:
                admin();
                break;
            case 2:
                customer();
                break;
            case 3:
                break;

            default:
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                break;
        }
    }
}