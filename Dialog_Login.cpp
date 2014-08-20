// Dialog_Login.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "Dialog_Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialog_Login dialog


Dialog_Login::Dialog_Login(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog_Login::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog_Login)
	m_passwd = _T("");
	m_user = _T("");
	//}}AFX_DATA_INIT
}


void Dialog_Login::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog_Login)
	DDX_Text(pDX, IDC_EDIT_PASSWD, m_passwd);
	DDX_Text(pDX, IDC_EDIT_USER, m_user);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog_Login, CDialog)
	//{{AFX_MSG_MAP(Dialog_Login)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialog_Login message handlers

BOOL Dialog_Login::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYDOWN) 
	{  
		switch(pMsg->wParam) 
		{  
		//case VK_RETURN: //回车  
		//	return TRUE;  
		case VK_ESCAPE: //ESC  
			return TRUE;  
		}  
	}	
	
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL Dialog_Login::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_user = "管理员";
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Dialog_Login::OnOK() 
{
	UpdateData();
	CString csSql;
	csSql.Format("select passwd from userinfo where username=\"%s\" ",m_user);
	if (!g_adoDataSet.Open(csSql,CADODataset::openQuery))
		return ;
	
	DWORD dwCnt	 = g_adoDataSet.GetRecordCount();	
	if (dwCnt<=0)
		return ;
	int index=0;
	CString strpasswd;
	while (!g_adoDataSet.IsEof())
	{
		if(!g_adoDataSet.GetCollect("passwd",strpasswd)) return;
		index++;
		g_adoDataSet.MoveNext();
	}
	if(m_passwd.Compare(strpasswd)!=0)
	{
		MessageBox("密码错误，请重新输入","提示",MB_OK);
		(CEdit*)GetDlgItem(IDC_EDIT_PASSWD)->SetFocus();
		((CEdit*)GetDlgItem(IDC_EDIT_PASSWD))->SetSel(0, -1);
		return;
	}
	else	
		CDialog::OnOK();	
}
