#include "tranlib.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

transaction* getLastTransaction(transaction* head){
  transaction* curr = head;
  while (curr->next != nullptr){
    curr = curr->next;
  }
  return curr;
};

void switchTransaction(transaction* tran1, transaction* tran2){
  int date2 = tran2->date;
  int type2 = tran2->type;
  account* acc12 = tran2->acc1;
  account* acc22 = tran2->acc2;
  string name12 = tran2->name1;
  string name22 = tran2->name2;
  float amount2 = tran2->amount;
  tran2->date = tran1->date;
  tran2->type = tran1->type;
  tran2->acc1 = tran1->acc1;
  tran2->acc2 = tran1->acc2;
  tran2->name1 = tran1->name1;
  tran2->name2 = tran1->name2;
  tran2->amount = tran1->amount;
  tran1->date = date2;
  tran1->type = type2;
  tran1->acc1 = acc12;
  tran1->acc2 = acc22;
  tran1->name1 = name12;
  tran1->name2 = name22;
  tran1->amount = amount2;
};

void sortTransaction_Date(transaction* head){
  if (head == nullptr) {
    return;
  }
  transaction* curr = head;
  bool change = true;
  while (change){
    change = false;
    curr = head;
    while (curr->next != nullptr){
      if (curr->date > curr->next->date){
        switchTransaction(curr, curr->next);
        change = true;
      }
      curr = curr->next;
    }
  }
};

void rsortTransaction_Date(transaction* head){
  if (head == nullptr) {
    return;
  }
  transaction* curr = head;
  bool change = true;
  while (change){
    change = false;
    curr = head;
    while (curr->next != nullptr){
      if (curr->date < curr->next->date){
        switchTransaction(curr, curr->next);
        change = true;
      }
      curr = curr->next;
    }
  }
};

void listTransaction(transaction* head){
  transaction* curr = head;
  cout << "==========Transactions===========" << endl;
  cout << "Date     Type    Amount\t\tAccount1\tAccount2" << endl;
  while (curr != nullptr){
    cout << curr->getPrintData() << endl;
    curr = curr->next;
  }
};

void outputTransactionFile(transaction* head, string name){
  transaction* curr = head;
  cout << fixed << setprecision(2);
  ofstream file;
  file.open(name);
  if (file.is_open()){
    while (curr != nullptr){
      file << curr->getData() << endl;
      curr = curr->next;
    }
  }
  file.close();
}

transaction* getTransaction(int date, int id, transaction* head){
  transaction* curr = head;
  while (curr != nullptr){
    if (curr->date == date){
      if (--id == 0){
        return curr;
      }
    }
  }
  return nullptr;
}

int listTransaction_date(int date, transaction* head){
  transaction* curr = head;
  int id = 1;
  cout << "==========Transactions===========" << endl;
  cout << "ID Date     Type    Amount\t\tAccount1\tAccount2" << endl;
  while (curr != nullptr){
    if (curr->date == date){
        cout << id << " " << curr->getPrintData() << endl;
    }
    curr = curr->next;
  }
  return id;
};

void deleteTransaction(transaction* target, transaction* &head, transaction* &tail){
  if (target->previous == nullptr && target->next != nullptr){
    target->next->previous = nullptr;
    head = target->next;
  }else if (target->previous != nullptr && target->next == nullptr){
    target->previous->next = nullptr;
    tail = target->previous;
  }else if (target->previous != nullptr && target->next != nullptr){
    target->previous->next = target->next;
    target->next->previous = target->previous;
  }else{
    head = nullptr;
    tail = nullptr;
  }
  delete target;
}
