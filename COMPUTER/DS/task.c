#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

struct Task
{
    int task_id;
    char title[100];
    int duration;
    char status[30];
}task[10];

int MAX = 5;
int front=-1;
int rear=-1;

void schedule(struct Task queue[]);
int isFull();
void insert(int item,int time,struct Task queue[],int i);
void run(struct Task queue[]);
void del(struct Task queue[]);
void display();
int isEmpty();
void delay(int time);

int main()
{
    int options;
    int MAX = 5;
    struct Task queue[MAX];
    FILE *t=fopen("task.txt","r+");
    if(t==NULL)
    {
        printf("File cannot be opened:\n");
        exit(1);
    }
    for(int i=0;i<10;i++)
    {
        fscanf(t,"%d %s %d %s",&task[i].task_id,&task[i].title,&task[i].duration,&task[i].status);
    }
    fclose(t);
    
    while(1)
    {
        printf("\nEnter:\n");
        printf("1-Scheduling a task\n");
        printf("2-Running a task\n");
        printf("3-Display scheduled task details\n");
        printf("4-Exit\n");
        scanf("%d",&options);

        switch(options)
        {
            case 1:schedule(queue);
                   break;

            case 2:run(queue);
                   break;

            case 3:display();
                   break;

            case 4:exit(1);
                   break;
                
            default :printf("Invalid input\n");
        }
    }
}

void schedule(struct Task queue[])
{
    int id,flag=0;
    printf("\nEnter id number of task to be scheduled: ");
    scanf("%d",&id);
    for (int i=0;i<10;i++)
    {
        if(task[i].task_id==id )
        {
            if(strcmp(task[i].status,"Queued")==1)
            {
                if(strcmp(task[i].status,"completed")==1)
                {
                    insert(id,task[i].duration,queue,i);
                    break;
                }
                else
                {
                    printf("Task is already completed!!\n");
                    break;
                }
            }
            else
            {
                printf("Task is already scheduled!!\n");
                break;
            }
            
        }
        else
        {
            flag++;
            continue;
            
        }
    }
    if(flag>9)
    {
        printf("Task of ID number %d not found\n",id);
    }
}

void insert(int item,int time,struct Task queue[],int i)
{
    if(front == MAX && rear==MAX-1)
    {
        front=-1;
        rear=-1;
    }
    if(isFull())
    {
        int maxtime=0;
        for (int i=0;i<MAX;i++)
        {
            maxtime=maxtime+queue[i].duration;
        }
        printf("Please wait:\n");
        printf("Minimum time for waiting is %d seconds and maxmimum time for waiting is %d seconds\n",queue[rear].duration,maxtime);
        return ;
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=rear+1;
	    queue[rear].task_id=item;
        queue[rear].duration=time;
        strcpy(task[i].status,"Queued");
        printf("Task of ID number %d is scheduled\n",item);
    }
}

int isFull()
{
    if(rear==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void run(struct Task queue[])
{
    if(isEmpty())
    {
        printf("Task is not scheduled\n");
        return;
    }
    printf("Task is running\n");
    printf("Please Wait\n");
    for(int i=0;i<queue[front].duration;i++)
    {
        printf("%d. ",i);
        delay(1);
    }
    printf("\nTask with ID %d is completed\n",queue[front].task_id);
    for(int i=0;i<10;i++)
    {
        if(queue[front].task_id==task[i].task_id)
        {
            strcpy(task[i].status,"completed");
            break;
        }
    }
    del(queue);
}

void del(struct Task queue[])
{
    if(isEmpty())
    {
        printf("Tasks are not scheduled\n");
        exit(1);
    }
    else
    {
        front++;
        MAX++;
    }

    
}

int isEmpty()
{
	if(front==-1 || front==rear+1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display()
{
    int count=0;
    printf("\nIdle tasks are:\n");
        for(int i=0;i<10;i++)
        {
            if(strcmp(task[i].status,"idle")==0||strcmp(task[i].status,"Idle")==0)
            {
                printf("ID:-%d , Task name:-",task[i].task_id);
                puts(task[i].title);
            }
        }

        printf("\nQueued tasks are:\n");
        for(int i=0;i<10;i++)
        {
            if(strcmp(task[i].status,"Queued")==0)
            {
                printf("ID:-%d , Task name:-",task[i].task_id);
                puts(task[i].title);
            }
        }

        printf("\nCompleted tasks are:\n");
        for(int i=0;i<10;i++)
        {
            if(strcmp(task[i].status,"completed")==0)
            { 
                printf("ID:-%d , Task name:-",task[i].task_id);
                puts(task[i].title);
            }
            else
            {
                count++;
            }
        }
        if(count>9)
        {
            printf("Tasks are not completed\n");
        }
}

void delay(int time)
{
    int time_ms = 1000 * time;
    clock_t start = clock();
    while (clock() < start + time_ms)
    {
        
    }
}