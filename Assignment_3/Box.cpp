#include<iostream>
using namespace std;

class Box{
    public:
    double len;
    double wid;
    double hei;

    Box(){
        this->len=4;
        this->wid=6;
        this->hei=5;
    }
    /*Box(float len,float wid,float hei){
        this->len=len;
        this->wid=wid;
        this->hei=hei;
    }*/
    void acceptBox(){
        cout<<"Enter the length of box : "<<endl;
        cin>>this->len;

        cout<<"Enter the width of box : "<<endl;
        cin>>this->wid;

        cout<<"Enter the height of box : "<<endl;
        cin>>this->hei;
    }
    void displayVolume(){
       double volume=this->len*this->wid*this->hei;
        cout<<"Enter the volume of the box : "<<volume<<endl;
    }
    
};

int main(){
    Box a;
    int n;
    cout<<"1. Initialize the values : "<<endl;
    cout<<"2. Accept the values : "<<endl;
    cout<<"3. Display volune of box : "<<endl;
    cout<<"Enter your choice : "<<endl;

    while(n!=0){
        cin>>n;
        switch (n){
            case 0: cout<<"Exit."<<endl;
            break;
            case 1: Box();
            cout<<"Initialization done."<<endl;
            break;
            case 2: a.acceptBox();
            break;
            case 3: a.displayVolume();
            break;
            default: cout<<"Invalid input."<<endl;
            break;
        }
    }
    
    return 0;
}