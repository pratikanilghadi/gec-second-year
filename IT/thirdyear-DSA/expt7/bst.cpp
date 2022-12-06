#include<iostream>

using namespace std;

//! Class node: A node of a binary search tree
class node
{
public:
int data;
node *left;
node *right;

node(int d)
{
    data=d;
    left=NULL;
    right=NULL;
}
};

//! Class BST : Binary Tree Class
class BST
{
    node *root;

    public:
    BST()
    {
        root = NULL;
    }
    void insertnode(int d);
    void insertnode(int d, node *temp);
    void printtree(node* root);
    node* returnroot();
};

// TODO: Implement the returnroot() function
node* BST::returnroot()
{
    return root;
}

// TODO: Implement the printtree Function
void BST::printtree(node* root)
{
    if(root==NULL)
        return;
    printtree(root->left);
    cout<<root->data<<" ";
    printtree(root->right);
}

// TODO: Implement the insertnode function
void BST::insertnode(int d)
{
    if(root==NULL)
    {
        root=new node(d);
    }
    else
    {
        insertnode(d,root);
    }
}

// TODO: Implement the insertnode function with a node pointer
void BST::insertnode(int d, node *temp)
{
    if(d<temp->data)
    {
        if(temp->left==NULL)
        {
            temp->left=new node(d);
        }
        else
        {
            insertnode(d,temp->left);
        }
    }
    else
    {
        if(temp->right==NULL)
        {
            temp->right=new node(d);
        }
        else
        {
            insertnode(d,temp->right);
        }
    }
}

//! Main Function: Creates an object of BST and calls member functions
int main()
{
    BST b;
    int a[] = {23,22,44,223,53,2,5,11};
    for( int i = 0; i < (sizeof(a)/sizeof(a[0])); i++ )
    {
        b.insertnode(a[i]);
    }
    b.printtree(b.returnroot());
    return 0;
}