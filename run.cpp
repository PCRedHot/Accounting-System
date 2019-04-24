#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "tranlib.h"

using namespace std;

//========================================
//functions

//========================================
static account* accHead = nullptr; //head account pointer
static transaction* tranHead = nullptr;  //head transaction pointer
static transaction* tranTail = nullptr;

int main(){
  //Create head and tail of transaction, point to nullptr

  //get accounts from file
  ifstream file;
  file.open("account");
  if (file.is_open()){
    string line;  //line format: name <tab> balance <tab> type
    account* curr = nullptr;
    while (getline(file, line)){
      int substrIndex = line.find('\t');
      string name = line.substr(0, substrIndex);
      float balance = stof(line.substr(substrIndex+1, line.length()-substrIndex-3));
      account* NewAcc = new account(name, balance);
      NewAcc->type = stoi(line.substr(line.length()-1));
      if (curr != nullptr){
        NewAcc->setPrevious(curr);
        NewAcc->next = nullptr;
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
      string date, type, name1, name2, amount;
      iss >> date >> type >> name1 >> name2 >> amount;
      if (!amount.empty()){//(account head, date, type, amount, name1, name2)
        current_T = new transaction(accHead, stoi(date), type, stof(amount), name1, name2);
      }
      else{//(account head, date, type, amount, name1)
        amount = name2;
        name2 = "";
        current_T = new transaction(accHead, stoi(date), type, stof(amount), name1);
      }

      if (tranHead != nullptr){
        tranTail->next = current_T;
        tranTail = current_T;
      }else{
        tranHead = current_T;
        tranTail = current_T;
      }

    }
  }
  else{
    cout << "No transaction file is found" << endl;
  }
  file.close();
  //**TO-DO**//


  string userInput = "";

  while (userInput != "Exit"){
      cout << "intro" << endl;
      cin >> userInput;
      //**TO-DO**//
      //reminders: check if it is the first account to be created!! if so, accHead = newAcc

      if (userInput == "Transaction"){

        //Functions menu of transactions
        cout << "Please select functions of transaction" << endl;
        cout << "1. Create new transaction" << endl;
        cout << "2. Get transactions on specific date" << endl;
        cout << "3. Get transactions of particular type" << endl;
        cout << "4. Sort existing transactions accouring date" << endl;
        cout << "5. List all transactions" << endl;
        cout << "6. Output all transactions to file" << endl;
        cout << "Please enter the number" << endl;

        cin >> userInput;

        switch (stoi(userInput)){
          case 1:
          {
            string input;
            cout << "Which kinds of transaction you want to record?" << endl;
            cout << "1. Expense" << endl;
            cout << "2. Revenue" << endl;
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
              cout << "Expense account: ";
              cin >> acc1Input;
              cout << "Asset account (input \"none\" if no asset account): ";
              cin >> acc2Input;
            }else {
              cout << "Revenue account: ";
              cin >> acc1Input;
              cout <<  "Asset account (input \"none\" if no asset account): ";
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
            {
              cout << "Please enter the date" << endl;
              string userInput;
              cin >> userInput;
              int dateFound = stoi(userInput);

              transaction* current_T = tranHead;
              while (current_T != nullptr){
                if (current_T->date == dateFound){
                  cout << current_T->date << " " << typeofTran(current_T->type) <<" ";
                  cout << current_T->name1 << " " << current_T->name2 << " ";
                  cout << current_T->amount <<endl;
                }
              }
              break;
            }

          case 3:{
            cout << "Please enter number of type" <<endl;
            cout << "1. Expense" << endl;
            cout << "2. Revenue" << endl;
            int typeFound;
            cin >> typeFound;

            transaction* current_T = tranHead;
            while (current_T != nullptr){
              if (current_T->type == typeFound){
                cout << current_T->date << " " << typeofTran(current_T->type) <<" ";
                cout << current_T->name1 << " " << current_T->name2 << " ";
                cout << current_T->amount <<endl;
              }
              current_T = current_T->next;
            }
            break;
          }

          case 4:{
            transaction* tranHead_new = nullptr;
            transaction* beforeTran = tranHead;

            int dateBefore;
            while (beforeTran != nullptr){
              transaction* current_T_new = tranHead_new;
              transaction temp = *beforeTran;
              temp.previous = nullptr;
              temp.next = nullptr;
              transaction* afterthis = find_insert(tranHead_new, temp.date);

              if (afterthis == nullptr){
                temp.next = tranHead_new;
                tranHead_new = &temp;
                temp.previous = nullptr;
              }
              else {

                afterthis->next->previous = &temp;
                temp.next = afterthis->next;
                temp.previous = afterthis;
                afterthis->next = &temp;

              }
              beforeTran = beforeTran->next;
            }
            tranHead = tranHead_new;
          }

          case 5:
            {
            transaction* current_output = tranHead;
            cout<< "Date  Type  Account1  Account2  Amount";//Need to correct format
            while (current_output != nullptr){
              cout << current_output->date << " ";
              if (current_output->type == 1) cout << "Expense" <<" ";
              else  cout << "Revenue" <<" ";
              cout << current_output->name1 << " ";
              if (!current_output->name2.empty()) cout << current_output->name2 << " ";
              cout << current_output->amount <<endl;
            }
            current_output = nullptr;
            break;
            }

          case 6:
            {
              ofstream fout("transaction");
              if (fout.is_open()){
                transaction* current_output = tranHead;
                cout<< "Date  Type  Account1  Account2  Amount";//Need to correct format
                while (current_output != nullptr){
                  fout << current_output->date << " ";
                  if (current_output->type == 1) fout << "Expense" <<" ";
                  else  fout << "Revenue" <<" ";
                  fout << current_output->name1 << " ";
                  if (!current_output->name2.empty()) fout << current_output->name2 << " ";
                  fout << current_output->amount <<endl;
                }
              }
              fout.close();

              cout << "All Transactions have been outputed to file!" << endl;
              break;
            }
          }
        }
        else if (userInput == "Account"){
          cout << "Please select functions of accounts" << endl;
          cout << "1. Add an account" << endl;
          cout << "2. Delete an account" << endl;
          cout << "3. Get information of an account" << endl;
          cout << "4. List all accounts in ascending order" << endl;
          cout << "5. List all accounts in descending order" << endl;
          cout << "6. Output all accounts to a file" << endl;
          cout << "7. Set amount of an account" << endl;
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
                newAcc->next = nullptr;
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
            account* accPtr = getAccount(name, accHead);
            if (accPtr == nullptr){
              cout << "Account named \"" << name << "\" not exist!" << endl;
            }else{
              deleteAccount(accPtr, accHead);
              cout << "Account \"" << name << "\" deleted!" << endl;
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
              cout << "-----transaction History-----" << endl;
              cout << "Date\tType\tBalance\tAccount1\tAccount2" << endl;
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
