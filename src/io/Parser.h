#pragma once
#include<vector>
#include<string>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"


class Parser
{
public:
	static std::vector<std::string>split(std::string line);

	static Client parse_to_client(std::string line);

	static Employee parse_to_Employee(std::string line);

	static Admin parse_to_Admin(std::string line);

};
