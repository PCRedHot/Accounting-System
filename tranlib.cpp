#include "tranlib.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

transaction* getLastTransaction(transaction* head){
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

void outputTransactionFile(transaction* head, string name){
  transaction* curr = head;
  ofstream file;
  file.open(name);
  if (file.is_open()){
    while (curr != nullptr){
      file << curr->getData() << endl;
    }
    curr = curr->next;
  }
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
}

int listTransaction_date(int date, transaction* head){
  transaction* curr = head;
  int id = 1;
  while (curr != nullptr){
    if (curr->date == date){
        cout << id << "\t" << curr->getData();
    }
    curr = curr->next;
  }
  return id;
};

void deleteTransaction(transaction* target, transaction* & head){
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
}
