#if !defined(AFX_MOTIONBLURINPUT_H__095413E8_00D0_4CC8_AB3D_35E0F2C9DA9C__INCLUDED_)
#define AFX_MOTIONBLURINPUT_H__095413E8_00D0_4CC8_AB3D_35E0F2C9DA9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MotionBlurInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMotionBlurInput dialog

class CMotionBlurInput : public CDialog
{
// Construction
public:
	CMotionBlurInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMotionBlurInput)
	enum { IDD = IDD_DIALOG11 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMotionBlurInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMotionBlurInput)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOTIONBLURINPUT_H__095413E8_00D0_4CC8_AB3D_35E0F2C9DA9C__INCLUDED_)
