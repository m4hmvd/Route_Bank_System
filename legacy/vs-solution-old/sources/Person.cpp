#include "Person.h"
#include <iostream>

int Person::counter = 2400000;

Person::Person(string name, string password)
{
    this->name = name;
    this->password = password;
    this->id = counter++;
}

void Person::set_name(string name)
{
    if (Validate::validate_name(name))
        this->name = name;
    else
        cout << "Invalid name, it should be only 5 to 20 alphabetic characters only" << endl;
}

string Person::get_name()
{
    return this->name;
}

int Person::get_id()
{
    return this->id;
}

void Person::set_password(string password)
{
    if (Validate::validate_password(password))
        this->password = password;
    else
        cout << "Invalid password, it should be from 8 to 20 characters..." << endl;
}

string Person::get_password()
{
    return this->password;
}

void Person::display()
{
    cout << "Name: " << name << "\nID: " << id
        << "\nPassword: " << password << "\n";
}
