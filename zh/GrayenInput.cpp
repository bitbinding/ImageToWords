// GrayenInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "GrayenInput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGrayenInput dialog


CGrayenInput::CGrayenInput(CWnd* pParent /*=NULL*/)
	: CDialog(CGrayenInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGrayenInput)
	//}}AFX_DATA_INIT
}


void CGrayenInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGrayenInput)
	DDX_Control(pDX, IDC_STATICrjq, m_l1);
	DDX_Control(pDX, IDC_STATICbjq, m_l3);
	DDX_Control(pDX, IDC_STATICscd, m_l4);
	DDX_Control(pDX, IDC_STATICgjq, m_l2);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_s3);
	DDX_Control(pDX, IDC_SCROLLBAR4, m_s4);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGrayenInput, CDialog)
	//{{AFX_MSG_MAP(CGrayenInput)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrayenInput message handlers

BOOL CGrayenInput::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
	SCROLLINFO si,siscd;
	si.fMask=SIF_ALL;
    si.nMax=10;
	si.nMin=0;
	si.nPage=1;
	si.nPos=5;
	siscd.fMask=SIF_ALL;
    siscd.nMax=510;
	siscd.nMin=0;
	siscd.nPage=1;
	siscd.nPos=510;
	m_s1.SetScrollInfo(&si,true);
	m_s2.SetScrollInfo(&si,true);
	m_s3.SetScrollInfo(&si,true);
	m_s4.SetScrollInfo(&siscd,true);
	int wr=5,wg=5,wb=5;
	float scd=0;
	CString str="";
	str.Format("红加权(%d):",wr);
	m_l1.SetWindowText(str);
	str.Format("绿加权(%d):",wg);
	m_l2.SetWindowText(str);
	str.Format("蓝加权(%d):",wb);
	m_l3.SetWindowText(str);
	str.Format("色彩度(%.2f):",scd);
	m_l4.SetWindowText(str);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();	
	pView->GrayenFilter(wr,wg,wb,scd);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGrayenInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	int stepl=1;
	int stepp=(pScrollBar==&m_s4)?5:1;
	int wr=5,wg=5,wb=5;
	float scd=0;
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
	wr=m_s1.GetScrollPos();
	wg=m_s2.GetScrollPos();
	wb=m_s3.GetScrollPos();
	scd=m_s4.GetScrollPos()<255 ? 514/((float)m_s4.GetScrollPos()+2)-1 : 510/(float)m_s4.GetScrollPos()-1;
	str.Format("红加权(%d):",wr);
	m_l1.SetWindowText(str);
	str.Format("绿加权(%d):",wg);
	m_l2.SetWindowText(str);
	str.Format("蓝加权(%d):",wb);
	m_l3.SetWindowText(str);
	str.Format("色彩度(%.2f):",scd);
	m_l4.SetWindowText(str);
	
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		if(wr+wg+wb==0){
			MessageBox("权重不全为零！");
		}
		pView->GrayenFilter(wr,wg,wb,scd);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	
}
