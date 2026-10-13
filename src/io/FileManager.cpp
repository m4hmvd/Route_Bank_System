#include "FileManager.h"
#include "DataPaths.h"

using namespace std;

vector<Client> allClients;
vector<Employee> allEmployees;
vector<Admin> allAdmins;


/// ============== TURNING FILES INTO VECTORS OF LINES ==============

vector<string> FileManager::getData_intoLines(string textFile)
{
    ifstream file(textFile);
    string line;
    vector<string>lines;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    return lines;
}


/// ================= ADD =================

void FileManager::addClient(Client obj)
{
    string status = to_string(obj.getActive());
    ofstream file(data::path("Clients.txt"), ios::app);

    if (file.is_open())
    {

    file << obj.get_id() << "&"
        << obj.get_name() << "&"
        << obj.get_password() << "&"
        << obj.get_balance() << "&" << status << "&" << obj.get_loan() << "&"
        << obj.get_risk_counter() << endl;

    file.close();
    }
}

void FileManager::addEmployee(Employee obj)
{
    ofstream file(data::path("Employees.txt"), ios::app);

    if (file.is_open())
    {

    file << obj.get_id() << "&"
        << obj.get_name() << "&"
        << obj.get_password() << "&"
        << obj.get_salary() << endl;

    file.close();
    }
}

void FileManager::addAdmin(Admin obj)
{
    ofstream file(data::path("Admins.txt"), ios::app);

    if (file.is_open())
    {

    file << obj.get_id() << "&"
        << obj.get_name() << "&"
        << obj.get_password() << "&"
        << obj.get_salary() << endl;

    file.close();
    }
}

/// ================= GET ALL =================

void FileManager::getAllClients()
{
    ifstream file(data::path("Clients.txt"));
    string line;

    if (file.is_open())
    {

    while (getline(file, line))
    {
        Client c = Parser::parse_to_client(line);
        allClients.push_back(c);

    }

    file.close();
    }
}

void FileManager::getAllEmployees()
{
    ifstream file(data::path("Employees.txt"));
    string line;

    if (file.is_open())
    {

    while (getline(file, line))
    {
        Employee e = Parser::parse_to_Employee(line);
        allEmployees.push_back(e);
    }

    file.close();
    }
}

void FileManager::getAllAdmins()
{
    ifstream file(data::path("Admins.txt"));
    string line;

    if (file.is_open())
    {

    while (getline(file, line))
    {
        Admin a = Parser::parse_to_Admin(line);
        allAdmins.push_back(a);
    }

    file.close();
    }
}

/// ================= REMOVE ALL =================

void FileManager::removeAllClients()
{
    ofstream file(data::path("Clients.txt"), ios::trunc);
    file.close();
}

void FileManager::removeAllEmployees()
{
    ofstream file(data::path("Employees.txt"), ios::trunc);
    file.close();
}

void FileManager::removeAllAdmins()
{
    ofstream file(data::path("Admins.txt"), ios::trunc);
    file.close();
}



