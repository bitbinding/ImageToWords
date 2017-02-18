#if !defined(AFX_CHUZAINPUT_H__09F23AE7_7883_41CA_8305_EBD752DB6B50__INCLUDED_)
#define AFX_CHUZAINPUT_H__09F23AE7_7883_41CA_8305_EBD752DB6B50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChuzaInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChuzaInput dialog

class CChuzaInput : public CDialog
{
// Construction
public:
	CChuzaInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChuzaInput)
	enum { IDD = IDD_DIALOG7 };
	CStatic	m_l3;
	CScrollBar	m_s3;
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChuzaInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChuzaInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHUZAINPUT_H__09F23AE7_7883_41CA_8305_EBD752DB6B50__INCLUDED_)
