#pragma once
#include<string>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;
class FilesHelper {
public:
	static  void savelastid(string fileName, int id);
	static int getlastid(string fileName);
	static void saveClient(Client c);
	static void saveEmployee(Employee e, string fileName, string lastidfile);
	static void getclients();
	static void getEmployees();
	static void getAdmin();
	static void clearFile(string fileName, string lastidFile);
};