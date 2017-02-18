#if !defined(AFX_SCALEINPUT_H__9331AD9C_68EC_4DC1_BD62_6EE390D57ACA__INCLUDED_)
#define AFX_SCALEINPUT_H__9331AD9C_68EC_4DC1_BD62_6EE390D57ACA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScaleInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScaleInput dialog

class CScaleInput : public CDialog
{
// Construction
public:
	CScaleInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScaleInput)
	enum { IDD = IDD_DIALOG18 };
	int		m_c1;
	int		m_ew0;
	int		m_eh0;
	int		m_e1;
	int		m_e2;
	BOOL	m_ch1;
	int		m_c2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScaleInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScaleInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit8();
	afx_msg void OnChangeEdit9();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCALEINPUT_H__9331AD9C_68EC_4DC1_BD62_6EE390D57ACA__INCLUDED_)
