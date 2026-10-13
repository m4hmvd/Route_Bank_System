#pragma once
#include <string>
#include "Validate.h"
using namespace std;
class Person
{
protected:
    int id;
    static int counter;
    string name, password;
    virtual void turn_on() = 0;

public:
    Person(string name, string password);

    void set_name(string name);
    string get_name();
    int get_id();

    void set_password(string password);
    string get_password();

    void display();
};

