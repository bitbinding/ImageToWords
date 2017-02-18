// SejieInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "SejieInput.h"
#include "ImageToWordsView.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSejieInput dialog


CSejieInput::CSejieInput(CWnd* pParent /*=NULL*/)
	: CDialog(CSejieInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSejieInput)
	m_e1 = 0;
	m_e2 = 0.0;
	m_e3 = 0;
	m_e4 = 0;
	m_e5 = 0;
	m_c1 = -1;
	//}}AFX_DATA_INIT
	int i;
	for(i=0;i<256;i++){			
		statPinshu[i]=0;
	}
	statMax=1;
	hkwid=11;//设置滑块宽高
	hkhei=9;
	hkDrag=0;
	grayPos=0;
	channelBw[0][0]=0;
	channelBw[0][1]=255;
	channelBw[0][2]=0;
	channelBw[0][3]=255;
	channelBw[1][0]=0;
	channelBw[1][1]=255;
	channelBw[1][2]=0;
	channelBw[1][3]=255;
	channelBw[2][0]=0;
	channelBw[2][1]=255;
	channelBw[2][2]=0;
	channelBw[2][3]=255;
	channelGray[0]=1;
	channelGray[1]=1;
	channelGray[2]=1;
}


void CSejieInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSejieInput)
	DDX_Text(pDX, IDC_EDIT2, m_e1);
	DDX_Text(pDX, IDC_EDIT3, m_e2);
	DDX_Text(pDX, IDC_EDIT4, m_e3);
	DDX_Text(pDX, IDC_EDIT5, m_e4);
	DDX_Text(pDX, IDC_EDIT6, m_e5);
	DDX_CBIndex(pDX, IDC_COMBO1, m_c1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSejieInput, CDialog)
	//{{AFX_MSG_MAP(CSejieInput)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_EN_KILLFOCUS(IDC_EDIT2, OnKillfocusEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT3, OnKillfocusEdit3)
	ON_EN_KILLFOCUS(IDC_EDIT4, OnKillfocusEdit4)
	ON_EN_KILLFOCUS(IDC_EDIT5, OnKillfocusEdit5)
	ON_EN_KILLFOCUS(IDC_EDIT6, OnKillfocusEdit6)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSejieInput message handlers

void CSejieInput::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	CRect rect;
	// 获取绘制坐标的文本框
	CWnd* pWnd = GetDlgItem(IDC_ZHIFANGTU); 
	pWnd->GetClientRect(&rect);
	// 指针
	CDC* pDC = pWnd->GetDC();
	pWnd->Invalidate();
	pWnd->UpdateWindow(); 
	//画外框
	//pDC->Rectangle(&rect); 
	//画直方图
	int i=0;
	if(statPinshu[i]<=statMax){
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.bottom-2-(rect.Height()-3)*statPinshu[i]/statMax);
	}else{
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.top-1);
	}
	for (i=1;i<255;i++){		
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.bottom-2-(rect.Height()-3)*statPinshu[i]/statMax);
	}
	if(statPinshu[i]<=statMax){
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.bottom-2-(rect.Height()-3)*statPinshu[i]/statMax);
	}else{
		pDC->MoveTo(rect.left+i+5,rect.bottom-1);
		pDC->LineTo(rect.left+i+5,rect.top-1);
	}
	CBitmap hkblack,hkwhite,hkgray,jianbian;	
	hkblack.LoadBitmap(IDB_HK1);
	hkwhite.LoadBitmap(IDB_HK2);
	hkgray.LoadBitmap(IDB_HK3);
	jianbian.LoadBitmap(IDB_JIANBIAN1);

	pWnd = GetDlgItem(IDC_HK1); 
	pWnd->GetClientRect(&rect);
	pDC = pWnd->GetDC();
	pWnd->Invalidate();
	pWnd->UpdateWindow();	
	CDC m;
	m.CreateCompatibleDC(NULL);	
	m.SelectObject(&hkblack);
	pDC->BitBlt(rect.left+m_e1,rect.top,hkwid,hkhei,&m,0,0,SRCCOPY);
	m.SelectObject(&hkgray);
	pDC->BitBlt(rect.left+grayPos,rect.top,hkwid,hkhei,&m,0,0,SRCCOPY);
	m.SelectObject(&hkwhite);
	pDC->BitBlt(rect.left+m_e3,rect.top,hkwid,hkhei,&m,0,0,SRCCOPY);
	
	pWnd = GetDlgItem(IDC_HK2); 
	pWnd->GetClientRect(&rect);
	pDC = pWnd->GetDC();
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	m.SelectObject(&jianbian);
	pDC->BitBlt(rect.left+5,rect.top,256,16,&m,0,0,SRCCOPY);
	m.SelectObject(&hkblack);
	pDC->BitBlt(rect.left+m_e4,rect.top+16,hkwid,hkhei,&m,0,0,SRCCOPY);
	m.SelectObject(&hkwhite);
	pDC->BitBlt(rect.left+m_e5,rect.top+16,hkwid,hkhei,&m,0,0,SRCCOPY);
	// Do not call CDialog::OnPaint() for painting messages
}

