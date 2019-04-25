#include <string>
#include "transaction.h"

transaction* getLastTransaction(transaction*);
void switchTransation(transaction*, transaction*);
void sortTransaction_Date(transaction*);
void rsortTransaction_Date(transaction*);
void listTransaction(transaction*);
void outputTransactionFile(string, transaction*);
transaction* getTransaction(int, int, transaction*);
int listTransaction_date(int, transaction*);
void deleteTransaction(transaction*);
