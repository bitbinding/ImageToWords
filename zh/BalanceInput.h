#if !defined(AFX_BALANCEINPUT_H__DDDC01CF_4A52_42C6_A21E_433B1F3F5E39__INCLUDED_)
#define AFX_BALANCEINPUT_H__DDDC01CF_4A52_42C6_A21E_433B1F3F5E39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BalanceInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBalanceInput dialog

class CBalanceInput : public CDialog
{
// Construction
public:
	CBalanceInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBalanceInput)
	enum { IDD = IDD_DIALOG1 };
	CStatic	m_l4;
	CStatic	m_l3;
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s4;
	CScrollBar	m_s3;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBalanceInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBalanceInput)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BALANCEINPUT_H__DDDC01CF_4A52_42C6_A21E_433B1F3F5E39__INCLUDED_)
