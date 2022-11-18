#include <iostream>

using namespace std;

template <class VAR>
class node 
{
    public:
    VAR data;
    node *next;
    node(VAR value)
    {   
        data = value;
        next = NULL;
    }
};

template <class TYPE>
class queue
{
    node<TYPE> *head;
    node<TYPE> *tail;

    public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }

    void remove();
    void add();
    void display();
};

template <class TYPE>
void queue<TYPE>:: display()
{
    if (head == NULL)
    {
        cout << "The queue is empty" << endl;
        return;
    }

    node<TYPE> *temp = head;
    cout << "[ ";
    while (temp != NULL)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << "]" << endl;;
}

template <class TYPE>
void queue<TYPE>:: remove()
{
    if (head == NULL)
    {
        cout << "The queue is empty" << endl;
        return;
    }

    node<TYPE> *temp = head;
    head = head->next;
    delete(temp);
}

template <class TYPE>
void queue<TYPE>:: add()
{
    int value;
    cout << "Enter the data to be stored: ";
    cin >> value;

    node<TYPE> *p = new node<TYPE>(value);

    if (head == NULL)
    {
        head = p;
        head->next = tail;
        return;
    } 

    if (tail == NULL)
    {
        head->next = p;
        tail = p;
        return;
    }

    tail->next = p;
    tail = p;
}

int main()
{
    queue<int> q;
    int choice;
    while (1)
    {
        cout << "1. Add" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                q.add();
                break;
            case 2:
                q.remove();
                break;
            case 3:
                q.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
}