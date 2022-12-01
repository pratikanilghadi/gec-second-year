#include <iostream>

using namespace std;

template <class T>
class bubble
{
    T a[10];
    int n;

    public:
    bubble(int size)
    {
        n = size;
    }
    void getdata();
    void sort();
    void display();
};

template <class T>
void bubble<T> :: getdata()
{
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

template <class T>
void bubble<T> :: sort()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i -1; j++)
        {
            if (a[j] > a[j + 1])
            {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

        }
        cout << "Pass " << i + 1 << ": ";
        display();
        cout << endl;;
    }
}

template <class T>
void bubble<T> :: display()
{
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

    bubble<float> b(size);
    b.getdata();
    b.sort();
    cout << "The sorted array is: ";
    b.display();
    return 0;
}