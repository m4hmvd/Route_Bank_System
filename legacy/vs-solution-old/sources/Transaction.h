#pragma once
#include <string>
#include "Time.h"

using namespace std;
class Transaction
{
private:
    string type;     // Deposit / Withdraw / Transfer
    double amount;
    Time time;

public:
    Transaction();
    Transaction(string t, double a);

    string get_type();
    double get_amount();
    Time get_time();
};

