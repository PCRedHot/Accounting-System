# Accounting System

> This is a group project from HKU ENGG1340 Group 120

---

## Table of content

- [Problem Statement](#problem-statement)
- [Problem Setting](#problem-setting)
- [Teammembers](#teammembers)

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

The Accounting System provides the basic function **Account**.

You can simply create varied type account, modified the existing accounts, list all of them and output to file.

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

Enter the function Add an account, it will show

    Please input the name of the account: Cash

You can create accounts like **Credit**, **Salary**, **Food**, or type in the name whatever you like.
In this case, we create the account named **Cash**, it has been stored in our **Sample cases**. After enter the name of account, the program will ask you the type of such account

    Which type is the account?
    1. Expense Account
    2. Revenue Account
    3. Asset Account

In this case, we make it as an Asset Account. Type in **3**

    Account named "Cash" is created!

Firstly initialized account's amount is preset as 0 (float).
After your account has been created, you can set its amount by **Set amount of account** function.

Here we provide you a sample of created accounts list, it can also be outputed by yourself.

    Name			Balance			Type
    Cash			-425.000000			Asset
    Credit			30.000000			Expense
    Clothing		200.000000		Expense
    Healthcare		225.000000		Expense
    Salary			2000.339966			Revenue
    Debit			20000.000000			Asset





## Teammembers

| **CHOI Chong Hing** | **CHEN Xingsheng** |
| :---: |:---:|
| 3035564940 | 3035535547 |
| [![CHOI Chong Hing](https://i.imgur.com/elZNX0z.jpg)](https://github.com/PCRedHot)    | [![CHEN Xingsheng](https://i.imgur.com/xasWEFT.jpg)](https://github.com/XsChen524) |
| <a href="https://github.com/PCRedHot" target="_blank">`github.com/PCRedHot`</a> | <a href="https://github.com/XsChen524" target="_blank">`github.com/XsChen524`</a> |
