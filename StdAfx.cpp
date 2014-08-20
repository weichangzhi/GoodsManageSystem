// stdafx.cpp : source file that includes just the standard includes
//	GoodsManageSystem.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

BOOL bDesc = 0;
int nColToSort=0;
int nLastColToSort=0;

bool IsNumber( LPCTSTR pszText )
{
	if (lstrlen( pszText )==0||lstrlen( pszText )>9)
		return false;
	for( int i = 0; i < lstrlen( pszText ); i++ )
		if( !_istdigit( pszText[ i ] ) )
			return false;
		
		return true;
}


int NumberCompare( LPCTSTR pszNumber1, LPCTSTR pszNumber2 )
{
	const int iNumber1 = atoi( pszNumber1 );
	const int iNumber2 = atoi( pszNumber2 );
	
	if( iNumber1 < iNumber2 )
		return -1;
	
	if( iNumber1 > iNumber2 )
		return 1;
	
	return 0;
}

void writelog(CString strlog)
{
	if(strlog.IsEmpty())
		return;
	strlog += "\r\n";
	if(g_fplog==NULL)
		return;
	CTime time = CTime::GetCurrentTime();
	CString tmp ;
	tmp.Format("[%02d-%02d %02d:%02d:%02d]  ",time.GetMonth(),time.GetDay(),time.GetHour(),time.GetMinute(),time.GetSecond());
	tmp += strlog;
	int len = tmp.GetLength();
	fwrite(tmp,len,1,g_fplog);
	fflush(g_fplog);
}

FILE* g_fplog = NULL;