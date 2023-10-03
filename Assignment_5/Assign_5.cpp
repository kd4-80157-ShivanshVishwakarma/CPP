#include <iostream>
using namespace std;

namespace Nmenu{
    int menu() {
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display" << endl;
    cout << "3. Sort the Records" << endl;
    cout << "4. Search the Records" << endl;
    cin >> choice;
    return choice;
    }
}
class Student {
private:
    string name;
    string gender;
    int rollNum;
    int sub1_marks;
    int sub2_marks;
    int sub3_marks;

public:
    Student() {
        this->name = "";
        this->gender = "";
        this->rollNum = 0;
        this->sub1_marks = 0;
        this->sub2_marks = 0;
        this->sub3_marks = 0;
    }

    void acceptStudent() {
        cin.ignore();
        cout << "ENTER NAME: ";
        getline(cin, this->name);
        cout << "ENTER GENDER (M/F): ";
        cin >> this->gender;
        cout << "ENTER ROLL NUMBER: ";
        cin >> this->rollNum;
        cout << "ENTER MARKS_1: ";
        cin >> this->sub1_marks;
        cout << "ENTER MARKS_2: ";
        cin >> this->sub2_marks;
        cout << "ENTER MARKS_3: ";
        cin >> this->sub3_marks;
    }

    void print() {
        cout << "NAME: " << this->name << endl;
        cout << "GENDER: " << this->gender << endl;
        cout << "ROLL NUMBER: " << this->rollNum << endl;
        cout << "MARKS_1: " << this->sub1_marks << endl;
        cout << "MARKS_2: " << this->sub2_marks << endl;
        cout << "MARKS_3: " << this->sub3_marks << endl;
        cout << "PERCENTAGE: " << (sub1_marks + sub2_marks + sub3_marks) / 3.0 << "%" << endl;
    }

    int get_rollNum() {
        return this->rollNum;
    }
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j].get_rollNum() > arr[j + 1].get_rollNum()) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
using namespace Nmenu;
int main() {
    int choice;
    int index = 0;
    Student arr[5];

    while ((choice = menu()) != 0) {
        switch (choice) {
            case 1:
                if (index < 5) {
                    arr[index].acceptStudent();
                    cout << "Student are added" << endl;
                    index++;
                }
                break;
            case 2:
                if (index > 0) {
                    for (int i = 0; i < index; i++) {
                        arr[i].print();
                    }
                }
                break;
            case 3:
                if (index > 0) {
                    selection_sort(arr, index);
                    cout << "Records sorted." << endl;
                    for (int i = 0; i < index; i++) {
            arr[i].print();}
                }
                break;
            case 4:
                if (index > 0) {
                    int rollno;
                    cout << "Enter roll number to search: ";
                    cin >> rollno;
                    bool found = false;
                    for (int i = 0; i < index; i++) {
                        if (arr[i].get_rollNum() == rollno) {
                            cout << "Found Student" << endl;
                            arr[i].print();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Student not found." << endl;
                    }
                }
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    return 0;
}