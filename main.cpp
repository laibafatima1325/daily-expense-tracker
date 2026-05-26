#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void storeExp();
void readExp();
void addExp();
void viewExp();
void totalExp();
void categoryWiseTotal();

float amount;
string category;
const int SIZE = 100;

int main()
{
    int choice;
    do{
        cout<<"----------DAILY EXPENSE TRACKER----------" <<endl;
        cout<<" 1. Add Expense" <<endl;
        cout<<" 2. View Expense" <<endl;
        cout<<" 3. Category wise total Expense" <<endl;
        cout<<" 4. Overall total Expense" <<endl;
        cout<<" 5. Exit" <<endl;
        cout<<"Please enter your choice(1-5): ";
        cin>> choice;
        if(choice < 1 || choice > 5)
        {
            cout<<"Invalid choice! Please enter a number between 1 and 5: ";
            cin >> choice;
        }
        if(choice == 1)
        {
            addExp();
        }
        else if(choice == 2)
        {
            viewExp();
        }
        else if (choice == 3)
        {
            categoryWiseTotal();
        }
        else if (choice == 4)
        {
            totalExp();
        }
    }while(choice != 5);
    return 0;
}
void addExp()
{
    int category;
    cout<<"------CATEGORIES------ " <<endl;
    cout<<"1. Food "<<endl;
    cout<<"2. Transport" <<endl;
    cout<<"3. Shopping"<<endl;
    cout<<"4. Bills" <<endl;
    cout<<"5. Health"<<endl;
    cout<<"6. Education" <<endl;
    cout<<"7. Entertainment" <<endl;
    cout<<"8. Other"<<endl;
    cout<<"Please select a category for which you want to add an expense: " ;
    cin>> category;
}