#include <iostream>
using namespace std;
#pragma once

class User {
private:
    // Private attribute
    int user_id;
    string login;
    string password;

   
public:

    User() {

    }
    User(int id, string login, string password) {     // Constructor
        id = id;
        login = login;
        password = password;
    }

    // Setter
    void setLogin(string login) {
        login = login;
    }
    // Getter
    string getLogin() {
        return login;
    }

    void setPassword(string password) {
        password = password;
    }

    string getPassword() {
        return password;
    }

    void setId(int user_id) {
        user_id = user_id;
    }

    int getId() {
        return user_id;
    }
};
