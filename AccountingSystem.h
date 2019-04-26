#include "tranlib.h"
#include <string>
#include <iostream>

using namespace std;

void listExpense(account*);
void listRevenue(account*);
void listAsset(account*);
void incomeStatement(account*);
bool check(string);
void outputAlert(float, string);
void deleteAccount(account*, account*&, account*&, transaction*);
