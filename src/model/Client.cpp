#include "Client.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include "FilesHelper.h"

using namespace std;

int Client::client_counter = 2400000;
double Client::total_balances = 0;
double Client::total_loans = 0;
int Client::transactionCount = 0;

void Client::turn_on() { ; }

Client::Client(string name, string password, double balance)
    : Person(name, password)
{
    this->id = FilesHelper::getNextClientId();
    autoTransferDone = false;
    this->balance = balance;
    this->isActive = true;
    this->loan = 0;
    transactionCount = 0;
    this-> total_balances += this->balance;
    this-> total_loans += this->loan;
    this->risk_counter = 0;
}



Client::Client(string name, string password)
    : Person(name, password)
{
    this->id = FilesHelper::getNextClientId();
    autoTransferDone = false;
    this->balance = 0;
    this->isActive = false;
    this->loan = 0;
    transactionCount = 0;
    this-> total_balances += this->balance;
    this-> total_loans += this->loan;
    this->risk_counter = 0;
}



Client::Client(int id, string name, string password, double balance,
            bool status, double loan, short risk_counter) : Person(name, password)
{
    this->id= id;
    this->balance = balance;
    this->isActive = status;
    this->loan = loan;
    this->risk_counter = risk_counter;
    this->total_balances += this->balance;
    this->total_loans += this->loan;
}

/* ================= ACCOUNT STATUS ================= */

string Client::getAccountProgress()
{
    if (balance < 5000)
        return "Low";
    else if (balance < 20000)
        return "Normal";
    else if (balance < 50000)
        return "High";
    else if (balance < 100000)
        return "Super";
    else
        return "VIP";
}

/* ================= TIME CHECK ================= */

bool Client::isTransferTimeAllowed()
{
    TimeOfDay now;
    TimeOfDay start(12, 0, 0);
    TimeOfDay end(23, 59, 59);

    return now.seconds_from(start) >= 0 &&
        end.seconds_from(now) >= 0;
}

/* ================= BASIC SETTERS & GETTERS ================= */

void Client::set_balance(double balance)
{
    if (balance >= 1500)
    {
        this-> total_balances -= this->balance;
        this->balance = balance;
        this-> total_balances += this->balance;
        FilesHelper::saveAllClients();
    }
    else
        cout << "Balance must be >= 1500" << endl;
}

double Client::get_balance()
{
    return balance;
}

void Client::setActive(bool status)
{
    isActive = status;
}

bool Client::getActive()
{
    return isActive;
}

double Client:: get_total_balances() const
{
    return this->total_balances;
}
double Client:: get_total_loans() const
{
    return this->total_loans;
}
short Client:: get_risk_counter() const
{
    return this->risk_counter;
}


double Client:: get_loan() const
{
    return this->loan;
}
/* ================= AUTO TRANSACTIONS ================= */

void Client::auto_transfer_at(
    int hour,
    int minute,
    int second,
    double amount,
    Client& recipient
)
{
    if (!isActive || !recipient.getActive())
        return;

    TimeOfDay now;
    TimeOfDay target(hour, minute, second);

    // Allowed window: 12:00 -> 23:59:59
    TimeOfDay start(12, 0, 0);
    TimeOfDay end(23, 59, 59);

    if (now.seconds_from(start) < 0 || end.seconds_from(now) < 0)
    {
        cout << "Transfers allowed only between 12:00 and 23:59:59" << endl;
        return;
        // this code executed only if the current time is between 00:00:00 and 11:59:59
    }


    if (abs(now.seconds_from(target)) <= 1 && !autoTransferDone)
    {
        if (balance >= amount)
        {
            balance -= amount;
            recipient.deposit(amount);
            autoTransferDone = true;

            cout << "Auto transfer executed at "
                << hour << ":"
                << setw(2) << setfill('0') << minute << ":"
                << setw(2) << setfill('0') << second << endl;



                if (transactionCount < MAX_TRANSACTIONS)
            transactions[transactionCount++] =
            Transaction("Scheduled Transfer", amount);
        }
        else
        {
            cout << "Auto transfer failed: insufficient balance\n";

        }
    }
}

