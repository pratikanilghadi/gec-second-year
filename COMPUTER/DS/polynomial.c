#include<stdio.h>
#include<stdlib.h>

struct node
{
 float coe;
 int pow;
 struct node *link;
};

struct node *create(struct node *start);
struct node *add_end(struct node *start,float coe,int pow);
void display(struct node *start);
void add(struct node *p1,struct node *p2);
void multiply(struct node *p1,struct node *p2);
struct node *addsame(struct node *p4);
struct node *addbefore(struct node *start);
struct node *del(struct node *start);

int main()
{
 struct node *p1 = NULL, *p2 = NULL;
 int option,p,mo=0,n=0;

 while(1)
 {
		printf("Enter :\n");
  printf("1-To insert elements in Polynomial\n");
		printf("2-To display polynomal 1 and 2\n");
		printf("3-To add two polynomials\n");
		printf("4-To multiply to polynomials\n");
		printf("5-To modify a polynomial\n");
		printf("6-for file input\n");
		printf("7-to exit\n");
		scanf("%d",&option);
 
 switch(option)
 {
    case 1:printf("1-to enter elements in poly 1\n");
           printf("2-to enter elements in poly 2\n");
           scanf("%d",&p);
           if(p==1)
           {
             p1=create(p1);
           }
           else if(p==2)
           {
             p2=create(p2);
           }
           else
           {
            	printf("only 2 polynomials are accepted\n");
           }
           break;

    case 2:printf("Polynomial 1 is :");
		   						display(p1);
		   						printf("Polynomial 2 is :");
 		   					display(p2);
		   						break;
 	
				case 3:add(p1,p2);
		   						break;
	
				case 4:multiply(p1,p2);
		   						break;

    case 5:printf("1-To modify polynomial 1\n");
           printf("2-To modify polynomial 2\n");
           scanf("%d",&mo);
           if(mo==1)
           {
														printf("0-To insert a new term in polynomial 1:\n");
														printf("1-To delete a term in polynomial 1:\n");
														scanf("%d",&n);
														if(n==0)
            		{
																p1=addbefore(p1);
																p1=addsame(p1);
																printf("modified polynomial is ");
																display(p1);	
														}	
														else
														{
																p1=del(p1);
																display(p1);
														}
											}
											else
											{
														printf("0-To insert a new term in polynomial 2:\n");
            		printf("1-To delete a term in polynomial 2:\n");
            		scanf("%d",&n);
            		if(n==0)
            		{
            			p2=addbefore(p2);
            			p2=addsame(p2);
            			printf("modified polynomial is ");
            			display(p2);	
												 	}
														else
														{
															p2=del(p2);
															printf("modified polynomial is ");
															display(p2);
														}
           
  								}
										break;
				case 6:printf("Enter the polynomial in Polynomial.txt file\n");
	 									FILE *fp1;
	 									char ch;
	 									fp1=fopen("Polynomial.txt","r");
											if(fp1==NULL)
	 									{
													printf("Cannot open file:\n");
													exit(1);
	 									}
	 									printf("The Polynomial in the file is:\n");
										 while(1)
    							{
												ch=fgetc(fp1);
												if(ch==EOF)
												{
														break;
												}
         			printf("%c",ch);
    						}
										printf("\n");
										fclose(fp1);
	 								break;

		  case 7:exit(1);
											break;
				default:printf("invalid input\n");
 }
}
}

struct node *create(struct node *start)
{
 int power,terms,i;
 float coef;
 printf("Enter total number of terms:\n");
 scanf("%d",&terms);
 
 for(i=0;i<terms;i++)
 {
  printf("Enter coeficient for term %d:\n",i+1);
  scanf("%f",&coef);
  printf("Enter power of term %d:\n",i+1);
  scanf("%d",&power);
  start=add_end(start,coef,power);
 }
 return start;
}

struct node *add_end(struct node *start,float coef,int power)
{
 struct node *temp=NULL;
 struct node *p=NULL;
 temp=(struct node *)malloc(sizeof(struct node));
 temp->coe=coef;
 temp->pow=power;

 if(start==NULL||power>start->pow)
 {
   temp->link=start;
   start=temp;
 }
 else
 {
  p=start;
  while(p->link!=NULL && p->link->pow >= power)
		{
				p=p->link; 
		} 
			temp->link = p->link;
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
		printf("Polynomial  is zero:\n");
		return;
	}
	
