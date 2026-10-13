#include"Parser.h"
#include<sstream>
#include<string>

using namespace std;

vector<string>Parser::split(string line)
{
    vector<string>result;
    string temp;
    stringstream dataline(line);
    while (getline(dataline, temp, '&'))
        {
			result.push_back(temp);
		}
    return result;
}
Client Parser::parse_to_client(string line)
{
    vector<string>data = split(line);
    int id = stoi(data[0]);
    string name = data[1];
    string password = data[2];
    double balance = stod(data[3]);
    bool status = stoi(data[4]);
    double loan = stod(data[5]);
    short risk_counter = stoi(data[6]);

    Client c(id,name,password,balance,status,loan,risk_counter);
    return c;
}
Employee Parser::parse_to_Employee(string line)
{
    vector<string>data = split(line);
    int id = stoi(data[0]);
    string name = data[1];
    string password = data[2];
    double salary = stod(data[3]);
    Employee e(id,name, password, salary);
    return e;
}
Admin Parser::parse_to_Admin(string line)
{
    vector<string>data = split(line);
    int id = stoi(data[0]);
    string name = data[1];
    string password = data[2];
    double salary = stod(data[3]);
    Admin a(id, name, password, salary);
    return a;
}
