#if !defined(AFX_ZIDINGYILVJING_H__2FF79FD1_AD73_47CD_809A_7A25FB77B0E5__INCLUDED_)
#define AFX_ZIDINGYILVJING_H__2FF79FD1_AD73_47CD_809A_7A25FB77B0E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Zidingyilvjing.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZidingyilvjing dialog

class CZidingyilvjing : public CDialog
{
// Construction
public:
	CZidingyilvjing(CWnd* pParent = NULL);   // standard constructor
	void ApplyFilter(int id);
// Dialog Data
	//{{AFX_DATA(CZidingyilvjing)
	enum { IDD = IDD_DIALOG8 };
	CSpinButtonCtrl	m_sp1;
	float	m_e1;
	float	m_e2;
	float	m_e3;
	float	m_e4;
	float	m_e5;
	float	m_e6;
	float	m_e7;
	float	m_e8;
	float	m_e9;
	float	m_e10;
	float	m_e11;
	float	m_e12;
	float	m_e13;
	float	m_e14;
	float	m_e16;
	float	m_e17;
	float	m_e18;
	float	m_e19;
	float	m_e20;
	float	m_e21;
	float	m_e22;
	float	m_e23;
	float	m_e24;
	float	m_e25;
	int		m_c1;
	CString	m_c2;	
	float	m_e15;
	int		m_ejs;
	float	m_esf;
	float	m_ewy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZidingyilvjing)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZidingyilvjing)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnChangeEdit31();
	afx_msg void OnChangeEdit32();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit7();
	afx_msg void OnChangeEdit8();
	afx_msg void OnChangeEdit9();
	afx_msg void OnChangeEdit10();
	afx_msg void OnChangeEdit11();
	afx_msg void OnChangeEdit12();
	afx_msg void OnChangeEdit13();
	afx_msg void OnChangeEdit14();
	afx_msg void OnChangeEdit15();
	afx_msg void OnChangeEdit16();
	afx_msg void OnChangeEdit17();
	afx_msg void OnChangeEdit18();
	afx_msg void OnChangeEdit19();
	afx_msg void OnChangeEdit20();
	afx_msg void OnChangeEdit21();
	afx_msg void OnChangeEdit22();
	afx_msg void OnChangeEdit23();
	afx_msg void OnChangeEdit24();
	afx_msg void OnChangeEdit25();
	afx_msg void OnChangeEdit26();
	afx_msg void OnChangeEdit27();
	afx_msg void OnChangeEdit28();
	afx_msg void OnChangeEdit29();
	afx_msg void OnChangeEdit30();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnChangeEdit2();
	afx_msg void OnDeltaposSpin3(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZIDINGYILVJING_H__2FF79FD1_AD73_47CD_809A_7A25FB77B0E5__INCLUDED_)
