// Zidingyilvjing.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "Zidingyilvjing.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZidingyilvjing dialog


CZidingyilvjing::CZidingyilvjing(CWnd* pParent /*=NULL*/)
	: CDialog(CZidingyilvjing::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZidingyilvjing)
	m_e1 = 0.0f;
	m_e2 = 0.0f;
	m_e3 = 0.0f;
	m_e4 = 0.0f;
	m_e5 = 0.0f;
	m_e6 = 0.0f;
	m_e7 = 0.0f;
	m_e8 = 0.0f;
	m_e9 = 0.0f;
	m_e10 = 0.0f;
	m_e11 = 0.0f;
	m_e12 = 0.0f;
	m_e13 = 0.0f;
	m_e14 = 0.0f;
	m_e16 = 0.0f;
	m_e17 = 0.0f;
	m_e18 = 0.0f;
	m_e19 = 0.0f;
	m_e20 = 0.0f;
	m_e21 = 0.0f;
	m_e22 = 0.0f;
	m_e23 = 0.0f;
	m_e24 = 0.0f;
	m_e25 = 0.0f;
	m_c1 = -1;
	m_c2 = _T("");
	m_e15 = 0.0f;
	m_ejs = 0;
	m_esf = 0.0f;
	m_ewy = 0.0f;
	//}}AFX_DATA_INIT
}


void CZidingyilvjing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZidingyilvjing)
	DDX_Control(pDX, IDC_SPIN3, m_sp1);
	DDX_Text(pDX, IDC_EDIT1, m_e1);
	DDX_Text(pDX, IDC_EDIT7, m_e2);
	DDX_Text(pDX, IDC_EDIT8, m_e3);
	DDX_Text(pDX, IDC_EDIT9, m_e4);
	DDX_Text(pDX, IDC_EDIT10, m_e5);
	DDX_Text(pDX, IDC_EDIT11, m_e6);
	DDX_Text(pDX, IDC_EDIT12, m_e7);
	DDX_Text(pDX, IDC_EDIT13, m_e8);
	DDX_Text(pDX, IDC_EDIT14, m_e9);
	DDX_Text(pDX, IDC_EDIT15, m_e10);
	DDX_Text(pDX, IDC_EDIT16, m_e11);
	DDX_Text(pDX, IDC_EDIT17, m_e12);
	DDX_Text(pDX, IDC_EDIT18, m_e13);
	DDX_Text(pDX, IDC_EDIT19, m_e14);
	DDX_Text(pDX, IDC_EDIT21, m_e16);
	DDX_Text(pDX, IDC_EDIT22, m_e17);
	DDX_Text(pDX, IDC_EDIT23, m_e18);
	DDX_Text(pDX, IDC_EDIT24, m_e19);
	DDX_Text(pDX, IDC_EDIT25, m_e20);
	DDX_Text(pDX, IDC_EDIT26, m_e21);
	DDX_Text(pDX, IDC_EDIT27, m_e22);
	DDX_Text(pDX, IDC_EDIT28, m_e23);
	DDX_Text(pDX, IDC_EDIT29, m_e24);
	DDX_Text(pDX, IDC_EDIT30, m_e25);
	DDX_CBIndex(pDX, IDC_COMBO2, m_c1);
	DDX_CBString(pDX, IDC_COMBO3, m_c2);
	DDX_Text(pDX, IDC_EDIT20, m_e15);
	DDX_Text(pDX, IDC_EDIT2, m_ejs);
	DDX_Text(pDX, IDC_EDIT31, m_esf);
	DDX_Text(pDX, IDC_EDIT32, m_ewy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZidingyilvjing, CDialog)
	//{{AFX_MSG_MAP(CZidingyilvjing)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT31, OnChangeEdit31)
	ON_EN_CHANGE(IDC_EDIT32, OnChangeEdit32)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT7, OnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, OnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT9, OnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT10, OnChangeEdit10)
	ON_EN_CHANGE(IDC_EDIT11, OnChangeEdit11)
	ON_EN_CHANGE(IDC_EDIT12, OnChangeEdit12)
	ON_EN_CHANGE(IDC_EDIT13, OnChangeEdit13)
	ON_EN_CHANGE(IDC_EDIT14, OnChangeEdit14)
	ON_EN_CHANGE(IDC_EDIT15, OnChangeEdit15)
	ON_EN_CHANGE(IDC_EDIT16, OnChangeEdit16)
	ON_EN_CHANGE(IDC_EDIT17, OnChangeEdit17)
	ON_EN_CHANGE(IDC_EDIT18, OnChangeEdit18)
	ON_EN_CHANGE(IDC_EDIT19, OnChangeEdit19)
	ON_EN_CHANGE(IDC_EDIT20, OnChangeEdit20)
	ON_EN_CHANGE(IDC_EDIT21, OnChangeEdit21)
	ON_EN_CHANGE(IDC_EDIT22, OnChangeEdit22)
	ON_EN_CHANGE(IDC_EDIT23, OnChangeEdit23)
	ON_EN_CHANGE(IDC_EDIT24, OnChangeEdit24)
	ON_EN_CHANGE(IDC_EDIT25, OnChangeEdit25)
	ON_EN_CHANGE(IDC_EDIT26, OnChangeEdit26)
	ON_EN_CHANGE(IDC_EDIT27, OnChangeEdit27)
	ON_EN_CHANGE(IDC_EDIT28, OnChangeEdit28)
	ON_EN_CHANGE(IDC_EDIT29, OnChangeEdit29)
	ON_EN_CHANGE(IDC_EDIT30, OnChangeEdit30)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, OnDeltaposSpin3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZidingyilvjing message handlers

