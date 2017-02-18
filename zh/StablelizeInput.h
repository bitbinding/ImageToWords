#if !defined(AFX_STABLELIZEINPUT_H__093AD8A1_C7C4_431F_B327_5D997702F7E2__INCLUDED_)
#define AFX_STABLELIZEINPUT_H__093AD8A1_C7C4_431F_B327_5D997702F7E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StablelizeInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStablelizeInput dialog

class CStablelizeInput : public CDialog
{
// Construction
public:
	CStablelizeInput(CWnd* pParent = NULL);   // standard constructor
	int angle;
	float bj,sl;
	void getConvolutioned(bool hbyl);

// Dialog Data
	//{{AFX_DATA(CStablelizeInput)
	enum { IDD = IDD_DIALOG10 };
	CStatic	m_l3;
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s3;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	BOOL	m_c1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStablelizeInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStablelizeInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STABLELIZEINPUT_H__093AD8A1_C7C4_431F_B327_5D997702F7E2__INCLUDED_)
