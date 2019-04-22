#include <string>
#include <iostream>

using namespace std;

class account{
public:
  string name;
  float balance;
  account* previous;
  account* next;

  account(string);
  account(string, float);

  void setName(std::string);
  void setBalance(float);
  float addAmount(float);
  void setPrevious(account*);
  void setNext(account*);
  void setPrevious(account&);
  void setNext(account&);

  string getData();

  void deleteAccount();
};
