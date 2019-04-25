#include "account.h"
#include <string>

using namespace std;

account* getAccount(string, account*);
void switchAccount(account*, account*);
void sortAccount_Balance(account*);
void rsortAccount_Balance(account*);
void outputAccountFile(account*, string);
account* getLastAccount(account*);
void listAccount(account*);
void deleteAccount(account*, account*&, account*&);