/* ================= TRANSACTIONS ================= */

void Client::deposit(double amount)
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }

    balance += amount;
    this-> total_balances += amount;
    cout << "Successfully Added :)" << endl;
    if(amount >= 500000)
        risk_counter++;

    if (transactionCount < MAX_TRANSACTIONS)
        transactions[transactionCount++] =
        Transaction("Deposit", amount);

        FilesHelper::saveAllClients();
}

void Client::withdraw(double amount)
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }

    if (balance >= amount)
    {
        balance -= amount;
        this-> total_balances -= amount;
        cout << "Successfully Withdrawn :)" << endl;

        if (transactionCount < MAX_TRANSACTIONS)
            transactions[transactionCount++] =
            Transaction("Withdraw", amount);
            FilesHelper::saveAllClients();
    }
    else
        cout << "Insufficient balance" << endl;
}

void Client::transfer_to(double amount, Client& recipient)
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }

    if (!isTransferTimeAllowed())
    {
        cout << "Transfers allowed only between 12:00 and 23:59:59" << endl;
        return;
    }

    if (balance >= amount && recipient.getActive())
    {
        balance -= amount;
        recipient.deposit(amount);

        if (transactionCount < MAX_TRANSACTIONS)
            transactions[transactionCount++] =
            Transaction("Transfer", amount);
            FilesHelper::saveAllClients();

        cout << "Transfer successful" << endl;
    }
    else
        cout << "Transfer failed" << endl;
}


void Client:: request_loan()
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }
    this->loan += 10000;
    this->balance += 10000;
    this-> total_balances += 10000;
    this-> total_loans += 10000;
    cout << " 10000 Loan added to " << this->id << " successfully " << endl;
    if (transactionCount < MAX_TRANSACTIONS)
            transactions[transactionCount++] =
            Transaction("Loan", 10000);

    FilesHelper::saveAllClients();
}

/* ================= DISPLAY ================= */

void Client::check_balance()
{
    cout << "Balance: " << fixed << setprecision(6) <<  balance << endl;
}

void Client::check_account_progress()
{
    if (getAccountProgress() == "Low")
    {
        cout << "Low" << endl << "There is more to do ..." << endl;
    }
    else if (getAccountProgress() == "Normal")
    {
        cout << "Normal" << endl << "We wait more ..." << endl;
    }
    else if (getAccountProgress() == "High")
    {
        cout << "High" << endl << "Wanna to be Super ???" << endl;
    }
    else if (getAccountProgress() == "Super")
    {
        cout << "Super" << endl << "Only 1 step ..." << endl;
    }
    else
    {
        cout << "VIP" << endl << "Superior <3 <3 <3" << endl;
    }

}

void Client::show_transaction_history()
{
    if (transactionCount == 0)
    {
        cout << "NOTHING !!" << endl;
        return;
    }
    else
    {
    cout << "\n--- Transaction History ---" << endl;

    for (int i = 0; i < transactionCount; i++)
    {
        TimeOfDay t = transactions[i].get_time();

        cout << transactions[i].get_type() << ": "
            << transactions[i].get_amount()
            << " at "
            << t.get_hours() << ":"
            << t.get_minutes() << ":"
            << t.get_seconds()
            << endl;
    }
    }
}


void Client::display()
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }
    cout << " \t\t  */		Client Information		\\* " << endl << endl;
    Person::display();

    cout << "Balance: " << balance << endl;
    cout << "Status: " << getAccountProgress() << endl;
    cout << "Loan: " << this->loan << endl;
}


/* ================= UPDATES ================= */
bool Client:: verify_password(string oldPassword)
{
    return (oldPassword == this->password);

}

void Client:: change_password(string oldPassword ,string newPassword)
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }
    if (!verify_password(oldPassword))
    {
        cout << "Invalid Old Password" << endl;
        return;
    }

	if (Validate::validate_password(newPassword))
    {
        this->set_password(newPassword);
		cout << "Password changed successfully" << endl;
    }
	else
    {
		cout << "Invalid new password" << endl;
	}
}
