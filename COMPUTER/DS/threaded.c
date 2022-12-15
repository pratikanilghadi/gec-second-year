#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>

typedef enum 
{false,true}boolean;
typedef struct node
{
    struct node *left;
    boolean lthread;
    int info;
    boolean rthread;
    struct node *right;
}node;
int array[50];
node *insert(node *root, int ikey);
node *del(node *root,int dkey);
node *case_a(node *root,node *par,node *p);
node *case_b(node *root,node *par,node *p);
node *in_succ(node *p);
node *in_pred(node *p);
node *case_c(node *root,node *par,node *p);
node *search(node *root,int skey);
void inorder(node *root);

int main()
{
    int op, nodes,data,i;
    node *root=NULL,*s=NULL;
    printf("Enter total number of nodes: ");
    scanf("%d", &nodes);

    for (int i = 0; i < nodes; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < nodes; i++)
    {
        root = insert(root, array[i]);
    }
    printf("Inorder Travsersal: ");
    inorder(root);

    while(1)
    {
        printf("\n-----------------------------\n");
        printf("1-Insert an element\n");
        printf("2-Deletion of an existing element\n");
        printf("3-Search an element\n");
        printf("4-Inorder Traversal\n");
        printf("5-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:printf("Enter the element: ");
                   scanf("%d",&data);
                   root=insert(root,data);
                   printf("Inorder Traversal after Inserting %d: ",data);
                   inorder(root);
                   break;

           case 2:printf("Enter the element: ");
                  scanf("%d",&data);
                  root=del(root,data);
                  printf("Inorder Traversal after Deleting %d: ",data);
                  inorder(root);
                  break;

            case 3:printf("Enter the element: ");
                   scanf("%d",&data);
                   s=search(root,data);
                   if(s!=NULL)
                   {
                    printf("Element found!!\n");
                   }
                   break;
            
            case 4:printf("Inorder Traversal: ");
                   inorder(root);
                   break;

            case 5:exit(1);
            

            default:printf("Invalid choice\n");
        }//end of switch
    }//end of while loop
} // end of main

//! Insert Function --------------------------------------------------------------------------------
node *insert(node *root, int ikey)
{
    node *temp, *par, *p;
    int found = 0;
    p = root;
    par = NULL;
    while (p != NULL)
    {
        if (ikey == p->info)
        {
            found = 1;
            break;
        }
        par = p;
        if (ikey < p->info)
        {
            if (p->lthread == false)
            {
                p = p->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (p->rthread == false)
            {
                p = p->right;
            }
            else
            {
                break;
            }
        }
    }
    if (found)
    {
        printf("Duplicate key\n");
    }
    else
    {
        temp=(node *)malloc(sizeof(node));
        temp->info = ikey;
        temp->lthread = true;
        temp->rthread = true;
        if(par == NULL)
        {
            root=temp;
            temp->left=NULL;
            temp->right=NULL;
        }
        else if(ikey < par->info)
        {
            temp->left=par->left;
            temp->right=par;
            par->lthread=false;
            par->left=temp;
        }
        else
        {
            temp->left=par;
            temp->right=par->right;
            par->rthread=false;
            par->right=temp;
        }
    }
    return root;
}

node *del(node *root,int dkey)
{
    node *par,*p;
    int found=0;
    p=root;
    par=NULL;
    while(p!=NULL)
    {
        if(dkey==p->info)
        {
            found=1;
            break;
        }
        par=p;
        if(dkey<p->info)
        {
            if(p->lthread==false)
            {
                p=p->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(p->rthread==false)
            {
                p=p->right;
            }
            else
            {
                break;
            }
        }
    }
    if(found==0)
    {
        printf("Element not found\n");
    }
    else if(p->lthread==false && p->rthread==false)
    {
        root=case_c(root,par,p);
    }
    else if(p->lthread==false)
    {
        root=case_b(root,par,p);
    }
    else if(p->rthread==false)
    {
        root=case_b(root,par,p);
    }
    else
    {
        root=case_a(root,par,p);
    }
    return root;
}

node *case_a(node *root,node *par,node *p)
{
    if(par==NULL)
    {
        root=NULL;
    }
    else if(p==par->left)
    {
        par->lthread=true;
        par->left=p->left;
    }
    else
    {
        par->rthread=true;
        par->right=p->right;
    }
    free(p);
    return root;
}

node *case_b(node *root,node *par,node *p)
{
    node *child,*s,*pr;
    if(p->lthread==false)
    {
        child=p->left;
    }
    else
    {
        child=p->right;
    }
    if(par==NULL)
    {
        root=child;
    }
    else if(p==par->left)
    {
        par->left=child;
    }
    else
    {
        par->right=child;
    }
    s=in_succ(p);
    pr=in_pred(p);
    if(p->lthread==false)
    {
        p->right=s;
    }
    else
    {
        if(p->rthread==false)
        {
            s->left=pr;
        }
    }
    free(p);
    return root;
}

node *in_succ(node *p)
{
    if(p->rthread==true)
    {
        return p->right;
    }
    else
    {
        p=p->right;
        while(p->lthread==false)
        {
            p=p->left;
        }
        return p;
    }
}

node *in_pred(node *p)
{
    if(p->lthread==true)
    {
        return p->left;
    }
    else
    {
        p=p->left;
        while(p->rthread==false)
        {
            p=p->right;
        }
        return p;

    }
}

node *case_c(node *root,node *par,node *p)
{
    node *succ,*parsucc;
    parsucc=p;
    succ=p->right;
    while(succ->left!=NULL)
    {
        parsucc=succ;
        succ=succ->left;
    }
    p->info=succ->info;
    if(succ->lthread==true && succ->rthread==true)
    {
        root=case_a(root,parsucc,succ);
    }
    else
    {
        root=case_b(root,parsucc,succ);
    }
    return root;
}

node *search(node *root,int skey)
{
    node *p=root;
    if(p==NULL)
    {
        printf("Element not found\n");
        return NULL;
    }
    else if(skey < p->info)
    {
        return search (p->left,skey);
    }
    else if(skey > p->info)
    {
        return search(p->right,skey);
    }
    else
    {
        return p;
    }
}

void inorder(node *root)
{
    node *p;
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    p=root;
    while(p->lthread==false)
    {
        p=p->left;
    }
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=in_succ(p);
    }
}