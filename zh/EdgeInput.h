#if !defined(AFX_EDGEINPUT_H__51AD032F_6B06_4CC8_BA0A_7F1BA51263D1__INCLUDED_)
#define AFX_EDGEINPUT_H__51AD032F_6B06_4CC8_BA0A_7F1BA51263D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EdgeInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEdgeInput dialog

class CEdgeInput : public CDialog
{
// Construction
public:
	CEdgeInput(CWnd* pParent = NULL);   // standard constructor
	SCROLLINFO si1,si2,si3,si4,si5;
	void updateAndFilter(bool willupdate=true);
	int angle,bkg,cofs,rate;
	float bj,sl;
// Dialog Data
	//{{AFX_DATA(CEdgeInput)
	enum { IDD = IDD_DIALOG9 };
	CStatic	m_l4;
	CStatic	m_l3;
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s4;
	CScrollBar	m_s3;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	int		m_co1;
	BOOL	m_ch1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEdgeInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEdgeInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDGEINPUT_H__51AD032F_6B06_4CC8_BA0A_7F1BA51263D1__INCLUDED_)
