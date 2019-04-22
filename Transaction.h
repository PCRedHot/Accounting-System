#include <string>
#include <iostream>
#include"account.h"

class Transaction {
public:
  int id;		       //id of the transaction
  std::string date;	   //date of the transaction
  std::string name_from; //the first account of the transaction
  std::string name_to; //the second account of the transaction
  float amount;	   //the transaction amount
  Transaction* previous;
  Transaction* next;

  Transaction(int);//main function needs to set previous and next transaction automatically

  void setdate_T(std::string);//atoi
  void set_from_account(account*);
  void set_to_account(account*);
  void setamount_T(float);

  void setPrevious_T(Transaction*);
  void setNext_T(Transaction*)
};
