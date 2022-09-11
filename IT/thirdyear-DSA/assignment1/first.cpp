#include<iostream>

using namespace std;

int main(void)
{
    cout << "Which convertion would you prefer" 
    << endl << "1.Celcius to Fahrenheit" 
    << endl << "2.Fahrenhiet to Celcius" << endl;

    int input;
    cin >> input;

    if (input < 1 || input > 2)
    {
        cout << "Invalid Input!" << endl;
        return 1;
    }

    cout << "Enter the temperature :";
    float temp;
    cin >> temp;

    if (input == 1)
        cout << "The temperature in Fahrenheit is : " << (temp*9/5.0) + 32  << endl;

    else 
        cout << "The temperature in Celcius is : " << (temp - 32)*(5.0/9.0) << endl;

}