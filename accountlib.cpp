#include "accountlib.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//get the pointer that point to account that named InputName
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

//switch the position of the two accounts
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

//sort the accounts by balance, ascending order
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

//sort the accounts by balance, descending order
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

//output account file
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

//list all accounts
void listAccount(account* head){
  account* curr = head;
  cout << left << setw(11) << "Name" << setw(11) << "Balance" << setw(8) << "Type" << endl;
  while (curr != nullptr){
    curr->PrintData();
    cout << endl;
    curr = curr->next;
  }
};
