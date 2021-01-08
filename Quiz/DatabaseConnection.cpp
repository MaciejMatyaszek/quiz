//#include <stdlib.h>
//#include <iostream>
//
///*
//  Include directly the different
//  headers from cppconn/ and mysql_driver.h + mysql_util.h
//  (and mysql_connection.h). This will reduce your build time!
//*/
//#include "mysql.h"
//
//#include <jdbc/cppconn/driver.h>
//#include <jdbc/cppconn/exception.h>
//#include <jdbc/cppconn/resultset.h>
//#include <jdbc/cppconn/statement.h>
//#include "DatabaseConnection.h"
//using namespace std;
//
//class Database {
//
//public:
//        sql::Driver* driver;
//        sql::Connection* con;
//       
//
//    void connectToDB() {
//        try {
//            /*sql::Driver* driver;
//            sql::Connection* con;
//            sql::Statement* stmt;
//            sql::ResultSet* res;*/
//
//            /* Create a connection */
//            driver = get_driver_instance();
//            con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
//            /* Connect to the MySQL test database */
//            con->setSchema("quiz");
//
//
//
//
//        }
//        catch (sql::SQLException& e) {
//            
//        }
//
//    }
//    auto executeQuery() {
//        sql::Statement* stmt;
//        sql::ResultSet* res;
//
//        stmt = con->createStatement();
//        res = stmt->executeQuery("SELECT * From User"); // replace with your statement
//        return res;
//    }
//    auto executeQueryLogin(string query) {
//        sql::Statement* stmt;
//        sql::ResultSet* res;
//
//        stmt = con->createStatement();
//        res = stmt->executeQuery(query); // replace with your statement
//        return res;
//    }
//    void executeInsertQuery(string query) {
//        sql::Statement* stmt;
//        sql::ResultSet* res;
//
//        stmt = con->createStatement();
//        stmt->execute(query); // replace with your statement
//        
//    }
//    void endConnection() {
//        //delete res;
//        //delete stmt;
//        //delete con;
//    }
//};



#ifndef _DB
#define _DB
#include "jdbc/mysql_connection.h"
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
using namespace sql;
using namespace std;

#define DB_NAME "quiz"
#define DB_HOST "*********"
#define DB_PORT 3306
#define DB_USER "root"
#define DB_PASS "root"

class Database {
private:
    static Database* instance;
    Driver* driver;
    ConnectOptionsMap connection_properties;
    Database();
public:
    static Database& getInstance();

    Connection* getConnection();

    virtual ~Database() {}
};

Database* Database::instance = 0;

Database::Database() : driver(get_driver_instance()) {
    connection_properties["hostName"] = DB_HOST;
    connection_properties["port"] = DB_PORT;
    connection_properties["userName"] = DB_USER;
    connection_properties["password"] = DB_PASS;
    connection_properties["OPT_RECONNECT"] = true;
}

Database& Database::getInstance() {
    if (Database::instance == 0) {
        instance = new Database();
    }
    return *instance;
}

Connection* Database::getConnection() {
    try {
        Connection* con = driver->connect(connection_properties);
        con->setSchema(DB_NAME);
        return con;
    }
    catch (SQLException& e) {
        cout << e.what();
    }
    return 0;
}

#endif // !_DB0