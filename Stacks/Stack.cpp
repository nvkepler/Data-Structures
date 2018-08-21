// Task :
//
// Push and Pop in Stack

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
    int top;
    public:
        int a[MAX];

        Stack()
        {
            top = -1;
        }

        bool push(int x);
        int pop();
        bool isEmpty();
        void display();
};

bool Stack::push(int x)
{
    if (top >= (MAX-1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout<<x<<" pushed"<<endl;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        cout<<x<<" poped"<<endl;
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::display()
{
    if(top > -1)
        {
        for(int i=0; i<top; i++)
        {
            cout<<a[i]<<"  ";
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
    struct Stack s;
    int num, choice,n;

    cout<<"Enter Number of Steps : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Choice :\n1 for PUSH\t2 for POP : ";
        cin>>choice;
        while(choice < 0 && choice > 3)
        {
            cout<<"Wrong Choice Entered...TRY AGAIN...\n";
            cin>>choice;
        }
        if(choice == 1)
        {
            cout<<"Enter Number to Push : ";
            cin>>num;
            s.push(num);
        }
        else
        {
            s.pop();
        }
    }
    
    s.display();

    return 0;
}
