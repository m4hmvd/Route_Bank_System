#pragma once
#include "Person.h"
#include "Client.h"

extern std::vector<Client> allClients;
extern std::vector<Employee> allEmployees;




class FilesHelper;


class Employee :
    public Person
{
protected:
    double salary;
    static int employee_counter;
    static double total_salaries;
    void turn_on();


    Employee(int id, std::string name, std::string password, double salary);

            /// THIS ONLY FOR CREATING OBJECTS WHICH COME FROM FILES


    friend class Parser;

public:
    Employee(std::string name, std::string password, double salary);

    void set_salary(double salary);
    double get_salary();

    void activate_client(Client& c);
    void deactivate_client(Client& c);
    void update_client_password(Client& recipient, std::string newPassword);
    int	count_clients_till(Client* c);
    void view_client_balance(Client* c);

    void display();


    void addClient(Client& client);
    Client* searchClient(int id);
    void listClient();


    friend class FilesHelper;
};
