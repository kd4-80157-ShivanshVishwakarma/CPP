#include<stdio.h>

struct Date
{
    int date;
    int month;
    int year;
};

void initDate(struct Date *ptrDate){
    ptrDate->date=22;
    ptrDate->month=9;
    ptrDate->year=2023;

}
void printDateOnConsole(struct Date *ptrDate){
    printf("Today's Date : %d-%d-%d",ptrDate->date,ptrDate->month,ptrDate->year);
}

void acceptDateFromConsole(struct Date* ptrDate) {
    printf("Enter the date : ");
    scanf("%d", &ptrDate->date);
    
    printf("Enter the month : ");
    scanf("%d", &ptrDate->month);
    
    printf("Enter the year : ");
    scanf("%d", &ptrDate->year);
}
int main(){
    struct Date D;

    // initDate(&D);
    int choice;
    printf("Enter the choice : ");
    do {
        scanf("%d",&choice);
        // printf()

        switch (choice) {
            case 1:
                initDate(&D);
                printf("Initialize the date : \n");
                break;
            case 2:
                printDateOnConsole(&D);
                break;
            case 3:
                acceptDateFromConsole(&D);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice entered\n");
                break;
        }
    } while (choice!=4);

    return 0;   

}