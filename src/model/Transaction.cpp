#include "Transaction.h"

using namespace std;

Transaction::Transaction()
{
    type = "";
    amount = 0;
    time = TimeOfDay();
}

Transaction::Transaction(string t, double a)
{
    type = t;
    amount = a;
    time = TimeOfDay();
}

string Transaction::get_type()
{
    return type;
}

double Transaction::get_amount()
{
    return amount;
}

TimeOfDay Transaction::get_time()
{
    return time;
}
