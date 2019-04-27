# Accounting System

> This is a group project from HKU ENGG1340 Group 120

---

## Table of content

- [Problem Statement](#problem-statement)
- [Problem Setting](#problem-setting)
- [Teammembers](#teammembers)
- [Usage](#Usage)

---

## Problem Statement

Living in high-paced life with much pressure, people need dealing with their balance of payments data from all kinds of area to evaluate personal financial status every day, which will be extraordinarily complicated and time-consuming tasks in case operated by traditional accounting methods. Thus, a more visual and efficient accounting system aimed at solving personal financial data’s tracking and management is in sore demand.

---

## Problem Setting


### Introduction


The Accounting System focus on helping manage personal wealth efficiently.

It will provide advanced accounting operations for users, making them able to create new accounts, and further add or modify records stored in the current accounts. The system will also output the records so far, as well as statistic data of the wealth, on the demand of the users.

![](https://img.shields.io/badge/Language-C++-brightgreen.svg)


### Features


The system receives user input with different information, and launchs relevant function to store them.

	1. Set name and balance for initial accounts
	2. Add records of transaction
	3. Delete and edit

&nbsp;

Feature | Purpose
------------- | -------------
Set name and balance  | Create initial accounts which can be further operated
Add records of transaction  | Record income and expense of multiple categories from different accounts
Delete and edit | Access and modify records easily

&nbsp;

Also, the system outputs multiple statistic reports which are calculated based on the existing data. Additionally, it will evaluate the general financial status of the user.

	4. List the record
	5. Statistic reports
	6. Evaluation

&nbsp;

Feature | Purpose
------ | ------
List the record | View previous transactions with accounts, date, amount or category (all or part)
Statistic reports | Give report of users' financial state in detail, about income and expenditure, proportion and variation
Evaluation | Briefly evaluate wealth states

&nbsp;

Besides, the accounting system provides practical and user-friendly functions

	7. Budget and alert

&nbsp;

Feature | Purpose
------ | ------
Budget and alert | Alert the user if total expenditure exceeds default budget

&nbsp;

The system will launch more incredible features in the comming soon.

---

## Usage


### Step 1. Makefile


If you are using Accounting System for the first time, it's necessary to compile the executable programs from source files by reading Makefile.

Users can type in the command below to compile run.cpp

    $ make run

If succeed, your terminal will display compilation process shown below

    g++ -c run.cpp
    g++ -c account.cpp
    g++ -c accountlib.cpp
    g++ -c transaction.cpp
    g++ -c tranlib.cpp
    g++ -c AccountingSystem.cpp
    g++ run.o account.o accountlib.o transaction.o tranlib.o AccountingSystem.o -o run

Congratulations! The program has been built successfully.


### Step 2. Run the program


The executable program now is created in your folder, named **run**.

You can type in the command below to run the program in terminal.

    $ ./run

If succeed, the program will display like this

    ********************************************
    This is an ENGG1340 project of group 120
    Powered by Parry Choi and Shane Chen
    ********************************************
    Welcome to Accounting System!
    ********************************************
    1. Account
    2. Transaction
    3. Finance analysis
    Please select a function
    Enter 'Exit' to teminate
    ********************************************

Then you may choose function and enter the number, or type in **Exit** to terminate the programm.

Note that if you run the program for the first time, these words will be displayed

    No alert file is found
    No account file is found
    No transaction file is found

Don't worry, that's because your have never created any data before.

The program will output and save existing data automatically, in the file **account**, **transaction** and **alert**.
Next time when you run, it will read initialized data and add them to you current data.

This can optimize users' control and storage of their personal financial data.

---

## Functions


### Account


The Accounting System provides the basic functions **Account**, which make it possible to easily manage personal accounts.

You can simply create varied type account, modified existing accounts, list all of them and output to file on your demand.

These are also the base of **Transaction** functions, we will covered in next section.

The Account Menu is shown below

    ********************************************
    Account Menu
    1. Add an account
    2. Delete an account
    3. Get information of an account
    4. List all accounts in ascending order
    5. List all accounts in descending order
    6. Output all accounts to a file
    7. Set amount of an account
    8. Return to last page
    Please select a function
    ********************************************

You can choose the function and type in the number


#### Create an acount


For the first time you run the program, there is no initialized data. So you need to create your personal accounts.

Enter the function **Add an account**, it will show

    Please input the name of the account: Cash

You can create accounts like **Credit**, **Salary**, **Food**, or type in the name whatever you like.

In this case, we create the account named **Cash**, it has been stored in our **Sample cases**.

After enter the name of account, the program will ask you the type of such account

    Which type is the account?
    1. Expense Account
    2. Revenue Account
    3. Asset Account

In this case, we make it as an Asset Account. Type in **3**

    Account named "Cash" is created!

Firstly initialized account's amount is preset as 0 (float type).

After your account has been created, you can set its amount by **Set amount of account** function.

    Input the name of the account: Cash
    Input the amount: 75
    !WARNING! THIS ACTION WILL CHANGE THE AMOUNT OF THE ACCOUNT DIRECTLY!
    Proceed? (Y/N) Y
    Cash has been set to 75

After you create an account, you can access its status using **Get information of an account**.

    Please input the name of the account: Cash

Then the balance of such account, together with corresponding transaction records

    Account information of Cash:
    Current Balance: 75.00
    -------------Transaction History------------
    Date		Type	Balance		Account1	Account2
    20190405	Asset	40.500000	Cash		Debit
    20190413	Asset	3000.000000	Debit		Cash

We will introduce **Transaction** function to you in next section.

If you want to delete some account, choose the function **Delete an account**.

    Please input the name of the account: Cash
    !WARNING! THIS ACTION WILL DELETE THE ACCOUNT AND YOU ARE NOT ABLE TO RECOVER IT!
    Proceed? (Y/N) Y
    Account "Cash" deleted!


#### List all accounts and output to file


The program allows you to list all existing accounts in ascending and descending order.

They can also be outputed directly to file that you created.

Just simply make use of the function **List all accounts** and **Output all accounts to a file**.

Here we provide you a sample of accounts list, it can also be outputed by yourself.

    Name		Balance			Type
    Cash		75.000000		Asset
    Credit		30.000000		Expense
    Clothing	200.000000		Expense
    Healthcare	225.000000		Expense
    Salary		2000.339966		Revenue
    Debit		20000.000000		Asset

When you output them, program will ask you the file name. Here we named it as **"Accounts.txt"**.

    Input the name of the file, include file type (e.g. output.txt): Accounts.txt
    Output as "Accounts.txt"

Note: The programm will sort according to your choice when listing out the accounts, so if you want to output a sorted account file, simply list it once in the program and then output as usual paratice.

### Transaction


**Transaction** is the most powerful function with great flexibility that we provide in our program

It can help you to create **transfer** between existing personal accounts, recording **revenue** and **expense** with the outside on specific **date**. Existing transactions it stored can also be sorted accounding date, and further output to file.

The Transaction Menu is shown below

    ********************************************
    Transaction Menu
    1. Create new transaction
    2. Get transactions on specific date
    3. List all transactions from old to new
    4. List all transactions from new to old
    5. Reverse and delete a transaction
    6. Output transactions to a file
    7. Return to last page
    Please select a function
    ********************************************


#### Create a transaction

First we introduce you how to create a transaction.
Enter the function **Create new transaction**, program will ask you which type of transaction you want

    Which kinds of transaction you want to record?
    1. Expense
    2. Revenue
    3. Asset transfer

Here we provide three kinds of transactions, which has covered most of daily demand

In this case, assuming you want to withdraw cash $40.5 from the debit account. Thus we choose **Asset transfer**.

Then the function will record necessary infomation of transactions to make it clear

    Please enter transaction infomation
    Date (YYYYMMDD): 20190405
    Asset account 1: Cash
    Asset account 2 (input "none" if no asset account): Debit
    Amount: 40.5
    This transaction is created successfully!

A transaction of $40.5 from the debit account to cash account has been created successfully!

The program allow you to record **expense** and **revenue** without the asset account.

Here we provide a case of gain the salary of $3000. For the **Asset account**, type in **none**.

    Which kinds of transaction you want to record?
    1. Expense
    2. Revenue
    3. Asset transfer

    2

    Please enter transaction infomation
    Date (YYYYMMDD): 20190420
    Revenue account: Salary
    Asset account (input "none" if no asset account): none
    Amount: 3000
    This transaction is created successfully!

To get the transactions on specific date, use the function **Get transactions on specific date**.

In this case, we'd like to get all transactions on April 5th, 2019. Type in the date in YYYYMMDD format.

    Please input the date: 20190405

    ==========Transactions===========
    ID	Date		Type	Amount		Account1	Account2
    1	20190405	Asset	35.119999	Cash		Debit

#### Reverse and delete

After you have created one transaction but want to cancel it, use the function **Reverse and delete a transaction**.

The program may need you to provide the date, and choose the one you want to reverse and delete on that day.

    Please input the date of transaction (YYYYMMDD): 20190405

    ==========Transactions===========
    ID	Date		Type		Amount		Account1	Account2
    1	20190405	Asset		40.500000	Cash		Debit

    Please select the transaction: 1
    Transaction deleted!

After transaction deleted, modified data in accounts will be recovered to the states before.

#### List and output to file

You can use the function **List all transactions** to check all transactions you created, sorting by date or rever.eds

Here we provide a sample transactions list

    ==========Transactions===========
    Date		Type		Amount		Account1	Account2
    20190301	Revenue		500.000000	Salary		Cash
    20190303	Expense		200.000000	Clothing	Cash
    20190330	Expense		225.000000	Healthcare	Cash
    20190405	Asset		35.119999	Cash		Debit
    20190420	Revenue		3000.000000	Salary

To output transactions to file, use **Output transactions to a file**

    Input the name of the file, include file type (e.g. output.txt): output_transactions.txt
    Output as "output_transactions.txt"

Then you transactions will output all your transaction records to file named **output_transactions.txt**


### Finance analysis

Finance analysis is a class of functions helping users to clearly understand their current financial states generally

Based on current datas, you can use the program to generate total expense ,revenue and asset. And ask it to offer you an statistic statement of income.

You can also set a budget in advance. When your total expense exceeds this value, program will **warn** you.

Finance Analysis Menus is shown below

    ********************************************
    Finance Analysis Menu
    1. List all expense accounts
    2. List all revenue accounts
    3. List all asset accounts
    4. Income statement
    5. Set expense alert
    6. Return to last page
    Please select a function
    ********************************************

#### List all expense/revenue/asset accounts

The program can basically show your total expense, revenue and asset states, using the first three **List all accounts** functions.

    ==========Expenses==========
    Name		Balance		Type
    Healthcare	450.000000	Expense
    Clothing	400.000000	Expense
    Credit		30.000000	Expense
    Total Expenses: 880.00

    ==========Revenues==========
    Name	Balance		Type  
    Salary	5500.339844	Revenue
    Total Revenues: 5500.34

    ==========Assets==========
    Name	Balance		Type
    Cash	185.119995	Asset
    Debit	19964.880859	Asset
    Total Assets: 20150.00

**Income statement** will show you the statistic datas. Sample case is shown below

    ==========Revenues==========
    Name    Balance         Type
    Salary  5500.339844     Revenue
    Total Revenues: 5500.34

    ==========Expenses==========
    Name		Balance		Type
    Healthcare	450.000000	Expense
    Clothing	400.000000	Expense
    Credit		30.000000	Expense
    Total Expenses: 880.00
    ----------------------------
    Net Gain/Loss: 4620.34
    Expense-Revenue Ratio: 1:6.25


#### Set expense alert

The default warning threshold is negative, which will not launch the alert.

Thus the program allows you to set an alert of expense value previously.

In this case, we set $1500 as an expense threshold

    Current expense alert threshold: -3035569920.00
    New threshold (input "none" to disable the alert): 1500
    Alert threshold set to 1500.00

After alert threshold has been set, if your expense exceed this value, the program will warn you about overspending when you **enter Finance Analysis Menu once again**.

    Please enter transaction infomation
    Date (YYYYMMDD): 20190427
    Expense account: Credit
    Asset account (input "none" if no asset account): Debit
    Amount: 8400
    This transaction is created successfully!


    !WARNING! Total expense exceed threshold set!

### Conclusion

All above is what we have for the group project **Accounting System**.

Using C++ programming language, Makefile, Github and based on algorithms and applications we learnt in ENGG1340 course, we present this project to show our comprehension of implementing an solution to problem in daily life, and promote it in practice by programming. It's also necessary to keep debugging and later maintance, as well as providing potential users a friendly UI and file input/output functions.

Thank you for your use and evaluation!

---

## Teammembers

| **CHOI Chong Hing** | **CHEN Xingsheng** |
| :---: |:---:|
| 3035564940 | 3035535547 |
| [![CHOI Chong Hing](https://i.imgur.com/elZNX0z.jpg)](https://github.com/PCRedHot)    | [![CHEN Xingsheng](https://i.imgur.com/xasWEFT.jpg)](https://github.com/XsChen524) |
| <a href="https://github.com/PCRedHot" target="_blank">`github.com/PCRedHot`</a> | <a href="https://github.com/XsChen524" target="_blank">`github.com/XsChen524`</a> |
