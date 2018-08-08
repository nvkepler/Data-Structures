// Task :
//
// Insert an element/node at beginning in Doubly Linked list

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

        node *create_node(int value);
        void insert(int value);
        void display();
};

node* list :: create_node(int value)
{
    node *temp = new node;
    temp -> previous = NULL;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

void list :: insert(int value)
{
    node *ptr;
    ptr = create_node(value);
    if(head == NULL && tail == NULL)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        ptr -> next = head;
        head -> previous = ptr;
        head = ptr;
    }
}

void list :: display()
{
    node *temp = new node;
    temp = head;
    if(head == NULL && tail == NULL)
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
    int x,num;
    cout<<"Enter how many numbers to enter in Doubly Linked List : ";
    cin>>x;

    for(int i=0; i<x; i++)
    {
        cout<<"Enter number : ";
        cin>>num;
        l.insert(num);
    }
    l.display();
    return 0;
}
