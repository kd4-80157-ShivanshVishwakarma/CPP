#include<iostream>
using namespace std;

class DateC{
    public:
    int date;
    int month;
    int year;

    void initDate(){
        date=22;
        month=9;
        year=2020;
    }
    void acceptDateFromConsole(){
        cout<<"Enter the date : "<<endl;
        cin>>date;

        cout<<"Enter the month : "<<endl;
        cin>>month;

        cout<<"Enter the year : "<<endl;
        cin>>year;

    }
    void printDateOnConsole(){
        cout<<"Today's date : "<<date<<" "<<month<<" "<<year<<endl;
    }
    bool isLeapYear(){
        int yr = year;
        if((yr%4==0 && yr%100!=0) || (yr%400==0)){
            return true;
        }
        return false;

    }

};
int main(){
    int n;
    DateC D;

    // D.initDate();

        cout << "1. Initialize the Date" << endl;
        cout << "2. Print the Date" << endl;
        cout << "3. Accept the Date" << endl;
        cout << "4. Check if it is Leap Year" << endl;
        cout << "5. Exit" << endl;
        cout<<"Enter the choice : "<<endl;
        do {
            cin>>n;
            switch (n){
                // cin>>n;
                case 1: D.initDate();
                break;
                case 3: D.acceptDateFromConsole();
                break;
                case 2: D.printDateOnConsole();
                break;
                case 4: if(D.isLeapYear())
                    cout<<"True"<<endl;
                else
                    cout<<"False"<<endl;
                break;
                case 5: cout<<"Exiting.."<<endl;
                break;
                default: cout<<"Invalid Date.";
                break;
            }
        } while(n!=5);

    return 0;
}