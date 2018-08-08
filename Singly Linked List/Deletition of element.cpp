// Task :
//
// Delete an element/node in Singly Linked list

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

        node* create_node(int value);
        void insert(int value);
        void display();
        void delete_node(int value);
};

node* list :: create_node(int value)
{
    node* temp = new node;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

void list :: insert(int value)
{
    node* temp;
    temp = create_node(value);
    if(head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
    }
}

void list :: delete_node(int number)
{
    node* temp = new node;
    node* ptr = new node;
    temp = head;
    while(temp->data != number)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr -> next = temp -> next;
    delete temp;
}

void list :: display()
{
    node* temp = new node;
    temp = head;
    if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp -> next;
        }
        cout<<endl;
    }
}

int main()
{
    list l;
    int n,num;
    cout<<"Enter many numbers you want to enter : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number : ";
        cin>>num;
        l.insert(num);
    }

    cout<<"Before Deletition : "<<endl;
    l.display();

    int no;
    cout<<"Enter Number to delete : ";
    cin>>no;
    l.delete_node(no);

    cout<<"After Deletition : "<<endl;
    l.display();
    return 0;
}
