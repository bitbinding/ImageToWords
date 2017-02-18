// WordsTransformInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "WordsTransformInput.h"
#include "ImageToWordsView.h"
#include "WtEditOutput.h"
#include "FontComboBox.h"
#include "CharacterSetInput.h"
//#include <wingdi.h>  
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordsTransformInput dialog


CWordsTransformInput::CWordsTransformInput(CWnd* pParent /*=NULL*/)
	: CDialog(CWordsTransformInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordsTransformInput)
	m_ch1 = FALSE;
	m_ch2 = FALSE;
	m_co1 = 0;
	m_co3 = -1;
	//}}AFX_DATA_INIT
	hei=10;
	fs=20;
	rate=50;
	wid=hei;
	wid2=hei;
	rowspac=hei/10;
	wid2rc=0;
	rowspacrc=2;
	pvdraging=false;
	px0=0,py0=0;
	pxt=0,pyt=0;
	moux0=0,mouy0=0;
}


void CWordsTransformInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordsTransformInput)
	DDX_Control(pDX, IDC_COMBO3, m_co2);
	DDX_Control(pDX, IDC_BUTTON7, m_fi);
	DDX_Control(pDX, IDC_BUTTON6, m_fb);
	DDX_Control(pDX, IDC_STATICpreview, m_lp);
	DDX_Control(pDX, IDC_STATIC13, m_lwsum);
	DDX_Control(pDX, IDC_STATIC12, m_ldk);
	DDX_Control(pDX, IDC_STATIC11, m_l7);
	DDX_Control(pDX, IDC_STATIC10, m_l6);
	DDX_Control(pDX, IDC_STATIC9, m_l5);
	DDX_Control(pDX, IDC_STATIC8, m_l4);
	DDX_Control(pDX, IDC_STATIC7, m_l3);
	DDX_Control(pDX, IDC_STATIC2, m_l2);
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR7, m_s7);
	DDX_Control(pDX, IDC_SCROLLBAR6, m_s6);
	DDX_Control(pDX, IDC_SCROLLBAR5, m_s5);
	DDX_Control(pDX, IDC_SCROLLBAR4, m_s4);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_s3);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_Check(pDX, IDC_CHECK1, m_ch1);
	DDX_Check(pDX, IDC_CHECK2, m_ch2);
	DDX_CBIndex(pDX, IDC_COMBO1, m_co1);
	DDX_CBIndex(pDX, IDC_COMBO4, m_co3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWordsTransformInput, CDialog)
	//{{AFX_MSG_MAP(CWordsTransformInput)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_CBN_SELCHANGE(IDC_COMBO4, OnSelchangeCombo4)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_WM_DELETEITEM()
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordsTransformInput message handlers

