#if !defined(AFX_BLURINPUT_H__032B9F84_A8A9_4526_99AE_24DB5E867BC1__INCLUDED_)
#define AFX_BLURINPUT_H__032B9F84_A8A9_4526_99AE_24DB5E867BC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BlurInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBlurInput dialog

class CBlurInput : public CDialog
{
// Construction
public:
	CBlurInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBlurInput)
	enum { IDD = IDD_DIALOG6 };
	CStatic	m_l2;
	CStatic	m_l3;
	CStatic	m_l1;
	CScrollBar	m_s3;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	BOOL	m_c1;
	BOOL	m_c2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlurInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBlurInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLURINPUT_H__032B9F84_A8A9_4526_99AE_24DB5E867BC1__INCLUDED_)
