// RuihuaInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "RuihuaInput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRuihuaInput dialog


CRuihuaInput::CRuihuaInput(CWnd* pParent /*=NULL*/)
	: CDialog(CRuihuaInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRuihuaInput)
	m_c1 = FALSE;
	m_c2 = FALSE;
	//}}AFX_DATA_INIT
	bj=1,yz=0;
	sl=1;
}


void CRuihuaInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRuihuaInput)
	DDX_Control(pDX, IDC_STATICyz1, m_l3);
	DDX_Control(pDX, IDC_STATICsl1, m_l2);
	DDX_Control(pDX, IDC_STATICbj1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_s3);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_Check(pDX, IDC_CHECK1, m_c1);
	DDX_Check(pDX, IDC_CHECK2, m_c2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRuihuaInput, CDialog)
	//{{AFX_MSG_MAP(CRuihuaInput)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRuihuaInput message handlers

BOOL CRuihuaInput::OnInitDialog() 
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
    si2.nMax=510;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=0;
	si3.fMask=SIF_ALL;
    si3.nMax=256;
	si3.nMin=0;
	si3.nPage=1;
	si3.nPos=0;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	m_s3.SetScrollInfo(&si3,true);
	bj=1,yz=0;
	sl=1;
	CString str="";	
	str.Format("半径(%d):",bj);
	m_l1.SetWindowText(str);
	str.Format("数量(%.2f):",sl);
	m_l2.SetWindowText(str);
	str.Format("阈值(%d):",yz);
	m_l3.SetWindowText(str);
	//pView->statZft(0,statPinshu);//计算原始各明暗度的频数
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRuihuaInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	int stepl=1;
	int stepp=(pScrollBar==&m_s1)?1:5;
	bj=1,yz=0;
	sl=1;
	CString str="";
	UpdateData(TRUE);
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
	sl=514/(512-(float)m_s2.GetScrollPos());
	yz=m_s3.GetScrollPos();
	str.Format("半径(%d):",bj);
	m_l1.SetWindowText(str);
	str.Format("数量(%.2f):",sl);
	m_l2.SetWindowText(str);
	str.Format("阈值(%d):",yz);
	m_l3.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->RuihuaFilter(bj,sl,yz,m_c1);
		if(m_c2==TRUE){
			pView->previewHeibaien(128);
		}
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);	
}

void CRuihuaInput::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	bj=1,yz=0;
	sl=1;
	UpdateData(TRUE);	
	bj=m_s1.GetScrollPos()+1;
	sl=514/(512-(float)m_s2.GetScrollPos());
	yz=m_s3.GetScrollPos();
	pView->RuihuaFilter(bj,sl,yz,m_c1);
	if(m_c2==TRUE){
		pView->previewHeibaien(128);
	}
}

void CRuihuaInput::OnCheck2() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	bj=1,yz=0;
	sl=1;
	UpdateData(TRUE);	
	bj=m_s1.GetScrollPos()+1;
	sl=514/(512-(float)m_s2.GetScrollPos());
	yz=m_s3.GetScrollPos();
	pView->RuihuaFilter(bj,sl,yz,m_c1);
	if(m_c2==TRUE){
		pView->previewHeibaien(128);
	}
}


