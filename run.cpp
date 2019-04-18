#include <iostream>
#include <string>
#include "account.h"
#include "transaction.h"

using namespace std;

int main(){
  cout << "intro" << endl;
  string userInput = "";

  while (userInput != "Exit"){
      cin >> userInput;
  }
  return 0;
}
