#include "Admin.h"
#include <iostream>

void Admin::turn_on() { ; }

Admin::Admin(string name, string password, double salary)
    : Employee(name, password, salary)
{
    ;
}

void Admin::display()
{
    cout << " \t\t  */\t\tAdmin Information\t\t\\* " << endl << endl;
    Employee::display();
}
