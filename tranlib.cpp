#include "tranlib.h"
#include <iostream>
#include <string>
using namespace std;

transaction* getLastTransaction(string date, transaction* head){
  transaction* curr = head;
  while (curr->next != nullptr){
    curr = curr->next;
  }
  return curr;
};

void switchTransation(transaction* tran1, transaction* tran2){
  transaction* tempP2 = tran2->previous, *tempN2 = tran2->next;
  if (tempP2 != tran1 && tempN2 != tran1){
    tran2->setPrevious(tran1->previous);
    tran2->setNext(tran1->next);
    tran1->setPrevious(tempP2);
    tran1->setNext(tempN2);
  }else if (tempP2 == tran1){
    tran2->setPrevious(tran1->previous);
    tran2->setNext(tran1);
    tran1->setPrevious(tran2);
    tran1->setNext(tempN2);
  }else if (tempN2 == tran1){
    tran2->setPrevious(tran1);
    tran2->setNext(tran1->next);
    tran1->setPrevious(tempP2);
    tran1->setNext(tran2);
  }
};

void sortTransaction_Date(transaction* head){
  if (head == nullptr) return;
  transaction* curr = head;
  bool change = true;
  while (change){
    change = false;
    while (curr->next != nullptr){
      if (curr->date > curr->next->date){
        switchTransation(curr, curr->next);
        change = true;
      }
    }
  }
};

void rsortTransaction_Date(transaction* head){
  if (head == nullptr) return;
  transaction* curr = head;
  bool change = true;
  while (change){
    change = false;
    while (curr->next != nullptr){
      if (curr->date < curr->next->date){
        switchTransation(curr, curr->next);
        change = true;
      }
    }
  }
};

void listTransaction(transaction* head){
  transaction* curr = head;
  while (curr != nullptr){
    cout << curr->getData();
    curr = curr->next;
  }
};

account* findNode (string nameinput, account* head_A){
  account* current = head_A;
  while (current->name != nameinput){
    current = current->next;
  }
  return current;
}