BOOL CWordsTransformInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	int i=0;
	CString str;
	hei=10;
	fs=(int)(-pView->wtfont.lfHeight);
	rate=50;
	//wid=hei*(int)(pView->wtfont.lfWidth)/fs;
	wid=hei;
	wid2=wid;
	rowspac=hei/10;
	wid2rc=0;
	rowspacrc=2;

	si1.fMask=SIF_ALL;
    si1.nMax=960;
	si1.nMin=10;
	si1.nPage=1;
	si1.nPos=(int)(hei*10);
	si2.fMask=SIF_ALL;
    si2.nMax=32;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=fs;
	si3.fMask=SIF_ALL;
    si3.nMax=100;
	si3.nMin=0;
	si3.nPage=1;
	si3.nPos=rate;
	si4.fMask=SIF_ALL;
	si4.nMax=960;
	si4.nMin=10;
	si4.nPage=1;
	si4.nPos=(int)(wid2*10);
	si5.fMask=SIF_ALL;
	si5.nMax=960;
	si5.nMin=0;
	si5.nPage=1;
	si5.nPos=(int)(rowspac*10);
	si6.fMask=SIF_ALL;
	si6.nMax=5;
	si6.nMin=0;
	si6.nPage=1;
	si6.nPos=wid2rc;
	si7.fMask=SIF_ALL;
	si7.nMax=10;
	si7.nMin=0;
	si7.nPage=1;
	si7.nPos=rowspacrc;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	m_s3.SetScrollInfo(&si3,true);
	m_s4.SetScrollInfo(&si4,true);
	m_s5.SetScrollInfo(&si5,true);
	m_s6.SetScrollInfo(&si6,true);
	m_s7.SetScrollInfo(&si7,true);

	LOGFONT fflf;
	m_co2.GetFont()->GetLogFont(&fflf);
	fflf.lfHeight=-12;
	cfco.CreateFontIndirect(&fflf); 
	m_co2.SetFont(&cfco);
	GetDlgItem(IDC_COMBO4)->SetFont(&cfco);
	
	m_fb.GetFont()->GetLogFont(&lfb);
	lfb.lfWeight=pView->wtfont.lfWeight>500?700:400;
	cfb.CreateFontIndirect(&lfb);
	m_fb.SetFont(&cfb);

	m_fi.GetFont()->GetLogFont(&lfi);
	lfi.lfItalic=pView->wtfont.lfItalic;
	cfi.CreateFontIndirect(&lfi);
	m_fi.SetFont(&cfi);

	if(pView->firstFontInfo){
		fontFaceEnum.Enumerate(this);
		if(m_co2.Initialize(fontFaceEnum)){
			pView->firstFontInfo=false;
		}
	}else{
		m_co2.Initialize(fontFaceEnum,true);
	}
	str=(LPCTSTR)pView->wtfont.lfFaceName;
	if(i=m_co2.FindString(-1,"等宽="+str),i!=CB_ERR){
		m_co2.SetCurSel(i);
	}else if(i=m_co2.FindString(-1,"比例="+str),i!=CB_ERR){
		m_co2.SetCurSel(i);
	}else if(i=m_co2.FindString(-1,"比例-"+str),i!=CB_ERR){
		m_co2.SetCurSel(i);
	}else if(i=m_co2.FindString(-1,"等宽-"+str),i!=CB_ERR){
		m_co2.SetCurSel(i);
	}else{
		m_co2.SetWindowText(str+"（未找到！）");
	}
	m_co3=3;
	
	UpdateData(FALSE);
	getWid();
	m_s4.SetScrollPos((int)(wid*10));
	if(pView->getPchEn("l",pView->pchsetLeng)==pView->getPchEn("m",pView->pchsetLeng)){
		m_ldk.SetWindowText("等宽");
	}else{
		m_ldk.SetWindowText("非等宽");
	}
	getWid();
	UpdateData(TRUE);
	//获得预览窗矩形
	GetDlgItem(IDC_STATICpreview)->GetWindowRect(&m_preview_rect);	
	ScreenToClient(&m_preview_rect);
	m_preview_rect.right-=4;
	m_preview_rect.bottom-=4;
	
	int rw=m_preview_rect.right-m_preview_rect.left;//预览框宽度
	int rh=m_preview_rect.bottom-m_preview_rect.top;//预览框高度
	preReco.Create(rw,rh,24);
	
	updateText(true);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWordsTransformInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	int stepl=1;
	int stepp=(pScrollBar==&m_s2 || pScrollBar==&m_s6 || pScrollBar==&m_s7)?1:5;
	if(pScrollBar==&m_s1){
		wid=hei;
	}
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
	UpdateData(TRUE);
	if(pScrollBar==&m_s1){
		//wid=m_s1.GetScrollPos()*(pView->wtfont.lfWidth)/fs;
		getWid();
		m_s2.SetScrollPos((int)(hei+0.5));
		m_s4.SetScrollPos((int)(wid*10));
		m_s5.SetScrollPos(m_s1.GetScrollPos()/10);
	}
	if(nSBCode!=SB_THUMBTRACK && (pScrollBar==&m_s1 || pScrollBar==&m_s2 || pScrollBar==&m_s4 || pScrollBar==&m_s5 || pScrollBar==&m_s6 || pScrollBar==&m_s7)){
		updateText(true);
	}else{
		updateText(false);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
void CWordsTransformInput::updateText(bool drawable){
	CString str="";

	hei=m_s1.GetScrollPos()/10.0f;
	fs=m_s2.GetScrollPos();
	rate=m_s3.GetScrollPos();
	wid2=m_s4.GetScrollPos()/10.0f;
	rowspac=m_s5.GetScrollPos()/10.0f;
	wid2rc=m_s6.GetScrollPos();
	rowspacrc=m_s7.GetScrollPos();
	str.Format("高度(%.1f)",hei);
	m_l1.SetWindowText(str);
	str.Format("字号(%d)",fs);
	m_l2.SetWindowText(str);
	str.Format("亮度(%d%%)",rate);
	m_l3.SetWindowText(str);
	str.Format("宽度(%.1f)",wid2);
	m_l4.SetWindowText(str);
	str.Format("行距(%.1f)",rowspac);
	m_l5.SetWindowText(str);
	str.Format("间距容差(%d)",wid2rc);
	m_l6.SetWindowText(str);
	str.Format("行距容差(%d)",rowspacrc);
	m_l7.SetWindowText(str);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd();
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->wtfont.lfHeight=-fs;
	float sett[10]={hei,fs,rate,wid2,rowspac,wid2rc,rowspacrc,wid};
	CRect rect;
	rect.left=0;
	rect.top=0;
	rect.right=(pView->wid)-1;
	rect.bottom=(pView->hei)-1;
	if(drawable){
		pView->wtPreDraw(sett,rect,0);
	}
	OnPaint();
}

void CWordsTransformInput::OnButton1() 
{
	// TODO: Add your control notification handler code here

}

void CWordsTransformInput::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	CFontDialog dlg(&(pView->wtfont),CF_EFFECTS|   CF_SCREENFONTS,NULL,NULL);
	int i;
	CString str;
	UpdateData(TRUE);
	if(dlg.DoModal()==IDOK){
		dlg.GetCurrentFont(&(pView->wtfont));
		if(pView->wtfont.lfHeight>0){
			pView->wtfont.lfHeight=-pView->wtfont.lfHeight;
		}
		if(pView->wtfont.lfHeight<-32){
			pView->wtfont.lfHeight=-32;
		}else if(pView->wtfont.lfHeight==0){
			pView->wtfont.lfHeight=-1;
		}
		m_s2.SetScrollPos((int)(-pView->wtfont.lfHeight));
		str=(LPCTSTR)pView->wtfont.lfFaceName;
		if(i=m_co2.FindString(-1,"等宽="+str),i!=CB_ERR){
			m_co2.SetCurSel(i);
		}else if(i=m_co2.FindString(-1,"比例="+str),i!=CB_ERR){
			m_co2.SetCurSel(i);
		}else if(i=m_co2.FindString(-1,"比例-"+str),i!=CB_ERR){
			m_co2.SetCurSel(i);
		}else if(i=m_co2.FindString(-1,"等宽-"+str),i!=CB_ERR){
			m_co2.SetCurSel(i);
		}else{
			m_co2.SetWindowText(str+"（未找到！）");
		}
		
		//cf=m_fb.GetFont();
		//cf->GetLogFont(&lfb);
		lfb.lfWeight=pView->wtfont.lfWeight>500?700:400;
		cfb.DeleteObject();
		cfb.CreateFontIndirect(&lfb);
		m_fb.SetFont(&cfb);

		//cf=m_fi.GetFont();
		//cf->GetLogFont(&lfi);
		lfi.lfItalic=pView->wtfont.lfItalic;
		cfi.DeleteObject();
		cfi.CreateFontIndirect(&lfi);
		m_fi.SetFont(&cfi);
		//wid=hei*(pView->wtfont.lfWidth)/fs;
		if(pView->getPchEn("l",pView->pchsetLeng)==pView->getPchEn("m",pView->pchsetLeng)){
			m_ldk.SetWindowText("等宽");
		}else{
			m_ldk.SetWindowText("非等宽");
		}
		getWid();
		m_s4.SetScrollPos((int)(wid*10));

		updateText(true);
	}
}

