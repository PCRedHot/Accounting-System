#include "tranlib.h"
#include <iostream>
#include <string>
using namespace std;

transaction* tranlib::getLastTransaction(string date, transaction* head){
  curr = head;
  while (curr->next != nullptr){
    curr = curr->next;
  }
  return curr;
};

void tranlib::switchTransation(transaction* tran1, transaction* tran2){
  transaction* tempP2 = tran2->previous, tempN2 = tran2->next;
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

void tranlib::sortTransaction_Date(transaction* head){
  if (head == nullptr) return;
  transaction* curr = head;
  bool change = true;
  while (change){
    change = false;
    while (curr->next != nullptr){
      if (stoi(curr->date) > stoi(curr->next->date)){
        switchTransation(curr, curr->next);
        change = true;
      }
    }
  }
};

void tranlib::rsortTransaction_Date(transaction* &head_T){
  if (head == nullptr) return;
  transaction* curr = head;
  bool change = true;
  while (change){
    change = false;
    while (curr->next != nullptr){
      if (stoi(curr->date) < stoi(curr->next->date)){
        switchTransation(curr, curr->next);
        change = true;
      }
    }
  }
};

void tranlib::outputTransaction(transaction* current_T){
  cout << current_T->acc1->name << " ";
  cout << current_T->acc2->name << " ";
  cout << current_T->amount <<endl;
};

void tranlib::modifytransactions(transaction* current_T, account* head_A){
  Account* fromAccount = head_A;
  Account* toAccount = head_A;

  while (current_T->name_from != fromAccount->name){
    fromAccount = fromAccount->next;
  }
  while (current_T->name_to != toAccount->name){
    toAccount = toAccount->next;
  }

  fromAccount->balance -= current_T->amount;
  toAccount->balance += current_T->amount;

  fromAccount = nullptr;
  toAccount = nullptr;

  cout << "Accounts have been modified!" << endl;
};
