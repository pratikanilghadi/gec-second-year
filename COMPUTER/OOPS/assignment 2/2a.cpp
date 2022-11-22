#include<iostream>

using namespace std;

class complex
{
    private:
            int real;
            int image;
    public:

            void input();
            friend complex add(complex &,complex &);
            void display(complex a ,complex b);
};

void complex::input()
{
    cout<<"Enter real part: ";
    cin>>real;
    cout<<"Enter imaginary part:";
    cin>>image;
}

complex add(complex &a,complex &b)
{
    complex sum;
    sum.real=a.real+b.real;
    sum.image=a.image+b.image;
    return sum;
}

void complex ::display(complex a,complex b)
{
	cout<<"First complex number is: "<<a.real<<"+("<<a.image<<")i"<<endl;
	cout<<"Second complex number is: "<<b.real<<"+("<<b.image<<")i"<<endl;
    cout<<"Added number is:"<<real<<"+("<<image<<")i"<<endl;
}

int main()
{
    complex a,b,s;
    a.input();
    b.input();
    s=add(a,b);
    s.display(a,b);
    return 0;
}