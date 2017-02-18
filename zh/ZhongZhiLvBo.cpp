// ZhongZhiLvBo.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "ZhongZhiLvBo.h"
#include "ImageToWordsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZhongZhiLvBo dialog


CZhongZhiLvBo::CZhongZhiLvBo(CWnd* pParent /*=NULL*/)
	: CDialog(CZhongZhiLvBo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZhongZhiLvBo)
	m_r1 = 0;
	//}}AFX_DATA_INIT
}


void CZhongZhiLvBo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZhongZhiLvBo)
	DDX_Control(pDX, IDC_STATIC14, m_l4);
	DDX_Control(pDX, IDC_SCROLLBAR4, m_s4);
	DDX_Control(pDX, IDC_STATIC6, m_l3);
	DDX_Control(pDX, IDC_STATIC2, m_l2);
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_s3);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_Radio(pDX, IDC_RADIO1, m_r1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZhongZhiLvBo, CDialog)
	//{{AFX_MSG_MAP(CZhongZhiLvBo)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZhongZhiLvBo message handlers

BOOL CZhongZhiLvBo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	si1.fMask=SIF_ALL;
    si1.nMax=20;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=0;
	si2.fMask=SIF_ALL;
    si2.nMax=255;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=0;
	si3.fMask=SIF_ALL;
    si3.nMax=510;
	si3.nMin=0;
	si3.nPage=1;
	si3.nPos=255;
	si4.fMask=SIF_ALL;
    si4.nMax=255;
	si4.nMin=0;
	si4.nPage=1;
	si4.nPos=255;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	m_s3.SetScrollInfo(&si3,true);
	m_s4.SetScrollInfo(&si4,true);
	bc=1,bl=0,bl2=255;
	power=1.0;
	CString str="";	
	str.Format("边长(%d):",bc);
	m_l1.SetWindowText(str);
	str.Format("低保留(%d):",bl);
	m_l2.SetWindowText(str);
	str.Format("指数(%.2f):",power);
	m_l3.SetWindowText(str);
	str.Format("高保留(%d):",bl2);
	m_l4.SetWindowText(str);
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CZhongZhiLvBo::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
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
	bc=m_s1.GetScrollPos()+1;
	bl=m_s2.GetScrollPos();
	bl2=m_s4.GetScrollPos();
	power=m_s3.GetScrollPos()>255 ? 514/(512-(double)m_s3.GetScrollPos())-1 : 510/(510-(double)m_s3.GetScrollPos())-1;
	str.Format("边长(%d):",bc);
	m_l1.SetWindowText(str);
	str.Format("低保留(%d):",bl);
	m_l2.SetWindowText(str);
	str.Format("高保留(%d):",bl2);
	m_l4.SetWindowText(str);
	str.Format("指数(%.2f):",power);
	m_l3.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->ZhongZhiLvBoFilterOld(bc,bl,bl2,power,m_r1,pScrollBar==&m_s1);		
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CZhongZhiLvBo::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	pView->ZhongZhiLvBoFilterOld(bc,bl,bl2,power,m_r1);
}

void CZhongZhiLvBo::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	pView->ZhongZhiLvBoFilterOld(bc,bl,bl2,power,m_r1);
}
