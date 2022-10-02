#include<iostream>
#define MAX 30

using namespace std;

/* ---------SPECIFICATION-----------
    Class "Stack"
    Functions : Push , Pop(The checking funcitonality is inbuilt) , isEmpty , isFull , Display
    Attributes : Status , Array , Top
    Object Name : para
*/ 
//! Class Defination-------------------------------------------------------
class stack{
    private:
        char array[MAX];
        int top;
    
    public:
        bool status;
        stack() { top = -1; for (int i = 0; i < MAX; i++) {array[i] = '*';} status = true;}
        bool isEmpty();
        bool isFull();
        //void Check();
        void Display();
        void pop(char value);
        void push(char value);
};

//! Push Function------------------------------------------------------
void stack :: push(char value)
{
    if( isFull())
    {
        cout << endl << "The expression has more left parenthesis then right" << endl;
        status = false;
    }
    top++;
    array[top] = value;
}

//! Pop Function-------------------------------------------------------
void stack :: pop(char value)
{
    if (isEmpty())
    {
        cout << endl << "The expression has more right parenthesis than left" << endl;
        status = false;
    }

    else if ((value == ')' && array[top] == '(') ||
             (value == '}' && array[top] == '{') || 
             (value == ']' && value == '['))
    {
        array[top] = '*';
        top--;
    }
}

//! isEmpty Function---------------------------------------------------
bool stack :: isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

//! isFull Function-----------------------------------------------------
bool stack :: isFull()
{
    if (top == MAX - 1)
        return true;
    else 
        return false;
}

//! Display Function----------------------------------------------------
void stack :: Display()
{
    cout << endl << "------------" << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << "------------" << endl;
}

//! Main Function-------------------------------------------------------
int main(void)
{
    stack para;
    string express;
    char buffer;
    cout << "Enter the expression to be evaluated" << endl;
    cin >> express;

    for (int i = 0; i < express.length(); i++)
    {
        
        buffer = express[i];
        if (buffer == '(' || buffer == '{' || buffer == '[')
        {
            if (para.isFull())
            {
                para.status = false;
                break;
            }
            para.push(buffer);
        }

        else if (buffer == ')' || buffer == '}' || buffer == ']')
        {
            
            if (para.isEmpty())
            {
                para.status = false;
                break;
            }
            para.pop(buffer);
        }
        else 
            continue;
    }

    if (!para.isEmpty())
    {
        para.status = false;
    }

    //! Check if the code is still functioning properly 
    if (!(para.status))
    {
        cout << "The expression has more opening brackets than closing" << endl;
    }
    else{
        cout << "The expression was evaluated successfully" << endl;
    }
}