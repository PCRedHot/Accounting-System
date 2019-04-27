#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "AccountingSystem.h"

using namespace std;

//========================================
//functions

//========================================
//Static variables
static account* accHead = nullptr; //head account pointer
static account* accTail = nullptr;
static transaction* tranHead = nullptr;  //head transaction pointer
static transaction* tranTail = nullptr;
static float expenseAlert = -3035564940;
static float totalExpense = 0;
static const string accountFileName = "account";
static const string transactionFileName = "transaction";
static const string alertFileName = "alert";
//========================================

int main(){
  cout << fixed << setprecision(2);

  //get alert information from file
  ifstream file;
  file.open(alertFileName);
  if (file.is_open()){
    string data;
    file >> data;
    expenseAlert = stof(data);
  }else{
    cout << "No expense alert file is found" << endl;
  }
  file.close();

  //get accounts from file
  file.open(accountFileName);
  if (file.is_open()){
    string line;  //line format: name <tab> balance <tab> type
    while (getline(file, line)){
      int substrIndex = line.find('\t');
      string name = line.substr(0, substrIndex);
      float balance = stof(line.substr(substrIndex+1, line.length()-substrIndex-3));
      account* NewAcc = new account(name, balance);
      NewAcc->type = stoi(line.substr(line.length()-1));
      if (accTail != nullptr){
        NewAcc->setPrevious(accTail);
        NewAcc->next = nullptr;
        accTail->setNext(NewAcc);
      }else{
        accHead = NewAcc;
      }
      accTail = NewAcc;
    }
  }else{
    cout << "No account file is found" << endl;
  }
  file.close();

  //get transactions from file

  file.open(transactionFileName); //format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
  if (file.is_open()){
    string line;
    while (getline(file, line)){

      transaction* current_T = nullptr;
      string date, type, name1, amount;
      int substrIndex = line.find('\t');
      date = line.substr(0, substrIndex);
      line = line.substr(substrIndex+1);
      substrIndex = line.find('\t');
      type = line.substr(0, substrIndex);
      line = line.substr(substrIndex+1);
      substrIndex = line.find('\t');
      amount = line.substr(0, substrIndex);
      line = line.substr(substrIndex+1);
      substrIndex = line.find('\t');
      name1 = line.substr(0, substrIndex);
      line = line.substr(substrIndex+1);
      if (!line.empty()){//format YYYYMMDD <tab> type <tab> amount <tab> acc1 (<tab> acc2)
        current_T = new transaction(accHead, stoi(date), stof(amount), name1, line);
      }
      else{
        current_T = new transaction(accHead, stoi(date), stof(amount), name1);
      }

      current_T->type = stoi(type);

      if (stoi(type) == 0){
        totalExpense += stof(amount);
      }else if (stoi(type) == 1){
        totalExpense -= stof(amount);
      }

      if (tranHead == nullptr){
        tranHead = current_T;
        tranTail = current_T;
        current_T->previous = nullptr;
        current_T->next = nullptr;
      }else{
        tranTail->next = current_T;
        current_T->previous = tranTail;
        current_T->next = nullptr;
        tranTail = current_T;
      }

    }
  }
  else{
    cout << "No transaction file is found" << endl;
  }
  file.close();

  //Main menu
  cout << "********************************************" << endl;
  cout << "This is an ENGG1340 project of group 120"  << endl;
  cout << "Powered by Parry Choi and Shane Chen" << endl;
  cout << "********************************************" << endl;
  cout << "Welcome to Accounting System!" << endl;

  string userInput = "";

  while (userInput != "Exit"){
      cout << "********************************************" << endl;
      cout << "1. Account" << endl;
      cout << "2. Transaction" << endl;
      cout << "3. Finance analysis" << endl;
      cout << "Please select a function" << endl;
      cout << "Enter 'Exit' to teminate" << endl;
      cout << "********************************************" << endl;

      cin >> userInput;

      if (!check(userInput) && userInput != "Exit"){
        cout << "Unknown user input" << endl;
        continue;
      }

      //Expense Alert
      if (expenseAlert > -3035564939 && expenseAlert < totalExpense) {
        cout << "!WARNING! Total expense exceed threshold set!" << endl;
      }

      if (userInput == "Transaction" || userInput == "2"){

        //Functions menu of transactions
        cout << "********************************************" << endl;
        cout << "Transaction Menu" << endl;
        cout << "1. Create new transaction" << endl;
        cout << "2. Get transactions on specific date" << endl;
        cout << "3. List all transactions from old to new" << endl;
        cout << "4. List all transactions from new to old" << endl;
        cout << "5. Reverse and delete a transaction" << endl;
        cout << "6. Output transactions to a file" << endl;
        cout << "7. Return to last page" << endl;
        cout << "Please select a function" << endl;
        cout << "********************************************" << endl;

        cin >> userInput;
        if (!check(userInput)){
          cout << "Unknown user input" << endl;
          continue;
        }

        switch (stoi(userInput)){
          case 1:
          {
            string input;
            cout << "Which kinds of transaction you want to record?" << endl;
            cout << "1. Expense" << endl;
            cout << "2. Revenue" << endl;
            cout << "3. Asset transfer" << endl;
            cin >> input;
            if (stoi(input) > 3 || stoi(input) < 1){
              cout << "Unknown user input, returning to menu" << endl;
              break;
            }
            string dateInput, acc1Input, acc2Input, amountInput;
            //User enter infomation of transactions
            cout << "Please enter transaction infomation" << endl;
            cout << "Date (YYYYMMDD): ";
            cin >> dateInput;

            if (stoi(input) == 1){
              cout << "Expense account: ";
              cin >> acc1Input;
              cout << "Asset account (input \"none\" if no asset account): ";
              cin >> acc2Input;
            }else if (stoi(input) == 2) {
              cout << "Revenue account: ";
              cin >> acc1Input;
              cout << "Asset account (input \"none\" if no asset account): ";
              cin >> acc2Input;
            }else {
              cout << "Asset account 1: ";
              cin >> acc1Input;
              cout << "Asset account 2 (input \"none\" if no asset account): ";
              cin >> acc2Input;
            }
            cout <<  "Amount: ";
            cin >> amountInput;

            //Create new dynamic transaction object
            account* acc1 = getAccount(acc1Input, accHead);
            account* acc2;
            if (acc1 == nullptr){
              cout << "Account \"" << acc1Input << "\" not found!" << endl;
              cout << "This transaction is not created" << endl;
              break;
            }
            if (acc1->type != 0 && stoi(input) == 1){
              cout << "Account \"" << acc1Input << "\" is not an expense account!" << endl;
              cout << "This transaction is not created" << endl;
              break;
            }
            if (acc1->type != 1 && stoi(input) == 2){
              cout << "Account \"" << acc1Input << "\" is not a revenue account!" << endl;
              cout << "This transaction is not created" << endl;
              break;
            }
            if (acc1->type != 2 && stoi(input) == 3){
              cout << "Account \"" << acc1Input << "\" is not an asset account!" << endl;
              cout << "This transaction is not created" << endl;
              break;
            }
            transaction* current_T;
            if (acc2Input != "none"){
              acc2 = getAccount(acc2Input, accHead);
              if (acc2 == nullptr){
                cout << "Account \"" << acc2Input << "\" not found!" << endl;
                cout << "This transaction is not created" << endl;
                break;
              }
              if (acc2->type != 2){
                cout << "Account \"" << acc2Input << "\" is not an asset account!" << endl;
                cout << "This transaction is not created" << endl;
                break;
              }
              current_T = new transaction(stoi(dateInput), stof(amountInput), acc1, acc2);
              acc1->balance += stof(amountInput);
              if (stoi(input) == 2){
                acc2->balance += stof(amountInput);
              } else{
                acc2->balance -= stof(amountInput);
              }
            }else{
              current_T = new transaction(stoi(dateInput), stof(amountInput), acc1);
              acc1->balance += stof(amountInput);
            }

            if (stoi(input) == 1){
              totalExpense += stof(amountInput);
            }else if (stoi(input) == 2){
              totalExpense -= stof(amountInput);
            }

            //Link the new created transaction to linked list
            if (tranHead == nullptr){
              tranHead = current_T;
            }else{
              tranTail->next = current_T;
              current_T->previous = tranTail;
            }
            tranTail = current_T;
            current_T->type = stoi(input)-1;

            cout << "This transaction is created successfully!" << endl;

            break;
          }

          case 2:
            {
              cout << "Please input the date: ";
              string userInput;
              cin >> userInput;
              listTransaction_date(stoi(userInput), tranHead);
              break;
            }

          case 3:
          {
            sortTransaction_Date(tranHead);
            listTransaction(tranHead);
            break;
          }

          case 4:
          {
            rsortTransaction_Date(tranHead);
            listTransaction(tranHead);
            break;
          }

          case 5:
          {
            string dateInput, id;
            int max_id;
            cout << "Please input the date of transaction (YYYYMMDD): ";
            cin >> dateInput;
            max_id = listTransaction_date(stoi(dateInput), tranHead);
            if (max_id == 0){
              cout << "No transactions found!" << endl;
              break;
            }
            cout << "Please select the transaction: ";
            cin >> id;
            if (stoi(id) > max_id || stoi(id) < 1){
              cout << "invaild user input" << endl;
              break;
            }else {
              transaction* target = getTransaction(stoi(dateInput), stoi(id), tranHead);
              if (target != nullptr){
                target->reverseTransaction();
                deleteTransaction(target, tranHead, tranTail);
              }
              cout << "Transaction deleted!" << endl;
            }
            break;
          }

          case 6:
          {
            string fileName;
            cout << "Input the name of the file, include file type (e.g. output.txt): ";
            cin >> fileName;
            if (fileName == transactionFileName){
              cout << "The file name \"" << transactionFileName << "\" is invaild!" << endl;
              cout << "Output failed" << endl;
            }
            outputTransactionFile(tranHead, fileName);
            cout << "Output as \"" << fileName << "\"" << endl;
            break;
          }

          case 7:
          {
            break;
          }

          default:
          {
          cout << "Unknown user input" << endl;
          break;
          }
        }
      }else if (userInput == "Account" || userInput == "1"){

          //Account menu
          cout << "********************************************" << endl;
          cout << "Account Menu" << endl;
          cout << "1. Add an account" << endl;
          cout << "2. Delete an account" << endl;
          cout << "3. Get information of an account" << endl;
          cout << "4. List all accounts in ascending order" << endl;
          cout << "5. List all accounts in descending order" << endl;
          cout << "6. Output all accounts to a file" << endl;
          cout << "7. Set amount of an account" << endl;
          cout << "8. Return to last page" << endl;
          cout << "Please select a function" << endl;
          cout << "********************************************" << endl;

          cin >> userInput;
          if (!check(userInput)){
            cout << "Unknown user input" << endl;
            continue;
          }
          string name;
          switch (stoi(userInput)) {
            case 1:
            {
            cout << "Please input the name of the account: ";
            cin >> name;
            if (getAccount(name, accHead) != nullptr){
              cout << "Account named \"" << name << "\" already exist!" << endl;
            }else{
              account* newAcc = new account(name);
              if (accHead == nullptr){
                accHead = newAcc;
                accTail = newAcc;
              }else{
                accTail->next = newAcc;
                newAcc->previous = accTail;
                newAcc->next = nullptr;
              }
              accTail = newAcc;
              string typeAcc;
              cout << "Which type is the account?" << endl;
              cout << "1. Expense Account" << endl;
              cout << "2. Revenue Account" << endl;
              cout << "3. Asset Account" << endl;
              cin >> typeAcc;
              if (stoi(typeAcc) < 1 || stoi(typeAcc) > 3){
                cout << "Unknown user input" << endl;
                break;
              }
              newAcc->type = stoi(typeAcc)-1;
              cout << "Account named \"" << name << "\" is created!" << endl;
            }
            break;
            }

            case 2:
            {
            string yesorno;
            cout << "Please input the name of the account: ";
            cin >> name;
            account* accPtr = getAccount(name, accHead);
            if (accPtr == nullptr){
              cout << "Account named \"" << name << "\" not exist!" << endl;
            }else{
              cout << "!WARNING! THIS ACTION WILL DELETE THE ACCOUNT AND YOU ARE NOT ABLE TO RECOVER IT!" << endl;
              cout << "Proceed? (Y/N) " ;
              cin >> yesorno;
              if (yesorno != "Y"){
                cout << "Cancelled" << endl;
                break;
              }else{
                deleteAccount(accPtr, accHead, accTail, tranHead);
                cout << "Account \"" << name << "\" deleted!" << endl;
              }
            }
            break;
            }

            case 3:
            {
            cout << "Please input the name of the account: ";
            cin >> name;
            account* accPtr = getAccount(name, accHead);
            if (accPtr == nullptr){
              cout << "Account named \"" << name << "\" not exist!" << endl;
            }else{
              cout << "Account information of " << name << ":"<< endl;
              cout << fixed << setprecision(2);
              cout << "Current Balance: " <<  accPtr->balance << endl;
              cout << "-------------Transaction History------------" << endl;
              cout << "Date\t\tType\tBalance\t\tAccount1\tAccount2" << endl;
              transaction* curr = tranHead;
              while (curr != nullptr){
                if (curr->acc1 == accPtr || curr->acc2 == accPtr){
                  cout << curr->getData() << endl;
                }
                curr = curr->next;
              }
            }
            break;
            }

            case 4:
            {
            sortAccount_Balance(accHead);
            listAccount(accHead);
            break;
            }

            case 5:
            {
            rsortAccount_Balance(accHead);
            listAccount(accHead);
            break;
            }

            case 6:
            {
              string fileName;
              cout << "Input the name of the file, include file type (e.g. output.txt): ";
              cin >> fileName;
              if (fileName == accountFileName){
                cout << "The file name \"" << accountFileName << "\" is invaild!" << endl;
                cout << "Output failed" << endl;
              }
              outputAccountFile(accHead, fileName);
              cout << "Output as \"" << fileName << "\"" << endl;
              break;
            }

            case 7:
            {
              string accName, input, input2;
              cout << "Input the name of the account: ";
              cin >> accName;
              cout << "Input the amount: ";
              cin >> input;
              cout << "!WARNING! THIS ACTION WILL CHANGE THE AMOUNT OF THE ACCOUNT DIRECTLY!" << endl;
              cout << "Proceed? (Y/N) ";
              cin >> input2;
              if (input2 != "Y"){
                cout << "Cancelled" << endl;
              }else{
                account* accPtr = getAccount(accName, accHead);
                if (accPtr == nullptr){
                  cout << "Account named \"" << accName << "\" not exist!" << endl;
                }else{
                  cout << accName << " has been set to " << input << endl;
                  accPtr->balance = stof(input);
                }
              }
              break;
            }

            case 8:
            {
              break;
            }

            default:
            {
            cout << "Unknown user input" << endl;
            break;
            }
          }
        }else if (userInput == "Finance analysis" || userInput == "3"){
          cout << "********************************************" << endl;
          cout << "Account Menu" << endl;
          cout << "1. List all expense accounts" << endl;
          cout << "2. List all revenue accounts" << endl;
          cout << "3. List all asset accounts" << endl;
          cout << "4. Income statement" << endl;
          cout << "5. Set expense alert" << endl;
          cout << "6. Return to last page" << endl;
          cout << "Please select a function" << endl;
          cout << "********************************************" << endl;
          cin >> userInput;

          if (!check(userInput)){
            cout << "Unknown user input" << endl;
            continue;
          }

          switch (stoi(userInput)) {
            case 1:
            {
              listExpense(accHead);
              break;
            }

            case 2:
            {
              listRevenue(accHead);
              break;
            }

            case 3:
            {
              listAsset(accHead);
              break;
            }

            case 4:
            {
              incomeStatement(accHead);
              break;
            }

            case 5:
            {
              string input;
              cout << "Current expense alert threshold: ";
              if (expenseAlert == -3035564940){
                cout << "none" << endl;
              }else{
                cout << expenseAlert << endl;
              }
              cout << "New threshold (input \"none\" to disable the alert): ";
              cin >> input;
              if (input == "none"){
                expenseAlert = -3035564940;
                cout << "Expense alert disabled" << endl;
              }else{
                expenseAlert = stof(input);
                cout << "Alert threshold set to " << expenseAlert << endl;
              }

            }

            case 6:
            {
              break;
            }

            default:
            {
              cout << "Unknown user input" << endl;
              break;
            }
          }

        }
  }

  //store accounts and transactions to files
  outputAccountFile(accHead, accountFileName);
  outputTransactionFile(tranHead, transactionFileName);
  outputAlert(expenseAlert, alertFileName);

  return 0;
}