	while(p!=NULL)
    {
		
		printf("(%.1fx^%d)",p->coe,p->pow);
		p=p->link;
		if(p!=NULL)
		{
			printf(" + ");
		}
		else
		{
			printf("\n");
		}
	}
}

void add(struct node *p1,struct node *p2)
{
	struct node *p3;
	p3=NULL;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->pow == p2->pow)
		{
			p3=add_end(p3,p1->coe+p2->coe,p1->pow);
			p1=p1->link;
			p2=p2->link;
		}
		else if(p1->pow > p2->pow)
		{
			p3=add_end(p3,p1->coe,p1->pow);
			p1=p1->link;
		}
		else if(p1->pow < p2->pow)
		{
			p3=add_end(p3,p2->coe,p2->pow);
			p2=p2->link;
		}
	}
	
	//polynomial 1 is empty
	while(p2!=NULL)
	{
		p3=add_end(p3,p2->coe,p2->pow);
		p2=p2->link;
	}
	
	//polynomial 2 is empty
	while(p1!=NULL)
	{
		p3 = add_end(p3,p1->coe,p1->pow);
		p1 = p1->link;
	}
	
	printf("Poly 1 and poly 2 are added!!!\n");
	printf("Added polynomial is : ");
	display(p3);
}

void multiply(struct node *p1,struct node *p2)
{
	struct node *p4=NULL,*poly1,*poly2;
	poly1=p1;
	poly2=p2;
	
	while(poly1!=NULL)
	{
		while(poly2!=NULL)
		{
			int power=0;
			float coef=0.0;
			
			coef=(poly1->coe)*(poly2->coe);
			power=(poly1->pow)+(poly2->pow);
			p4=add_end(p4,coef,power);
			poly2=poly2->link;
		}
		poly2=p2;
		poly1=poly1->link;
	}
	p4=addsame(p4);
	printf("Poly 1 and Poly 2 are multiplied!!!\n");
	display(p4);
}

struct node *addsame(struct node *start)
{
	struct node *temp1, *temp2,*same;
	temp1=start;
	while(temp1!=NULL && temp1->link!=NULL)
	{
		temp2=temp1;
		while(temp2->link!=NULL)
		{
			if(temp1->pow==temp2->link->pow)
			{
				temp1->coe=temp1->coe+temp2->link->coe;
				same=temp2->link;
				temp2->link=temp2->link->link;
				free(same);
			}
			else
			{
				temp2=temp2->link;
			}
			temp1=temp1->link;
		}
	}
	return start;
}

struct node *addbefore(struct node *start)
{
	int newp;
	float newc;
	struct node *p,*temp;
	printf("Enter coeficient of the term to be inserted :\n");
  	scanf("%f",&newc);
  	printf("Enter power of the term to be inserted :\n");
  	scanf("%d",&newp);
  	temp=(struct node *)malloc(sizeof(struct node));
  	temp->coe=newc;
  	temp->pow=newp;
  	temp->link=NULL;
  	p=start;
  	if(start==NULL)
  	{
  		printf("Enter terms in polynomial\n");
  		return start;
	}
	if(p->pow<=newp)
	{
		temp->link=start;
		start=temp;
		return start;
	}
	while(p!=NULL)
	{
		if(p->pow<=newp)
		{
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	return start;
}


struct node *del(struct node *start)
{
		int delp;
		float delc;
		printf("Enter the coefficient of the term to be deleted\n");
		scanf("%f",&delc);
		printf("Enter the power of the term to be deleted\n");
		scanf("%d",&delp);
		struct node *tmp,*p;
		if(start==NULL)
		{
			printf("Polynomial is empty\n");
			return start;
		}

	else if(start->pow==delp)
	{
		tmp=start;
		start=start->link;
		free(tmp);
		return start;
	}

	p=start;
	while(p->link!=NULL)
	{
		if (p->link->pow==delp)
		{ 
					struct node *tmp= (struct node*)malloc(sizeof(struct node));
		   tmp=p->link;
		   p->link=tmp->link;
		   free(tmp);
		   return p;
		}
		p=p->link;
	}
   printf("Element not found!");
   return p;
}