int CSejieInput::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

BOOL CSejieInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFrameWnd *pFWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pFWnd->GetActiveView();
	pView->statZft(0,statPinshu);//计算原始各明暗度的频数
	int i;
	statMax=1;
	for(i=1;i<255;i++){
		if(statMax<statPinshu[i]){
			statMax=statPinshu[i];
		}
	}
	m_e1=0;
	m_e2=1;
	m_e3=255;
	m_e4=0;
	m_e5=255;
	setGrayPosition();
	m_c1=0;
	

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSejieInput::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(TRUE);
	if(point.x>=14+m_e1 && point.x<14+m_e1+hkwid && point.y>=155 && point.y<155+hkhei && point.x<14+(m_e1+hkwid+m_e3)/2){
		hkDrag=1;
	}else if(point.x>=14+m_e3 && point.x<14+m_e3+hkwid && point.y>=155 && point.y<155+hkhei){
		hkDrag=3;
	}else if(point.x>=14+grayPos && point.x<14+grayPos+hkwid && point.y>=155 && point.y<155+hkhei){
		hkDrag=2;
	}
	if(point.x>=14+m_e4 && point.x<14+m_e4+hkwid && point.y>=252 && point.y<252+hkhei && point.x<14+(m_e4+hkwid+m_e5)/2){
		hkDrag=4;
	}else if(point.x>=14+m_e5 && point.x<14+m_e5+hkwid && point.y>=252 && point.y<252+hkhei){
		hkDrag=5;
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CSejieInput::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pFWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pFWnd->GetActiveView();
	UpdateData(TRUE);
	if(hkDrag!=0){
		pView->SejieFilter(m_e1,m_e2,m_e3,m_e4,m_e5,m_c1);
	}
	hkDrag=0;
	CDialog::OnLButtonUp(nFlags, point);
}

void CSejieInput::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pFWnd; 
	CImageToWordsView *pView;
	if(nFlags==MK_LBUTTON && hkDrag!=0){
		UpdateData(TRUE);
		if(hkDrag==1){
			m_e1=point.x-20;
			if(m_e1<0)m_e1=0;
			else if(m_e1>=m_e3)m_e1=m_e3-1;
		}else if(hkDrag==2){
			grayPos=point.x-20;			
			if(grayPos<=m_e1){grayPos=m_e1+1;}
			else if(grayPos>=m_e3){grayPos=m_e3-1;}	
			getGrayPower();
		}else if(hkDrag==3){
			m_e3=point.x-20;
			if(m_e3>255)m_e3=255;
			else if(m_e3<=m_e1)m_e3=m_e1+1;
		}else if(hkDrag==4 && point.x<m_e5+20 && point.x>=0+20){
			m_e4=point.x-20;
			if(m_e4<0)m_e4=0;
			else if(m_e4>=m_e5)m_e4=m_e5-1;
		}else if(hkDrag==5 && point.x>m_e4+20 && point.x<=255+20){
			m_e5=point.x-20;
			if(m_e5>255)m_e5=255;
			else if(m_e5<=m_e4)m_e5=m_e4+1;
		}
		UpdateData(FALSE);
		if(hkDrag!=2){
			setGrayPosition();
		}
		OnPaint();
		pFWnd =(CFrameWnd*)  AfxGetMainWnd(); 
		pView = (CImageToWordsView*)  pFWnd->GetActiveView();
		if(pView->wid<=1024 && pView->hei<=768){		
			pView->SejieFilter(m_e1,m_e2,m_e3,m_e4,m_e5,m_c1);
		}
	}	
	CDialog::OnMouseMove(nFlags, point);
}

