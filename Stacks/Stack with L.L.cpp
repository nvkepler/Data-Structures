// Task :
//
// Stack using Singly Linked List

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

class list
{
    node *head, *tail;
    public:
        list()
        {
            head = NULL;
            tail = NULL;
        }

        node *create_node(int value);
        void push(int value);
        void display();
        void pop();
};

node* list :: create_node(int value)
{
    node *temp = new node;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

void list :: push(int value)
{
    node *p;
    p = create_node(value);
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        p -> next = head;
        head = p;
    }
}

void list :: display()
{
    node *temp = new node;
    temp = head;
    if(head == NULL)
    {
        cout<<"Empty Stack"<<endl;
    }
    else
    {
        temp = head;
        cout<<"Elements in Stack : "<<endl;
        while(temp != NULL)
        {
            cout<<temp -> data<<"\t";
            temp = temp -> next;
        }
        cout<<endl;
    }
}

void list :: pop()
{
    int flag = 0;
    if(head == NULL)
    {
        cout<<"Underflow"<<endl;
    }
    node* temp = new node;
    temp = head;
    head = head->next;
    delete temp;
}

int main()
{
    list l;
    int x,num;
    cout<<"Enter Steps : ";
    cin>>x;
    int choice;
    cout<<"Enter Choice : \n1 for push\t2 for pop : "<<endl;
    for(int i=0; i<x; i++)
    {
        cout<<"Enter Your Choice : ";
        cin>>choice;
        while(choice < 1 && choice > 2)
        {
            cout<<"Wrong Choice Entered... TRY AGAIN"<<endl;
            cout<<"Enter Your Choice : ";
            cin>>choice;
        }
        if(choice == 1)
        {
            cout<<"Enter Number : ";
            cin>>num;
            l.push(num);
        }
        else
        {
            l.pop();
        }
    }
    l.display();
    return 0;
}
