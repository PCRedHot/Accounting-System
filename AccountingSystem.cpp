#include "AccountingSystem.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void listExpense(account* head){
  cout << fixed << setprecision(2);
  float totalExpense = 0;
  transaction* curr = head;
  sortTransaction_Date(head);
  cout << "==========Expenses==========" << endl;
  cout << "Name\tBalane\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 0){
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalExpense += curr->balance;
    }
  }
  cout << "Total Expenses:" << right << totalExpense << endl;
  cout << left;
};

void listRevenue(account* head){
  cout << fixed << setprecision(2);
  transaction* curr = head;
  float totalRevenue = 0;
  sortTransaction_Date(head);
  cout << "==========Revenues==========" << endl;
  cout << "Name\tBalane\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 1){
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalRevenue += curr->balance;
    }
  }
  cout << "Total Revenues:" << right << totalRevenue << endl;
  cout << left;
};

void listAsset(accout* head){
  cout << fixed << setprecision(2);
  transaction* curr = head;
  sortTransaction_Date(head);
  float totalAsset = 0;
  cout << "==========Assets==========" << endl;
  cout << "Name\tBalane\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 2){
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalAsset += curr->balance;
    }
  }
  cout << "Total Assets:" << right << totalAsset << endl;
  cout << left;
}

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
