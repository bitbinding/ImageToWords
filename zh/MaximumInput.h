#if !defined(AFX_MAXIMUMINPUT_H__32801F14_E2C3_467F_B046_9D5104BC062D__INCLUDED_)
#define AFX_MAXIMUMINPUT_H__32801F14_E2C3_467F_B046_9D5104BC062D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MaximumInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMaximumInput dialog

class CMaximumInput : public CDialog
{
// Construction
public:
	CMaximumInput(CWnd* pParent = NULL);   // standard constructor
	int bjc2;//样本半径的两倍（即边长减一）
// Dialog Data
	//{{AFX_DATA(CMaximumInput)
	enum { IDD = IDD_DIALOG12 };
	CStatic	m_l1;
	CScrollBar	m_s1;
	int		m_r1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaximumInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMaximumInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAXIMUMINPUT_H__32801F14_E2C3_467F_B046_9D5104BC062D__INCLUDED_)
