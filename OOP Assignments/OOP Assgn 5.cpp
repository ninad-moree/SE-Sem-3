#include<iostream>
#include<conio.h>
using namespace std;

#define n 10
template<typename T>
class Sorting
{
    public:
    static void Selction_Sort(T arr[] , int size)
    {
        for(int i=0; i<size-1; i++)
        {
            int min = i;
            for(int j=i+1; j<size; j++)
            {
                if(arr[j] < arr[min])
                {
                    min = j;
                }
            }
            T temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
};

template<typename T>
void Display(T arr[] , int size)
{
    cout<<"Array is:"<<flush;
    for(int i=0; i<size; i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

int main()
{
    int Int_Array[n];
    float Float_Array[n];

    int sizeInt;
    int sizeFloat;
    int choice;

    do
    {
        cout<<" ****** Menu ******"<<endl;
        cout<<"1. Sort integer array"<<endl;
        cout<<"2. Sort float array"<<endl;
        cout<<"3. Exit the code"<<endl;
        cout<<endl;

        cout<<"Enter your choice:"<<flush;
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1:
            cout<<"Enter size of integer array:"<<flush;
            cin>>sizeInt;
            for(int i=0; i<sizeInt ; i++)
            {
                cout<<"Enter element:"<<flush;
                cin>>Int_Array[i];
            }
            Display<int>(Int_Array,sizeInt);
            cout<<"*** Sorted Array ***"<<endl;
            Sorting<int>::Selction_Sort(Int_Array,sizeInt);
            Display<int>(Int_Array,sizeInt);
            break;

            case 2:
            cout<<"Enter size of float array:"<<flush;
            cin>>sizeFloat;
            for(int i=0; i<sizeFloat; i++)
            {
                cout<<"Enter element:"<<flush;
                cin>>Float_Array[i];
            }
            Display<float>(Float_Array,sizeFloat);
            cout<<"*** Sorted Array ***"<<endl;
            Sorting<float>::Selction_Sort(Float_Array,sizeFloat);
            Display<float>(Float_Array,sizeFloat);
            break;

            case 3:
            cout<<"Exiting the code..."<<endl;
            exit(0);
            break;
            
            default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }while(choice!=3);

    getch();
    return 0;
}