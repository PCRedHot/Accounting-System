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
}

transaction::transaction(string dateInput, float amountInput, account* acc1Input, account* acc2Input){
  date = dateInput;
  amount = amountInput;
  acc1 = acc1Input;
  acc2 = acc2Input;
}

void setdate_T(string date_input){
  date = stoi(date_input);
}

void setAccount1(account*){
  name_from = account->name;
}

void setAccount2(account*){
  name_to = account->name;
}

void setamount(string amount_input){
  amount = stoi(amount_input)
}

void setPrevious(transaction* acc){
  previous = acc;
}

void setNext(transaction* acc){
  next = acc;
}
