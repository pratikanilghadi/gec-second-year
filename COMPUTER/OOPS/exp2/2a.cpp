#include<iostream>


using namespace std;

void swap(int &one,int &two)
{
    int temp;
    temp=one;
    one=two;
    two=temp;
}

int main()
{
    int one ,two;
    cout<<"Enter value of a\n";
    cin>>one;
    cout<<"enter value of b\n";
    cin>>two;
    cout<<"Before Swapping"<<endl;
    cout<<"a="<<one<<" b="<<two<<endl;

    swap(one,two);
    cout<<"After Swapping"<<endl;
    cout<<"a="<<one<<" b="<<two<<endl;
}
