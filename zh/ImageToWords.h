// ImageToWords.h : main header file for the IMAGETOWORDS application
//

#if !defined(AFX_IMAGETOWORDS_H__50D44DD6_D6F5_4D6F_BD02_155335C2DBAE__INCLUDED_)
#define AFX_IMAGETOWORDS_H__50D44DD6_D6F5_4D6F_BD02_155335C2DBAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "ImageToWords_i.h"

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsApp:
// See ImageToWords.cpp for the implementation of this class
//

class CImageToWordsApp : public CWinApp
{
public:
	CImageToWordsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageToWordsApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CImageToWordsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETOWORDS_H__50D44DD6_D6F5_4D6F_BD02_155335C2DBAE__INCLUDED_)
