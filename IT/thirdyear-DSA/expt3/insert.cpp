#include <iostream>

using namespace std;

class insert
{
    int a[10], n, i, j, temp;

    public:
    void getdata();
    void sort();
    void display();
};

void insert::getdata()
{
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void insert::sort()
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

void insert :: display()
{
    cout << "The sorted array is: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main(void)
{
    insert obj;
    obj.getdata();
    obj.sort();
    obj.display();
    return 0;
}