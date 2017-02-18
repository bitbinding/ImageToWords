// WtEditOutput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "WtEditOutput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWtEditOutput dialog


CWtEditOutput::CWtEditOutput(CWnd* pParent /*=NULL*/)
	: CDialog(CWtEditOutput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWtEditOutput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	forTransform=false;
	
}
CWtEditOutput::CWtEditOutput(int gridhei0,int rate0,int ziji0,CWnd* pParent /*=NULL*/)
	: CDialog(CWtEditOutput::IDD, pParent){
	gridhei=gridhei0;
	rate=rate0;
	ziji=ziji0;
	forTransform=true;
	
}


void CWtEditOutput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWtEditOutput)
	DDX_Control(pDX, IDC_STATIC1, m_s1);
	DDX_Control(pDX, IDC_EDIT1, m_eresult);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWtEditOutput, CDialog)
	//{{AFX_MSG_MAP(CWtEditOutput)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_EN_UPDATE(IDC_EDIT1, OnUpdateEdit1)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWtEditOutput message handlers

HBRUSH CWtEditOutput::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	// TODO: Change any attributes of the DC here
	 if (pWnd->GetDlgCtrlID() == IDC_EDIT1) {
		pDC->SetTextColor(RGB(0,0,255));
		
	}
	 
 	  //CFont cf;
	  //cf.CreateFontIndirect(&(pView->wtfont));
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CWtEditOutput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	CFontDialog fdlg;
	fdlg.GetCurrentFont(&lf);	
	if(forTransform){
		lf.lfCharSet=pView->wtfont.lfCharSet;
		lf.lfClipPrecision=pView->wtfont.lfClipPrecision;
		lf.lfEscapement=pView->wtfont.lfEscapement;
		strcpy(lf.lfFaceName,pView->wtfont.lfFaceName);
		lf.lfHeight=(int)(-gridhei);
		lf.lfItalic=pView->wtfont.lfItalic;
		lf.lfOrientation=pView->wtfont.lfOrientation;
		lf.lfOutPrecision=pView->wtfont.lfOutPrecision;
		lf.lfPitchAndFamily=pView->wtfont.lfPitchAndFamily;
		lf.lfQuality=pView->wtfont.lfQuality;
		lf.lfStrikeOut=pView->wtfont.lfStrikeOut;
		lf.lfUnderline=pView->wtfont.lfUnderline;
		lf.lfWeight=pView->wtfont.lfWeight;
		lf.lfWidth=pView->wtfont.lfWidth;
		cc=2;
		cr=0;
		words=pView->getPchs(ziji);
		SetTimer(1,0,NULL);		
		//int i,j;
	}
	CFont *cf=new CFont;
	cf->CreateFontIndirect(&lf);
	m_eresult.SetFont(cf);
	GetClientRect(&m_rect0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWtEditOutput::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(forTransform){
		CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
		CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
		CString result="";
		if(cr>=pView->wordGridLengr){
			KillTimer(1);
		}
		/*if(cc>=pView->wordGrid[cr][1]-1){
			cc=2;
			cr++;
			m_eresult.GetWindowText(result);
			result+="\r\n";
			m_eresult.SetWindowText(result);
		}
		if(cr>=pView->wordGridLengr){
			KillTimer(1);
		}
		m_eresult.GetWindowText(result);
		result+=pView->identifyGrid(ziji,words,cc,cr,gridhei,rate);
		m_eresult.SetWindowText(result);
		cc++;*/
		int i;
		m_eresult.GetWindowText(result);
		for(i=2;i<pView->wordGrid[cr][1]-1;i++){
			result+=pView->identifyGrid(ziji,words,i,cr,gridhei,rate);
		}
		result+="\r\n";
		m_eresult.SetWindowText(result);
		cr++;
	}
	CDialog::OnTimer(nIDEvent);
}

