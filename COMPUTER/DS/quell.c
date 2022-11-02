#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int value;
    struct node *link;
}node;

node *front=NULL,*rear=NULL;

void insert(int data);
void de();
void display();

int main()
{
    int option,value;
    
    while(1)
    {
        printf("\n--------------------\n");
        printf("1-To insert element\n");
        printf("2-Delete the element\n");
        printf("3-Display\n");
        printf("4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:printf("Enter the value to be added : ");
                   scanf("%d",&value);
                   insert(value);
                   break;
            
            case 2:de();
                   break;

            case 3:display();
                   break;

            case 4:exit(1);
                   break;

            default:printf("Invalid input\n");
        }
    }
}

void insert(int data)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->value=data;
    temp->link=NULL;
    if(front==NULL)
    {
        front=temp;
        rear=temp;
        front->link=NULL;
        rear->link=NULL;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}

void de()
{
    int item;
    node *temp=NULL;
    if(front==NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        temp=front;
        item=temp->value;
        front=front->link;
        free(temp);
    }
    printf("\nDeleted element is %d\n",item);
}

void display()
{
    node *p;
    p=front;
    if(front==NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        printf("Elements in queue are: ");
        while(p!=NULL)
        {
            printf("%d ",p->value);
            p=p->link;
        }
        printf("\n");
    }
}