#include<iostream>

using namespace std;

template <class TYPE>
class node
{
    public:
    TYPE data;
    node* left;
    node* right;
    
    node(TYPE value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

template <class DATA>
class tree
{
    private:
    node<DATA>* root;

    public:
    tree()
    {
        root = NULL;
        getdata();
        inorder(root);
        cout << endl;
        preorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
    }
    void insertnode(DATA value);
    void insertnode(DATA value,node<DATA>* block);
    void inorder(node<DATA> *block);
    void preorder(node<DATA> *block);
    void postorder(node<DATA> *block);
    void getdata();
};

template<class DATA>
void tree<DATA>:: getdata()
{
    int arr[] = {10,22,33,2,5};
    for(int i = 0; i < 5; i++)
    {
        insertnode(arr[i]);
    }
}

template<class DATA>
void tree<DATA>:: insertnode(DATA value)
{
    if (root == NULL)
    {
        node<DATA> *p = new node<DATA>(value);
        root = p;
        return;
    }

    if (value <= root->data)
    {
        if(root->left == NULL)
        {
            node<DATA> *p = new node<DATA>(value);
            root->left = p;
            return;
        }
        else
        {
            insertnode(value,root->left);
            return;
        }
    }

    else
    {
        if(root->right == NULL)
        {
            node<DATA> *p = new node<DATA>(value);
            root->right = p;
            return;
        }
        else
        {
            insertnode(value,root->right);
            return;
        }
    }
}

template<class DATA>
void tree<DATA>:: insertnode(DATA value,node<DATA> *block)
{
    if (value <= block->data)
    {
        if (block->left == NULL)
        {
            node<DATA> *p = new node<DATA>(value);
            block->left = p;
            return;
        }
        else
        {
            insertnode(value,block->left);
            return;
        }
    }

    else
    {
        if (block->right == NULL)
        {
            node<DATA> *p = new node<DATA>(value);
            block->right = p;
            return;
        }
        else
        {
            insertnode(value,block->right);
            return;
        }
    }
}

//_____________________INORDER TRAVERSAL_____________________________________________
template<class DATA>
void tree<DATA> :: inorder(node<DATA> *block)
{
    if(block == NULL) {return;}
    inorder(block->left);
    cout << block->data << " ";
    inorder(block->right);
}

template <class DATA>
void tree<DATA> :: postorder(node<DATA> *block)
{
    if(block == NULL) {return;}
    postorder(block->left);
    postorder(block->right);
    cout << block->data << " ";
}

template <class DATA>
void tree<DATA> :: preorder(node<DATA> *block)
{
    if(block == NULL) {return;}
    cout << block->data << " ";
    preorder(block->left);
    preorder(block->right);
}

int main()
{
    tree<int> obj;
}