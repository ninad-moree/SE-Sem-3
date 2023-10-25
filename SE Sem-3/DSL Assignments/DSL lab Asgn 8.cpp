/*  Write C++ program for storing appointment schedule for day. Appointments are booked 
    randomly using linked list. Set start and end time and min and max duration for visit slot. 
    Write functions for
    a) Display free slots
    b) Book appointment
    c) Cancel appointment ( check validity, time bounds, availability)
    d) Sort list based on time
    e) Sort list based on time using pointer manipulation  

    22 November 2022 */

#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

class Node
{
    private:
    Node *next;
    bool isBooked;
    float start_time;
    float end_time;
    float min_duration;
    float max_duration;

    public:
    Node(bool isBooked = false,float start_time=0,float end_time=0,float min_duration=0,float max_duration=60)
    {
        this->isBooked=isBooked;
        this->start_time=start_time;
        this->end_time=end_time;
        this->min_duration=min_duration;
        this->max_duration=max_duration;

        next=nullptr;
    };
    friend class Schedule;
};

class Schedule
{
    private:
    Node *head;
    Node *tail;
    Node *sort;
    static int slot_no;

    public:
    Schedule()
    {
        head=nullptr;
        tail=nullptr;
        sort=nullptr;
    }

    void Create_Slot(float startTime=0)
    {
        Node *temp = new Node();
        slot_no++;
        if (startTime < 10 || startTime > 17)
        {
            cout<<"Enter valid time"<<endl;
            return;
        }
        if (startTime==0)
        {
            cout<<"Enter start time:"<<flush;
            cin>>startTime;
        }

        temp->start_time=startTime;
        cout<<"Enter end time:"<<flush;
        cin>>temp->end_time;
        cout<<"Max duration:"<<flush;
        cin>>temp->max_duration;
        cout<<"Min duration:"<<flush;
        cin>>temp->min_duration;

        if (head==nullptr)  //empty list
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    void Display_Slot()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            cout<<"*******Booked SLots*******"<<endl;
            cout<<left<<setw(15)<<"Start time"<<left<<setw(15)<<"End time"<<left<<setw(15)<<"Max duration"<<left<<setw(15)<<"Min Duration"<<endl;
            
            while(temp!=nullptr)
            {
                cout<<left<<setw(15)<<temp->start_time<<left<<setw(15)<<temp->end_time<<left<<setw(15)<<temp->max_duration<<left<<setw(15)<<temp->min_duration<<endl;
                temp=temp->next;
            }
        }
        else  // if list empty
        {
            cout<<"No slots booked till now"<<endl;
        } 
    }

    void Book_SLot()
    {
        cout<<"Booking time is from 10 to 6"<<endl;
        cout<<endl;
        float startTime;
        cout<<"Enter the start time(hr):"<<flush;
        cin>>startTime;

        Node *temp = head;
        while(temp!=nullptr)
        {
            if (temp->start_time<=startTime && temp->end_time>startTime )
            {
                cout<<"Slot is already booked"<<endl;
                return;
            }
            temp=temp->next;
        }
        Create_Slot(startTime);
    }

    void Cancel_Slot()
    {
        float startTime;
        cout<<"Enter the start time(hr) to cancel the appointment:"<<flush;
        cin>>startTime;

        Node *temp =head;
        Node *temp1=head;
        while (temp != nullptr)
        {
            if(temp->start_time==startTime)
            {
                char i_p;
                cout<<"Slot found. Please press y to cancel:"<<flush;
                cin>>i_p;
                if (i_p=='Y' || i_p=='y')
                {
                    if (head->next==nullptr)
                    {
                        head=nullptr;
                    }
                    else if(temp == head)
                    {
                        head=temp->next;
                    }
                    else
                    {
                        temp1->next=temp->next;
                    }
                    delete temp;
                    slot_no--;
                    return;
                }
                else
                {
                    cout<<"Did not cancel the appointment"<<endl;
                    return;
                } 
            }
            temp1=temp;
            temp=temp->next;
        }
        cout<<"Did not find the slot"<<endl;  
    }

    void Sort_StartTime()
    {
        for (int i=0;i<slot_no-1;i++)
        {
            Node *temp = head;
            while (temp->next!=nullptr)
            {
                if (temp->start_time  > temp->next->start_time)
                {
                    float swap = temp->start_time;
                    temp->start_time = temp->next->start_time;
                    temp->next->start_time = swap;

                    swap= temp->end_time;
                    temp->end_time = temp->next->end_time;
                    temp->next->end_time = swap;

                    swap = temp->min_duration;
                    temp->min_duration = temp->next->min_duration;
                    temp->next->min_duration = swap;

                    swap= temp->max_duration;
                    temp->max_duration = temp->next->max_duration;
                    temp->next->max_duration = swap;
                }
                temp=temp->next;
            }
        }
    }

    void Sort_Pointers()
    {
        Node *temp1 = head;
        Node *temp2 = head;

        Node *nptr1 = temp2;
        Node *nptr2 = temp2->next;
        Node *nptr3 = temp2->next->next;

        while (temp1)
        {
            if (temp1->next)
            {
                while (temp2)
                {
                    if (temp2->next)
                    {
                        if (temp2->start_time > temp2->next->start_time)
                        {
                            nptr2->next = nptr3->next;
                            nptr3->next = nptr2;
                            nptr1->next = nptr3;
                        }
                        temp2=temp2->next;
                    }
                    else
                    {
                        break;
                    }
                }
                temp1=temp1->next;
            }
            else
            {
                break;
            }
        }
    }

};

int Schedule::slot_no=0;

int main()
{
    Schedule day;
    bool repeat = true;
    while (repeat)
    {
        cout<<"Menu"<<endl;
        cout<<"1. Book Appointment"<<endl;
        cout<<"2. Display Slot"<<endl;
        cout<<"3. Sort based on start time"<<endl;
        cout<<"4. Delete Appointment"<<endl;
        cout<<"5. Sort base on pointers"<<endl;
        cout<<"6. Exit the code"<<endl;

        cout<<endl;

        int choice;
        cout<<"Enter your choice:"<<flush;
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case 1:
        day.Book_SLot();
        cout<<endl;
        break;

        case 2:
        day.Display_Slot();
        cout<<endl;
        break;

        case 3:
        day.Sort_StartTime();
        cout<<endl;
        break;

        case 4:
        day.Cancel_Slot();
        cout<<endl;
        break;

        case 5:
        day.Sort_Pointers();
        cout<<endl;
        break;

        case 6:
        repeat=false;
        cout<<"Exitting the code"<<endl;
        break;

        default:
        cout<<"Invalid choice"<<endl;
        cout<<endl;
        }
    }
    getch();
    return 0;
}