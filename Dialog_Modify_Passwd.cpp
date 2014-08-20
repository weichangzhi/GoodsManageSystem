// Dialog_Modify_Passwd.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "Dialog_Modify_Passwd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialog_Modify_Passwd dialog


Dialog_Modify_Passwd::Dialog_Modify_Passwd(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog_Modify_Passwd::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog_Modify_Passwd)
	m_passed1 = _T("");
	m_passwd2 = _T("");
	//}}AFX_DATA_INIT
}


void Dialog_Modify_Passwd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog_Modify_Passwd)
	DDX_Text(pDX, IDC_EDIT_PASSWD1, m_passed1);
	DDX_Text(pDX, IDC_EDIT_PASSWD2, m_passwd2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog_Modify_Passwd, CDialog)
	//{{AFX_MSG_MAP(Dialog_Modify_Passwd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialog_Modify_Passwd message handlers

BOOL Dialog_Modify_Passwd::PreTranslateMessage(MSG* pMsg) 
{
	switch(pMsg->wParam) 
		{  
		//case VK_RETURN: //�س�  
		//	return TRUE;  
		case VK_ESCAPE: //ESC  
			return TRUE;  
		}  
	
	return CDialog::PreTranslateMessage(pMsg);
}

void Dialog_Modify_Passwd::OnOK() 
{
	UpdateData();
	if(m_passed1.Compare(m_passwd2))
	{
		MessageBox("2�������벻һ�£�����������������","��ʾ",MB_OK);
		(CEdit*)GetDlgItem(IDC_EDIT_PASSWD2)->SetFocus();
		((CEdit*)GetDlgItem(IDC_EDIT_PASSWD2))->SetSel(0, -1);
		return;
	}
	CString sql;	
	sql.Format("update userinfo set passwd=\"%s\"  where username=\"%s\" ",m_passed1,"����Ա");
	if(!g_adoDataSet.ExecSql(sql))
	{
		MessageBox("�޸����ݿ�ʧ��","��ʾ",MB_OK);
		return ;
	}	// TODO: Add your command handler code here
		MessageBox("�޸�����ɹ�","��ʾ",MB_OK);
	CDialog::OnOK();
}
