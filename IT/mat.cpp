#include <iostream>
#define MAX 7

using namespace std;

class graph
{
    int matrix[MAX][MAX];

    public:
    graph()
    {
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
            {
                matrix[i][j] = 0;
            }
    }

    void display();
    void insert(int from,int to,int value);
    void search(int value);
};

void graph :: display()
{
    for (int i = 0; i < MAX; i++)
    {
        cout << "|  ";
        for (int j = 0; j < MAX; j++)
        {
           cout << matrix[i][j] << "  ";
        }
        cout << "|" << endl;
    }
}

void graph :: insert(int from,int to ,int value)
{
    if ( (from > MAX || from < 0) || (to > MAX || to < 0))
    {
        cout << "Invalid" << endl;
        return;
    }
    matrix[from-1][to-1] = value;
    matrix[to-1][from-1] = value;
}

void graph:: search(int value)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i; j < MAX; j++)
        {
            if (matrix[i][j] == value)
            {
                cout << "The cost 24 exist between the nodes " << i + 1 << " and " << j + 1 << endl;
            }
        }
    }
}

//The code creates an object of graph and uses the insert function to insert nodes into the graph
//An empty value represents or NULL value represents no connection
int main()
{
    graph obj;
    obj.insert(1,2,28);
    obj.insert(1,6,10);
    obj.insert(2,7,14);
    obj.insert(2,3,16);
    obj.insert(3,4,12);
    obj.insert(7,4,18);
    obj.insert(7,5,24);
    obj.insert(6,5,25);
    obj.insert(5,4,22);
    obj.search(24);
}