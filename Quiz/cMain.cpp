#include "cMain.h"
#include "cCategorySelection.h"
#include "Register.h"
/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql.h"
#include <string>

#include "DatabaseRepository.h"
#include "User.cpp"

using namespace std;



wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
	EVT_BUTTON(10002, OnButtonClicked2)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Quizz App", wxPoint(70, 30), wxSize(400, 250), wxCAPTION | wxCLOSE_BOX)
{ 
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	m_btn1 = new wxButton(this, 10001, "Zaloguj", wxPoint(160, 150), wxSize(150, 50));
	m_btn2 = new wxButton(this, 10002, "Załóż konto", wxPoint(10, 150), wxSize(150, 50));
	m_login = new wxTextCtrl(this, wxID_ANY, "", wxPoint(50, 70), wxSize(300, 30));
	m_password = new wxTextCtrl(this, wxID_ANY, "", wxPoint(50, 110), wxSize(300, 30));
	m_staticTekst = new wxStaticText(this, wxID_ANY, "Login", wxPoint(125, 10), wxSize(150, 50), wxALIGN_CENTRE_HORIZONTAL);
	m_staticTekst->SetFont(font);
	newFrame = new cCategorySelection();
	registerFrame = new cRegister();
	

	//db.endConnection();
	   
	
}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{


	string login = m_login->GetValue().ToStdString();
	string password = m_password->GetValue().ToStdString();
	DatabaseRepository db;

	std::list<User> list = db.getAllEmployees(db.getConn(), login, password);
	int size = list.size();
	if (size > 0)
	{
		newFrame->Show(true);
		this->Destroy();

		evt.Skip();
	}
}

void cMain::OnButtonClicked2(wxCommandEvent& evt)
{

	
		registerFrame->Show(true);
		this->Destroy();
	
	evt.Skip();
}
