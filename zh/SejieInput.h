#if !defined(AFX_SEJIEINPUT_H__D628B35C_08E3_46E3_A4DB_2062EB0940C7__INCLUDED_)
#define AFX_SEJIEINPUT_H__D628B35C_08E3_46E3_A4DB_2062EB0940C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SejieInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSejieInput dialog

class CSejieInput : public CDialog
{
// Construction
public:
	CSejieInput(CWnd* pParent = NULL);   // standard constructor
	int statPinshu[256];//原始各明暗度的频数
	int statMax;//原始各明暗度的最大值（不计首尾二值）	
	int hkwid;//滑块宽高
	int hkhei;
	int hkDrag;//第hkDragable滑块在拖动（0为均未拖动）	
	void setGrayPosition();
	void getGrayPower();
	int grayPos;//灰块的位置
	int channelBw[3][4];
	double channelGray[3];
// Dialog Data
	//{{AFX_DATA(CSejieInput)
	enum { IDD = IDD_DIALOG2 };
	int		m_e1;
	double	m_e2;
	int		m_e3;
	int		m_e4;
	int		m_e5;
	int		m_c1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSejieInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSejieInput)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKillfocusEdit2();
	afx_msg void OnKillfocusEdit3();
	afx_msg void OnKillfocusEdit4();
	afx_msg void OnKillfocusEdit5();
	afx_msg void OnKillfocusEdit6();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEJIEINPUT_H__D628B35C_08E3_46E3_A4DB_2062EB0940C7__INCLUDED_)
