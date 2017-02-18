// TrimInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "TrimInput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrimInput dialog


CTrimInput::CTrimInput(CWnd* pParent /*=NULL*/)
	: CDialog(CTrimInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrimInput)
	m_ew0 = 0;
	m_eh0 = 0;
	m_e1 = 1;
	m_e2 = 1;
	m_c1 = FALSE;
	m_c2 = -1;
	m_e3 = 0;
	m_e4 = 0;
	m_c3 = FALSE;
	//}}AFX_DATA_INIT
	bgc=RGB(255,255,255);
}


void CTrimInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrimInput)
	DDX_Text(pDX, IDC_EDIT1, m_ew0);
	DDX_Text(pDX, IDC_EDIT7, m_eh0);
	DDX_Text(pDX, IDC_EDIT8, m_e1);
	DDV_MinMaxInt(pDX, m_e1, 1, 46340);
	DDX_Text(pDX, IDC_EDIT9, m_e2);
	DDV_MinMaxInt(pDX, m_e2, 1, 32767);
	DDX_Check(pDX, IDC_CHECK2, m_c1);
	DDX_CBIndex(pDX, IDC_COMBO6, m_c2);
	DDX_Text(pDX, IDC_EDIT10, m_e3);
	DDX_Text(pDX, IDC_EDIT11, m_e4);
	DDX_Check(pDX, IDC_CHECK1, m_c3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTrimInput, CDialog)
	//{{AFX_MSG_MAP(CTrimInput)
	ON_EN_CHANGE(IDC_EDIT8, OnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT9, OnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT10, OnChangeEdit10)
	ON_EN_CHANGE(IDC_EDIT11, OnChangeEdit11)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_CBN_SELCHANGE(IDC_COMBO6, OnSelchangeCombo6)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrimInput message handlers

BOOL CTrimInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	//UpdateData(TRUE);
	m_ew0=pView->wid;
	m_eh0=pView->hei;
	m_e1=pView->wid;
	m_e2=pView->hei;
	m_c2=0;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTrimInput::OnChangeEdit8() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_c1==1 && m_e1!=0 && m_e1<46340){
		m_e2=(int)((float)m_eh0*m_e1/m_ew0+0.5f);
		if(m_e2<=0){
			m_e2=1;
		}else if(m_e2>=32767){
			m_e2=32766;
		}
	}	
	if(m_e1!=0 && m_e1<46340 && m_e2!=0 && m_e2<32767){
		switch(m_c2){
			case 1:
				m_e3=0;
				m_e4=0;
				break;
			case 2:
				m_e3=(m_e1*2+1)/4-((pView->wid)*2+1)/4;
				m_e4=0;
				break;
			case 3:
				m_e3=m_e1-(pView->wid);
				m_e4=0;
				break;
			case 4:
				m_e3=0;
				m_e4=(m_e2*2+1)/4-((pView->hei)*2+1)/4;
				break;
			case 5:
				m_e3=(m_e1*2+1)/4-((pView->wid)*2+1)/4;
				m_e4=(m_e2*2+1)/4-((pView->hei)*2+1)/4;
				break;
			case 6:
				m_e3=m_e1-(pView->wid);
				m_e4=(m_e2*2+1)/4-((pView->hei)*2+1)/4;
				break;
			case 7:
				m_e3=0;
				m_e4=m_e2-(pView->hei);
				break;
			case 8:
				m_e3=(m_e1*2+1)/4-((pView->wid)*2+1)/4;
				m_e4=m_e2-(pView->hei);
				break;
			case 9:
				m_e3=m_e1-(pView->wid);
				m_e4=m_e2-(pView->hei);
				break;
			default:
				break;
		}
		pView->TrimFilter(m_e1,m_e2,m_e3,m_e4,bgc,m_c3==TRUE);
		UpdateData(FALSE);		
	}else{
		UpdateData(FALSE);	
		UpdateData(TRUE);
	}
	//UpdateData(TRUE);
}

