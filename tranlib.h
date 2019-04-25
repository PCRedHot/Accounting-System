#include <string>
#include "transaction.h"

transaction* getLastTransaction(transaction*);
void switchTransation(transaction*, transaction*, transaction*&, transaction*&));
void sortTransaction_Date(transaction*&, transaction*&);
void rsortTransaction_Date(transaction*&, transaction*&);
void listTransaction(transaction*);
void outputTransactionFile(transaction*, string);
transaction* getTransaction(int, int, transaction*);
int listTransaction_date(int, transaction*);
void deleteTransaction(transaction*, transaction*&, transaction*&);
