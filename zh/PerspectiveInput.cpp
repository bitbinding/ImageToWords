// PerspectiveInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "PerspectiveInput.h"
#include "ImageToWordsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPerspectiveInput dialog


CPerspectiveInput::CPerspectiveInput(CWnd* pParent /*=NULL*/)
	: CDialog(CPerspectiveInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPerspectiveInput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPerspectiveInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPerspectiveInput)
	DDX_Control(pDX, IDC_STATIC2, m_l2);
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPerspectiveInput, CDialog)
	//{{AFX_MSG_MAP(CPerspectiveInput)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPerspectiveInput message handlers

BOOL CPerspectiveInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SCROLLINFO si1,si2;
	si1.fMask=SIF_ALL;
    si1.nMax=75;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=0;
	si2.fMask=SIF_ALL;
    si2.nMax=150;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=75;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	int scale=0,offset=0;
	CString str="";
	str.Format("Ëõ·Å(%d¡ã):",scale);
	m_l1.SetWindowText(str);
	str.Format("Æ«ÒÆ(%d¡ã):",offset);
	m_l2.SetWindowText(str);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->PerspectiveFilter(scale,offset);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPerspectiveInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	int stepl=1;
	int stepp=(pScrollBar==&m_s1)?1:5;
	
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
	int scale=0,offset=0;
	scale=m_s1.GetScrollPos();
	offset=m_s2.GetScrollPos()-75;
	CString str="";
	str.Format("Ëõ·Å(%d¡ã):",scale);
	m_l1.SetWindowText(str);
	str.Format("Æ«ÒÆ(%d¡ã):",offset);
	m_l2.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->PerspectiveFilter(scale,offset);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
