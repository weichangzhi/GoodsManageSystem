// Preview.cpp : implementation file
//

#include "stdafx.h"
#include "GoodsManageSystem.h"
#include "Preview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreview dialog


CPreview::CPreview(CWnd* pParent /*=NULL*/)
	: CDialog(CPreview::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreview)
	m_strTime = _T("");
	m_strIndex = _T("");
	m_strSellName = _T("");
	m_strSellPhone = _T("");
	
	m_strCompanyName = _T("");
	m_strUserAddress = _T("");
	m_strUserName  = _T("");
	m_strUserPhone = _T("");
	
	m_dProCount = 0;
	m_pProInfo = NULL;
	
	m_strTotalPrice = _T("");
	m_strSellPrice = _T("");
	m_strTotalCount = _T("");
	m_strUpperMoney = _T("");
	//}}AFX_DATA_INIT
}


void CPreview::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreview)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreview, CDialog)
	//{{AFX_MSG_MAP(CPreview)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreview message handlers

HBRUSH CPreview::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	CBrush m_brush (RGB(255,255,255));
	
	CRect m_rect;
	GetClientRect(m_rect);
	
	pDC->FillRect(m_rect,&m_brush);
	// TODO: Return a different brush if the default is not desired
	return m_brush;
}

BOOL CPreview::OnInitDialog() 
{
	CDialog::OnInitDialog();
		return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPreview::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect m_rect;
	GetClientRect(m_rect);	
	CDC* pDC = GetDC();
	screenx = pDC->GetDeviceCaps(LOGPIXELSX);
	screeny = pDC->GetDeviceCaps(LOGPIXELSY);
	DrawReport(m_rect,GetDC(),false);
}

