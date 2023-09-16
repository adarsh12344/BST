#include <bits/stdc++.h> 

using namespace std;
  

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


bool bst(BinaryTreeNode<int> *root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>=min && root->data<=max)
    {
        bool left = bst(root->left,min,root->data);
        bool right = bst(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    
    bst(root,INT_MIN,INT_MAX);

}