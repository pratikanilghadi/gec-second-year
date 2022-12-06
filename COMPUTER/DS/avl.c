#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node
{
 struct node *left;
 int info;
 struct node *right;
 int balance;
}node;

node *insert(node *pptr,int ikey);
node *insert_left_check(node *pptr,int *ptaller);
node *insert_left_Balance(node *pptr);
node *rotate_right(node *pptr);
node *rotate_left(node *pptr);
node *insert_right_check(node *pptr,int *ptaller);
node *insert_right_Balance(node *pptr);
void inorder(node *p);
node *del(node *pptr,int d);
node *del_left_check(node *pptr,int *pshorter);
node *del_Right_Balance(node *pptr,int *pshorter);
node *delete_right_check(node *pptr,int *pshorter);
node *del_Left_Balance(node *pptr,int *pshorter);
node *search(node *p,int s);
int MAXwidth(node *p);
int height(node *p);
int widthlevel(node *p,int level);
int min(node *p);
int max(node *p);
void newinorder(node *p);
int array[100];

int main()
{
 int n=0,op=0,a=0;
 node *root=NULL,*s=NULL;
 printf("Enter the number of nodes in the tree: ");
 scanf("%d",&n);

 for(int i=0;i<n;i++)
 {
  printf("Enter the element %d: ",i+1);
  scanf("%d",&array[i]);
 }

 for(int i=0;i<n;i++)
 {
       root=insert(root,array[i]);
 }

 while(1)
 {
       printf("\n-------------------\n");
       printf("1-insert an element\n");
       printf("2-Delete an element\n");
       printf("3-To search a element\n");
       printf("4-Find the width of the tree\n");
       printf("5-Finding the max value and min value nodes\n");
       printf("6-Display elements in decending order\n");
       printf("7-Exit\n");
       printf("Enter Your choice: ");
       scanf("%d",&op);

       switch(op)
       {
              case 1:printf("Enter the element to be inserted: ");
                     scanf("%d",&a);
                     root=insert(root,a);
                     printf("Inorder traversal of the tree after insertion is: ");
                     inorder(root);
                     printf("\n");
                     break;

              case 2:printf("Enter the element to be deleted: ");
                     scanf("%d",&a);
                     root=del(root,a);
                     printf("Inorder traversal of the tree after deletion is: ");
                     inorder(root);
                     printf("\n");
                     break;

              case 3:printf("Enter the element to be searched: ");
                     scanf("%d",&a);
                     s=search(root,a);
                     if(s!=NULL)
                     { printf("Element found !!\n");}
                     break;

              case 4:printf("Width of the tree is: %d",MAXwidth(root));
                     break;

              case 5:printf("Max value node is: %d\n",max(root));
                     printf("Min value node is: %d\n",min(root));
                     break;

              case 6:printf("Inorder traversal of the tree is: ");
                     newinorder(root);
                     break;

              case 7:exit(1);
                     break;

              default:printf("Invalid choice\n");
       }//end of switch
 }//end of while loop
}//end of main

node *insert(node *pptr,int ikey)
{
 static int taller;
 if(pptr==NULL)
 {
  pptr=(node *)malloc(sizeof(node));
  pptr->info=ikey;
  pptr->left=NULL;
  pptr->right=NULL;
  pptr->balance=0;
  taller=TRUE;
 }
 else if(ikey<pptr->info)
 {
  pptr->left=insert(pptr->left,ikey);
  if(taller==TRUE)
  { pptr=insert_left_check(pptr,&taller);}
 }
  else if(ikey>pptr->info)
  {
   pptr->right=insert(pptr->right,ikey);
   if(taller==TRUE)
   { pptr=insert_right_check(pptr,&taller);}
  }
  else
  {
   printf("Duplicate key\n");
   taller=FALSE;
  }
  return pptr;
 }

