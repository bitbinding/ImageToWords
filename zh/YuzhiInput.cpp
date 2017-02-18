// YuzhiInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "YuzhiInput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYuzhiInput dialog


CYuzhiInput::CYuzhiInput(CWnd* pParent /*=NULL*/)
	: CDialog(CYuzhiInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYuzhiInput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	int i;
	for(i=0;i<256;i++){			
		statPinshu[i]=0;
	}
	statMax=1;
	yz=0;
	dbd=0;
}


void CYuzhiInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYuzhiInput)
	DDX_Control(pDX, IDC_STATICyzdb, m_l2);
	DDX_Control(pDX, IDC_STATICyuzhi, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CYuzhiInput, CDialog)
	//{{AFX_MSG_MAP(CYuzhiInput)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYuzhiInput message handlers

BOOL CYuzhiInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SCROLLINFO si1,si2;
	si1.fMask=SIF_ALL;
    si1.nMax=256;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=128;
	si2.fMask=SIF_ALL;
    si2.nMax=510;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=255;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	yz=128;//阈值
	dbd=1;//对比度
	CString str="";
	str.Format("阈值(%d):",yz);
	m_l1.SetWindowText(str);
	str.Format("对比(%.2f):",dbd);
	m_l2.SetWindowText(str);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();	
	pView->statZft(0,statPinshu);//计算原始各明暗度的频数
	int i;
	statMax=1;
	for(i=1;i<255;i++){
		if(statMax<statPinshu[i]){
			statMax=statPinshu[i];
		}
	}
	pView->YuzhiFilter(yz,dbd);
	//pView->GrayenFilter(wr,wg,wb,scd);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CYuzhiInput::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	// 获取绘制坐标的文本框
	CWnd* pWnd = GetDlgItem(IDC_ZHIFANGTU2); 
	pWnd->GetClientRect(&rect);
	// 指针
	CDC* pDC = pWnd->GetDC();
	pWnd->Invalidate();
	pWnd->UpdateWindow(); 
	//画外框
	//pDC->Rectangle(&rect); 
	//画直方图
	CPen pen,*oldpen;
	pen.CreatePen(PS_SOLID,1,RGB(127,127,127));
	oldpen=pDC->SelectObject(&pen);
	int i=0;
	int T=256/dbd;
	int bchange=128-(int)(128/dbd)>0?(128-(int)(128/dbd))%T:128-(int)(128/dbd);
	int wchange=bchange+yz*T/256;
	if(i>=wchange){pDC->SelectObject(&pen);bchange+=T;wchange+=T;}
	else if(i>=bchange){pDC->SelectObject(oldpen);}
	if(statPinshu[i]<=statMax){
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.bottom-2-(rect.Height()-3)*statPinshu[i]/statMax);
	}else{
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.top-1);
	}
	for (i=1;i<255;i++){
		if(i>=wchange){pDC->SelectObject(&pen);bchange+=T;wchange+=T;}
		else if(i>=bchange){pDC->SelectObject(oldpen);}	
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.bottom-2-(rect.Height()-3)*statPinshu[i]/statMax);
	}
	if(i>=wchange){pDC->SelectObject(&pen);bchange+=T;wchange+=T;}
	else if(i>=bchange){pDC->SelectObject(oldpen);}
	if(statPinshu[i]<=statMax){
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.bottom-2-(rect.Height()-3)*statPinshu[i]/statMax);
	}else{
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.top-1);
	}
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CYuzhiInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
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
	yz=m_s1.GetScrollPos();
	dbd=514/(512-(float)m_s2.GetScrollPos())-1;
	str.Format("阈值(%d):",yz);
	m_l1.SetWindowText(str);
	if(dbd>=0.01){
		str.Format("对比(%.2f):",dbd);
	}else{
		str="对比(>0)";
	}
	m_l2.SetWindowText(str);
	OnPaint();
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		pView->YuzhiFilter(yz,dbd);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
