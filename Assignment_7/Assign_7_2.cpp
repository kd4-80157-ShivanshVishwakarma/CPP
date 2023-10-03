#include<iostream>
using namespace std;

class Product{
    protected:

    int id;
    string title;
    float price;
    char type;
    float bill;

    public:
    
    virtual void calculateBill()=0;
    // virtual void display()=0;

    /*void setId(int id){
        this->id=id;
    }
    void setTitle(string title){
        this->title=title;
    }
    void setPrice(float price){
        this->price=price;
    }
    void setType(float type){
        this->price=type;
    }*/
    void setBill(float bill){
        this->bill=bill;
    }
    int getBill(){
        return this->bill;
    }
    // void display

    void accept(){
        cout<<"Enter ID : "<<endl;
        cin>>this->id;

        cout<<"Enter Title : "<<endl;
        cin>>this->title;

        cout<<"Enter Price : "<<endl;
        cin>>this->price;
    }

};
class Book:public Product{
    private:
    string author;
    
    public:
    Book(){
        this->author="";
    }
    Book(string author){
        this->author="Alchemist";
    }
    void accept(){
        Product::accept();
        cout<<"Enter Author of Book: "<<endl;
        cin>>this->author;
    }
    void calculateBill(){
        this->setBill(this->price*(1-0.1));
    }
};

class Tape:public Product{
    private:
    string artist;
    
    public:
    Tape(){
        this->artist="";
    }
    Tape(string artist){
        this->artist="Alchemist";
    }
    void accept(){
        Product::accept();
        cout<<"Enter Artist of Tape : "<<endl;
        cin>>this->artist;
    }
    void calculateBill(){
        this->setBill(this->price*(1-0.05));
    }
};

int menu()
{
    int choice;
    cout << "--------------------" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add Books" << endl;
    cout << "2. Add Tapes" << endl;
    cout << "3. Calculate Bill" << endl;
    cout << "4. Total Bill" << endl;
    cout << "Enter Your Chocie = ";
    cin >> choice;
    return choice;
}

int main(){
    int choice;
    Product *arr[3];
    int ind = 0;
    float tot=0;
    while ((choice = menu()) != 0)
    {
        // cin>>choice;
        switch (choice)
        {
        case 1:cout<<"---------Books----------\n";
            if (ind < 3)
            {
                arr[ind] = new Book();
                arr[ind]->accept();
                arr[ind]->calculateBill();
                ind++;
            }
            else 
                cout << "*--Can not add more products--*" << endl;
            break;

        case 2:cout<<"---------Tapes----------\n";
            if (ind < 3){
                arr[ind] = new Tape();
                arr[ind]->accept();
                arr[ind]->calculateBill();
                ind++;
            }
            else
                cout << "*--Can not add more products--*" << endl;
            break;

        case 3:cout<<"Bill Calculaion : "<<endl;
            for(int i=0;i<ind;++i){
                tot+=arr[i]->getBill();
            }
            break;
        case 4:
            cout<<"Total Bill : "<<tot<<endl;
            break;
        default:
            cout << "INCORRECT INPUT." << endl;
            break;
        }
    }
    for(int i=0;i<ind;++i){
        delete arr[i];
    }
    return 0;
}