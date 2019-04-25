#include <iostream>
#include <string>
#include "transaction.h"
using namespace std;

transaction::transaction(account* head, int dateInput, float amountInput, string acc1Input){
  date = dateInput;
  amount = amountInput;
  name1 = acc1Input;
  acc1 = getAccount(acc1Input, head);
  name2 = "";
  acc2 = nullptr;
};

transaction::transaction(account* head, int dateInput, float amountInput, string acc1Input, string acc2Input){
  date = dateInput;
  amount = amountInput;
  name1 = acc1Input;
  name2 = acc2Input;
  acc1 = getAccount(acc1Input, head);
  acc2 = getAccount(acc2Input, head);
};

transaction::transaction(int dateInput, float amountInput, account* acc1Input, account* acc2Input){
  date = dateInput;
  amount = amountInput;
  acc1 = acc1Input;
  acc2 = acc2Input;
  name1 = acc1Input->name;
  name2 = acc2Input->name;
};

transaction::transaction(int dateInput, float amountInput, account* acc1Input){
  date = dateInput;
  amount = amountInput;
  acc1 = acc1Input;
  name1 = acc1Input->name;
};

void transaction::setDate(string date_input){
  date = stoi(date_input);
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
  string output = to_string(date) + '\t' + to_string(type) + '\t' + to_string(amount) + '\t' + name1;
  if (name2 != "") output += '\t' + name2;
  return output;
};// format: YYYYMMDD <tab> amount <tab> acc1 <tab> acc2

string transaction::getPrintData(){
  string output = to_string(date) + " ";
  switch (type) {
    case 0:
    {
      output += "Expense";
      break;
    }

    case 1:
    {
      output += "Revenue";
      break;
    }

    default:
    {
      break;
    }
  }
  output += " " + to_string(amount) + '\t' + name1;
  if (name2 != "") output += '\t' + name2;
  return output;
}

void transaction::reverseTransaction(){
  acc1->balance -= amount;
  if (acc2!=nullptr){
    if (type == 0){
      acc2->balance += amount;
    }else if (type == 1){
      acc2->balance -= amount;
    }
  }
}