void CWordsTransformInput::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	//CFontDialog dlg(&(pView->wtfont),CF_EFFECTS|   CF_SCREENFONTS,NULL,NULL);
	// 获取绘制坐标的文本框
	CWnd* pWnd = GetDlgItem(IDC_STATICpreview);
	// 指针
	CDC* pDC = pWnd->GetDC();
	pWnd->Invalidate(FALSE);
	pWnd->UpdateWindow();
	//选择字体
	CFont cf;
	cf.CreateFontIndirect(&(pView->wtfont));
	pDC->SelectObject(&cf);
	int i=0,j=0,k=0;//循环变量
	CString str="";
	int rw=m_preview_rect.right-m_preview_rect.left;//预览框宽度
	int rh=m_preview_rect.bottom-m_preview_rect.top;//预览框高度
	pView->m_Image.BitBlt(pDC->m_hDC,0,0,rw,rh,px0,py0);

	BYTE *pbyte;
	CImage pchimg;
	pchimg.Create(32,32,24);
	pView->getPchCh("说");
	UINT *p1=pView->pchset[pView->pchsetLeng];
	
	
	UINT p2[32];
	pView->getPchPic(p2,hei,fs,wid,px0,py0);
	for(i=0;i<32;i++){
		for(j=0;j<32;j++){
			pbyte=(BYTE *)pchimg.GetPixelAddress(j,i);
			if(((p1[i]>>j)&1) && ((p2[i]>>j)&1)){
				pbyte[2]=0;
				pbyte[1]=0;
				pbyte[0]=0;
			}else if((p1[i]>>j)&1){
				pbyte[2]=0;
				pbyte[1]=0;
				pbyte[0]=255;
			}else if((p2[i]>>j)&1){
				pbyte[2]=0;
				pbyte[1]=127;
				pbyte[0]=0;
			}else{
				pbyte[2]=255;
				pbyte[1]=255;
				pbyte[0]=255;
			}
		}
	}
	pchimg.BitBlt(pDC->m_hDC,0,0,32,32,0,0);
	//m_lp.SetWindowText("");
	//preReco.Draw(pDC->m_hDC,0,0);
	pchimg.Destroy();
	ReleaseDC(pDC);
	



		
	// Do not call CDialog::OnPaint() for painting messages
}
FIXED CWordsTransformInput::FixedFromDouble(double d){
    long l;
    l = (long) (d * 65536L);
    return *(FIXED *)&l;
}
void CWordsTransformInput::SetMat(LPMAT2 lpMat){
	lpMat->eM11 = FixedFromDouble(2);
	lpMat->eM12 = FixedFromDouble(0);
	lpMat->eM21 = FixedFromDouble(0);
	lpMat->eM22 = FixedFromDouble(2);
}

