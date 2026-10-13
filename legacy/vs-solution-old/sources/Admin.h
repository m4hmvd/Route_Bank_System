#pragma once
#include "Employee.h"
class Admin :
    public Employee
{
private:
    void turn_on();

public:
    Admin(string name, string password, double salary);
    void display();
};

