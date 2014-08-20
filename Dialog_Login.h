#if !defined(AFX_DIALOG_LOGIN_H__91519A61_8B90_4D0E_8936_F48824DF0CE9__INCLUDED_)
#define AFX_DIALOG_LOGIN_H__91519A61_8B90_4D0E_8936_F48824DF0CE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dialog_Login dialog

class Dialog_Login : public CDialog
{
// Construction
public:
	Dialog_Login(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dialog_Login)
	enum { IDD = IDD_DIALOG_LOGIN };
	CString	m_passwd;
	CString	m_user;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dialog_Login)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dialog_Login)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_LOGIN_H__91519A61_8B90_4D0E_8936_F48824DF0CE9__INCLUDED_)
