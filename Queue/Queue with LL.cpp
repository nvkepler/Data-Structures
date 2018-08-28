// Task :
//
// Make a queue with Linked List

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

class Queue
{
    node *head, *tail, *front, *rear;
    public:
        Queue()
        {
            head = NULL;
            tail = NULL;
            front = NULL;
            rear = NULL;
        }

        node* create_node(int value);
        void insert_element(int);
        void delete_element();
        void display();
};

node* Queue :: create_node(int value)
{
    node *temp = new node;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

void Queue :: insert_element(int value)
{
    node *temp = new node;
    temp = create_node(value);
    if(head == NULL)
    {
        head = temp;
        tail = head;
        front = head;
        rear = tail;
    }
    else
    {
        tail -> next = temp;
        tail = tail -> next;
        rear = tail;
    }
}

void Queue :: delete_element()
{
    node *temp = new node;
    temp = head;
    if(head == NULL)
    {
        cout<<"No element to delete"<<endl;
    }
    else
    {
        temp = head;
        head = head -> next;
        delete temp;
        front = head;
    }
}

void Queue :: display()
{
    node *temp = new node;
    temp = head;
    if(head == NULL)
    {
        cout<<"No Element to Show"<<endl;
    }
    else
    {
        temp = head;
        cout<<"Elements present : ";
        while(temp != NULL)
        {
            cout<<temp -> data<<"  ";
            temp = temp -> next;
        }
        cout<<endl;
    }
}

int main()
{
    Queue q;
    int n,num,choice;
    cout<<"Enter Number of Steps : ";
    cin>>n;

    cout<<"**************************************"<<endl;
    cout<<"   ************* MENU *************  "<<endl;
    cout<<"1 to insert"<<endl;
    cout<<"2 to delete"<<endl;
    cout<<"                ******"<<endl;
    cout<<"**************************************"<<endl;

    for(int i = 0; i<n; i++)
    {
        cout<<"Enter Your Choice : ";
        cin>>choice;
        while(choice < 1 || choice > 2)
        {
            cout<<"Wrong Number Entered... TRY AGAIN"<<endl;
            cout<<"Enter Choice Again : ";
            cin>>choice;
        }
        if(choice == 1)
        {
            cout<<"Enter Number : ";
            cin>>num;
            q.insert_element(num);
        }
        else
        {
            q.delete_element();
        }
        cout<<"--------------------------------"<<endl;
    }
    q.display();

    return 0;
}
