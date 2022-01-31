/*
                AUTHOR : 2125_ANKIT
                Roll no : 2125
                PROGRAM: BINARY SEARCH TREE FILE
                DATE CREATED: OCT 2021
                DATE MODIFIED: OCT 2021
 */
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"2125_bst.h"
treeType * BST_createTree()
{
  treeType *new_tree=(treeType *)malloc(1*sizeof(treeType));
  if(new_tree)
  {
    new_tree->root=NULL;
    new_tree->count=0;
  }
  return new_tree; 
  
}
bool BST_insert(treeType *tree,eleType data)
{
  node *new_ptr;
  new_ptr= (node *)malloc(sizeof(node));
  if(!new_ptr)  //memory overflow
    return false;
  else
  new_ptr->right=new_ptr->left=NULL;
  new_ptr->data=data;
  if(tree->root==NULL) //if(tree->count==0) we can use any of them for checking about empty tree
    tree->root=new_ptr;
  else
    _insert(tree->root,new_ptr);
  (tree->count)++;
  return true;  //successfull insertion    
}
node * _insert(node *root,node *new_ptr)
{
  if(!root) //null subtree
    return new_ptr;
    //locate null subtree for insertion
  if (new_ptr->data.key < root->data.key)
  {
    root->left=_insert(root->left,new_ptr);
  }
  else
    root->right=_insert(root->right,new_ptr);
  return root;
}
void BST_intraverse(treeType*tree)
{
  _intraverse(tree->root);
}
void _intraverse(node*root)
{
  if (root)
  {
    _intraverse(root->left);//inorder
    //_print(root->data.key);
    printf("%d%s",root->data.key,root->data.name);
    _intraverse(root->right);
  }
}
void BST_posttraverse(treeType*tree)
{
  _posttraverse(tree->root);
}
void _posttraverse(node*root)
{
  if (root)
  {
    _posttraverse(root->left);
    _posttraverse(root->right);
    printf("%d%s",root->data.key,root->data.name);
    //_print(root->data.key);    //postorder
  }
}
void BST_pretraverse(treeType*tree)
{
  _pretraverse(tree->root);
}
void _pretraverse(node*root)
{
  if (root)
  {
    //_print(root->data.key);
    printf("%d%s",root->data.key,root->data.name);
    _pretraverse(root->left);  //preorder
    _pretraverse(root->right);
   
  }
}

bool BST_del(treeType* tree,keyType delkey)
{
  bool success;
  node *newRoot;
  newRoot=_delete(tree->root,delkey,&success);
  if(success)
  {
    tree->root=newRoot;
    tree->count--;
  }
  return success;
}
node * _delete(node*root,keyType delkey,bool *success)
{
  if(root==NULL)
  {
    *success=false;
    return NULL;
  }
  if(delkey < root->data.key)
  {
    root->left=_delete(root->left,delkey,success);
  }
  else if (delkey > root->data.key)
  {
    root->right=_delete(root->right,delkey,success);
  }
  else
  {
    if(root->left && root->right) // 2 children
    {
      //finding inorder predecessor for node to be deleted
      node *inorder_pre=root->left;
      while (inorder_pre->right)
      {
        inorder_pre=inorder_pre->right;
      }
      //copy data of inorder into node to deleted
      root->data=inorder_pre->data;
      //delete inorder pre
      root->left=_delete(root->left,inorder_pre->data.key,success);      
    }
    else //0 or 1 child
    {
      node* temp=root;
      if(root->left==NULL)
      {
        root=root->right;
      }
      else if(root->right==NULL)
      {
        root=root->left;
      }
      free(temp);
      *success=true;
    }

  }
  return root;
}
void destroybst(treeType*tree)
{
  while (tree->root!=NULL)
  {
    tree->count--;
    node *temp=tree->root;
    if(tree->root->left)
      tree->root=tree->root->left;
    else
      tree->root=tree->root->right;
    free(temp);
  }  
}

bool isEmpty(treeType *tree) //it checks if the queue is empty or not
{
    if(tree->count==0)
    {
        return true;
    }
    return false;
}
node *search(node *root,keyType key)
{
  if (root==NULL)
  {
    return NULL;
  }
  else if(key < root->data.key)
  {
    return search(root->left,key);
  }
  else if(key > root->data.key)
  {
    return search(root->right,key);
  }
  else
    return root;
}