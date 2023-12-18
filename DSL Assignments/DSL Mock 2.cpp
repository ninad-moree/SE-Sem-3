/*==============================
   Name - Ninad More
   Roll No - 21253
   Title -Parenthesis Checking
  ==============================*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 50  
      
class Stack
{
    char s[MAX];
    int top;

    public:
    Stack()
    {
        top=-1;
    }

    void push(char ch);
    char pop();
    bool isEmpty();
    bool isFull();
    bool checkParenthesis(char expr[]);
};

bool Stack::isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

bool Stack::isFull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

void Stack::push(char ch)
{
    if(!isFull())
    {
        top++;
        s[top]=ch;
    }
}

char Stack::pop()
{
    if(!isEmpty())
    {
        char ch=s[top];
        top--;
        return ch;
    }
    else
        return '\0';
}

bool Stack::checkParenthesis(char expr[])
{
    char x;

    for (int i=0; expr[i]!='\0'; i++)
    {
        if (expr[i]=='(' || expr[i]=='[' || expr[i]=='{')
        {
            push(expr[i]);
            continue;
        }

        if (isEmpty())
           return false;

        switch (expr[i])
        {
            case ')':
                x = pop();
                if (x=='{' || x=='[')
                    return false;
                break;

            case '}':
                x = pop();
                if (x=='(' || x=='[')
                    return false;
                break;

            case ']':
                x = pop();            
                if (x =='(' || x == '{')
                    return false;
                break;
        }
    }
    return (isEmpty());
}

void indexPosition(char expr[])
{
    
}

int main()
{    
    char expr[50];
    Stack st;

    int choice;
    bool repeat = true;

    while(repeat)
    {
        cout<<endl;
        cout<<"****** MENU ******"<<endl;
        cout<<"1. Expression"<<endl;
        cout<<"2. Exit the code"<<endl;
        cout<<endl;
        cout<<"Enter your choice:"<<flush;
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1:
                cout<<"Enter your Expression: "<<flush;
                cin>>expr;

                if (st.checkParenthesis(expr))
                    cout<<"Expression is balanced"<<endl;
                else
                    cout<<"Expression is not balanced"<<endl;
                break;

            case 2:
                cout<<"Exiting the code...."<<endl;
                repeat = false;
                break;

            default:
                cout<<"Enter valid input"<<endl;
                break;
        }
    }
    return 0;
}

/*
Output:
   (){}{[()]}
   Expression is balanced

   ({)[]
   Expression is not balanced
*/