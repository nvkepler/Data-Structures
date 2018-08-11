// Task :
//
// Reverse of Singly Linked List

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
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

        node *create_node(int);
        void insert(int);
        void display();
        void reverse();
};

node* list :: create_node(int value)
{
    node *temp = new node;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

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
        tail = tail -> next;
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
        while(temp != NULL)
        {
            cout<<temp-> data<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

void list :: reverse()
{
    node *temp = new node;
    temp = NULL;
    tail = head;

    if(head == NULL)
    {
        cout<<"No Elements in List to Reverse"<<endl;
    }
    else
    {
        while(tail->next != NULL)
        {
            temp = tail->next;
            if(temp -> next == NULL)
            {
                tail -> next = NULL;
            }
            else
            {
                tail -> next = temp -> next;
            }
            temp -> next = head;
            head = temp;
        }
    }
}

int main()
{
    list l;
    int n,num,count = 0;
    cout<<"Enter List Size : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number : ";
        cin>>num;
        l.insert(num);
        count++;
    }

    cout<<"Elements in the List : ";
    l.display();

    cout<<"After Reversing : ";
    l.reverse();
    if(count > 1)
    {
        l.display();
    }

    return 0;
}
