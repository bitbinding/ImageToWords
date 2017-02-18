// ImageToWordsDoc.h : interface of the CImageToWordsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGETOWORDSDOC_H__7950E0A3_154E_4002_AD97_3F6A2AF7CAE6__INCLUDED_)
#define AFX_IMAGETOWORDSDOC_H__7950E0A3_154E_4002_AD97_3F6A2AF7CAE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "ImageToWordsView.h"

class CImageToWordsDoc : public CDocument
{
protected: // create from serialization only
	CImageToWordsDoc();
	DECLARE_DYNCREATE(CImageToWordsDoc)
// Attributes
public:
	CString filename;
	CString extname;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageToWordsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageToWordsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageToWordsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETOWORDSDOC_H__7950E0A3_154E_4002_AD97_3F6A2AF7CAE6__INCLUDED_)
