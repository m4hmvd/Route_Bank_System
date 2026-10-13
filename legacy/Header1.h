//parser .cpp
#pragma once
#include"parser.h"
#include<sstream>

	 vector<string>Parser::split(string line) {
		vector<string>result;
		string temp;
		stringstream ss(line);
		while (getline(ss, temp, ',')) {
			result.push_back(temp);
		}
		return result;
	}
	 Client Parser::parsetoclient(string line) {
		vector<string>data = split(line);
		string name = data[0];
		string pass = data[1];
		double balance = stod(data[2]);
		Client c(name, pass, balance);
		return c;
	}
	 Employee Parser::parsetoEmployee(string line) {
		vector<string>data = split(line);
		string name = data[0];
		string pass = data[1];
		double balance = stod(data[2]);
		Employee e(name, pass, salary);
		return e;
	}
	 Admin Parser::parsetoAdmin(string line) {
		vector<string>data = split(line);
		string name = data[0];
		string pass = data[1];
		double balance = stod(data[2]);
		Admin a(name, pass, salary);
		return a;
	}

}
