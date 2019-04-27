#include "AccountingSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctype.h>

using namespace std;

//list all expense account
void listExpense(account* head){
  cout << fixed << setprecision(2);
  float totalExpense = 0;
  account* curr = head;
  cout << setw(19) << right << setfill('=') << "Expenses" << setw(11) << left << "=" << endl;
  cout << setfill(' ');
  cout << left << setw(11) << "Name" << setw(11) << "Balance" << setw(8) << "Type" << endl;
  while (curr != nullptr){
    if (curr->type == 0){
      curr->PrintData();
      cout << endl;
      totalExpense += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Expenses: " << totalExpense << endl;
};

//list all revenue account
void listRevenue(account* head){
  cout << fixed << setprecision(2);
  account* curr = head;
  float totalRevenue = 0;
  cout << setw(19) << right << setfill('=') << "Expenses" << setw(11) << left << "=" << endl;
  cout << setfill(' ');
  cout << left << setw(11) << "Name" << setw(11) << "Balance" << setw(8) << "Type" << endl;
  while (curr != nullptr){
    if (curr->type == 1){
      curr->PrintData();
      cout << endl;
      totalRevenue += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Revenues: " << totalRevenue << endl;
};

//list all asset accounts
void listAsset(account* head){
  cout << fixed << setprecision(2);
  account* curr = head;
  float totalAsset = 0;
  cout << setw(18) << right << setfill('=') << "Assets" << setw(12) << left << "=" << endl;
  cout << setfill(' ');
  cout << left << setw(11) << "Name" << setw(11) << "Balance" << setw(8) << "Type" << endl;
  while (curr != nullptr){
    if (curr->type == 2){
      curr->PrintData();
      cout << endl;
      totalAsset += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Assets: " << totalAsset << endl;
}

//print income statement
void incomeStatement(account* head){
  cout << fixed << setprecision(2);
  account* curr = head;
  float totalRevenue = 0;
  cout << setw(19) << right << setfill('=') << "Revenues" << setw(11) << left << "=" << endl;
  cout << setfill(' ');
  cout << left << setw(11) << "Name" << setw(11) << "Balance" << setw(8) << "Type" << endl;
  while (curr != nullptr){
    if (curr->type == 1){
      curr->PrintData();
      cout << endl;
      totalRevenue += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Revenues: " << totalRevenue << endl;
  curr = head;
  float totalExpense = 0;
  cout << setw(19) << right << setfill('=') << "Expenses" << setw(11) << left << "=" << endl;
  cout << setfill(' ');
  cout << left << setw(11) << "Name" << setw(11) << "Balance" << setw(8) << "Type" << endl;
  while (curr != nullptr){
    if (curr->type == 0){
      curr->PrintData();
      cout << endl;
      totalExpense += curr->balance;
    }
    curr = curr->next;
  }
  cout << "Total Expenses: " << totalExpense << endl;
  cout << "------------------------------" << endl;
  cout << "Net Gain/Loss: " << totalRevenue - totalExpense << endl;
  float ratio = totalRevenue/totalExpense;
  cout << "Expense-Revenue Ratio: 1:" << ratio << endl;
};

//check if the input string is a single digit
bool check(string input){
  if (input.length() != 1){
    return false;
  }
  if (isdigit(input[0])){
    return true;
  }else{
    return false;
  }
};

//output alert file
void outputAlert(float amount, string fileName){
  ofstream file;
  file.open(fileName);
  if (file.is_open()){
    file << amount;
  }else{
    cout << "Output expense alert file failed" << endl;
  }
  file.close();
};

//delete target account
void deleteAccount(account* acc, account* &head, account* &tail, transaction* headT){
  if (acc->previous == nullptr && acc->next != nullptr){
    acc->next->previous = nullptr;
    head = acc->next;
  }else if (acc->previous != nullptr && acc->next == nullptr){
    acc->previous->next = nullptr;
    tail = acc->previous;
  }else if (acc->previous != nullptr && acc->next != nullptr){
    acc->previous->next = acc->next;
    acc->next->previous = acc->previous;
  }else{
    head = nullptr;
    tail = nullptr;
  }
  transaction* curr = headT;
  while (curr != nullptr){
    if (curr->name1 == acc->name){
      curr->acc1 = nullptr;
    }
    if (curr->name2 == acc->name){
      curr->acc2 = nullptr;
    }
    curr = curr->next;
  }
  delete acc;
};
