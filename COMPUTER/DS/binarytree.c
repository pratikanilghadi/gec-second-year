#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50
typedef struct node 
{
 int value;
 struct node *link;
}node;

typedef struct treenode
{
 int value;
 struct treenode *right;
 struct treenode *left;
}treenode;

node *create(node *start,int n);
node *addatbeg(node *start,int data);
node *addatend(node *start,int data);
treenode *construct(node *inptr,node *postptr,int num);
int height(treenode *root);
int depth(treenode *ptr,int data);
void queueinsert(treenode *item);
treenode *queuedelete();
int queueempty();
void levelorder(treenode *root);
void spiral(treenode *root);
void printlevel(treenode *root,int level,bool ltr);
void post(treenode *ptr);

treenode *queue[MAX];
int front=-1,rear=-1;

int main()
{
        
 int n=0,op=0;
 node *inorder,*postorder;
 treenode *tree;
 printf("Enter number of nodes : ");
 scanf("%d",&n);
 printf("\nEnter Inorder traversal\n");
 inorder=create(inorder,n);
 printf("\nEnter Postorder traversal\n");
 postorder=create(postorder,n);
 tree=construct(inorder,postorder,n);
 printf("\nTREE CONSTRUCTED\n");
 printf("\nPostorder traversal : ");
 post(tree);


 while(1)
 {
  printf("\n--------------------\n");
  printf("1-find height of tree\n");
  printf("2-find depth of a node\n");
  printf("3-to perform level order traversal\n");
  printf("4-to perform spiral traversal\n");
  printf("5-to exit\n");
  printf("Enter your choice : ");
  scanf("%d",&op);

  switch(op)
  {
   case 1:printf("\nHeight of tree is %d\n",height(tree));
          break;

   case 2:printf("\nEnter the value of node whose depth is to be found : ");
          scanf("%d",&n);
          printf("Depth of node is %d\n",depth(tree,n));
          break;

   case 3:printf("\nlevel order traversal is :");
          levelorder(tree);
          printf("\n");
          break;

  case 4:printf("\nSpiral traversal is :");
               spiral(tree);
               printf("\n");
         break;

  case 5:exit(1);

  default:printf("Invalid option");
  }
 }
}

node *create(node *start,int n)
{
 int data;
 start=NULL;
 if(n==0)
 {
  return start;
 }
 printf("Enter value : ");
 scanf("%d",&data);
 start=addatbeg(start,data);
 for(int i=1;i<n;i++)
 {
  printf("Enter value : ");
  scanf("%d",&data);
  start=addatend(start,data);
 }
 return start;
}

node *addatbeg(node *start,int data)
{
 node *temp;
 temp=(node *)malloc(sizeof(node));
 temp->value=data;
 temp->link=start;
 start=temp;
 return start;
}

node *addatend(node *start,int data)
{
 node *temp,*p;
 temp=(node *)malloc(sizeof(node));
 temp->value=data;
 p=start;
 while(p->link!=NULL)
 {
  p=p->link;
 }
 p->link=temp;
 temp->link=NULL;
 return start;
}

treenode *construct(node *inptr,node *postptr,int num)
{
 treenode *temp;
 node *q,*ptr;
 int i,j;
 if(num==0)
 {
  return NULL;
 }

 ptr=postptr;

 for(i=1;i<num;i++)
 {
  ptr=ptr->link;
 }
 temp=(treenode *)malloc(sizeof(treenode));
 temp->value=ptr->value;
 temp->left=NULL;
 temp->right=NULL;
 if(num==1)
 {
        return temp;
 }
 q=inptr;
 for(i=0;q->value!=ptr->value;i++)
 {
        q=q->link;
 }
 temp->left=construct(inptr,postptr,i);
 for(j=1;j<=i;j++)
 {
        postptr=postptr->link;
 }
 temp->right=construct(q->link,postptr,num-i-1);
 return temp;
}

int height(treenode *ptr)
{
 int hleft,hright;
 if(ptr==NULL)
 {
  return 0;
 }
 hleft=height(ptr->left);
 hright=height(ptr->right);
 if(hleft>hright)
 {
  return 1+hleft;
 }
 else
 {
  return 1+hright;
 }
}

int depth(treenode *ptr,int data)
{
 int n;
 if(ptr==NULL)
 {
  return -1;     
 }
 n=-1;
 if((ptr->value==data) || (n=depth(ptr->left,data))>=0 || (n=depth(ptr->right,data))>=0)
 {
  return n+1;
 }      
 return n;
}

void queueinsert(treenode *item)
{
       if(rear==MAX-1)
       {
       printf("Queue overflow");
       return;
       }
       if(front==-1)
       {
       front=0;
       }
       rear=rear+1;
       queue[rear]=item;
}

treenode *queuedelete()
{
 treenode *item;
 if(front==-1||front>rear)
 {
  printf("Queue underflow");
  exit(1);
 }
 item=queue[front];
 front=front+1;
 return item;
}

int queueempty()
{
 if(front==-1||front>rear)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

void levelorder(treenode *root)
{
       treenode *ptr=root;
       if(ptr==NULL)
       {
              printf("Tree is empty");
              return;
       }
       queueinsert(ptr);
       while(!queueempty())
       {
              ptr=queuedelete();
              printf("%d ",ptr->value);
              if(ptr->left!=NULL)
              {
                     queueinsert(ptr->left);
              }
              if(ptr->right!=NULL)
              {
                     queueinsert(ptr->right);
              }
       }
       printf("\n");
}

void spiral(treenode *root)
{
       int c=height(root);
       int i;
       bool ltr=false;
       for(i=1;i<=c;i++)
       {
              printlevel(root,i,ltr);
              ltr=!ltr;
       }

}

void printlevel(treenode *root,int level,bool ltr)
{
       if(root==NULL)
       {
              return;
       }
       if(level==1)
       {
              printf("%d ",root->value);
       }
       else if(level>1)
       {
              if(ltr)
              {
                     printlevel(root->left,level-1,ltr);
                     printlevel(root->right,level-1,ltr);
              }
              else
              {
                     printlevel(root->right,level-1,ltr);
                     printlevel(root->left,level-1,ltr);
              }
       }
}

void post(treenode *ptr)
{
 if(ptr==NULL)
 {
  return;     
 }
 post(ptr->left);
 post(ptr->right);
 printf("%d ",ptr->value);      
}