#if !defined(AFX_YUZHIINPUT_H__9CC93A2D_3240_4980_8E38_79A1C1607868__INCLUDED_)
#define AFX_YUZHIINPUT_H__9CC93A2D_3240_4980_8E38_79A1C1607868__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// YuzhiInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CYuzhiInput dialog

class CYuzhiInput : public CDialog
{
// Construction
public:
	CYuzhiInput(CWnd* pParent = NULL);   // standard constructor
	int statPinshu[256];//原始各明暗度的频数
	int statMax;//原始各明暗度的最大值（不计首尾二值）	
	int yz;//阈值
	float dbd;//对比度
// Dialog Data
	//{{AFX_DATA(CYuzhiInput)
	enum { IDD = IDD_DIALOG4 };
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYuzhiInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CYuzhiInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YUZHIINPUT_H__9CC93A2D_3240_4980_8E38_79A1C1607868__INCLUDED_)
