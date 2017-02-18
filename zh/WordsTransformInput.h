#if !defined(AFX_WORDSTRANSFORMINPUT_H__49493550_CC72_49A2_8557_C1908AEC39AB__INCLUDED_)
#define AFX_WORDSTRANSFORMINPUT_H__49493550_CC72_49A2_8557_C1908AEC39AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WordsTransformInput.h : header file
//
#include "FontComboBox.h"
/////////////////////////////////////////////////////////////////////////////
// CWordsTransformInput dialog

class CWordsTransformInput : public CDialog
{
// Construction
public:
	CWordsTransformInput(CWnd* pParent = NULL);   // standard constructor
	SCROLLINFO si1,si2,si3,si4,si5,si6,si7;//滚动条信息
	int fs,rate,wid2rc,rowspacrc;//字号、文字超出与不到的平衡、字间距容差、行距容差
	float hei,wid,wid2,rowspac;//格子高度、格子与字体等宽高比时的宽度、格子设置的宽度（截取）、行距
	void updateText(bool drawable);//更新显示的文字
	FIXED FixedFromDouble(double d);
	void SetMat(LPMAT2 lpMat);
	void getWid();//获得格子与字体等宽高比时的宽度
	RECT m_preview_rect;//预览框矩形
	bool pvdraging;//预览框图片在拖动
	int px0,py0;//预览框图片左上角点相对于主窗体图的坐标
	int pxt,pyt;//移动时预览框图片左上角点相对于主窗体图的坐标
	int moux0,mouy0;//移动前鼠标坐标
	CImage preReco;//识别前的预览图
	CWizFontsEnumerator fontFaceEnum;
	CFont cfco,cfb,cfi;
	LOGFONT lfb,lfi;
	//CImage Img
// Dialog Data
	//{{AFX_DATA(CWordsTransformInput)
	enum { IDD = IDD_DIALOG16 };
	CFontComboBox	m_co2;
	CButton	m_fi;
	CButton	m_fb;
	CStatic	m_lp;
	CStatic	m_lwsum;
	CStatic	m_ldk;
	CStatic	m_l7;
	CStatic	m_l6;
	CStatic	m_l5;
	CStatic	m_l4;
	CStatic	m_l3;
	CStatic	m_l2;
	CStatic	m_l1;
	CScrollBar	m_s7;
	CScrollBar	m_s6;
	CScrollBar	m_s5;
	CScrollBar	m_s4;
	CScrollBar	m_s3;
	CScrollBar	m_s2;
	CScrollBar	m_s1;
	BOOL	m_ch1;
	BOOL	m_ch2;
	int		m_co1;
	int		m_co3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordsTransformInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWordsTransformInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSelchangeCombo4();
	afx_msg void OnButton10();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnButton11();
	afx_msg void OnButton7();
	afx_msg void OnButton6();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDSTRANSFORMINPUT_H__49493550_CC72_49A2_8557_C1908AEC39AB__INCLUDED_)
