# PROJECT2-BMA
BMA- Bank Management Application

Bank Management System

A simple C++ Bank Management System that performs basic banking operations using Object-Oriented Programming (OOP) and Binary File Handling.

#Features: 
1. Create New Account,
2. Display All Accounts,
3. Search Account,
4. Deposit Amount,
5. Withdraw Amount,
6. Check Balance,
7. Persistent Data Storage using File Handling.

#Technologies Used: 
 C++,
File Handling (fstream),
Object-Oriented Programming,
Binary Files.

#Concepts Used:
1. Classes & Objects
2. Encapsulation
3. Functions
4. File Handling
5. Binary File Operations
6. Conditional Statements
7. Loops

#How It Works: 

The system stores customer account details in a binary file named:
bank.dat

Each account contains:
Account Number,
Customer Name,
Account Balance.

#Sample Output

========== BANK MANAGEMENT SYSTEM ==========
1. Create New Account
2. Display All Accounts
3. Search Account
4. Deposit Amount
5. Withdraw Amount
6. Check Balance
7. Exit
============================================
Enter Your Choice : 1

Enter Account Number : 2541

Enter Customer Name  : DC
 
Enter Initial Balance: 2500

Account Created Successfully!

The data remains saved even after closing the program.

#Important Note:

If unnecessary or corrupted records appear:

1. Delete old bank.dat
2. Re-run the program

This happens because corrupted binary data may exist from previous executions.
