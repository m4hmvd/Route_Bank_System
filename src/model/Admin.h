#pragma once
#include "Employee.h"

extern std::vector<Client> allClients;
extern std::vector<Employee> allEmployees;
extern std::vector<Admin> allAdmins;



class Admin :
    public Employee
{
private:
    static int admin_counter;
    void turn_on();

    Admin(int id, std::string name, std::string password, double salary);

            /// THIS ONLY FOR CREATING OBJECTS WHICH COME FROM FILES
    friend class Parser;

public:
    Admin(std::string name, std::string password, double salary);
    void see_system_statistics_till(Client* c,Employee* e);
    void risk_assessment(Client& c);
    void increase_salary(Employee& e, double amount);
    void decrease_salary(Employee& e, double amount);
    void display();


    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void listEmployee();


};
