#include <iostream>
#include <string>
using namespace std;

// Function to display multiplication tables
void tables(int user_num) {
    for (int i = 0; i < 12; i++) {
        cout << user_num << " * " << i + 1 << " = " << user_num * (i + 1) << endl;
    }
    cout << "\n";
}

int main() {
    string input;
    int user_num;

    cout << "Enter 'end' to quit the program at any time.\n";

    do {
        cout << "Enter your number: ";
        cin >> input;

        if (input == "end") {
            break; 
        }

        try {
            user_num = stoi(input); 
            tables(user_num);
        } catch (invalid_argument&) {
            cout << "Invalid input! Please enter a valid number or 'end' to quit.\n";
        }

    } while (true);

    cout << "Program ended." << endl;
    return 0;
}

