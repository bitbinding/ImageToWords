#if !defined(AFX_PERSPECTIVEINPUT_H__310C9783_D2A5_4442_A890_B4DD9EE37C57__INCLUDED_)
#define AFX_PERSPECTIVEINPUT_H__310C9783_D2A5_4442_A890_B4DD9EE37C57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PerspectiveInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPerspectiveInput dialog

class CPerspectiveInput : public CDialog
{
// Construction
public:
	CPerspectiveInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPerspectiveInput)
	enum { IDD = IDD_DIALOGPERSPECTIVE };
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPerspectiveInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPerspectiveInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSPECTIVEINPUT_H__310C9783_D2A5_4442_A890_B4DD9EE37C57__INCLUDED_)
