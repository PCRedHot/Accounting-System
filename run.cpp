#include <iostream>
#include <string>
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

  }

  //store accounts and transactions to files
  outputAccountFile(accHead);
  //**TO-DO**//

  return 0;
}
