#include<iostream>
using namespace std;

class Employee{
    private:
    int id;
    float sal;

    public:

    Employee(){
        this->id=0;
        this->sal=0;
    }
    Employee(int id,float sal){
        this->id=id;
        this->sal=sal;
    }
    void setId(int id){
        this->id=id;
    }
    int getId(){
        return this->id;
    }
    void setSal(float sal){
        this->sal=sal;
    }
    int getSal(){
        return this->sal;
    }
    void accept(){
        cout<<"Enter Emplooyee ID : "<<endl;
        cin>>this->id;

        cout<<"Enter Emplooyee salary : "<<endl;
        cin>>this->sal;
    }
    void display(){
        cout<<"Emplooyee ID : "<<this->id<<endl;

        cout<<"Emplooyee salary : "<<this->sal<<endl;
    }
};
class Manager:public virtual Employee{
    private:
    float bonus;

    public:

    Manager(){
        setId(0);
        setSal(0);
        this->bonus=0;
    }
        
    Manager(int id,float sal,float bonus){
        this->getId();
        this->getSal();
        this->bonus=bonus;
    }
    float getBonus(){
        
        float bon=this->bonus;
        return bon;
    }
    void setBonus(float bonus){
        this->bonus=bonus;
    }
    void display(){
        Employee::display();
        display_manager();

    }
    void accept(){
        Employee::accept();
        accept_manager();
    }
    protected:
    void display_manager(){
        cout<<"Bonus : "<<this->bonus<<endl;
    }

    void accept_manager(){
        cout<<"Enter bonus : "<<endl;
        cin>>this->bonus;
    }
    
};
class Salesman:public virtual Employee{
    private:
    float comm;

    public:

    Salesman(){
        this->comm=0;
        this->getId();
        this->getSal();
    }
    Salesman(int id,float sal,float, float bonus){
        getId();
        setId(id);
        setSal(sal);
        this->comm=comm;
    }
    float getComm(){
        return this->comm;
    }
    void setComm(float comm){
        this->comm=comm;
    }

    void accept(){
        Employee::accept();
        accept_salesman();
    }

    void display(){
        Employee::display();
        display_salesman();
    }

    protected:
    void display_salesman(){
        cout<<"Commission : "<<this->comm<<endl;
    }
    void accept_salesman(){
        cout<<"Enter Commission : "<<endl;
        cin>>this->comm;
    }

};
class Salesmanager:public Salesman,public Manager{
    public:
    Salesmanager(){
        this->getId();
        this->getSal();
        this->getBonus();
        this->getComm();
    }
    Salesmanager(int id,float sal,float bonus,float comm){
        setId(id);
        setSal(sal);
        setComm(comm);
        setBonus(bonus);
    }
    void display(){
        Employee::display();
    }
    void accept(){
        Employee::accept();
    }
};
int main(){
    Salesman s1;
    s1.accept();
    s1.display();
    // s1.display_manager();//Not accessible 
    //s1.display_salesman();//Not accessible

    return 0;
}