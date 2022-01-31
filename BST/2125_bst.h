/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: BINARY SEARCH TREE HEADER FILE
                DATE CREATED: OCT 2021
                DATE MODIFIED: OCT 2021
 */
#ifndef _BST_H
    #define _BST_H
    typedef int keyType;
    struct Data
    {
      keyType key;
      char name[20];
      //char add[20];
    };
    typedef struct Data eleType;
    struct bst_node 
    {
      eleType data;
      struct bst_node *left, *right;
    };
    typedef struct bst_node node;
    struct BStree
    {
      struct bst_node *root;
      int count;
    };
    typedef struct BStree treeType;
    
    //protoTypes
  /*Function : Allocates memory for BST
    input: none
    Precondition: none
    output:empty tree has created head node pointer or null if memory overflow
    postcondition: head allocatede or memory overflow */
    treeType *BST_createTree();
  /*Function : inserts new data into the tree
    input: *treeType element type
    precondition: tree is pointer to BST structure
    output: success(true) overflow(flase)
    postcondition: data is inserted or memory overflow */
    bool BST_insert(treeType *,eleType);
  /*Fuunction: It for insert new data into a leaf node 
    input: data pointer and root
    precondition: Application has called BST_insert which passes the root
    output: new leaf node is added at left or right of the root node
    postcondition: Data is inserted
    */
    node * _insert(node *root,node *new_ptr);
    /*Function : display tree using any pre post or inorder traversel
    input: treetype
    Precondition: tree has been created
    output: Display tree
    postcondition:none*/
    void BST_intraverse(treeType*);
    /*Function : visit tree's node and print data for each node
    input: *node
    precondition : tree has been created
    output: print each node data
    Postcondition: All nodes visited*/
    void _intraverse(node*);
    void BST_posttraverse(treeType*);
    void _posttraverse(node*root);
    void BST_pretraverse(treeType*);
    void _pretraverse(node*root);
    /*Function: It deletes node from the tree
      precondition: tress has been created
      input:treeType ,key to be deleted
      postcondition: node is deleted & memory cleared if key found
      output: true if success false of not successs
      */
    bool BST_del(treeType*,keyType);
    /*Function: searches for node with key and del it if found
    precondition: tree has been created
    input: node,key and success
    post: if key found del and memory recycled else tree is unchanged
    output: pointer of the root of the subtree which is deleted ,Null if not found*/
    node *_delete(node*,keyType,bool *);
    /*Function: Deletes tree and free memory
    input: *treeType
    precondition : tree has been created
    output:none
    post: deletes all elements and free memory
    */
    void destroybst(treeType*);
    /*Function: Search Element if there is any
    input: *treeType and key
    precondition : tree has been created
    output: searched and printed the data
    post : none */
    node *searchtree(treeType*,keyType);
    /*Function: checking the tree is empty or not empty
    input : treetype
    Precondition: none
    output: true if bst is empty and false if bst is not empty
    Postcondition: none
    */
    bool isEmpty(treeType*);
    //eleType _print(treeType *);

#endif