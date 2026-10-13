#include "Employee.h"
#include "FilesHelper.h"
#include <iostream>

using namespace std;

int Employee::employee_counter = 2100000;
double Employee::total_salaries = 0;

void Employee::turn_on() { ; }

Employee::Employee(string name, string password, double salary)
    : Person(name, password)
{
    this->id = FilesHelper::getNextEmployeeId();
    this->salary = salary;
    this->total_salaries+=this->salary;
}

Employee::Employee(int id, string name, string password, double salary)
            : Person(name, password)
{
    this->id= id;
    this->salary = salary;
    this->total_salaries += this->salary;
}

void Employee::set_salary(double salary)
{
    if (salary >= 5000)
    {
        this->total_salaries-=this->salary;
        this->salary = salary;
        this->total_salaries+=this->salary;
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
    FilesHelper::saveAllClients();
}

void Employee::deactivate_client(Client& c)
{
    c.setActive(false);
    cout << "Client account deactivated successfully" << endl;
    FilesHelper::saveAllClients();
}

void Employee:: update_client_password(Client& recipient, string newPassword)
 {
    if (!recipient.getActive())
        return;
    if (Validate::validate_password(newPassword))
        {
        recipient.set_password(newPassword);
        cout << "Client password updated successfully" << endl;
        FilesHelper::saveAllClients();
		}
		else
        {
        cout << "Invalid password" << endl;
		}

	}


int	Employee:: count_clients_till(Client* c)
{
	return c->get_id() - 2399999;
}

void Employee:: view_client_balance(Client* c)
{
    cout << c->get_id() << " 's Balance: " << c->get_balance() << endl;

}



void Employee::display()
{
    cout << " \t\t  */\t\tEmployee Information\t\t\\* " << endl << endl;
    Person::display();
    cout << "Salary: " << this->salary << endl;
}




/// =========== OTHERS ===================


void Employee::addClient(Client& client)
{
    allClients.push_back(client);
    FilesHelper::saveAllClients();
}

Client* Employee::searchClient(int id)
{
    for (size_t i = 0; i < allClients.size(); i++)
    {
        if (allClients[i].get_id() == id)
        {
            return &allClients[i];
        }
    }
    return nullptr;
}

void Employee::listClient()
{
    if (allClients.empty())
    {
        cout << "No clients found" << endl;
    }
    else
    {
        cout << " \t\t  */		Clients List		\\* " << endl << endl;
        for (size_t i = 0; i < allClients.size(); i++)
        {
            cout << "Client no. " << i+1 << endl;
            allClients[i].display();
            cout << endl;
        }
    }
}




