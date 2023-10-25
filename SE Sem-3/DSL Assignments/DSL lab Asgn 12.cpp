/*  Write program to implement a priority queue in C++ using an inorder list to store the
    items in the queue. Create a class that includes the data items (which should be
    template) and the priority (which should be int). The inorder list should contain these
    objects, with operator <= overloaded so that the items with highest priority appear at the
    start of the list (which will make it relatively easy to retrieve the highest item.)
    
    2 December 2022 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <class T>
class jobStruct
{
    public:
        T job;
        int priority;

        bool operator <= (const jobStruct &a)
        {
            if(priority <= a.priority)
            {
                return true;
            }
            return false;
        }
};

template <class T>
class JobQueue
{
    public:
    jobStruct <T>*jobQ;
    int size;
    int front;
    int rear;

    JobQueue(int s)
    {
        size = s;
        jobQ = new jobStruct<T>[s];
        front = -1;
        rear = -1;
    }

    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty.\n";
        }
        else
        {
            cout<<left<<setw(10)<<"Job"<<left<<setw(10)<<"Priority"<<endl;
            for(int i = front; i <= rear; i++)
            {
                cout<<left<<setw(10)<<jobQ[i].job<<left<<setw(10)<<jobQ[i].priority<<endl;
            }
            cout<<endl;
        }
    }

    bool isEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if(rear == size - 1)
        {
            return true;
        }
        return false;
    }

    void enqueue()
    {
        if (isFull())
        {
            cout<<"Queue is already full"<<endl;
        }
        else
        {
            if(isEmpty())
            {
                jobStruct <T>newJob;
                cout<<"Enter job to be added to the queue: ";
                cin>>newJob.job;
                cout<<"Enter priority of the job: ";
                cin>>newJob.priority;
                jobQ[++rear] = newJob;
                front++;
            }
            else
            {
                jobStruct <T>newJob;
                cout<<"Enter job to be added to the queue: ";
                cin>>newJob.job;
                cout<<"Enter priority of the job: ";
                cin>>newJob.priority;
                jobQ[++rear] = newJob;
            }
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout<<"Queue is empty hence can't dequeue."<<endl;
        }
        else
        {
            for(int i = front; i <= rear; i++)
            {
                for(int j = front; j <= rear; j++)
                {
                    if (!(jobQ[i] <= jobQ[j]))
                    {
                        jobStruct <T>tempJob = jobQ[i];
                        jobQ[i] = jobQ[j];
                        jobQ[j] = tempJob;
                    }
                }
            }
            
            cout<<"Job that has been removed\n";
            cout<<left<<setw(10)<<"Job"<<left<<setw(10)<<"Priority"<<endl;
            cout<<left<<setw(10)<<jobQ[front].job<<left<<setw(10)<<jobQ[front].priority<<endl;

            if(front < rear)
            {
                front++;
            }
            else
            {
                front = -1;
                rear = -1;
            }

            display();
        }
    }
};

int main()
{   
    int s,c;
    cout<<"Enter size of queue: ";
    cin>>s;
    
    JobQueue <char>jobQueue(s);
    
    bool con = true;
    while(con)
    {
        int choice;
        cout<<"****** MENU ******"<<endl;
        cout<<"1. Add element"<<endl;
        cout<<"2. Delete element"<<endl;
        cout<<"3. Display elements"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice:"<<flush;
        cin >> choice;
        switch (choice)
        {
            case 1:
                jobQueue.enqueue();
                break;

            case 2:
                jobQueue.dequeue();
                break;

            case 3:
                jobQueue.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                con = false;
                break;

            default:
                cout << "Wrong input!" << endl;
                break;
        }
    }
    return 0;
}