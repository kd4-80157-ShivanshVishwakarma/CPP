#include"./Cylinder.h"
// #include "./Menu"

int main(){
    Cylinder c;
    int n;
    cout<<"1. Initialize the values "<<endl;
    cout<<"2. Pass the length and height "<<endl;
    cout<<"3. Get radius "<<endl;
    cout<<"4. Set radius "<<endl;
    cout<<"5. Get height "<<endl;
    cout<<"6. Set height "<<endl;
    cout<<"7. Get volume"<<endl;
    cout<<"8. Print volume "<<endl;
    cout<<"0. Exit."<<endl;
    cout<<"Enter your choice : "<<endl;
    while(n!=0){
        cin>>n;
        switch(n){
            case 1: Cylinder();
            cout<<"Initialization done."<<endl;
            break; 
            case 2: Cylinder();
            cout<<"The values are passsed."<<endl;
            break; 
            case 3: cout<<"The radius is : "<<c.getRadius()<<endl;
            break;
            case 4: c.setRadius(4.2);
            cout<<"Radius value is set."<<endl;
            break;
            case 5: cout<<"The height is : "<<c.getHeight()<<endl;
            break;  
            case 6: c.setHeight(3.2);
            cout<<"Height value is set."<<endl;
            break;
            case 7: cout<<"The volume is : "<<c.getVolume()<<endl;
            break;
            case 8: cout<<"Print volume : "<<endl;
            c.printVolume();
            break;
            case 0: cout<<"Exiting.."<<endl;
            break;
            default:
            break;
        }
    }  
    return 0;
}

