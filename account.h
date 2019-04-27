#include <string>
#include <iostream>

using namespace std;

class account{
public:
  string name;
  float balance;
  account* previous;
  account* next;
  int type; //0: expense 1: revenue 2: asset

  account(string);
  account(string, float);

  void setName(std::string);
  void setBalance(float);
  float addAmount(float);
  void setPrevious(account*);
  void setNext(account*);
  void setPrevious(account&);
  void setNext(account&);

  void PrintData();
  string getData();
};
