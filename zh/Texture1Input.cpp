// Texture1Input.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "Texture1Input.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTexture1Input dialog


CTexture1Input::CTexture1Input(CWnd* pParent /*=NULL*/)
	: CDialog(CTexture1Input::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTexture1Input)
	m_c1 = 0;
	//}}AFX_DATA_INIT
}


void CTexture1Input::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTexture1Input)
	DDX_Control(pDX, IDC_STATIC2, m_l2);
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_CBIndex(pDX, IDC_COMBO1, m_c1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTexture1Input, CDialog)
	//{{AFX_MSG_MAP(CTexture1Input)
	ON_WM_HSCROLL()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTexture1Input message handlers

BOOL CTexture1Input::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SCROLLINFO si1,si2;
	si1.fMask=SIF_ALL;
    si1.nMax=100;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=0;
	si2.fMask=SIF_ALL;
    si2.nMax=100;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=0;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	int offset=0,rate=0;
	CString str="";
	str.Format("重合像素(%d):",offset);
	m_l1.SetWindowText(str);
	str.Format("缩放起始(%d%%):",rate);
	m_l2.SetWindowText(str);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->Texture1FilterPreload();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTexture1Input::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
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
	int offset=0,rate=0;
	offset=m_s1.GetScrollPos();
	rate=m_s2.GetScrollPos();
	CString str="";
	str.Format("重合像素(%d):",offset);
	m_l1.SetWindowText(str);
	str.Format("缩放起始(%d%%):",rate);
	m_l2.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->Texture1Filter(offset,rate,m_c1);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CTexture1Input::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int offset=0,rate=0;
	offset=m_s1.GetScrollPos();
	rate=m_s2.GetScrollPos();

	UpdateData(TRUE);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->Texture1Filter(offset,rate,m_c1);
}
