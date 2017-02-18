// ScaleInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "ScaleInput.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScaleInput dialog


CScaleInput::CScaleInput(CWnd* pParent /*=NULL*/)
	: CDialog(CScaleInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScaleInput)
	m_c1 = -1;
	m_ew0 = 0;
	m_eh0 = 0;
	m_e1 = 1;
	m_e2 = 1;
	m_ch1 = FALSE;
	m_c2 = -1;
	//}}AFX_DATA_INIT
}


void CScaleInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScaleInput)
	DDX_CBIndex(pDX, IDC_COMBO1, m_c1);
	DDX_Text(pDX, IDC_EDIT1, m_ew0);
	DDX_Text(pDX, IDC_EDIT7, m_eh0);
	DDX_Text(pDX, IDC_EDIT8, m_e1);
	DDV_MinMaxInt(pDX, m_e1, 1, 46340);
	DDX_Text(pDX, IDC_EDIT9, m_e2);
	DDV_MinMaxInt(pDX, m_e2, 1, 32767);
	DDX_Check(pDX, IDC_CHECK2, m_ch1);
	DDX_CBIndex(pDX, IDC_COMBO6, m_c2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScaleInput, CDialog)
	//{{AFX_MSG_MAP(CScaleInput)
	ON_EN_CHANGE(IDC_EDIT8, OnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT9, OnChangeEdit9)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO6, OnSelchangeCombo6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScaleInput message handlers

BOOL CScaleInput::OnInitDialog() 
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
	m_c1=1;
	m_c2=4;
	//m_ch1=1;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CScaleInput::OnChangeEdit8() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_ch1==1 && m_e1!=0 && m_e1<46340){
		m_e2=(int)((float)m_eh0*m_e1/m_ew0+0.5f);		
		if(m_e2<=0){
			m_e2=1;
		}else if(m_e2>=32767){
			m_e2=32766;
		}
	}
	if(m_e1!=0 && m_e1<46340 && m_e2!=0 && m_e2<32767){
		pView->ScaleFilter(m_e1,m_e2,m_c2,m_c1);
		UpdateData(FALSE);		
	}else{
		UpdateData(FALSE);	
		UpdateData(TRUE);
	}
	
	//UpdateData(TRUE);
}

void CScaleInput::OnChangeEdit9() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_ch1==1 && m_e2!=0 && m_e2<32767){
		m_e1=(int)((float)m_ew0*m_e2/m_eh0+0.5f);
		if(m_e1<=0){
			m_e1=1;
		}else if(m_e1>=46340){
			m_e1=46339;
		}
	}
	if(m_e1!=0 && m_e1<46340 && m_e2!=0 && m_e2<32767){
		pView->ScaleFilter(m_e1,m_e2,m_c2,m_c1);
		UpdateData(FALSE);
	}else{
		UpdateData(FALSE);
		UpdateData(TRUE);
	}	
	//UpdateData(TRUE);
}

void CScaleInput::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_c1==0){		
		GetDlgItem(IDC_COMBO6)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO6)->EnableWindow(TRUE);
	}else{
		GetDlgItem(IDC_COMBO6)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO6)->EnableWindow(FALSE);
	}
	if(m_e1!=0 && m_e1<46340 && m_e2!=0 && m_e2<32767){
		
		pView->ScaleFilter(m_e1,m_e2,m_c2,m_c1);
	}
}

void CScaleInput::OnSelchangeCombo6() 
{
	// TODO: Add your control notification handler code here
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	UpdateData(TRUE);
	if(m_e1!=0 && m_e1<46340 && m_e2!=0 && m_e2<32767){		
		pView->ScaleFilter(m_e1,m_e2,m_c2,m_c1);
	}
}
