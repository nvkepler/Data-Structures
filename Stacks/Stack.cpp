#include <iostream>
using namespace std;

class Stack
{
    int top,MAX;
    public:
        int arr[20];

        Stack()
        {
            top = -1;
            MAX = 20;
        }

        void push(int);
        void pop();
        void display();
};

void Stack :: push(int value)
{
    if(top >= MAX)
    {
        cout<<"Overflow Occured"<<endl;
    }
    else
    {
        arr[++top] = value;
        if(top > -1)
        {
            cout<<"Stack is : ";
            for(int i=0; i<=top; i++)
            {
                cout<<arr[i]<<"  ";
            }
            cout<<endl;
        }
    }
}

void Stack :: pop()
{
    if(top < 0)
    {
        cout<<"Underflow Occured"<<endl;
    }
    else
    {
        top = top-1;
        cout<<"Stack is : ";
        for(int i=0; i<=top; i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
}

void Stack :: display()
{
    if(top > -1)
    {
        cout<<"Final Result : ";
        for(int i=0; i<=top; i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"No Elements to show"<<endl;
    }
}

int main()
{
    Stack s;
    int n,choice,number;
    cout<<"Enter Number of Steps : ";
    cin>>n;

    cout<<"***************  MENU  ***************"<<endl;
    cout<<"Press 1 to PUSH"<<endl;
    cout<<"Press 2 to POP"<<endl;
    cout<<"**************************************"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Your Choice : ";
        cin>>choice;

        while(choice < 1 || choice > 2)
        {
            cout<<"Wrong Choice Entered... TRY AGAIN"<<endl;
            cout<<"Enter Your Choice : ";
            cin>>choice;
        }

        if(choice == 1)
        {
            cout<<"Enter Number : ";
            cin>>number;
            s.push(number);
            cout<<"*****************************"<<endl;
        }
        else if(choice == 2)
        {
            s.pop();
            cout<<"*****************************"<<endl;
        }
    }

    s.display();

    return 0;
}
