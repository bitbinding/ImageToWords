#if !defined(AFX_FONTCOMBOBOX_H__FEA73C3C_6D26_4748_A802_D9FCEE4C6EE7__INCLUDED_)
#define AFX_FONTCOMBOBOX_H__FEA73C3C_6D26_4748_A802_D9FCEE4C6EE7__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WizFontNamesComboBox.h : header file
//

#include "WizFontsEnumerator.h"

/////////////////////////////////////////////////////////////////////////////
// CFontComboBox window

class CFontComboBox : public CComboBox
{
// Construction
public:
	CFontComboBox();

// Attributes
public:

// Operations
public:
	bool Initialize(const CWizFontsEnumerator& fonts,bool simply=false);
	const CWizFontsEnumerator::Font* GetCurrentFont(const CWizFontsEnumerator& fonts);
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontComboBox)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFontComboBox();

	// Generated message map functions
private:
	
protected:
	//{{AFX_MSG(CFontComboBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	static char memoItem[1600][64];
	static int memoItemLeng;
	LOGFONT lf;
	DECLARE_MESSAGE_MAP()
};

#endif