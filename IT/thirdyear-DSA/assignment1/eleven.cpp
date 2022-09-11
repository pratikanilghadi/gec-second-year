#include<iostream>

using namespace std;

class complex
{
    int real;
    int img;
    
    public:
//Constructor
    complex(int r,int i)
    {
        real = r;
        img = i;
    }
//Additon
    void addition(int r,int i)
    {
        real += r;
        img += i;
    }
//Subraction
    void subtract(int r,int i)
    {
        real -= r;
        img -= i;
    }
//Display
    void display()
    {
        cout << "--------------------------" << endl;
        cout << real << " + " << img << 'i' << endl;
        cout << "--------------------------" << endl;
    }
};

int main(void)
{
    int img,real;
    cout << "Enter the real part of the number ";
    cin >> real;
    cout << endl << "Enter the imaginary part of the number ";
    cin >> img;
    cout << endl;

    complex problem(real,img);
    problem.display();
    cout << endl;
    problem.addition(10,10);
    cout << endl;
    problem.display();
    cout << endl;
    problem.subtract(5,5);
    cout << endl;
    problem.display();
}