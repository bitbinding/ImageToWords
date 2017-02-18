#if !defined(AFX_TRIMINPUT_H__8F22626F_A883_4BDC_B555_186725FDE176__INCLUDED_)
#define AFX_TRIMINPUT_H__8F22626F_A883_4BDC_B555_186725FDE176__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TrimInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTrimInput dialog

class CTrimInput : public CDialog
{
// Construction
public:
	CTrimInput(CWnd* pParent = NULL);   // standard constructor
	COLORREF bgc;
// Dialog Data
	//{{AFX_DATA(CTrimInput)
	enum { IDD = IDD_DIALOG19 };
	int		m_ew0;
	int		m_eh0;
	int		m_e1;
	int		m_e2;
	BOOL	m_c1;
	int		m_c2;
	int		m_e3;
	int		m_e4;
	BOOL	m_c3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrimInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTrimInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit8();
	afx_msg void OnChangeEdit9();
	afx_msg void OnChangeEdit10();
	afx_msg void OnChangeEdit11();
	afx_msg void OnButton1();
	afx_msg void OnSelchangeCombo6();
	afx_msg void OnCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRIMINPUT_H__8F22626F_A883_4BDC_B555_186725FDE176__INCLUDED_)