void CSejieInput::setGrayPosition(){
	//UpdateData(TRUE);
	grayPos=m_e1+(int)((m_e3-m_e1)*pow(0.5,m_e2));
}
void CSejieInput::getGrayPower(){
	m_e2=log(((double)grayPos-m_e1)/(m_e3-m_e1))/log(0.5);	
}

void CSejieInput::OnKillfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_e1<0){
		m_e1=0;
	}else if(m_e1>=m_e3){
		m_e1=m_e3-1;
	}
	UpdateData(FALSE);
	setGrayPosition();
	OnPaint();
	CFrameWnd *pFWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pFWnd->GetActiveView();
	pView->SejieFilter(m_e1,m_e2,m_e3,m_e4,m_e5,m_c1);
}

void CSejieInput::OnKillfocusEdit3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_e2<=0){
		m_e2=1;
	}
	UpdateData(FALSE);
	setGrayPosition();
	OnPaint();
	CFrameWnd *pFWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pFWnd->GetActiveView();
	pView->SejieFilter(m_e1,m_e2,m_e3,m_e4,m_e5,m_c1);
}

void CSejieInput::OnKillfocusEdit4() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_e3>255){
		m_e3=255;
	}else if(m_e3<=m_e1){
		m_e3=m_e1+1;
	}
	UpdateData(FALSE);
	setGrayPosition();
	OnPaint();
	CFrameWnd *pFWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pFWnd->GetActiveView();
	pView->SejieFilter(m_e1,m_e2,m_e3,m_e4,m_e5,m_c1);
}

void CSejieInput::OnKillfocusEdit5() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_e4<0){
		m_e4=0;
	}else if(m_e4>=m_e5){
		m_e4=m_e5-1;
	}
	UpdateData(FALSE);
	setGrayPosition();
	OnPaint();
	CFrameWnd *pFWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pFWnd->GetActiveView();
	pView->SejieFilter(m_e1,m_e2,m_e3,m_e4,m_e5,m_c1);
}

void CSejieInput::OnKillfocusEdit6() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_e5<0){
		m_e5=0;
	}else if(m_e5<=m_e4){
		m_e5=m_e4+1;
	}
	UpdateData(FALSE);
	setGrayPosition();
	OnPaint();
	CFrameWnd *pFWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pFWnd->GetActiveView();
	pView->SejieFilter(m_e1,m_e2,m_e3,m_e4,m_e5,m_c1);
}

void CSejieInput::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here

	CFrameWnd *pFWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pFWnd->GetActiveView();
	int m_c1prev=m_c1;
	UpdateData(TRUE);
	if(m_c1prev==0){
			channelBw[0][0]=m_e1;
			channelBw[0][1]=m_e3;
			channelBw[0][2]=m_e4;
			channelBw[0][3]=m_e5;
			channelBw[1][0]=m_e1;
			channelBw[1][1]=m_e3;
			channelBw[1][2]=m_e4;
			channelBw[1][3]=m_e5;
			channelBw[2][0]=m_e1;
			channelBw[2][1]=m_e3;
			channelBw[2][2]=m_e4;
			channelBw[2][3]=m_e5;
			channelGray[0]=m_e2;
			channelGray[1]=m_e2;
			channelGray[2]=m_e2;
	}else{
			channelBw[m_c1prev-1][0]=m_e1;
			channelBw[m_c1prev-1][1]=m_e3;
			channelBw[m_c1prev-1][2]=m_e4;
			channelBw[m_c1prev-1][3]=m_e5;			
			channelGray[m_c1prev-1]=m_e2;
			channelGray[m_c1prev-1]=m_e2;
			channelGray[m_c1prev-1]=m_e2;
	}
	pView->statZft(m_c1,statPinshu);//计算原始各明暗度的频数
	int i=0;
	statMax=1;
	for(i=1;i<255;i++){
		if(statMax<statPinshu[i]){
			statMax=statPinshu[i];
		}
	}
	if(m_c1==0){
		m_e1=0;
		m_e2=1;
		m_e3=255;
		m_e4=0;
		m_e5=255;
	}else{
		m_e1=channelBw[m_c1-1][0];
		m_e2=channelGray[m_c1-1];
		m_e3=channelBw[m_c1-1][1];
		m_e4=channelBw[m_c1-1][2];
		m_e5=channelBw[m_c1-1][3];
	}
	setGrayPosition();
	UpdateData(FALSE);
	OnPaint();
	pView->SejieFilter(m_e1,m_e2,m_e3,m_e4,m_e5,m_c1);
}
