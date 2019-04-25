#include <iostream>
#include <string>
#include "transaction.h"
using namespace std;

transaction::transaction(account* head, int dateInput, string typeInput, float amountInput, string acc1Input){
  date = dateInput;
  amount = amountInput;
  name1 = acc1Input;
  acc1 = getAccount(acc1Input, head);
  //Type: 1. Expense 2. Revenue
  type = (typeInput = "Expense")?1:2;
};

transaction::transaction(account* head, int dateInput, string type, float amountInput, string acc1Input, string acc2Input){
  date = dateInput;
  amount = amountInput;
  name1 = acc1Input;
  name2 = acc2Input;
  acc1 = getAccount(acc1Input, head);
  acc2 = getAccount(acc2Input, head);
  //Type: 1. Expense 2. Revenue
  type = (typeInput = "Expense")?1:2;
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

void transaction::deleteTransaction(){
  previous->setNext(next);
  next->setPrevious(previous);
  delete this;
}

void transaction::reverseTransaction(){

}

transaction* find_insert(transaction* head, int datetemp){
  if (head == nullptr || head->date >= datetemp)
    return nullptr;

  transaction* current = head;

  while (current->next != nullptr){
    if (current->next->date >= datetemp)
      return current;
    else current = current->;
  }

  return current;
}
