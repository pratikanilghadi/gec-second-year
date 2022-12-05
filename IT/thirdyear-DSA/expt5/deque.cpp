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
class deque
{
    node<TYPE> *head;
    node<TYPE> *tail;

    public:
    deque()
    {
        head = NULL;
        tail = NULL;
    }

    void removehead();
    void removetail();
    void add();
    void display();
};

template <class TYPE>
void deque<TYPE>:: removetail()
{
    if (head == NULL)
    {
        cout << "The deque is empty" << endl;
        return;
    }

    node<TYPE> *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    cout << "The value deleted is: " << tail->data << endl;
    delete(tail);
    tail = temp;
}

template <class TYPE>
void deque<TYPE>:: display()
{
    if (head == NULL)
    {
        cout << "The deque is empty" << endl;
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
void deque<TYPE>:: removehead()
{
    if (head == NULL)
    {
        cout << "The deque is empty" << endl;
        return;
    }

    node<TYPE> *temp = head;
    head = head->next;
    delete(temp);
}

template <class TYPE>
void deque<TYPE>:: add()
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
    deque<int> q;
    int choice;
    while (1)
    {
        cout << "1. Add" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Remove tail" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                q.add();
                break;
            case 2:
                q.removehead();
                break;
            case 3:
                q.removetail();
                break;
            case 4:
                q.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
                exit(0);
        }
    }
}