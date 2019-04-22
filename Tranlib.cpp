#include "Tranlib.h"
#include <iostream>
#include <string>
using namespace std;

Transaction* getTransaction(int date, Transaction*){

}
void switchTransation(account*, account*);

void sortTransaction_Date(Transaction* &head_T){
  //Insert sort
  //Create a new linked list to store sorted transactions
  Transaction* current_T = head_T;
  Transaction* head_T_sorted = nullptr;

  while (current_T != nullptr){

    Transaction temp = *current_T;

    if (head_T_sorted == nullptr || temp.date < head_T_sorted->date){
      temp.next = head_T_sorted;
      head_T_sorted = &temp;
    }
    else{
      Transaction* insert = head_T_sorted;
      while (insert->next->date < temp.date)
        insert = insert->next;

      temp.next = insert->next;
      insert->next = &temp;
    }
    //Update the current pointer
    current_T = current_T->next;
  }

  int new_id = 1;
  Transaction* current_T_sorted = head_T_sorted;
  while (current_T_sorted != nullptr){
    current_T_sorted->id = new_id;
    new_id++;
    current_T_sorted = current_T_sorted->next;
  }
  //Assign new id to the linked list sequently
  head_T = head_T_sorted;
  //Assign the new linked list to the original head pointer
}

void rsortTransaction_Date(Transaction* &head_T){
  //Insert sort
  //Create a new linked list to store sorted transactions
  Transaction* current_T = head_T;
  Transaction* head_T_rsorted = nullptr;

  while (current_T != nullptr){

    Transaction temp = *current_T;

    if (head_T_rsorted == nullptr || temp.date > head_T_rsorted->date){
      temp.next = head_T_rsorted;
      head_T_rsorted = &temp;
    }
    else{
      Transaction* insert = head_T_rsorted;
      while (insert->next->date > temp.date)
        insert = insert->next;

      temp.next = insert->next;
      insert->next = &temp;
    }
    //Update the current pointer
    current_T = current_T->next;
  }

  int new_id = 1;
  Transaction* current_T_rsorted = head_T_rsorted;
  while (current_T_rsorted != nullptr){
    current_T_rsorted->id = new_id;
    new_id++;
    current_T_rsorted = current_T_rsorted->next;
  }
  //Assign new id to the linked list sequently
  head_T = head_T_rsorted;
  //Assign the new linked list to the original head pointer
}

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
