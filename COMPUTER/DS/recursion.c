#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
}node;

node *addatbeg(node *start,int data);
node *addatend(node *start,int data);

void convert(int num ,int base)
{
 int rem=num%base;
 if(num==0)
 { return; }

 convert(num/base,base);

 if(rem<10)
 {
  printf("%d",rem);
 }
 else
 {
  printf("%c",rem-10+'A');
 }
}

void tower(int disks,char source,char temp,char dest)
{
 if(disks==1)
 {
  printf("Move disk %d from %c ----> %c\n",disks,source,dest);
  return;
 }
 tower(disks-1,source,dest,temp);
 printf("Move disk %d from %c ----> %c\n",disks,source,dest);
 tower(disks-1,temp,source,dest);
}

int divisor(int a,int b)
{
       if(b==0)
       {
              return a;
       }
       
       return divisor(b,a%b);
}
void reverse(char *sti)
{ 
       if(*sti=='\0')
       {
            return;
       }
       reverse(sti+1);
       putchar(*sti);       
}
node *create(node *start)
{
       int i,n=1;
	start=NULL;
	if(n==0)
       {
           return start;
       }
		
	start=addatbeg(start,10);
       start=addatend(start,30);
       start=addatend(start,360);
       start=addatend(start,70);
       start=addatend(start,31);
       start=addatend(start,80);
       start=addatend(start,380);
       start=addatend(start,810);
       start=addatend(start,100);
       start=addatend(start,40);
       start=addatend(start,90);
       start=addatend(start,04);
       start=addatend(start,03);
	return start;	
}

node *addatbeg(node *start,int data)
{
	node *tmp;
	tmp=(node *)malloc(sizeof(node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}

node *addatend(node *start,int data)
{
       node *p,*tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
       {
              p=p->link;
       }
	p->link=tmp;
	tmp->link=NULL;
	return start;
}
void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is:\n");
	while(p!=NULL)
	{
		printf("%d  ",p->info);
		p=p->link;
	}
	printf("\n\n");
}

int search(node *start,int item)
{
       node *p=start;
       if(p==NULL)
       {
              return 0;
       }
       if(p->info==item)
       {
              return 1;
       }
       return search(p->link,item);
}

int main()
{
 int op=0,num=0,disks=0,num1=0,num2=0,item,found=0;
 char source='A',temp='B',dest='C';
 char *sti;
 struct node *start;
 
 while(1)
 {
  printf("\n---------------");
  printf("\n1-Base conversion\n");
  printf("2-Tower of Hanoi\n");
  printf("3-To find greatest common divisor\n");
  printf("4-Reverse a string\n");
  printf("5-to search an item\n");
  printf("6-Exit\n");
  printf("Enter Your choice: ");
  scanf("%d",&op);

  switch(op)
  {
   case 1:do
          {
           printf("\nEnter a positive decimal number\n");
           scanf("%d",&num);
          }while(num<=0);

          printf("Binary: ");
          convert(num,2);
          printf("\n");
          printf("Octal: ");
          convert(num,8);
          printf("\n");
          printf("Hexadecimal: ");
          convert(num,16);
          printf("\n");
          break;

   case 2:printf("\nEnter number of disks\n");
          scanf("%d",&disks);
          printf("Sequence is : \n");
          tower(disks,source,temp,dest);
          break;

   case 3:printf("\nEnter 1st number : ");
          scanf("%d",&num1);
          printf("Enter 2nd number : ");
          scanf("%d",&num2);
          printf("Greatest Common Divisor of %d and %d is %d \n",num1,num2,divisor(num1,num2));
          break;

   case 4:printf("Enter string : ");
          scanf("%s",&sti);
          printf("Originnal string is:  ");
	   printf("%s",&sti);
	   printf("\nReversed string is : ");
	   reverse(&sti);
	   printf("\n");
          break;

  case 5:start=create(start);
         printf("\nEnter the value to be search: ");
         scanf("%d",&item);
         found=search(start,item);
         if(found==1)
         {
              printf("Item found!!\n");
         }
         else
         {
              printf("Item not found!!\n");
         }
         break;

   case 6:exit(1);

   default:printf("Invalid Input\n");
  }
 } 
}
