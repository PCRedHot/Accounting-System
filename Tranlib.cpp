#include "Tranlib.h"
#include <iostream>
using namespace std;

Transaction* getTransaction(string, account*);
void switchTransation(account*, account*);
void sortTransaction_Date(account*);
void rsortTransaction_Date(account*);

void outputTransaction(Transaction* current_T){
  cout << current_T->id << " ";
  cout << current_T->name_from << " ";
  cout << current_T->name_to << " ";
  cout << current_T->amount <<endl;
}

void modifyAccounts(Transaction* current_T, Account* head_A){
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
}
