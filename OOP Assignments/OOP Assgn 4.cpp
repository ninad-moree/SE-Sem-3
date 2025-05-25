#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main() {
    fstream f;
    f.open("Ninad.txt",ios::out);

    if (!f) 
        cout<<"Error while creating file"<<endl;
    else {
        cout<<"File created"<<endl;
        f<<"Welcome to Pune! This is Ninad. Ninad Loves circket?"<<endl;
    }

    string y;
    fstream file1("Ninad.txt");
    while(getline(file1,y)) {
        cout<<y<<endl;
    }

    string curr;
    int count;
    fstream file2("Ninad.txt",ios::in);
    while(getline(file2,curr)) {
        for(int i=0;i<curr.size();i++) {
            if(curr[i]=='.' || curr[i]=='?' || curr[i]=='!')
                count=count+1;
        }
    }

    cout<<"Number of sentences are:"<<count<<endl;

    getch();
    return 0;
}