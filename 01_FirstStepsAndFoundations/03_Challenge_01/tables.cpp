#include <iostream>
using namespace std;

// Function to display multiplication tables
void tables(int user_num) {
    for (int i = 0; i < 12; i++) {
        cout << user_num << " + " << i + 1 << " = " << user_num * (i + 1) << endl;
    }
    cout << "\n";
}

int main() {
    int user_num = 0;  // Declare user_num locally in main

    do {
        cout << "Enter your number: ";
        cin >> user_num;

        if (user_num != -1) {  // Only call tables() if user_num is not -1
            tables(user_num);
        }

    } while (user_num != -1);

    cout << "Program ended." << endl;
    return 0;
}

