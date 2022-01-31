#include"resturant.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//start of yasin
//https://replit.com/@2121-yasin/cproject#proj/menu.c
int append()
{
   FILE *fp;
   char str[80];
 
   fp = fopen("data.txt", "a");
 
   printf("Enter data to append:");
   //gets(str);
   scanf(" %[^\n]s",str);
 
   fprintf(fp, "\n%s",str);
 
   printf("data is appended in data.txt file.");
   fclose(fp);
   //File validation is to be added..
   return 0;
}//end of append


//start of search
#define FILENAME_SIZE 1024
#define MAX_LINE 2048
int searchdel()
{
  // file handles for the original file and temp file
  FILE *file, *temp;

  // store the filename and temp filename
  char filename[FILENAME_SIZE];
  char temp_filename[FILENAME_SIZE];

  // will store each line in the file, and the line to delete
  char buffer[MAX_LINE];
  int delete_line = 0;
  
  // have the user enter the filename, store it into the filename char array
  printf("File: ");
  scanf("%s", filename);
  
  // creates a temp filename "temp___filename.txt" where filename.txt is the 
  // name of the file entered by the user by first copying the prefix temp____
  // to temp_filename and then appending the original filename
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);
  
  // have the user enter the line number to delete, store it into delete_line
  printf("Delete Line: ");
  scanf("%d", &delete_line);
  printf("\nItem id %d is deleted from data.txt file",delete_line);
  
  // open the original file for reading and the temp file for writing
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");
  
  // if there was a problem opening either file let the user know what the error
  // was and exit with a non-zero error status
  if (file == NULL || temp == NULL)
  {
    printf("Error opening file(s)\n");
    return 1;
  }
  
  // current_line will keep track of the current line number being read
  bool keep_reading = true;
  int current_line = 1;
  do 
  {
    // stores the next line from the file into the buffer
    fgets(buffer, MAX_LINE, file);
   
    // if we've reached the end of the file, stop reading from the file, 
    // otherwise so long as the current line is NOT the line we want to 
    // delete, write it to the file
    if (feof(file)) keep_reading = false;
    else if (current_line != delete_line)
      fputs(buffer, temp);
    
    // keeps track of the current line being read
    current_line++;
  
  } while (keep_reading);
  
  // close our access to the files
  fclose(file);
  fclose(temp);
  
  // delete the original file, give the temp file the name of the original file
  remove(filename);
  rename(temp_filename, filename);

  return 0;
}//end of yasin


//create Linked list of admin
	node *head_cost=NULL; 
	node *newnode;
	node*tail_cost=NULL;
	node *head_admin=NULL;
	node *tail_admin = NULL;
	node *head_s; 
node *create_adm(node *head,int data,char nameOfFood[100],float price)
{
	newnode = (node*)malloc(1 *sizeof(node));
	newnode->data=data;
	newnode->price=price;
	strcpy(newnode->nameOfFood,nameOfFood);//it do not consider space as parameter we should take measure //nameOfFood is not assignable so we are using strcpy for storing the value
	newnode->next=NULL;
	newnode->prev=NULL;
	node *temp=head;
	if(temp ==NULL)
		head_admin = tail_admin =newnode; //head_admin and tail_admin is head and tail node respectively of admin
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
		tail_admin=newnode;
	}
	return head_admin;
} //if everything goes right it creats admin

//create customer's linked list and used for selecting items
node *create_cost(node *head,int data,int quantity)
{
	newnode= (node *)malloc(1 *sizeof(node));
	node *temp1 = head_admin; //temp1 for costmer to connect with admin for menu and prices
	int flag=0; //initilizing flag variable for future use
	while(temp1!=NULL)
	{
		if(temp1->data==data)
		{
			flag =1;
			break;
		}
		temp1 = temp1->next;
	}
	if(flag==1)
	{
		newnode->data=data;
		newnode->price=quantity*(temp1->price); //here we are connceting the menu using temp
		newnode->quantity=quantity;
		strcpy(newnode->nameOfFood,temp1->nameOfFood); 
		newnode->next=NULL;
		newnode->prev=NULL;
		node *temp=head_cost;
		if(temp==NULL)
			head_cost=tail_cost=newnode;
		else
		{
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newnode;
			tail_cost=newnode;
		}
	}
	else
    {
        printf("\n\t\t\t\t\t\t\tThis item is not present in the menu!\n");
    }
	return head_cost;

}

