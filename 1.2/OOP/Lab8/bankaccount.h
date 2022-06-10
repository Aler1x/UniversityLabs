#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#ifndef SET_H
#define SET_H
#include <QString>
#include <QLabel>
#include <QTableWidget>
#include <QLineEdit>
#include <QTextStream>
#include <QFile>
#endif //SET_H

class BankAccount
{
public:
  double m_money;
  QString m_transactionHistory;

  BankAccount(){};

  BankAccount(double m){
    m_money = m;
    m_transactionHistory = "";
  }

  ~BankAccount(){}
  void withdrawMoney(double amount){};
  void transferMoney(double amount){};
  void payForUtilities(double amount){};
  void displayTransactionHistory(QTableWidget *tbw, double money){};
  void enterOnAccount(double amount){};
  void saveInFile(QString str){};
  QString print(){
    return "This class: BankAccount. All classes StandartBankAccount, SocialBankAccount, VIPBankAccount";
  }
};

class StandartBankAccount : protected BankAccount{
public:
  StandartBankAccount(double m):BankAccount(m){}

  double getMoney();
  void withdrawMoney(double amount);
  void transferMoney(double amount);
  void payForUtilities(double amount);
  void displayTransactionHistory(QTableWidget *tbw, double money);
  void enterOnAccount(double amount);
  void saveInFile(QString str);
  QString print();
};

class SocialBankAccount : public BankAccount{

public:
  SocialBankAccount(double m):BankAccount(m){}

  void withdrawMoney(double amount);
  void transferMoney(double amount);
  void payForUtilities(double amount);
  void displayTransactionHistory(QTableWidget *tbw, double money);
  void enterOnAccount(double amount);
  void saveInFile(QString str);
  QString print();

  void defoultDeposit();
};

class VIPBankAccount : public BankAccount{

protected:
  double m_creditMoney;

public:
  VIPBankAccount(double m):BankAccount(m){m_creditMoney = 0;}

  void withdrawMoney(double amount);
  void transferMoney(double amount);
  void payForUtilities(double amount);
  void displayTransactionHistory(QTableWidget *tbw, double money);
  void enterOnAccount(double amount);
  void saveInFile(QString str);
  QString print();

  void defoultDeposit();
  void takeCredit(double creditMoney);
  void creditPercents();

  double getCreditMoney();
  void returnCredit();
};

#endif // BANKACCOUNT_H
