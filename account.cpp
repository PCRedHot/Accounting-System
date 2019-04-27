#include <iostream>
#include <string>
#include <iomanip>
#include "account.h"

using namespace std;

//initialize account
//	input: 	string InputName - name of the account
//	output:	None
account::account(string InputName){
  name = InputName;
  balance = 0;
};

//initialize account
//	input: 	string InputName - name of the account
//          float val - value of the accounts
//	output:	None
account::account(string InputName, float val){
  name = InputName;
  balance = val;
};

//set the name of the account to InputName
//	input: 	string InputName - name of the account
//	output:	None
void account::setName(string InputName){
  name = InputName;
};

//set the balance of the account to val
//	input:	float val - balance of the account
//	output:	None
void account::setBalance(float val){
  balance = val;
};

//add val to the balance and return the new balance
//	input: 	float val - amount to be added
//	output:	float balance - new balance of the account
float account::addAmount(float val){
  balance += val;
  return balance;
};

//set the previous account pointer to acc
//	input:  account* acc - pointer to the previous account
//	output: None
void account::setPrevious(account* acc){
  previous = acc;
};

//set the next account pointer to acc
//	input:  account* acc - pointer to the next account
//	output: None
void account::setNext(account* acc){
  next = acc;
};

void account::setPrevious(account& acc){
  previous = &acc;
};

void account::setNext(account& acc){
  next = &acc;
};

//output a string in the standard format for storage
//	input:  None
//	output: data - data of the account in standard format
string account::getData(){
  string data = name + '\t' + to_string(balance) + '\t' + to_string(type);
  return data;
};

//Print data in standard format
void account::PrintData(){
  cout << setfill(' ');
  cout << left << setw(11) << name << setw(11) << fixed << setprecision(2) << balance;
  switch (type) {
    case 0:
    {
      cout << setw(8) << "Expense";
      break;
    }

    case 1:
    {
      cout << setw(8) << "Revenue";
      break;
    }

    case 2:
    {
      cout << setw(8) << "Asset";
      break;
    }

    default:
    {
      cout << setw(8) << "Unknown";
      break;
    }
  }
};
