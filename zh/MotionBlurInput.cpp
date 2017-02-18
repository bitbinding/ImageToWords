// MotionBlurInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "MotionBlurInput.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMotionBlurInput dialog


CMotionBlurInput::CMotionBlurInput(CWnd* pParent /*=NULL*/)
	: CDialog(CMotionBlurInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMotionBlurInput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMotionBlurInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMotionBlurInput)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMotionBlurInput, CDialog)
	//{{AFX_MSG_MAP(CMotionBlurInput)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMotionBlurInput message handlers

BOOL CMotionBlurInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMotionBlurInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
