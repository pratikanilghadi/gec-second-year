#include <iostream>

using namespace std;

class select
{
    int a[10], n, i, j, temp, min, pos;

    public:
    void getdata();
    void sort();
    void display();
};

void select::getdata()
{
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void select:: display()
{
    cout << "The sorted array is: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void select:: sort()
{
    for (int i = 0; i < n ; i++)
    {
        min = a[i];
        pos = i;
        for (int j = i + 1; j < n ; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                pos = j;
            }
        }
        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
    }
}

int main(void)
{
    select s;
    s.getdata();
    s.sort();
    s.display();
    return 0;
}