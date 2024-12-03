#include <stdio.h>
#include <malloc.h>

typedef struct binarysearchtree{
    struct binarysearchtree* right;
    struct binarysearchtree* left;
    int data;
}bst;
void init(bst* node){
    node->data=0;
    node->left=NULL;
    node->right=NULL;
}
bst* new(int data){
    bst* node;
    node=(bst*)malloc(sizeof(int));
    node->data=data;
    return node;
}
void insert(bst* node,int data){

    if(node->data>data){
        insert(node->left,data);
    }
}
