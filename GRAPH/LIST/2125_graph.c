/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: FILE OF GRAPH
                DATE CREATED: SEPT 2021
                DATE MODIFIED: SEPT 2021
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"2125_graph.h"
#include"2125_queue.h"
#include"2125_stack.h"

graphNd *create_graph()
{
    graphNd *newGraph = (graphNd *)malloc(sizeof(graphNd));
    if(newGraph)
    {
        newGraph->vertexCount=0;
        newGraph->firstVertex=NULL;
    }
    return newGraph;
}

int insertVertex(graphNd * graph,eleType data)
{
    vertexNd *newVertex = (vertexNd *)malloc(sizeof(vertexNd));
	
    if(newVertex)
    {
		//newVertex->name=name;
		newVertex -> in_degree=0;
		newVertex -> out_degree=0;
		newVertex->processed =0;
        newVertex->data=data;
		newVertex->firstLink=NULL;
		newVertex->nextVertex=NULL;
        if(graph->firstVertex==NULL)
        {
            graph->firstVertex=newVertex;
        }
        else
        {
            vertexNd *ptr = graph->firstVertex;
            while(ptr->nextVertex!=NULL)
                ptr=ptr->nextVertex;
            ptr->nextVertex=newVertex;
        }
        graph->vertexCount++;
        return 1;
    }
    else
        return -1; 
}

// insertEdge(g1, 'A', 'D'); A-->D
int insertEdge(graphNd * graph, keyType fromVertexKey,keyType tovertexKey)
{
	//1. Locate fromVertexKey in vertexList
	vertexNd * fromVertex = _locate(graph,fromVertexKey);
    if(!fromVertex)
		return -2;
	//2. Locate tovertexKey in vertexList
	vertexNd * toVertex = _locate(graph,tovertexKey);
    if(!toVertex)
        return -3;
	//3. found fromVertexKey and toVertexKey, hence creating mem for new edge
	linkNd *newEdge =(linkNd *)malloc(sizeof(linkNd));
	if(newEdge)
	{
		newEdge->destination = toVertex;
		newEdge->nextLink=NULL;
		if(fromVertex->firstLink==NULL)
		{
			fromVertex->firstLink =newEdge;
		}
		else 
		{
			linkNd * ptr = fromVertex->firstLink; 
			while(ptr->nextLink !=NULL)
			{
				ptr= ptr->nextLink;
			}
			ptr->nextLink = newEdge;
		}
		graph->edgeCount++;
		fromVertex->out_degree++;
		toVertex->in_degree++;
		return 1;
	}
	return -1;
}


//ret NULL if key not found
//else it will ret the ptr to the vertex having key = srchkey
vertexNd* _locate(graphNd *graph,keyType srchkey)
{
    vertexNd * ptr = graph->firstVertex;  
	while(ptr)
	{
		if(ptr->data.key==srchkey)
		{
			return ptr;
		}
		ptr = ptr->nextVertex;
	}
	return NULL;	
}

int Delete_vertex(graphNd *graph, keyType delkey)
{
	int found =0;
	vertexNd *ptr = graph->firstVertex;
	vertexNd *prev=NULL;
	while(ptr!=NULL)
	{
		if(ptr->data.key==delkey)
		{
			found=1;
			break;
		}
		prev = ptr;
		ptr = ptr->nextVertex;
	}
	if(found==0)
	{
		return -2;
	}
	if(found==1 && ptr->in_degree==0 && ptr->out_degree==0)
	{
		if(ptr==graph->firstVertex)
			graph->firstVertex=ptr->nextVertex;
		else
			prev->nextVertex=ptr->nextVertex;
      graph->vertexCount--;
      free(ptr);
      return 1;
	}
	else
		return -1;
	
}

int Del_Edge(graphNd *graph,keyType fromKey,keyType toKey)
{
	vertexNd * fromVertex = _locate(graph,fromKey);
    if(!fromVertex)
		return -2; //not found from vertex
	//2. Locate toKey in vertexList
	vertexNd * toVertex = _locate(graph,toKey);
    if(!toVertex)
        return -3;
	//2. Locate toKey in Adjlist
	//checking if they are making Edge.
	linkNd *toptr = fromVertex->firstLink;
	linkNd *toPrev = NULL;
	while (toptr)
	{
		if(toptr->destination->data.key==toKey)
			break;
		toPrev=toptr;
		toptr=toptr->nextLink;
	}
	//if There is no edge between from and tokey
	if(toptr->destination->data.key!=toKey)
		return -1;  
	//if they make edge
	fromVertex->out_degree--;
	toVertex->in_degree--;
	//if to be deleted item found at first link
	if(toptr==fromVertex->firstLink) 
	{
		fromVertex->firstLink=toptr->nextLink;
	}
	else
		toPrev->nextLink=toptr->nextLink;
	free(toptr);
	return 1;
}

void BSF_traversal(graphNd *graph)
{
	if(graph==NULL)
		return;
	qType q =createQueue();
	eleType_q vertexA;
	vertexNd *ptr =graph->firstVertex;
	linkNd *link=ptr->firstLink;
	while(ptr)
	{

		if(ptr->processed==0)
		{
			enqueue(ptr->data.key,&q);
			ptr->processed=1;
		}
		else
		{
			if(!isEmpty(q)&&ptr->processed==1)
			{
				vertexA = dequeue(&q);
				printf("%c\n",vertexA);
        		ptr->processed=2;
			}
			else if(ptr->processed==2)
			{
				while(link)
				{
					if(link->destination->processed==0)
					{
						enqueue(link->destination->data.key,&q);
            			link->destination->processed=1;
					}
					link=link->nextLink;
				}
			}
				
		ptr=ptr->nextVertex;
		}
	}
	destroyQueue(&q);	
}


void DSF_traversal(graphNd *graph)
{
	if(graph==NULL)
		return;
	stackType s =createStack();
	eleType_s vertexA;
	vertexNd *ptr =graph->firstVertex;
	linkNd *link=ptr->firstLink;
	while(ptr)
	{

		if(ptr->processed==0)
		{
			push(ptr->data.key,&s);
			ptr->processed=1;
		}
		else
		{
			if(!isEmptys(s)&&ptr->processed==1)
			{
				vertexA = pop(&s);
				printf("%c\n",vertexA);
        		ptr->processed=2;
			}
			else if(ptr->processed==2)
			{
				while(link)
				{
					if(link->destination->processed==0)
					{
						push(link->destination->data.key,&s);
            			link->destination->processed=1;
					}
					link=link->nextLink;
				}
			}
				
		ptr=ptr->nextVertex;
		}
	}
	destroyStack(&s);	
}

void destroy(graphNd *graph)
{
	while(graph->firstVertex!=NULL)
	{
		graph->vertexCount--;
    	graph->edgeCount--;
		vertexNd *temp = graph->firstVertex;
    	graph->firstVertex =graph->firstVertex->nextVertex;
		free(temp);
	}
}





