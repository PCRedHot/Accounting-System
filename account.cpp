#include <iostream>
#include <string>
#include "account.h"

using namespace std;

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

string account::getName(){
  return name;
};

float account::getBalance(){
  return balance;
};

account* account::getNext(){
  return next;
};

account* account::getPrevious(){
  return previous;
};

string account::getData(){
  string data = date + '\t' + to_string(balance);
  return data;
};
