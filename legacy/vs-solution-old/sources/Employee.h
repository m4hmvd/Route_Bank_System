#pragma once
#include "Person.h"
#include "Client.h"
class Employee :
    public Person
{
protected:
    double salary;
    void turn_on();

public:
    Employee(string name, string password, double salary);

    void set_salary(double salary);
    double get_salary();

    void activate_client(Client& c);
    void deactivate_client(Client& c);

    void display();
};

