#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std; // This line will help avoid repetitively referencing std::

class BankAccount {
private:
    string* accountID; // Creating a string pointer to the accountID attribute
    string* accountHolderName; // Creating a string pointer to the accountHolderName attribute
    string* password; // Creating a string pointer to the password attribute
    double* balance; // Creating a double pointer to the balance attribute
    bool validated = false;
    bool admin_validation = false;

public:
    // Constructor: Allocate memory for all attributes
    BankAccount() 
        : accountID(new string()), 
          accountHolderName(new string()), 
          password(new string()), 
          balance(new double(0.0)) {}

    BankAccount(string name, string pass) 
        : accountID(new string()), 
          accountHolderName(new string(name)), 
          password(new string(pass)), 
          balance(new double(0.0)) {}

    // Safeguarded setters that allocate memory if needed
    void setAccountHolderName(string name) { 
        if (!accountHolderName) accountHolderName = new string();
        *accountHolderName = name; 
    }

    void setPassword(string pass) { 
        if (!password) password = new string();
        *password = pass; 
    }

    void setAccountID(string ID) { 
        if (!accountID) accountID = new string();
        *accountID = ID; 
    }

    string getAccountHolderName() { return *accountHolderName; }
    string getPassword() { return *password; }

    int randomNumberGenerator() {
        srand(time(0)); // Seed the random number generator with the current time
        return rand() % 10000 + 1; // Generate a random number between 1 and 10000
    }

    // Dynamically allocating memory for account details including ID, name, and password
    void setAccountInformation(string ID, string name, string pass) {
        setAccountID(ID);
        setAccountHolderName(name);
        setPassword(pass);
    }

    void displayAccountInformation() {
        cout << "\nThe following is your bank account information. Please remember this for later access to your bank account for any interactions." << endl;
        cout << "Account ID: " << *accountID << endl;
        cout << "Account Holder's Name: " << *accountHolderName << endl;
        cout << "Account Password: " << *password << endl;
        cout << "Account Balance: " << *balance << endl;
    }

    void createBankAccount() {
        string name, pass;
        if (accountHolderName->empty()) {
            cout << "Please provide the account holder's name: " << endl;
            cin >> name; 
            setAccountHolderName(name); // Set account holder's name
        }
        if (password->empty()) {
            cout << "Please provide a password for your bank account: " << endl;
            cin >> pass;
            setPassword(pass); // Set password
        }
        string accountID = accountHolderName->substr(0, accountHolderName->find(' ')) + to_string(randomNumberGenerator());
        setAccountInformation(accountID, *accountHolderName, *password); // Assign account information
        displayAccountInformation(); // Show details to the user
    }

    void validateUser() {
        string attempted_name, attempted_password, attempted_ID;
        cout << "Enter Account Holder's Name: ";
        cin >> attempted_name;
        cout << "Enter Account Password: ";
        cin >> attempted_password;
        cout << "Enter Account ID: ";
        cin >> attempted_ID;

        if (attempted_name == *accountHolderName && attempted_password == *password && attempted_ID == *accountID) {
            validated = true;
            cout << "Validation successful!" << endl;
        } else {
            validationFailure();
        }
    }
    
    void adminValidation(){
        string attempted_username, attempted_password;
	cout << "Enter username: ";
	cin >> attempted_username;
	cout << "Enter password: ";
	cin >> attempted_password;
	
	if(attempted_username == "admin" && attemmpted_password == "12345678"){
	    admin_validation = true;
	}
    }

    void validationFailure() {
        cout << "\nYou entered incorrect credentials, so your validation failed!\n" << endl;
        validated = false;
    }

    void bankDeposit() {
        if (validated) {
            double depositAmount;
            cout << "How much USD would you like to deposit?" << endl;
            cin >> depositAmount;
            *balance += depositAmount;
            cout << "Your new bank balance is $" << *balance << endl;
        } else {
            cout << "You must validate your account first." << endl;
        }
    }

    void bankWithdrawal() {
        if (validated) {
            double withdrawalAmount;
            cout << "How much USD would you like to withdraw?" << endl;
            cin >> withdrawalAmount;
            if (*balance >= withdrawalAmount) {
                *balance -= withdrawalAmount;
                cout << "Your new bank balance is $" << *balance << endl;
            } else {
                cout << "Your bank balance is not sufficient to make a withdrawal of $" << withdrawalAmount << ". You only have $" << *balance << " left in your bank balance." << endl;
            }
        } else {
            cout << "You must validate your account first." << endl;
        }
    }

    ~BankAccount() {
        delete accountID;
        delete accountHolderName;
        delete password;
        delete balance;
    }
};

string menu() {
    cout << "\nPick one of the interaction options:\n"
         << "Option (1): Create Bank Account\n"
         << "Option (2): Validate User\n"
         << "Option (3): Display Account Information\n"
         << "Option (4): Deposit into Account\n"
         << "Option (5): Withdraw from Account\n"
	 << "Option (6) Validate as an Administratie User.\n"
         << "Write the number in parenthesis corresponding to and following your chosen option." 
	 << endl;
    string user_input;
    cin >> user_input;
    return user_input;
}

void redirect(BankAccount& account, string choice) {
    if (choice == "1") {
        cout << "You are being redirected to create a bank account." << endl;
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
    } else if (choice == "6"){
        cout << "You are being redirected to the Admin Validation System." << endl;
	account.adminValidation();
    }else{
	cout << "Invalid option. Please try again." << endl;
    }
    if (admin_validation == true && chioce == "7"){
        cout << "You are being redirected to view all user information." << endl;
	account.viewAllInformation();
    }
}

int main() {
    BankAccount account;
    string input = "";
    cout << "You may perform as many operations or interactions as you would like. Please use the 'end' keyword to exit from the program." << endl;
    while (input != "end") {
        input = menu();
        if (input != "end") {
            redirect(account, input);
        }
    }
    return 0;
}

