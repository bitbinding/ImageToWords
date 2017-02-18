#if !defined(AFX_WTEDITOUTPUT_H__E2F04F42_F8B9_4B14_9AAC_A21B7862A320__INCLUDED_)
#define AFX_WTEDITOUTPUT_H__E2F04F42_F8B9_4B14_9AAC_A21B7862A320__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WtEditOutput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWtEditOutput dialog

class CWtEditOutput : public CDialog
{
// Construction
public:
	CWtEditOutput(CWnd* pParent = NULL);   // standard constructor
	CWtEditOutput(int gridhei0,int rate0,int ziji0,CWnd* pParent = NULL);   //
	int gridhei;//行高
	int rate;//文字超出与不到的平衡
	int ziji;//字集号
	bool forTransform;//是否用于转换
	char *words;//字集对应的字符数组
	int cc,cr;//当前转换所用格子的列号和行号
	LOGFONT lf;
	CRect m_rect0;
// Dialog Data
	//{{AFX_DATA(CWtEditOutput)
	enum { IDD = IDD_DIALOG17 };
	CStatic	m_s1;
	CEdit	m_eresult;
	//}}AFX_DATA
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWtEditOutput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWtEditOutput)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnUpdateEdit1();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WTEDITOUTPUT_H__E2F04F42_F8B9_4B14_9AAC_A21B7862A320__INCLUDED_)
