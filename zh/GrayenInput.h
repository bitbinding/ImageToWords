#if !defined(AFX_GRAYENINPUT_H__51C70D46_A1DC_4EEC_8BC5_8FA43D4BE474__INCLUDED_)
#define AFX_GRAYENINPUT_H__51C70D46_A1DC_4EEC_8BC5_8FA43D4BE474__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GrayenInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGrayenInput dialog

class CGrayenInput : public CDialog
{
// Construction
public:
	CGrayenInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGrayenInput)
	enum { IDD = IDD_DIALOG3 };
	CStatic	m_l1;
	CStatic	m_l3;
	CStatic	m_l4;
	CStatic	m_l2;
	CScrollBar	m_s3;
	CScrollBar	m_s4;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrayenInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGrayenInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAYENINPUT_H__51C70D46_A1DC_4EEC_8BC5_8FA43D4BE474__INCLUDED_)
