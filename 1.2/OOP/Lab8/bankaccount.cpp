#include "bankaccount.h"

#define STANDART_COMMISION 0.03
#define SOCIAL_DEPOSIT_PERCENT (0.05)

#define VIP_CREDIT_LIMIT 100000
#define VIP_DEPOSIT_PERCENT 0.07
#define VIP_CREDIT_PERCENT 0.1

//-----------------------------------------------------------------------------------
//---------------------------------Standart Bank Account-----------------------------
//-----------------------------------------------------------------------------------

double StandartBankAccount::getMoney()
{
return m_money;
}

void StandartBankAccount::withdrawMoney(double amount) {
  m_money -=amount + (amount * STANDART_COMMISION);

  QString str = "Зі звичайного рахунку знято " + QString::number(amount) + "грн" + " + " + QString::number(amount * STANDART_COMMISION) + "грн комісії" +
                "\nНа рахунку залишилось " + QString::number(m_money) + "грн.";
  saveInFile(str);
}

void StandartBankAccount::transferMoney(double amount)
{
  m_money -= amount + (amount * STANDART_COMMISION);

  QString str = "Зі звичайного рахунку знято " + QString::number(amount + (amount * STANDART_COMMISION)) + "грн.\nНа рахунку залишилось " + QString::number(m_money) + "грн." +
      "\nПереказано " + QString::number(amount) +"грн.";
  saveInFile(str);
}

void StandartBankAccount::payForUtilities(double amount)
{
  m_money -=amount + (amount * STANDART_COMMISION);

  QString str = "Зі звичайного рахунку знято " + QString::number(amount) + "грн.\nНа рахунку залишилось " + QString::number(m_money) + "грн.";
  saveInFile(str);
}

void StandartBankAccount::displayTransactionHistory(QTableWidget *tbw, double money)
{
 tbw->insertRow(0);
 QTableWidgetItem *item = new QTableWidgetItem();
 QString str = "0";
 if(money>0){
    str = "+" + QString::number(money);
   } else {
    str = QString::number(money);
   }
 item->setText(str);
 tbw->setItem(0, 0, item);
 m_transactionHistory += str += ", ";
}

void StandartBankAccount::enterOnAccount(double amount)
{
  amount = amount - amount*STANDART_COMMISION;
  m_money +=amount;
  QString str = "На звичайний рахунок додано " + QString::number(amount) + "грн.\nНа рахунку наявно " + QString::number(m_money) + "грн.";
}

void StandartBankAccount::saveInFile(QString str) {
  QTextStream out(stdout);

  QFile file("D:\\University\\2_semester\\OOP\\Lab8\\Backup\\StandartAccoutData.txt");

  if(file.open(QIODevice::WriteOnly)){
      QTextStream out(&file);
      str+="\n\n";
      out << str << Qt::endl;
    } else {
      qWarning("Помилка: файл не можливо відкрити");
    }
  file.close();
}

QString StandartBankAccount::print()
{
  return "This class: StandartBankAccount. All classes StandartBankAccount, SocialBankAccount, VIPBankAccount";
}

//-----------------------------------------------------------------------------------
//---------------------------------VIP Bank Account---------------------------------
//-----------------------------------------------------------------------------------

void VIPBankAccount::withdrawMoney(double amount)
{
  m_money -=amount;

  QString str = "З ВІП рахунку знято " + QString::number(amount) + "грн.\nНа рахунку залишилось " + QString::number(m_money) + "грн.";
  saveInFile(str);
}

void VIPBankAccount::transferMoney(double amount)
{
  m_money -= amount;

  QString str = "Зі ВІП рахунку знято " + QString::number(amount) + "грн.\nНа рахунку залишилось " + QString::number(m_money) + "грн." +
      "\nПереказано " + QString::number(amount) +"грн.";
  saveInFile(str);
}

void VIPBankAccount::payForUtilities(double amount)
{
  m_money -=amount;

  QString str = "Зі ВІП рахунку знято " + QString::number(amount) + "грн.\nНа рахунку залишилось " + QString::number(m_money) + "грн.";
  saveInFile(str);
}

void VIPBankAccount::displayTransactionHistory(QTableWidget *tbw, double money)
{
  tbw->insertRow(0);
  QTableWidgetItem *item = new QTableWidgetItem();
  QString str = "0";
  if(money>0){
     str = "+" + QString::number(money);
    } else {
     str = QString::number(money);
    }
  item->setText(str);
  tbw->setItem(0, 0, item);
  m_transactionHistory += str += ", ";
}

void VIPBankAccount::enterOnAccount(double amount)
{
  m_money +=amount;
  QString str = "На ВІП рахунок додано " + QString::number(amount) + "грн.\nНа рахунку наявно " + QString::number(m_money) + "грн.";
  saveInFile(str);
}

