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
	bool validated = false;
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
	    *accountID = new string(ID);
	    *accountHolderName = new string(name)
	    *password = new string(password)
	}
	
	void displayAccountInformation(){
            // Summarizing account details for the user
	    cout << "The following is your bank account information. Please remember this for later access to your bank account for any interactions." << endl;
	    cout << "Account ID: " << *accountID << endl;
	    cout << "Account Holder's Name: " << *accountHolderName << endl;
	    cout << "Account Password: " << *password << endl;
	    cout << "Account Balance: " << *balance << endl;
	}

        // Creating a bank account using existing information or requesting necessary information if unkown
	void createBankAccount(){
	    if(this->accountHolderName.empty()){
	        cout << "Please provide the account holder's name: " << endl;
		cin >> name; // Take user input for holder's name
	        setAcountHolderName(name);
	    }
	    if(this->password.empty()){
	        cout << "Please provide a password for your bank account: " << endl;
		cin >> pass; // Take user input for password
		setPaswowrd(pass);
	    }
	    // Creating the accountID by taking the first item from accountHolderName and concatenating that with a random number ranging from 1 to 10000
	    accountID = this->accountHolderName.substr(0,accountHolderName.find(' ')) << randomNumberGenerator() << endl;
	    setAccountInformation(accountID, name, pass);
	    // Summarizing account details for the the user
	    cout << "The following is your bank account information. Please remember this for later access to your bank account for any interactions." << endl;
	    displayAccountInformation();
	}

	void validateUser(){
	    validation_success = true
	    while(validation_success == true){
	        cout << "Enter Account Holder's Name: ";
	        cin >> attempted_name;
	        if(attempted_name != *password){
	            validationFailure();
		    validation_success = false;
	        }
	        cout << "Enter Account Password: ";
	        cin >> attempted_password
                if(attempted_password != *password){
	            validationFailure();
		    validation_success = false;
	        }
		cout << "Enter Account ID: ";
		cin >> attempted_ID;
		if(attempted_ID != *accountID){
		    validationFailure();
		    validation_success = false;
		}
		if(validation_success = true){
		    validated = true;
		}
	    }
	}
	void validationFailure(){
	    cout << "You entered incorrect credentials, so your validation failed!";
	    validated = false;
	}

	void bankDeposit(double newDeposit){
	    if(validated=true){
	        *balance += newDeposit;
	        cout << "Your new bank balance is: $" << *balance << endl;
	    }
	}

	void bankDeposit(){
	    if(validated=true){
	        cout << "How much USD would you like to deposit?" << endl;
	        cin >> depositAmount;
	        *balance += depositAmount;
	        cout << "Your new bank balance is $" << *balance << endl;
	    }
	}

	void bankWithdrawal(double withdrawalAmount){
	    if(validated=true){
	        if(*balance -= withdrawalAmount >= 0){
	            *balance -= withdrawalAmount;
		    cout << "Your new bank balance is $" << *balance << endl;
	        } else{
	            cout << "Your bank balance is not sufficient to make a withdrawal of $" << withdrawalAmount << ". You only have $" << *balance << "left in your bank balance." << endl;
	        }
	    }
	}
	
	void bankWithdrawal(){
	    if(validation=true){
	        cout << "How much USD would you like to withdraw?" << endl;
	        cin >> withdrawalAmount;
	        if(*balance -= withdrawalAmount >= 0){
	            *balance -= withdrawalAmount;
		    cout << "Your new bank balance is $" << *balance << endl;
	        } else{
	            cout << "Your bank balance is not sufficient to make a withdrawal of $" << withdrawalAmount << ". You only have $" << *balance << "leftr in your bank balance." << endl;
	        }
	    }

	}

};
