#include <iostream>

using namespace std;

class radix
{
    int a[10], n, i, j, temp;;

    public:
    void getdata();
    void sort();
    void display();
};

void radix::getdata()
{
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void radix::display()
{
    cout << "The sorted array is: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void radix::sort()
{

}

int main(void)
{
    radix obj;
    obj.getdata();
    obj.sort();
    obj.display();
    return 0;
}