void VIPBankAccount::saveInFile(QString str)
{
  QTextStream out(stdout);

  QFile file("D:\\University\\2_semester\\OOP\\Lab8\\Backup\\VIPAccoutData.txt");

  if(file.open(QIODevice::Append)){
      QTextStream out(&file);
      str+="\n\n";
      out << str << Qt::endl;
    } else {
      qWarning("Помилка: файл не можливо відкрити");
    }
  file.close();
}

QString VIPBankAccount::print()
{
  return "This class: VIPBankAccount. All classes StandartBankAccount, SocialBankAccount, VIPBankAccount";
}

void VIPBankAccount::defoultDeposit()
{
  if(m_money > 10000){
     m_money += m_money * VIP_DEPOSIT_PERCENT;
     QString str = "На ВІП рахунок нараховано депозит " + QString::number(m_money*VIP_DEPOSIT_PERCENT) + "грн.\nНа рахунку наявно " + QString::number(m_money) + "грн.\n\n";
     saveInFile(str);
    }
}

void VIPBankAccount::takeCredit(double creditMoney)
{
 if(creditMoney <= VIP_CREDIT_LIMIT && creditMoney > 0){
     m_creditMoney += creditMoney;
     m_money += creditMoney;
 QString str = "На ваш рахунок додано " + QString::number(m_creditMoney) + "грн кредитних коштів.\nНа рахунку наявно " + QString::number(m_money) + "грн.";
 saveInFile(str);
   }
}

void VIPBankAccount::creditPercents()
{
  m_money -= m_creditMoney * VIP_CREDIT_PERCENT;
  QString str = "З ВІП рахунку знято " + QString::number(m_creditMoney * VIP_CREDIT_PERCENT) + "грн для погашення відсотків по кредиту.\nНа рахунку залишилось " + QString::number(m_money) + "грн.";
  saveInFile(str);
}

double VIPBankAccount::getCreditMoney()
{
return m_creditMoney;
}

void VIPBankAccount::returnCredit()
{
 m_money-= m_creditMoney;

 QString str = "З ВІП рахунку знято " + QString::number(m_creditMoney) + "грн для погашення кредитної заборгованості.\nНа рахунку залишилось " + QString::number(m_money) + "грн.";
 m_creditMoney = 0;
 saveInFile(str);
}

//-----------------------------------------------------------------------------------
//---------------------------------Social Bank Account-------------------------------
//-----------------------------------------------------------------------------------

void SocialBankAccount::withdrawMoney(double amount)
{
  m_money -=amount;

  QString str = "З соціального рахунку знято " + QString::number(amount) + "грн.\nНа рахунку залишилось " + QString::number(m_money) + "грн.";
  saveInFile(str);
}

void SocialBankAccount::transferMoney(double amount)
{
  m_money -= amount;

  QString str = "Зі соціального рахунку знято " + QString::number(amount) + "грн.\nНа рахунку залишилось " + QString::number(m_money) + "грн." +
      "\nПереказано " + QString::number(amount) +"грн.";
  saveInFile(str);
}

void SocialBankAccount::payForUtilities(double amount)
{
  m_money -=amount;

  QString str = "Зі соціального рахунку знято " + QString::number(amount) + "грн.\nНа рахунку залишилось " + QString::number(m_money) + "грн.";

  saveInFile(str);
}

void SocialBankAccount::displayTransactionHistory(QTableWidget *tbw, double money)
{
  tbw->insertRow(0);
  QTableWidgetItem *item = new QTableWidgetItem();
  QString str = "0";
  if(money>0){
     str = "+" + QString::number(money);
    } else {
     str = QString::number(money);
    }
  item->setText(str);
  tbw->setItem(0, 0, item);
  m_transactionHistory += str += ", ";
}

void SocialBankAccount::enterOnAccount(double amount)
{
  m_money +=amount;
  QString str = "На соціальний рахунок додано " + QString::number(amount) + "грн.\nНа рахунку наявно " + QString::number(m_money) + "грн.\n\n";
  saveInFile(str);
}

void SocialBankAccount::saveInFile(QString str)
{
  QTextStream out(stdout);

  QFile file("D:\\University\\2_semester\\OOP\\Lab8\\Backup\\SocialAccoutData.txt");

  if(file.open(QIODevice::Append)){
      QTextStream out(&file);
      str += "\n";
      out << str << Qt::endl;
    } else {
      qWarning("Помилка: файл не можливо відкрити");
    }
  file.close();
}

QString SocialBankAccount::print()
{
  return "This class: SocialBankAccount. All classes StandartBankAccount, SocialBankAccount, VIPBankAccount";
}

void SocialBankAccount::defoultDeposit()
{
     m_money = (m_money * SOCIAL_DEPOSIT_PERCENT) + m_money;
     QString str = "На соціальний рахунок нараховано депозит " + QString::number(m_money*SOCIAL_DEPOSIT_PERCENT) + "грн.\nНа рахунку наявно " + QString::number(m_money) + "грн.\n\n";
     saveInFile(str);
}
