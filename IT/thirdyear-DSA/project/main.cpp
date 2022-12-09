// A todo application in c++ using priotity queue

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int give_month(string month1)
{
    if (month1 == "Jan") return 1;
    else if (month1 == "Feb") return 2;
    else if (month1 == "Mar") return 3;
    else if (month1 == "Apr") return 4;
    else if (month1 == "May") return 5;
    else if (month1 == "Jun") return 6;
    else if (month1 == "Jul") return 7;
    else if (month1 == "Aug") return 8;
    else if (month1 == "Sep") return 9;
    else if (month1 == "Oct") return 10;
    else if (month1 == "Nov") return 11;
    else return 12;
}

string get_time()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    return dt;
}

class node
{
    public:
    string task;
    string priority;
    bool status;
    string time;
    string due_time;
    node *next;
    int level;
    node()
    {
        status = false;
        next = NULL;
        level = 0;
    }
};

class todo_queue
{
    private:
    node *head;
    node *tail;

    public:
    todo_queue()
    {
        head = NULL;
        tail = NULL;
    }

    void greet();
    void start();
    void add();
    void add(node *temp);
    void view();
    void update();
    node* extract(node *current);
};

//! -------------------------------VOID UPDATE()---------------------------------!
/*! 
    This function updates the status of the task
*/
void todo_queue:: update()
{
    system("cls");
    node* current = head;
    if (current == NULL)
    {
        cout << "No tasks to display" << endl;
        return;
    }

    int count = 0;
    while (current != NULL)
    {
        count++;
        cout << count << ". " << current->task << endl;
        cout << "Priority: " << current->priority << "\t" << "Due time: " << current->due_time << "\t" << "Status: " << current->status << endl;
        cout << endl;
    }

    cout << "Enter the task number to update: ";
    int task_number;
    cin >> task_number;
    current = head;
    for (int i = 1; i < task_number; i++)
    {
        current = current->next;
    }
    node *temp = extract(current);
    
    cout << "What is the status of the task? " << endl;
    cout << "1. Completed" << endl;
    cout << "2. Incomplete" << endl;
    int stat;
    cin >> stat;
    if (stat == 1)
    {
        temp->status = true;
    }
    else
    {
        temp->status = false;
    }

    if (temp->status == true)
    {
        delete(temp);
        return;
    }

    cout << "Would you want to change the priority of the task? " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter the new priority of the task: ";
        string priority;
        cin >> priority;
        temp->priority = priority;
    }

    cout << "Would you want to change the due time of the task? " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;

    if (choice == 1)
    {
        add(temp);
    }

    return;
}

//! -------------------------------VOID EXRACT()---------------------------------!
/*! 
    This function removes the task from the queue and returns the task node
*/
node *todo_queue:: extract(node *current)
{
    node *temp = current;
    current = current->next;
    return temp;
}


//! -------------------------------VOID VIEW()---------------------------------!
/*! 
    This function displays the tasks in the queue
*/
void todo_queue:: view()
{
    system("cls");
    node *current = head;
    if (current == NULL)
    {
        cout << "No tasks to display" << endl;
        return;
    }

    int count = 0;
    while (current != NULL)
    {
        count++;
        cout << count << ". " << current->task << endl;
        cout << "Priority: " << current->priority << "\t" << "Due time: " << current->due_time << "\t" << "Status: " << current->status << endl;
        cout << endl;
        current = current->next;
    }
}