void CWordsTransformInput::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (point.x>(m_preview_rect.left) && point.x<(m_preview_rect.right) && point.y>(m_preview_rect.top) && point.y<(m_preview_rect.bottom)){
		pvdraging=true;
		moux0=point.x;
		mouy0=point.y;
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CWordsTransformInput::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	HCURSOR hcursor;
	if (nFlags==0 && nFlags==point.x>(m_preview_rect.left) && point.x<(m_preview_rect.right) && point.y>(m_preview_rect.top) && point.y<(m_preview_rect.bottom)){
		hcursor = LoadCursor(NULL,IDC_ARROW);
		SetCursor(hcursor);
	}else if(!pvdraging){
		hcursor = LoadCursor(NULL,IDC_ARROW);
		SetCursor(hcursor);
	}else if(nFlags==MK_LBUTTON){
		hcursor = LoadCursor(NULL,IDC_SIZEALL);
		SetCursor(hcursor);
		CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
		CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
		int rw=m_preview_rect.right-m_preview_rect.left;//预览框宽度
		int rh=m_preview_rect.bottom-m_preview_rect.top;//预览框高度
		if(rw<pView->wid){
			pxt=moux0-point.x+px0;
			if(pxt<0)pxt=0;
			if(pxt+rw>=pView->wid)pxt=pView->wid-rw-1;
		}
		if(rh<pView->hei){
			pyt=mouy0-point.y+py0;
			if(pyt<0)pyt=0;
			if(pyt+rh>=pView->hei)pyt=pView->hei-rh-1;
		}
		// 获取绘制坐标的文本框
		CWnd* pWnd = GetDlgItem(IDC_STATICpreview);
		// 指针
		CDC* pDC = pWnd->GetDC();
		pWnd->Invalidate(FALSE);
		pWnd->UpdateWindow();
		pView->m_Image.BitBlt(pDC->m_hDC,0,0,rw,rh,pxt,pyt);
		ReleaseDC(pDC);
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CWordsTransformInput::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(pvdraging){
		pvdraging=false;
		px0=pxt;
		py0=pyt;
		OnPaint();
	}
	CDialog::OnLButtonUp(nFlags, point);
}

void CWordsTransformInput::OnSelchangeCombo4() 
{
	// TODO: Add your control notification handler code here
	getWid();
	m_s4.SetScrollPos((int)(wid*10));
	updateText(true);
}
void CWordsTransformInput::getWid(){
	CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	UpdateData(TRUE);
	pView->wtfont.lfHeight=-m_s2.GetScrollPos();
	if(-pView->wtfont.lfHeight>=12){
		if(m_co3<=2){
			wid=pView->getPchEn("1",pView->pchsetLeng)*hei/fs;
		}else{
			wid=pView->getPchEn("囊",pView->pchsetLeng)*hei/fs;
		}
	}else{
		if(m_co3<=2){
			wid=hei/2;
		}else{
			wid=hei*21/20;
		}
	}
}

void CWordsTransformInput::OnButton10() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CWtEditOutput dlg((int)hei,rate,m_co3);
	dlg.DoModal();
}

