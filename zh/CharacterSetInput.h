#if !defined(AFX_CHARACTERSETINPUT_H__0C40079D_7BC4_4564_AFB1_377CDD6E1E0C__INCLUDED_)
#define AFX_CHARACTERSETINPUT_H__0C40079D_7BC4_4564_AFB1_377CDD6E1E0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CharacterSetInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCharacterSetInput dialog

class CCharacterSetInput : public CDialog
{
// Construction
public:
	CCharacterSetInput(CWnd* pParent = NULL);   // standard constructor
	CRect m_rect0;
// Dialog Data
	//{{AFX_DATA(CCharacterSetInput)
	enum { IDD = IDD_DIALOG20 };
	CListCtrl	m_l1;
	CEdit	m_e1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharacterSetInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCharacterSetInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARACTERSETINPUT_H__0C40079D_7BC4_4564_AFB1_377CDD6E1E0C__INCLUDED_)
