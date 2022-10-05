#include<iostream>
#define MAX 50
#include<cmath>

using namespace std;

/*//!----------------------Class 'stackpre'------------------------------------
//?Data Members: top - stores the index , stack - the stack containing the final infix expression
//?Member Functions: Push() - Push a given expression on the the final infix stack ,
//?                  Pop() - Pops the top most element in the stack and returns the expression
//?                  Merge() - takes the operator , pops two elements and merges them with parenthesis
//?                  Check() - iterates through whole expression and 
//?                  Display() - displays the stack
*///!--------------------------------------------------------------------------
class stackpost
{
    private:
    int top;
    int evtop;
    int evstack[MAX];
    string stack[MAX];
    bool isnumber;

    public:
    stackpost(){top = -1;evtop = -1; isnumber = false; for (int i = 0; i < MAX; i++) { stack[i] = " ";}}
    string pop();
    void evmerge(char sign);
    void evaluate(string expression);
    void push(string buffer);
    void merge(string buffer);
    void check(string expression);
    void display();
};

//* Defination for evaluate()----------------------------------------------------------
//? First check if a number was there in the expression or not
//? Then evaluates the expression
void stackpost :: evaluate(string expression)
{
    if(isnumber)
    {
        string buffer;
        for( int i = 0; i < expression.length(); i++)
        {
            buffer = expression[i];
            char contain = expression[i];

            if((contain >= '0' && contain <= '9'))
            {
                evtop++;
                evstack[evtop] = (int) contain - 48;
            }
            else if ( contain == '+' || contain == '-' || contain == '/' || contain == '*' 
                  || contain == '^')
            {
                evmerge(contain);
            }
            else 
            {
                continue;
            }
        }
        int answer = evstack[0];
        cout << endl << "The evalution is:" << answer << endl;
    }
    else
    {
        return;
    }
}

//* Defination for evmerge()-------------------------------------------------
//? Evaluate the two digit in the stack
void stackpost :: evmerge(char sign)
{
    int value = 0;
    if (sign == '+')
    {
        value = evstack[evtop];
        evtop--;
        value += evstack[evtop];
        evstack[evtop] = value;
    }

    else if (sign == '*')
    {
        value = evstack[evtop];
        evtop--;
        value *= evstack[evtop];
        evstack[evtop] = value;
    }

    else if (sign == '/')
    {
        value = evstack[evtop];
        evtop--;
        value /= evstack[evtop];
        evstack[evtop] = value;
    }

    else if (sign == '-')
    {
        value = evstack[evtop];
        evtop--;
        value -= evstack[evtop];
        evstack[evtop] = value;
    }

    else
    {
        value = evstack[evtop];
        evtop--;
        value = pow(value,evstack[evtop]);
        evstack[evtop] = value;
    }


}

//* Defination for check()----------------------------------------------------
//? Iterates throught the whole expression and checks if the character is an
//? operator or an operand and calls push or merge as required
void stackpost :: check(string expression)
{
    if((expression[0] >= '0') && (expression[0] <= '9'))
    isnumber = true;

    string buffer;
    for( int i = 0; i < expression.length(); i++)
    {
        buffer = expression[i];
        char contain = expression[i];
        if( (contain >= 'a' && contain <= 'z') || (contain >= 'A' && contain <= 'Z')
            || (contain >= '0' && contain <= '9'))
        {
            push(buffer);
        }
        else if ( contain == '+' || contain == '-' || contain == '/' || contain == '*' 
                  || contain == '^')
        {
            merge(buffer);
        }
        else 
        {
            continue;
        }
    }
}

//* Defination for pop--------------------------------------------------------
//? Stores the topmost element in a variable and removes the topmost element 
//? and Returns the variable stored
string stackpost :: pop()
{
    string buffer;
    buffer = stack[top];
    stack[top] = " ";
    top--;
    return buffer;
}

//* Defination for push-------------------------------------------------------
void stackpost :: push(string buffer)
{
    top++;
    stack[top] = buffer;
}

//* Defination for merge------------------------------------------------------
//? Pops the two topmost elements and combines it with parenthesis and the recived 
//? operator and pushes the obtained expression onto the stack
void stackpost :: merge(string buffer)
{
    string first, second, expression;
    first = pop();
    second = pop();
    expression = "(" + second + buffer + first + ")";
    push(expression);
}

//* Defination for Display----------------------------------------------------
void stackpost :: display()
{
    cout << stack[top];
    cout << endl;
}

//! Main Function Defination---------------------------------------------------
int main(void)
{
 stackpost stack;
 string expression;

 cout << "Enter the expression" << endl;
 cin >> expression;

 stack.check(expression);
 stack.display();
 stack.evaluate(expression);
}