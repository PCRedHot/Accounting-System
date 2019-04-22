#include "accountlib.h"
#include <iostream>

using namespace std;

//Function: get the pointer that point to account that named InputName
//	input: 	string InputName - name to search
//	        account* head - the pointer that point to the first account
//	output:	account* - pointer that point to account that named InputName
account* accountlib::getAccount(string InputName, account* head){
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
void accountlib::switchAccount(account* acc1, account* acc2){
  account* tempP2 = acc2->previous, tempN2 = acc2->next;
  acc2.setPrevious(acc1->previous);
  acc2.setNext(acc1->next);
  acc1.setPrevious(tempP2);
  acc1.setPrevious(tempN2);
};

//Function: sort the accounts by balance, ascending order
//	input: 	account* head - the pointer that point to the first account
//	output:	None
void accountlib::sortAccount_Balance(account* head){
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
void accountlib::rsortAccount_Balance(account* head){
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

void accountlib::outputAccountFile(account* head){
  if (head != nullptr){
    ofstream file;
    file.open("account");
    account* curr = accHead;
    while (curr != nullptr){
      file << curr->getData();
      curr = curr->next;
    }
    file.close();
  }else{
    cout << "No account to store" << endl;
  }
};

account* accountlib::getLastAccount(account* head){
  account* curr = head;
  while (curr->next != nullptr){
    curr = curr->next;
  }
  return curr;
};

void accountlib::listAccount(account* head){
  account* curr = head;
  while (curr != nullptr){
    cout << curr->getData();
    curr = curr->next();
  }
};
