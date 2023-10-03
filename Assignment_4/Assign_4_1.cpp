#include<iostream>
// #include<bits/stdc++.h>
using namespace std;

class Time{

    private:
    
    int Hr;
    int Min;
    int Sec;
    public:

    Time(){
        this->Hr=15;
        this->Min=20;
        this->Sec=21;
    }
    Time(int Hr,int Min,int Sec){
        this->Hr=Hr;
        this->Min=Min;
        this->Sec=Sec;
    }
    void acceptTime(){
        cout<<"Enter hour : "<<endl;
        cin>>this->Hr;

        cout<<"Enter Min : "<<endl;
        cin>>this->Min;

        cout<<"Enter Sec : "<<endl;
        cin>>this->Sec;
    }
    int getHour(){
        return this->Hr;
    }
    int getMinute(){
        return this->Min;
    }
    int getSeconds(){
        return this->Sec;
    }
    void printTime(){
        cout<<"HR : "<<this->Hr<<"Min : "<<this->Min<<"Sec : "<<this->Sec<<endl;
    }
    /*void setHour(){
        cin>>this->Hr<<endl;
    }
    void setMin(){
        cin>>this->Min<<endl;
    }
    void setSec(){
        cin>>this->Hr<<endl;
    }
    }*/
};

int main(){
    Time **arr=new Time*[2];
    // Time 

    for(int i=0;i<2;++i){
        arr[i]=new Time();
    }
    for(int i=0;i<2;++i){
        arr[i]->acceptTime();
    }
    for(int i=0;i<2;++i){
        arr[i]->printTime();
    }
    for(int i=0;i<2;++i){
        delete[] arr[i];
    }
    delete arr;
    return 0;
}