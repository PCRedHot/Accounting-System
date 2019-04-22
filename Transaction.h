#include <string>
#include <iostream>

class transaction {
public:
  std::string date;	   //date of the transaction
  account* acc1; //the first account of the transaction
  account* acc2; //the second account of the transaction
  float amount;	   //the transaction amount
  transaction* previous;
  transaction* next;

  transaction(string, float, account*);//main function needs to set previous and next transaction
  transaction(string, float, account*, account*);

  void setdate_T(std::string);//atoi
  void set_from_account(account*);
  void set_to_account(account*);
  void setamount_T(float);

  void setPrevious_T(transaction*);
  void setNext_T(transaction*);
};
