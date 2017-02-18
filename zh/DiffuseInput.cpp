// DiffuseInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "DiffuseInput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiffuseInput dialog


CDiffuseInput::CDiffuseInput(CWnd* pParent /*=NULL*/)
	: CDialog(CDiffuseInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDiffuseInput)
	m_r1 = 0;
	m_c1 = FALSE;
	m_c2 = FALSE;
	//}}AFX_DATA_INIT
}


void CDiffuseInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiffuseInput)
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_Radio(pDX, IDC_RADIO1, m_r1);
	DDX_Check(pDX, IDC_CHECK1, m_c1);
	DDX_Check(pDX, IDC_CHECK3, m_c2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDiffuseInput, CDialog)
	//{{AFX_MSG_MAP(CDiffuseInput)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiffuseInput message handlers

BOOL CDiffuseInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	si1.fMask=SIF_ALL;
    si1.nMax=19;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=1;
	si2.fMask=SIF_ALL;
    si2.nMax=255;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=0;
	m_s1.SetScrollInfo(&si1,true);
	bjc2=2;
	CString str="";	
	str.Format("°ë¾¶(%.1f):",bjc2*0.5f);
	m_l1.SetWindowText(str);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->DiffuseFilter(bjc2,m_r1==0?false:true);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDiffuseInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
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
	if(m_c1==FALSE){
		bjc2=m_s1.GetScrollPos()+1;
		str.Format("°ë¾¶(%.1f):",bjc2*0.5f);
		m_l1.SetWindowText(str);
	}else{
		offset=m_s1.GetScrollPos();
		str.Format("Æ«ÒÆ(%d):",offset);
		m_l1.SetWindowText(str);
	}	
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		if(m_c1==FALSE){
			pView->DiffuseFilter(bjc2,m_r1==0?false:true);
		}else{
			pView->ColourOffsetFilter(offset);
		}
		if(m_c2==TRUE){
			pView->previewHeibaien(128);
		}
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CDiffuseInput::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_c1==FALSE){
		pView->DiffuseFilter(bjc2,m_r1==0?false:true);
	}else{
		pView->ColourOffsetFilter(offset);
	}
	if(m_c2==TRUE){
		pView->previewHeibaien(128);
	}
}

void CDiffuseInput::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_c1==FALSE){
		pView->DiffuseFilter(bjc2,m_r1==0?false:true);
	}else{
		pView->ColourOffsetFilter(offset);
	}
	if(m_c2==TRUE){
		pView->previewHeibaien(128);
	}
}

void CDiffuseInput::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_c1==FALSE){
		pView->DiffuseFilter(bjc2,m_r1==0?false:true);
	}else{
		pView->ColourOffsetFilter(offset);
	}
	if(m_c2==TRUE){
		pView->previewHeibaien(128);
	}
}

void CDiffuseInput::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	CString str="";
	UpdateData(TRUE);
	if(m_c1==FALSE){
		m_s1.SetScrollInfo(&si1,true);
	}else{
		m_s1.SetScrollInfo(&si2,true);
	}
	if(m_c1==FALSE){
		bjc2=m_s1.GetScrollPos()+1;
		str.Format("°ë¾¶(%.1f):",bjc2*0.5f);
		m_l1.SetWindowText(str);
	}else{
		offset=m_s1.GetScrollPos();
		str.Format("Æ«ÒÆ(%d):",offset);
		m_l1.SetWindowText(str);
	}
	if(m_c1==FALSE){
		pView->DiffuseFilter(bjc2,m_r1==0?false:true);
	}else{
		pView->ColourOffsetFilter(offset);
	}
	if(m_c2==TRUE){
		pView->previewHeibaien(128);
	}
}

void CDiffuseInput::OnCheck3() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_c1==FALSE){
		pView->DiffuseFilter(bjc2,m_r1==0?false:true);
	}else{
		pView->ColourOffsetFilter(offset);
	}
	if(m_c2==TRUE){
		pView->previewHeibaien(128);
	}
}
