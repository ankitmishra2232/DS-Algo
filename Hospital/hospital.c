#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<curses.h>
#include<time.h>
#include"priorityq.h"
  //time
  void times()
  {
    struct tm* ptr;

    time_t t;

    t = time(NULL);

    ptr = localtime(&t);

    printf("%s", asctime(ptr));
  }
  
int main()
{
    printf("\n ******* WELCOME ******* ");
    int choice,ele_priority;
    eleType input,dequeued_ele,displayele,data;
    char c;
    
    queueType s =createQueue();
    do
        {
                printf("\n ******** Massachusett Hospital ******** \n");
                printf("\n1.Patient Registration\n");
                printf("2.EXIT\n");
                printf("\nEnter your choice : ");
                 if(scanf("%d%c",&choice,&c) !=2 || c !='\n' || choice<0)  //Input Validations that takes int value only.
                 {   
                 while(getchar()!='\n')
                   printf("Invalid input please select any Integer between 1-to-2");
                  //printf("\n");
                  continue;                                      
                   }
                  else
                   {

                switch(choice)
                {
                 case 1: //new appointment
                 do{
                        printf("\n1.New Appointment");
                        printf("\n2.Show Registered data");
                        printf("\n3.Generate Bill\n");
                        printf("4.Remove patient data\n");
                        printf("5.Back-to-main-menu\n");
                        printf("select apprppriate choice : ");
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
                             printf("Please enter patient information for Appintment\n");
                             printf("\nEnter PatientName : ");
                             scanf("%s",data.pname);
                             printf("\nEnter PatientConNo : ");
                             scanf("%s",data.con_no);
                             printf("\nEnter PatientAddress : ");
                             scanf("%s",data.address);
                             printf("\nEnter PatientDisease : ");
                             scanf("%s",data.disease);
                             printf("\nEnter DoctorName : ");
                             scanf("%s",data.docname);
                             printf("\nEnter TreatmentFee : ");
                             scanf("%s",data.treatmentfee);
                             printf("\nlesser number higher the priority");
                             printf("\nEnter Priority how badly they need a treatment :");
                             scanf("%d",&ele_priority);
                             enqueue(data,ele_priority,&s);
                             break;
                             case 2:
                              if(!isEmpty(s))
                               {
                              display(&s);

                              }
                              else
                              {
                              printf("\nit's Empty !!!\n");
                              printf("\n Press Next Choice:\t");
                              }
                             break;
                             case 3:
                             printf("\n");
                             printf("\n\n#################### $$ FEE $$ ####################\n");
                             times();
                             printf("\n\n");
                             printf("DoctorsName : %s",data.docname);
                             printf("\t\tHospital ContactNo : 9970811754");
                             printf("\n");
                             printf("\nAmount Paid : %s",data.treatmentfee);
                             printf("\n\n");
                           
                             printf("\n\n#################### THANKYOU ####################\n");
                             break;
                             case 4:
                             if(!isEmpty(s))
                             {
                            dequeued_ele= dequeue(&s);
                            printf("\ndata removed after treatment over as FCFS bases\n");
                            }
                             else
                            printf("\n UNDERFLOW");
                             break;
                             case 5:
                             break;
                             default :
                             printf("\nwrong choice\n");
                           }}}while(choice!=5);

                        break;
                 case 2:
                        printf("\nEXITTED");
                        exit(1);
                 default :
                        printf("\nWrong choice\n");
                }/*End of switch*/
        }}/*End of while*/
        while(choice!=2);
       destroyQueue(&s);
        return 0;
}/*End of main()*/