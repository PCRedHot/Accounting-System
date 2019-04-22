#include <string>
#include "transaction.h"

transaction* gettransaction(int, transaction*);

void switchTransation(account*, account*);
void sortTransaction_Date(transaction* &head_T);
void rsortTransaction_Date(transaction* &head_T);
void outputTransaction(transaction* current_T);
void modifyAccounts(transaction* current_T, account* head_A);
