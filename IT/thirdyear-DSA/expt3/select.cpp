#include <iostream>

using namespace std;

template <class T>
class select
{
    T a[10], temp;
    int n, i, j, min, pos;

    public:
    void getdata();
    void sort();
    void display();
};

template <class T>
void select<T>::getdata()
{
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

template <class T>
void select<T>:: display()
{
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

template <class T>
void select<T>:: sort()
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
        cout << "Pass " << i + 1 << ": ";
        display();
        cout << endl;
    }
}

int main(void)
{
    select<int> s;
    s.getdata();
    s.sort();
    cout << "The sorted array is: ";
    s.display();
    return 0;
}