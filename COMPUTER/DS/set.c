#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int value;
	struct node *link;
};

struct node *create(struct node *start);
struct node *add_end(struct node *start,int element);
void display(struct node *start);
void uni(struct node *a,struct node *b);
int present(struct node *start,int element);
void intersection(struct node *a,struct node *b);
void diff(struct node *a,struct node *b);

int main()
{
	struct node *a=NULL,*b=NULL;
	int option;
	while(1)
	{
		printf("\n\nEnter:\n");
		printf("1-To enter elements in set A\n");
		printf("2-To enter elements in set B\n");
		printf("3-to Display sets\n");
		printf("4-Union of Set A and B\n");
		printf("5-Intersection of Set A and B\n");
		printf("6-Set Difference(A-B):\n");
		printf("7-Set Difference(B-A):\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:printf("For inserting elements in Set-A\n"); 
 		   		  a=create(a);
 		       break;
 		           
 		case 2:printf("For inserting elements in Set-B\n"); 
 		   		  b=create(b);
 		       break;
 		           
 		case 3:printf("Set A is :");
		   		   display(a);
		   		   printf("Set B is :");
 		   	   display(b);
		   		   break;

		 case 4:uni(a,b);
		   		   break;

		 case 5:intersection(a,b);
		   			break;

		 case 6:diff(a,b);
				    break;

			case 7:diff(b,a);
				   			break;

			case 8:exit(1);
									break;
					
			default:printf("invalid input:\n");	
		}
	}
}

struct node *create(struct node *start)
{
	int element,terms,i;
	printf("Enter total number of elements:\n");
 scanf("%d",&terms);
    
 for(i=0;i<terms;i++)
 	{
  		printf("Enter %d element of set:\n",i+1);
  		scanf("%d",&element);
  		start=add_end(start,element);
 	}	
  return start;
}

struct node *add_end(struct node *start,int element)
{
 struct node *temp=NULL;
 struct node *p=NULL;
 temp=(struct node *)malloc(sizeof(struct node));
 temp->value=element;
 temp->link=NULL;

 if(start==NULL)
 {
   start=temp;
 }
 else
 {
  p=start;
  while(p->link!=NULL)
  {
   p=p->link;
  }
  p->link=temp;
 }
 return start;
}

void display(struct node *start)
{
	struct node *p;
	p=start;
	if(p==NULL)
	{
		printf("Empty:\n");
		return;
	}
	printf("{");
	while(p!=NULL)
    {
		printf("%d",p->value);
		p=p->link;
		if(p!=NULL)
		{
			printf(" , ");
		}
		else
		{
			printf("}\n");
		}
	}
}

void uni(struct node *a,struct node *b)
{
	struct node *c=NULL,*temp1,*temp2;
	temp1=a;
	temp2=b;
	while(temp1!=NULL)
	{
		c=add_end(c,temp1->value);
		temp1=temp1->link;
	}
	while(temp2!=NULL)
	{
		if(!present(c,temp2->value))
		{
			add_end(c,temp2->value);
		}
		temp2=temp2->link;	
	}
	printf("union is :");
	display(c);
}

int present(struct node *start,int element)
{
	struct node *temp=start;
	while(temp!=NULL)
	{
		if(temp->value==element)
		{
			return 1;
		}
		temp=temp->link;
	}
	return 0;
}

void intersection(struct node *a,struct node *b)
{
	struct node *i=NULL;
	struct node *temp=a;
	
	while(temp!=NULL)
	{
		if(present(b,temp->value))
		{
			i=add_end(i,temp->value);
		}
		temp=temp->link;
	}
	printf("Intersection of set A and Set B is : ");
	display(i);
}

void diff(struct node *a,struct node *b)
{
	struct node *d=NULL;
	struct node *temp=a;
	while(temp!=NULL)
	{
		if(!present(b,temp->value))
		{
			d=add_end(d,temp->value);
		}
		temp=temp->link;
	}
	printf("set difference is :");
	display(d);
}