//! -------------------------------VOID ADD() modded---------------------------------!
/*! 
    This function adds a task to the queue
*/
void todo_queue:: add(node *temp)
{
    cout << "Enter the due time of the task in the format dd/mm/yyyy " << endl;
    cout << "Enter the date: ";
    int date;
    cin >> date;
    cout << "Enter the month: ";
    int month;
    cin >> month;
    cout << "Enter the year: ";
    int year;
    cin >> year;

    string due_time = to_string(date) + "/" + to_string(month) + "/" + to_string(year);

    string time = get_time();
    // seperate each word from the string into individual strings
    string month1 = time.substr(4, 3);
    string date1 = time.substr(8, 2);
    string year1 = time.substr(20, 4);
    
    time = month1 + " " + date1 + " " + year1;

    temp->due_time = due_time;
    temp->status = false;
    temp->time = time;
    int diff_year = stoi(year1) - year;
    int diff_month = give_month(month1) - month;
    int diff_date = stoi(date1) - date;
    int level = diff_year * 365 + diff_month * 30 + diff_date;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        node *current = head;
        if (level < current->level)
        {
            temp->next = head;
            head = temp;
        }

        else
        {
            while (current->next != NULL && level > current->next->level)
            {
                current = current->next;
            }

            temp->next = current->next;
            current->next = temp;
        }
    }
}

//! -------------------------------VOID ADD()---------------------------------!
/*! 
    This function adds a task to the queue
*/
void todo_queue:: add()
{
    cout << "Enter the task: "; 
    string task;
    cin >> task;

    cout << "Enter the priority of the task: ";
    string priority;
    cin >> priority;

    cout << "Enter the due time of the task in the format dd/mm/yyyy " << endl;
    cout << "Enter the date: ";
    int date;
    cin >> date;
    cout << "Enter the month: ";
    int month;
    cin >> month;
    cout << "Enter the year: ";
    int year;
    cin >> year;

    string due_time = to_string(date) + "/" + to_string(month) + "/" + to_string(year);

    string time = get_time();
    // seperate each word from the string into individual strings
    string month1 = time.substr(4, 3);
    string date1 = time.substr(8, 2);
    string year1 = time.substr(20, 4);
    
    time = month1 + " " + date1 + " " + year1;

    node *temp = new node;
    temp->task = task;
    temp->priority = priority;
    temp->due_time = due_time;
    temp->status = false;
    temp->time = time;
    int diff_year = stoi(year1) - year;
    int diff_month = give_month(month1) - month;
    int diff_date = stoi(date1) - date;
    int level = diff_year * 365 + diff_month * 30 + diff_date;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        node *current = head;
        if (level < current->level)
        {
            temp->next = head;
            head = temp;
        }

        else
        {
            while (current->next != NULL && level > current->next->level)
            {
                current = current->next;
            }

            temp->next = current->next;
            current->next = temp;
        }
    }
}
//! -------------------------------VOID START()---------------------------------!
/*! 
    This function displays the menu and calls the functions based on the user's choice
*/
void todo_queue:: start()
{
    int choice;
    do
    {
        system("cls");
        cout << "1. Add a task" << endl;
        cout << "2. View the tasks" << endl;
        cout << "3. Update the status of the task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            view();
            break;
        case 3:
            update();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);
}


//! -------------------------------VOID GREET()---------------------------------!
/*!
    This function greets the user and displays the welcome message and the name of the developers
*/
void todo_queue::greet()
{
    system("cls");
    for (int i = 0; i < 150; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t Welcome to the Todo application" << endl;
    cout << "\t\t\t\t\t\tYou can add, delete, update and view your tasks" << endl;
    cout << "\t\t\t\t\t\t\t   Press any key to continue" << endl;
    cout << endl << endl << endl;
        for (int i = 0; i < 150; i++)
    {
        cout << "-";
    }
    cout << endl;
    cin.get();
    system("cls");
    cout << "This Application gives you 3 options:" << endl;
    cout << "1. Add a task , this will be automatically sorted based on the urgency of the task" << endl;
    cout << "2. View the tasks, this will show all the pending task which are to be done" << endl;
    cout << "3. Update the status of the task, this will update the status of the task " << endl;
    cout << endl << endl << endl;
    cout << "This Project was made by: Pratik Ghadi and Madhure Komarpant" << endl;
    //Sleep to make the program wait for 3 seconds
    Sleep(3000);
    system("cls");
}

int main()
{
    todo_queue object;
    object.greet();
    Sleep(3);
    object.start();
    return 0;
}