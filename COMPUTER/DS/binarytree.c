#include<stdio.h>
#include<stdlib.h>
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

treenode *queue[MAX];
int front=-1,rear=-1;

int main()
{
        
 int n=0,op=0;
 node *inorder,*postorder;
 treenode *tree;
 printf("Enter number of nodes : ");
 scanf("%d",&n);
 printf("Enter inorder traversal\n");
 inorder=create(inorder,n);
 printf("Enter postorder traversal\n");
 postorder=create(postorder,n);
 tree=construct(inorder,postorder,n);
 printf("TREE CONSTRUCTED");

 while(1)
 {
  printf("\n1-find height of tree\n");
  printf("2-find depth of a node\n");
  printf("3-to perform level order traversal\n");
  printf("4-to perform spiral traversal\n");
  printf("5-to exit\n");
  scanf("%d",&op);

  switch(op)
  {
   case 1:printf("Height of tree is %d",height(tree));
          break;

   case 2:printf("Enter the value of node whose depth is to be found");
          scanf("%d",&n);
          printf("Depth of node is %d\n",depth(tree,n));
          break;

   case 3:levelorder(tree);
          break;

  case 4:printf("Spiral traversal is :");
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
 int dleft,dright;
 if(ptr==NULL)
 {
  return 0;
 }
 if(ptr->value==data)
 {
  return 1;
 }
 dleft=depth(ptr->left,data);
 dright=depth(ptr->right,data);
 if(dleft>dright)
 {
  return 1+dleft;
 }
 else
 {
  return 1+dright;
 }
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