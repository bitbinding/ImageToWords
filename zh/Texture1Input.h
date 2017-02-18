#if !defined(AFX_TEXTURE1INPUT_H__B869D1AF_F3CF_46CB_BBAC_3CBA6B1D7FB8__INCLUDED_)
#define AFX_TEXTURE1INPUT_H__B869D1AF_F3CF_46CB_BBAC_3CBA6B1D7FB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Texture1Input.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTexture1Input dialog

class CTexture1Input : public CDialog
{
// Construction
public:
	CTexture1Input(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTexture1Input)
	enum { IDD = IDD_DIALOGTEXTURE1 };
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	int		m_c1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTexture1Input)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTexture1Input)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTURE1INPUT_H__B869D1AF_F3CF_46CB_BBAC_3CBA6B1D7FB8__INCLUDED_)
