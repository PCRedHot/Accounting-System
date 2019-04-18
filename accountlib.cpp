#include "accountlib.h"
#include <iostream>

using namespace std;

account* getAccount(string InputName, account* head){
  account* curr = head;
  while (curr != nullptr){
    if (curr->name == InputName) return curr;
    curr = curr->next;
  }
  cout << "No Account named " << InputName << " is found." << endl;
  return nullptr;
};

account* getAccount(float val, account* head){
  account* curr = head;
  while (curr != nullptr){
    if (curr->balance == val) return curr;
    curr = curr->next;
  }
  cout << "No Account has " << val << " balance." << endl;
  return nullptr;
};

void switchAccount(account* acc1, account* acc2){
  account* tempP2 = acc2->previous, tempN2 = acc2->next;
  acc2.setPrevious(acc1->previous);
  acc2.setNext(acc1->next);
  acc1.setPrevious(tempP2);
  acc1.setPrevious(tempN2);
};

void sortAccount_Balance(account* head){
  account* curr = head;
  bool change;
  while (change){
    change = false;
    while (curr->next != nullptr){
      if (curr->balance > curr->next->balance){
        change = true;
        switchAccount(curr, curr->next);
      }
      curr = curr->next;
    }
  }
};

void rsortAccount_Balance(account* head){
  account* curr = head;
  bool change;
  while (change){
    change = false;
    while (curr->next != nullptr){
      if (curr->balance < curr->next->balance){
        change = true;
        switchAccount(curr, curr->next);
      }
      curr = curr->next;
    }
  }
};
