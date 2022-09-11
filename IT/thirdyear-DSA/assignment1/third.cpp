#include<iostream>

using namespace std;

char grade(int sum)
{
    char grade;
    if (sum < 50)
        return 'F';
    
    else if (sum < 60)
        return 'E';

    else if ( sum < 70)
        return 'D';

    else if ( sum < 80)
        return 'C';

    else if ( sum < 90)
        return 'B';
    
    else 
        return 'A';
}
class student
{
    public:
    int a;
    int b;
    int c;
};

int main(void)
{
    cout << "How many student do want to record";
    int num;
    cin >> num;

    student *name = new student[num];
    cout << endl << "Enter the subjects of each student" << endl;
    for ( int i = 0; i < num; i++)
    {
        cout << "Enter marks of student " << i + 1 << "\t";
        cin >> name[i].a >> name[i].b >> name[i].c;
    }

    cout << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "For Student " << i << " : " << "Marks: "
        << name[i].a << "\t" << name[i].b << "\t" << name[i].c << "\t"
        << "Grade: " << grade((name[i].a + name[i].b + name[i].c)/3) << endl << endl;
    }
}