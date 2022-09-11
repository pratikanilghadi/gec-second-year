#include<iostream>

using namespace std;

void swapvalue(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "A : " << a << "\t B : " << b << endl;
}

void swapaddress(int *a,int *b)
{
    int *temp = a;
    a = b;
    b = temp;
    cout << "A : " << *a << "\t B : " << *b <<endl;
}
int main(void)
{
    cout << "Enter the two numbers you want to swap" << endl;
    int a,b;
    cin >> a >> b;
    
    swapvalue(a,b);
    swapaddress(&a,&b);
}