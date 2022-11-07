#include <iostream>

using namespace std;

template <class VARIABLE>
class node
{
    public:
    VARIABLE data;
    node *next;
    node(VARIABLE value) {data = value; next = NULL;}   
};

template <class TYPE>
class stack
{
    node<TYPE> *top;

    public:
    stack() {top = NULL;}
    void push();
    void pop();
    void display();
};

template <class TYPE>
void stack<TYPE>:: push()
{
    TYPE value;
    cout << "Enter the data to be stored: " << endl;
    cin >> value;

    node<TYPE> *p = new node<TYPE>(value);
    
    if (top == NULL)
    {
        top = p;
    }

    else
    {
        p->next = top;
        top = p;
    }
}

template <class TYPE>
void stack<TYPE>:: pop()
{
    if (top == NULL)
    {
        cout << "The stack is already empty" << endl;
        return;
    }

    node<TYPE> *temp;
    temp = top;
    top = top->next;
    cout << "The value deleted is :" << temp->data << endl;
    delete(temp);
}

template <class TYPE>
void stack<TYPE>:: display()
{
    if (top == NULL)
    {
        cout << "The stack is empty" << endl;
        return;
    }

    node<TYPE> *temp = top;
    cout << "[ ";
    while (temp != NULL)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << "]" << endl;;
}

int main()
{
    stack<string> s;
    int choice;
    
    while(1)
    {
        cout << "Enter your choice: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            s.push();
            break;

            case 2:
            s.pop();
            break;

            case 3:
            s.display();
            break;

            case 4:
            cout << "Exiting the program" << endl;
            exit(0);
            break;

            default:
            cout << "Invalid Option" << endl;
        }
    }
}