/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: HEADER FILE OF GRAPH
                DATE CREATED: NOV 2021
                DATE MODIFIED: NOV 2021
 */
#include<stdlib.h>
#ifndef _GRAPH_H
    #define _GRAPH_H
    struct linkNode
    {
        //float weight;
        struct vertexNode *destination;
        struct linkNode *nextLink;
    };
    typedef struct linkNode linkNd;
    typedef char keyType;
    struct Data
    {
        keyType key;//
        char name[20];
    };
    typedef struct Data eleType;
    struct vertexNode
    {
       // vertex *v;
        eleType data;
        //float weight;
        //int visited;
        short in_degree, out_degree; // in case of undirected graph, we need only out degree
        short processed;//to be used in case of BFS and DFS
        struct vertexNode *nextVertex;
        //struct vertexNode *prevVertex;
        struct linkNode *firstLink;
    };
    typedef struct vertexNode vertexNd;
    struct graphNode
    {
        struct vertexNode *firstVertex;
        int vertexCount;
        int edgeCount;
    };    
    typedef struct graphNode graphNd; // head for the graph

    //ProtoTyes
    /*Function : Allocates memory for Graph
    input: none
    Precondition: none
    output:empty Graph has created head node pointer or null if memory overflow
    postcondition: head allocatede or memory overflow */
    graphNd *create_graph();
    /*Function : creates a empty vertex in graph
    input: * graph & elementType 
    Precondition: graph exists
    output:GraphNd
    postcondition: an empty vertex graph is created */
    int insertVertex(graphNd *,eleType);
     /*Function : creates a empty edge in graph
    input:  *graph , from key and to key
    Precondition: vertex exists
    output:GraphNd
    postcondition: an empty edge graph is created */
    int insertEdge(graphNd * , keyType,keyType );
     /*Function : loacte key if it exits
    input: *graph , keyType
    Precondition: Key exists
    output: GraphNd
    postcondition: gaph key located */
    vertexNd* _locate(graphNd *,keyType key);
        /*Function : Delete vertex if it exists
    input: *graph , keyType
    Precondition: keys exists
    output: GraphNd
    postcondition: vertex inserted successfully  */
    int Delete_vertex(graphNd*, keyType);
         /*Function : Delete edge if it exists
    input: *graph , fromKey and toKey
    Precondition: edges exists
    output: GraphNd
    postcondition: edge inserted successfully  */
    int Del_Edge(graphNd*,keyType fromKey,keyType toKey);
      /*Function : visit graphs GraphNd and print data for each GraphNd
    input: *GraphNd
    precondition : Graph has been created
    output: print each GraphNd data
    Postcondition: All GraphNd visited*/
    void BSF_traversal(graphNd *);
        /*Function : visit graphs GraphNd and print data for each GraphNd
    input: *GraphNd
    precondition : Graph has been created
    output: print each GraphNd data
    Postcondition: All GraphNd visited*/
	void DSF_traversal(graphNd *);
      //Function: displays the elements of the graph
    //Precondition: graph is not empty
    //Input: graphNd
    //output: displays the elements of the graphNd
    //Postcondition: none
	void destroy(graphNd *graph);
#endif 