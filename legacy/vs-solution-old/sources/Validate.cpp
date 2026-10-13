#include "Validate.h"

bool Validate::validate_name(string name)
{
    bool flag = true;
    if (!(name.length() >= 5 && name.length() <= 20))
    {
        return false;
    }
    else
    {
        for (short i = 0; i < name.length(); i++)
        {
            if (!((name[i] >= 'A' && name[i] <= 'Z') ||
                (name[i] >= 'a' && name[i] <= 'z')))
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
}

bool Validate::validate_password(string password)
{
    bool find_digit = 0;
    bool find_symbol = 0;
    bool find_capital = 0;

    if (!(password.length() >= 8 && password.length() <= 20))
    {
        return false;
    }
    else
    {
        for (short i = 0; i < password.length(); i++)
        {
            if (password[i] >= 'A' && password[i] <= 'Z')
                find_capital = 1;
            else if (password[i] >= '0' && password[i] <= '9')
                find_digit = 1;
            else if (!(password[i] >= 'a' && password[i] <= 'z'))
                find_symbol = 1;
        }
        return find_capital && find_digit && find_symbol;
    }
}
