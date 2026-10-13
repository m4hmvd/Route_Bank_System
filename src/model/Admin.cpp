#include "Admin.h"
#include "FilesHelper.h"
#include <iostream>
#include<iomanip>

using namespace std;


int Admin::admin_counter = 1900000;


void Admin::turn_on() { ; }

Admin::Admin(string name, string password, double salary)
    : Employee(name, password, salary)
{
    this->id = FilesHelper::getNextAdminId();
}

Admin::Admin(int id, string name, string password, double salary)
       : Employee(id, name, password, salary){;}
void Admin:: increase_salary(Employee& e,double amount)
{
    e.set_salary(e.get_salary() + amount);
    FilesHelper::saveAllEmployees();
}

void Admin:: decrease_salary(Employee& e, double amount)
{
    e.set_salary(e.get_salary() - amount);
    FilesHelper::saveAllEmployees();
}

void Admin::see_system_statistics_till(Client* c, Employee* e)
{
    cout << "Number of Clients: " << count_clients_till(c) << endl;
    cout << "Number of Employees: " << e->get_id() - 2099999 << endl;
    cout << "Total Balances: " << fixed << setprecision(6) << c->get_total_balances() << endl;
    cout << "Total Loans: " << c->get_total_loans() << endl;
    cout << "Total Salaries: " << e->total_salaries << endl;
}


void Admin:: risk_assessment(Client& c)
{
    if (c.get_risk_counter() >= 3)
    {
        deactivate_client(c);
        cout << "Client deactivated due to high risk" << endl;
    }
    else
    {
        cout << "there isn't a risk from this client" << endl;
    }
}

void Admin::display()
{
    cout << " \t\t  */\t\tAdmin Information\t\t\\* " << endl << endl;
    Person::display();
    cout << "Salary: " << this->salary << endl;
}



///   ============ OTHERS ===============

void Admin::addEmployee(Employee& e)
{
    allEmployees.push_back(e);
    FilesHelper::saveAllEmployees();
}

Employee* Admin::searchEmployee(int id)
{
    for (size_t i = 0; i < allEmployees.size(); i++)
    {
        if (allEmployees[i].get_id() == id)
        {
            return &allEmployees[i];
        }
    }
    return nullptr;
}


void Admin::listEmployee()
{
    if (allEmployees.empty())
    {
        cout << "No Employees found" << endl;
    }
    else
    {
        cout << " \t\t  */		 Employees List		\\* " << endl << endl;
        for (size_t i = 0; i < allEmployees.size(); i++)
        {
            cout << "Employee no. " << i+1 << endl;
            allEmployees[i].display();
            cout << endl;
        }
    }
}


