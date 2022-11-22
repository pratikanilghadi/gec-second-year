#include<iostream>

using namespace std;

int steps = 0;

class hanoi
{
    int size;

    public:
    hanoi(int input)
    {
        size = input;
        solve(size, 1 , 3, 2);
    }
    void solve(int n, int from, int to, int use);   
};

void hanoi::solve(int n, int from, int to, int use)
{
    steps++;
    if(n == 1)
    {
        cout << "Move disk " << n << " from " << from << " to " << to << endl;
        return;
    }
    solve(n-1, from, use, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    solve(n-1, use, to, from);
}

int main()
{
    time_t start, end;
    time(&start);
    hanoi obj(3);
    time(&end);
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken;
    return 0;
}