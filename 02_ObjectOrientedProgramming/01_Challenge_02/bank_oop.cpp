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
    bool during_creation = false;    // Boolean to check whether an account is in the process of creation

public:
    static bool validated_account;            // Static for shared use among objects to see if validated   
    static vector<BankAccount*> accounts;    // Static vector to store all created accounts
    static bool admin_privileges;           // Validation flag for admin privileges
    static bool logged_out;                // Static flag to check whether account is logged out

    // Constructor: Allocate memory for all attributes
    BankAccount():
        accountID(new string()),
        accountHolderName(new string()),
        password(new string()),
        balance(new double(0.0)) {
        accounts.push_back(this); // Add the newly created account to the global list
    }

    BankAccount(string name, string pass):
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
    bool isValidated() const { return validated; }

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
        during_creation = true;  // Set flag to true while the account is in the process of being created
        validated = false;       // Reset validated flag to false to require validation after account is created
        string name, pass;
        cout << "Please provide the account holder's name: ";
        getline(cin, name);

        cout << "Please provide a password for your bank account: ";
        getline(cin, pass);

        string ID = accountHolderName->substr(0, accountHolderName->find(' ')) + to_string(randomNumberGenerator());
        setAccountInformation(ID, name, pass);

        cout << "\nYour account has been successfully created! Here is your account information:\n";
        displayAccountInformation();

        during_creation = false; // Reset flag after account creation
}


    BankAccount* validateUser() {
        string attempted_name, attempted_password, attempted_ID;
        cout << "Enter Account Holder's Name: ";
        getline(cin, attempted_name);
        cout << "Enter Account Password: ";
        getline(cin, attempted_password);
        cout << "Enter Account ID: ";
        getline(cin, attempted_ID);

        for (BankAccount* account : accounts) {
            if (attempted_name == *account->accountHolderName && 
                attempted_password == *account->password && 
                attempted_ID == *account->accountID) {
                account->validated = true;
                cout << "Validation successful! You are now logged in." << endl;
                return account;
            }
        }
        cout << "\nValidation failed! Incorrect credentials." << endl;
        return nullptr;
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
	if (!(accountID->empty())){
            cout << "Your account (ID: " << *accountID << ") belonging to " << *accountHolderName << " has been terminated." << endl;
	}
        delete accountID;
        delete accountHolderName;
        delete password;
        delete balance;
    }
};

bool BankAccount::admin_privileges = false;
bool BankAccount::validated_account = false;
bool BankAccount::logged_out = false;
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

void redirect(BankAccount*& currentAccount, string choice) {
    static BankAccount* validatedAccount = nullptr; // Make validatedAccount static to retain state
    if ((!((choice == "1") || !(choice == "2"))) && BankAccount::logged_out == true) {
	cout << "You may only create a new account because you are currently logged out." << endl;
	return;
    }

    if (choice == "1") {
        if(BankAccount::validated_account){
            validatedAccount->displayAccountInformation();
        } else{
            cout << "You are being redirected to create a bank account." << endl;
	    BankAccount* newAccount = new BankAccount();
	    newAccount->createBankAccount();
	    BankAccount::logged_out = false;
        }
    } else if (choice == "2") {
        cout << "You are being redirected to validate your credentials." << endl;
        BankAccount* tempAccount = currentAccount->validateUser();
	if (tempAccount) {
	    validatedAccount = tempAccount; // Store validated account
            delete currentAccount;
            currentAccount = validatedAccount;
	    BankAccount::validated_account = true;
	    cout << "User validation successful!" << endl;
	}
	} else if (choice == "3") {
            cout << "You are being redirected to your account's information display." << endl;
            if (BankAccount::validated_account) {
                validatedAccount->displayAccountInformation();
		return;
            }
	    cout << "ERROR: You must validate your account first!" << endl;
	} else if (choice == "4") {
            cout << "You are being redirected to the deposit utility function." << endl;
            if (BankAccount::validated_account) {
                validatedAccount->bankDeposit();
		return;
            }
            cout << "ERROR: You must validate your account first!" << endl;
	} else if (choice == "5") {
            cout << "You are being redirected to the withdrawal utility function." << endl;
            if (BankAccount::validated_account) {
                validatedAccount->bankWithdrawal();
		return;
            }
            cout << "ERROR: You must validate your account first!" << endl;
        } else if (choice == "6") {
            cout << "You are being redirected to view all accounts." << endl;
            if (BankAccount::admin_privileges == true) {
                BankAccount::viewAllInformation();
            }
	    cout << "ERROR: You must validate as an admin user to gain admin privileges!" << endl;
	} else if (choice == "7") {
            cout << "You are being redirected to log out." << endl;
	    if (BankAccount::validated_account) {
                validatedAccount->logOut();
	        validatedAccount = nullptr;
		BankAccount::logged_out = true;
		return;
	    }
	    cout << "ERROR: You are not validated yet!" << endl;
	} else {
	    cout << "Invalid option. Please try again." << endl;
	    }
	}


int main() {
    srand(time(0)); // Seed the random number generator
    BankAccount* currentAccount = new BankAccount();
    string input = "";
    cout << "You may perform as many operations or interactions as you would like. Please use the 'end' keyword to exit the program." << endl;
    while (input != "end") {
        input = menu();
        if (input != "end") {
            redirect(currentAccount, input);
        }
    }
    delete currentAccount;
    return 0;
}

