#include<iostream>

using namespace std;

void square(int value)
{
    cout << value * value << endl;
}

void square(float value)
{
    cout << value * value << endl;
}

void square(double value)
{
    cout << value * value << endl;
}

int main(void)
{
    cout << "Enter the number to be square " << endl;
    double value;
    
    cin >> value;

    square(value);
    square((int)value);
    square((float)value);
}