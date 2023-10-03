#include<iostream>
using namespace std;

class Matrix{
    private:
    int **arr;
    int row;
    int col;
    public:
    Matrix(){
        this->row=2;
        this->row=3;
        this->arr=new int*[row];
        for(int i=0;i<row;++i){
            this->arr[i]=new int[col];
        }
        
    }
    Matrix(int row,int col):row(row),col(col){
        this->arr=new int*[row];

        for(int i=0;i<row;++i){
            this->arr[i]=new int[col];
        }
    
    }
    ~Matrix(){
        for(int i=0;i<row;++i){
            delete[] arr[i];
            
        }
        delete arr;
       
    }
    void acceptMatrix(){
        //User input
        cout<<"Enter the matrix1 values : "<<endl;
        for(int i=0;i<this->row;++i){
            for(int j=0;j<this->col;++j){
                cin>>this->arr[i][j];
            }
        }


    }
    void add(Matrix *m1, Matrix *m2){
        for(int i=0;i<this->row;++i){
            for(int j=0;j<this->col;++j){
                this->arr[i][j]=m1->arr[i][j]+m2->arr[i][j];
            }
        }
    }
    void subtract(Matrix *m1, Matrix *m2){
        for(int i=0;i<this->row;++i){
            for(int j=0;j<this->col;++j){
                this->arr[i][j]=m1->arr[i][j]-m2->arr[i][j];
            }
        }
    }
    void multiply(Matrix *m1, Matrix *m2){
        for(int i=0;i<this->row;++i){
            for(int j=0;j<this->col;++j){
                this->arr[i][j]=0;
                for(int k=0;k<this->row;++k){
                    this->arr[i][j]+=m1->arr[i][k]*m2->arr[k][j];
                }
                
            }
        }
    }
    void transpose(Matrix *m1){
        for(int i=0;i<this->row;++i){
            for(int j=0;j<this->col;++j){
                this->arr[i][j]=m1->arr[j][i];
            }
        }
        cout<<"Transpose "<<endl;
        for(int i=0;i<this->row;++i){
            for(int j=0;j<this->col;++j){
                cout<<this->arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void print(){
        cout<<"Print array :"<<endl;
        for(int i=0;i<this->row;++i){
            for(int j=0;j<this->col;++j){
                cout<<this->arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int row,col;
    cout<<"Enter row and col : "<<endl;
    cin>>row>>col;
    // int *arr=new int[row][col];
    Matrix m1(row,col);
    m1.acceptMatrix();
    Matrix m2(row,col);
    m2.acceptMatrix();
    Matrix combine(row,col);
    // combine.add(&m1,&m2);
    combine.subtract(&m1,&m2);
    combine.multiply(&m1,&m2);
    // combine.transpose(&m1);
    combine.print();
    // m1.print();
    // m2.print();
    // Matrix m2(row,col);
    // c1.acceptMatrix();
    // c1.multiply();
    // c1.add();
    // c1.transpose();
    
    return 0;
}