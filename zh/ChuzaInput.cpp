// ChuzaInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "ChuzaInput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChuzaInput dialog


CChuzaInput::CChuzaInput(CWnd* pParent /*=NULL*/)
	: CDialog(CChuzaInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChuzaInput)
	//}}AFX_DATA_INIT
}


void CChuzaInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChuzaInput)
	DDX_Control(pDX, IDC_STATIC6, m_l3);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_s3);
	DDX_Control(pDX, IDC_STATIC2, m_l2);
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChuzaInput, CDialog)
	//{{AFX_MSG_MAP(CChuzaInput)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChuzaInput message handlers

BOOL CChuzaInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SCROLLINFO si1,si2,si3;
	si1.fMask=SIF_ALL;
    si1.nMax=49;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=0;
	si2.fMask=SIF_ALL;
    si2.nMax=256;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=32;
	si3.fMask=SIF_ALL;
    si3.nMax=15;
	si3.nMin=0;
	si3.nPage=1;
	si3.nPos=2;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	m_s3.SetScrollInfo(&si3,true);
	int num=1,yz=32,hx=2;
	CString str="";
	str.Format("数量(%d):",num);
	m_l1.SetWindowText(str);
	str.Format("阈值(%d):",yz);
	m_l2.SetWindowText(str);
	str.Format("化小(%d):",hx);
	m_l3.SetWindowText(str);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->ChuzaFilter(num,yz,hx);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CChuzaInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	int stepl=1;
	int stepp=(pScrollBar==&m_s1)?1:5;
	int num=1,yz=32,hx=2;
	CString str="";
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
	num=m_s1.GetScrollPos()+1;
	yz=m_s2.GetScrollPos();
	hx=m_s3.GetScrollPos();
	str.Format("数量(%d):",num);
	m_l1.SetWindowText(str);
	str.Format("阈值(%d):",yz);
	m_l2.SetWindowText(str);
	str.Format("化小(%d):",hx);
	m_l3.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->ChuzaFilter(num,yz,hx);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
