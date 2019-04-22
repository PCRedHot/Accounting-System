#include "account.h"
#include <string>
#include <iostream>

account* getAccount(std::string, account*);
void switchAccount(account*, account*);
void sortAccount_Balance(account*);
void rsortAccount_Balance(account*);
void outputAccountFile(account*);
account* getLastAccount(account*);
void listAccount(account*);