void CPreview::DrawReport(CRect rect, CDC *pDC, BOOL isprinted)
{
// 	int printx,printy;
// 	printx = pDC->GetDeviceCaps(LOGPIXELSX);
// 	printy = pDC->GetDeviceCaps(LOGPIXELSY);
// 	double ratex = (double)(printx)/screenx;
// 	double ratey = (double)(printy)/screeny;
// 	if(isprinted)
// 	{
// 		DOCINFO   doc;     
// 	    ZeroMemory(&doc,sizeof(doc));     
// 	    doc.cbSize = sizeof(doc);     
// 	    doc.lpszDocName = (LPCTSTR)"销售出货单";  
// 		pDC->StartDoc(&doc);	
// 		pDC->StartPage();
// 	}
// 	else
// 	{
// 		ratex=1,ratey=1;
// 	}
	int printx,printy;
	printx = pDC->GetDeviceCaps(LOGPIXELSX);
	printy = pDC->GetDeviceCaps(LOGPIXELSY);
	double ratex = (double)(printx)/screenx;
	double ratey = (double)(printy)/screeny;
	int phyx = pDC->GetDeviceCaps(PHYSICALWIDTH);
	int phyy = pDC->GetDeviceCaps(PHYSICALHEIGHT);
	ratex = (double)(phyx)/screenx * (screenx/600.0);
	ratey = (double)(phyy)/screeny * (screeny/600.0);
	char log[256] = {0};
	sprintf(log,"DrawReport \t%s,%d:rect [%dx%d, %dx%d],phy [%dx%d], screan[%dx%d],rate[%fx%f]",__FILE__,__LINE__,
			rect.left,rect.top,rect.right,rect.bottom,phyx,phyy,screenx,screeny,ratex,ratey);
	writelog(log);

	if(isprinted)
	{
		DOCINFO   doc;
	    ZeroMemory(&doc,sizeof(doc));
	    doc.cbSize = sizeof(doc);
	    doc.lpszDocName = (LPCTSTR)"销售出货单";
		pDC->StartDoc(&doc);	
		pDC->StartPage();
	}
	else
	{
		ratex=1,ratey=1;
	}
	CRect recttmp(rect);
	CFont font130,font150,font90,font80;
	CPen pen1,pen2,*pOldPen;
	font130.CreatePointFont(130,_T("宋体"),pDC);
	font90.CreatePointFont(90,_T("宋体"),pDC);
	font150.CreatePointFont(150,_T("宋体"),pDC);
	pDC->SelectObject(&font150);
	rect.DeflateRect(0,(int)(ratey*30),0,0);
	pDC->DrawText("销售出货单",rect,DT_CENTER);

	pDC->SelectObject(&font90);
	rect.DeflateRect((int)(50*ratex),(int)(ratey*30),0,0);
	pDC->DrawText("公司名称:",rect,DT_LEFT);
	rect.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText(m_strCompanyName,rect,DT_LEFT);
	rect.DeflateRect((int)(-ratex*50),(int)(ratey*15),0,0);
	pDC->DrawText("客户地址:",rect,DT_LEFT);
	rect.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText(m_strUserAddress,rect,DT_LEFT);
	rect.DeflateRect((int)(-ratex*50),(int)(ratey*15),0,0);
	pDC->DrawText("客户电话:",rect,DT_LEFT);
	rect.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText(m_strUserPhone,rect,DT_LEFT);
	rect.DeflateRect((int)(-ratex*50),(int)(ratey*15),0,0);
	pDC->DrawText("联系人:",rect,DT_LEFT);
	rect.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText(m_strUserName,rect,DT_LEFT);

	rect.DeflateRect((int)(ratex*320),(int)(-ratey*45),0,0);
	pDC->DrawText("出货单号:",rect,DT_LEFT);
	rect.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText(m_strIndex,rect,DT_LEFT);
	rect.DeflateRect((int)(-ratex*50),(int)(ratey*15),0,0);
	pDC->DrawText("出货日期:",rect,DT_LEFT);
	rect.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText(m_strTime,rect,DT_LEFT);
	rect.DeflateRect((int)(-ratex*50),(int)(ratey*15),0,0);
	pDC->DrawText("销售人员:",rect,DT_LEFT);
	rect.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText(m_strSellName,rect,DT_LEFT);
	rect.DeflateRect((int)(-ratex*50),(int)(ratey*15),0,0);
	pDC->DrawText("联系电话:",rect,DT_LEFT);
	rect.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText(m_strSellPhone,rect,DT_LEFT);
	//170,486,515,638
	pen1.CreatePen (PS_SOLID,2,RGB(0,0,0));
	pOldPen=pDC->SelectObject (&pen1);
	//画表格外边框
	pDC->Rectangle (recttmp.left+(int)(ratex*50),recttmp.top+(int)(ratey*120),recttmp.right-(int)(ratex*50),recttmp.top+(int)(ratey*380));

	//创建画笔
	pen2.CreatePen (PS_SOLID,1,RGB(0,0,0));
	pOldPen=pDC->SelectObject (&pen2);
	//画横线
	for(int i=1;i<=13;i++)
	{
		pDC->MoveTo (recttmp.left+(int)(ratex*50),(int)(ratey*120+i*ratey*20));
		pDC->LineTo (recttmp.right-(int)(ratex*50),(int)(ratey*120+i*ratey*20));
	}
	//画竖线
	pDC->MoveTo (recttmp.left+(int)(ratex*80),(int)(ratey*120));
	pDC->LineTo (recttmp.left+(int)(ratex*80),(int)(ratey*360));
	pDC->MoveTo (recttmp.left+(int)(ratex*230),(int)(ratey*120));
	pDC->LineTo (recttmp.left+(int)(ratex*230),(int)(ratey*360));
	pDC->MoveTo (recttmp.left+(int)(ratex*290),(int)(ratey*120));
	pDC->LineTo (recttmp.left+(int)(ratex*290),(int)(ratey*380));
	pDC->MoveTo (recttmp.left+(int)(ratex*350),(int)(ratey*120));
	pDC->LineTo (recttmp.left+(int)(ratex*350),(int)(ratey*380));
	pDC->MoveTo (recttmp.left+(int)(ratex*410),(int)(ratey*120));
	pDC->LineTo (recttmp.left+(int)(ratex*410),(int)(ratey*380));
	pDC->MoveTo (recttmp.left+(int)(ratex*470),(int)(ratey*120));
	pDC->LineTo (recttmp.left+(int)(ratex*470),(int)(ratey*360));

	pDC->MoveTo (recttmp.left+(int)(ratex*50),(int)(ratey*420));
	pDC->LineTo (recttmp.right-(int)(ratex*50),(int)(ratey*420));
		pDC->MoveTo (recttmp.left+(int)(ratex*50),(int)(ratey*422));
	pDC->LineTo (recttmp.right-(int)(ratex*50),(int)(ratey*422));

	//写产品标头
	CRect rect1(recttmp);
	rect1.left += (int)(55*ratex);
	rect1.top += (int)(ratey*125);
	pDC->DrawText("序号",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*30),0,0,0);
	pDC->DrawText("商品型号",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*150),0,0,0);
	pDC->DrawText("单位",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*60),0,0,0);
	pDC->DrawText("单价",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*60),0,0,0);
	pDC->DrawText("数量",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*60),0,0,0);
	pDC->DrawText("金额",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*60),0,0,0);
	pDC->DrawText("备注",rect1,DT_LEFT|DT_EDITCONTROL|DT_WORDBREAK);
	//t 190,b 526,l 540,r 638
	//写入产品信息
	if (m_dProCount>0)
	{
		int index = 0;
		for (index=0;(index<m_dProCount) && (index<11);index++)//每页只能写入11项产品
		{
			rect1 = recttmp;
			rect1.left += (int)(55*ratex);
			rect1.top += (int)(ratey*145 + ratey*20*index);
			CString strIndex;
			strIndex.Format("%d",index+1);
			pDC->DrawText(strIndex,rect1,DT_LEFT);
			rect1.DeflateRect((int)(ratex*30),0,0,0);
			pDC->DrawText(m_pProInfo[index].strProType,rect1,DT_LEFT|DT_EDITCONTROL|DT_WORDBREAK);
			rect1.DeflateRect((int)(ratex*150),0,0,0);
			pDC->DrawText(m_pProInfo[index].strUint,rect1,DT_LEFT);
			rect1.DeflateRect((int)(ratex*60),0,0,0);
			pDC->DrawText(m_pProInfo[index].strPrice,rect1,DT_LEFT);
			rect1.DeflateRect((int)(ratex*60),0,0,0);
			pDC->DrawText(m_pProInfo[index].strCount,rect1,DT_LEFT);
			rect1.DeflateRect((int)(ratex*60),0,0,0);
			pDC->DrawText(m_pProInfo[index].strMoney,rect1,DT_LEFT);
			rect1.DeflateRect((int)(ratex*60),0,0,0);
			pDC->DrawText(m_pProInfo[index].strTips,rect1,DT_LEFT|DT_EDITCONTROL|DT_WORDBREAK);		
		}
	}
	rect1 = recttmp;
	rect1.left += (int)(55*ratex);
	rect1.top += (int)(ratey*365);
	pDC->DrawText("金额合计(大写):",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*60),0,0,0);//大写总金额
	pDC->DrawText("",rect,DT_LEFT);

	rect1.DeflateRect((int)(ratex*180),0,0,0);
	pDC->DrawText("合计",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*60),0,0,0);//数量
	pDC->DrawText(m_strTotalCount,rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*60),0,0,0);//总金额
	pDC->DrawText(m_strTotalPrice,rect1,DT_LEFT);
	rect1 = recttmp;
	rect1.left += (int)(55*ratex);
	rect1.top += (int)(ratey*395);
	pDC->DrawText("审核人:",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText("____________",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*130),0,0,0);
	pDC->DrawText("制单人:",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText("____________",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*130),0,0,0);
	pDC->DrawText("客户签收:",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText("____________",rect1,DT_LEFT);

	font80.CreatePointFont(85,_T("宋体"),pDC);
	pDC->SelectObject(&font80);
	rect1 = recttmp;
	rect1.left += (int)(55*ratex);
	rect1.top += (int)(ratey*430);
	pDC->DrawText("第1页/共1页",rect1,DT_LEFT);
	rect1.DeflateRect((int)(ratex*360),0,0,0);
	pDC->DrawText("打印时间:",rect1,DT_LEFT);
	CTime currentTime = CTime::GetCurrentTime();
	CString strTimePrint;
	strTimePrint.Format("%04d-%02d-%02d  %02d:%02d:%02d",currentTime.GetYear(),
		currentTime.GetMonth(),currentTime.GetDay(),currentTime.GetHour(),currentTime.GetMinute(),currentTime.GetSecond());
	rect1.DeflateRect((int)(ratex*50),0,0,0);
	pDC->DrawText(strTimePrint,rect1,DT_LEFT);

	if(isprinted)
	{
		pDC->EndPage();
		pDC->EndDoc();
	}
}