#pragma once
#include "Person.h"
#include "Transaction.h"
class Client :
    public Person
{
private:
    double balance;
    bool isActive;

    static const int MAX_TRANSACTIONS = 100;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
    bool autoTransferDone;
    void turn_on();
    bool isTransferTimeAllowed();
    string getAccountStatus();

public:
    Client(string name, string password, double balance);

    void set_balance(double balance);
    double get_balance();

    void setActive(bool status);
    bool getActive();

    void deposit(double amount);
    void withdraw(double amount);
    void transfer_to(double amount, Client& recipient);
    void auto_transfer_at(int hour,int minute,int second,double amount, Client& recipient);

    void check_balance();
    void check_account_status();
    void show_transaction_history();

    void display();
};
