#include<iostream>
#include<cstring>
#define MAX 10

using namespace std;

class stackpre
{
private:
    int top_stack;
    int top_pre;
    char stack[MAX];
    char pre[MAX];

public:
    bool status;
    stackpre()
    {
        top_stack = -1;
        top_pre = -1;
        status = true;
        for (int i = 0; i < MAX; i++)
        {
            pre[i] = ' ';
        }
    }
    bool isempty();
    bool isfull();
    void check(string expression);
    void push_stack(char buffer);
    void push_pre(char buffer);
    void pop();
    void display();
};

//! Push_Stack------------------------------------------------------------------
void stackpre ::push_stack(char buffer)
{
    if (buffer == ')')
    {
        while (stack[top_stack] != '(')
        {
            if (isempty())
            {
                cout << "Too Many Parenthesis" << endl;
                break;
            }
            pop();
        }
        top_stack--;
    }

    else if (buffer == '^')
    {
        top_stack++;
        stack[top_stack] = buffer;
    }

    else if (buffer == '*' || buffer == '/')
    {
        while (stack[top_stack] == '^')
        {
            pop();
        }
        top_stack++;
        stack[top_stack] = buffer;
    }

    else if (buffer == '+' || buffer == '-')
    {
        while (stack[top_stack] == '^' || stack[top_stack] == '*' || stack[top_stack] == '/')
        {
            pop();
        }
        top_stack++;
        stack[top_stack] = buffer;
    }

    else
    {
        if (isempty())
        {
            top_stack++;
            stack[top_stack] = buffer;
        }
        else
        {
            pop();
            top_stack++;
            stack[top_stack] = buffer;
        }
    }
}

//! Push_pre-------------------------------------------------------------------
void stackpre ::push_pre(char buffer)
{
    top_pre++;
    pre[top_pre] = buffer;
}

//! Pop-------------------------------------------------------------------------
void stackpre ::pop()
{
    if (isempty())
    {
        status = false;
        cout << "Issue in Popping" << endl;
        return;
    }

    top_pre++;
    pre[top_pre] = stack[top_stack];
    top_stack--;
}

//! isempty---------------------------------------------------------------------
bool stackpre ::isempty()
{
    if (top_stack == -1)
        return true;
    else
        return false;
}

//! isfull----------------------------------------------------------------------
bool stackpre ::isfull()
{
    if (top_stack == MAX - 1)
        return true;
    else
        return false;
}

//! Display---------------------------------------------------------------------
void stackpre ::display()
{
    string exp=strrev(pre);
    cout << exp;
}

//! Check-----------------------------------------------------------------------
void stackpre ::check(string expression)
{
    char buffer;

    for (int i = 0; i < expression.length(); i++)
    {
        buffer = expression[i];
        //? Checks for blank space
        if (buffer == ' ')
            continue;

        else if ((buffer >= 'A' && buffer <= 'Z') || (buffer >= 'a' && buffer <= 'z') || (buffer >= '0' && buffer <= '9'))
        {
            push_pre(buffer);
        }

        else if (buffer == '*' || buffer == '/' || buffer == '+' || buffer == '-' || buffer == '^' || buffer == '(' || buffer == ')')
        {
            push_stack(buffer);
        }

        else
        {
            cout << "Expression Invalid" << endl;
        }

        if (!(status))
        {
            break;
        }
    }
    if (status)
    {
        while (!isempty())
        {
            pop();
        }
    }
}

//-------MAIN------------------------------
int main()
{
    string InfixExp;
    stackpre obj;
    cout<<"Enter the Expression"<<endl;
    cin>>InfixExp;
    obj.check(InfixExp);
    obj.display();
}
