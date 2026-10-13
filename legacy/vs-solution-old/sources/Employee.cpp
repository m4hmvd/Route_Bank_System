#include "Employee.h"
#include <iostream>

void Employee::turn_on() { ; }

Employee::Employee(string name, string password, double salary)
    : Person(name, password)
{
    this->salary = salary;
}

void Employee::set_salary(double salary)
{
    if (salary >= 5000)
    {
        this->salary = salary;
    }
    else
    {
        cout << "Sorry! it should be greater than or equal 5000" << endl;
    }
}

double Employee::get_salary()
{
    return this->salary;
}

void Employee::activate_client(Client& c)
{
    c.setActive(true);
    cout << "Client account activated successfully" << endl;
}

void Employee::deactivate_client(Client& c)
{
    c.setActive(false);
    cout << "Client account deactivated successfully" << endl;
}

void Employee::display()
{
    cout << " \t\t  */\t\tEmployee Information\t\t\\* " << endl << endl;
    Person::display();
    cout << "Salary: " << this->salary << endl;
}
