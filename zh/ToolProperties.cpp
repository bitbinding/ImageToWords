// ToolProperties.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "ToolProperties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolProperties dialog


CToolProperties::CToolProperties(CWnd* pParent /*=NULL*/)
{
	//{{AFX_DATA_INIT(CToolProperties)
	m_e1 = 10;
	m_e2 = 0;
	m_e3 = _T("000000");
	m_check1 = TRUE;
	//}}AFX_DATA_INIT
	color=0;
	//SetDlgItemText(IDC_EDIT1,"1");
	//SetDlgItemText(IDC_EDIT2,"100");
	//SetDlgItemText(IDC_EDIT3,"0");
}


void CToolProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToolProperties)
	DDX_Text(pDX, IDC_EDIT1, m_e1);
	DDX_Text(pDX, IDC_EDIT2, m_e2);
	DDX_Text(pDX, IDC_EDIT3, m_e3);
	DDX_Check(pDX, IDC_CHECK1, m_check1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToolProperties, CDialogBar)
	//{{AFX_MSG_MAP(CToolProperties)
	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolProperties message handlers




BOOL CToolProperties::OnInitDialog() 
{
	//CDialogBar::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CToolProperties::OnButton1() 
{
	// TODO: Add your control notification handler code here
	updateVariables();
	CColorDialog dlg;
	dlg.m_cc.Flags = CC_FULLOPEN | CC_RGBINIT;
	int r=color>>16&0xff;
	int g=color>>8&0xff;
	int b=color&0xff;
	dlg.m_cc.rgbResult = RGB(r, g, b);
	if(dlg.DoModal()==IDOK){
		COLORREF colorRef=dlg.GetColor();
		r=GetRValue(colorRef);
		g=GetGValue(colorRef);
		b=GetBValue(colorRef);
		color=r<<16|g<<8|b;
		updateInterface();
	}
}

void CToolProperties::updateVariables(){
	UpdateData(TRUE);
	color=0;
	sscanf((LPCTSTR)m_e3,"%x",&color);
}

void CToolProperties::updateInterface(){
	m_e3.Format("%06x",color);
	UpdateData(FALSE);
}
