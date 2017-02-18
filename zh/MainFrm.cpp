// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "ImageToWordsView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_WORDSTRANSFORM, OnWordstransform)
	ON_UPDATE_COMMAND_UI(ID_WORDSTRANSFORM, OnUpdateWordstransform)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	if (!m_wndDlgBar.Create(this, IDR_TOOLPROPERTIES, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Failed to create dialogbar\n");
		return -1;		// fail to create
	}

	if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
	int i=0,j=0;
	if(GetMenu()!=NULL){
		i=0;
		j=GetMenu()->GetMenuItemCount();
		while(i<j){
			if((GetMenu()->GetMenuState(i,MF_BYPOSITION))&MF_ENABLED==0){
				GetMenu()->RemoveMenu(i,MF_BYPOSITION);
				j=GetMenu()->GetMenuItemCount();
			}else{
				i++;
			}
		}
	}
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers



void CMainFrame::OnWordstransform() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnUpdateWordstransform(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	/*CImageToWordsView *pView = (CImageToWordsView*)  this->GetActiveView();
	if(pView==NULL){
		CFrameWnd::OnClose();
		return;
	}
	if(pView->hasValidImage() && (pView->undoi>0 || pView->undort)){
		int ret=MessageBox("文件已修改，是否保存？","提示",MB_YESNOCANCEL);
		if(ret==IDYES){
			pView->OnFileSave();
			CFrameWnd::OnClose();
			return;
		}else if(ret==IDNO){
			CFrameWnd::OnClose();
			return;
		}else{
			return;
		}
	}*/
	CFrameWnd::OnClose();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_wndDlgBar.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
    {
        return TRUE;
    }
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFrameWnd::PreTranslateMessage(pMsg);
}
