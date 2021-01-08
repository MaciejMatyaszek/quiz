#pragma once
#include<iostream>
#include <stdlib.h>
#include <mysql.h>

#include <string>
#include <algorithm>
#include <list>
#include <string>
#include "User.cpp"

#pragma once
class DatabaseRepository
{
private:
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;

public:
	DatabaseRepository();
	~DatabaseRepository();
	std::list<User> getAllEmployees(MYSQL* conn, string login, string password);
	//std::list<Employee> DatabaseRepository::getAllEmployeesBySort(MYSQL* conn, std::string sort);
	//int getLastRecordFromEmployees(MYSQL* conn);
	//void saveEmployee(Employee emp, MYSQL* conn);
	//std::list<Role> getAllRoles(MYSQL* conn);
	//int getLastRecordFromRoles(MYSQL* conn);
	//void saveRole(Role newRole, MYSQL* conn);
	//int DatabaseRepository::averageSaralry(MYSQL* conn);
	//int DatabaseRepository::countEmployee(MYSQL* conn, std::string sort);
	//void DatabaseRepository::removeUser(MYSQL* conn, int userId);
	//void DatabaseRepository::updateEmployee(const int& id, Employee* emp, MYSQL* conn);
	//time_t DatabaseRepository::String2time_t(const std::string& strDateTime);
	MYSQL* getConn() {
		return this->conn;
	}
};