void CWtEditOutput::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	 CWnd *pWnd,*pWnd2;
	 int centx,btnw,btnh;
    pWnd = GetDlgItem(IDC_EDIT1);     //获取控件句柄
	pWnd2 = GetDlgItem(IDC_BUTTON9);
    if(nType==1) return;   //如果是窗体最小化则什么都不做
    if(pWnd && pWnd2)//判断是否为空，因为对话框创建时会调用此函数，而当时控件还未创建
    {
      CRect rect,rect2;   //获取控件变化前大小
      pWnd->GetWindowRect(&rect);
	  pWnd2->GetWindowRect(&rect2);
      ScreenToClient(&rect);//将控件大小转换为在对话框中的区域坐标
	ScreenToClient(&rect2);
	centx=cx/2;
      btnw=rect2.Width();
	  btnh=rect2.Height();

      rect.right=cx-10;
      rect.bottom=cy-btnh-15-64;	
	pWnd->MoveWindow(rect);//设置控件大小

	pWnd = GetDlgItem(IDC_STATIC1);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	rect.right=cx-10;
	rect.top=cy-btnh-15-64;
    rect.bottom=cy-btnh-15;
	  
		rect2.bottom=cy-7;
		rect2.top=cy-7-btnh;
		rect2.right=centx-9-btnw;
		rect2.left=centx-9-2*btnw;

		
      pWnd->MoveWindow(rect);
		pWnd2->MoveWindow(rect2);

		pWnd2 = GetDlgItem(IDC_BUTTON2);
		pWnd2->GetWindowRect(&rect2);
		ScreenToClient(&rect2);
		rect2.bottom=cy-7;
		rect2.top=cy-7-btnh;
		rect2.right=centx-3;
		rect2.left=centx-3-btnw;
		pWnd2->MoveWindow(rect2);

		pWnd2 = GetDlgItem(IDC_BUTTON1);
		pWnd2->GetWindowRect(&rect2);
		ScreenToClient(&rect2);
		rect2.bottom=cy-7;
		rect2.top=cy-7-btnh;
		rect2.right=centx+3+btnw;
		rect2.left=centx+3;
		pWnd2->MoveWindow(rect2);

		pWnd2 = GetDlgItem(IDOK);
		pWnd2->GetWindowRect(&rect2);
		ScreenToClient(&rect2);
		rect2.bottom=cy-7;
		rect2.top=cy-7-btnh;
		rect2.right=centx+9+2*btnw;
		rect2.left=centx+9+btnw;		
		pWnd2->MoveWindow(rect2);
		rect.left=0;
		rect.right=cx;
		rect.bottom=cy;
		rect.top=cy-btnh-15;
		InvalidateRect(rect);
    }
    GetClientRect(&m_rect0);
	
}

void CWtEditOutput::OnUpdateEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	
}

void CWtEditOutput::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CPoint Point = m_eresult.GetCaretPos();
	int n = m_eresult.CharFromPos(Point);
	int nLineIndex = HIWORD(n);
	int nCharIndex = LOWORD(n);
	int nLineBeg = m_eresult.LineIndex();
	CString str="";
	str.Format(_T("Line = %d, Column = %d\r\n"), nLineIndex, nCharIndex - nLineBeg);//行号列号
	int col=nCharIndex - nLineBeg;

	char char2[50];
	m_eresult.GetLine(nLineIndex,char2,50);
	CString str2=char2;
	if(col<1){
		col=1;
	}
	if(col>str2.GetLength()-2){
		col=str2.GetLength()-2;
	}
	
	//str2[col]='\0';
	str+=str2[col-1];
	m_s1.SetWindowText(str);
	/*CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
	//CFontDialog dlg(&(pView->wtfont),CF_EFFECTS|   CF_SCREENFONTS,NULL,NULL);
	// 获取绘制坐标的文本框
	CWnd* pWnd = GetDlgItem(IDC_STATIC1);
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
	ReleaseDC(pDC);*/
}
