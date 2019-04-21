#include <iostream>
#include <string>
#include "Transaction.h"

using namespace std;

//int id;		       //id of the transaction
//string date;	   //date of the transaction
//string account1->name; //the first account of the transaction
//string account2->name; //the second account of the transaction
//float amount;	   //the transaction amount
//Transaction* previous;
//Transaction* next;

Transaction::Transaction(int id_input){
  id = order;
}//main function needs to set previous and next transaction automatically

void setdate_T(string date_input){
  date = stoi(date_input)
}//stoi

void set_from_account(account*){
  name_from = account->name;
}

void set_to_account(account*){
  name_to = account->name;
}

void setamount_T(string amount_input){
  amount = stoi(amount_input)
}

void setPrevious_T(Transaction* acc){
  previous = acc;
}

void setNext_T(Transaction* acc){
  next = acc;
}
