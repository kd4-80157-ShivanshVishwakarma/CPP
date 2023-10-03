#include<iostream>
using namespace std;

class Date{
    public:
    int date;
    int month;
    int year;

    public:
    Date(){
        this->date=0;
        this->month=0;
        this->year=0;
    }
    Date(int date,int month,int year){
        this->date=date;
        this->month=month;
        this->year=year;
    }
    void acceptDate(){
        cout<<"Enter the date : "<<endl;
        cin>>this->date;

        cout<<"Enter the month : "<<endl;
        cin>>this->month;

        cout<<"Enter the year : "<<endl;
        cin>>this->year;
    }
    void displayDate(){
        cout<<this->date<<"/"<<this->month<<"/"<<this->year<<endl;
        
    }
    void setDate(int date){
        this->date=date;
    }
    void setMonth(int month){
        this->month=month;
    }
    void setYear(int year){
        this->year=year;
    }
    bool isLeap(){
        int yr=this->year;
        if((yr%4==0 && yr%100!=0)||(yr%400==0)){
            return true;
        }
        return false;
    }
};
class Employee{
    private:
    int id;
    float sal;
    string dept;
    Date doj;

    public:
    Employee(){
        this->id=0;
        this->sal=0;
        this->dept="";
    }
    Employee(int id,float sal,string dept,int date,int month,int year):doj(date,month,year){
        this->id=id;
        this->sal=sal;
        this->dept;
    }
    void acceptEmployee(){
        cout<<"Enter the ID : "<<endl;
        cin>>this->id;

        cout<<"Enter the Salary : "<<endl;
        cin>>this->sal;

        cout<<"Enter the Dept name : "<<endl;
        cin>>this->dept;

        cout<<"Date of joining : "<<endl;
        
        doj.acceptDate();
    }

    void displayEmployee(){
        cout<<"Employee ID : "<<this->id<<endl;

        cout<<"Employee Salary : "<<this->sal<<endl;

        cout<<"Employee Dept : "<<this->dept<<endl;

        doj.displayDate();
        isLeapYear();
    }
    void isLeapYear(){
        if(doj.isLeap())
            cout<<"It is leap year."<<endl;
        else
            cout<<"Not a leap year."<<endl;
    }
};
class Person{
    private:
    string name;
    string addr;
    Date birth_date;

    public:

    Person(){
        this->name="";
        this->addr="";
    }
    Person(string name,string addr,int date,int month,int year):birth_date(date,month,year){
        this->name=name;
        this->addr=addr;
    }
    void acceptPerson(){
        cout<<"Enter the name : "<<endl;
        // cin.ignore();
        getline(cin,this->name);

        cout<<"Enter the address : "<<endl;
        getline(cin,this->addr);

        cout<<"Enter date of birth : "<<endl;
        birth_date.acceptDate();
    }
    void displayPerson(){
        cout<<"Name of the person : "<<this->name<<endl;

        cout<<"Address : "<<this->addr<<endl;

        cout<<"Date of birth: ";
        birth_date.displayDate();
    }

};
int main(){
    Employee e1;
    e1.acceptEmployee();
    e1.displayEmployee();
    // Person p1("Shiv Rathore","Gulati chowk",1,1,2000);
    // p1.acceptPerson();
    // p1.displayPerson();
    

    return 0;
}