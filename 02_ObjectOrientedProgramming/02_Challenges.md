# 02 OOP Practice Challenges

These challenges are designed to help you practice object-oriented programming concepts in C++. Each challenge includes specific requirements to strengthen your understanding of OOP principles and techniques.

---

## Challenge 01: Create a Simple Bank Account System
Design a program to simulate basic banking operations using classes and objects.

### Requirements:
- Create a `BankAccount` class with attributes like `accountNumber`, `accountHolderName`, and `balance`.
- Implement methods for:
  - Depositing money.
  - Withdrawing money (ensure the balance doesn't go negative).
  - Displaying account details.
- Allow the user to perform multiple operations until they choose to exit.

---

## Challenge 02: Build an Employee Management System
Write a program to manage employee data using inheritance and polymorphism.

### Requirements:
- Create a base class `Employee` with attributes like `name` and `id`.
- Derive two classes `FullTimeEmployee` and `PartTimeEmployee` from `Employee`.
- Each derived class should override a method to calculate and display salary based on specific criteria:
  - Full-time employees have a fixed monthly salary.
  - Part-time employees are paid hourly.
- Use dynamic memory allocation to create employee objects and display their details.

---

## Challenge 03: Develop a Smart Inventory Management System
Create a program to manage an advanced inventory system with multiple features using encapsulation, inheritance, and dynamic memory.

### Requirements:
- Create a base class `Item` with attributes like `name`, `ID`, `price`, and `quantity`.
- Derive specialized classes such as `PerishableItem` and `NonPerishableItem`:
  - `PerishableItem` should include an additional attribute for expiration date.
  - `NonPerishableItem` can have a category attribute (e.g., electronics, furniture).
- Implement functionality for:
  - Adding new items to the inventory.
  - Removing items from the inventory.
  - Updating item details (price, quantity, or expiration date).
  - Displaying inventory data sorted by category or expiration date.
- Use a menu-driven interface to interact with the system and allow multiple operations until the user chooses to exit.

---

