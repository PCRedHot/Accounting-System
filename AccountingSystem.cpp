#include "AccountingSystem.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void listExpense(account* head){
  cout << fixed << setprecision(2);
  float totalExpense = 0;
  account* curr = head;
  cout << "==========Expenses==========" << endl;
  cout << "Name\tBalance\tType" << endl;
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
  account* curr = head;
  float totalRevenue = 0;
  cout << "==========Revenues==========" << endl;
  cout << "Name\tBalance\tType" << endl;
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
  account* curr = head;
  float totalAsset = 0;
  cout << "==========Assets==========" << endl;
  cout << "Name\tBalance\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 2){
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalAsset += curr->balance;
    }
  }
  cout << "Total Assets:" << right << totalAsset << endl;
  cout << left;
}

void incomeStatement(account* head){
  cout << fixed << setprecision(2);
  account* curr = head;
  float totalRevenue = 0;
  cout << "==========Revenues==========" << endl;
  cout << "Name\tBalance\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 1){
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalRevenue += curr->balance;
    }
  }
  cout << "Total Revenues:" << right << totalRevenue << endl;
  cout << left;
  curr = head;
  float totalExpense = 0;
  cout << "==========Expenses==========" << endl;
  cout << "Name\tBalance\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 0){
      cout << curr->getData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalExpense += curr->balance;
    }
  }
  cout << "Total Expenses:" << right << totalExpense << endl;
  cout << left << "----------------------------" << endl;
  cout << "Net Gain/Loss" << right << totalRevenue - totalExpense << left << endl;
};
