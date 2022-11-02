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
class stackpre
{
    private:
    int top;
    int evtop;
    bool isnumber;
    int evstack[MAX];
    string stack[MAX];

    public:
    stackpre(){top = -1;evtop = -1;isnumber = false; for (int i = 0; i < MAX; i++) { stack[i] = " ";}}
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
void stackpre :: evaluate(string expression)
{
    if(isnumber)
    {
        string buffer;
        for( int i = expression.length() - 1; i >= 0; i--)
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
void stackpre :: evmerge(char sign)
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
void stackpre :: check(string expression)
{
    int index = expression.length() - 1; 
    if (expression[index] >= '0' && expression[index] <= '9')
        isnumber = true;
    string buffer;
    for( int i = expression.length() - 1; i >= 0; i--)
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
string stackpre :: pop()
{
    string buffer;
    buffer = stack[top];
    stack[top] = " ";
    top--;
    return buffer;
}

//* Defination for push-------------------------------------------------------
void stackpre :: push(string buffer)
{
    top++;
    stack[top] = buffer;
}

//* Defination for merge------------------------------------------------------
//? Pops the two topmost elements and combines it with parenthesis and the recived 
//? operator and pushes the obtained expression onto the stack
void stackpre :: merge(string buffer)
{
    string first, second, expression;
    first = pop();
    second = pop();
    expression = "(" + first + buffer + second + ")";
    push(expression);
}

//* Defination for Display----------------------------------------------------
void stackpre :: display()
{
    cout << stack[top];
    cout << endl;
}

//! Main Function Defination---------------------------------------------------
int main(void)
{
 stackpre stack;
 string expression;

 cout << "Enter the expression" << endl;
 cin >> expression;

 stack.check(expression);
 stack.display();
 stack.evaluate(expression);
}