#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
 struct node *prev;
 int data;
 struct node *next;
}node;

node *create(node *start);
node *addtoempty(node *start,int data);
node *addatend(node *start,int data);
void display(node *start);
node *swap(node *start);

int main()
{
 node *start=NULL;
 start=create(start);
	printf("Created list is: ");
 display(start);
 start=swap(start);
	printf("Swapped list is: ");
 display(start);
}

node *create(node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
 {
  return start;
 }
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=addtoempty(start,data);
	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=addatend(start,data);	
	}
	return start;
}

node *addtoempty(node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}

node *addatend(node *start,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}

void display(node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}



node *swap(node *start)
{
 node *c=start;
 node *n,*p;
 while(c!=NULL && c->next!=NULL)
 {
  n=c->next;
  p=c->prev;
		if(p!=NULL)
  {
   p->next=n;
  }
  n->prev=p;
  c->prev=n;
  c->next=n->next;
  n->next=c;
  if(c->next!=NULL)
  {
   c->next->prev=c;
  }
		if(n->prev==NULL)
		{
			start=n;
		}
		c=c->next;
 }

 return start;
}