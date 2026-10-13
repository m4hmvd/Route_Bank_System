#include "FilesHelper.h"
#include <fstream>
#include "DataPaths.h"

using namespace std;


int FilesHelper::getNextClientId()
{
    int id;
    ifstream in(data::path("Clients_Last_ID.txt"));

    if (!in)
    {
        id = 2400000;
    }
    else
    {
        in >> id;
        id++;
    }
    in.close();

    ofstream out(data::path("Clients_Last_ID.txt"), ios::trunc);
    out << id;
    out.close();

    return id;
}





int FilesHelper::getNextEmployeeId()
{
    int id;
    ifstream in(data::path("Employees_Last_ID.txt"));

    if (!in)
    {
        id = 2100000;
    }
    else
    {
        in >> id;
        id++;
    }
    in.close();

    ofstream out(data::path("Employees_Last_ID.txt"), ios::trunc);
    out << id;
    out.close();

    return id;
}

int FilesHelper::getNextAdminId()
{
    int id;
    ifstream in(data::path("Admins_Last_ID.txt"));

    if (!in)
    {
        id = 1900000;
    }
    else
    {
        in >> id;
        id++;
    }
    in.close();

    ofstream out(data::path("Admins_Last_ID.txt"), ios::trunc);
    out << id;
    out.close();

    return id;
}


void FilesHelper::getClients()
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
void FilesHelper::getEmployees()
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
void FilesHelper::getAdmins()
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


void FilesHelper::saveClient(Client obj)
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
void FilesHelper::saveEmployee(Employee obj)
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
void FilesHelper::saveAdmin(Admin obj)
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

void FilesHelper::clearFile(string filename, string lastIDfile)
{
    ofstream file1(filename, ios::trunc);
    file1.close();

    ofstream file2(lastIDfile, ios::trunc);
    file2.close();

}



void FilesHelper::saveAllClients()
{
  ofstream file(data::path("Clients.txt"), ios::trunc);
  if (file.is_open())
    {
    for (size_t i = 0; i < allClients.size(); i++)
    {
      Client &obj = allClients[i];
      string status = to_string(obj.getActive());
      file << obj.get_id() << "&" << obj.get_name() << "&" << obj.get_password()
           << "&" << obj.get_balance() << "&" << status << "&" << obj.get_loan()
           << "&" << obj.get_risk_counter() << endl;
    }
    file.close();
  }
}



void FilesHelper::saveAllEmployees()
{
  ofstream file(data::path("Employees.txt"), ios::trunc);
  if (file.is_open())
    {
    for (size_t i = 0; i < allEmployees.size(); i++)
    {
      Employee &obj = allEmployees[i];
      file << obj.get_id() << "&" << obj.get_name() << "&" << obj.get_password()
           << "&" << obj.get_salary() << endl;
    }
    file.close();
  }
}

void FilesHelper::saveAllAdmins()
{
  ofstream file(data::path("Admins.txt"), ios::trunc);
  if (file.is_open())
    {
    for (size_t i = 0; i < allAdmins.size(); i++)
    {
      Admin &obj = allAdmins[i];
      file << obj.get_id() << "&" << obj.get_name() << "&" << obj.get_password()
           << "&" << obj.get_salary() << endl;
    }
    file.close();
  }
}

