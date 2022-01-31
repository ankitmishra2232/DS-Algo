/*	Author-> 2125_ANKIT
  	PROGRAM: HEADER FILE OF Ray
	DATE CREATED: NOV 2021
    DATE MODIFIED: NOV 2021
 */
#include<stdlib.h>
#include<stdbool.h>
#ifndef _LL_H
	#define _LL_H
	typedef struct Node
	{
		char nameOfFood[100];
		int quantity;
		float price;
		int data;
		//struct node *prev;
		struct node *next;
	}node;

	// node *head_cost=NULL, *newnode,*tail_cost=NULL;
	// node *head_admin=NULL, *tail_admin = NULL;
	// node *head_s;
	/*create Admin*/
	node *create_adm(node *head,int data,char nameOfFood[100],float price);
	/*create cost*/
	node *create_cost(node *head,int data,int quantity);
	/*display List*/
	void displayList(node *head);
	/*total sale*/
	node* totalsales(int data,int quantity);
	/*calculate_sale*/
	void calculate_sale();
	/*del data*/
	node *del_data(node *head,int data,node *tail);
	/*delete item from menu*/
	int delitem_admin();
	/*remove food from ordering*/
	int delitem_cost();
	/*display bill*/
	void display_bill();
	/*destroy LL*/
	node delList(node *head);

#endif



