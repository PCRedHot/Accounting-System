#include <string>
#include "transaction.h"

transaction* getLastTransaction(transaction*);
void switchTransation(transaction*, transaction*);
void sortTransaction_Date(transaction*);
void rsortTransaction_Date(transaction*);
void outputTransaction(transaction*);
void modifyAccounts(transaction*, account*);
