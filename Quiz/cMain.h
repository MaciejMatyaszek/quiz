#pragma once
#include "wx/wx.h"
#include "cCategorySelection.h"
#include "Register.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
public:
	wxButton* m_btn1 = nullptr;
	wxButton* m_btn2 = nullptr;
	wxTextCtrl* m_login = nullptr;
	wxTextCtrl* m_password = nullptr;
	wxStaticText* m_staticTekst = nullptr;
	cCategorySelection* newFrame = nullptr;
	cRegister* registerFrame = nullptr;
	void OnButtonClicked(wxCommandEvent& evt);
	void OnButtonClicked2(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

