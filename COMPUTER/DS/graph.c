//implementing graph using adjacency list
#include <stdio.h>
#include <stdlib.h>

int n = 6,i; // total vertices;
struct edge;
typedef struct vertex
{
    int info;
    struct edge *firstedge;
    struct vertex *nextvertex;
}vertex;

typedef struct edge
{
    struct edge *nextedge;
    struct vertex *destvertex;
}edge;

vertex *start = NULL;

void add_vertex(int v)
{
    vertex *ptr = start;
    vertex *temp;
    if ((temp = (vertex *)malloc(sizeof(vertex))) == NULL)
    {
        printf("<memory overflow>\n");
        return;
    }
    temp->info = v, temp->nextvertex = temp->firstedge = NULL;
    if (start == NULL)
    { start = temp; }
    else
    {
        while (ptr->nextvertex != NULL)
        { ptr = ptr->nextvertex; }
        ptr->nextvertex = temp;
    }
    n++;
}

vertex *find_vertex(int v)
{
    vertex *ptr = start, *loc;
    while (ptr != NULL)
    {
        if (ptr->info == v)
        {
            loc = ptr;
            return loc;
        }
        else
        { ptr = ptr->nextvertex; }
    }
    printf("vertex %d not present\n", v);
}

void add_edge(int u, int v)
{
    vertex *locu = find_vertex(u), *locv = find_vertex(v);
    if (locu == NULL)
    {
        printf("Start vertex not present\n");
        return;
    }
    if (locv == NULL)
    {
        printf("Destination vertex not present\n");
        return;
    }
    edge *ed;
    if ((ed = (edge *)malloc(sizeof(edge))) == NULL)
    {
        printf("<memory overflow>\n");
        return;
    }
    ed->destvertex = locv;
    ed->nextedge = NULL;
    if (locu->firstedge == NULL)
    { locu->firstedge = ed; }
    else
    {
        edge *tempedge = locu->firstedge;
        while (tempedge->nextedge != NULL)
        {tempedge = tempedge->nextedge; }
        tempedge->nextedge = ed;
    }
    return;
}

void display()
{
    if (start == NULL)
    {
        printf("The graph has no vertices or edges\n");
        return;
    }
    vertex *ptr = start;
    edge *ed;
    while (ptr != NULL)
    {
        ed = ptr->firstedge;
        printf(" %d --> ", ptr->info);
        while (ed != NULL)
        {
            printf(" %d --> ", ed->destvertex->info);
            ed = ed->nextedge;
        }
        printf("NULL");
        ptr = ptr->nextvertex;
        printf("\n");
        printf(" | \n");
        printf(" v ");
        printf("\n");
    }
    printf("NULL");
    printf("\n");
}

// bfs using adjacency list
void BFT()
{
    int visited[n];
    for ( i = 0; i < n; i++)
    { visited[i] = 0; }
    vertex *ptr = start;
    edge *ed;
    int queue[n], front = -1, rear = -1;
    while (ptr != NULL)
    {
        if (visited[ptr->info] == 0)
        {
            printf("%d ", ptr->info);
            visited[ptr->info] = 1;
            queue[++rear] = ptr->info;
            while (front != rear)
            {
                int temp = queue[++front];
                ed = find_vertex(temp)->firstedge;
                while (ed != NULL)
                {
                    if (visited[ed->destvertex->info] == 0)
                    {
                        printf("%d ", ed->destvertex->info);
                        visited[ed->destvertex->info] = 1;
                        queue[++rear] = ed->destvertex->info;
                    }
                    ed = ed->nextedge;
                }
            }
        }
        ptr = ptr->nextvertex;
    }
}

// dfs using adjacency list
void DFT()
{
    int visited[n];
    for ( i = 0; i < n; i++)
    { visited[i] = 0; }
    vertex *ptr = start;
    edge *ed;
    int stack[n], top = -1;
    while (ptr != NULL)
    {
        if (visited[ptr->info] == 0)
        {
            printf("%d ", ptr->info);
            visited[ptr->info] = 1;
            stack[++top] = ptr->info;
            while (top != -1)
            {
                int temp = stack[top];
                ed = find_vertex(temp)->firstedge;
                while (ed != NULL)
                {
                    if (visited[ed->destvertex->info] == 0)
                    {
                        printf("%d ", ed->destvertex->info);
                        visited[ed->destvertex->info] = 1;
                        stack[++top] = ed->destvertex->info;
                        break;
                    }
                    ed = ed->nextedge;
                }
                if (ed == NULL)
                { top--; }
            }
        }
        ptr = ptr->nextvertex;
    }
}

int main()
{
   //inserting the vertices
    for ( i =1; i<=6 ;i++)
    {
        add_vertex(i);
    }
   //inserting the edges
    add_edge(1,2), add_edge(1,5), add_edge(2,1), add_edge(2,3), add_edge(3,2), add_edge(3, 4), add_edge(2, 5);
     add_edge(5,1), add_edge(5,2), add_edge(5,4), add_edge(6,4),add_edge(4,3),add_edge(4,5),add_edge(4,6);
     
    printf("The following graph is constructed:\n");
    display();
    printf("\nBFS of constructed graph: ");
    BFT();
    printf("\nDFS of constructed graph: ");
    DFT();
    int ch;
    int v, sv, ev;
    do
    {
        printf("\n\nThe operations provided:\n1. Add a new vertex\n2. Add three new edges\n");
        printf("3.Display the Breadth-First Transversal\n4.Display the Depth-First Transversal\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        printf("\n");
        
        switch (ch)
        {
        case 1:
            printf("Enter vertex: ");
            scanf("%d", &v);
            add_vertex(v);
            break;
            
        case 2:
         	for(i=1;i<=3;i++)
         {  printf("\nConstructing new edge %d:\n",i);
            printf("Enter starting vertex: ");
            scanf("%d", &sv);
            printf("Enter ending vertex: ");
            scanf("%d", &ev);
            add_edge(sv, ev);
          }
            break;
            
        case 3:
            BFT();
            break;
            
        case 4:
            DFT();
            break;
            
        case 5:
        	printf("The updated graph is:\n");
            display();
            exit(0);
            break;
            
        default:
            printf("Invalid Input!\n");
            break;
        }
    } while (ch!=5);
    return 0;
}