// ImageToWordsDoc.cpp : implementation of the CImageToWordsDoc class
//

#include "stdafx.h"
#include "ImageToWords.h"

#include "ImageToWordsDoc.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsDoc

IMPLEMENT_DYNCREATE(CImageToWordsDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageToWordsDoc, CDocument)
	//{{AFX_MSG_MAP(CImageToWordsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsDoc construction/destruction

extern bool externalFilterMode;
extern void restartApp();

CImageToWordsDoc::CImageToWordsDoc()
{
	// TODO: add one-time construction code here
	filename="";
	extname="";
}

CImageToWordsDoc::~CImageToWordsDoc()
{
}

BOOL CImageToWordsDoc::OnNewDocument()
{
	if(externalFilterMode && filename!=""){
		if(MessageBox(NULL,"在被外部加载的模式下无法执行“新建”命令，是否进行重启？","ImageToWords",MB_YESNO)==IDYES){
			restartApp();
		}
		return FALSE;
	}
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	filename="";
	extname="";
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CImageToWordsDoc serialization

void CImageToWordsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsDoc diagnostics

#ifdef _DEBUG
void CImageToWordsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageToWordsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsDoc commands

BOOL CImageToWordsDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	//if (!CDocument::OnOpenDocument(lpszPathName))
		//return FALSE;
	
	// TODO: Add your specialized creation code here
	//MessageBox(NULL,"OnOpenDocument","CDoc",0);
	if(externalFilterMode && filename!=""){
		if(MessageBox(NULL,"在被外部加载的模式下无法执行“打开”命令，是否进行重启？","ImageToWords",MB_YESNO)==IDYES){
			restartApp();
		}
		return FALSE;
	}

	char *fn=(LPTSTR)lpszPathName;
	filename.Format(_T("%s"),fn);
	int i=0;
	int j=-1;
	int leng=strlen(fn);
	
	for(i=0;i<leng;i++){
		if(fn[i]<0){
			i++;
			continue;
		}
		if(i<leng && fn[i]=='.'){
			j=i;
		}
	}
	if(j>=0 && j<leng){
		extname.Format("%s",fn+j);
	}else{
		extname="";
	}

	CFrameWnd *pWnd=NULL;
	CImageToWordsView *pView=NULL;
	pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	if(pWnd!=NULL){
		pView = (CImageToWordsView*)  pWnd->GetActiveView();
	}
	if(pView!=NULL){
		pView->openFile();
	}

	return TRUE;
}

BOOL CImageToWordsDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	//MessageBox(NULL,"OnSaveDocument","CDoc",0);
	return FALSE;
}

void CImageToWordsDoc::OnCloseDocument() 
{
	// TODO: Add your specialized code here and/or call the base class
	CDocument::OnCloseDocument();
}
