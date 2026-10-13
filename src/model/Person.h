#pragma once
#include <string>
#include "Validate.h"
class Person
{
protected:
    int id;
    std::string name, password;
    virtual void turn_on() = 0;

public:
    Person(std::string name, std::string password);

    void set_name(std::string name);
    std::string get_name();
    int get_id();

    void set_password(std::string password);
    std::string get_password();

    void display();
};
