//cpp.files
#pragma once
#include<fstream>
#include<iostream>
#include"FilesHelper.h"
#include"parser.h"

  void FilesHelper::savelastid(string fileName,int id) {
		ofstream file(fileName);
		file >> id;
		file.close();
	}
 int getlastid(string fileName){
		ifstream file(fileName);
	int id;
	if (file.is_open())
		file >> id;
	else
		id = 24000;
	file.close();
	return id;
	}
  void FilesHelper::saveClient(Client c) {
	  ofstream file("Clients.txt", ios::app);
	  c.getid << file() << ","
		  << c.getName() << ","
		  << c.getbalance() << ","
		  << endl;
	  file.close();
	  savelast("lastclientid.txt", c.getid());
  }
  void FilesHelper::saveEmployee(Employee e,string fileName,string lastidfile) {
	  ofstream file(fileName, ios::app);
	  e.getid << file() << ","
		  << e.getName() << ","
		  << e.getbalance() << ","
		  << endl;
	  file.close();
	  savelast(lastidfile, e.getid());
  }
  void FilesHelper::getclients() {
	  ifstream file("Client.txt")
		  string line;
	  while (getline(file, line)) {
		  Client c= parser::parsertoClient(line);
		  cout << c.getid()" "
			  c.getName() << " "
			  c.getbalance() <<endl;
	  }
	  file.close();
	}
  void FilesHelper::getEmployees() {
	  ifstream file("Employees.txt")
		  string line;
	  while (getline(file, line)) {
		  Employee e= parser::parsertoClient(line);
		  cout << e.getid()" "
			  e.getName() << " "
			  e.getbalance() << endl ;
	  }
	  file.close();
  }
  void FilesHelper::getAdmin() {
	  ifstream file("Admin.txt")
		  string line;
	  while (getline(file, line)) {
		  Admin a = parser::parsertoAdmin(line);
		  cout << a.getid()" "
			  a.getName() << " "
			  a.getbalance() << endl;
	  }
	  file.close();
  }
  void FilesHelper::clearFile(string fileName, string lastidFile) {
	  ofstream file(fileName);
	  file.close();
	  savelast(lastidfile, 24000);
  }
