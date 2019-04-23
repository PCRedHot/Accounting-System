#include <string>
#include <iostream>

class transaction {
public:
  int date; //date of the transaction YYYYMMDD
  int type;
  account* acc1; //the first account of the transaction
  account* acc2; //the second account of the transaction
  float amount;	   //the transaction amount
  transaction* previous;
  transaction* next;

  transaction(int, float, account*);//main function needs to set previous and next transaction
  transaction(int, float, account*, account*);

  void setDate(std::string);//atoi
  void setAccount1(account*);
  void setAccount2(account*);
  void setAmount(float);

  void setPrevious(transaction*);
  void setNext(transaction*);

  void deleteTransaction();
  void reverseTransaction();

  string getData(); //format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
};
