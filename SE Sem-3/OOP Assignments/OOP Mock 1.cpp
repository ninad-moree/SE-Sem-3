#include <iostream>
#include <string>
using namespace std;

class Publication
{
private:
string title;
float price;
public:
Publication()
{
title="";
price=0.0;
}

void add_data()
{
cout<<"Enter title:"<<flush;
cin.ignore();
getline(cin,title);
cout<<"Enter price:"<<flush;
cin>>price;
}

void display_data()
{
cout<<"Information is:"<<endl;
cout<<"Title is:"<<title<<endl;
cout<<"Price is:"<<price<<endl;
}
};

class tape : public Publication
{
private:
int playtime;
public:
tape()
{
playtime=0;
}

void add_data()
{
Publication::add_data();
cout<<"Enter play time:"<<flush;
cin>>playtime;
}

void display_data()
{
Publication::display_data();
    try {
    if(playtime<0)
    throw(playtime);
    }
catch(int f)
{
cout<<"Error:Invalid play time:"<<f<<endl;
cout<<"Title:"<<""<<endl;
cout<<"Price:"<<0<<endl;
playtime=0;
}
cout<<"Play time is:"<<playtime<<endl;
}
};

class book : public tape
{
private:
int pages;
public:
book()
{
pages=0;
}

void add_data()
{
Publication::add_data();
cout<<"Enter no of pages:"<<flush;
cin>>pages;
}

void display_data()
{
Publication::display_data();
try{
if(pages<0)
throw(pages);
}
catch(int r)
{
cout<<"Error:Invalid pages:"<<r<<endl;
cout<<"Title:"<<""<<endl;
cout<<"Price:"<<0<<endl;
pages=0;

}
cout<<"Pages are:"<<pages<<endl;
}
};

int main()
{
tape t[10];
book b[10];
int choice;
int book_count=0;
int tape_count=0;

do{
cout<<"*********Menu*********"<<endl;
cout<<"1. Add Book"<<endl;
cout<<"2. Add Tape"<<endl;
cout<<"3. Display Book"<<endl;
cout<<"4. Display Tape"<<endl;
cout<<"5. Exit"<<endl;

cout<<"Enter your choice:"<<flush;
cin>>choice;

switch(choice)
{
case 1:
b[book_count].add_data();
book_count++;
break;

case 2:
t[tape_count].add_data();
tape_count++;
break;

case 3:
for(int j=0;j<book_count;j++)
{
b[j].display_data();
cout<<endl;
}
break;

case 4:
for(int j=0;j<tape_count;j++)
{
t[j].display_data();
cout<<endl;
}
break;

case 5:
cout<<"Exiting the code..."<<endl;
exit(0);

default:
cout<<"Invalid Choice"<<endl;
    }

}while(choice!=5);

return 0;
}