#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "accountlib.h"
#include "transaction.h"

using namespace std;

//========================================
//functions

//========================================
static account* accHead; //head account pointer
static transaction* tranHead;  //head transaction pointer

int main(){
  //Create head and tail of transaction, point to nullptr
  Transaction* head_T = nullptr;
  Transaction* tail_T = nullptr;
  int order_T = 1;
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
      account NewAcc = new account(name, balance);
      if (curr != nullptr){
        NewAcc.setPrevious(curr);
        curr->setNext(NewAcc);
      }else{
        accHead = &NewAcc;
      }
      curr = &NewAcc;
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
       
        switch (userInput){
          case 1:
            //Create new dynamic transaction object
            Transaction* current_T = new Transaction (order_T);
            
            //User enter infomation of transactions
            cout << "Please enter transaction infomation" << endl;
            cout << "Format: YYYYMMDD From To Amount" << endl;
            
            getline(cin,userInput);
            string temp;
            istringstream iss(userInput);
            iss >> temp;
            current_T->date = stoi(temp);
            iss >> current_T->name_from;
            iss >> current_T->name_to;
            iss >> temp;
            current_T->amount = stof(temp);

            //Link the new created transaction to linked list
            if (head_T = nullptr){
              head_T = current_T;
              tail_T = current_T;
              current_T = head->next;
            }
            else{
              tail_T->next = current_T;
              tail_T = current_T->next;
            }
            order_T++;
            
            modifyAccounts(current_T, head_A);
            current_T = nullptr;
            break;

          case 2:
            break;
.
          case 5:
            Transaction* current_T = head_T
            while (current_T->next != nullptr) {
              outputTransaction(current_T);
            }
            cout << "All Transactions listed!" <<endl;
            break;
  }

  //store accounts and transactions to files
  outputAccountFile(accHead);
  //**TO-DO**//

  return 0;
}
