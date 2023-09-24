#include<iostream>
using namespace std;

class Address{
    public:
    string building;
    string street;
    string city;
    int pin;

    Address(){
        this->building="Pawar Apartment";
        this->street="Patan colony, Shaniwar peth";
        this->city="Karad City";
        this->pin=415110;
    }
    Address(string building,string street,string city,int pin){
        this->building=building;
        this->street=street;
        this->city=city;
        this->pin=pin;
    }
    void accept(){
        cout<<"Enter the building name : "<<endl;
        getline(cin,this->building);

        cout<<"Enter the street : "<<endl;
        getline(cin,this->street);

        cout<<"Enter the city : "<<endl;
        cin>>this->city;
        
        cout<<"Enter the pincode : "<<endl;
        cin>>this->pin;
    }
    void display(){
        cout<<"Address : \n"<<"Building : "<<this->building<<"\nStreet : "<<this->street<<"\nCity : "<<this->city<<"\nPin : "<<this->pin<<endl;
    }
    //getters
    string getbuilding(){
        return this->building;
    }
    string getstreet(){
        return this->street;
    }
    string getcity(){
        return this->city;
    }
    int getpin(){
        return this->pin;
    }
    //setters
    void setbuilding(string building){
        this->building=building;
    }
    void setstreet(string street){
        this->street=street;
    }
    void setcity(string city){
        this->city=city;
    }
    void setpin(int pin){
        this->pin=pin;
    }

};

int main(){
    Address a;
    Address("Apartment G4","Shaniwar peth road","PatanColony",415110);
    a.accept();
    a.display();
    cout<<"Get building "<<a.getbuilding()<<endl;
    cout<<"Get street "<<a.getstreet()<<endl;
    cout<<"Get city "<<a.getcity()<<endl;
    cout<<"Get pin "<<a.getpin()<<endl;
    a.setbuilding("apartment");
    a.setstreet("Patan Street");
    a.setcity("Karad");
    a.setpin(451237);
    return 0;
}