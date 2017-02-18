// WizFontNamesComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "FontComboBox.h"
#include "ImageToWordsView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontComboBox
int CFontComboBox::memoItemLeng=0;
char CFontComboBox::memoItem[1600][64];
CFontComboBox::CFontComboBox()
{
}

CFontComboBox::~CFontComboBox()
{
}


BEGIN_MESSAGE_MAP(CFontComboBox, CComboBox)
	//{{AFX_MSG_MAP(CFontComboBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontComboBox message handlers
bool CFontComboBox::Initialize(const CWizFontsEnumerator& fonts,bool simply)
{
	ResetContent();
	bool canSimplify=true;
	int i=0;	
	if(!simply){
		CFrameWnd *pWndView =(CFrameWnd*)  AfxGetMainWnd(); 
		CImageToWordsView *pView = (CImageToWordsView*)  pWndView->GetActiveView();
		//char str[32];
		CFontDialog fd;
		fd.GetCurrentFont(&lf);
		lf.lfHeight=-32;
		lf.lfWeight=400;
		//CString str="宋体";
		if(fonts.GetFontsCount()>1600){
			canSimplify=false;
		}
		memoItemLeng=0;
		for (i = 0; i < fonts.GetFontsCount(); i++)
			{
			const CWizFontsEnumerator::Font* pFont = fonts.GetFont(i);
			if (pFont)
				{
				CString name = pFont->Name();
				if(strlen((LPTSTR)(LPCTSTR)name)<32){
					strcpy(lf.lfFaceName,(LPTSTR)(LPCTSTR)name);
					//strcpy(str,lf.lfFaceName);
					if (pView->getPchEn("　",pView->pchsetLeng,&lf)==pView->getPchEn("■",pView->pchsetLeng,&lf) && pFont->IsTrueType()){
						if (pView->getPchEn("l",pView->pchsetLeng,&lf)==pView->getPchEn("m",pView->pchsetLeng,&lf)){
							name = "等宽="+name;
						}else{
							name = "比例="+name;
						}
					}else if(pFont->IsTrueType()){
						if (pView->getPchEn("l",pView->pchsetLeng,&lf)==pView->getPchEn("m",pView->pchsetLeng,&lf)){
							name = "等宽-"+name;
						}else{
							name = "比例-"+name;
						}
					}else{
						name = "特殊-"+name;
					}
				}else{
						name = "（字体名过长）";
				}				
				if(strlen((LPTSTR)(LPCTSTR)name)>=64 || memoItemLeng>=1600-1){
					canSimplify=false;
				}
				if(canSimplify){
					strcpy(memoItem[memoItemLeng],(LPTSTR)(LPCTSTR)name);
					memoItemLeng++;
				}
				int j = AddString(name);
				if (j >= 0)
					{
					SetItemData(j, i);
					}
				else
					{
					ASSERT(0);
					}
				}
			else
				{ ASSERT(0); }
			}
		if (fonts.GetFontsCount() > 0)
			SetCurSel(0);
	}else{
		for(i=0;i<memoItemLeng && i<1600;i++){
			AddString((LPCTSTR)memoItem[i]);
		}
	}
	return canSimplify;
}

BOOL CFontComboBox::PreCreateWindow(CREATESTRUCT& cs) 
{
	return CComboBox::PreCreateWindow(cs);
}

const CWizFontsEnumerator::Font* CFontComboBox::GetCurrentFont(const CWizFontsEnumerator& fonts)
{
	int i = GetCurSel();
	if (i >= 0)
	{
		int j = GetItemData(i);
		if (j >= 0)
		{
			const CWizFontsEnumerator::Font* font = fonts.GetFont(j);
			ASSERT(font);
			return font;
		}
		else
		{	ASSERT(0);	}
	}
	else
	{	ASSERT(0); }

	return NULL;
}
