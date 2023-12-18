#include<iostream>
#include<vector>
#include<algorithm>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;

typedef struct rec
{
    char name[20];
    char Birthdate[20];
    char phone[11];
}node;
node temp;

vector<node> v1;
vector<node>::iterator itr;

bool compare(const node &p1,const node &p2)
{
    if(strcmp(p1.name,p2.name)<0)
        return true;
    else
        return false;
}

void Insert()
{
    int n;
    cout<<"How many students to insert?:"<<flush;
    cin>>n;
    cout<<"Enter details"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter name:"<<flush;
        cin>>temp.name;
        cout<<"Enter birth date:"<<flush;
        cin>>temp.Birthdate;
        cout<<"Enter phone no:"<<flush;
        cin>>temp.phone;

        v1.push_back(temp);
    }
}

void Display()
{
    cout<<"Database is:"<<endl;
    cout<<endl;
    cout<<left<<setw(15)<<"Name"<<left<<setw(10)<<"Birthdate"<<left<<setw(10)<<"Phone"<<endl;
    for(itr=v1.begin();itr!=v1.end();itr++)
    {
        cout<<left<<setw(10)<<(*itr).name<<left<<setw(10)<<(*itr).Birthdate<<left<<setw(20)<<(*itr).phone<<left<<setw(10)<<endl;
    }
}

void Search()
{
    char key[25];
    int flag = 0;
    cout<<"Enter name to search:"<<flush;
    cin>>key;
    for(itr=v1.begin();itr!=v1.end();itr++)
    {
        if(strcmp((*itr).name,key)==0)
        {
            flag=1;
            break;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        cout<<"Student is present in the list"<<endl;
    }
    else
    {
        cout<<"Not present"<<endl;
    }
}

void Delete()
{
    char key[20];
    cout<<"Enter name to delete:"<<flush;
    cin>>key;
    for(itr=v1.begin();itr!=v1.end();itr++)
    {
        if(strcmp((*itr).name,key)==0)
        {
            v1.erase(itr);
            cout<<"Name deleted"<<endl;
            break;
        }
        else
        {
            cout<<"Name not in the list"<<endl;
        }
    }
}

void Sort()
{
    sort(v1.begin(),v1.end(),compare);
}

int main()
{
    int choice;
    bool repeat=true;

    while(repeat)
    {
        cout<<endl;
        cout<<"****** MENU ******"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Sort"<<endl;
        cout<<"4. Search"<<endl;
        cout<<"5. Delete"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<endl;

        cout<<"enter your choice:"<<flush;
        cin>>choice;

        switch(choice)
        {
            case 1:
            Insert();
            break;

            case 2:
            Display();
            break;

            case 3:
            Sort();
            break;

            case 4:
            Search();
            break;

            case 5:
            Delete();
            break;

            case 6:
            cout<<"Exiting the code"<<endl;
            repeat=false;
            break;

            default:
            break;
        }
    }
    getch();
    return 0;
}