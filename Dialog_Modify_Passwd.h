#if !defined(AFX_DIALOG_MODIFY_PASSWD_H__198AC2EE_5C75_49A0_9C3C_8679631F68BC__INCLUDED_)
#define AFX_DIALOG_MODIFY_PASSWD_H__198AC2EE_5C75_49A0_9C3C_8679631F68BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Modify_Passwd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dialog_Modify_Passwd dialog

class Dialog_Modify_Passwd : public CDialog
{
// Construction
public:
	Dialog_Modify_Passwd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dialog_Modify_Passwd)
	enum { IDD = IDD_DIALOG_MODIFY_PASSWD };
	CString	m_passed1;
	CString	m_passwd2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dialog_Modify_Passwd)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dialog_Modify_Passwd)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_MODIFY_PASSWD_H__198AC2EE_5C75_49A0_9C3C_8679631F68BC__INCLUDED_)
