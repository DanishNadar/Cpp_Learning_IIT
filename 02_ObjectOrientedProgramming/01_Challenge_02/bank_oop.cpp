#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std; // This line will help avoid repetitively referencing std::

class BankAccount{
    private:
        string* accountID; // Creating a string pointer to the accountID attribute
        string* accountHolderName; // Creating a string pointer to the accountHolderName attribute
        string* password; // Creating a string pointer to the password attribute
        double* balance; // Creating a double pointer to the balance attribute
        bool validated = false;
    public:
        // instantiating an attribute to a null pointer, nullptr, instantiates it with no real starting value
        BankAccount() : accountID(nullptr), accountHolderName(nullptr), password(nullptr), balance(new double(0.0)) {}
        BankAccount(string name, string pass) : accountHolderName(new string(name)), password(new string(pass)), balance(new double(0.0)) {}

        void setAccountHolderName(string name) { *accountHolderName = name; }
        void setPassword(string pass) { *password = pass; }
        void setAccountID(string ID) { *accountID = ID; }
        string getAccountHolderName() { return *accountHolderName; }
        string getPassword() { return *password; }

        int randomNumberGenerator() {
            // Seed the random number generator with the current time
            srand(time(0));

            // Generate a random number between 1 and 10000
            int random_number = rand() % 10000 + 1;
            return random_number;
        }

        // Dynamically allocating memory for account details including ID, name, and password
        void setAccountInformation(string ID, string name, string pass) {
            *accountID = ID;
            *accountHolderName = name;
            *password = pass;
        }

        void displayAccountInformation() {
            // Summarizing account details for the user
            cout << "The following is your bank account information. Please remember this for later access to your bank account for any interactions." << endl;
            cout << "Account ID: " << *accountID << endl;
            cout << "Account Holder's Name: " << *accountHolderName << endl;
            cout << "Account Password: " << *password << endl;
            cout << "Account Balance: " << *balance << endl;
        }

        // Creating a bank account using existing information or requesting necessary information if unknown
        void createBankAccount() {
            string name, pass;
            if (this->accountHolderName == nullptr || this->accountHolderName->empty()) {
                cout << "Please provide the account holder's name: " << endl;
                cin >> name; // Take user input for holder's name
                setAccountHolderName(name);
            }
            if (this->password == nullptr || this->password->empty()) {
                cout << "Please provide a password for your bank account: " << endl;
                cin >> pass; // Take user input for password
                setPassword(pass);
            }
            // Creating the accountID by taking the first item from accountHolderName and concatenating that with a random number ranging from 1 to 10000
            string accountID = this->accountHolderName->substr(0, this->accountHolderName->find(' ')) + to_string(randomNumberGenerator());
            setAccountInformation(accountID, *accountHolderName, *password);
            // Summarizing account details for the user
            cout << "The following is your bank account information. Please remember this for later access to your bank account for any interactions." << endl;
            displayAccountInformation();
        }

        void validateUser() {
            bool validation_success = true;
            while (validation_success == true) {
                string attempted_name, attempted_password, attempted_ID;
                cout << "Enter Account Holder's Name: ";
                cin >> attempted_name;
                if (attempted_name != *accountHolderName) {
                    validationFailure();
                    validation_success = false;
                }
                cout << "Enter Account Password: ";
                cin >> attempted_password;
                if (attempted_password != *password) {
                    validationFailure();
                    validation_success = false;
                }
                cout << "Enter Account ID: ";
                cin >> attempted_ID;
                if (attempted_ID != *accountID) {
                    validationFailure();
                    validation_success = false;
                }
                if (validation_success == true) {
                    validated = true;
                }
            }
        }

        void validationFailure() {
            cout << "You entered incorrect credentials, so your validation failed!";
            validated = false;
        }

        void bankDeposit(double newDeposit) {
            if (validated == true) {
                *balance += newDeposit;
                cout << "Your new bank balance is: $" << *balance << endl;
            }
        }

        void bankDeposit() {
            double depositAmount;
            if (validated == true) {
                cout << "How much USD would you like to deposit?" << endl;
                cin >> depositAmount;
                *balance += depositAmount;
                cout << "Your new bank balance is $" << *balance << endl;
            }
        }

        void bankWithdrawal(double withdrawalAmount) {
            if (validated == true) {
                if (*balance >= withdrawalAmount) {
                    *balance -= withdrawalAmount;
                    cout << "Your new bank balance is $" << *balance << endl;
                } else {
                    cout << "Your bank balance is not sufficient to make a withdrawal of $" << withdrawalAmount << ". You only have $" << *balance << " left in your bank balance." << endl;
                }
            }
        }

        void bankWithdrawal() {
            double withdrawalAmount;
            if (validated == true) {
                cout << "How much USD would you like to withdraw?" << endl;
                cin >> withdrawalAmount;
                if (*balance >= withdrawalAmount) {
                    *balance -= withdrawalAmount;
                    cout << "Your new bank balance is $" << *balance << endl;
                } else {
                    cout << "Your bank balance is not sufficient to make a withdrawal of $" << withdrawalAmount << ". You only have $" << *balance << " left in your bank balance." << endl;
                }
            }
        }

        ~BankAccount() {
            delete accountID;
            delete accountHolderName;
            delete password;
            delete balance;
        }
	

};
string menu(){
    cout << "Pick one of the interaction options:\n" << "Option (1): Create Bank Account\n" << "Option (2): Validate User\n" >> "Option (3): Display Account Information\n" << "Option (4): Deposit into Account\n" << "Option (5): Withdraw from Account" >> "Write the number in parenthesis corresponding to and following your chosen option." >> endl;
    cin >> user_input;
    return user_input;
}
void redirect(string choice){
    switch(choice){
        case "1": // Create Bank Account
	    cout << "You are being redirected to create a bank account." << endl;
            createBankAccount();
	case "2": // Validate User
	    cout << "You are being redirected to validate your credentials." << endl;
	    validateUser();
	case "3": // Display Account Inforamtion
	    cout << "You are being redirected to your account's information display" >> endl;
            displayAccountInformation();
	case "4": // Deposit into Account
            cout << "You are being redirected to the deposit utility function." << endl;
	    bankDeposit();
	case "5" // Withdrawal from Account
            cout << "You are being redirected to the withdrawal utility function." << endl;
	    bankWithdrawal();
    }
}

int main(){
    string input = "";
    cout << "You may perform as many operations or interactions as you would like. Please use the 'end' keyword to exit from the program." << endl;
    while(input!="end"){
    	input = menu();
	redirect(input);
    }
}

