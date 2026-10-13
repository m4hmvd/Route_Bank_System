#pragma once
#include "Person.h"
#include "Transaction.h"
#include <vector>





class Admin;
class Employee;

class Client : public Person
{
private:
    static int client_counter;
    double balance;
    bool isActive;
    double loan;
    static double total_balances;
    static double total_loans;
    short risk_counter;

    double get_total_balances() const;
    double get_total_loans() const;
    short get_risk_counter() const;

    friend class Admin;
    friend class FileManager;
    friend class Parser;
    friend class FilesHelper;

    static const int MAX_TRANSACTIONS = 100;
    Transaction transactions[MAX_TRANSACTIONS];
    static int transactionCount;

    bool autoTransferDone;
    void turn_on();
    bool isTransferTimeAllowed();
    std::string getAccountProgress();


    Client(int id, std::string name, std::string password, double balance,
            bool status, double loan, short risk_counter);

            /// THIS ONLY FOR CREATING OBJECTS WHICH COME FROM FILES

public:
    Client(std::string name, std::string password, double balance); /// Normal Condition
    Client(std::string name, std::string password);

    void set_balance(double balance);
    double get_balance();

    void setActive(bool status);
    bool getActive();

    void deposit(double amount);
    void withdraw(double amount);
    void transfer_to(double amount, Client& recipient);
    void request_loan();
    void auto_transfer_at(int hour,int minute,int second,double amount, Client& recipient);

    bool verify_password(std::string oldPassword);
    void change_password(std::string oldPassword ,std::string newPassword);

    void check_balance();
    void check_account_progress();
    void show_transaction_history();

    double get_loan() const;

    void display();
};



extern std::vector<Client> allClients;
