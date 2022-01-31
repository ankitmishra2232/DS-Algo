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
		struct Node *prev;
		struct Node *next;
	}node;


	/*create Admin*/ //menu node
	node *create_adm(node *head,int data,char nameOfFood[100],float price);
	/*create cost*/ //selected from menu
	node *create_cost(node *head,int data,int quantity);
	/*display List*/
	void displayList(node *head);
	/*total sale*/
	node* totalsales(int data,int quantity);
	/*calculate_sale*/
	void calculatetotsales();
	/*del data*/
	node *del_order(node *head,int data,node *tail);
	/*delete item from menu*/
	int delitem_admin();
	/*remove food from ordering*/
	int delitem_cost();
	/*display bill*/
	void display_bill();
	/*destroy LL*/
	node *delList(node *head);
	void adminmenu();
	void customermenu();
	void admin();
	void customer();
	void mainmenu();
  
  int append();
  int searchdel();
#endif



