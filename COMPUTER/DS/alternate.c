#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *link;
}node;

node *create(node *last);
node *addtoempty(node *last,int data);
void display(node *last);
node *addatend(node *last,int data);
node *alt(node *last);

int main()
{
 node *last=NULL;
 last=create(last);
 printf("Original list is: ");
 display(last);
 
 last=alt(last);
	printf("\nUpdated list is : ");
 display(last);
 return 0;
}

node *create(node *last)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	last=NULL;
	if(n==0)
 {
  return last;
 }
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	last=addtoempty(last,data);
	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		last=addatend(last,data);	
	}
	return last;
}

node *addtoempty(node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(node));
	tmp->data=data;
	last=tmp;
	last->link=last;
	return last;
}

node *addatend(node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}

void display(node *last)
{
	node *p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=last->link;
	do 
	{
		printf("%d ",p->data);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}

node *alt(node *last)
{
 if(last==NULL)
 {
  printf("List is empty\n");
  return last;
 }

 node *prev=last->link;
 node *next=last->link->link;

 while(prev!=NULL && next!=NULL)
 {
  if(last==last->link)//only 1 node
  {
   free(prev);
   last=NULL;
   return last;

  }
  if(next==last)//last node to be deleted
  {
   prev->link=next->link;
   last=prev;
   free(next);
   return last;
   }

   if(last==prev)//end of the list
   {
    return last;
   }
   
  prev->link=next->link;
  free(next);

  prev=prev->link;
  if(prev!=last)
  {
   next=prev->link;
  }
 }
 return last;
}