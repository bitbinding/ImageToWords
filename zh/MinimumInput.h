#if !defined(AFX_MINIMUMINPUT_H__8D176C6D_720A_4791_9207_15867501F9EE__INCLUDED_)
#define AFX_MINIMUMINPUT_H__8D176C6D_720A_4791_9207_15867501F9EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MinimumInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMinimumInput dialog

class CMinimumInput : public CDialog
{
// Construction
public:
	CMinimumInput(CWnd* pParent = NULL);   // standard constructor
	int bjc2;//样本半径的两倍（即边长减一）
// Dialog Data
	//{{AFX_DATA(CMinimumInput)
	enum { IDD = IDD_DIALOG13 };
	CStatic	m_l1;
	CScrollBar	m_s1;
	int		m_r1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMinimumInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMinimumInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINIMUMINPUT_H__8D176C6D_720A_4791_9207_15867501F9EE__INCLUDED_)
