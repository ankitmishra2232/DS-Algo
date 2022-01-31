/*
  AUTHOR : 2125_ANKIT
  PROGRAM: BINARY SEARCH TREE USING LINKED LIST MAIN FILE
  DATE CREATED: OCT 2021
  DATE MODIFIED: OCT 2021
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2125_bst.h"
int main()
{
    printf("This program is For making Binary Search Tree");
    printf("\nPlease Enter Valid Choice :-");
    int choice;
    char c;
    eleType input, searched_ele;
    keyType key;
    treeType *tree =BST_createTree();
    do
    {
        printf("\n 1> Insert\n2>inTraverse \n3>postTravserse\n4>preTraverse \n 5>Search\n 6> Delete\n 7>EXIT\n");
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
                case 1://INSert
                    printf("\nEnter the values to be inserted like Roll number and Name\n:-\t");
                    while(scanf("%d%s",&input.key,input.name) !=2){
						while(getchar()!='\n')
                		printf("Invalid input! Please enter an integer for roll no. and a string for name.");
                		printf("\n");                             
					}
                    if(BST_insert(tree,input)==true)
                        printf("\n %d &  %s Inserted",input.key,input.name);
                    
					break;
                case 2://inTraverse
                    if(!isEmpty(tree))
                    {   
                        printf("\nIn Traverse : \n");
                        BST_intraverse(tree);
                    }
                    else
                        printf("\n no Elemented is inserted\n");

                    break;
                case 3: //Post Travserse
                    if(!isEmpty(tree))
                    {
                        printf("\nPost Traverse : \n");
                        BST_posttraverse(tree);
                    }
                    else
                        printf("\n no Elemented is inserted\n");

                    break;
                case 4:// Pre Traverse
                    if(!isEmpty(tree))
                    {
                        printf("\nPre Traverse : \n");
                        BST_pretraverse(tree);
                    }
                    else
                        printf("\n no Elemented is inserted\n");

                    break;
                case 5: // search
                    if(!isEmpty(tree))
                    {
                        while(scanf("%d",&key) != 1)  //Input Validations that takes int value only.
        				{   
        				    while(getchar()!='\n');

							printf("Invalid input! Please enter a roll no of integer data type.");
							printf("\n");
        				    continue;                                      
        				}
                        if(search(tree->root,key))
                            printf("\nData Found");
                        else
                        	printf("Not Found");
                    }
                    else
                        printf("underFlow");
                        break;
                case 6: // Del
                    if(!isEmpty(tree))
                    {
                       while(scanf("%d",&key) != 1)
						{
							while(getchar()!='\n');

							printf("Invalid input! Please enter a roll no of integer data type.");
							printf("\n");
        				    continue; 

						}
                        if(BST_del(tree,key)==true)
                            printf("\nDEL SuccessFul %d",key);
                        else
                            printf("\n NOT FOUND");
                    }
                    else
                        printf("\nUnderflow");
                        break;
                case 7:
                    printf("\nEXIT");
                    break;

            
                default:
                printf("\nInvalid choice please choose between 1-7");
                    break;
            }   
        }

    }while (choice!=7);
    destroybst(tree);
    BST_intraverse(tree); 
    return 0;
}