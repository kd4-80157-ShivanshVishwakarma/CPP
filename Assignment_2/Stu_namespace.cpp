#include<iostream>
using namespace std;

namespace NStudent{
    class Student{

    public:
    int roll_no;
    string name;
    int marks;

    void initStudent(){
        this->roll_no=80157;
        this->name="Rakesh";
        this->marks=60;
    }
    void acceptStudentFromConsole(){
        cout<<"Enter the roll_no : "<<endl;
        cin>>roll_no;

        cout<<"Enter the name : "<<endl;
        cin>>name;

        cout<<"Enter the marks : "<<endl;
        cin>>marks;
    }
    void printStudentOnConsole(){
        cout<<"Student's Report : \nMarks - "<<roll_no<<",\nName - "<<name<<",\nMarks - "<<marks<<endl;
    }
   };
}
int main(){
    NStudent::Student s1;
    int n;
    cout<<"Enter your choice : "<<endl;
    cout << "1. Initialize the Date" << endl;
    cout << "2. Print the Date" << endl;
    cout << "3. Accept the Date" << endl;
    cout << "4. Exit" << endl;
    cout<<"Enter your choice : "<<endl;
    bool flag=false;
    do {
        cin>>n;
        switch (n){
            case 1: s1.initStudent();
            cout<<"Initialization done."<<endl;
            break;
            case 2: s1.printStudentOnConsole();
            break;
            case 3: s1.acceptStudentFromConsole();
            break;
            case 4: cout<<"Exiting.."<<endl;
            break;
            default: flag=true;
            cout<<"Invalid Input."<<endl;
            break;
        }
        if(flag){
            break;
        }
    }while(n!=4);

    return 0;
}