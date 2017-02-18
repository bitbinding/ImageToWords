#if !defined(AFX_RUIHUAINPUT_H__C67EE7AF_CB0A_43C8_BE25_DC0CD49A24A9__INCLUDED_)
#define AFX_RUIHUAINPUT_H__C67EE7AF_CB0A_43C8_BE25_DC0CD49A24A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RuihuaInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRuihuaInput dialog

class CRuihuaInput : public CDialog
{
// Construction
public:
	CRuihuaInput(CWnd* pParent = NULL);   // standard constructor
	int bj,yz;
	float sl;	
// Dialog Data
	//{{AFX_DATA(CRuihuaInput)
	enum { IDD = IDD_DIALOG5 };
	CStatic	m_l3;
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s3;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	BOOL	m_c1;
	BOOL	m_c2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRuihuaInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRuihuaInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RUIHUAINPUT_H__C67EE7AF_CB0A_43C8_BE25_DC0CD49A24A9__INCLUDED_)
