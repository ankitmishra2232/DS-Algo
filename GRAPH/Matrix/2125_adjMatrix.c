/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: .c FILE OF Adj matrix GRAPH
                DATE CREATED: NOV 2021
                DATE MODIFIED: DEC 2021
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"2125_stack.h"
#include"2125_queue.h"
#include"2125_adjMatrix.h"

graphNd* createGraph(int numvertices){
    int i, j;
    graphNd* graph = (graphNd *)malloc(sizeof(graphNd));
    if(graph){
        graph->vertextCount = numvertices;
        graph->vertexVector = (eleType *)malloc(numvertices * sizeof(eleType));
        graph->adjMatrix = (int **)malloc(numvertices* sizeof(int*));
        for(i=0; i<numvertices; i++){
            graph->vertexVector[i] = ' '; //making vector empty
            graph->adjMatrix[i] = (int *)malloc(numvertices * sizeof(int));
            for(j=0; j<numvertices; j++)
                graph->adjMatrix[i][j] = 0; //making edge 0
        }
    }
    return graph;
}

void insertVertex(graphNd *graph, eleType vertexname, int vertexNumber){
    graph->vertexVector[vertexNumber] = vertexname;
}

int insertEdge(graphNd *graph, eleType sourceName, eleType destinationName){
    //return 1: success
    //return -1: source doesnt exist
    //return -2: destination doesnt exist
    int success = -2, count = 0, source, destination;
    while(count < graph->vertextCount){
        if(graph->vertexVector[count] == sourceName){
            success = -1;
            source = count;
            break;
        }
        count++;
    }
    if(success == -1){
        count = 0;
        while(count < graph->vertextCount){
            if(graph->vertexVector[count] == destinationName){
                success = 1;
                destination = count;
                break;
            }
            count++;
        }
        if(success == 1){
            graph->adjMatrix[source][destination] = 1;
            return(1); //Added new edge
        }
        return(-2); //Destination not found
    }
    return(-1); //Source not found
}

void DFS(graphNd *graph){
    stackType s;
    int count = 0, i, j;
    int processed[20];
    char remove;
    for(count = 0; count < graph->vertextCount; count++)
        processed[count] = 0;
    count = 0;
    s = createStack();
    while(count < graph->vertextCount){
        if (processed[count] == 0){
            push(graph->vertexVector[count], &s);
            processed[count] = 1;
        }
        while(isEmptys(s) == false){
            remove = pop(&s);
            printf("\n%c", remove);
            for(i = 0; i < graph->vertextCount; i++)
                if(graph->vertexVector[i] == remove)
                    break;
            processed[i] = 2;
            for(j = 0; j < graph->vertextCount; j++)
                if(graph->adjMatrix[i][j] == 1)
                    if(processed[j] == 0){
                        push(graph->vertexVector[j], &s);
                        processed[j] = 1;
                    }
        }
        count++;
    }
    destroyStack(&s);
}

void BFS(graphNd *graph)
{
    qType q;
    int count = 0, i, j;
    int processed[20];
    char remove;
    for(count = 0; count < graph->vertextCount; count++)
        processed[count] = 0;
    count = 0;
    q = createQueue();
    while(count < graph->vertextCount)
	{
        if(processed[count] == 0)
		{
            enqueue(graph->vertexVector[count], &q);
            processed[count] = 1;
        }
        while(isEmpty(q) == false)
		{
            remove= dequeue(&q);
            printf("\n%c", remove);
            for(i = 0; i < graph->vertextCount; i++)
                if(graph->vertexVector[i] == remove)
                    break;
            processed[i] = 2;
            for(j = 0; j < graph->vertextCount; j++)
                if(graph->adjMatrix[i][j] == 1)
                    if(processed[j] == 0)
					{
                        enqueue(graph->vertexVector[j], &q);
                        processed[j] = 1;
                    }
        }
        count++;
    }
   destroyQueue(&q);
}

int removeEdge(graphNd* graph, eleType sourceName, eleType destinationName)
{
    //return 1: success
    //return -1: source not found in the graph adjacency list
    //return -2: destination not found in the graph adjacency list
    int success = -2, count = 0, source, destination;
    while(count < graph->vertextCount)
	{
        if(graph->vertexVector[count] == sourceName)
		{
            success = -1;
            source = count;
            break;
        }
        count++;
    }
    if(success == -1)
	{
        count = 0;
        while(count < graph->vertextCount)
		{
            if(graph->vertexVector[count] ==  destinationName)
			{
                success = 1;
                destination = count;
                break;
            }
            count++;
        }
        if(success == 1)
		{
            graph->adjMatrix[source][destination] = 0;
            return(1); //Added new edge
        }
        return(-2); //Destination not found
    }
    return(-1); //Source not found
}

void displayGraph(graphNd* graph)
{
	 // Display the graph (adjMatrix)
    int i,j, vertex;
    vertex = graph->vertextCount;
    for(i=0; i< vertex; i++)
	{
        for(j=0; j < vertex; j++) 
			printf("%d ",(graph->adjMatrix)[i][j]);
        printf("\n");
    }
}

void destroyGraph(graphNd *graph)
{
    if(graph)
	{
		if(graph->adjMatrix)
		{
			for(int i=0;i< graph->vertextCount;i++)
				free(graph->adjMatrix[i]);
			free(graph->adjMatrix);
		}
	}
	free(graph);
}