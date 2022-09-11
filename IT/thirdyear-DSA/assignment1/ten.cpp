#include<iostream>

using namespace std;

class bus
{
    
    public:
    int number;
    bus()
    {
        number = 9923;
    }
    friend void detail();
};

class passanger
{
    
    public:
    string name;
    passanger(string person)
    {
        name = person;
    }
    friend void detail();
};

void detail(bus &a,passanger &b)
{
    cout << "The bus number is : " << a.number << endl;
    cout << "The name of the person is : " << b.name;
}

int main(void)
{
    bus a;
    passanger b("Pratik");

    detail(a,b);
}