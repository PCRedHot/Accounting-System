class account{
public:
  string name;
  float balance;
  account* previous;
  account* next;
  void setName(string);
  void setBalance(float);
  float addAmount(float);
  void setPrevious(account);
  void setPrevious(account*);
  void setNext(account);
  void setNext(account*);

  string getName();
  float getBalance();
  account* getNext();
  account* getPrevious();

  string getData();
}
