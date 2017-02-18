// RotateInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "RotateInput.h"
#include "ImageToWordsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRotateInput dialog


CRotateInput::CRotateInput(CWnd* pParent /*=NULL*/)
	: CDialog(CRotateInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRotateInput)
	m_co1 = 0;
	//}}AFX_DATA_INIT
	bgc=RGB(255,255,255);
}


void CRotateInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRotateInput)
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_CBIndex(pDX, IDC_COMBO1, m_co1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRotateInput, CDialog)
	//{{AFX_MSG_MAP(CRotateInput)
	ON_WM_HSCROLL()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateInput message handlers

BOOL CRotateInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SCROLLINFO si1;
	si1.fMask=SIF_ALL;
    si1.nMax=360;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=180;
	m_s1.SetScrollInfo(&si1,true);
	int angle=0;
	CString str="";
	str.Format("실똑(%d):",angle);
	m_l1.SetWindowText(str);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRotateInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	int stepl=1;
	int stepp=5;
	
	switch(nSBCode){
		case SB_LINELEFT:
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()-stepl>0?pScrollBar->GetScrollPos()-stepl:0);
			break;
		case SB_LINERIGHT:
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()+stepl<pScrollBar->GetScrollLimit()?pScrollBar->GetScrollPos()+stepl:pScrollBar->GetScrollLimit());
			break;
		case SB_PAGELEFT:
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()-stepp>0?pScrollBar->GetScrollPos()-stepp:0);
			break;
		case SB_PAGERIGHT:
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()+stepp<pScrollBar->GetScrollLimit()?pScrollBar->GetScrollPos()+stepp:pScrollBar->GetScrollLimit());
			break;
		case SB_THUMBPOSITION: 
			pScrollBar->SetScrollPos(nPos);
			break; 
		case SB_THUMBTRACK: 
			//ScrollWindow((scrollinfo.nPos-nPos)*10,0); 
			//scrollinfo.nPos = nPos; 
			//SetScrollInfo(SB_HORZ,&scrollinfo,SIF_ALL); 
			break; 
		case SB_ENDSCROLL: 
			break;  
	}
	int angle=m_s1.GetScrollPos()-180;
	CString str;
	str.Format("실똑(%d):",angle);
	m_l1.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->RotateFilter((double)angle,m_co1,bgc);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CRotateInput::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int angle=m_s1.GetScrollPos()-180;
	CString str;
	str.Format("실똑(%d):",angle);
	m_l1.SetWindowText(str);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->RotateFilter((double)angle,m_co1,bgc);
}

void CRotateInput::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg(bgc,CC_FULLOPEN);
	if(dlg.DoModal()==IDOK){
		bgc=dlg.GetColor();
		int angle=m_s1.GetScrollPos()-180;
		CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
		CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
		pView->RotateFilter((double)angle,m_co1,bgc);
	}
}
