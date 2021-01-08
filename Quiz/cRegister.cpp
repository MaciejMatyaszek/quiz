#include "Register.h"
#include "cCategorySelection.h"

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql.h"

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>


using namespace std;


wxBEGIN_EVENT_TABLE(cRegister, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

cRegister::cRegister() : wxFrame(nullptr, wxID_ANY, "Quizz App", wxPoint(70, 30), wxSize(400, 250), wxCAPTION | wxCLOSE_BOX)
{
	//string test;
	//Database db;
	//sql::ResultSet* res;
	//db.connectToDB();
	//res = db.executeQuery();
	//while (res->next()) {
	//	
	// test = res->getString(2); //This the 2nd column

	//}
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	m_btn1 = new wxButton(this, 10001, "Zarejstuj", wxPoint(160, 150), wxSize(150, 50));
	m_login = new wxTextCtrl(this, wxID_ANY, "", wxPoint(50, 70), wxSize(300, 30));
	m_password = new wxTextCtrl(this, wxID_ANY, "", wxPoint(50, 110), wxSize(300, 30));
	m_staticTekst = new wxStaticText(this, wxID_ANY, "Rejestracja", wxPoint(125, 10), wxSize(150, 50), wxALIGN_CENTRE_HORIZONTAL);
	m_staticTekst->SetFont(font);
	


	


}

cRegister::~cRegister()
{
}

void cRegister::OnButtonClicked(wxCommandEvent& evt)
{


	string login = m_login->GetValue().ToStdString();
	string password = m_password->GetValue().ToStdString();
	//Database db;
	//db.connectToDB();

	////sql::ResultSet* res;
	////string query = "Select * From User WHERE login='" + login + "' and password='" + password + "'";
	////res = db.executeQueryLogin(query);
	//int size = 0;
	////while (res->next()) {

	////	size++;

	////}


	//if (size > 0)
	//{
	//	
	//}
	//else {
	//	string query2 = "INSERT INTO User (login, password) VALUES('"+login+"','"+password+"')";
	//	
	//    db.executeInsertQuery(query2);
	//	
	//}

	
}
