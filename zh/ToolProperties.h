#if !defined(AFX_TOOLPROPERTIES_H__7BFD02FB_B5FE_4F7F_B1B5_C7F662D8292E__INCLUDED_)
#define AFX_TOOLPROPERTIES_H__7BFD02FB_B5FE_4F7F_B1B5_C7F662D8292E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ToolProperties.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToolProperties dialog

class CToolProperties : public CDialogBar
{
// Construction
public:
	CToolProperties(CWnd* pParent = NULL);   // standard constructor
	void updateVariables();
	void updateInterface();
	int color;
// Dialog Data
	//{{AFX_DATA(CToolProperties)
	enum { IDD = IDR_TOOLPROPERTIES };
	int		m_e1;
	int		m_e2;
	CString	m_e3;
	BOOL	m_check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:

	// Generated message map functions
	//{{AFX_MSG(CToolProperties)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLPROPERTIES_H__7BFD02FB_B5FE_4F7F_B1B5_C7F662D8292E__INCLUDED_)
