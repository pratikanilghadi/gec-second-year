#include <iostream>

using namespace std;

template <class T>
class insert
{
    T a[10], temp;
    int n, i, j;

    public:
    insert() { n = 0;}
    void getdata();
    void sort();
    void display();
};

template <class T>
void insert<T>::getdata()
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
void insert<T>::sort()
{
    for (i = 1; i < n ; i++)
    {
        for (j = i; j > 0; j--)
        {
            if (a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
            
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }   
            cout << endl;
        }
        cout << "Pass " << i << ": ";
        display();
        cout << endl;
    }
}

template <class T>
void insert<T> :: display()
{
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main(void)
{
    insert<int> obj;
    obj.getdata();
    obj.sort();
    cout << "The sorted array is: ";
    obj.display();
    return 0;
}