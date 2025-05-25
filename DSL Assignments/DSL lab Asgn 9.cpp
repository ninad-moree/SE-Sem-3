#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
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
    if(top==-1)
        return 1;
    else
        return 0;
}

bool Stack::isFull()
{
    if(top==MAX-1)
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

int main()
{    
    char expr[50];
    Stack st;
    cout<<"Enter  Expression: "<<flush;
    cin>>expr;
    if (st.checkParenthesis(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    getch();
    return 0;
}