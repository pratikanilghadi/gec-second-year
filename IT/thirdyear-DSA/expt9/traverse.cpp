//C++ code for implementing breadth first search and depth first search using adjacency matrix
#include <iostream>
#include <stack>
#include <queue>
#define MAX 5

using namespace std;

int visited[MAX*MAX];

void clear_visited()
{
    for(int m = 0; m < MAX * MAX; m++)
    {
        visited[m] = 0;
    }
}
//!---------------------------Class Defination-------------------------------------------
class mgraph
{
    public:
    int matrix[MAX][MAX];
    mgraph();
    void getdata();
    void bfs();
    void dfs();
};
//!---------------------------Function mgraph()----------------------------------------
/*
    Constructor function of the class mgraph()
*/
mgraph::mgraph()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

//Todo-------------------------Function getdata()----------------------------------------
/*
    This function gets it data from user (The connection of the vertices) for the MAX * MAX matric (for MAX vertices)
*/
void mgraph:: getdata()
{
    int choice = 0;
    do
    {
        system("cls");
        cout << "Do you want to make link between nodes?" << endl;
        cout << "1.Yes" << endl;
        cout << "2.NO" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int i = 0,j = 0;
                cout << "Enter the two nodes you want to connect" << endl;
                cin >> i;
                cin >> j;
                matrix[i][j] = 1;
                matrix[j][i] = 1;
                break;
            }
            
            case 2:
            break;

            default:
            cout << "Incorrect option" << endl;
        }
    } while (choice!=2);
}

//Todo-------------------------Function bfs()--------------------------------------------
/*
    This function works out the Breadth First Search Algorithm
*/
void mgraph:: bfs()
{
    clear_visited();
    queue<int> bque;
    bque.push(0);
    while(!bque.empty())
    {
        
    }
}

//Todo-------------------------Function dfs()--------------------------------------------
/*
    This function works out the Depth First Search Algorithm
*/
void mgraph:: dfs()
{
    clear_visited();
}

//!============================Main Function Defination===================================
int main()
{
    mgraph obj;
    obj.getdata();
    obj.bfs();
    obj.dfs();
}

