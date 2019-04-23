#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "accountlib.h"
#include "tranlib.h"

using namespace std;

//========================================
//functions

//========================================
static account* accHead; //head account pointer
static transaction* tranHead = nullptr;  //head transaction pointer
static transaction* tranTail = nullptr;

int main(){
  //Create head and tail of transaction, point to nullptr

  //get accounts from file
  ifstream file;
  file.open("account");
  if (file.is_open()){
    string line;  //line format: name <tab> balance <tab> type
    account* curr;
    while (getline(file, line)){
      int substrIndex = line.find('\t');
      string name = line.substr(0, substrIndex);
      float balance = stof(line.substr(substrIndex+1, line.length()-substrIndex-3));
      account* NewAcc = new account(name, balance);
      NewAcc->type = stoi(line.substr(line.length()-1));
      if (curr != nullptr){
        NewAcc->setPrevious(curr);
        curr->setNext(NewAcc);
      }else{
        accHead = NewAcc;
      }
      curr = NewAcc;
    }
  }else{
    cout << "No account file is found" << endl;
  }
  file.close();

  //get transactions from file
  file.open("transaction"); //line format: YYYYMMDD <tab> amount <tab> acc1 <tab> acc2
  if (file.is_open()){
    string line;
    istringstream iss(line);
    while (getline(file, line)){

      transaction* current_T = nullptr;
      string date, acc1, acc2, amount;
      iss >> date >> amount >> acc1 >> acc2;
      if (!acc2.empty())
        current_T = new transaction(stoi(date), stof(amount), findNode(acc1, accHead), findNode(acc2, accHead));
      else  current_T = new transaction(stoi(date), stof(amount), findNode(acc1, accHead));

      if (tranHead != nullptr){
        tranTail->next = current_T;
        tranTail = current_T;
      }
      else{
        tranHead = current_T;
        tranTail = current_T;
      }

    }
  }else{
    cout << "No transaction file is found !" << endl;
  }
  file.close();
  //**TO-DO**//


  cout << "intro" << endl;    //**TO-DO**//
  string userInput = "";

  while (userInput != "Exit"){
      cin >> userInput;
      //**TO-DO**//
      //reminders: check if it is the first account to be created!! if so, accHead = newAcc

      if (userInput == "Transction"){

        //Functions menu of transactions
        cout << "Please select functions of transaction" << endl;
        cout << "1. Create new transaction" << endl;
        cout << "2. Get transactions on specific date" << endl;
        cout << "3. Sort existing transactions accouring date" << endl;
        cout << "4. List all transactions" << endl;
        cout << "Please enter the number" << endl;

        cin >> userInput;

        switch (stoi(userInput)){
          case 1:
          {
            string input;
            cout << "Which kinds of transaction you want to record?" << endl;
            cout << "1. Expenses" << endl;
            cout << "2. Revenues" << endl;
            cin >> input;
            if (stoi(input) > 2 || stoi(input) < 1){
              cout << "Unknown user input, returning to menu" << endl;
              break;
            }
            string dateInput, acc1Input, acc2Input, amountInput;
            //User enter infomation of transactions
            cout << "Please enter transaction infomation" << endl;
            cout << "Date (YYYYMMDD): ";
            cin >> dateInput;

            if (stoi(input) == 1){
              cout << endl << "Expense account: ";
              cin >> acc1Input;
              cout << endl << "Account to deduct (input \'none\" if no asset account): ";
              cin >> acc2Input;
            }else {
              cout << endl << "Revenue account: ";
              cin >> acc1Input;
              cout << endl << "Asset account  (input \'none\" if no asset account): ";
              cin >> acc2Input;
            }
            cout << endl << "Amount: ";
            cin >> amountInput;
            cout << endl;

            //Create new dynamic transaction object
            account* acc1 = getAccount(acc1Input, accHead);
            account* acc2;
            if (acc1 == nullptr){
              cout << "Account \"" << acc1Input << "\" not found!" << endl;
              cout << "This transaction is not created" << endl;
              break;
            }
            if (acc1->type != 1 && stoi(input) == 1){
              cout << "Account \"" << acc1Input << "\" is not an expense account!" << endl;
              cout << "This transaction is not created" << endl;
              break;
            }
            if (acc1->type != 2 && stoi(input) == 2){
              cout << "Account \"" << acc1Input << "\" is not a revenue account!" << endl;
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
              if (acc2->type != 3){
                cout << "Account \"" << acc1Input << "\" is not an asset account!" << endl;
                cout << "This transaction is not created" << endl;
                break;
              }
              current_T = new transaction(stoi(dateInput), stof(amountInput), acc1, acc2);
              acc1->balance += stof(amountInput);
              if (stoi(input) == 1){
                acc2->balance -= stof(amountInput);
              } else{
                acc2->balance += stof(amountInput);
              }
            }else{
              current_T = new transaction(stoi(dateInput), stof(amountInput), acc1);
              acc1->balance += stof(amountInput);
            }

            //Link the new created transaction to linked list
            if (tranHead == nullptr){
              tranHead = current_T;
            }else{
              transaction* last = getLastTransaction(tranHead);
              last->setNext(current_T);
              current_T->setPrevious(last);
            }
            current_T->type = stoi(input);

            //modifyAccounts(current_T, head_A); ??
            break;
          }

          case 2:
            break;

          case 5:
            listTransaction(tranHead);
            break;
          }
        }else if (userInput == "Account"){
          cout << "Please select functions of accounts" << endl;
          cout << "1. Add an account" << endl;
          cout << "2. Delete an account" << endl;
          cout << "3. Get information of an account" << endl;
          cout << "4. List all accounts in ascending order" << endl;
          cout << "5. List all accounts in descending order" << endl;
          cout << "6. Output all accounts to a file" << endl;
          cout << "Please enter the number" << endl;
          cin >> userInput;
          string name;
          switch (stoi(userInput)) {
            case 1:
            {
            cout << "Please input the name of the account: ";
            cin >> name;
            cout << endl;
            if (getAccount(name, accHead) != nullptr){
              cout << "Account named \"" << name << "\" already exist!" << endl;
            }else{
              account* newAcc = new account(name);
              if (accHead == nullptr){
                accHead = newAcc;
              }else{
                account* lastAcc = getLastAccount(accHead);
                lastAcc->setNext(newAcc);
                newAcc->setPrevious(lastAcc);
              }
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
            cout << "Please input the name of the account: ";
            cin >> name;
            cout << endl;
            account* accPtr = getAccount(name, accHead);
            if (accPtr == nullptr){
              cout << "Account named \"" << name << "\" not exist!" << endl;
            }else{
              accPtr->deleteAccount();
            }
            break;
            }

            case 3:
            {
            cout << "Please input the name of the account: ";
            cin >> name;
            cout << endl;
            account* accPtr = getAccount(name, accHead);
            if (accPtr == nullptr){
              cout << "Account named \"" << name << "\" not exist!" << endl;
            }else{
              cout << "Account information of " << name << ":"<< endl;
              cout << fixed << setprecision(2);
              cout << "Current Balance: " <<  accPtr->balance;
              cout << "-----transaction History-----" << endl;
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
              cout << "Input the name of the file, include file type (e.g. output.txt)" << endl;
              cin >> fileName;
              outputAccountFile(accHead, fileName);
              cout << "Output as \"" << fileName << "\"" << endl;
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
  outputAccountFile(accHead, "account");
  //**TO-DO**//

  return 0;
}
