#include<iostream>
#define MAX 5

using namespace std;

class stack
{
    private:
    int top;
    int array[MAX];

    public:
    stack() 
    {
        top = -1;
        for ( int i = 0; i < MAX ; i++)
        {
            array[i] = 0;
        }
    }
    void pop();
    void push(int value);
    void seek();
    void display();
    bool isempty();
    bool isfull();
};

void stack :: pop()
{
    if (isempty())
    {
        cout << endl << "The stack is empty" << endl;
        return;
    }
    array[top] = 0;
    top--;
}

void stack :: push(int value)
{
    if (isfull())
    {
        cout << endl << "The stack is full" << endl;
        return;
    }
    top++;
    array[top] = value;
}

bool stack :: isempty()
{
    if(top == -1)
        return true;
    else
        return false;
}

bool stack :: isfull()
{
    if(top == MAX - 1)
        return true;
    else
        return false;
}

void stack :: seek()
{
    if(isempty())
    {
        cout << endl << "The stack is empty" << endl;
    }
    cout << endl << "The top of the stack is: " << array[top] << endl;
}

void stack :: display()
{
    cout << endl << "[\t";
    for ( int i = 0; i < MAX; i++)
    {
        cout << array[i] << "\t" ;
    }
    cout << "]" << endl;
}

//? Main Function
//? Name of object is : "example"
int main(void)
{
    stack example;
    int input;
    int value;

    do{
        cout << endl << "Choose one operation" << endl;
        cout << "1.Push" << endl << "2.Pop" << endl << "3.Check if empty" << endl << "4.Check if full" <<
        endl << "5.Display top of stack" << endl << "6.Display whole stack" << endl << "7.Exit" << endl;
        cin >> input;

        switch(input)
        {
            case 1:
                cout << endl << "Enter the value to be added" << endl;
                cin >> value;
                example.push(value);
                break;
            
            case 2:
                example.pop();
                example.display();
                break;

            case 3:
                if(example.isempty())
                    cout << endl << "The stack is empty" << endl;
                else
                    cout << endl << "The stack is not empty" << endl;
                break;

            case 4:
                if(example.isfull())
                    cout << endl << "The is full" << endl;
                else
                    cout << endl << "The stack is not full" << endl;
                break;
            
            case 5:
                example.seek();
                break;

            case 6:
                example.display();
                break;
            
            case 7:
                break;
            
            defalt:
                cout << endl << "Wrong option" << endl;
        }
    }while(input != 7);
}