#include<iostream>

using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class bst
{
    private:
    node *root;

    public:
    bst()
    {
        root = NULL;
    }
    void insertnode(int value);
    void search(int value);
    void add(int value,node *block);
};

void bst:: insertnode(int value)
{
    if (root == NULL)
    {
        node *p = new node(value);
        root = p;
    }

    else
    {
        add(value,root);
    }
}

void bst:: add(int value,node *block)
{
    if(value <= block->data)
    {
        if(block->left == NULL)
        {
            node *p = new node(value);
            block->left = p;
        }

        else
        add(value,block->left);
    }

    else
    {
        if(block->right == NULL)
        {
            node *p = new node(value);
            block->right = p;
        }
        else
        add(value,block->right);

    }
}

void bst:: search(int value)
{
    if (root == NULL)
    {
        cout << "Not found in the List" << endl;
        return;
    }

    node *temp = root;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            cout << "The element is present" << endl;
            break;
        }

        else if(temp->data > value)
        {
            temp = temp->left;
        }

        else if(temp->data < value)
        {
            temp = temp->right;
        }
    }

    if(temp == NULL)
    {
        cout << "The element is absent" << endl;
    }
}

int main()
{
    bst obj;
    int arr[] = {33,64,6,3,7,22,6};
    for(int i = 0;i < 7; i++)
    {
        obj.insertnode(arr[i]);
    }
    obj.search(55);
}