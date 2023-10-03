#include<iostream>
using namespace std;

class operation{
    private:
    long fact=1;
    int n;
    public:

    void factorial(){
        cin>>this->n;
        if(this->n<=0)
            throw 2025;
        
        for(int i=1; i<=this->n; i++){
            fact=fact*i;
        }
    }
};

int main(){
    operation op;
    try{
        op.factorial();
    }
    catch(int er){
        if(er==2025){
            cout<<"ERROR 2025 : Num can not be 0 or less than 0\n";
        }
    }
    cout<<"successful execution"<<endl;
    return 0;
}