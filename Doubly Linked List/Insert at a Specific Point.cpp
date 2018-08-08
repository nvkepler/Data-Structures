// Task :
//
// Insert an element/node at a Specific Point

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

        node* create_node(int value);
        void insert(int value);
        void display();
        void insert_at_pos(int position, int value);
};

node* list :: create_node(int value)
{
    node* temp = new node;
    temp -> previous = NULL;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

void list :: insert(int value)
{
    node* ptr;
    ptr = create_node(value);
    if(head == NULL)
    {
        head = ptr;
        tail = head;
    }
    else
    {
        tail -> next = ptr;
        ptr -> previous = tail;
        tail = tail -> next;
    }
}

void list :: insert_at_pos(int position, int value)
{
    node *temp = new node;
    temp -> data = value;
    if(position == 0)
    {
        temp -> previous = NULL;
        temp -> next = NULL;
        head = temp;
    }
    else
    {
        node *new_node = new node;
        new_node = head;
        int count = 1;
        while(count != position)
        {
            new_node = new_node -> next;
            count++;
        }
        temp -> next = new_node->next;
        temp -> previous = new_node;
        new_node -> next = temp;
    }
}

void list :: display()
{
    node *temp = new node;
    temp = head;
    if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        temp = head;
        while (temp != NULL)
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
    int n,num,no,pos;
    cout<<"Enter Size of List : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number : ";
        cin>>num;
        l.insert(num);
    }

    cout<<"Enter New Number to add in list : ";
    cin>>no;
    cout<<"Enter its Position : ";
    cin>>pos;
    l.insert_at_pos(pos,no);

    l.display();
    return 0;
}
