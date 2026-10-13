#pragma once
#include <string>
#include "TimeOfDay.h"

class Transaction
{
private:
    std::string type;     // Deposit / Withdraw / Transfer
    double amount;
    TimeOfDay time;

public:
    Transaction();
    Transaction(std::string t, double a);

    std::string get_type();
    double get_amount();
    TimeOfDay get_time();
};
