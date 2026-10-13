#pragma once
#include "Admin.h"
#include "FileManager.h"


class Client;
class Employee;
class Admin;


class FilesHelper
{
public:
    static int getNextClientId();
    static int getNextEmployeeId();
    static int getNextAdminId();

    static void saveClient(Client c);
    static void saveEmployee(Employee e);
    static void saveAdmin(Admin a);


    static void getClients();
    static void getEmployees();
    static void getAdmins();
    static void clearFile(std::string fileName, std::string lastIDfile);


    static void saveAllClients();
    static void saveAllEmployees();
    static void saveAllAdmins();



friend class Client;
friend class Employee;
friend class Admin;
};