//displays placed orders
void displayList(node *head)
{
    node *temp1 = head;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tList is empty!!\n\n");
    }
    else
    {
        printf("\n");
        while(temp1!=NULL)
        {
            if(temp1->quantity==0)
                printf("\t\t\t\t\t\t\t%d\t%s\t%0.2f\n",temp1->data,temp1->nameOfFood,temp1->price);
            else
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t%d\t%0.2f\n",temp1->data,temp1->nameOfFood,temp1->quantity,temp1->price);
            }

            temp1 = temp1->next;
        }
        printf("\n");
    }

}

//for admin total sale of the present day can be shown by this
node* totalsales(int data,int quantity)
{
    newnode = (node*)malloc(1*sizeof(node));
    int flag = 0;

    node * temp1 = head_admin;
    while(temp1->data!=data)
    {
        temp1 = temp1->next;
    }

    newnode->data = data;
    newnode->price = quantity*(temp1->price);
    newnode-> quantity = quantity;
    strcpy(newnode->nameOfFood,temp1->nameOfFood);
    newnode->next = NULL;
    newnode->prev = NULL;

    node *temp = head_s; //stands for head sell

    if(temp==NULL)
        head_s = newnode;
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->data==data)
            {
                flag = 1;
                break;
            }
            temp=temp->next;
        }

        if(flag==1)  //adding if flag 1 
        {
            temp->quantity += newnode-> quantity;
            temp->price += newnode->price;
        }
        else
        {
            temp->next=newnode;
        }
    }

    return head_s;
}

//calculates total bill
void calculatetotsales()
{
    node *temp = head_cost;
    while(temp!=NULL)
    {
        head_s = totalsales(temp->data, temp->quantity);
        temp=temp->next;
    }
} 

