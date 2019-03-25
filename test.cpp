#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Structure of an account
struct Account {
 	string name;     //name of the account
 	bool type;      //type of the account, true for debit account, false for credit account
 	float balance;  // balance of the account
};

//Structure of a transaction
struct Transaction {
 	int id;		       //id of the transaction
	string date;	   //date of the transaction
	string account1; //the first account of the transaction
	string account2; //the second account of the transaction
	float amount;	   //the transaction amount
};

float addAmount(Account& acc, float amount);

static vector<Account> accountList;
static vector<string> accountName;
static vector<Transaction> transactionList;
static int totalTransaction = 0;

//Function: Create a new account
//	input: 	string name - the name of the account
//		bool type - the type of the account
//	output:	none
void createAccount(string name, bool type){
  Account a = {name, type, 0};
  accountName.push_back(name);
	accountList.push_back(a);
}

//Function: Find the index of the account in account list with its name
//	input:	string name-  the name of the account
//	output:	int index - return the index of the account in account list
int findIndexOfAccount(string name){
  for (int i = 0; i < accountName.size(); i++){
    if (accountName[i]==name){
      return i;
    }
  }
  return -1;
}

//Function: Create new transaction
//	input:	string date - the date of the transaction
//		string acc1_name - the name of the first account
//		string acc2_name - the name of the second account
//		float amount - the amount of the transaction
//	output:	none
void createTransaction(string date, string acc1_name, string acc2_name, float amount) {
  int index1 = findIndexOfAccount(acc1_name);
  int index2 = findIndexOfAccount(acc2_name);
  if (index1 == -1){
    cout << "No account named \"" << acc1_name << "\" found!" << endl;
    return;
  }
  if (index2 == -1){
    cout << "No account named \"" << acc2_name << "\" found!" << endl;
    return;
  }
  float amount1 = amount, amount2;
  if (accountList[index1].type != accountList[index2].type){
    amount2 = amount;
  }else {
    amount2 = -amount;
  }
  addAmount(accountList[index1], amount1);
  addAmount(accountList[index2], amount2);
  Transaction a = {++totalTransaction, date, acc1_name, acc2_name, amount};
  transactionList.push_back(a);
}

//Function: Print all accounts in the format “Account_name: Balance”
//	input:	none
//	output:	none
void printAccount(){
  cout << "Account Name: Balance" << endl;
  for (int i = 0; i < accountName.size(); i++){
    cout << accountName[i] << ": " << accountList[i].balance << endl;
  }
}

//Function: Print all Transactions in the format “id: date account1 account2 amount”
//	input:	none
//	output:	none
void printTransaction(){
  cout << "id: date account1 acount2 amount" << endl;
  for (int i = 0; i < totalTransaction; i++){
    cout << transactionList[i].id << ": " << transactionList[i].date << " " << transactionList[i].account1 << " " << transactionList[i].account2 << " " << transactionList[i].amount << endl;
  }
}

//Function: Add amount to an account’s balance
//	input:	Account& acc - target account
//		float amount - amount of money
//	output:	Account& acc - return the adjusted account (pass by reference)
//		float acc.balance - return the newly adjusted balance of the account
float addAmount(Account& acc, float amount){
  acc.balance += amount;
  return acc.balance;
}

int main(){
  string userInput;
  cin >> userInput;
  while (userInput != "Exit"){
    if (userInput == "Add"){
      string name;
      string input;
      cout << "Input the name of the account: ";
      cin >> name;
      cout << "Is the account an expense or asset account (Y/N)? ";
      while(true){
        cin >> input;
        if (input == "Y"){
          createAccount(name, true);
          break;
        }else if (input == "N"){
          createAccount(name, false);
          break;
        }else {
          cout << "Please input either 'Y' or 'N'." << endl;
        }
      }
      cout << "Account " << name << " has been created!" << endl;
    }else if (userInput == "PrintAccount"){
      printAccount();
    }else if (userInput == "PrintTransaction"){
      printTransaction();
    }else if (userInput == "Transaction"){
      string date, acc1_name, acc2_name, strAmount;
      float amount;
      cout << "Input the date of the transaction: ";
      cin >> date;
      cout << "Input the first account of the transaction: ";
      cin >> acc1_name;
      cout << "Input the second account of the transaction: ";
      cin >> acc2_name;
      cout << "Input the amount of the transaction: ";
      cin >> amount;
      cout << strAmount;
      //TO-DO CHECK IF STR AMOUNT IS FLOAT OR NOT
      createTransaction(date, acc1_name, acc2_name, amount);
    }
    cin >> userInput;
  }
  return 0;
}
