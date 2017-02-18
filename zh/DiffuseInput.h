#if !defined(AFX_DIFFUSEINPUT_H__BF4DB25C_4016_41C0_97DA_5DE17EBA3634__INCLUDED_)
#define AFX_DIFFUSEINPUT_H__BF4DB25C_4016_41C0_97DA_5DE17EBA3634__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiffuseInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDiffuseInput dialog

class CDiffuseInput : public CDialog
{
// Construction
public:
	CDiffuseInput(CWnd* pParent = NULL);   // standard constructor
	int bjc2;//样本半径的两倍（即边长减一）
	int offset;//颜色偏移量
	SCROLLINFO si1,si2;
// Dialog Data
	//{{AFX_DATA(CDiffuseInput)
	enum { IDD = IDD_DIALOG15 };
	CStatic	m_l1;
	CScrollBar	m_s1;
	int		m_r1;
	BOOL	m_c1;
	BOOL	m_c2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiffuseInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDiffuseInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnButton1();
	afx_msg void OnCheck1();
	afx_msg void OnCheck3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIFFUSEINPUT_H__BF4DB25C_4016_41C0_97DA_5DE17EBA3634__INCLUDED_)
