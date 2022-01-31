/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: Main FILE OF Adj matrix GRAPH
                DATE CREATED: NOV 2021
                DATE MODIFIED: DEC 2021
 */
#include<stdio.h>
#include"2125_adjMatrix.h"

int main(){
    printf("<<<<<Adjacent Matrix>>>>>");
    int choice, vertexNum, check, i;
    char vName, sourceName, destinationName,ch;
    printf("\nEnter the Number of Vertices\n");
	  if(scanf("%d%c",&vertexNum,&ch) !=2 || ch !='\n' || vertexNum<0)  //Input Validation
    { 
      while(getchar()!='\n')
          printf("Invlaid input please enter any Interger Value");
          printf("\n");
          return 0;
    }
    else{
        printf("\nValid Input\n");
        graphNd *matrix= createGraph(vertexNum);
		if(matrix)
            printf("\nNew matrix adjacency matrix to be inserted.");
        else
		{
            printf("\nMatrix could not be created.Memory overflow.");
        }
        for(i=0; i<vertexNum; i++)
		{                    
			printf("\nEnter name of vertex: ");
            scanf(" %c", &vName);
            insertVertex(matrix, vName, i);
            printf("\nNew vertex added in the matrix.");
        }
        do{
          printf("\n1.insertEdge\n2.removeEdge\n3.BFS\n4.DFS\n5.displayGraph\n6.Exit\n");
          if(scanf("%d%c",&choice,&ch) !=2 || ch!='\n' || choice <0)
          { 
          while(getchar()!='\n')
            printf("Invlaid input please enter any Interger");
            printf("\n");
            continue;
          }
          else{
            switch(choice){
              case 1:
                printf("\nEnter name of source vertex: ");
                scanf(" %c", &sourceName);
                printf("\nEnter name of destination vertex: ");
                scanf(" %c", &destinationName);
                check = insertEdge(matrix, sourceName, destinationName);
                if(check == 1)
                    printf("\nNew edge added in the matrix.");
                else if(check == -1)
                    printf("\nSource vertex could not be found. Enter valid input. Try again.");
                else if(check == -2)
                    printf("\nDestination vertex could not be found. Enter valid input. Try again.");
                break;
              case 2:
                if(matrix->vertextCount == 0)
                    printf("\nMatrix have no vertices.");
                else{
                    printf("\nEnter name of source vertex:\n ");
                    scanf(" %c", &sourceName);
                    printf("\nEnter name of destination vertex: ");
                    scanf(" %c", &destinationName);
                    check = removeEdge(matrix, sourceName, destinationName);
                    if(check == 1)
                        printf("\nEdge deleted Succesfully from the adjacency list.");
                    else
                        printf("\nEdge not be found in the matrix adjacency list.");
                }
                break;
              case 3:
                  //BFS
                if(matrix->vertextCount == 0)
                    printf("\nMatrix have no vertices.");
                else
                    BFS(matrix);
                break;
              case 4:
                //DFS
              if(matrix->vertextCount == 0)
                  printf("\nMatrix have no vertices.");
              else
                  DFS(matrix);
              break;
              case 5:
                  displayGraph(matrix);
                  break;
              case 6:
                printf("Exit");
                break;
              default:
                printf("Invalid choice choose between 1-6");
            }
          }
       }
        while(choice!=6);
        destroyGraph(matrix);
    }
    return 0;
  }