// removes itmes from ordered list
node *del_order(node *head,int data,node *tail)
{
    if(head==NULL)
    {
        printf("\n\t\t\t\t\t\t\tList is empty\n");
    }
    else
    {
        node* temp;
        if(data==head->data)
        {
            temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(temp);
        }
        else if(data==tail->data)
        {
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        else
        {
            temp = head;
            while(data!=temp->data)
            {
                temp = temp->next;
            }
            temp->prev = temp->next;
            temp->next = temp->prev;
            
            free(temp);
        }
    }
    return head;
}
//it deletes items from menu
int delitem_admin()
{
    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num;
    scanf("%d",&num);

    node* temp=head_admin;
    while(temp!=NULL)
    {
        if (temp->data == num)
        {
            head_admin = del_order(head_admin, num,tail_admin);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}
// del item from selected
int delitem_cost()
{
    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num;
    scanf("%d",&num);

    node* temp=head_cost;
    while(temp!=NULL)
    {
        if (temp->data == num)
        {
            head_cost = del_order(head_cost,num, tail_cost);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}

//it basically displays bills via calculation
void display_bill()
{
    displayList(head_cost);
    node *temp = head_cost;
    float total_price = 0;
    while (temp!=NULL)
    {
        total_price +=temp->price;
        temp = temp->next;
    }

    printf("\t\t\t\t\t\t\tTotal price: %0.02f\n",total_price);
}
// It destroys every
node* delList(node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        node* temp = head;
        while(temp->next!=0)
        {
            temp = temp->next;
            free(temp->prev);
        }
        free(temp);
        head = NULL;
    }

    return head;
}
//

void adminmenu()
{
    printf("\n\t\t\t\t\t\t\t1. View total sales\n");
    printf("\t\t\t\t\t\t\t2. Add new items in the order menu\n");
    printf("\t\t\t\t\t\t\t3. Delete items from the order menu\n");
    printf("\t\t\t\t\t\t\t4. Display order menu\n");
    printf("\t\t\t\t\t\t\t5. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice --->");
}

void customermenu()
{
    printf("\n\t\t\t\t\t\t\t1. Place your order\n");
    printf("\t\t\t\t\t\t\t2. View your ordered items\n");
    printf("\t\t\t\t\t\t\t3. Delete an item from order\n");
    printf("\t\t\t\t\t\t\t4. Display and print final bill\n");
    printf("\t\t\t\t\t\t\t5. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice --->");
}

void admin()
{
    printf("\n\t\t\t\t\t   ----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t    ADMIN SECTION\n");
    printf("\t\t\t\t\t   ----------------------------------------------\n");
    while(1)
    {
        adminmenu();

        int opt;
        scanf("%d",&opt);

        if(opt==5)
            break;

        switch (opt)
        {
            case 1:
                displayList(head_s);
                break;
            case 2:

                printf("\n\t\t\t\t\t\t\tEnter serial no. of the food item: ");
                int num,flag = 0;
                char name[50];
                float price;
                scanf("%d",&num);

                node *temp = head_admin;

                while(temp!=NULL)
                {
                    if(temp->data==num)
                    {
                        printf("\n\t\t\t\t\t\tFood item with given serial number already exists!!\n\n");
                        flag = 1;
                        break;
                    }
                    temp = temp->next;
                }

                if(flag==1)
                    break;

                printf("\t\t\t\t\t\t\tEnter food item name: ");
                scanf(" %[^\n]s",name);  //it takes inputs till enter button including spaces and space previous to % is for not taking \n before
                printf("\t\t\t\t\t\t\tEnter price: ");
                scanf("%f",&price);
                head_admin = create_adm(head_admin, num, name, price);
                printf("\n\t\t\t\t\t\t\tNew food item added to the list!!\n\n");
                break;
            case 3:
                if(delitem_admin())
                {
                    printf("\n\t\t\t\t\t\t### Updated list of food items menu ###\n");
                    displayList(head_admin);
                }
                else
                    printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist!\n\n");

                break;
            case 4:
                printf("\n\t\t\t\t\t\t\t   ### Order menu ###\n");
                displayList(head_admin);
                break;

            default:
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                break;
        }
    }
}

void customer()
{
    int flag=0,j=1;
    char ch;
    printf("\n\t\t\t\t\t   ----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t    CUSTOMER SECTION\n");
    printf("\t\t\t\t\t   ----------------------------------------------\n");
    while(1)
    {
        customermenu();

        int opt;
        scanf("%d",&opt);

        if(opt==5)
            break;

        switch (opt)
        {
            case 1:
                displayList(head_admin);
                printf("\n\t\t\t\t\t\tEnter number corresponding to the item you want to order: ");
                int n;
                scanf("%d",&n);
                printf("\t\t\t\t\t\tEnter quantity: ");
                int quantity;
                scanf("%d",&quantity);
                head_cost = create_cost(head_cost,n,quantity);
                break;
            case 2:
                printf("\n\t\t\t\t\t\t\t  ### List of ordered items ###\n");
                displayList(head_cost);
                break;
            case 3:
                if(delitem_cost())
                {
                    printf("\n\t\t\t\t\t\t### Updated list of your ordered food items ###\n");
                    displayList(head_cost);
                }
                else
                    printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist!!\n");
                break;
            case 4:
                calculatetotsales();
                printf("\n\t\t\t\t\t\t\t  ### Final Bill ###\n");
                display_bill();
                head_cost = delList(head_cost);
                printf("\n\t\t\t\t\t\tPress any key to return to main menu:\n\t\t\t\t\t\t");
                fflush(stdin);
                ch=fgetc(stdin);
                flag=1;
                break;

            default:
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                break;
        }
        if(flag==1)
            break;
    }
}

void mainmenu()
{
    printf("\n        **************************************************************************\n");
    printf("                            WELCOME TO HOTEL MANAGEMENT SYSTEM                    \n");
    printf("          **************************************************************************\n\n\n");
    printf("\t\t\t\t\t\t\t1. ADMIN SECTION--> \n");
    printf("\t\t\t\t\t\t\t2. CUSTOMER SECTION--> \n");
    printf("\t\t\t\t\t\t\t3. Exit--> \n\n");
    printf("\t\t\t\t\t\t\tEnter Your Choice --->");
}