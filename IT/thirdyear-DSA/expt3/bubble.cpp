#include <iostream>

using namespace std;

class bubble
{
    int a[10], n;

    public:
    bubble(int size)
    {
        n = size;
    }
    void getdata();
    void sort();
    void display();
};

void bubble :: getdata()
{
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void bubble :: sort()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i -1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void bubble :: display()
{
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main(void)
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size; 

    bubble b(size);
    b.getdata();
    b.sort();
    b.display();
    return 0;
}