#include<iostream>
#include<conio.h>
using namespace std;

class Dequeue {
   int size;
   int *arr;
   int front;
   int rear;

   public:
   Dequeue(int s) {
      size = s;
      arr = new int[s];
      front = rear = -1;
   }

   int Full() {
      if(rear ==  size-1)
         return 1;
      else
         return 0;
   }

   int Empty() {
      if(front == rear == -1 || front == rear)
         return 1;
      else
         return 0;
   }

   void Insert_Rear(int a) {
      if(Full())
         cout<<"Queue is full"<<endl;
      else {
         rear++;
         arr[rear]=a;
      }
   }

   void Insert_Front(int ele) {
      if(Full())
         cout<<"Queue is full"<<endl;

      else {
         int i,j;
         if(front==-1)
            front++;

         i=front-1;
         while(i>=0) {
            arr[i+1]=arr[i];
            i--;
         }

         j=rear;
         while (j>=front) {
            arr[j+1]=arr[j];
            j--;
         }

         rear++;
         arr[front]=ele;
      }
   }

   int Delete_Rear() {
      if(Empty())
         cout<<"Queue is empty"<<endl;
      else {
         int a;
         a=arr[rear];
         rear--;
         return a;
      }
   }

   int Delete_Front() {
      if(Empty())
         cout<<"Queue is empty"<<endl;
      else {
         int a;
         front++;
         a=arr[front];
         return a;
      }
   }

   void Display() {
      cout<<"Front---->"<<flush;
      for(int i=front;i<=rear;i++)
         cout<<arr[i]<<" ";
      cout<<"<----Rear"<<endl;
   }
};

int main() {
   int s;
   cout<<"Enter size of the array:"<<flush;
   cin>>s;

   Dequeue dq(s);

   int choice;
   int element;
   bool repeat = true;

   while(repeat) {
      cout<<endl;
      cout<<"****** MENU ******"<<endl;
      cout<<"1. Insert from rear"<<endl;
      cout<<"2. Insert from front"<<endl;
      cout<<"3. Delete from rear"<<endl;
      cout<<"4. Delete from front"<<endl;
      cout<<"5. Dislplay"<<endl;
      cout<<"6. Exit"<<endl;
      cout<<endl;

      cout<<"Enter your choie:"<<flush;
      cin>>choice;

      switch(choice) {
         case 1:
            cout<<"Enter element to be added:"<<flush;
            cin>>element;
            dq.Insert_Rear(element);
            break;
         case 2:
            cout<<"Enter element to be added:"<<flush;
            cin>>element;
            dq.Insert_Front(element);
            break;
         case 3:
            cout<<"Deleted element is:"<<dq.Delete_Rear();
            break;
         case 4:
            cout<<"Deleted element is:"<<dq.Delete_Front();
            break;
         case 5:
            dq.Display();
            break;
         case 6:
            cout<<"Exitting the code"<<endl;
            repeat = false;
            break;
         default:
            cout<<"Enter valid choice"<<endl;
            break;
      }
   }

   getch();
   return 0;
}