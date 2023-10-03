#include<iostream>
using namespace std;

namespace Nmenu{
    int menu()
    {
        int choice;
        cout << "--------------------" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Accept Employees" << endl;
        cout << "2. Display designation and their count" << endl;
        cout << "3. Display designations" << endl;
        cout << "Enter Your Chocie = ";
        cin >> choice;
        return choice;
    }
}

class Employee{
    private:
    int id;
    float sal;
    string type;

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
    string getType(){
        return this->type;
    }
    void accept(){
        cout<<"Enter Employee ID : "<<endl;
        cin>>this->id;

        cout<<"Enter Employee salary : "<<endl;
        cin>>this->sal;

        cout<<"Enter Type : "<<endl;
        cin>>this->type;
    }
    void display(){
        cout<<"Employee ID : "<<this->id<<endl;

        cout<<"Employee salary : "<<this->sal<<endl;
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
        Employee:accept();
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
        // Manager::display();
        // Salesman::display();
        Employee::display();
    }
    void accept(){
        // Manager::accept();
        // Salesman::accept();
        Employee::accept();
    }
};
using namespace Nmenu;
int main(){
    // Salesmanager s1;
    // s1.accept();
    // s1.display();
    // s1.display_manager();//Not accessible 
    //s1.display_salesman();//Not accessible
    Employee *emp[10];
    int choice;
    int indx=0;
    string designation;
    while((choice=menu())!=0){
        switch (choice){
            case 1:if(indx<10){
                cout<<"Enter designation : \n";
                cin>>designation;
                        if(designation=="M"){
                            emp[indx]=new Manager();
                            emp[indx]->accept();
                            indx++;
                        }
                        else if(designation=="S"){
                            emp[indx]=new Salesman();
                            emp[indx]->accept();
                            indx++;
                        }
                        else if(designation=="SM"){
                            emp[indx]=new Salesmanager();
                            emp[indx]->accept();
                            indx++;
                        }
                        else{
                            cout<<"Not valid."<<endl;
                        }
                        break;
            case 2: if(indx<10){
                        int cntM=0;int cntS=0;int cntSM=0;
                        for(int i=0;i<indx;++i){
                            if(emp[i]->getType()=="M"){
                                cntM++;
                            }
                            else if(emp[i]->getType()=="S"){
                                cntS++;
                            }
                            else if(emp[i]->getType()=="SM"){
                                cntSM++;
                            }
                            else{continue;}
                        }
                        cout<<"Manager - "<<cntM<<endl;
                        cout<<"Salesman - "<<cntS<<endl;
                        cout<<"Salesmanager - "<<cntSM<<endl;
                    }
                    break;
            case 3: if(indx<10){
                        for(int i=0;i<indx;++i){
                            if(emp[i]->getType()=="M"){
                                cout<<"Manager"<<endl;
                            }
                            else if(emp[i]->getType()=="S"){
                                cout<<"Salesman"<<endl;
                            }
                            else if(emp[i]->getType()=="SM"){
                                cout<<"Salesmanager"<<endl;
                            }
                        }
                    }
                    break;
            case 0:cout<<"Exit"<<endl;   
            break;     
            default:cout<<"Wrong choice"<<endl;
            break;
            }
        }
    }
    for(int i=0;i<indx;++i){
        delete emp[i];
    }
    return 0;
}