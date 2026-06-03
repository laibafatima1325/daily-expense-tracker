#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void storeExp(string category, double amount, string note);
void addExp();
void viewExp();
void viewAllExpenses();
void viewExpensesByDate();
double totalExp();
void categoryWiseTotal();
void storeDate(string date);
void setBudget();
void budgetReport();
bool isValidDate(string date );

double amount;
string category;
string note;
string date;

int main()
{
    int choice;
    do
    {
        cout << "----------DAILY EXPENSE TRACKER----------" << endl;
        cout << " 1. Add Expense" << endl;
        cout << " 2. View Expense" << endl;
        cout << " 3. Category wise total Expense" << endl;
        cout << " 4. Overall total Expense" << endl;
        cout << " 5. Set budget" << endl;
        cout << " 6. Budget report " << endl;
        cout << " 7. Exit " << endl;
        cout << "Please enter your choice(1-7): ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter only numbers from 1 to 7: ";
            cin >> choice;
        }
        if (choice < 1 || choice > 7)
        {
            cout << "Invalid choice! Please enter a number between 1 and 7: ";
            cin >> choice;
        }
        if (choice == 1)
        {
            addExp();
        }
        else if (choice == 2)
        {
            viewExp();
        }
        else if (choice == 3)
        {
            categoryWiseTotal();
        }
        else if (choice == 4)
        {
            cout << "\n Overall Total Expense = " << totalExp()<< endl ;
        }
        else if (choice == 5)
        {
            setBudget();
        }
        else if (choice == 6)
        {
            budgetReport();
        }
    } while (choice != 7);
    return 0;
}
bool isValidDate(string date)
{
    if(date.length() != 10)
        return false;

    if(date[2] != '-' || date[5] != '-')
        return false;

    for(int i = 0; i < 10; i++)
    {
        if(i == 2 || i == 5)
            continue;

        if(date[i] < '0' || date[i] > '9')
            return false;
    }

    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    if(day < 1 || month < 1 || year < 1)
        return false;

    if(month > 12)
        return false;

    int daysInMonth[] =
    {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool leapYear =
        (year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0);

    if(leapYear)
        daysInMonth[1] = 29;

    if(day > daysInMonth[month - 1])
        return false;

    return true;
}

void addExp()
{
    int choice, option;
    string date;
    bool valid;
    cin.ignore(1000, '\n');
    do
    {
        cout << "Enter date (DD-MM-YYYY): ";
        getline(cin, date);

        valid = isValidDate(date) ;
         if(!valid)         
        {
            cout << "Invalid date! Please enter a valid date ." << endl;
        }

    } while(!valid);
    
    storeDate(date);
    do
    {
        cout << "\n------CATEGORIES------ " << endl;
        cout << "1. Food " << endl;
        cout << "2. Transport" << endl;
        cout << "3. Shopping" << endl;
        cout << "4. Bills" << endl;
        cout << "5. Health" << endl;
        cout << "6. Education" << endl;
        cout << "7. Entertainment" << endl;
        cout << "8. Other" << endl;
        cout << "Please select a category for which you want to add an expense: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter only numbers(1-8): ";
            cin >> choice;
        }
        if (choice < 1 || choice > 8)
        {
            cout << "Invalid! Please enter numbers between 1 and 8: ";
            cin >> choice;
        }
        if (choice == 1)
            category = "Food";
        else if (choice == 2)
            category = "Transport";
        else if (choice == 3)
            category = "Shopping";
        else if (choice == 4)
            category = "Bills";
        else if (choice == 5)
            category = "Health";
        else if (choice == 6)
            category = "Education";
        else if (choice == 7)
            category = "Entertainment";
        else if (choice == 8)
        {
            cin.ignore(1000, '\n');
            cout << "Enter category name: ";
            getline(cin, category);
        }
        do
        {
            cout << "Please enter amount: ";
            cin >> amount;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter numbers only" << endl;
                amount = -1;
            }
            else if (amount <= 0)
            {
                cout << "Amount must be greater than 0" << endl;
            }

        } while (amount <= 0);

        cin.ignore(1000, '\n');
        cout << "Enter a note/description of where you have spent your money: ";
        getline(cin, note);

        storeExp(category, amount, note);

        cout << "\nExpense added successfully!" << endl;
        cout << "1. Add another expense" << endl;
        cout << "2. Finish day" << endl;
        cout << "Please select an option: ";
        cin >> option;
        cin.ignore(1000, '\n');
        if (option == 2)
        {
            break;
        }
    } while (option != 2);
}
void storeExp(string category, double amount, string note)
{
    ofstream fin("expenses.txt", ios::app);
    if (!fin.fail())
    {
        fin << "Category: " << category << endl;
        fin << "Amount: " << amount << endl;
        fin << "Note: " << note << endl;
        fin << "---------------\n";
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
    if (!file.fail())
    {
        file << "===============\n";
        file << "Date: " << date << endl;
        file << "===============\n";
        file.close();
    }
    else
    {
        cout << "Error opening file!";
    }
}
void viewExp()
{
    int choice;
    cout << "\n-------------VIEW EXPENSES------------------\n";
    cout << " 1. View all expense " << endl;
    cout << " 2. view expense by date " << endl;
    cout << "Please enter your choice : ";
    cin >> choice;
    if (choice == 1)
    {
        viewAllExpenses();
    }
    else if (choice == 2)
    {
        viewExpensesByDate();
    }
    else
    {
        cout << "Invalid choice!";
    }
}
void viewAllExpenses()
{
    ifstream file("expenses.txt");
    if (file.fail())
    {
        cout << "Error opening file!" << endl;
    }
    else
    {
        string line;
        cout << "\n===== ALL EXPENSES =====\n";
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
}
void viewExpensesByDate()
{
    string date;
    string line;
    bool found = false;
    cin.ignore();
    cout << "Enter Date (DD-MM-YYYY): ";
    getline(cin, date);
    ifstream file("expenses.txt");
    if (file.fail())
    {
        cout << "Error opening file!" << endl;
        return ;
    }
    while (getline(file, line))
    {
        if (line == "Date: " + date)
        {
            found = true;

            cout << "\n===== EXPENSES FOR " << date << " =====\n";

            cout << line << endl;

            while (getline(file, line))
            {
                if (line.find("Date:") != string::npos)
                {
                    break;
                }
                else
                {
                    cout << line << endl;
                }
            }

            break;
        }
    }
    if (!found)
    {
        cout << "No expenses found for this date." << endl;
    }
    file.close();
}
void categoryWiseTotal()
{
    ifstream file("expenses.txt");

    if (file.fail())
    {
        cout << "Error opening file!" << endl;
        return ;
    }

    string word;
    string currentCategory;

    double food = 0;
    double transport = 0;
    double shopping = 0;
    double bills = 0;
    double health = 0;
    double education = 0;
    double entertainment = 0;
    double other = 0;

    while (file >> word)
    {
        if (word == "Category:")
        {
            file >> currentCategory;
        }

        else if (word == "Amount:")
        {
            double amount;
            file >> amount;

            if (currentCategory == "Food")
                food += amount;
            else if (currentCategory == "Transport")
                transport += amount;
            else if (currentCategory == "Shopping")
                shopping += amount;
            else if (currentCategory == "Bills")
                bills += amount;
            else if (currentCategory == "Health")
                health += amount;
            else if (currentCategory == "Education")
                education += amount;
            else if (currentCategory == "Entertainment")
                entertainment += amount;
            else
                other += amount;
        }
    }

    cout << "\n===== CATEGORY WISE TOTAL =====\n";
    cout << "Food: " << food << endl;
    cout << "Transport: " << transport << endl;
    cout << "Shopping: " << shopping << endl;
    cout << "Bills: " << bills << endl;
    cout << "Health: " << health << endl;
    cout << "Education: " << education << endl;
    cout << "Entertainment: " << entertainment << endl;
    cout << "Other: " << other << endl;

    file.close();
}
double totalExp()
{
    ifstream file("expenses.txt");

    if (file.fail())
    {
        cout << "Error opening file!" << endl;
        return 0 ;
    }

    string word;
    double total = 0;

    while (file >> word)
    {
        if (word == "Amount:")
        {
            double amount;
            file >> amount;
            total += amount ;
        }
    }
    file.close();
    return total;
}
void setBudget()
{
    double budget;

    do
    {
        cout << "Enter your total  budget: ";
        cin >> budget;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            budget = -1;
            cout << "Invalid input! Numbers only." << endl;
        }
        else if (budget <= 0)
        {
            cout << "Budget must be greater than 0." << endl;
        }

    } while (budget <= 0);

    ofstream file("budget.txt");

    if (file.fail())
    {
        cout << "Error opening file!" << endl;
        return;
    }

    file << budget;
    file.close();

    cout << "Budget saved successfully!" << endl;
}
void budgetReport()
{
    ifstream budgetFile("budget.txt");

    if (budgetFile.fail())
    {
        cout << "No budget found! Please set a budget first." << endl;
        return;
    }

    double budget;
    budgetFile >> budget;
    budgetFile.close();

    double totalSpent = totalExp();

    cout << "\n========== BUDGET REPORT ==========" << endl;
    cout << "Budget Amount: " << budget << endl;
    cout << "Total Expenses: " << totalSpent << endl;

    if (totalSpent > budget)
    {
        cout << "Budget Exceeded!" << endl;
        cout << "Exceeded By: "
             << totalSpent - budget << endl;
    }
    else
    {
        cout << "Remaining Budget: "
             << budget - totalSpent << endl;
    }
}