void CWordsTransformInput::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	UpdateData(TRUE);
	//CString str;
	char pChar[129];
	/*if(m_co2==0){
		str="Times New Roman";
		strcpy(pView->wtfont.lfFaceName,(LPTSTR)(LPCTSTR)str);
		m_co3=0;
	}
	if(m_co2==1){
		str="宋体";
		strcpy(pView->wtfont.lfFaceName,(LPTSTR)(LPCTSTR)str);
		m_co3=3;
	}
	if(pView->getPchEn("l",pView->pchsetLeng)==pView->getPchEn("m",pView->pchsetLeng)){
		m_ldk.SetWindowText("等宽");
	}else{
		m_ldk.SetWindowText("非等宽");
	}*/
	m_co2.GetWindowText(pChar,128);
	if(strlen(pChar)>=5){
		m_ldk.SetWindowText((LPCTSTR)(pChar+5));
		strcpy(pView->wtfont.lfFaceName,(pChar+5));
	}else{
		MessageBox("字体名称长度异常");
	}
	UpdateData(FALSE);
	getWid();
	m_s4.SetScrollPos((int)(wid*10));
	updateText(true);
}

void CWordsTransformInput::OnButton11() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CWordsTransformInput::OnButton6() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	if(pView->wtfont.lfWeight>500){
		pView->wtfont.lfWeight=400;
	}else{
		pView->wtfont.lfWeight=700;
	}

	//cf=m_fb.GetFont();
	//cf->GetLogFont(&lfb);
	lfb.lfWeight=pView->wtfont.lfWeight>500?700:400;
	cfb.DeleteObject();
	cfb.CreateFontIndirect(&lfb);
	m_fb.SetFont(&cfb);
	
	//cf=m_fi.GetFont();
	//cf->GetLogFont(&lfi);
	lfi.lfItalic=pView->wtfont.lfItalic;
	cfi.DeleteObject();
	cfi.CreateFontIndirect(&lfi);
	m_fi.SetFont(&cfi);
}

void CWordsTransformInput::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	if(pView->wtfont.lfItalic==TRUE){
		pView->wtfont.lfItalic=FALSE;
	}else{
		pView->wtfont.lfItalic=TRUE;
	}
	//cf=m_fb.GetFont();
	//cf->GetLogFont(&lfb);
	lfb.lfWeight=pView->wtfont.lfWeight>500?700:400;
	cfb.DeleteObject();
	cfb.CreateFontIndirect(&lfb);	
	m_fb.SetFont(&cfb);

	//cf=m_fi.GetFont();
	//cf->GetLogFont(&lfi);
	lfi.lfItalic=pView->wtfont.lfItalic;
	cfi.DeleteObject();
	cfi.CreateFontIndirect(&lfi);
	m_fi.SetFont(&cfi);
	
}




void CWordsTransformInput::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CCharacterSetInput dlg;
	dlg.DoModal();
}
