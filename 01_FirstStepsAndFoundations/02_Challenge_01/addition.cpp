#include <iostream>

int main() {
    int num1, num2, sum; // Declaring the variables I will need in this program

    std::cout << "Enter your first number: "; // Prompting the user to enter their first number
    std::cin >> num1; // Receiving user input and storing it in the variable num1

    std::cout << "Enter your second number: ";
    std::cin >> num2;

    sum = num1 + num2; // Performing addition using the addition operator, +, and storing the result in the varaible, sum

    std::cout << "The sum of your two numbers is: " << sum << std::endl; // Concatenating the output with calculated sum and using std::endl to cleanly terminate the output line

    return 0;
}

