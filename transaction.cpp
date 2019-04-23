#include <iostream>
#include <string>
#include "transaction.h"
#include "account.h"
#include "accountlib.h"
using namespace std;


transaction::transaction(string dateInput, float amountInput, account* acc1Input){
  date = dateInput;
  amount = amountInput;
  acc1 = acc1Input;
};

transaction::transaction(string dateInput, float amountInput, account* acc1Input, account* acc2Input){
  date = dateInput;
  amount = amountInput;
  acc1 = acc1Input;
  acc2 = acc2Input;
};

void transaction::setDate(string date_input){
  date = date_input;
};

void transaction::setAccount1(account* acc){
  acc1 = acc;
};

void transaction::setAccount2(account* acc){
  acc2 = acc;
};

void transaction::setAmount(string amount_input){
  amount = stof(amount_input);
};

void transaction::setPrevious(transaction* tran){
  previous = tran;
};

void transaction::setNext(transaction* tran){
  next = tran;
};

string transaction::getData(){
  string output = to_string(date) + '\t' + to_string(amount) + '\t' + acc1->name;
  if (acc2 != nullptr) output += '\t' acc2-> name;
  return output;
};// format: YYYYMMDD <tab> amount <tab> acc1 <tab> acc2