BOOL CZidingyilvjing::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData(TRUE);
	m_e13=1.0f;
	m_esf=1.0f;
	m_c1=0;
	m_ejs=5;
	//m_sp1.SetRange(1,99);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CZidingyilvjing::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CZidingyilvjing::OnChangeEdit31() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT31);
}

void CZidingyilvjing::OnChangeEdit32() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT32);
}

void CZidingyilvjing::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT1);
}

void CZidingyilvjing::OnChangeEdit7() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT7);
}

void CZidingyilvjing::OnChangeEdit8() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT8);
}

void CZidingyilvjing::OnChangeEdit9() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT9);
}

void CZidingyilvjing::OnChangeEdit10() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT10);
}

void CZidingyilvjing::OnChangeEdit11() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT11);
}

void CZidingyilvjing::OnChangeEdit12() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT12);
}

void CZidingyilvjing::OnChangeEdit13() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT13);
}

void CZidingyilvjing::OnChangeEdit14() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT14);
}

void CZidingyilvjing::OnChangeEdit15() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT15);
}

void CZidingyilvjing::OnChangeEdit16() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT16);
}

void CZidingyilvjing::OnChangeEdit17() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT17);
}

void CZidingyilvjing::OnChangeEdit18() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT18);
}

void CZidingyilvjing::OnChangeEdit19() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT19);
}

void CZidingyilvjing::OnChangeEdit20() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT20);
}

void CZidingyilvjing::OnChangeEdit21() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT21);
}

void CZidingyilvjing::OnChangeEdit22() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT22);
}

void CZidingyilvjing::OnChangeEdit23() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT23);
}

void CZidingyilvjing::OnChangeEdit24() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT24);
}

void CZidingyilvjing::OnChangeEdit25() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT25);
}

void CZidingyilvjing::OnChangeEdit26() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT26);
}

void CZidingyilvjing::OnChangeEdit27() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT27);
}

void CZidingyilvjing::OnChangeEdit28() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT28);
}

void CZidingyilvjing::OnChangeEdit29() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT29);
}

void CZidingyilvjing::OnChangeEdit30() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT30);
}
void CZidingyilvjing::ApplyFilter(int id){
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	CString str;
	GetDlgItemText(id,str);
	if(str!="-"){
		UpdateData(TRUE);
		if(m_esf!=0.0f){
			bool rable= (m_c1==0 || m_c1==1 || m_c1==5 || m_c1==6);
			bool gable= (m_c1==0 || m_c1==2 || m_c1==4 || m_c1==6);
			bool bable= (m_c1==0 || m_c1==3 || m_c1==4 || m_c1==5);
			if(m_ejs==5){
				float arrup[25]={m_e1/m_esf,m_e2/m_esf,m_e3/m_esf,m_e4/m_esf,m_e5/m_esf,m_e6/m_esf,m_e7/m_esf,m_e8/m_esf,m_e9/m_esf,m_e10/m_esf,m_e11/m_esf,m_e12/m_esf,m_e13/m_esf,m_e14/m_esf,m_e15/m_esf,m_e16,m_e17/m_esf,m_e18/m_esf,m_e19/m_esf,m_e20/m_esf,m_e21/m_esf,m_e22/m_esf,m_e23/m_esf,m_e24/m_esf,m_e25/m_esf};
				pView->ConvolutionFilter(arrup,m_ewy,25,5,2,2,rable,gable,bable);
			}/*else if(m_ejs==3){
				float arrup[9]={m_e7/m_esf,m_e8/m_esf,m_e9/m_esf,m_e12/m_esf,m_e13/m_esf,m_e14/m_esf,m_e17/m_esf,m_e18/m_esf,m_e19/m_esf};
				pView->ConvolutionFilter(arrup,m_ewy,9,3,1,1,rable,gable,bable);
			}else if(m_ejs==1){
				float arrup[1]={m_e13/m_esf};
				pView->ConvolutionFilter(arrup,m_ewy,1,1,0,0,rable,gable,bable);
			}*/
		}
	}
}

void CZidingyilvjing::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	ApplyFilter(IDC_EDIT32);
}

void CZidingyilvjing::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	//UpdateData();
	//m_sp1.SetPos(m_ejs);
}

void CZidingyilvjing::OnDeltaposSpin3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here

	/*if(pNMUpDown->iDelta == 1) {　

	}else if(pNMUpDown->iDelta == -1) {
　　
　　}
　　*/
	*pResult = 0;
}
