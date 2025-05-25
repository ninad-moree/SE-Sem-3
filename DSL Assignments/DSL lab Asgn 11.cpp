#include<iostream>
using namespace std;

class Queue1 {
    private:
    int size;
    int *job;
    int front,rear;

    public:
    Queue1(int s) {
        size=s;
        job = new int[s];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (rear == size -1)
            return 1;
        else
            return 0;
    }

    bool isEmpty() {
        if (rear == -1 || front == rear+1)
            return 1;
        else
            return 0;
    }

    void Enqueue(int element) {
        if(isFull())
            cout<<"Queue is full, element cannot be added"<<endl;
        else {
            if(rear == -1) {
                front++;
                job[++rear] = element;
                cout<<"Element added successfully"<<endl;
            }
            else {
                job[++rear] = element;
                cout<<"Element added successfully"<<endl;
            }
        }
    }

    void Dequeue() {
        if(isEmpty())
            cout<<"Queue is empty,  element cannot be deleted"<<endl;
        else {
            cout<<"Element "<<job[front]<<" deleted succesfully"<<endl;
            front++;
        }
    }
    
    void Display() {
        if(isEmpty())
            cout<<"Queue is empty"<<endl;
        else {
            for(int i=front;i<=rear;i++)
                cout<<job[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    int s;
    cout<<"Enter size of array:"<<flush;
    cin>>s;
    cout<<endl;

    Queue1 que(s);
    int choice, element;
    bool repeat = true;
    while (repeat) {
        cout<<" ****** MENU ******"<<endl;
        cout<<"1. Add Element"<<endl;
        cout<<"2. Delete Element"<<endl;
        cout<<"3. Display Element"<<endl;
        cout<<"4. Exit the code"<<endl;
        cout<<endl;

        cout<<"Enter your choice:"<<flush;
        cin>>choice;

        switch (choice) {
            case 1:
            cout<<"Enter an element:"<<flush;
            cin>>element;
            que.Enqueue(element);
            break;

            case 2:
            que.Dequeue();
            break;

            case 3:
            que.Display();
            break;

            case 4:
            repeat = false;
            break;

            default:
            cout<<"Invalid input"<<endl;
            break;
        }
    }
    return 0;
}