#include <iostream>
#include <string>
#include <vector> // To keep track of all created accounts
#include <cstdlib>
#include <ctime>

using namespace std;

class BankAccount {
private:
    string* accountID;               // Pointer to dynamically store the account ID
    string* accountHolderName;       // Pointer to dynamically store the account holder's name
    string* password;                // Pointer to dynamically store the account password
    double* balance;                 // Pointer to dynamically store the account balance
    bool validated = false;          // Validation flag for user authentication
    bool admin_privileges = false;   // Validation flag for admin privileges
    static bool during_creation;  // Static for shared use
    static vector<BankAccount*> accounts; // Static vector to store all created accounts

public:
    static bool during_creation; // Static for shared use
    // Constructor: Allocate memory for all attributes
    BankAccount() :
        accountID(new string()),
        accountHolderName(new string()),
        password(new string()),
        balance(new double(0.0)) {
        accounts.push_back(this); // Add the newly created account to the global list
    }

    BankAccount(string name, string pass) :
        accountID(new string()),
        accountHolderName(new string(name)),
        password(new string(pass)),
        balance(new double(0.0)) {
        accounts.push_back(this); // Add the newly created account to the global list
    }

    void setAccountHolderName(string name) {
        if (!accountHolderName) { accountHolderName = new string(); }
        *accountHolderName = name;
    }

    void setPassword(string pass) {
        if (!password) { password = new string(); }
        *password = pass;
    }

    void setAccountID(string ID) {
        if (!accountID) { accountID = new string(); }
        *accountID = ID;
    }

    string getAccountHolderName() { return *accountHolderName; }
    string getPassword() { return *password; }

    int randomNumberGenerator() {
        return rand() % 10000 + 1; // Generate a random number between 1 and 10000
    }

    void setAccountInformation(string ID, string name, string pass) {
        setAccountID(ID);
        setAccountHolderName(name);
        setPassword(pass);
    }

    void displayAccountInformation() {
        if (!validated && !during_creation) {
            cout << "You must validate your account to view information." << endl;
            return;
        }
        cout << "\nThe following is your bank account information. Please remember this for later access to your bank account for any interactions." << endl;
        cout << "Account ID: " << *accountID << endl;
        cout << "Account Holder's Name: " << *accountHolderName << endl;
        cout << "Account Password: " << *password << endl;
        cout << "Account Balance: $" << *balance << endl;
    }

    void createBankAccount() {
        string name, pass;
        if (accountHolderName->empty()) {
            cout << "Please provide the account holder's name: ";
            getline(cin, name);
            setAccountHolderName(name);
        }
        if (password->empty()) {
            cout << "Please provide a password for your bank account: ";
            getline(cin, pass);
            setPassword(pass);
        }
        string ID = accountHolderName->substr(0, accountHolderName->find(' ')) + to_string(randomNumberGenerator());
        setAccountInformation(ID, *accountHolderName, *password);
        displayAccountInformation();
    }

    void validateUser() {
        string attempted_name, attempted_password, attempted_ID;
        cout << "Enter Account Holder's Name: ";
        getline(cin, attempted_name);
        cout << "Enter Account Password: ";
        getline(cin, attempted_password);
        cout << "Enter Account ID: ";
        getline(cin, attempted_ID);

        if (attempted_name == "admin" && attempted_password == "12345678" && attempted_ID == "admin1234") {
            admin_privileges = true;
            cout << "You have logged in as an authorized administrative user and have obtained admin privileges." << endl;
            return;
        }

        if (attempted_name == *accountHolderName && attempted_password == *password && attempted_ID == *accountID) {
            validated = true;
            cout << "Validation successful!" << endl;
        } else {
            cout << "\nValidation failed! Incorrect credentials." << endl;
            validated = false;
        }
    }

    void bankDeposit() {
        if (validated) {
            double depositAmount;
            cout << "How much USD would you like to deposit? ";
            cin >> depositAmount;
            cin.ignore();
            *balance += depositAmount;
            cout << "Your new bank balance is $" << *balance << endl;
        } else {
            cout << "You must validate your account first." << endl;
        }
    }

    void bankWithdrawal() {
        if (validated) {
            double withdrawalAmount;
            cout << "How much USD would you like to withdraw? ";
            cin >> withdrawalAmount;
            cin.ignore();
            if (*balance >= withdrawalAmount) {
                *balance -= withdrawalAmount;
                cout << "Your new bank balance is $" << *balance << endl;
            } else {
                cout << "Your bank balance is insufficient. You only have $" << *balance << " in your account." << endl;
            }
        } else {
            cout << "You must validate your account first." << endl;
        }
    }

    static void viewAllInformation() {
        if (accounts.empty()) {
            cout << "No accounts have been created yet." << endl;
            return;
        }
        cout << "\nListing all accounts in memory:\n";
        for (size_t i = 0; i < accounts.size(); ++i) {
            cout << "Account #" << i + 1 << ":\n";
            accounts[i]->displayAccountInformation();
            cout << "-------------------" << endl;
        }
    }

    void logOut() {
        if (validated) {
            cout << "You have been logged out." << endl;
            validated = false;
        } else {
            cout << "You are not logged in." << endl;
        }
    }

    ~BankAccount() {
        cout << "Your account (ID: " << *accountID << ") belonging to " << *accountHolderName << " has been terminated." << endl;
        delete accountID;
        delete accountHolderName;
        delete password;
        delete balance;
    }
};

vector<BankAccount*> BankAccount::accounts;

string menu() {
    cout << "\nPick one of the interaction options:\n"
         << "Option (1): Create Bank Account\n"
         << "Option (2): Validate User\n"
         << "Option (3): Display Account Information\n"
         << "Option (4): Deposit into Account\n"
         << "Option (5): Withdraw from Account\n"
         << "Option (6): View All Accounts (Admin)\n"
         << "Option (7): Log out of account\n"
         << "Write the number in parenthesis corresponding to and following your chosen option."
         << endl;
    string user_input;
    getline(cin, user_input);
    return user_input;
}

void redirect(BankAccount& account, string choice) {
    if (choice == "1") {
        cout << "You are being redirected to create a bank account." << endl;
	BankAccount::during_creation = true;
        account.createBankAccount();
    } else if (choice == "2") {
        cout << "You are being redirected to validate your credentials." << endl;
        account.validateUser();
    } else if (choice == "3") {
        cout << "You are being redirected to your account's information display." << endl;
        account.displayAccountInformation();
    } else if (choice == "4") {
        cout << "You are being redirected to the deposit utility function." << endl;
        account.bankDeposit();
    } else if (choice == "5") {
        cout << "You are being redirected to the withdrawal utility function." << endl;
        account.bankWithdrawal();
    } else if (choice == "6") {
        cout << "You are being redirected to view all accounts." << endl;
        BankAccount::viewAllInformation();
    } else if (choice == "7") {
        account.logOut();
    } else {
        cout << "Invalid option. Please try again." << endl;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    BankAccount account;
    string input = "";
    cout << "You may perform as many operations or interactions as you would like. Please use the 'end' keyword to exit the program." << endl;
    while (input != "end") {
        input = menu();
        if (input != "end") {
            redirect(account, input);
        }
    }
    return 0;
}

