#include<iostream>
using namespace std;

class Stack{
    // private:
    
    public:
    int *arr;
    int top;
    int size;
    Stack(){
        size=5;
        arr=new int[size];
        top=-1;
    }
    Stack(int s){
        size=s;
        arr=new int[size];
        top=-1;
    }
    void destroy(){
        delete[] arr;
    }
    void push(int x){
        if(top==size-1){
            cout<<"stack overflow"<<endl;
        }
        top++;
        arr[top]=x;
    }
    int pop(){
        if(top==-1){
            cout<<"stack overflow"<<endl;
        }
        return arr[top--];
    }
    int peek(){
        int p=arr[top];
        return p;
    }
    bool isEmpty(){
        if(top==-1){
            cout<<"Empty"<<endl;
            return true;
        }
        return false;
    }
    bool isFull(){
        if(top==(size-1)){
            cout<<"Full"<<endl;
            return true;
        }
        return false;
    }
    void print(){
        if(top<=size-1){
            for(int i=top;i>=0;--i){
                cout<<arr[i]<<endl;
            }
        }
    }
    
};


int main(){
    Stack s1;
    s1.push(5);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(3);
    s1.push(3);
    // s1.push(7);
    // cout<<"Pop out - "<<s1.pop()<<endl;
    cout<<"Peek element - "<<s1.peek()<<endl;
    cout<< (s1.isEmpty()==0) ? "Not Empty" : "Empty";
    // cout<<s1.isFull()<<endl;
    s1.print();
    s1.destroy();
    return 0;
}