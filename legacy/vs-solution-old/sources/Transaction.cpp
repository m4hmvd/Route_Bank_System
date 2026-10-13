#include "Transaction.h"

Transaction::Transaction()
{
    type = "";
    amount = 0;
    time = Time();
}

Transaction::Transaction(string t, double a)
{
    type = t;
    amount = a;
    time = Time();
}

string Transaction::get_type()
{
    return type;
}

double Transaction::get_amount()
{
    return amount;
}

Time Transaction::get_time()
{
    return time;
}
