#include<iostream>
#define MAX 30

using namespace std;

//! Class defination
class stackpre
{
    private:
    int top_stack;
    int top_pre;
    char stack[MAX];
    char pre[MAX];

    public:
    bool status;
    stackpre(){top_stack = -1;top_pre = -1;for (int i = 0; i < MAX; i++){pre[i] = ' ';}}
    void check(string expression);
    void push_pre(char buffer);
    void push_stack(char buffer);
    void pop();
    bool isempty();
    bool isfull();
    void display();
};

//! Push_Pre--------------------------------------------------------------
void stackpre :: push_pre(char buffer)
{
    top_pre++;
    pre[top_pre] = buffer;
}

//! Push_Stack------------------------------------------------------------
void stackpre :: push_stack(char buffer)
{
    
}

//! Pop-------------------------------------------------------------------
void stackpre :: pop()
{
    if (isempty())
    {
        cout << "Something went wrong" << endl;
        status = false;
        return;
    }

    top_pre++;
    pre[top_pre] = stack[top_stack];
    top_stack--;
}

//! isempty---------------------------------------------------------------
bool stackpre :: isempty()
{
    if (top_stack == -1)
        return true;
    else
        return false;
}

//! isfull----------------------------------------------------------------
bool stackpre :: isfull()
{
    if (top_stack == MAX - 1)
        return true;
    else
        return false;
}

//! Check-----------------------------------------------------------------
void stackpre :: check(string expression)
{
    char buffer;

    for (int i = expression.length() - 1; i >= 0; i--)
    {
        buffer = expression[i];

        if(buffer == ' ')
            continue;
        
        else if ((buffer >= 'A' && buffer <= 'Z') || (buffer >= 'a' && buffer <= 'z') || (buffer >= '0' && buffer <= '9'))
        {
            push_pre(buffer);
        }

        else if(buffer == '*' || buffer == '/' || buffer == '+' || buffer == '-' || buffer == '^' || buffer == '(' || buffer == ')')
        {
            push_stack(buffer);
        }

        else
        {
            cout << "Expression Invalid" << endl;
            status = false;
        }

        if (!(status))
        {
            break;
        }
    }

    if(status)
    {
        while(!isempty())
        {
            pop();
        }
    }
}

//! Display---------------------------------------------------------------
void stackpre :: display()
{
    cout << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << pre[i];
    }
    cout << endl;
}

//! Main function---------------------------------------------------------
int main(void)
{
    string expression;
    stackpre pre;

    cout << "Enter the expression" << endl;
    cin >> expression;

    pre.check(expression);

    if (pre.status)
        pre.display();
    else
        cout << "Invalid Expression" << endl;
}