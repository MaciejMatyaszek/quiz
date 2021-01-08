#pragma once
#pragma once
#include "wx/wx.h"
#include "cCategorySelection.h"

class cRegister : public wxFrame
{
public:
	cRegister();
	~cRegister();
public:
	wxButton* m_btn1 = nullptr;
	
	wxTextCtrl* m_login = nullptr;
	wxTextCtrl* m_password = nullptr;
	//wxTextCtrl* m_password2 = nullptr;
	wxStaticText* m_staticTekst = nullptr;
	cCategorySelection* newFrame = nullptr;
	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

