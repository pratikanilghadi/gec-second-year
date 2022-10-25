#include <iostream>

using namespace std;

class selection
{
    int a[10], n;

    public:
    selection(int size)
    {
        n = size;
    }
    void getdata();
    void sort();
    void display();
};

void selection :: getdata()
{
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void selection :: display()
{
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void selection :: sort()
{
    for (int i = 1; i < n; i++)
    {
        if ( a[i] < a[)
    }
}

int main(void)
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size; 

    selection s(size);
    s.getdata();
    s.sort();
    s.display();
}