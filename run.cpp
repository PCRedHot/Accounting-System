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
static transaction* tranHead;  //head transaction pointer

int main(){
  //Create head and tail of transaction, point to nullptr
  transaction* head_T = nullptr;
  transaction* tail_T = nullptr;
  //

  //get accounts from file
  ifstream file;
  file.open("account");
  if (file.is_open()){
    string line;  //line format: name <tab> balance
    account* curr;
    while (getline(file, line)){
      int substrIndex = line.find('\t');
      string name = line.substr(0, substrIndex);
      float balance = stof(line.substr(substrIndex+1, line.length()-substrIndex-1));
      account* NewAcc = new account(name, balance);
      if (curr != nullptr){
        NewAcc->setPrevious(curr);
        curr->setNext(NewAcc);
      }else{
        accHead = NewAcc;
      }
      curr = NewAcc;
      delete NewAcc;
    }
  }else{
    cout << "No account file is found" << endl;
  }
  file.close();

  //get transactions from file
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
        cout << "2. Get existing transaction" << endl;
        cout << "3. Switch transactions" << endl;
        cout << "4. Sort existing transactions accouring date" << endl;
        cout << "5. List all transactions" << endl;
        cout << "Please enter the number" << endl;

        cin >> userInput;

        switch (stoi(userInput)){
          case 1:
          {
            string dateInput, acc1Input, acc2Input, amountInput;
            //User enter infomation of transactions
            cout << "Please enter transaction infomation" << endl;
            cout << "Date: ";
            cin >> dateInput;
            cout << endl << "Account 1: ";
            cin >> acc1Input;
            cout << endl << "Account 2 (input \'none\" if no second account): ";
            cin >> acc2Input;
            cout << endl << "Amount: ";
            cin >> amountInput;

            //Create new dynamic transaction object
            account* acc1 = getAccount(acc1Input), acc2;
            transaction* current_T;
            if (acc2Input != "none"){
              acc2 = getAccount(acc2Input);
              current_T = new transaction(dateInput, stof(amountInput), acc1, acc2);
            }else{
              current_T = new transaction(dateInput, stof(amountInput), acc1);
            }

            //Link the new created transaction to linked list
            if (head_T == nullptr){
              head_T = current_T;
            }else{

            }


            modifyAccounts(current_T, head_A);
            current_T = nullptr;
            delete current_T;
            break;
          }

          case 2:
            break;
.
          case 5:
            transaction* current_T = head_T
            while (current_T->next != nullptr) {
              outputtransaction(current_T);
            }
            cout << "All transactions listed!" <<endl;
            break;
          }
        }else if (userInput == "Account"){
          cout << "Please select functions of accounts" << endl;
          cout << "1. Add an account" << endl;
          cout << "2. Delete an account" << endl;
          cout << "3. Get information of an account" << endl;
          cout << "4. List all accounts in ascending order" << endl;
          cout << "5. List all accounts in descending order" << endl;
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
              cout << "Account named \"" << name << "\" created!" << endl;
              delete newAcc;
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
              //**To-DO**//
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

            default:
            {
            cout << "Unknown user input" << endl;
            break;
            }
          }
        }

  }

  //store accounts and transactions to files
  outputAccountFile(accHead);
  //**TO-DO**//

  return 0;
}
