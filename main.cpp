#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void storeExp(string category, double amount, string note);
void readExp();
void addExp();
void viewExp();
void totalExp();
void categoryWiseTotal();
void storeDate(string date);

double amount;
string category;
string note;
string date;
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
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter only numbers from 1 to 5: ";
            cin>> choice;
        }
        if(choice < 1 || choice > 5)
        {
            cout<<"Invalid choice! Please enter a number between 1 and 5: ";
            cin >> choice;
        }
        if(choice == 1)
        {
            addExp();
        }
       // else if(choice == 2)
        {
       //     viewExp();
        }
       // else if (choice == 3)
        {
       //     categoryWiseTotal();
        }
       // else if (choice == 4)
        {
       //     totalExp();
        }
    }while(choice != 5);
    return 0;
}
void addExp()
{
    int choice, option;
    cout<<"Enter date(DD-MM-YYYY): ";
    cin.ignore(1000, '\n');
    getline(cin, date);
    storeDate(date);
    do{
        cout<<"\n------CATEGORIES------ " <<endl;
        cout<<"1. Food "<<endl;
        cout<<"2. Transport" <<endl;
        cout<<"3. Shopping"<<endl;
        cout<<"4. Bills" <<endl;
        cout<<"5. Health"<<endl;
        cout<<"6. Education" <<endl;
        cout<<"7. Entertainment" <<endl;
        cout<<"8. Other"<<endl;
        cout<<"Please select a category for which you want to add an expense: " ;
        cin>> choice;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter only numbers(1-8): ";
            cin>> choice;
        }
        if(choice < 1 || choice > 8)
        {
            cout <<"Invalid! Please enter numbers between 1 and 9: ";
            cin>> choice;
        }
        if(choice == 1)
            category = "Food";
        else if(choice == 2)
            category = "Transport";
        else if(choice == 3)
            category = "Shopping";
        else if(choice == 4)
            category = "Bills";
        else if(choice == 5)
            category = "Health";
        else if(choice == 6)
            category = "Education";
        else if(choice == 7)
            category = "Entertainment";
        else if(choice == 8)
        {
            cin.ignore(1000, '\n');
            cout << "Enter category name: ";
            getline(cin, category);
        }
        do{
            cout << "Please enter amount: ";
            cin >> amount;

            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter numbers only"<<endl;
                amount = -1;
            }
            else if(amount <= 0)
            {
                cout << "Amount must be greater than 0"<<endl;
            }

        } while(amount <= 0);

        cin.ignore(1000, '\n');
        cout << "Enter a note/description of where you have spent your money: ";
        getline(cin, note);

        storeExp(category, amount, note);

        cout<<"\nExpense added successfully!"<<endl;
        cout<<"1. Add another expense"<<endl;
        cout<<"2. Finish day"<<endl;
        cout<<"Please select an option: ";
        cin>> option;
        cin.ignore(1000, '\n');
        if(option == 2)
        {
            break;
        }
    }while(option != 2);
}
void storeExp(string category, double amount, string note)
{
    ofstream fin("expenses.txt", ios::app);
        if(!fin.fail())
        {
            fin << "Category: " <<category << endl;
            fin << "Amount: " <<amount << endl;
            fin << "Note: " <<note << endl;
            fin<<"---------------\n";
            fin.close();
        }
        else
        {
            cout << "\nError opening file!";
        }
}
void storeDate(string date)
{
    ofstream file("expenses.txt", ios::app);
    if(!file.fail())
    {
        file<<"===============\n";
        file<<"Date: "<<date <<endl;
        file<<"===============\n";
        file.close();
    }
    else{
        cout<<"Error opening file!";
    }
}