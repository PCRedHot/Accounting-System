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
  string name2 = acc2->name;
  float balance2 = acc2->balance;
  int type2 = acc2->type;
  acc2->name = acc1->name;
  acc2->balance = acc1->balance;
  acc2->type = acc1->type;
  acc1->name = name2;
  acc1->balance = balance2;
  acc1->type = type2;
};

//Function: sort the accounts by balance, ascending order
//	input: 	account* head - the pointer that point to the first account
//	output:	None
void sortAccount_Balance(account* head){
  if (head == nullptr) {
    return;
  }
  account* curr = head;
  bool change = true;
  while (change){
    change = false;
    curr = head;
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
  if (head == nullptr) {
    return;
  }
  account* curr = head;
  bool change = true;
  while (change){
    change = false;
    curr = head;
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
  ofstream file;
  file.open(name);
  account* curr = head;
  while (curr != nullptr){
    file << curr->getData() << '\n';
    curr = curr->next;
  }
  file.close();
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
  cout << "Name\tBalance\t\tType" << endl;
  while (curr != nullptr){
    cout << curr->getPrintData() << endl;
    curr = curr->next;
  }
};

void deleteAccount(account* acc, account* &head, account* &tail, transaction* head){
  if (acc->previous == nullptr && acc->next != nullptr){
    acc->next->previous = nullptr;
    head = acc->next;
  }else if (acc->previous != nullptr && acc->next == nullptr){
    acc->previous->next = nullptr;
    tail = acc->previous;
  }else if (acc->previous != nullptr && acc->next != nullptr){
    acc->previous->next = acc->next;
    acc->next->previous = acc->previous;
  }else{
    head = nullptr;
    tail = nullptr;
  }
  transaction* curr = head;
  while (curr != nullptr){
    if (curr->name1 == acc->name){
      curr->acc1 = nullptr;
    }
    if (curr->name2 == acc->name){
      curr->acc2 = nullptr;
    }
    curr = curr->next;
  }
  delete acc;
};
