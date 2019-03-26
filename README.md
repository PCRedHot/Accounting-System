# Accounting System

> This is a group project from HKU ENGG1340 Group 120

---

## Table of content

- [Problem Statement](#problem-statement)
- [Problem Setting](#problem-setting)
- [Usage](#usage)
- [Teammembers](#teammembers)

---

## Problem Statement

Living in high-paced life with much pressure, people need dealing with their balance of payments data from all kinds of area to evaluate personal financial status every day, which will be extraordinarily complicated and time-consuming tasks in case operated by traditional accounting methods. Thus, a more visual and efficient accounting system aimed at solving personal financial data’s tracking and management is in sore demand.

---

## Problem Setting

### Introduction

The Accounting System focus on helping manage personal wealth efficiently.

It will provide a variety of accounting operations for users, making them able to create new accounts, and further add or modify records stored in the current accounts. The system will also output the records so far, as well as statistic data of the wealth, on the demand of the users. 

![](https://img.shields.io/badge/Language-C++-brightgreen.svg)

###Features

Making proper use of C++, Commands, various programming and accounting knowledge, we hope the Accounting system can operate efficiently and achieve the established functions.

The system will accept different type as its input and, thus, achieve relevant functions to store them.
- Set name and balance for the initial users: As long as created, the initial user data can be in further operations.
- Add records of income and expenses to the specific user: The basic operation on the users’ balance. In order to record clearly, users can choose multiple categories (i.e. food, game, salary) for their transactions from different accounts (Cash, debit card, credit card default) and date.
- Delete and edit: Recorded data can be accessed to be further modified or deleted easily by specifying the category.

Also, the system can output multiple statistic reports which are calculated based on the existing data. Additionally, it will evaluate the general financial status of the user.
- List the record: The system will be able to output the records that have stored so far, including the information about the amount, date, types of income or expense, account and remarks (if needed) for users purposes of viewing. We can also ask for just part of the current data, or sort them in different order by date or categories.
- Statistic report: Based on the record data, the system will give users statistic report about their financial state so far (including monthly income and expense, the percentage of the particular set of expenses, the variability of income and expense), which will help them handle the future plan more accurately.
- Budget setting and alert: The system will allow the user to set a default budget. When the total expense is reaching the budget, there should be alarm from the system to warn the user.

In the coming soon, we may add more features for the system, based on the completion and implementation of the program.

---

## Usage

> This section is under construction, and changes are likely in the future

** Functions **
```C++
//Structure of an account
struct Account {
 	string name; 	//name of the account
 	bool type; 	//type of the account, true for debit account, false for credit account
 	float balance; 	// balance of the account
};

//Structure of a transaction
struct Transaction {
 	int id;		//id of the transaction
	string date;	//date of the transaction
	string account1;//the first account of the transaction
	string account2;//the second account of the transaction
	float amount;	//the transaction amount
};

//Function: Create a new account
//	input: 	string name - the name of the account
//		bool type - the type of the account
//	output:	none
void createAccount(string name, bool type);

//Function: Find the index of the account in account list with its name
//	input:	string name-  the name of the account
//	output:	int index - return the index of the account in account list
void findIndexOfAccount(string name);

//Function: Create new transaction
//	input:	string date - the date of the transaction
//		string acc1_name - the name of the first account
//		string acc2_name - the name of the second account
//		float amount - the amount of the transaction
//	output:	none
void createTransaction(string date, string acc1_name, string acc2_name, float amount);

//Function: Print all accounts in the format “Account_name: Balance”
//	input:	none
//	output:	none
void printAccount();

//Function: Print all Transactions in the format “id: date account1 account2 amount”
//	input:	none
//	output:	none
void printTransaction();

//Function: Add amount to an account’s balance
//	input:	Account& acc - target account
//		float amount - amount of money
//	output:	Account& acc - return the adjusted account (pass by reference)
//		float acc.balance - return the newly adjusted balance of the account
float addAmount(Account& acc, float amount);
```

---

## Teammembers

| **CHOI Chong Hing** | **CHEN Xingsheng** | 
| :---: |:---:|
| [![CHOI Chong Hing](https://i.imgur.com/elZNX0z.jpg)](https://github.com/PCRedHot)    | [![CHEN Xing Sheung](https://i.imgur.com/xasWEFT.jpg)](https://github.com/XsChen524) | 
| <a href="https://github.com/PCRedHot" target="_blank">`github.com/PCRedHot`</a> | <a href="https://github.com/XsChen524" target="_blank">`github.com/XsChen524`</a> | 
