#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std // This line will help avoid repetetively referencing std::

class BankAccount{
    private:
	string* accountID; // Creating a string pointer to the accountID attribute
        string* accountHolderName; // Creating a string pointer to the accountHolderName attribute
	string* password; // Creating a string pointer to the password attribute
        double* balance; // Creating a double pointer to the balance attribute
    public:
	// instantiating an attribute to a null pointer, nullptr, instantiates it with no real starting value
	BankAccount() = accountNumber(nullptr), accountHolderName(nullptr), password(nullptr), balance(0.0);
	BankAccount(string name, string pass) : accountHolderName(name), password(pass) {}
	void setAccountHolderName(string name){accountHolderName=name;}
	void setPassword(string pass){password=pass;}
	void setAccountID(string ID){accountID=ID;}
	string getAccountholderName(){return this->accountHolderName;}
	string getPassword(){return this->password;}

	int randomNumberGenerator(){
	    // Seed the random number generator with the current time
	    srand(time(0));

            // Generate a random number between 1 and 10000
            int random_number = rand() % 10000 + 1;
	    return random_number

	}
	// Dynamically allocating memory for account details including ID, name, and password
	void setAccountInformation(string ID, string name, string pass){
	    accountID = new string(ID);
	    accountHolderName = new string(name)
	    password = new string(password)
	}
        // Creating a bank account using existing information or requesting necessary information if unkown
	void createBankAccount(){
	    if(this->accountHolderName.empty()){
	        cout << "Please provide the account holder's name: " << endl;
		cin >> name; // Take user input for holder's name
	        setAccountHolderName(name);
	    }
	    if(this->password.empty()){
	        cout << "Please provide a password for your bank account: " << endl;
		cin >> pass; // Take user input for password
		setPaswowrd(pass);
	    }
	    // Creating the accountID by taking the first item from accountHolderName and concatenating that with a random number ranging from 1 to 10000
	    accountID = this->accountHolderName.substr(0,accountHolderName.find(' ')) << randomNumberGenerator() << endl;
	    setAccountInformation(accountID, name, pass)
	    // Summarizing account details for the user
	    cout << "The following is your bank account information. Please remember this for later access to your bank account for any interactions." << endl;
	    cout << "Account ID: " << this->accountID << endl;
	    cout << "Account Holder's Name: " << this->accountHolderName << endl;
	    cout << "Account Password: " << this->password << endl;
	    cout << "Account Balance: " << this->balance << endl;
	}
	

};