node *insert_left_check(node *pptr,int *ptaller)
{
 switch(pptr->balance)
 {
  case 0:pptr->balance=1;
         break;

  case -1:pptr->balance=0;
          *ptaller=FALSE;
          break;
       
  case 1:pptr=insert_left_Balance(pptr);
         *ptaller=FALSE;
 }
 return pptr;
}

node *insert_left_Balance(node *pptr)
{
 node *aptr,*bptr;
 aptr=pptr->left;
 if(aptr->balance==1)
 {
  pptr->balance=0;
  aptr->balance=0;
  pptr=rotate_right(pptr); 
 }
 else
 {
  bptr=aptr->right;
  switch(bptr->balance)
  {
   case 1:pptr->balance=-1;
          aptr->balance=0;
          break;
   case 0:pptr->balance=0;
          aptr->balance=0;
          break;
   case -1:pptr->balance=0;
           aptr->balance=1;
           break;
  }
  bptr->balance=0;
  pptr->left=rotate_left(aptr);
  pptr=rotate_right(pptr);
 }
 return pptr;
}

node *rotate_right(node *pptr)
{
       node *aptr;
       aptr=pptr->left;
       pptr->left=aptr->right;
       aptr->right=pptr;
       return aptr;
}

node *rotate_left(node *pptr)
{
       node *aptr;
       aptr=pptr->right;
       pptr->right=aptr->left;
       aptr->left=pptr;
       return aptr;
}

node *insert_right_check(node *pptr,int *ptaller)
{
 switch(pptr->balance)
 {
  case 0:pptr->balance=-1;
         break;

  case 1:pptr->balance=0;
          *ptaller=FALSE;
          break;
       
  case -1:pptr=insert_right_Balance(pptr);
         *ptaller=FALSE;
 }
 return pptr;
}

node *insert_right_Balance(node *pptr)
{
 node *aptr,*bptr;
 aptr=pptr->right;
 if(aptr->balance==-1)
 {
  pptr->balance=0;
  aptr->balance=0;
  pptr=rotate_left(pptr); 
 }
 else
 {
  bptr=aptr->left;
  switch(bptr->balance)
  {
   case 1:pptr->balance=0;
          aptr->balance=-1;
          break;
   case 0:pptr->balance=0;
          aptr->balance=0;
          break;
   case -1:pptr->balance=1;
           aptr->balance=0;
           break;
  }
  bptr->balance=0;
  pptr->right=rotate_right(aptr);
  pptr=rotate_left(pptr);
 }
 return pptr;
}

void inorder(node *p)
{
       if(p==NULL)
       { return;}

       inorder(p->left);
       printf("%d ",p->info);
       inorder(p->right);
}

node *del(node *pptr,int d)
{
       node *temp,*succ;
       static int shorter;

       if(pptr==NULL)
       {
              printf("Element not found");
              shorter=FALSE;
              return (pptr);
       }
       if(d<pptr->info)
       {
              pptr->left=del(pptr->left,d);
              if(shorter==TRUE)
              {  pptr=del_left_check(pptr,&shorter);}
       }
       else if(d>pptr->info)
       {
              pptr->right=del(pptr->right,d);
              if(shorter==TRUE)
              { pptr=delete_right_check(pptr,&shorter); }
       }
       else
       {
              if(pptr->left!=NULL && pptr->right!=NULL)
              {
                     succ=pptr->right;
                     while(succ->left!=NULL)
                     {  succ=succ->left; }
                     pptr->info=succ->info;
                     pptr->right=del(pptr->right,succ->info);
                     if(shorter==TRUE)
                     { pptr=delete_right_check(pptr,&shorter);}
              }
              else
              {
                     temp=pptr;
                     if(pptr->left!=NULL)
                     {  pptr=pptr->left; }
                     else if(pptr->right!=NULL)
                     { pptr=pptr->right; }
                     else
                     { pptr=NULL; }
                     free(temp);
                     shorter=TRUE;
              }
       }
       return pptr;
}

