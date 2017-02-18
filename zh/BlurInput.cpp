// BlurInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "BlurInput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlurInput dialog


CBlurInput::CBlurInput(CWnd* pParent /*=NULL*/)
	: CDialog(CBlurInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBlurInput)
	m_c1 = FALSE;
	m_c2 = FALSE;
	//}}AFX_DATA_INIT
}


void CBlurInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBlurInput)
	DDX_Control(pDX, IDC_STATICyz2, m_l2);
	DDX_Control(pDX, IDC_STATICrb, m_l3);
	DDX_Control(pDX, IDC_STATICbj2, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_s3);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_Check(pDX, IDC_CHECK1, m_c1);
	DDX_Check(pDX, IDC_CHECK2, m_c2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBlurInput, CDialog)
	//{{AFX_MSG_MAP(CBlurInput)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlurInput message handlers

BOOL CBlurInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SCROLLINFO si1,si2,si3;
	si1.fMask=SIF_ALL;
    si1.nMax=9;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=0;
	si2.fMask=SIF_ALL;
    si2.nMax=256;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=256;
	si3.fMask=SIF_ALL;
	si3.nMax=100;
	si3.nMin=0;
	si3.nPage=1;
	si3.nPos=5;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	m_s3.SetScrollInfo(&si3,true);
	int bj=1,yz=256,gd=5;
	CString str="";	
	str.Format("°ë¾¶(%d):",bj);
	m_l1.SetWindowText(str);
	str.Format("ãÐÖµ(%d):",yz);
	m_l2.SetWindowText(str);
	str.Format("¹ý¶É(%d):",gd);
	m_l3.SetWindowText(str);
	UpdateData(TRUE);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->BlurFilter(bj,yz,gd,m_c1,m_c2);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBlurInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	int stepl=1;
	int stepp=(pScrollBar==&m_s1 || pScrollBar==&m_s3)?1:5;
	int bj=1,yz=256,gd=5;
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
	bj=m_s1.GetScrollPos()+1;
	yz=m_s2.GetScrollPos();
	gd=m_s3.GetScrollPos();
	str.Format("°ë¾¶(%d):",bj);
	m_l1.SetWindowText(str);
	str.Format("ãÐÖµ(%d):",yz);
	m_l2.SetWindowText(str);
	str.Format("¹ý¶É(%d):",gd);
	m_l3.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->BlurFilter(bj,yz,gd,m_c1,m_c2);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CBlurInput::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	int bj=1,yz=256,gd=5;
	UpdateData(TRUE);	
	bj=m_s1.GetScrollPos()+1;
	yz=m_s2.GetScrollPos();
	gd=m_s3.GetScrollPos();
	pView->BlurFilter(bj,yz,gd,m_c1,m_c2);
}

void CBlurInput::OnCheck2() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	int bj=1,yz=256,gd=5;
	UpdateData(TRUE);
	bj=m_s1.GetScrollPos()+1;
	yz=m_s2.GetScrollPos();
	gd=m_s3.GetScrollPos();
	pView->BlurFilter(bj,yz,gd,m_c1,m_c2);
}
