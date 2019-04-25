#include "accountlib.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Function: get the pointer that point to account that named InputName
//	input: 	string InputName - name to search
//	        account* head - the pointer that point to the first account
//	output:	account* - pointer that point to account that named InputName
account* getAccount(string InputName, account* head){
  account* curr = head;
  while (curr != nullptr){
    if (curr->name == InputName) return curr;
    curr = curr->next;
  }
  //cout << "No Account named " << InputName << " is found." << endl;
  return nullptr;
};

//Function: switch the position of the two accounts
//	input: 	account* acc1 - first account
//	        account* acc2 - second account
//	output:	None
void switchAccount(account* acc1, account* acc2){
  account* tempP2 = acc2->previous, *tempN2 = acc2->next;
  if (tempP2 != acc1 && tempN2 != acc1){
    acc2->setPrevious(acc1->previous);
    acc2->setNext(acc1->next);
    acc1->setPrevious(tempP2);
    acc1->setNext(tempN2);
  }else if (tempP2 == acc1){
    acc2->setPrevious(acc1->previous);
    acc2->setNext(acc1);
    acc1->setPrevious(acc2);
    acc1->setNext(tempN2);
  }else if (tempN2 == acc1){
    acc2->setPrevious(acc1);
    acc2->setNext(acc1->next);
    acc1->setPrevious(tempP2);
    acc1->setNext(acc2);
  }
};

//Function: sort the accounts by balance, ascending order
//	input: 	account* head - the pointer that point to the first account
//	output:	None
void sortAccount_Balance(account* head){
  if (head == nullptr) return;
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

//Function: sort the accounts by balance, descending order
//	input: 	account* head - the pointer that point to the first account
//	output:	None
void rsortAccount_Balance(account* head){
  if (head == nullptr) return;
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

void outputAccountFile(account* head, string name){
  if (head != nullptr){
    ofstream file;
    file.open(name);
    account* curr = head;
    while (curr != nullptr){
      file << curr->getData() << endl;
      curr = curr->next;
    }
    file.close();
  }else{
    cout << "No account to store" << endl;
  }
};

account* getLastAccount(account* head){
  account* curr = head;
  while (curr->next != nullptr){
    curr = curr->next;
  }
  return curr;
};

void listAccount(account* head){
  account* curr = head;
  cout << "Name\tBalannce\tType" << endl;
  while (curr != nullptr){
    cout << curr->getData() << endl;
    curr = curr->next;
  }
};

void deleteAccount(account* acc, account* &head){
  if (acc->previous == nullptr && acc->next != nullptr){
    acc->next->previous = nullptr;
    head = acc->next;
  }else if (acc->previous != nullptr && acc->next == nullptr){
    acc->previous->next = nullptr;
  }else if (acc->previous != nullptr && acc->next != nullptr){
    acc->previous->next = acc->next;
    acc->next->previous = acc->previous;
  }else{
    head = nullptr;
  }
  delete acc;
};