node *del_left_check(node *pptr,int *pshorter)
{
       switch(pptr->balance)
       {
              case 0:pptr->balance=-1;
                     *pshorter=FALSE;
                     break;

              case 1:pptr->balance=0;
                     break;

              case -1:pptr=del_Right_Balance(pptr,pshorter);        
       }
       return pptr;
}

node *del_Right_Balance(node *pptr,int *pshorter)
{
       node *aptr,*bptr;
       aptr=pptr->right;
       if(aptr->balance==0)
       {
              pptr->balance=-1;
              aptr->balance=1;
              *pshorter=FALSE;
              pptr=rotate_left(pptr);
       }
       else if(aptr->balance==-1)
       {
              pptr->balance=0;
              aptr->balance=0;
              pptr=rotate_left(pptr);
       }
       else
       {
              bptr=aptr->left;
              switch(bptr->balance)
              {
                     case 0:pptr->balance=0;
                            aptr->balance=0;
                            break;

                     case 1:pptr->balance=0;
                            aptr->balance=-1;
                            break;
                    
                     case -1:pptr->balance=1;
                            aptr->balance=0;
                            break; 
              }
              bptr->balance=0;
              pptr->right=rotate_right(aptr);
              pptr=rotate_left(pptr);
       }
       return pptr;
}

node *delete_right_check(node *pptr,int *pshorter)
{
       switch(pptr->balance)
       {
              case 0:pptr->balance=1;
                     *pshorter=FALSE;
                     break;

              case -1:pptr->balance=0;
                     break;

              case 1:pptr=del_Left_Balance(pptr,pshorter);        
       }
       return pptr;
}

node *del_Left_Balance(node *pptr,int *pshorter)
{
       node *aptr,*bptr;
       aptr=pptr->left;
       if(aptr->balance==0)
       {
              pptr->balance=1;
              aptr->balance=-1;
              *pshorter=FALSE;
              pptr=rotate_right(pptr);
       }
       else if(aptr->balance==1)
       {
              pptr->balance=0;
              aptr->balance=0;
              pptr=rotate_right(pptr);
       }
       else
       {
              bptr=aptr->right;
              switch(bptr->balance)
              {
                     case 0:pptr->balance=0;
                            aptr->balance=0;
                            break;

                     case 1:pptr->balance=-1;
                            aptr->balance=0;
                            break;
                    
                     case -1:pptr->balance=0;
                            aptr->balance=1;
                            break; 
              }
              bptr->balance=0;
              pptr->left=rotate_left(aptr);
              pptr=rotate_right(pptr);
       }
       return pptr;
}

node *search(node *p,int s)
{
       if(p==NULL)
       {
              printf("Element not found!!\n");
              return NULL;
       }
       else if(s<p->info)
       { return search(p->left,s);}
       else if(s>p->info)
       { return search(p->right,s); }
       else
       { return p; }
}

int MAXwidth(node *p)
{
       int maxwidth=0,width,h=0;
       h=height(p);

       for(int i=1;i<=h;i++)
       {
              width=widthlevel(p,i);
              if(width>maxwidth)
              {  maxwidth=width; }
       }
       return maxwidth;
}

int height(node *p)
{
       int lheight,rheight;
       if(p==NULL)
       { return 0; }
       lheight=height(p->left);
       rheight=height(p->right);
       if(lheight>rheight)
       { return lheight+1; }
       else
       { return rheight+1; }
}

int widthlevel(node *p,int level)
{
       if(p==NULL)
       { return 0; }
       if(level==1)
       { return 1;}
       else 
       { return widthlevel(p->left,level-1)+widthlevel(p->right,level-1); }
}

int max(node *p)
{
       if(p==NULL)
       { return NULL; }
       else if(p->right==NULL)
       { return p->info; }
       else
       { return max(p->right);}
}

int min(node *p)
{
       if(p==NULL)
       { return NULL; }
       else if(p->left==NULL)
       { return p->info; }
       else
       { return min(p->left); }
}

void newinorder(node *p)
{
       if(p==NULL)
       { return; }
       newinorder(p->right);
       printf("%d ",p->info);
       newinorder(p->left);
}