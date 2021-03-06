#include <string>
#include <iostream>
#include "accountlib.h"

class transaction{
public:
  transaction(account*, int, float, std::string);//(account head, date, type, amount, name1)
  transaction(account*, int, float, std::string, std::string);//(account head, date, type, amount, name1, name2)
  transaction(int, float, account*, account*);
  transaction(int, float, account*);

  int date; //date of the transaction YYYYMMDD
  int type; //0:expense 1:revenue
  account* acc1; //the first account of the transaction
  account* acc2; //the second account of the transaction
  std::string name1;
  std::string name2;
  float amount;	   //the transaction amount
  transaction* previous;
  transaction* next;

  void setDate(std::string);
  void setAccount1(account*);
  void setAccount2(account*);
  void setAmount(std::string);

  void setPrevious(transaction*);
  void setNext(transaction*);

  void reverseTransaction();

  void PrintData();
  string getData(); //format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
};
