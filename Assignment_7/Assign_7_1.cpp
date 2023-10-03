#include<iostream>
using namespace std;

class Date{
    private:
    int day;
    int month;
    int year;
    public:

    Date(){
        this->day=0;
        this->month=0;
        this->year=0;
    }

    Date(int day,int month,int year){
        this->day=day;
        this->month=month;
        this->year=year;
    }
    void set_day(int day){
        this->day=day;
    }
    void set_month(int day){
        this->month=month;
    }
    void set_year(int day){
        this->year=year;
    }
    virtual void acceptDate(){
        cout<<"Enter the date : "<<endl;
        cin>>this->day;

        cout<<"Enter the month : "<<endl;
        cin>>this->month;

        cout<<"Enter the year : "<<endl;
        cin>>this->year;
    }
    virtual void display(){
        cout<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
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

        doj.display();
        isLeapYear();
    }
    void isLeapYear(){
        if(doj.isLeap())
            cout<<"It is leap year."<<endl;
        else
            cout<<"Not a leap year."<<endl;
    }
};
class Person:public Employee{
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
    void accept(){
        cout<<" pp Enter the name : "<<endl;
        // cin.ignore();
        getline(cin,this->name);

        cout<<"pp Enter the address : "<<endl;
        getline(cin,this->addr);

        cout<<"pp Enter date of birth : "<<endl;
        birth_date.acceptDate();
    }
    void display(){
        cout<<"Name of the person : "<<this->name<<endl;

        cout<<"Address : "<<this->addr<<endl;

        cout<<"Date of birth: ";
        birth_date.display();
    }

};
int main(){
    Employee p1;
    
    // Person p1;
    // p1.accept();
    // p1.display();
    return 0;
}