# Accounting System

> This is a group project from HKU ENGG1340 Group 120

---

## Table of content

- [Problem Statement](#problem-statement)
- [Problem Setting](#problem-setting)
- [Usage](#usage)
- [Team](#team)

---

## Problem Statement

---

## Problem Setting

---

## Usage

> This section is under construction, and changes are likely in the future

** Functions **
```C++
//Structure of an account
struct Account {
  string name;
  bool type; //type of the account, true for debit account, false for credit account
  float balance;
};

//Structure of a transaction
struct Transaction {
  int id;
	string date;
	string account1;
	string account2;
	float amount;
};

//Function: Create a new account
//	input: 	string name - the name of the account
//		bool type - the type of the account
//	output:	none
void createAccount(string name, bool type);

//Function: Find the index of the account in account list with its name
//	input:	string name-  the name of the account
//	output:	int index - return the index of the account in account list
void  findIndexOfAccount(string name);

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

## Team

| **CHOI Chong Hing** | **CHEN Xing Sheung** | 
| :---: |:---:|
| [![CHOI Chong Hing](https://i.imgur.com/elZNX0z.jpg)](https://github.com/PCRedHot)    | [![CHEN Xing Sheung](https://i.imgur.com/xasWEFT.jpg)](https://github.com/XsChen524) | 
| <a href="https://github.com/PCRedHot" target="_blank">`github.com/PCRedHot`</a> | <a href="https://github.com/XsChen524" target="_blank">`github.com/XsChen524`</a> | 
