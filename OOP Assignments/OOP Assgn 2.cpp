#include <iostream>
#include<conio.h>
using namespace std;

class Student
{
private:
    string name, blood_group, address;
    long long rno, std_class, division, DOB, telephone_num, drv_lic;

public:
    Student()
    {
        try
        {
            cout << "Enter the Name: ";
            cin >> name;
            cout << "Enter the RollNo: ";
            cin >> rno;
            cout << "Enter the Class: ";
            cin >> std_class;
            cout << "Enter the Division: ";
            cin >> division;
            cout << "Enter the DOB: ";
            cin >> DOB;
            cout << "Enter the Blood Group: ";
            cin >> blood_group;
            cout << "Enter the Contact Address: ";
            cin >> address;
            cout << "Enter the Telephone number: ";
            cin >> telephone_num;
            cout << "Enter the Driving License No.: ";
            cin >> drv_lic;
            cout << "Default constructor executed\n";
        }
        catch (...)
        {
            cout << "Some wrong info was entered" << endl;
        }
    }
    Student(string name, string blood_group, string address, int rno, int std_class, int division, int DOB, int telephone_num, int drv_lic)
    {
        this->name = name;
        this->blood_group = blood_group;
        this->address = address;
        this->rno = rno;
        this->std_class = std_class;
        this->division = division;
        this->DOB = DOB;
        this->telephone_num = telephone_num;
        this->drv_lic = drv_lic;
        cout << "Parameterized constructor successfully executed\n";
    }
    Student(Student &obj)
    {
        name = obj.name;
        blood_group = obj.blood_group;
        address = obj.address;
        rno = obj.rno;
        std_class = obj.std_class;
        division = obj.division;
        DOB = obj.DOB;
        telephone_num = obj.telephone_num;
        drv_lic = obj.drv_lic;
        cout << "Copy constructor executed\n";
    }
    ~Student()
    {
        cout << "Object destructed\n";
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "RollNo: " << rno << endl;
        cout << "Class: " << std_class << endl;
        cout << "Division:" << division << endl;
        cout << "DOB: " << DOB << endl;
        cout << "Blood Group: " << blood_group << endl;
        cout << "Contact Address: " << address << endl;
        cout << "Telephone number: " << telephone_num << endl;
        cout << "Driving License No.: " << drv_lic << endl;
    }
    friend class Friend;
};

class Friend
{
public:
    inline void showName(Student &obj)
    {
        cout << "Name is: " << obj.name << "\n";
    }
};

int main()
{
    int choice;
    Student obj1("Ninad", "A+", " Katraj", 21253, 2, 2, 18032003, 7841987199, 69);

    do
    {
        cout<<endl;
        cout<<"**** MENU ****"<<endl;
        cout<<"1. Default COnstructor"<<endl;
        cout<<"2. Paremeterized COnstructor"<<endl;
        cout<<"3. Copy COnstructor"<<endl;
        cout<<"4. Print Using Static function"<<endl;
        cout<<"5. Print Name using friend Class"<<endl;
        cout<<"6. Delete Object"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<endl;

        cout<<"Enter your choice"<<endl;
        cin >> choice;
        cout<<endl;

        switch (choice)
        {
            case 1:
            {
                Student objD;
                break;
            }
            case 2:
            {
                Student objP("Ninad", "A+", " Katraj", 21253, 2, 2, 18032003, 7841987199, 69);
                break;
            }
            case 3:
            {
                Student objC(obj1);
                break;
            }
            case 4:
            {
                obj1.display();
                break;
            }
            case 5:
            {
                Friend objE;
                objE.showName(obj1);
                break;
            }
            case 6:
            {
                Student *p = new Student("Ninad", "A+", " Katraj", 21253, 2, 2, 18032003, 7841987199, 69);
                delete p;
                break;
            }
            case 7: 
            {
                break;
            }
            default:
            {
                cout << "Wrong Input!\n";
            }
        }
    } while (choice != 7);
    getch();
    return 0;
}