#include<iostream>
#define CHECK(a) ( a == 0 ? true : false)

using namespace std;

int main(void)
{
    int num;
    cout << "Enter the number to be checked" << endl;
    cin >> num;

    bool status = false;

    for ( int i = 2; i <= num/2; i++)
        {
            status = CHECK(num%i);
            if (true)
                break;
        }
    if (status)
        cout << endl << "The number is not a Prime number" << endl;
    else
        cout << endl << "The number is a Prime number" << endl;
}