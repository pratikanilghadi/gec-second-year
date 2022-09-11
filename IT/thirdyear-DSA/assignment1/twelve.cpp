#include<iostream>

using namespace std;

class trace
{
    public:
    static int count;
    trace()
    {
        count++;
    }
    int counter()
    {
        return count;
    }
};
int trace:: count = 0;

int main(void)
{
    trace one;
    trace two;
    trace three;
    trace four;

    cout << one.counter() << endl;
    cout << two.counter() << endl;
    cout << three.counter() << endl;
    cout << four.counter() << endl;
}