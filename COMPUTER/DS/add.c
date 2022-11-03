#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
 struct node *prev;
 int value;
 struct node *next;
}node;

int count(int a);
node *create(node *start ,int nodetotal,int num);
node *addtoempty(node *start,int num);
node *addatend(node *start,int num);
void display(node *start);
node *add(node *n1,node *n2);
node *cre(node *start,int sum);

int main()
{
 int num1=0,num2=0,l1=0,l2=0;
 node *n1=NULL,*n2=NULL,*s=NULL;
 printf("Enter num1 : ");
 scanf("%d",&num1);
 printf("Enter num2: ");
 scanf("%d",&num2);
 l1=count(num1);//count number of digits
 l2=count(num2);
 n1=create(n1,l1,num1);
 n2=create(n2,l2,num2);
	s=add(n1,n2);//add both lists
	printf("\nNum1 is: ");
 display(n1);
	printf("Num2 is: ");
	display(n2);
	printf("Sum is: ");
	display(s);
}

int count(int a)
{
 int total=0;
 while(a!=0)
 {
  total++;
  a=a/10;
 }
 return total;
}

node *create(node *start ,int nodetotal,int num)
{
 start=NULL;
 if(nodetotal==0)
 {
  return start;
 }
 start=addtoempty(start,num%10);
 num=num/10;
 for(int i=2;i<=nodetotal;i++)
 {
  start=addatend(start,num%10);
  num=num/10;
 }
 return start;
}

node *addtoempty(node *start,int num)
{
 node *temp;
 temp=(node *)malloc(sizeof(node));
 temp->value=num;
 temp->prev=NULL;
 temp->next=NULL;
 start=temp;
 return start;
}

node *addatend(node *start,int num)
{
 node *temp,*p;
 temp=(node *)malloc(sizeof(node));
 temp->value=num;
 p=start;
 while(p->next!=NULL)
 {
  p=p->next;
 }
 p->next=temp;
 temp->next=NULL;
 temp->prev=p;
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
	while(p->next!=NULL)
	{
		printf("%d->",p->value);

		p=p->next;
	}
	printf("%d",p->value);
	printf("\n");
}

node *add(node *n1,node *n2)
{
	node *s=NULL;
	int sum=0,carry=0;
	while(n1!=NULL && n2!=NULL)
	{
		sum=n1->value+n2->value+carry;
		carry=sum/10;
		sum=sum%10;
		s=cre(s,sum);
		n1=n1->next;
		n2=n2->next;
	}
	while(n1!=NULL)
	{
		sum=n1->value+carry;
		carry=sum/10;
		sum=sum%10;
		s=cre(s,sum);
		n1=n1->next;
	}
	while(n2!=NULL)
	{
		sum=n2->value+carry;
		carry=sum/10;
		sum=sum%10;
		s=cre(s,sum);
		n2=n2->next;
	}
	if(carry!=0)
	{
		s=cre(s,carry);
	}
	return s;
}

node *cre(node *start,int sum)
{
	if(start==NULL)
	{
		start=addtoempty(start,sum);
		return start;
	}
	addatend(start,sum);
	return start;
}