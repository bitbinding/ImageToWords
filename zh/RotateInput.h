#if !defined(AFX_ROTATEINPUT_H__30391BD9_13E4_4359_9185_7A3FB4359326__INCLUDED_)
#define AFX_ROTATEINPUT_H__30391BD9_13E4_4359_9185_7A3FB4359326__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RotateInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRotateInput dialog

class CRotateInput : public CDialog
{
// Construction
public:
	CRotateInput(CWnd* pParent = NULL);   // standard constructor
	COLORREF bgc;
// Dialog Data
	//{{AFX_DATA(CRotateInput)
	enum { IDD = IDD_DIALOGROTATE };
	CStatic	m_l1;
	CScrollBar	m_s1;
	int		m_co1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotateInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRotateInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEINPUT_H__30391BD9_13E4_4359_9185_7A3FB4359326__INCLUDED_)
