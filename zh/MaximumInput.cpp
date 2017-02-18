// MaximumInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "MaximumInput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMaximumInput dialog


CMaximumInput::CMaximumInput(CWnd* pParent /*=NULL*/)
	: CDialog(CMaximumInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMaximumInput)
	m_r1 = 0;
	//}}AFX_DATA_INIT
}


void CMaximumInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMaximumInput)
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_Radio(pDX, IDC_RADIO1, m_r1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMaximumInput, CDialog)
	//{{AFX_MSG_MAP(CMaximumInput)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMaximumInput message handlers

BOOL CMaximumInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SCROLLINFO si1;
	si1.fMask=SIF_ALL;
    si1.nMax=19;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=2;
	m_s1.SetScrollInfo(&si1,true);
	bjc2=3;
	CString str="";
	if(bjc2>1){
		str.Format("°ë¾¶(%.1f):",bjc2*0.5f-0.5f);
	}else{
		str="°ë¾¶(0.25):";
	}
	m_l1.SetWindowText(str);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->MaximumFilter(bjc2-1,m_r1==0?false:true);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMaximumInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	int stepl=1;
	int stepp=5;
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
	bjc2=m_s1.GetScrollPos()+1;
	if(bjc2>1){
		str.Format("°ë¾¶(%.1f):",bjc2*0.5f-0.5f);
	}else{
		str="°ë¾¶(0.25):";
	}
	m_l1.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->MaximumFilter(bjc2-1,m_r1==0?false:true);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMaximumInput::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	pView->MaximumFilter(bjc2-1,m_r1==0?false:true);
}

void CMaximumInput::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	pView->MaximumFilter(bjc2-1,m_r1==0?false:true);
}
