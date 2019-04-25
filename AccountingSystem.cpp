#include "AccountingSystem.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void listExpense(transaction* head){
  transaction* curr = head;
  sortTransaction_Date(head);
  cout << "=====Expense Transaction History=====" << endl;
  cout << "Date\t\tType\tAmount\tAccount 1\tAccount 2(optional)" << endl;
  while (curr != nullptr){
    if (curr->type == 0){
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
    }
  }
};

void listRevenue(transaction* head){
    cout << fixed << setprecision(2);
  transaction* curr = head;
  sortTransaction_Date(head);
  cout << "=====Renvenue Transaction History=====" << endl;
  cout << "Date\t\tType\tAmount\tAccount 1\tAccount 2(optional)" << endl;
  while (curr != nullptr){
    if (curr->type == 1){
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
    }
  }
};
void incomeStatement(transaction* head){
  cout << fixed << setprecision(2);
  transaction* curr = head;
  float Revenue = 0;
  cout << "=====Expense Transaction History=====" << endl;
  cout << "Date\t\tType\tAmount\tAccount 1\tAccount 2(optional)" << endl;
  while (curr != nullptr){
    if (curr->type == 0){
      Revenue -= curr->amount;
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
    }
  }
  cout << "=====Renvenue Transaction History=====" << endl;
  cout << "Date\t\tType\tAmount\tAccount 1\tAccount 2(optional)" << endl;
  while (curr != nullptr){
    if (curr->type == 1){
      Revenue += curr->amount;
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
    }
  }
  cout << endl << "Net Gain/Loss" << right << Renvenue << left << endl;
};
