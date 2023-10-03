#include<iostream>
using namespace std;

namespace Nmenus{
    int menu(){
    int choice;
    cout<<"1. Accept Account Detail : "<<endl;
    cout<<"2. Deposit cash : "<<endl;
    cout<<"3. Withdraw cash : "<<endl;
    cout<<"4. Display Account Details : "<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
    }
    int submenu(){
        int choice;
        cout<<"1. SAVINGS "<<endl;
        cout<<"2. CURRENT "<<endl;
        cout<<"3. DMAT "<<endl;
        cout<<"0. EXIT "<<endl;
        cout<<"Enter Account Type: ";
        cin>>choice;
        return choice;
    }
}
using namespace Nmenus;
enum accType {
    SAVINGS=1,
    CURRENT,
    DMAT
};
class ExceptionInsuffFunds{
    private:
    int accid;
    double curr_balance;
    double withdraw_balance;
    public:

    /*ExceptionInsuffFunds(){
        this->accid=0;
        this->curr_balance=0;
        this->withdraw_balance=0;
    }*/
    ExceptionInsuffFunds(int accid,double curr_balance,double withdraw_balance){
        this->accid=accid;
        this->curr_balance=curr_balance;
        this->withdraw_balance=withdraw_balance;
    }
    void display(){
        cout<<"ERROR: 2302 Can not withdraw the given amount you have insufficient balance"<<endl;
        cout<<"You do not have sufficient balance your "<<this->curr_balance<<" is less than your "<<this->withdraw_balance<<"withdrawl amount"<<endl;
    }

};
class Account{
    private:
    int id;
    accType acc_type;
    double balance;

    public:
    int choice;

    Account(){
        this->id=0;
        this->acc_type=SAVINGS;
        this->balance=0;
    }
    Account(int id,accType acc_type){
        this->id=id;
        this->acc_type=acc_type;
    }
    void accept(){
        cout<<"Enter ID : "<<endl;
        cin>>this->id;

        cout<<"Enter Account Type : ";
        choice = submenu();
        
        cout<<"Enter Balance : "<<endl;
        cin>>this->balance;
    }
    void display(){
        cout<<"Account ID : "<<this->id<<endl;
        switch(choice){
                    case SAVINGS: cout<<"Account Type : SAVINGS"<<endl;
                    break;
                    case CURRENT: cout<<"Account Type :CURRENT"<<endl;
                    break;
                    case DMAT: cout<<"Account Type :DMAT"<<endl;
                    break;
                }
        cout<<"Account Balance : "<<this->balance<<endl;
    }
    void setId(int id){
        this->id=id;
    }
    int getId(){
        return this->id;
    }
    void setAccType(accType acc_type){
        this->acc_type=acc_type;

    }
    accType getAccType(){
        return acc_type;
    }
    double getBalance(){
        return this->balance;
    }
    void deposit(double amount){
        cout<<amount<<" Amount has been credited into your Bank."<<endl;
        this->balance+=amount;
    }
        
    void withdraw(double amount){
        if(this->balance<amount){
            throw ExceptionInsuffFunds(this->id,this->balance,amount);
        }
        else{
            cout<<amount<<" Amount has been withdrawn from your Bank."<<endl;
            this->balance-=amount;
        }
    }
};

int main(){
    Account *arr[5];
    int choice;
    int indx=0;
    while((choice=menu())!=0){
        switch (choice){
            case 1:
            arr[indx]=new Account();
            arr[indx]->accept();
            indx++;
            break;
            case 2:
                int accid;
                cout<<"Enter your account ID : \n";
                cin>>accid;
                for(int i=0;i<indx;++i){
                    int amount;
                    if(accid==arr[i]->getId()){
                        cout<<"Enter deposit amount : \n";
                        cin>>amount;
                        arr[i]->deposit(amount);
                        break;
                    }
                    else{
                        cout<<"Invalid ID."<<endl;
                    }
                }
                break;
            case 3: 
                accid=0;
                cout<<"Enter your account ID : \n";
                cin>>accid;
                for(int i=0;i<indx;++i){
                    int amount;
                    if(accid==arr[i]->getId()){
                        cout<<"Enter withdrawl amount : \n";
                        cin>>amount;
                        try{
                            arr[i]->withdraw(amount);
                        }
                        catch(ExceptionInsuffFunds e){
                            e.display();
                        }
                        break;
                    }
                    else{
                        cout<<"Invalid ID."<<endl;
                    }
                }
                break;
            case 4:
                accid=0;
                cout<<"Enter your account ID : \n";
                cin>>accid;
                for(int i=0;i<indx;++i){
                    if(accid==arr[i]->getId()){
                        arr[i]->display();
                    }
                    break;
                }
                break;
            default:cout<<"Successfully completed.";
            break;
            
        }
    }

    return 0;
}