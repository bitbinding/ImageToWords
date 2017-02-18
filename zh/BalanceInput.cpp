// BalanceInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "BalanceInput.h"
#include "ImageToWordsView.h"
//#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBalanceInput dialog


CBalanceInput::CBalanceInput(CWnd* pParent /*=NULL*/)
	: CDialog(CBalanceInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBalanceInput)
	//}}AFX_DATA_INIT
}


void CBalanceInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBalanceInput)
	DDX_Control(pDX, IDC_STATICd, m_l4);
	DDX_Control(pDX, IDC_STATICc, m_l3);
	DDX_Control(pDX, IDC_STATICb, m_l2);
	DDX_Control(pDX, IDC_STATICa, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR4, m_s4);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_s3);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBalanceInput, CDialog)
	//{{AFX_MSG_MAP(CBalanceInput)
	ON_WM_CREATE()
	ON_WM_HSCROLL()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBalanceInput message handlers



int CBalanceInput::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

BOOL CBalanceInput::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
	SCROLLINFO si,si2;
	si.fMask=SIF_ALL;
    si.nMax=510;
	si.nMin=0;
	si.nPage=1;
	si.nPos=255;
	si2.fMask=SIF_ALL;
    si2.nMax=360;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=180;
	m_s1.SetScrollInfo(&si,true);
	m_s2.SetScrollInfo(&si,true);
	m_s3.SetScrollInfo(&si2,true);
	m_s4.SetScrollInfo(&si,true);
	int ld=0,sx=0;
	float dbd=1,bhd=1;
	CString str="";
	str.Format("亮度(%d):",ld);
	m_l1.SetWindowText(str);
	str.Format("对比度(%.2f):",dbd);
	m_l2.SetWindowText(str);
	str.Format("色相(%d):",sx);
	m_l3.SetWindowText(str);
	str.Format("饱和(%.2f):",bhd);
	m_l4.SetWindowText(str);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CBalanceInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();	
	int stepl=1;
	int stepp=5;
	int ld,sx;
	float dbd,bhd;
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
	ld=m_s1.GetScrollPos()-255;
	dbd=m_s2.GetScrollPos()>255 ? 514/(512-(float)m_s2.GetScrollPos())-1 : 510/(510-(float)m_s2.GetScrollPos())-1;
	sx=m_s3.GetScrollPos()-180;
	bhd=m_s4.GetScrollPos()>255 ? 514/(512-(float)m_s4.GetScrollPos())-1 : 510/(510-(float)m_s4.GetScrollPos())-1;
	str.Format("亮度(%d):",ld);
	m_l1.SetWindowText(str);
	str.Format("对比度(%.2f):",dbd);
	m_l2.SetWindowText(str);
	str.Format("色相(%d):",sx);
	m_l3.SetWindowText(str);
	str.Format("饱和(%.2f):",bhd);
	m_l4.SetWindowText(str);
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->BalanceFilter(ld,dbd,sx,bhd);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CBalanceInput::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}
