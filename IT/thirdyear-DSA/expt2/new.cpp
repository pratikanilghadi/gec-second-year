#include<iostream>
#define MAX 30

using namespace std;

//! Class Defination------------------------------------------------------------
class stackpost
{
    private:
    int top_stack;
    int top_post;
    char stack[MAX];
    char post[MAX];

    public:
    bool status;
    stackpost() {top_stack = -1;top_post = -1;status = true;for(int i= 0; i < MAX; i++){post[i]=' ';}}
    bool isempty();
    bool isfull();
    void check(string expression);
    void push_stack(char buffer);
    void push_post(char buffer);
    void pop();
    void display();
};

//! Push_Stack------------------------------------------------------------------
void stackpost :: push_stack(char buffer)
{
    if ( buffer == ')')
    {
        while(stack[top_stack] != '(')
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

    else if ( buffer == '^')
    {
            top_stack++;
            stack[top_stack] = buffer;
    }

    else if ( buffer == '*' || buffer == '/')
    {
        while ( stack[top_stack] == '^')
        {
            pop(); 
        }
        top_stack++;
        stack[top_stack] = buffer;
    }

    else if ( buffer == '+' || buffer == '-')
    {
        while ( stack[top_stack] == '^' || stack[top_stack] == '*' || stack[top_stack] == '/')
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

//! Push_Post-------------------------------------------------------------------
void stackpost :: push_post(char buffer)
{
    top_post++;
    post[top_post] = buffer;
}

//! Pop-------------------------------------------------------------------------
void stackpost :: pop()
{
    if (isempty())
    {
        status = false;
        cout << "Issue in Popping" << endl;
        return;
    }

    top_post++;
    post[top_post] = stack[top_stack];
    top_stack--;

}

//! isempty---------------------------------------------------------------------
bool stackpost :: isempty()
{
    if (top_stack == -1)
        return true;
    else 
        return false;
}

//! isfull----------------------------------------------------------------------
bool stackpost :: isfull()
{
    if (top_stack == MAX - 1)
        return true;
    else
        return false;
}

//! Display---------------------------------------------------------------------
void stackpost :: display()
{
    for ( int i = 0; i < MAX; i++)
        cout << post[i];
    cout << endl;
}

//! Check-----------------------------------------------------------------------
void stackpost :: check(string expression)
{
    char buffer;

    for (int i = 0; i < expression.length(); i++)
    {
        buffer = expression[i];
        //? Checks for blank space
        if(buffer == ' ')
            continue;
        
        else if ((buffer >= 'A' && buffer <= 'Z') || (buffer >= 'a' && buffer <= 'z') || (buffer >= '0' && buffer <= '9'))
        {
            push_post(buffer);
        }

        else if(buffer == '*' || buffer == '/' || buffer == '+' || buffer == '-' || buffer == '^' || buffer == '(' || buffer == ')')
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
    if(status)
    {
        while(!isempty())
        {
            pop();
        }
    }
}

//! Main Function---------------------------------------------------------------
int main(void)
{
    string expression;
    stackpost post;

    cout << "Enter the expression" << endl;
    cin >> expression;

    post.check(expression);
    if (post.status)
        post.display();
    else
        cout << "The code has an error" << endl;

}