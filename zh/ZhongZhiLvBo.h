#if !defined(AFX_ZHONGZHILVBO_H__62C26300_CB62_4B14_B679_335CB3110B61__INCLUDED_)
#define AFX_ZHONGZHILVBO_H__62C26300_CB62_4B14_B679_335CB3110B61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZhongZhiLvBo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZhongZhiLvBo dialog

class CZhongZhiLvBo : public CDialog
{
// Construction
public:
	CZhongZhiLvBo(CWnd* pParent = NULL);   // standard constructor
	SCROLLINFO si1,si2,si3,si4;
	int bc,bl,bl2;
	double power;
// Dialog Data
	//{{AFX_DATA(CZhongZhiLvBo)
	enum { IDD = IDD_DIALOG14 };
	CStatic	m_l4;
	CScrollBar	m_s4;
	CStatic	m_l3;
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s3;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	int		m_r1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZhongZhiLvBo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZhongZhiLvBo)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHONGZHILVBO_H__62C26300_CB62_4B14_B679_335CB3110B61__INCLUDED_)
