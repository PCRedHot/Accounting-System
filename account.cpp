#include <iostream>
#include <string>
#include "account.h"

using namespace std;

account::account(string InputName){
  name = InputName;
  balance = 0;
}

account::account(string InputName, float val){
  name = InputName;
  balance = val;
}

void account::setName(string InputName){
  name = InputName;
};

void account::setBalance(float val){
  balance = val;
};

float account::addAmount(float val){
  balance += val;
  return balance;
};

void account::setPrevious(account acc){
  previous = &acc;
};

void account::setPrevious(account* acc){
  previous = acc;
};

void account::setNext(account acc){
  next = &acc;
};

void account::setNext(account* acc){
  next = acc;
};


string account::getData(){
  string data = date + '\t' + to_string(balance);
  return data;
};

void account::deleteAccount(){
  previous->setNext(next);
  next->setPrevious(previous);
  delete this;
}
