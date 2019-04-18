#include <iostream>
#include <string>
#include <fstream>
#include "account.h"
#include "transaction.h"

using namespace std;

//========================================
//functions
void outputAccountFile();

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
      
  }

  //store accounts and transactions to files
  outputAccountFile();
  //**TO-DO**//

  return 0;
}

void outputAccountFile(){
  if (accHead != nullptr){
    ofstream file;
    file.open("account");
    account* curr = accHead;
    while (curr != nullptr){
      file << curr->getData();
      curr = curr->getNext();
    }
    file.close();
  }else{
    cout << "No account to store" << endl;
  }
}
