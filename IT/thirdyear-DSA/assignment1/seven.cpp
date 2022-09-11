#include<iostream>
#define AREA(a,b) a * b
using namespace std;

int main(void)
{
    cout << "Enter the height and widht of the Rectangle respectively" << endl;
    float height , width;

    cin >> height >>width; 
    cout << "Area is : " << AREA(height,width) << endl;   
}