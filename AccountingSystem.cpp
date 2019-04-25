#include "AccountingSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctype.h>

using namespace std;

void listExpense(account* head){
  cout << fixed << setprecision(2);
  float totalExpense = 0;
  account* curr = head;
  cout << "==========Expenses==========" << endl;
  cout << "Name\tBalance\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 0){
      cout << curr->getPrintData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalExpense += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Expenses: " << totalExpense << endl;
};

void listRevenue(account* head){
  cout << fixed << setprecision(2);
  account* curr = head;
  float totalRevenue = 0;
  cout << "==========Revenues==========" << endl;
  cout << "Name\tBalance\t\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 1){
      cout << curr->getPrintData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalRevenue += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Revenues: " << totalRevenue << endl;
};

void listAsset(account* head){
  cout << fixed << setprecision(2);
  account* curr = head;
  float totalAsset = 0;
  cout << "==========Assets==========" << endl;
  cout << "Name\tBalance\t\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 2){
      cout << curr->getPrintData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalAsset += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Assets: " << totalAsset << endl;
}

void incomeStatement(account* head){
  cout << fixed << setprecision(2);
  account* curr = head;
  float totalRevenue = 0;
  cout << "==========Revenues==========" << endl;
  cout << "Name\tBalance\t\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 1){
      cout << curr->getPrintData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalRevenue += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Revenues: " << totalRevenue << endl;
  curr = head;
  float totalExpense = 0;
  cout << "==========Expenses==========" << endl;
  cout << "Name\tBalance\t\tType" << endl;
  while (curr != nullptr){
    if (curr->type == 0){
      cout << curr->getPrintData() << endl;//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
      totalExpense += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Expenses: " << totalExpense << endl;
  cout << "----------------------------" << endl;
  cout << "Net Gain/Loss: " << totalRevenue - totalExpense << endl;
};

bool check(string input){
  if (input.length() != 1){
    return false;
  }
  if (isdigit(input[0])){
    return true;
  }else{
    return false;
  }
}

void outputAlert(float amount, string fileName){
  ofstream file;
  file.open(fileName);
  if (file.is_open()){
    file << amount;
  }else{
    cout << "Output expense alert file failed" << endl;
  }
  file.close();
}
