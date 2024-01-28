#include<iostream>
using namespace std;
struct BankAccount {
    int accno;
    string name;
    int amd;
};
BankAccount b1[100];
int count = 0; 
void create() {
    if (count >= 100) {
        cout << "Maximum number of accounts reached." << endl;
        return;
    }
    cout << "Enter account number: ";
    cin >> b1[count].accno;
    cout << "Enter account holder name: ";
    cin >> b1[count].name;
    cout << "Enter amount: ";
    cin >> b1[count].amd;
    count++;
    cout << "Account created successfully." << endl;
}
void display() {
    if (count == 0) {
        cout << "No accounts found." << endl;
        return;
    }
    cout << "Accounts List:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Account Number: " << b1[i].accno << endl;
        cout << "Account Holder Name: " << b1[i].name << endl;
        cout << "Account Balance: " << b1[i].amd << endl;
        cout << "------------------------" << endl;
    }
}
void withdraw() {
    int accno, amount;
    cout << "Enter the account number: ";
    cin >> accno;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (b1[i].accno == accno) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Account not found." << endl;
        return;
    }
    cout << "Enter the amount to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= b1[index].amd) {
        b1[index].amd -= amount;
        cout << "Withdrawal successful.\nRemaining balance: " << b1[index].amd << endl;
    } else {
        cout << "Invalid amount or insufficient balance." << endl;
    }
}
void deposit() {
    int accno, amount;
    cout << "Enter the account number: ";
    cin >> accno;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (b1[i].accno == accno) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Account not found." << endl;
        return;
    }
    cout << "Enter the amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        b1[index].amd += amount;
        cout << "Deposit successful.\nNew balance: " << b1[index].amd << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
}
int main() {
    int choice;
    cout<<"_______________________________________________________________\n";
    cout<<"\tBank\n \t     Management\n  \t\t   \tSystem \n";
    cout<<"_______________________________________________________________\n";
    do {
        cout << "Select an option:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display Account Details" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;cout<<endl;
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                deposit();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please enter a valid number." << endl;
        }

    } while (choice != 5);

    return 0;
}