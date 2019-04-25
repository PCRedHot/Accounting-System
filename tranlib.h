#include <string>
#include "transaction.h"

transaction* getLastTransaction(transaction*);
void switchTransaction(transaction*, transaction*);
void sortTransaction_Date(transaction*);
void rsortTransaction_Date(transaction*);
void listTransaction(transaction*);
void outputTransactionFile(transaction*, string);
transaction* getTransaction(int, int, transaction*);
int listTransaction_date(int, transaction*);
void deleteTransaction(transaction*, transaction*&, transaction*&);
