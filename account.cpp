#include <iostream>
#include <string>

using namespace std;

//Function: initialize account
//	input: 	string InputName - name of the account
//	output:	None
account::account(string InputName){
  name = InputName;
  balance = 0;
};

//Function: initialize account
//	input: 	string InputName - name of the account
//          float val - value of the accounts
//	output:	None
account::account(string InputName, float val){
  name = InputName;
  balance = val;
};

//Function: set the name of the account to InputName
//	input: 	string InputName - name of the account
//	output:	None
void account::setName(string InputName){
  name = InputName;
};

//Function: set the balance of the account to val
//	input:	float val - balance of the account
//	output:	None
void account::setBalance(float val){
  balance = val;
};

//Function: add val to the balance and return the new balance
//	input: 	float val - amount to be added
//	output:	float balance - new balance of the account
float account::addAmount(float val){
  balance += val;
  return balance;
};

//Function: set the previous account pointer to acc
//	input:  account* acc - pointer to the previous account
//	output: None
void account::setPrevious(account* acc){
  previous = acc;
};

//Function: set the next account pointer to acc
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

//Function: output a string in the standard format for storage
//	input:  None
//	output: data - data of the account in standard format
string account::getData(){
  string data = date + '\t' + to_string(balance);
  return data;
};

//Function: delete this account
//	input:  None
//	output: None
void account::deleteAccount(){
  previous->setNext(next);
  next->setPrevious(previous);
  delete this;
};
