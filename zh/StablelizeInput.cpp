// StablelizeInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "StablelizeInput.h"
#include "ImageToWordsView.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStablelizeInput dialog


CStablelizeInput::CStablelizeInput(CWnd* pParent /*=NULL*/)
	: CDialog(CStablelizeInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStablelizeInput)
	m_c1 = FALSE;
	//}}AFX_DATA_INIT
}


void CStablelizeInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStablelizeInput)
	DDX_Control(pDX, IDC_STATIC3, m_l3);
	DDX_Control(pDX, IDC_STATIC2, m_l2);
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_s3);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_Check(pDX, IDC_CHECK1, m_c1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStablelizeInput, CDialog)
	//{{AFX_MSG_MAP(CStablelizeInput)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStablelizeInput message handlers

BOOL CStablelizeInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SCROLLINFO si1,si2,si3;
	si1.fMask=SIF_ALL;
    si1.nMax=99;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=9;
	si2.fMask=SIF_ALL;
    si2.nMax=510;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=255;
	si3.fMask=SIF_ALL;
    si3.nMax=360;
	si3.nMin=0;
	si3.nPage=1;
	si3.nPos=45;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	m_s3.SetScrollInfo(&si3,true);
	angle=45;
	bj=1,sl=1;
	CString str="";	
	str.Format("长度(%.1f):",bj);
	m_l1.SetWindowText(str);
	str.Format("程度(%.2f):",sl);
	m_l2.SetWindowText(str);
	str.Format("角度(%d):",angle);
	m_l3.SetWindowText(str);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStablelizeInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default	
	int stepl=1;
	int stepp=5;	
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
	bj=(m_s1.GetScrollPos()+1)/10.0f;	
	sl=m_s2.GetScrollPos()>255 ? 514/(512-(float)m_s2.GetScrollPos())-1 : 510/(510-(float)m_s2.GetScrollPos())-1;
	angle=m_s3.GetScrollPos();
	str.Format("长度(%.1f):",bj);
	m_l1.SetWindowText(str);
	str.Format("程度(%.2f):",sl);
	m_l2.SetWindowText(str);
	str.Format("角度(%d):",angle);
	m_l3.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		getConvolutioned(m_c1==TRUE);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CStablelizeInput::OnCheck1() 
{
	// TODO: Add your control notification handler code here	
	UpdateData(TRUE);	
	getConvolutioned(m_c1==TRUE);
}

void CStablelizeInput::getConvolutioned(bool hbyl){
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();	
	double angle2=angle*3.141592653589793/180;
	double rx=bj*cos(angle2);
	double ry=bj*sin(angle2);
	int xs=(int)floor(rx);
	int ys=(int)floor(ry);
	float dx=(float)(rx-xs);
	float dy=(float)(ry-ys);
	float arr1[5]={-(1-dx)*(1-dy)*sl,-dx*(1-dy)*sl,-(1-dx)*dy*sl,-dx*dy*sl,sl+1};
	pView->ConvolutionFilter(arr1,0,5,2,-xs,-ys);
	if(hbyl){
		pView->previewHeibaien(128);
	}
}