void CTrimInput::OnChangeEdit9() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_c1==1 && m_e2!=0 && m_e2<32767){
		m_e1=(int)((float)m_ew0*m_e2/m_eh0+0.5f);
		if(m_e1<=0){
			m_e1=1;
		}else if(m_e1>=46340){
			m_e1=46339;
		}
	}
	if(m_e1!=0 && m_e1<46340 && m_e2!=0 && m_e2<32767){
		switch(m_c2){
			case 1:
				m_e3=0;
				m_e4=0;
				break;
			case 2:
				m_e3=(m_e1*2+1)/4-((pView->wid)*2+1)/4;
				m_e4=0;
				break;
			case 3:
				m_e3=m_e1-(pView->wid);
				m_e4=0;
				break;
			case 4:
				m_e3=0;
				m_e4=(m_e2*2+1)/4-((pView->hei)*2+1)/4;
				break;
			case 5:
				m_e3=(m_e1*2+1)/4-((pView->wid)*2+1)/4;
				m_e4=(m_e2*2+1)/4-((pView->hei)*2+1)/4;
				break;
			case 6:
				m_e3=m_e1-(pView->wid);
				m_e4=(m_e2*2+1)/4-((pView->hei)*2+1)/4;
				break;
			case 7:
				m_e3=0;
				m_e4=m_e2-(pView->hei);
				break;
			case 8:
				m_e3=(m_e1*2+1)/4-((pView->wid)*2+1)/4;
				m_e4=m_e2-(pView->hei);
				break;
			case 9:
				m_e3=m_e1-(pView->wid);
				m_e4=m_e2-(pView->hei);
				break;
			default:
				break;
		}
		pView->TrimFilter(m_e1,m_e2,m_e3,m_e4,bgc,m_c3==TRUE);
		UpdateData(FALSE);		
	}else{
		UpdateData(FALSE);	
		UpdateData(TRUE);
	}
	//UpdateData(TRUE);
}

void CTrimInput::OnChangeEdit10() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	CString str;
	GetDlgItemText(IDC_EDIT10,str);
	if(str!="-"){
		UpdateData(TRUE);
		if(m_c2==0){pView->TrimFilter(m_e1,m_e2,m_e3,m_e4,bgc,m_c3==TRUE);}
	}
}

void CTrimInput::OnChangeEdit11() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();	
	CString str;
	GetDlgItemText(IDC_EDIT11,str);
	if(str!="-"){
		UpdateData(TRUE);
		if(m_c2==0){pView->TrimFilter(m_e1,m_e2,m_e3,m_e4,bgc,m_c3==TRUE);}
	}
}

void CTrimInput::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg(bgc,CC_FULLOPEN);
	if(dlg.DoModal()==IDOK){
		bgc=dlg.GetColor();
	}
}

void CTrimInput::OnSelchangeCombo6() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);	
	if(m_c2>0){
		GetDlgItem(IDC_EDIT10)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT11)->EnableWindow(FALSE);
	}else{
		GetDlgItem(IDC_EDIT10)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT11)->EnableWindow(TRUE);
	}
	switch(m_c2){
		case 1:
			m_e3=0;
			m_e4=0;
			break;
		case 2:
			m_e3=(m_e1*2+1)/4-((pView->wid)*2+1)/4;
			m_e4=0;
			break;
		case 3:
			m_e3=m_e1-(pView->wid);
			m_e4=0;
			break;
		case 4:
			m_e3=0;
			m_e4=(m_e2*2+1)/4-((pView->hei)*2+1)/4;
			break;
		case 5:
			m_e3=(m_e1*2+1)/4-((pView->wid)*2+1)/4;
			m_e4=(m_e2*2+1)/4-((pView->hei)*2+1)/4;
			break;
		case 6:
			m_e3=m_e1-(pView->wid);
			m_e4=(m_e2*2+1)/4-((pView->hei)*2+1)/4;
			break;
		case 7:
			m_e3=0;
			m_e4=m_e2-(pView->hei);
			break;
		case 8:
			m_e3=(m_e1*2+1)/4-((pView->wid)*2+1)/4;
			m_e4=m_e2-(pView->hei);
			break;
		case 9:
			m_e3=m_e1-(pView->wid);
			m_e4=m_e2-(pView->hei);
			break;
		default:
			break;
	}
	pView->TrimFilter(m_e1,m_e2,m_e3,m_e4,bgc,m_c3==TRUE);
	UpdateData(FALSE);
	//UpdateData(TRUE);
}

void CTrimInput::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	pView->TrimFilter(m_e1,m_e2,m_e3,m_e4,bgc,m_c3==TRUE);	
}
