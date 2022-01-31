/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: Main FILE OF GRAPH
                DATE CREATED: NOV 2021
                DATE MODIFIED: NOV 2021
 */
#include <stdio.h>
#include "2125_graph.h"
#include "2125_queue.h"
#include "2125_stack.h"

int main()
{
  printf("<<Graph Using linked list>>\n");
  int choice;
  char ch;
  keyType keyE;
  eleType newDate;
  graphNd *graph = create_graph();
  
  do{
    printf("\n1.InsertVertex\n2.InesertEdge\n3.DeleteVertex\n4.DeleteEdge\n5.Bfs\n6.Dfs\n7.Exit\n");
    if(scanf("%d%c",&choice,&ch) !=2 || ch !='\n' || choice<0)  //Input Validations
        {   
            while(getchar()!='\n')
                printf("Invalid input please select any Integer between 1-to-7\n");
                printf("\n");
                continue;                                      
        }
        else{
          switch(choice){
          case 1: //InsertVertex
              printf("Enter the Key and name to be inserted in the Graph\n");
              scanf("%c%s",&newDate.key,newDate.name); 
              if(insertVertex(graph,newDate)==true)
                printf("\nInserted Successfull\n");
              break;
          case 2: //InsertEdge
              printf("Enter the Key to Key to be inserted in the Graph\n");
              scanf("%c%c",&keyE,&keyE);
              if(insertEdge(graph,keyE,keyE)==true)
                printf("\nInserted Successfull\n");
                else
                printf("\nkey not found to insert an edge\n");
              break;

          case 3: //DeleteVertex
              printf("Enter the key to be deleted from the graph\n");
              scanf("%c",&keyE);
              if(Delete_vertex(graph,keyE)==true)
                  printf("\nDeleted Successfully\n");
              else
				          printf("\n Deleted Unsuccessfull\n");
                break;
          case 4: //DeleteEdge
                printf("Enter The key to key to be deleted from the graph\n");
              scanf("%c%c",&keyE,&keyE);
              if(Del_Edge(graph,keyE,keyE)==true)
                  printf("Deleted Successfull\n");
                  
              else
                  printf("Deleted Unsuccessfull\n");
                  break;

          case 5: //bfs
                    printf("Breadth-first-traversal is : ");
                    BSF_traversal(graph);
                    printf("\n");  
                break;
          case 6: //dfs
                    printf("Depth-first-traversal is : ");
                    DSF_traversal(graph);
                    printf("\n");
                  break;
          case 7: //Exit
		  			printf("EXIT");
                  break;
          default:
              printf("Invalid Choice choose between 1 - 7 \n");
          }
        }
  }
  while(choice!=7);
    destroy(graph);
return 0;
} 