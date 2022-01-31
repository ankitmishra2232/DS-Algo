/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: HEADER FILE OF Adj matrix GRAPH
                DATE CREATED: NOV 2021
                DATE MODIFIED: DEC 2021
 */
#ifndef MATRIX_ADJACENCY
    #define MATRIX_ADJACENCY

    typedef char eleType;
    typedef struct graphNode graphNd;
    struct graphNode{
        int vertextCount; 
        eleType *vertexVector;
        int **adjMatrix;
    };

    /*
        function: Create an empty matrix
        input: int
        pre-condition: none
        output: graphNd* type
        post-condition: empty matrix is created
    */
    graphNd* createGraph(int);

    /*
        function: Enters new vertex in the matrix
        input: graphNd*, eleType
        pre-condition: matrix exists
        output: 1 if vertex added, otherwise -1
        post-condition: New verted added in the matrix
    */
    void insertVertex(graphNd *, eleType , int);

    /*
        function: Inserts an edge between two vertices
        input: graphNd*, EleType, EleType
        pre-condition: matrix exists
        output: 1 if edge inserted success, -1 if memory couldnt be created, -2 if source doesnt exist, -3 if destination doesnt exist
        post-condition: 
    */
    int insertEdge(graphNd *, eleType, eleType );

    /*
        function: Displays names of vertices in matrix using Breadth First Seach method
        input: graphNd*
        pre-condition: matrix exists and is not empty
        output: none
        post-condition: none
    */
    void BFS(graphNd *);

    /*
        function: Displays names of vertices in matrix using Depth First Seach method
        input: graphNd*
        pre-condition: matrix exists and is not empty
        output: none
        post-condition: none
    */
    void DFS(graphNd *);

    /*
        function: Deletes an edge between two vertices from the matrix and free the memory allocated
        input: graphNd*, EleType, EleType
        pre-condition: matrix exists and is not empty
        output: 1 if edge deleted, otherwise -1
        post-condition: Edge is deleted
    */
    int removeEdge(graphNd *,eleType, eleType);
	/*
	function: display's Graph
	input : graphNd*
	pre condition: graph created
	output : matrix
	post condition :none
	*/
	void displayGraph(graphNd* );
    /*
        function: Delete the matrix
        input: graphNd*
        pre-condition: matrix exist
        output: none
        post-condition: All the edges and vertices from the matrix are deleted and free the memory allocated
    */
    void destroyGraph(graphNd *);
#endif