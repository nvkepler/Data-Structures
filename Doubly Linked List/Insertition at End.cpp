// Task :
//
// Insertition of an element/node at end in Doubly Linked List

#include <iostream>
using namespace std;

struct node
{
    struct node* previous;
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

        node* create_node(int);
        void insert(int);
        void display();
};

node* list :: create_node(int value)
{
    node* temp = new node;
    temp -> previous = NULL;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
};

void list :: insert(int value)
{
    node *temp;
    temp = create_node(value);
    if(head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail -> next = temp;
        temp -> previous = tail;
        tail = temp;
    }
}

void list :: display()
{
    node *temp = new node;
    if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            cout<<temp -> data<<"\t";
            temp = temp -> next;
        }
        cout<<endl;
    }
}

int main()
{
    list l;
    int n,num;
    cout<<"Enter List Size : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number : ";
        cin>>num;
        l.insert(num);
    }
    l.display();
    return 0;
}
