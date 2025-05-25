#include<iostream>
#include<conio.h>
using namespace std;

struct Node {
    int seat_row , seat_col;
    string status;
    Node *next , *previous;
} *head[10], *tail[10];

class Ticket_Booking {
    public:
    Ticket_Booking() {
        for(int i=1;i<=10;i++) {
            head[i] = tail[i] = NULL;
            Node *newnode;
            for(int j=1;j<=7;j++) {
                newnode = Create_Node(i,j);
                if(head[i] == tail[i] && head[i] == NULL) {
                    head[i] = tail[i] = newnode;
                    head[i]->next = tail[i]->next = NULL;
                    head[i]->previous = tail[i]->previous = NULL;
                }
                else  {
                    tail[i]->next = newnode;
                    newnode->next = head[i];
                    newnode->previous = tail[i];
                    tail[i] = newnode;
                    head[i]->previous = tail[i];
                }
            }
        }
    }

    Node *Create_Node(int x , int y) {
        Node *newnode;
        newnode = new(struct Node);
        if(newnode == NULL) {
            cout<<"No seats are booked"<<endl;
            return 0;
        }
        else {
            newnode->seat_row = x;
            newnode->seat_col = y;
            newnode->status = "A";
            newnode->next = NULL;
            newnode->previous = NULL;
            return newnode;
        }
    }

    void Book_Seat() {
        int noOfSeats;
        cout<<"Enter how many seats you want to book:"<<flush;
        cin>>noOfSeats;
        cout<<endl;
        for(int k=1;k<=noOfSeats;k++) {
            int x,y;
            cout<<"Enter the row and column of the seat you want to book:"<<flush;
            cin>>x>>y;
            cout<<endl;

            Node *newnode;
            newnode = head[x];
            for(int i=1;i<=7;i++) {
                if(newnode->seat_col == y) {
                    if (newnode->status ==  "A")
                        newnode->status = "B";
                    else {
                        cout<<" Sorry the seat is already booked"<<endl;
                        cout<<endl;
                    }
                }
                newnode = newnode->next;
            }
        }

        Display_Seat();
        cout<<endl;
    }

    void Cancel_Seat() {
        int dltSeat;
        cout<<"Enter how many seats you want to delete:"<<flush;
        cin>>dltSeat;
        cout<<endl;
        for(int k=1;k<=dltSeat;k++) {  
            int x,y;
            cout<<"Enter the row and column of the seat you want to cancel:"<<flush;
            cin>>x>>y;
            cout<<endl;

            Node *dltnode;
            dltnode = head[x];
            for(int i=1;i<=7;i++) {
                if(dltnode->seat_col == y) {
                    if(dltnode->status == "B")
                        dltnode->status = "A";
                    else {
                        cout<<"Seat is already not booked"<<endl;
                        cout<<endl;
                    }
                }
                dltnode = dltnode->next;
            }
        }

        Display_Seat();
        cout<<endl;
    }

    void Display_Seat() {
        Node *nptr;
        for(int i=1;i<=10;i++) {
            nptr=head[i];

            for(int j=1;j<=7;j++) {
                cout<<nptr->seat_row<<":"<<nptr->seat_col<<"-"<<nptr->status<<"\t";
                nptr = nptr->next;
            }

            cout<<endl;
        }
    }
};

int main() {
    Ticket_Booking ticket;
    bool repeat = true;
    int choice;

    ticket.Display_Seat();
    cout<<endl;

    while(repeat) { 
        cout<<" ****** MENU ****** "<<endl;
        cout<<"1. Book Seats"<<endl;
        cout<<"2. Cancel Seats"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<endl;

        cout<<"Enter your choice:"<<flush;
        cin>>choice;
        cout<<endl;

        switch(choice) {
            case 1:
            ticket.Book_Seat();
            cout<<endl;
            break;

            case 2:
            ticket.Cancel_Seat();
            cout<<endl;
            break;

            case 3:
            repeat = false;
            cout<<"Exitting the code"<<endl;
            break;

            default:
            cout<<"Enter valid choice"<<endl;
            break;
        }
    }
    
    getch();
    return 0;
}