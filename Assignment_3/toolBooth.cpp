#include<iostream>
using namespace std;

class toolBooth{
    private:
    unsigned int payCars;
    unsigned int nopayCars;
    double totAmt;
    public:
    toolBooth(){
        this->payCars=0;
        this->totAmt=0;
    }
    void payingCar(){
        this->payCars=this->payCars+1;
        this->totAmt+=0.50;
    }
    void nopayCar(){
        this->payCars=this->payCars-1;
    }
    void printOnConsole(){
        cout<<"Total Paying cars : "<<this->totAmt/0.5<<endl;
        cout<<"Total Non-paying cars : "<<abs(this->payCars-(this->totAmt/0.5))<<endl;
        cout<<"Total amount collected : "<<this->totAmt<<endl;
    }

};

int main(){
    toolBooth a;
    int x;
    cout<<"1. Number of paying cars : "<<endl;
    cout<<"2. Number of Non-paying cars : "<<endl;
    cout<<"3. Total amount collected : "<<endl;
    cout<<"0. Exit."<<endl;
    cout<<"Enter your choice : "<<endl;
    while(x!=0){
        cin>>x;
        switch (x){
            case 1: cout<<"Paid successfully : "<<endl;
            a.payingCar();
            break;
            case 2: cout<<"Have not paid : "<<endl;
            a.nopayCar();
            break;
            case 3: cout<<"Total amount : "<<endl;
            a.printOnConsole();
            break;
            case 4: cout<<"Exiting."<<endl;
            break;
            default: cout<<"Invalid input."<<endl;
            break;
        }
    }
    return 0;
}