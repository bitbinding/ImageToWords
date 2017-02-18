// ImageToWordsView.cpp : implementation of the CImageToWordsView class
//

#include "stdafx.h"
#include "ImageToWords.h"

#include "ImageToWordsDoc.h"
#include "ImageToWordsView.h"
#include "BalanceInput.h"
#include "SejieInput.h"
#include "GrayenInput.h"
#include "YuzhiInput.h"
#include "RuihuaInput.h"
#include "BlurInput.h"
#include "ChuzaInput.h"
#include "Zidingyilvjing.h"
#include "EdgeInput.h"
#include "StablelizeInput.h"
#include "WordsTransformInput.h"
#include "ScaleInput.h"
#include "TrimInput.h"
#include "MinimumInput.h"
#include "MaximumInput.h"
#include "DiffuseInput.h"
#include "ZhongZhiLvBo.h"
#include "Texture1Input.h"
#include "PerspectiveInput.h"
#include "RotateInput.h"
#include "ToolProperties.h"
#include "math.h"
#include "MainFrm.h"
#include <ctime>
#include <cstdlib>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsView

IMPLEMENT_DYNCREATE(CImageToWordsView, CScrollView)

BEGIN_MESSAGE_MAP(CImageToWordsView, CScrollView)
	//{{AFX_MSG_MAP(CImageToWordsView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_BALANCE, OnBalance)
	ON_UPDATE_COMMAND_UI(ID_BALANCE, OnUpdateBalance)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SEJIE, OnSejie)
	ON_UPDATE_COMMAND_UI(ID_SEJIE, OnUpdateSejie)
	ON_COMMAND(ID_FANXIANG, OnFanxiang)
	ON_UPDATE_COMMAND_UI(ID_FANXIANG, OnUpdateFanxiang)
	ON_COMMAND(ID_GRAYEN, OnGrayen)
	ON_UPDATE_COMMAND_UI(ID_GRAYEN, OnUpdateGrayen)
	ON_COMMAND(ID_YUZHI, OnYuzhi)
	ON_UPDATE_COMMAND_UI(ID_YUZHI, OnUpdateYuzhi)
	ON_COMMAND(ID_TIDU, OnTidu)
	ON_UPDATE_COMMAND_UI(ID_TIDU, OnUpdateTidu)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_COMMAND(ID_EDIT_REDO, OnEditRedo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, OnUpdateEditRedo)
	ON_COMMAND(ID_RUIHUA, OnRuihua)
	ON_UPDATE_COMMAND_UI(ID_RUIHUA, OnUpdateRuihua)
	ON_COMMAND(ID_BLUR, OnBlur)
	ON_UPDATE_COMMAND_UI(ID_BLUR, OnUpdateBlur)
	ON_COMMAND(ID_CHUZA, OnChuza)
	ON_UPDATE_COMMAND_UI(ID_CHUZA, OnUpdateChuza)
	ON_COMMAND(ID_ZDYFI, OnZdyfi)
	ON_UPDATE_COMMAND_UI(ID_ZDYFI, OnUpdateZdyfi)
	ON_COMMAND(ID_EDGE, OnEdge)
	ON_UPDATE_COMMAND_UI(ID_EDGE, OnUpdateEdge)
	ON_COMMAND(ID_STABLELIZE, OnStablelize)
	ON_UPDATE_COMMAND_UI(ID_STABLELIZE, OnUpdateStablelize)
	ON_COMMAND(ID_WORDSTRANSFORM, OnWordstransform)
	ON_UPDATE_COMMAND_UI(ID_WORDSTRANSFORM, OnUpdateWordstransform)
	ON_COMMAND(ID_MENUSCALE, OnMenuscale)
	ON_UPDATE_COMMAND_UI(ID_MENUSCALE, OnUpdateMenuscale)
	ON_COMMAND(ID_QIANBI, OnQianbi)
	ON_UPDATE_COMMAND_UI(ID_QIANBI, OnUpdateQianbi)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	ON_COMMAND(ID_MENUTRIM, OnMenutrim)
	ON_UPDATE_COMMAND_UI(ID_MENUTRIM, OnUpdateMenutrim)
	ON_COMMAND(ID_MINIMUMFI, OnMinimumfi)
	ON_UPDATE_COMMAND_UI(ID_MINIMUMFI, OnUpdateMinimumfi)
	ON_COMMAND(ID_MAXIMUMFI, OnMaximumfi)
	ON_UPDATE_COMMAND_UI(ID_MAXIMUMFI, OnUpdateMaximumfi)
	ON_COMMAND(ID_KUOSAN, OnKuosan)
	ON_UPDATE_COMMAND_UI(ID_KUOSAN, OnUpdateKuosan)
	ON_COMMAND(ID_ZHONGZHILVBO, OnZhongzhilvbo)
	ON_UPDATE_COMMAND_UI(ID_ZHONGZHILVBO, OnUpdateZhongzhilvbo)
	ON_WM_DROPFILES()
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_TEXTURE1, OnTexture1)
	ON_UPDATE_COMMAND_UI(ID_TEXTURE1, OnUpdateTexture1)
	ON_COMMAND(ID_MENUPERSPECTIVE, OnMenuperspective)
	ON_UPDATE_COMMAND_UI(ID_MENUPERSPECTIVE, OnUpdateMenuperspective)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_MENUROTATE, OnMenurotate)
	ON_UPDATE_COMMAND_UI(ID_MENUROTATE, OnUpdateMenurotate)
	ON_COMMAND(ID_FUZHIGONGJU, OnFuzhigongju)
	ON_UPDATE_COMMAND_UI(ID_FUZHIGONGJU, OnUpdateFuzhigongju)
	ON_COMMAND(ID_ROUHUA, OnRouhua)
	ON_UPDATE_COMMAND_UI(ID_ROUHUA, OnUpdateRouhua)
	ON_COMMAND(ID_TIAOSEBAN, OnTiaoseban)
	ON_UPDATE_COMMAND_UI(ID_TIAOSEBAN, OnUpdateTiaoseban)
	ON_COMMAND(ID_DIGUAN, OnDiguan)
	ON_UPDATE_COMMAND_UI(ID_DIGUAN, OnUpdateDiguan)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsView construction/destruction
bool externalFilterMode=false;
void restartApp(){
	char szPath[MAX_PATH+1];
	if(!GetModuleFileName(NULL,szPath,MAX_PATH)){
        return;
    }
	ShellExecute(NULL,"open",szPath,NULL,NULL,SW_SHOWNORMAL);
	AfxGetMainWnd()->PostMessage(WM_CLOSE); 
}
CImageToWordsView::CImageToWordsView()
{
	// TODO: add construction code here

	char *commandLine=GetCommandLine();
	int commandLineSize=commandLine!=NULL?strlen(commandLine):0;
	if(commandLineSize>8 && strcmp(commandLine+commandLineSize-8," -filter")==0){
		externalFilterMode=true;
	}else{
		externalFilterMode=false;
	}


	preshow=false;
	tempshow=false;
	undoMaxTimes=50;
	undoImage=new CImage[undoMaxTimes];
	undoi=-1;
	undoimax=-1;
	undort=false;
	sx0=0,sy0=0;
	int i;
	imageInfo=new BYTE[9];
	for(i=0;i<9;i++){
		imageInfo[i]=255;
	}
	wordGridLengr=1;
	pchsetLeng=1;
	CFontDialog fontdlg;
	fontdlg.GetCurrentFont(&wtfont);
	wtfont.lfHeight=-20;
	wtfont.lfWeight=400;
	CString str="宋体";
	strcpy(wtfont.lfFaceName,(LPTSTR)(LPCTSTR)str);
	ti.Create(50,50,24);
	firstFontInfo=true;
	toolMode=1;
	mx0=-1;
	my0=-1;
	mx02=-1;
	my02=-1;
	linePos=0.0;
	copymx0=-1;
	copymy0=-1;
	copydx=0;
	copydy=0;
	painting=false;
	srand(unsigned(time(0)));
}

CImageToWordsView::~CImageToWordsView()
{
	if(externalFilterMode && hasValidImage() && (undoi>0 || undort)){
		OnFileSave();
	}
	if(imageInfo!=NULL){
		delete []imageInfo;
		imageInfo=NULL;
	}
	if(!m_Image.IsNull()){
		m_Image.Destroy();
	}if(!p_Image.IsNull()){
		p_Image.Destroy();
	}if(!t_Image.IsNull()){
		t_Image.Destroy();
	}
	if(undoImage!=NULL){
		int i;
		for(i=0;i<undoMaxTimes;i++){
			if(!undoImage[i].IsNull()){
				undoImage[i].Destroy();
			}
		}
		delete []undoImage;
		undoImage=NULL;
	}
}

BOOL CImageToWordsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

bool CImageToWordsView::hasValidImage(){
	return !m_Image.IsNull() && !p_Image.IsNull() && !t_Image.IsNull();
}

void CImageToWordsView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	CImageToWordsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->filename=="" || pDoc->extname==""){
		OnFileNew();
	}else{
		openFile();
	}
	DragAcceptFiles(TRUE);
	// TODO: Add your specialized code here and/or call the base class
	
}
/////////////////////////////////////////////////////////////////////////////
// CImageToWordsView drawing


void CImageToWordsView::OnDraw(CDC* pDC)
{
	CImageToWordsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	if(hasValidImage()){
		if(preshow && tempshow){
			t_Image.Draw(pDC->m_hDC,sx0,sy0);
		}else if(preshow){
			p_Image.Draw(pDC->m_hDC,sx0,sy0);
		}else{
			m_Image.Draw(pDC->m_hDC,sx0,sy0);
		}
	}
	// TODO: add draw code for native data here
}

void CImageToWordsView::openFile(){
	CImageToWordsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	copymx0=-1;
	copymy0=-1;
	copydx=0;
	copydy=0;

	CRect rect;
	CString str;
	int i;
	int j;
	int result;
	if(!m_Image.IsNull()){
		m_Image.Destroy();
	}
	if(!p_Image.IsNull()){
		p_Image.Destroy();
	}
	if(!t_Image.IsNull()){
		t_Image.Destroy();
	}
	result=m_Image.Load(pDoc->filename);
	if(result!=E_FAIL){
		p_Image.Load(pDoc->filename);
	}else{
		MessageBox("文件格式不支持！");
		m_Image.Create(800,600,24);
		p_Image.Create(800,600,24);
	}
	

	wid=m_Image.GetWidth();
	hei=m_Image.GetHeight();
	t_Image.Create(wid,hei,24);
	
	undoi=-1;
	undoimax=-1;
	undort=false;
	BYTE *mByte;
	COLORREF colour;
	for(i=0;i<undoMaxTimes;i++){
		if(!undoImage[i].IsNull()){
			undoImage[i].Destroy();
		}
		//undoImage[i].Create(wid,hei,m_Image.GetBPP()>24?m_Image.GetBPP():24);
	}
	if(m_Image.GetBPP()<24 ||  m_Image.GetBPP()!=p_Image.GetBPP() || m_Image.IsIndexed() || p_Image.IsIndexed()){
		//pDoc->filename="";
		//m_Image.Destroy();
		//p_Image.Destroy();
		//for(i=0;i<10;i++){
			//undoImage[i].Destroy();
		//}
		//MessageBox("暂不支持非真彩色位图");
		//SetScrollSizes(MM_TEXT,CSize(800,600));
		m_Image.Destroy();
		m_Image.Create(wid,hei,24);
		//p_Image.Create(wid,hei,24);			
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				colour=p_Image.GetPixel(i,j);
				*mByte=GetBValue(colour);
				mByte[1]=GetGValue(colour);
				mByte[2]=GetRValue(colour);
			}
		}
		p_Image.Destroy();
		p_Image.Create(wid,hei,24);
		resumePreview();
	}//else{
	SetScrollSizes(MM_TEXT,CSize(wid,hei));
	delete []imageInfo;
	imageInfo=new BYTE[wid*hei];
	for(i=0;i<wid*hei;i++){
		imageInfo[i]=255;
	}
	recordUndo();
}

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsView printing

BOOL CImageToWordsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageToWordsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageToWordsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsView diagnostics

#ifdef _DEBUG
void CImageToWordsView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImageToWordsView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImageToWordsDoc* CImageToWordsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageToWordsDoc)));
	return (CImageToWordsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageToWordsView message handlers

bool CImageToWordsView::openMenuCommon(CDialog &dlg,void (*myFilter)(CDialog*,CImageToWordsView*)){
	resumePreview();
	if(dlg.DoModal()==IDOK){
		if(myFilter!=NULL){
			(*myFilter)(&dlg,this);
		}
		cloneImage();
		preshow=false;
		Invalidate();
		return true;
	}else{
		preshow=false;
		tempshow=false;
		Invalidate();
		return false;
	}
}

void CImageToWordsView::updateMenuCommon(CCmdUI* pCmdUI){
	//CImageToWordsDoc* pDoc = GetDocument();
	if(!hasValidImage())
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

void CImageToWordsView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	if(externalFilterMode){
		if(MessageBox("在被外部加载的模式下无法执行“打开”命令，是否进行重启？","ImageToWords",MB_YESNO)==IDYES){
			restartApp();
		}
		return;
	}

	CImageToWordsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CFileDialog dlg(TRUE,NULL,NULL,NULL,"所有格式(*.bmp;*.jpg;*.jpeg;*.gif;*.png;*.tif;*.tiff)|*.bmp;*.jpg;*.jpeg;*.gif;*.png;*.tif;*.tiff|BMP文件(*.bmp)|*.bmp|JPG文件(*.jpg;jpeg)|*.jpg;*.jpeg|GIF文件(*.gif)|*.gif|PNG文件(*.png)|*.png|TIF文件(*.tif;*.tiff)|*.tif;*.tiff|所有文件(*.*)|*.*||");
	int nStructSize = 0;
    DWORD dwVersion, dwWindowsMajorVersion, dwWindwosMinorVersion;
    dwVersion = GetVersion();
    dwWindowsMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwWindwosMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
	CString str;
	str.Format("%d",dwVersion);
	//MessageBox(str);
	int i=88,j=1;
    if(dwVersion < 0x80000000)
    {
	nStructSize=88;
    }
    else
    {
    nStructSize = 76; //98下显示老版本，如图1
    }
    dlg.m_ofn.lStructSize = nStructSize; //------用来检测目前的操作系统的版本信息	
	//dlg.m_ofn.lStructSize = 88;
	if(dlg.DoModal()==IDOK){
		pDoc->filename.Format(_T("%s"),(LPTSTR)(LPCTSTR)(dlg.GetPathName()));
		pDoc->extname = dlg.GetFileExt(); //返回选定文件的扩展文件名
		openFile();
		Invalidate();
		int i=pDoc->filename.ReverseFind(_T('\\'));
		int j=pDoc->filename.ReverseFind(_T('/'));
		int k=i>=j?i:j;
		CString filenameStr2=_T("无标题");
		if(k>=0){
			filenameStr2=pDoc->filename.Right(pDoc->filename.GetLength()-k-1);
		}else{
			filenameStr2=pDoc->filename;
		}
		CMainFrame* pMf = (CMainFrame*)AfxGetMainWnd();
		pMf->SetWindowText(filenameStr2+_T(" - ImageToWords"));
		//openNew=false;
	}
	
}

void CImageToWordsView::OnBalance() 
{
	// TODO: Add your command handler code here	
	CBalanceInput dlg;
	openMenuCommon(dlg);
}
void CImageToWordsView::BalanceFilter(int ld,float dbd,int sx,float bhd){
	int i=0,j=0;//循环变量
	BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	int colour;//转换的中间变量
	//int *colohsl;//转换色相向后的hsl值
	//BYTE *colohrgb;//转换色相向后的rgb值
	int colomin,colomax,colomid;
	BYTE coloavam;//颜色HSL中的L值
	BYTE colospan;//颜色RGB中最亮的和最暗的差(颜色HSL中的L值为127时的S值的两倍)
	int coloh;//颜色HSL中的H值
	int r,g,b,temp=0;
	//float rgbdh=255.0f/60;
	int hflag;
	int colonmid;
	sx=sx*765/180;
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);

			/*colohsl=toHSL(*(mByte+2),*(mByte+1),*mByte);
			colohsl[0]+=sx;
			colohsl[1]*=bhd;
			colohrgb=fromHSL(*colohsl,*(colohsl+1),*(colohsl+2));

			colour=(colohrgb[2]-128)*dbd+128+ld;
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}
			*pByte++;

			colour=(colohrgb[1]-128)*dbd+128+ld;
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}
			*pByte++;

			colour=(colohrgb[0]-128)*dbd+128+ld;
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}*/
			
			if(*mByte<=mByte[1]){				
				colomin=*mByte;
				colomax=mByte[1];
				colomid=mByte[2];
				hflag=1;
			}else{
				colomin=mByte[1];
				colomax=*mByte;
				colomid=mByte[2];
				hflag=4;
			}
			if(colomin>mByte[2]){
				colomid=colomin;
				colomin=mByte[2];
				hflag=hflag<3?2:3;
			}
			if(colomax<mByte[2]){
				colomid=colomax;
				colomax=mByte[2];
				hflag=hflag<3?0:5;
			}
			coloavam=(colomax+colomin)/2;
			colospan=colomax-colomin;
			if(sx!=0 && colospan!=0){
				coloh=(hflag&1)==0?hflag*255+(colomid-colomin)*255/colospan:hflag*255+(colomax-colomid)*255/colospan;
				coloh+=sx;
				if(coloh<0){
					coloh+=1530;
				}else if(coloh>=1530){
					coloh-=1530;
				}
				hflag=coloh/255;
				colonmid=coloh%255*colospan/255;
				switch(hflag){
					case 0:
						r=colomax;
						g=colomin+colonmid;
						b=colomin;
						break;
					case 1:
						r=colomax-colonmid;
						g=colomax;
						b=colomin;
						break;
					case 2:
						r=colomin;
						g=colomax;
						b=colomin+colonmid;
						break;
					case 3:
						r=colomin;
						g=colomax-colonmid;
						b=colomax;
						break;
					case 4:
						r=colomin+colonmid;
						g=colomin;
						b=colomax;
						break;
					case 5:
						r=colomax;
						g=colomin;
						b=colomax-colonmid;
						break;
				}				
			}else{
				r=*(mByte+2);
				g=*(mByte+1);
				b=*mByte;
				
			}
			
			//if(bhd>((float)255)/(*colomax))bhd=((float)255)/(*colomax);
			//if(bhd>((float)255)/(255-*colomin))bhd=((float)255)/(255-*colomin);

			colour=(b-coloavam)*bhd+coloavam;
			//colour=(*mByte-coloavam)*bhd+coloavam;
			colour=(colour-128)*dbd+128+ld;			
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}			
			pByte++;
			//mByte++;


			colour=(g-coloavam)*bhd+coloavam;
			colour=(colour-128)*dbd+128+ld;			
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}			
			pByte++;
			//mByte++;

			colour=(r-coloavam)*bhd+coloavam;
			colour=(colour-128)*dbd+128+ld;			
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}

		}
	}
	preshow=true;
	Invalidate(FALSE);	
}
void CImageToWordsView::cloneImage(){
	int i=0,j=0;
	BYTE* mByte;
	BYTE* pByte;
	if(wid!=p_Image.GetWidth() || hei!=p_Image.GetHeight()){
		wid=p_Image.GetWidth();
		hei=p_Image.GetHeight();
		m_Image.Destroy();
		m_Image.Create(wid,hei,24);
		SetScrollSizes(MM_TEXT,CSize(wid,hei));
		delete []imageInfo;
		imageInfo=new BYTE[wid*hei];
		clearTempImage();
	}
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
            mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			*mByte=*pByte;
			pByte++;
			mByte++;
			*mByte=*pByte;
			pByte++;
			mByte++;
			*mByte=*pByte;
		}
	}
	recordUndo();
}
void CImageToWordsView::resumePreview(){
	int i=0,j=0;
	BYTE* mByte;
	BYTE* pByte;
	if(wid!=p_Image.GetWidth() || hei!=p_Image.GetHeight()){
		p_Image.Destroy();
		p_Image.Create(wid,hei,24);
	}for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
            mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			*pByte=*mByte;
			pByte++;
			mByte++;
			*pByte=*mByte;
			pByte++;
			mByte++;
			*pByte=*mByte;
		}
	}
}
void CImageToWordsView::OnUpdateBalance(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
	
}
double* CImageToWordsView::toHSL(BYTE &r,BYTE &g,BYTE &b){
	double R = r/255.0;
	double G = g/255.0;
	double B = b/255.0;
	double max, min, diff, r_dist, g_dist, b_dist;
	static double hsl[3];
	max = r;//Math.max(Math.max(R, G), B);
	min = g;//Math.min(Math.min(R, G), B);
	diff = max-min;
	hsl[2] =(max+min)*255/2;
	if (diff == 0) {
		hsl[0] = 0;
		hsl[1] = 0;
	} else {
		if (hsl[2]<0.5) {
			hsl[1] = diff*255/(max+min);
		} else {
			hsl[1] = diff*255/(2-max-min);
		}
		r_dist = (max-R)/diff;
		g_dist = (max-G)/diff;
		b_dist = (max-B)/diff;
		if (R == max) {
			hsl[0] = b_dist-g_dist;
		} else if (G == max) {
			hsl[0] = 2+r_dist-b_dist;
		} else if (B == max) {
			hsl[0] = 4+g_dist-r_dist;
		}
		hsl[0] *= 60;
		if (hsl[0]<0) {
			hsl[0] += 360;
			}
		if (hsl[0]>=360) {
			hsl[0] -= 360;
		}
	}	
	return hsl;
}
BYTE* CImageToWordsView::fromHSL(double &h,double &s,double &l){
	double p1,p2;
	static BYTE rgb[3];
	double S=s/255.0;
	double L=l/255.0;
	if (L<=0.5) {
		p2 = L*(1+S);
	} else {
		p2 = L+S-(L*S);
	}
	p1 = 2*L-p2;
	if (S == 0) {
		rgb[0] = (BYTE)l;
		rgb[1] = (BYTE)l;
		rgb[2] = (BYTE)l;
	} else {
		rgb[0] = toRgbMid(p1, p2, h+120);
		rgb[1] = toRgbMid(p1, p2, h);
		rgb[2] = toRgbMid(p1, p2, h-120);
	}
	return rgb;
}

BYTE CImageToWordsView::toRgbMid(double q1,double q2,double hue){
	if (hue>360) {
		hue = hue-360;
	}
	if (hue<0) {
		hue = hue+360;
	}
	if (hue<60) {
		return (BYTE)((q1+(q2-q1)*hue/60)*255);
	} else if (hue<180) {
		return (BYTE)(q2*255);
	} else if (hue<240) {
		return (BYTE)((q1+(q2-q1)*(240-hue)/60)*255);
	} else {
		return (BYTE)(q1*255);
	}
}



void CImageToWordsView::OnSejie() 
{
	// TODO: Add your command handler code here	
	CSejieInput dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateSejie(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}
void CImageToWordsView::statZft(int channel,int (&pinshu)[256]) 
{
	// TODO: Add your command update UI handler code here
	//static int pinshu[256];
	int i,j;
	BYTE *mByte;
	for(i=0;i<256;i++){			
		pinshu[i]=0;
	}
	if (channel==0){
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){			
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pinshu[(*mByte+*(mByte+1)+*(mByte+2))/3]++;
			}
		}
	}else if (channel==1){
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){			
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pinshu[*(mByte+2)]++;
			}
		}
	}else if (channel==2){
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){			
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pinshu[*(mByte+1)]++;
			}
		}
	}else if (channel==3){
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){			
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pinshu[*mByte]++;
			}
		}
	}
	//memcpy(pinshur, pinshu, sizeof(pinshu));
}
void CImageToWordsView::SejieFilter(int inb,double ing,int inw,int outb,int outw,int channel){
	int i=0,j=0;//循环变量
	BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	int colour;//转换的中间变量
	double pg;//灰滑块值对应的指数
	int chanzl;//channel值对应的指针增量	
	if(inb>=0 && inb<inw && inw<=255 && ing>=1/255.0 && ing<=255 && outb>=0 && outb<outw && outw<=255){
		pg=1/ing;
		chanzl=3-channel;		
		if(channel==0){
			if(ing==1){
				for(j=0;j<hei;j++){
					for(i=0;i<wid;i++){
						mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
						colour=(*mByte-inb)*255/(inw-inb);
						if(colour<=0) {colour=0;}
						else if(colour>=255) {colour=255;}
						colour=outb+colour*(outw-outb)/255;
						if(colour<=0) {*pByte=0;}
						else if(colour>=255) {*pByte=255;}
						else {*pByte=colour;}
						pByte++;
						mByte++;

						colour=(*mByte-inb)*255/(inw-inb);
						if(colour<=0) {colour=0;}
						else if(colour>=255) {colour=255;}
						colour=outb+colour*(outw-outb)/255;
						if(colour<=0) {*pByte=0;}
						else if(colour>=255) {*pByte=255;}
						else {*pByte=colour;}
						pByte++;
						mByte++;

						colour=(*mByte-inb)*255/(inw-inb);
						if(colour<=0) {colour=0;}
						else if(colour>=255) {colour=255;}
						colour=outb+colour*(outw-outb)/255;
						if(colour<=0) {*pByte=0;}
						else if(colour>=255) {*pByte=255;}
						else {*pByte=colour;}
					}
				}
			}else{
				for(j=0;j<hei;j++){
					for(i=0;i<wid;i++){
						mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
						colour=(int)(pow((*mByte-inb)/(double)(inw-inb),pg)*255);
						if(colour<=0) {colour=0;}
						else if(colour>=255) {colour=255;}
						colour=outb+colour*(outw-outb)/255;
						if(colour<=0) {*pByte=0;}
						else if(colour>=255) {*pByte=255;}
						else {*pByte=colour;}
						pByte++;
						mByte++;

						colour=(int)(pow((*mByte-inb)/(double)(inw-inb),pg)*255);
						if(colour<=0) {colour=0;}
						else if(colour>=255) {colour=255;}
						colour=outb+colour*(outw-outb)/255;
						if(colour<=0) {*pByte=0;}
						else if(colour>=255) {*pByte=255;}
						else {*pByte=colour;}
						pByte++;
						mByte++;

						colour=(int)(pow((*mByte-inb)/(double)(inw-inb),pg)*255);
						if(colour<=0) {colour=0;}
						else if(colour>=255) {colour=255;}
						colour=outb+colour*(outw-outb)/255;
						if(colour<=0) {*pByte=0;}
						else if(colour>=255) {*pByte=255;}
						else {*pByte=colour;}
					}
				}
			}
		}else if(channel==1 || channel==2 || channel==3){
			if(ing==1){
				for(j=0;j<hei;j++){
					for(i=0;i<wid;i++){
						mByte=(BYTE *)m_Image.GetPixelAddress(i,j)+chanzl;
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j)+chanzl;
						colour=(*mByte-inb)*255/(inw-inb);
						if(colour<=0) {colour=0;}
						else if(colour>=255) {colour=255;}
						colour=outb+colour*(outw-outb)/255;
						if(colour<=0) {*pByte=0;}
						else if(colour>=255) {*pByte=255;}
						else {*pByte=colour;}						
					}
				}
			}else{
				for(j=0;j<hei;j++){
					for(i=0;i<wid;i++){
						mByte=(BYTE *)m_Image.GetPixelAddress(i,j)+chanzl;
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j)+chanzl;
						colour=(int)(pow((*mByte-inb)/(double)(inw-inb),pg)*255);
						if(colour<=0) {colour=0;}
						else if(colour>=255) {colour=255;}
						colour=outb+colour*(outw-outb)/255;
						if(colour<=0) {*pByte=0;}
						else if(colour>=255) {*pByte=255;}
						else {*pByte=colour;}						
					}
				}
			}
		}
		preshow=true;
		Invalidate(FALSE);
	}	
}

void CImageToWordsView::OnFanxiang() 
{
	// TODO: Add your command handler code here
	int i=0,j=0;//循环变量
	BYTE* mByte;//原图指针
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			*mByte=255-(*mByte);
			mByte++;
			*mByte=255-(*mByte);
			mByte++;
			*mByte=255-(*mByte);
			mByte++;
		}
	}
	recordUndo();
	preshow=false;
	tempshow=false;
	Invalidate();
}

void CImageToWordsView::OnUpdateFanxiang(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::OnGrayen() //Grayen应为Discolor
{
	// TODO: Add your command handler code here	
	CGrayenInput dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateGrayen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}
void CImageToWordsView::GrayenFilter(int wr,int wg,int wb,float scd){
	int i=0,j=0;//循环变量
	BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	int colour;//转换的中间变量
	BYTE coloava;//颜色RGB的加权平均值	
	if(wr+wg+wb!=0){
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
				coloava=((*(mByte+2))*wr+(*(mByte+1))*wg+(*mByte)*wb)/(wr+wg+wb);

				colour=(*mByte-coloava)*scd+coloava;			
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;
				
				colour=(*mByte-coloava)*scd+coloava;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;
				
				colour=(*mByte-coloava)*scd+coloava;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
			}
		}	
		preshow=true;
		Invalidate(FALSE);
	}else{
		preshow=false;
		Invalidate(FALSE);
	}
}

void CImageToWordsView::OnYuzhi() 
{
	// TODO: Add your command handler code here	
	CYuzhiInput dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateYuzhi(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::YuzhiFilter(int yz,float dbd){
	int i=0,j=0;//循环变量
	BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	int coloava;//颜色RGB的加权平均值
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			coloava=(*(mByte+2)+*(mByte+1)+*mByte)/3;			
			coloava=(int)((coloava-128)*dbd+128)%256;	
			if(coloava>=yz) {
				*pByte=255;
				pByte++;
				*pByte=255;
				pByte++;
				*pByte=255;
			} else  {
				*pByte=0;
				pByte++;
				*pByte=0;
				pByte++;
				*pByte=0;
			}
		}
	}
	preshow=true;
	Invalidate(FALSE);
}

void CImageToWordsView::previewHeibaien(int yz){
	int i=0,j=0;//循环变量
	//BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	int coloava;//颜色RGB的加权平均值
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			//mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			//coloava=(*(mByte+2)+*(mByte+1)+*mByte)/3;
			coloava=(*(pByte+2)+*(pByte+1)+*pByte)/3;			
			//coloava=(int)((coloava-128)*dbd+128)%256;	
			if(coloava>=yz) {
				*pByte=255;
				pByte++;
				*pByte=255;
				pByte++;
				*pByte=255;
			} else  {
				*pByte=0;
				pByte++;
				*pByte=0;
				pByte++;
				*pByte=0;
			}
		}
	}
	preshow=true;
	Invalidate(FALSE);
}

void CImageToWordsView::OnTidu() 
{
	// TODO: Add your command handler code here
	int i=0,j=0;//循环变量
	BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	BYTE* bytex;//原图右一像素指针
	BYTE* bytey;//原图下一像素指针
	int colour;//转换的中间变量	
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);	
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
			if(i<wid-1){
				bytex=(BYTE *)m_Image.GetPixelAddress(i+1,j);
			}else if(wid>1){
				bytex=(BYTE *)m_Image.GetPixelAddress(i-1,j);
			}else{
				bytex=(BYTE *)m_Image.GetPixelAddress(i,j);
			}
			if(j<hei-1){
				bytey=(BYTE *)m_Image.GetPixelAddress(i,j+1);
			}else if(hei>1){
				bytey=(BYTE *)m_Image.GetPixelAddress(i,j-1);
			}else{
				bytey=(BYTE *)m_Image.GetPixelAddress(i,j);
			}
			
			colour=labs(*bytex-*mByte)>=labs(*bytey-*mByte)?labs(*bytex-*mByte):labs(*bytey-*mByte);			
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}
			pByte++;
			mByte++;
			bytex++;
			bytey++;
			
			colour=labs(*bytex-*mByte)>=labs(*bytey-*mByte)?labs(*bytex-*mByte):labs(*bytey-*mByte);
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}
			pByte++;
			mByte++;
			bytex++;
			bytey++;
			
			colour=labs(*bytex-*mByte)>=labs(*bytey-*mByte)?labs(*bytex-*mByte):labs(*bytey-*mByte);
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}
		}
	}	
	cloneImage();
	preshow=false;
	tempshow=false;
	Invalidate();	
}

void CImageToWordsView::OnUpdateTidu(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::OnEditUndo() 
{
	// TODO: Add your command handler code here
	if(!(!hasValidImage() || !undort && undoi<=0 || undort && undoi==undoimax+1 || undort && undoi==undoMaxTimes-1 && undoimax==0)){
		int i=0,j=0;
		BYTE* mByte;
		BYTE* uByte;
		if(undoi<=0){
			undoi=undoMaxTimes-1;
		}else if(undoi>0){
			undoi--;
		}
		if(undoi>=0 || undoi<=9){
			if(wid!=undoImage[undoi].GetWidth() || hei!=undoImage[undoi].GetHeight()){
				wid=undoImage[undoi].GetWidth();
				hei=undoImage[undoi].GetHeight();
				m_Image.Destroy();
				p_Image.Destroy();
				t_Image.Destroy();
				m_Image.Create(wid,hei,24);
				p_Image.Create(wid,hei,24);
				t_Image.Create(wid,hei,24);
				SetScrollSizes(MM_TEXT,CSize(wid,hei));
				delete []imageInfo;
				imageInfo=new BYTE[wid*hei];
			}
			for(j=0;j<hei;j++){
				for(i=0;i<wid;i++){
					mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
					uByte=(BYTE *)undoImage[undoi].GetPixelAddress(i,j);
					*mByte=*uByte;
					uByte++;
					mByte++;
					*mByte=*uByte;
					uByte++;
					mByte++;
					*mByte=*uByte;
				}
			}
		}
		preshow=false;
		Invalidate();
	}
}

void CImageToWordsView::OnUpdateEditUndo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}
void CImageToWordsView::recordUndo(){
	int i=0,j=0;
	BYTE* mByte;
	BYTE* uByte;
	if(undoi>=undoMaxTimes-1){
		undoi=0;
		undort=true;
	}else{
		undoi++;
	}
	undoimax=undoi;
	if(undoi>=0 || undoi<=undoMaxTimes-1){
		if(undoImage[undoi].IsNull()){
			undoImage[undoi].Create(wid,hei,m_Image.GetBPP());
		}
		if(wid!=undoImage[undoi].GetWidth() || hei!=undoImage[undoi].GetHeight()){
			undoImage[undoi].Destroy();
			undoImage[undoi].Create(wid,hei,24);
		}
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				uByte=(BYTE *)undoImage[undoi].GetPixelAddress(i,j);
				*uByte=*mByte;
				uByte++;
				mByte++;
				*uByte=*mByte;
				uByte++;
				mByte++;
				*uByte=*mByte;
			}
		}
	}
}

void CImageToWordsView::OnEditRedo() 
{
	// TODO: Add your command handler code here
	if(!(!hasValidImage() || undoi==undoimax)){
		int i=0,j=0;
		BYTE* mByte;
		BYTE* uByte;
		if(undoi>=undoMaxTimes-1){
			undoi=0;
		}else{
			undoi++;
		}
		if(undoi>=0 || undoi<=undoMaxTimes-1){
			if(wid!=undoImage[undoi].GetWidth() || hei!=undoImage[undoi].GetHeight()){
				wid=undoImage[undoi].GetWidth();
				hei=undoImage[undoi].GetHeight();
				m_Image.Destroy();
				p_Image.Destroy();
				t_Image.Destroy();
				m_Image.Create(wid,hei,24);
				p_Image.Create(wid,hei,24);
				t_Image.Create(wid,hei,24);
				SetScrollSizes(MM_TEXT,CSize(wid,hei));
				delete []imageInfo;
				imageInfo=new BYTE[wid*hei];
			}
			for(j=0;j<hei;j++){
				for(i=0;i<wid;i++){
					mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
					uByte=(BYTE *)undoImage[undoi].GetPixelAddress(i,j);
					*mByte=*uByte;
					uByte++;
					mByte++;
					*mByte=*uByte;
					uByte++;
					mByte++;
					*mByte=*uByte;
				}
			}
		}
		preshow=false;
		Invalidate();
	}
}

void CImageToWordsView::OnUpdateEditRedo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void OnRuihuaOK(CDialog *dialog,CImageToWordsView *pView) {
	CRuihuaInput *dlg=dynamic_cast<CRuihuaInput *>(dialog);
	if(dlg==NULL){
		return;
	}
	if(dlg->m_c2==TRUE){
		pView->RuihuaFilter(dlg->bj,dlg->sl,dlg->yz,dlg->m_c1);
	}
}

void CImageToWordsView::OnRuihua() 
{
	// TODO: Add your command handler code here
	CRuihuaInput dlg;
	openMenuCommon(dlg,OnRuihuaOK);
}

void CImageToWordsView::OnUpdateRuihua(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}
void CImageToWordsView::RuihuaFilter(int r,float sl,int yz,BOOL smooth){
	int i=0,j=0,k=0,l=0,m=0,n=0;//循环变量
	BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	/*if(r>10){
		r=10;
	}*/
	int leng=r*2+1;//锐化求平均时所用方框的边长
	
	int sumr,sumg,sumb,sumarea;//颜色总和，方框的内切圆面积
	int sumrprevr,sumgprevr,sumbprevr,sumareaprevr;//上边颜色总和，方框的内切圆面积
	int colour;//转换的中间变量
	int er,eg,eb;//r,g,b的平均值
	int nr,ng,nb;//r,g,b锐化后的值（未考虑阈值和柔化）

	int *leftEdge=NULL;
	int *rightEdge=NULL;
	int *upEdge=NULL;
	int *downEdge=NULL;
	
	leftEdge=new int[leng];
	rightEdge=new int[leng];
	upEdge=new int[leng];
	downEdge=new int[leng];
	
	
	/**/if(smooth==1){
		for(i=0;i<wid*hei;i++){
			imageInfo[i]=255;
		}
	}/**/

	sumr=0;
	sumg=0;
	sumb=0;
	sumarea=0;
	for(l=0;l<leng;l++){
		leftEdge[l]=0;
		rightEdge[l]=0;
		for(k=0;k<leng;k++){
			m=k-r;
			n=l-r;
			if(m*m+n*n<=r*r){
				if(m>=0 && n>=0 && m<wid && n<hei){
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					sumb+=*mByte;
					sumg+=*(mByte+1);
					sumr+=*(mByte+2);
					sumarea++;
				}
				if(leftEdge[l]>=0){
					leftEdge[l]=m;
				}
				rightEdge[l]=m;
			}
		}
		upEdge[l]=leftEdge[l];
		downEdge[l]=rightEdge[l];
	}
	sumrprevr=sumr;
	sumgprevr=sumg;
	sumbprevr=sumb;
	sumareaprevr=sumarea;
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			if(i>0){
				for(l=0;l<leng;l++){
					n=j+l-r;
					if(n<0 ||  n>=hei){
						continue;
					}

					m=i-1+leftEdge[l];
					if(m>=0 && m<wid){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						sumb-=*mByte;
						sumg-=*(mByte+1);
						sumr-=*(mByte+2);
						sumarea--;
					}
					m=i+rightEdge[l];
					if(m>=0 && m<wid){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						sumb+=*mByte;
						sumg+=*(mByte+1);
						sumr+=*(mByte+2);
						sumarea++;
					}
				}
			}else if(j>0){
				sumr=sumrprevr;
				sumg=sumgprevr;
				sumb=sumbprevr;
				sumarea=sumareaprevr;
				
				for(k=0;k<leng;k++){
					m=i+k-r;
					if(m<0 ||  m>=hei){
						continue;
					}

					n=j-1+upEdge[k];
					if(n>=0 && n<hei){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						sumb-=*mByte;
						sumg-=*(mByte+1);
						sumr-=*(mByte+2);
						sumarea--;
					}

					n=j+downEdge[k];
					if(n>=0 && n<hei){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						sumb+=*mByte;
						sumg+=*(mByte+1);
						sumr+=*(mByte+2);
						sumarea++;
					}
				}

				sumrprevr=sumr;
				sumgprevr=sumg;
				sumbprevr=sumb;
				sumareaprevr=sumarea;
			}
			
			er=sumr/sumarea;
			eg=sumg/sumarea;
			eb=sumb/sumarea;
			if(sumarea==0)continue;
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
			nb=(*mByte-eb)*sl+eb;
			if(nb<0){nb=0;}
			else if(nb>255){nb=255;}
			ng=(mByte[1]-eg)*sl+eg;
			if(ng<0){ng=0;}
			else if(ng>255){ng=255;}
			nr=(mByte[2]-er)*sl+er;
			if(nr<0){nr=0;}
			else if(nr>255){nr=255;}
			if(abs(nb-*mByte)>=yz || abs(ng-*(mByte+1))>=yz || abs(nr-*(mByte+2))>=yz){
				/**/if(smooth==TRUE)imageInfo[j*wid+i]-=107;/**/
				*pByte=nb;
				*pByte++;
				*pByte=ng;
				*pByte++;
				*pByte=nr;
			}else{
				/**/if(smooth==TRUE){
					if(i>0){if(imageInfo[j*wid+i-1]>169)imageInfo[j*wid+i-1]-=96;}
					if(i<wid-1){if(imageInfo[j*wid+i+1]>169)imageInfo[j*wid+i+1]-=96;}
					if(j>0){if(imageInfo[(j-1)*wid+i]>169)imageInfo[(j-1)*wid+i]-=96;}
					if(j<hei-1){if(imageInfo[(j+1)*wid+i]>169)imageInfo[(j+1)*wid+i]-=96;}
				}/**/

				colour=(nb-*mByte)*abs(*mByte-nb)/yz+*mByte;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;

				
				colour=(ng-*mByte)*abs(*mByte-ng)/yz+*mByte;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;

				colour=(nr-*mByte)*abs(*mByte-nr)/yz+*mByte;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
			}
		}
	}
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			if(smooth==1 && imageInfo[j*wid+i]<100){
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
				*pByte=(*pByte+(*mByte)*2)/3;
				pByte++;
				mByte++;

				*pByte=(*pByte+(*mByte)*2)/3;				
				pByte++;
				mByte++;

				*pByte=(*pByte+(*mByte)*2)/3;				
				pByte++;
				mByte++;
			}
		}
	}

	delete []leftEdge;
	leftEdge=NULL;
	delete []rightEdge;
	rightEdge=NULL;
	delete []upEdge;
	upEdge=NULL;
	delete []downEdge;
	downEdge=NULL;

	preshow=true;
	Invalidate(FALSE);	
}

void CImageToWordsView::OnBlur() 
{
	// TODO: Add your command handler code here	
	CBlurInput dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateBlur(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

double CImageToWordsView::normalDistribution(double x,double y,double r,double change){
	int imax=(int)r;
	if(change>0 && imax>=1){
		double xr=x-r,yr=y-r;
		int i,c;
		for(i=2*imax,c=1;i>imax;i--){
			c*=i;
		}
		for(i=imax;i>1;i--){
			c/=i;
		}
		double sigma2p=r*r/(2*log((double)c)*change);
		/*if(change>1.5){
			change=change;
		}*/
		return exp(-xr*xr/(2*sigma2p))*exp(-yr*yr/(2*sigma2p));
	}else{
		return 1.0;
	}
}

void CImageToWordsView::BlurFilter(int r,int yz,int rb,BOOL smooth,BOOL roundSample){
	int i=0,j=0,k=0,l=0,m=0,n=0;//循环变量
	BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	int leng=r*2+1;//模糊求平均时所用方框的边长
	int sumr,sumg,sumb,sumarea;//颜色加权总和，颜色容量，权重
	int sumrprevr,sumgprevr,sumbprevr,sumareaprevr;//上边颜色总和，方框的内切圆面积
	int er,eg,eb;//r,g,b的平均值
	bool isCircle=roundSample!=FALSE;

	int *leftEdge=NULL;
	int *rightEdge=NULL;
	int *upEdge=NULL;
	int *downEdge=NULL;
	if(isCircle){
		leftEdge=new int[leng];
		rightEdge=new int[leng];
		upEdge=new int[leng];
		downEdge=new int[leng];
		
	}

	/**/if(smooth==1){
		for(i=0;i<wid*hei;i++){
			imageInfo[i]=255;
		}
	}/**/
	
	sumr=0;
	sumg=0;
	sumb=0;
	sumarea=0;
	if(isCircle){
		for(l=0;l<leng;l++){
			leftEdge[l]=0;
			rightEdge[l]=0;
			for(k=0;k<leng;k++){
				m=k-r;
				n=l-r;
				if(m*m+n*n<=r*r){
					if(m>=0 && n>=0 && m<wid && n<hei){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						sumb+=*mByte;
						sumg+=*(mByte+1);
						sumr+=*(mByte+2);
						sumarea++;
					}
					if(leftEdge[l]>=0){
						leftEdge[l]=m;
					}
					rightEdge[l]=m;
				}
			}
			upEdge[l]=leftEdge[l];
			downEdge[l]=rightEdge[l];
		}
	}else{
		for(l=0;l<leng;l++){
			for(k=0;k<leng;k++){
				m=k-r;
				n=l-r;
				if(m>=0 && n>=0 && m<wid && n<hei){
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					sumb+=*mByte;
					sumg+=*(mByte+1);
					sumr+=*(mByte+2);
					sumarea++;
				}	
			}
		}
	}
	sumrprevr=sumr;
	sumgprevr=sumg;
	sumbprevr=sumb;
	sumareaprevr=sumarea;

	int colour;//转换的中间变量
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			if(isCircle){
				if(i>0){
					for(l=0;l<leng;l++){
						n=j+l-r;
						if(n<0 ||  n>=hei){
							continue;
						}

						m=i-1+leftEdge[l];
						if(m>=0 && m<wid){
							mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
							sumb-=*mByte;
							sumg-=*(mByte+1);
							sumr-=*(mByte+2);
							sumarea--;
						}
						m=i+rightEdge[l];
						if(m>=0 && m<wid){
							mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
							sumb+=*mByte;
							sumg+=*(mByte+1);
							sumr+=*(mByte+2);
							sumarea++;
						}
					}
				}else if(j>0){
					sumr=sumrprevr;
					sumg=sumgprevr;
					sumb=sumbprevr;
					sumarea=sumareaprevr;
					
					for(k=0;k<leng;k++){
						m=i+k-r;
						if(m<0 ||  m>=hei){
							continue;
						}

						n=j-1+upEdge[k];
						if(n>=0 && n<hei){
							mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
							sumb-=*mByte;
							sumg-=*(mByte+1);
							sumr-=*(mByte+2);
							sumarea--;
						}

						n=j+downEdge[k];
						if(n>=0 && n<hei){
							mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
							sumb+=*mByte;
							sumg+=*(mByte+1);
							sumr+=*(mByte+2);
							sumarea++;
						}
					}

					sumrprevr=sumr;
					sumgprevr=sumg;
					sumbprevr=sumb;
					sumareaprevr=sumarea;
				}
			}else{
				if(i>0){
					for(l=0;l<leng;l++){
						n=j+l-r;
						if(n<0 ||  n>=hei){
							continue;
						}

						m=i-1-r;
						if(m>=0){
							mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
							sumb-=*mByte;
							sumg-=*(mByte+1);
							sumr-=*(mByte+2);
							sumarea--;
						}
						m=i+r;
						if(m<wid){
							mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
							sumb+=*mByte;
							sumg+=*(mByte+1);
							sumr+=*(mByte+2);
							sumarea++;
						}
					}
				}else if(j>0){
					sumr=sumrprevr;
					sumg=sumgprevr;
					sumb=sumbprevr;
					sumarea=sumareaprevr;
					
					for(k=0;k<leng;k++){
						m=i+k-r;
						if(m<0 ||  m>=hei){
							continue;
						}

						n=j-1-r;
						if(n>=0){
							mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
							sumb-=*mByte;
							sumg-=*(mByte+1);
							sumr-=*(mByte+2);
							sumarea--;
						}

						n=j+r;
						if(n<hei){
							mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
							sumb+=*mByte;
							sumg+=*(mByte+1);
							sumr+=*(mByte+2);
							sumarea++;
						}
					}

					sumrprevr=sumr;
					sumgprevr=sumg;
					sumbprevr=sumb;
					sumareaprevr=sumarea;
				}
			}
			

			er=sumr/sumarea;
			eg=sumg/sumarea;
			eb=sumb/sumarea;
			if(sumarea==0)continue;
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);				
			if(abs((int)(eb-*mByte))<yz || abs((int)(eg-*(mByte+1)))<yz || abs((int)(er-*(mByte+2)))<yz){
				/**/if(smooth==TRUE)imageInfo[j*wid+i]-=107;/**/
				colour=(int)(eb);
				//colour=(*mByte-colour)*sl+colour;				
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;

				colour=(int)(eg);
				//colour=(*mByte-colour)*sl+colour;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;

				colour=(int)(er);
				//colour=(*mByte-colour)*sl+colour;
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
			}else{
				
				colour=(int)(eb);
				if(abs(*mByte-colour)<=yz+rb && rb!=0){
					colour=(colour-*mByte)*(yz+rb-abs(*mByte-colour))/rb+*mByte;				
					if(colour<=0) {*pByte=0;}
					else if(colour>=255) {*pByte=255;}
					else {*pByte=colour;}
				}else{
					/**/if(smooth==TRUE){
						if(i>0){if(imageInfo[j*wid+i-1]>169)imageInfo[j*wid+i-1]-=96;}
						if(i<wid-1){if(imageInfo[j*wid+i+1]>169)imageInfo[j*wid+i+1]-=96;}
						if(j>0){if(imageInfo[(j-1)*wid+i]>169)imageInfo[(j-1)*wid+i]-=96;}
						if(j<hei-1){if(imageInfo[(j+1)*wid+i]>169)imageInfo[(j+1)*wid+i]-=96;}
					}/**/
					*pByte=*mByte;
				}
				pByte++;
				mByte++;

				colour=(int)(eg);
				if(abs(*mByte-colour)<=yz+rb && rb!=0){
					colour=(colour-*mByte)*(yz+rb-abs(*mByte-colour))/rb+*mByte;				
					if(colour<=0) {*pByte=0;}
					else if(colour>=255) {*pByte=255;}
					else {*pByte=colour;}
				}else{
					/**/if(smooth==TRUE){
						if(i>0){if(imageInfo[j*wid+i-1]>169)imageInfo[j*wid+i-1]-=96;}
						if(i<wid-1){if(imageInfo[j*wid+i+1]>169)imageInfo[j*wid+i+1]-=96;}
						if(j>0){if(imageInfo[(j-1)*wid+i]>169)imageInfo[(j-1)*wid+i]-=96;}
						if(j<hei-1){if(imageInfo[(j+1)*wid+i]>169)imageInfo[(j+1)*wid+i]-=96;}
					}/**/
					*pByte=*mByte;
				}
				pByte++;
				mByte++;

				colour=(int)(er);
				if(abs(*mByte-colour)<=yz+rb && rb!=0){
					colour=(colour-*mByte)*(yz+rb-abs(*mByte-colour))/rb+*mByte;				
					if(colour<=0) {*pByte=0;}
					else if(colour>=255) {*pByte=255;}
					else {*pByte=colour;}
				}else{
					/**/if(smooth==TRUE){
						if(i>0){if(imageInfo[j*wid+i-1]>169)imageInfo[j*wid+i-1]-=96;}
						if(i<wid-1){if(imageInfo[j*wid+i+1]>169)imageInfo[j*wid+i+1]-=96;}
						if(j>0){if(imageInfo[(j-1)*wid+i]>169)imageInfo[(j-1)*wid+i]-=96;}
						if(j<hei-1){if(imageInfo[(j+1)*wid+i]>169)imageInfo[(j+1)*wid+i]-=96;}
					}/**/
					*pByte=*mByte;
				}
				/**pByte=*mByte;
				pByte++;
				mByte++;

				*pByte=*mByte;
				pByte++;
				mByte++;

				*pByte=*mByte;*/
			}
		}
	}
	/**/if(smooth==1){
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){				
				if(imageInfo[j*wid+i]<100){
					sumr=0;
					sumg=0;
					sumb=0;
					sumarea=0;
					for(m=i-1;m<i+2;m++){
						for(n=j-1;n<j+2;n++){
							if(m>=0 && n>=0 && m<wid && n<hei){
								if(imageInfo[j*wid+i]>=100){
									pByte=(BYTE *)p_Image.GetPixelAddress(m,n);
									sumb+=(*pByte);
									sumg+=(*(pByte+1));
									sumr+=(*(pByte+2));
									sumarea+=1;
								}
							}
						}
					}
					if(sumarea<=0)continue;
					pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
					*pByte=sumb/sumarea;
					pByte++;
					mByte++;

					*pByte=sumg/sumarea;				
					pByte++;
					mByte++;

					*pByte=sumr/sumarea;				
					pByte++;
					mByte++;
				}
			}
		}
	}/**/
	
	if(leftEdge!=NULL){
		delete []leftEdge;
		leftEdge=NULL;
	}
	if(rightEdge!=NULL){
		delete []rightEdge;
		rightEdge=NULL;
	}
	if(upEdge!=NULL){
		delete []upEdge;
		upEdge=NULL;
	}
	if(downEdge!=NULL){
		delete []downEdge;
		downEdge=NULL;
	}

	preshow=true;
	Invalidate(FALSE);
}


void CImageToWordsView::OnChuza() 
{
	// TODO: Add your command handler code here	
	CChuzaInput dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateChuza(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}
BYTE CImageToWordsView::chuzaCheck(int x,int y,int yz){
	if(x<0 || y<0 || x>=wid || y>=hei)return 255;
	BYTE* cent=(BYTE *)m_Image.GetPixelAddress(x,y);
	BYTE* edge=cent;
	BYTE conn=0;	
	if(x>0 && y>0){
		edge=(BYTE *)m_Image.GetPixelAddress(x-1,y-1);
		if(abs(*edge-*cent)<yz && abs(*(edge+1)-*(cent+1))<yz && abs(*(edge+2)-*(cent+2))<yz)conn+=16;
	}

	if(y>0){
		edge=(BYTE *)m_Image.GetPixelAddress(x,y-1);
		if(abs(*edge-*cent)<yz && abs(*(edge+1)-*(cent+1))<yz && abs(*(edge+2)-*(cent+2))<yz)conn+=32;
	}

	if(x<wid-1 && y>0){
		edge=(BYTE *)m_Image.GetPixelAddress(x+1,y-1);
		if(abs(*edge-*cent)<yz && abs(*(edge+1)-*(cent+1))<yz && abs(*(edge+2)-*(cent+2))<yz)conn+=64;
	}

	if(x>0){
		edge=(BYTE *)m_Image.GetPixelAddress(x-1,y);
		if(abs(*edge-*cent)<yz && abs(*(edge+1)-*(cent+1))<yz && abs(*(edge+2)-*(cent+2))<yz)conn+=128;
	}


	if(x<wid-1){
		edge=(BYTE *)m_Image.GetPixelAddress(x+1,y);
		if(abs(*edge-*cent)<yz && abs(*(edge+1)-*(cent+1))<yz && abs(*(edge+2)-*(cent+2))<yz)conn+=8;
	}

	if(x>0 && y<hei-1){
		edge=(BYTE *)m_Image.GetPixelAddress(x-1,y+1);
		if(abs(*edge-*cent)<yz && abs(*(edge+1)-*(cent+1))<yz && abs(*(edge+2)-*(cent+2))<yz)conn+=4;
	}
	if(y<hei-1){
		edge=(BYTE *)m_Image.GetPixelAddress(x,y+1);
		if(abs(*edge-*cent)<yz && abs(*(edge+1)-*(cent+1))<yz && abs(*(edge+2)-*(cent+2))<yz)conn+=2;
	}

	if(x<wid-1 && y<hei-1){
		edge=(BYTE *)m_Image.GetPixelAddress(x+1,y+1);
		if(abs(*edge-*cent)<yz && abs(*(edge+1)-*(cent+1))<yz && abs(*(edge+2)-*(cent+2))<yz)conn++;
	}
	return conn;
}
void CImageToWordsView::ChuzaFilter(int num,int yz,int hx){
	int i=0,j=0,k=0,l=0,m=0,n=0;//循环变量
	BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	int colour;//转换的中间变量
	BYTE *arr=new BYTE[wid*hei];//某点是否应用除杂（chuzaCheck的返回值）
	//BYTE *arr2=new BYTE[wid*hei];//某点是否应用除杂（arr[]的按十六进制位反转）
	//BYTE *checked=new BYTE[wid*hei];//某点是否已检查过
	BYTE chain[256];//数量判断中的像素链位置
	int connpos[256];//像素链中的“相连”（阈值小于给定值）表
	//int connpos0;//像素链中的“相连”（阈值小于给定值）块的左上角或首行某点
	int sumr=0,sumg=0,sumb=0,sumarea=0;//颜色总和，方框的内切圆面积
	for(i=0;i<wid*hei;i++){
		imageInfo[i]=255;
		if(i%wid>=0 && i%wid<wid && i/wid>=0 && i/wid<hei){
			arr[i]=chuzaCheck(i%wid,i/wid,yz);
			//arr2[i]=(arr[i]<<4)|(arr[i]>>4);
		}else{
			arr[i]=255;
			//arr2[i]=255;
		}
	}
	for(i=0;i<256;i++){
		chain[i]=255;
		connpos[i]=0;
	}
	int jp=0,jp1=1;
	for(j=0;j<hei;j++){
		jp=j*wid;
		jp1=(j+1)*wid;
		for(i=0;i<wid;i++){
			if(imageInfo[jp+i]==255){
				/*connpos0=chuzaCheck(i,j,yz);
				if(connpos0==0){
					imageInfo[jp+i]=0;
				}else if(num>=2){
					if(connpos0==8 && chuzaCheck(i+1,j,yz)==16 && i<wid-1){imageInfo[jp+i]=8;imageInfo[jp+i+1]=16;}
					else if(connpos0==4 && chuzaCheck(i-1,j+1,yz)==32 && i>0 && j<hei-1){imageInfo[jp+i]=4;imageInfo[jp1+i-1]=32;}
					else if(connpos0==2 && chuzaCheck(i,j+1,yz)==64 && j<hei-1){imageInfo[jp+i]=2;imageInfo[jp1+i]=64;}
					else if(connpos0==1 && chuzaCheck(i+1,j+1,yz)==128 && i<wid-1 && j<hei-1){imageInfo[jp+i]=1;imageInfo[jp1+i+1]=128;}
				}*/
				if(arr[jp+i]<16){
					connpos[0]=j*wid+i;
					chain[0]=arr[connpos[0]];
					l=1;
					for(k=0;k<num+hx;k++){
						//if(chain[k]==255)chain[k]=arr[connpos[k]];
						if(chain[k]==255)break;
						
						if(l<255 && i>0 && j>0 && (chain[k]&16)==16){connpos[l]=connpos[k]-wid-1;chain[l]=arr[connpos[l]];l++;}
						if(l<255 && j>0 && (chain[k]&32)==32){connpos[l]=connpos[k]-wid;chain[l]=arr[connpos[l]];l++;}
						if(l<255 && i<wid-1 && j>0 && (chain[k]&64)==64){connpos[l]=connpos[k]-wid+1;chain[l]=arr[connpos[l]];l++;}
						if(l<255 && i<wid-1 && (chain[k]&128)==128){connpos[l]=connpos[k]-1;chain[l]=arr[connpos[l]];l++;}
						if(l<255 && i<wid-1 && (chain[k]&8)==8){connpos[l]=connpos[k]+1;chain[l]=arr[connpos[l]];l++;}
						if(l<255 && i>0 && j<hei-1 && (chain[k]&4)==4){connpos[l]=connpos[k]+wid-1;chain[l]=arr[connpos[l]];l++;}
						if(l<255 && j<hei-1 && (chain[k]&2)==2){connpos[l]=connpos[k]+wid;chain[l]=arr[connpos[l]];l++;}
						if(l<255 && i<wid-1 && j<hei-1 && (chain[k]&1)==1){connpos[l]=connpos[k]+wid+1;chain[l]=arr[connpos[l]];l++;}
						
						for(m=k+1;m<l;m++){
							for(n=0;n<m;n++){
								if(connpos[n]==connpos[m] && l-1>k){
									connpos[m]=connpos[l-1];
									chain[m]=chain[l-1];
									l--;
									m--;
									break;
								}
							}
						}						
						if(l>num+hx || l>=255)break;
						if(k>=l-1)break;
					}
					if(k==l-1){
						//if(arr[connpos[k]]&arr2[connpos[k-1]]&0xf0==0){
							for(k=0;k<num && k<l;k++){
								imageInfo[connpos[k]]=chain[k];
							}
						//}
					}
				}
			}
			if(imageInfo[jp+i]!=255){
				sumr=0;
				sumg=0;
				sumb=0;
				sumarea=0;
				//connpos0=imageInfo[jp+i]&1;
				for(k=0;k<8;k++){
					if(((imageInfo[jp+i]>>(BYTE)(7-k))&1)==0){
						if(k<=3){
							m=(3-k)%3+i-1;
							n=(3-k)/3+j-1;
						}else{
							m=(k+1)%3+i-1;
							n=(k+1)/3+j-1;
						}
						if(m>=0 && n>=0 && m<wid && n<hei){
								mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
								sumb+=*mByte;
								sumg+=*(mByte+1);
								sumr+=*(mByte+2);
								sumarea++;
						}
					}
				}
				if(sumarea==0)continue;
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
				colour=(int)(sumb/sumarea);
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;

				colour=(int)(sumg/sumarea);
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
				pByte++;
				mByte++;

				colour=(int)(sumr/sumarea);
				if(colour<=0) {*pByte=0;}
				else if(colour>=255) {*pByte=255;}
				else {*pByte=colour;}
			}else{
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
				*pByte=*mByte;
				pByte++;
				mByte++;

				*pByte=*mByte;
				pByte++;
				mByte++;

				*pByte=*mByte;
			}
		}
	}
	delete []arr;
	//delete []arr2;
	preshow=true;
	Invalidate(FALSE);
}

void CImageToWordsView::OnZdyfi() 
{
	// TODO: Add your command handler code here	
	CZidingyilvjing dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateZdyfi(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}
void CImageToWordsView::ConvolutionFilter(float *arr,float offset,int leng,int lengc,int midi,int midj){	
	//int lengr=leng/lengc;//转换矩阵的行数等于它的总元素数除以它的列数
	int i=0,j=0,k=0,l=0,lk=0,m=0,n=0;//循环变量
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);;//预览图指针
	//float r=0,g=0,b=0;//转换的中间变量
	int lengr=leng/lengc;
	int *arr2=new int[leng];
	for(i=0;i<leng;i++){
		arr2[i]=(int)(arr[i]*256+0.5f);
	}
	int offset2=(int)(offset*256+0.5f);
	int r=0,g=0,b=0,arrlk=0;;//转换的中间变量
	for (j=0; j<hei; j++) {
		for (i=0; i<wid; i++) {			
			//****************初始化****************
			/*r=offset;
			g=offset;
			b=offset;*/
			r=offset2;
			g=offset2;
			b=offset2;
			//****************滤镜计算****************
			for (l=0;l<lengr;l++) {
				for (k=0;k<lengc;k++) {
					lk=l*lengc+k;
					if(lk<0 || lk>=leng)continue;
					arrlk=arr2[lk];
					if (arrlk!=0) {					
						m=k+i-midi;
						n=l+j-midj;
						if (m<0)m=0;
						if (n<0)n=0;
						if (m>=wid)m=wid-1;
						if (n>=hei)n=hei-1;
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);					
						//r+=(*(mByte+2))*(*(arr+arrlk));
						//g+=(*(mByte+1))*(*(arr+arrlk));				
						//b+=(*mByte)*(*(arr+arrlk));
						r+=mByte[2]*arrlk;
						g+=mByte[1]*arrlk;				
						b+=(*mByte)*arrlk;
					}
				}
			}
			if(leng==5){
				arrlk=arr2[4];
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);					
				r+=mByte[2]*arrlk;
				g+=mByte[1]*arrlk;				
				b+=(*mByte)*arrlk;
			}
			//****************溢出处理****************
			r=r>>8;
			g=g>>8;
			b=b>>8;
			if (r>255) {
				r=255;
			} else if (r<0) {
				r=0;
			}
		
			if (g>255) {
				g=255;
			} else if (g<0) {
				g=0;
			}		
			if (b>255) {
				b=255;
			} else if (b<0) {
				b=0;
			}			
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			*pByte=(BYTE)b;
			pByte++;
			*pByte=(BYTE)g;
			pByte++;
			*pByte=(BYTE)r;
		}
	}
	delete []arr2;
	preshow=true;
	Invalidate(FALSE);	
}
void CImageToWordsView::ConvolutionFilter(float *arr,float offset,int leng,int lengc,int midi,int midj,bool rable,bool gable,bool bable){
	//int lengr=leng/lengc;//转换矩阵的行数等于它的总元素数除以它的列数
	int i=0,j=0,arrlk=0,m=0,n=0;//循环变量
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);//预览图指针
	bool notallable=!(rable && gable && bable);
	//float r=0.0f,g=0.0f,b=0.0f;//转换的中间变量
	int *arr2=new int[leng];
	for(i=0;i<leng;i++){
		arr2[i]=(int)(arr[i]*256+0.5f);
	}
	int offset2=(int)(offset*256+0.5f);
	int r=0,g=0,b=0;//转换的中间变量
	for (j=0; j<hei; j++) {
		for (i=0; i<wid; i++) {
			//****************初始化****************
			/*r=offset;
			g=offset;
			b=offset;*/
			r=offset2;
			g=offset2;
			b=offset2;
			//****************滤镜计算****************
			for (arrlk=0;arrlk<leng;arrlk++) {
				if (*(arr+arrlk)!=0.0f) {
					m=arrlk%lengc+i-midi;
					n=arrlk/lengc+j-midj;
					if (m<0) {
						m=0;
					}
					if (n<0) {
						n=0;
					}
					if (m>=wid) {
						m=wid-1;
					}
					if (n>=hei) {
						n=hei-1;
					}
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					/*if (rable) {
						r+=(float)(*(mByte+2))*(*(arr+arrlk));
					}
					if (gable) {
						g+=(float)(*(mByte+1))*(*(arr+arrlk));
					}
					if (bable) {
						b+=(float)(*mByte)*(*(arr+arrlk));
					}*/
					if (rable) {
						r+=(float)(*(mByte+2))*(*(arr2+arrlk));
					}
					if (gable) {
						g+=(float)(*(mByte+1))*(*(arr2+arrlk));
					}
					if (bable) {
						b+=(float)(*mByte)*(*(arr2+arrlk));
					}
				}				
			}
			//****************溢出处理和未应用处理****************
			if (notallable) {
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			}
			if (rable) {
				r=r>>8;
				if (r>255) {
					r=255;
				} else if (r<0) {
					r=0;
				}
			} else {
				r=*(mByte+2);
			}
			if (gable) {
				g=g>>8;
				if (g>255) {
					g=255;
				} else if (g<0) {
					g=0;
				}
			} else {
				g=*(mByte+1);
			}
			if (bable) {
				b=b>>8;
				if (b>255) {
					b=255;
				} else if (b<0) {
					b=0;
				}
			} else {
				b=*mByte;
			}
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			*pByte=(BYTE)b;
			pByte++;
			*pByte=(BYTE)g;
			pByte++;
			*pByte=(BYTE)r;
		}
	}
	preshow=true;
	Invalidate(FALSE);
}

void OnEdgeOK(CDialog *dialog,CImageToWordsView *pView) {	
	CEdgeInput *dlg=dynamic_cast<CEdgeInput *>(dialog);
	if(dlg==NULL){
		return;
	}
	if(dlg->m_ch1){
		dlg->updateAndFilter(false);
	}
}

void CImageToWordsView::OnEdge() 
{
	// TODO: Add your command handler code here	
	CEdgeInput dlg;
	openMenuCommon(dlg,OnEdgeOK);
}

void CImageToWordsView::OnUpdateEdge(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::EdgeFilter1(int r,float sl,int rate,int bkg,int cofs){
	if(r<=0){
		resumePreview();
		preshow=true;
		Invalidate(FALSE);
		return;
	}
	int i=0,j=0,k=0,l=0,m=0,n=0;//循环变量
	BYTE* mByte;//原图指针
	BYTE* pByte;//预览图指针
	
	/*if(r>10){
		r=10;
	}*/
	int leng=r*2+1;//求平均时所用方框的边长
	int sumr,sumg,sumb,sumarea;//颜色总和，方框的内切圆面积
	int sumrprevr,sumgprevr,sumbprevr,sumareaprevr;//上边颜色总和，方框的内切圆面积
	int er,eg,eb;//r,g,b的平均值
	int nr,ng,nb;//r,g,b求边缘后的值（未考虑阈值和柔化）

	int *leftEdge=NULL;
	int *rightEdge=NULL;
	int *upEdge=NULL;
	int *downEdge=NULL;
	
	leftEdge=new int[leng];
	rightEdge=new int[leng];
	upEdge=new int[leng];
	downEdge=new int[leng];
	

	sumr=0;
	sumg=0;
	sumb=0;
	sumarea=0;
	for(l=0;l<leng;l++){
		leftEdge[l]=0;
		rightEdge[l]=0;
		for(k=0;k<leng;k++){
			m=k-r;
			n=l-r;
			if(m*m+n*n<=r*r){
				if(m>=0 && n>=0 && m<wid && n<hei){
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					sumb+=*mByte;
					sumg+=*(mByte+1);
					sumr+=*(mByte+2);
					sumarea++;
				}
				if(leftEdge[l]>=0){
					leftEdge[l]=m;
				}
				rightEdge[l]=m;
			}
		}
		upEdge[l]=leftEdge[l];
		downEdge[l]=rightEdge[l];
	}
	sumrprevr=sumr;
	sumgprevr=sumg;
	sumbprevr=sumb;
	sumareaprevr=sumarea;
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			if(i>0){
				for(l=0;l<leng;l++){
					n=j+l-r;
					if(n<0 ||  n>=hei){
						continue;
					}

					m=i-1+leftEdge[l];
					if(m>=0 && m<wid){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						sumb-=*mByte;
						sumg-=*(mByte+1);
						sumr-=*(mByte+2);
						sumarea--;
					}
					m=i+rightEdge[l];
					if(m>=0 && m<wid){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						sumb+=*mByte;
						sumg+=*(mByte+1);
						sumr+=*(mByte+2);
						sumarea++;
					}
				}
			}else if(j>0){
				sumr=sumrprevr;
				sumg=sumgprevr;
				sumb=sumbprevr;
				sumarea=sumareaprevr;
				
				for(k=0;k<leng;k++){
					m=i+k-r;
					if(m<0 ||  m>=hei){
						continue;
					}

					n=j-1+upEdge[k];
					if(n>=0 && n<hei){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						sumb-=*mByte;
						sumg-=*(mByte+1);
						sumr-=*(mByte+2);
						sumarea--;
					}

					n=j+downEdge[k];
					if(n>=0 && n<hei){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						sumb+=*mByte;
						sumg+=*(mByte+1);
						sumr+=*(mByte+2);
						sumarea++;
					}
				}

				sumrprevr=sumr;
				sumgprevr=sumg;
				sumbprevr=sumb;
				sumareaprevr=sumarea;
			}
			if(sumarea==0)continue;
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
			er=(sumr-mByte[2])/(sumarea-1);
			eg=(sumg-mByte[1])/(sumarea-1);
			eb=(sumb-mByte[0])/(sumarea-1);

			nr=(int)((mByte[2]-er)*sl+bkg+cofs*mByte[2]);
			ng=(int)((mByte[1]-eg)*sl+bkg+cofs*mByte[1]);
			nb=(int)((mByte[0]-eb)*sl+bkg+cofs*mByte[0]);

			if(nr<0){
				nr=0;
			}
			if(nr>255){
				nr=255;
			}
			if(ng<0){
				ng=0;
			}
			if(ng>255){
				ng=255;
			}
			if(nb<0){
				nb=0;
			}
			if(nb>255){
				nb=255;
			}

			if(rate<0 && rate>=-25){
				nb=nb+(ng-nb)*(-rate)/25;
			}else if(rate<-25){
				ng=ng+(nr-ng)*(-rate-25)/75;
				nb=ng;
			}else if(rate>0 && rate<=75){
				nr=nr+(ng-nr)*rate/75;
			}else if(rate>75){
				ng=ng+(nb-ng)*(rate-75)/25;
				nr=ng;
			}
			
			if(rate!=0){
				if(nr<0){
					nr=0;
				}
				if(nr>255){
					nr=255;
				}
				if(ng<0){
					ng=0;
				}
				if(ng>255){
					ng=255;
				}
				if(nb<0){
					nb=0;
				}
				if(nb>255){
					nb=255;
				}
			}

			
			pByte[2]=nr;
			pByte[1]=ng;
			pByte[0]=nb;
		}
	}

	delete []leftEdge;
	leftEdge=NULL;
	delete []rightEdge;
	rightEdge=NULL;
	delete []upEdge;
	upEdge=NULL;
	delete []downEdge;
	downEdge=NULL;

	preshow=true;
	Invalidate(FALSE);	
}

void OnStablelizeOK(CDialog *dialog,CImageToWordsView *pView) {	
	CStablelizeInput *dlg=dynamic_cast<CStablelizeInput *>(dialog);
	if(dlg==NULL){
		return;
	}
	if(dlg->m_c1==TRUE){
		dlg->getConvolutioned(false);
	}
}

void CImageToWordsView::OnStablelize() //Stablelize应为Stablize
{
	// TODO: Add your command handler code here	
	CStablelizeInput dlg;
	openMenuCommon(dlg,OnStablelizeOK);
}

void CImageToWordsView::OnUpdateStablelize(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::OnWordstransform() 
{
	// TODO: Add your command handler code here
	CImageToWordsDoc* pDoc = GetDocument();
	CWordsTransformInput dlg;
	dlg.DoModal();
	preshow=false;
	Invalidate();
}

void CImageToWordsView::OnUpdateWordstransform(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}
void CImageToWordsView::wtPreDraw(float (&arr)[10],CRect rect,float size){
	int i=0,j=0,k=0;
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);//预览图指针
	int arr0=(int)arr[0];
	RuihuaFilter(1,5,0,false);
	/*if(size==0)*/previewHeibaien(128);//YuzhiFilter(128,1.0f);

	wordGridLengr=0;
	for(i=0;i<2052;i++){
		if((int)((arr[0]+arr[4])*i)>rect.bottom){				
			break;
		}
		wordGrid[i][0]=rect.top+(int)((arr[0]+arr[4])*i);
		for(j=2;j<1026;j++){
			if((int)(arr[3]*(j-2))>rect.right){				
				break;
			}
			wordGrid[i][j]=rect.left+(int)(arr[3]*(j-2));						
		}
		wordGrid[i][1]=j;
	}
	wordGridLengr=i;
	for(i=0;i<wordGridLengr;i++){
		for(k=wordGrid[i][2];k<=wordGrid[i][wordGrid[i][1]-1];k++){
			if(k>=1 && wordGrid[i][0]>=1){
				pByte=(BYTE *)p_Image.GetPixelAddress(k-1,wordGrid[i][0]-1);
				*pByte=0;
				*(pByte+1)=0;
				*(pByte+2)=255;
			}
			if(wordGrid[i][0]+arr0<hei){
				if(k>=1 && wordGrid[i][0]+arr0>=1){
					pByte=(BYTE *)p_Image.GetPixelAddress(k-1,wordGrid[i][0]+arr0-1);
					*pByte=0;
					*(pByte+1)=0;
					*(pByte+2)=255;
				}
			}			
		}
		for(j=2;j<wordGrid[i][1];j++){
			for(k=wordGrid[i][0]+1;k<=wordGrid[i][0]+arr0-1 && k<hei;k++){
				if(k>=1 && wordGrid[i][j]>=1){
					pByte=(BYTE *)p_Image.GetPixelAddress(wordGrid[i][j]-1,k-1);
					*pByte=0;
					*(pByte+1)=0;
					*(pByte+2)=255;
				}
			}
		}
	}
	preshow=true;
	Invalidate();
}
int CImageToWordsView::getPchCh(CString str,int pos,LOGFONT *lf){
	if(pos<0){
		pos=pchsetLeng;
	}
	if(pos>65536){
		pos=65536;
	}
	int fontHeight=-wtfont.lfHeight;
	int rightCount=0,rightCountmax=0;
	int leftCount=-1,leftCountmin=32;
	int upCount=0;	
	if(fontHeight>0 && fontHeight<=32 && pos<65532 && pos>=-1){
		int i,j;
		BYTE *point=(BYTE *)ti.GetPixelAddress(0,0);
		for(j=0;j<32;j++){
			for(i=0;i<32;i++){
				point=(BYTE *)ti.GetPixelAddress(i,j);
				*point=255;
				//*(point+1)=0;
				//*(point+2)=0;
			}
		}
		CImageDC *tidc=new CImageDC(ti);
		CFont *wtcf=new CFont();
		if(lf==NULL){
			wtcf->CreateFontIndirect(&wtfont);
		}else{
			wtcf->CreateFontIndirect(lf);
		}
		CDC *pDC=CDC::FromHandle(*tidc);
		pDC->SelectObject(wtcf);
		//pDC->FillSolidRect(0,0,32,32,RGB(255,255,255));
		pDC->TextOut(0,0,str);
		
		for(j=0;j<32;j++){
			leftCount=-1;
			rightCount=0;
			for(i=0;i<32;i++){
				point=(BYTE *)ti.GetPixelAddress(i,j);
				if(*point<=200){
					if(leftCount==-1)leftCount=i;
					rightCount=i;					
				}
			}
			if(leftCount!=-1 && leftCount<leftCountmin)leftCountmin=leftCount;
			if(rightCount>rightCountmax)rightCountmax=rightCount;
			if(leftCountmin>=32){
				upCount=j+1;
			}
		}
		rightCountmax++;

		if(leftCountmin<0){
			leftCountmin=0;
		}
		if(leftCountmin>=32){
			leftCountmin=31;
		}
		if(rightCountmax<0){
			rightCountmax=0;
		}
		if(rightCountmax>32){
			rightCountmax=32;
		}
		if(leftCountmin>rightCountmax){
			rightCountmax=leftCountmin;
		}
		if(upCount<0){
			rightCount=0;
		}
		if(upCount>=32){
			rightCountmax=31;
		}


		if(pos>=0){
			for(j=0;j<32-upCount;j++){
				pchset[pos][j]=0x0;		
				for(i=0;i<32 && i<rightCountmax-leftCountmin;i++){			
					point=(BYTE *)ti.GetPixelAddress(i+leftCountmin,j+upCount);
					if(*point<=200){
						pchset[pos][j]|=1<<i;
					}				
				}
			}
		}
		wtcf->DeleteObject();
		delete tidc;
		delete wtcf;
	}
	return rightCountmax-leftCountmin;
}
int CImageToWordsView::getPchEn(CString str,int pos,LOGFONT *lf){
	if(pos<0){
		pos=pchsetLeng;
	}
	if(pos>65536){
		pos=65536;
	}
	int fontHeight=-wtfont.lfHeight;
	int rightCount=0;
	if(fontHeight>0 && fontHeight<=32 && pos<65532 && pos>=-1){
		int i,j;
		BYTE *point=(BYTE *)ti.GetPixelAddress(0,0);
		for(j=0;j<32;j++){
			for(i=0;i<32;i++){
				point=(BYTE *)ti.GetPixelAddress(i,j);
				*point=0;
				//*(point+1)=0;
				//*(point+2)=0;
			}
		}
		CImageDC *tidc=new CImageDC(ti);
		CFont *wtcf=new CFont();
		if(lf==NULL){
			wtcf->CreateFontIndirect(&wtfont);
		}else{
			wtcf->CreateFontIndirect(lf);
		}
		CDC *pDC=CDC::FromHandle(*tidc);
		pDC->SelectObject(wtcf);
		//pDC->FillSolidRect(0,0,32,32,RGB(255,255,255));
		pDC->TextOut(0,0,str);
		
		for(i=31;i>=0;i--){
			point=(BYTE *)ti.GetPixelAddress(i,0);
			if(*point<=200){
				rightCount++;
			}else{
				break;
			}
		}
		if(pos>=0){
			for(j=0;j<32;j++){
				pchset[pos][j]=0x0;
				if(j>=fontHeight){				
					continue;
				}
				for(i=0;i<32 && i<32-rightCount;i++){				
					point=(BYTE *)ti.GetPixelAddress(i,j);
					if(*point<=200){
						pchset[pos][j]|=1<<i;
					}				
				}
			}
		}
		wtcf->DeleteObject();
		delete tidc;
		delete wtcf;
	}
	return 32-rightCount;
}
void CImageToWordsView::getPchPic(UINT (&arr)[32],int srcHeight,int fontHeight,int srcWidth,int x0,int y0){
	BYTE *mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	int sum=0;//每个马赛克方格内的颜色总数
	int sumarea=0;//马赛克方格数乘3
	int i=0,j=0;//循环变量图上坐标在某个方格的宽度和高度
	int xmin=0,xmax=0,ymin=0,ymax=0;//图上坐标在某个方格的上下限
	int x=x0,y=y0;//图上坐标
	int pointsWidth=srcWidth*fontHeight/srcHeight;
	if(pointsWidth<0)pointsWidth=0;
	if(pointsWidth>32)pointsWidth=32;
	if(fontHeight>0 && fontHeight<=srcHeight && fontHeight<=32){
		for(j=0;j<32;j++){
			arr[j]=0;
			if(j>=fontHeight)continue;
			ymin=j*srcHeight/fontHeight+y0;
			ymax=(j+1)*srcHeight/fontHeight+y0;			
			for(i=0;i<pointsWidth && i<srcWidth;i++){
				xmin=i*srcHeight/fontHeight+x0;
				xmax=(i+1)*srcHeight/fontHeight+x0;
				sum=0;
				sumarea=0;
				for(y=ymin;y<ymax;y++){
					for(x=xmin;x<xmax;x++){
						if(x<wid && y<hei && x>=0 && y>=0){
							mByte=(BYTE *)m_Image.GetPixelAddress(x,y);
							sum+=*mByte+*(mByte+1)+*(mByte+2);
						}else{
							sum+=765;
						}
						sumarea+=3;
					}
				}
				if(sumarea!=0){
					if(sum/3<=127){
						arr[j]|=1<<i;
					}
				}
			}
		}
	}else if(fontHeight>0 && fontHeight<=32){
		for(j=0;j<32;j++){
			arr[j]=0;
			if(j>=fontHeight)continue;
			/*y=(int)(j*srcHeight/fontHeight+y0+0.5f);
			for(i=0;i<pointsWidth;i++){
				x=(int)(i*srcHeight/fontHeight+x0+0.5f);
				if(x<wid && y<hei && x>=0 && y>=0){
					mByte=(BYTE *)m_Image.GetPixelAddress(x,y);
					if(*mByte+*(mByte+1)+*(mByte+2)<=127){
						arr[j]|=1<<i;
					}
				}
			}*/
			y=(int)((float)j*srcHeight/fontHeight+y0+0.5f);
			for(i=0;i<pointsWidth;i++){
				x=(int)((float)i*srcHeight/fontHeight+x0+0.5f);
				if(x<wid && y<hei && x>=0 && y>=0){
					mByte=(BYTE *)m_Image.GetPixelAddress(x,y);
					sum=(*mByte+*(mByte+1)+*(mByte+2))/3;
					if(sum<=127){
						arr[j]|=1<<i;
					}
				}
			}
		}
	}
}
char* CImageToWordsView::getPchs(int ziji){
	static char wordset[65537];
	CString str;
	char wordn[3];
	char i=0,j=0;
	int n=0;
	if(ziji==0){
		str="`-=;,./~!@#$%^&*()_+{}:|<>?1234567890 \\\'\"";
		strcpy(wordset,(LPTSTR)(LPCTSTR)str);
	}else if(ziji==1){
		str="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
		strcpy(wordset,(LPTSTR)(LPCTSTR)str);
	}else if(ziji==2){
		str="`-=;,./~!@#$%^&*()_+{}|<>? abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\\\'\"";
		strcpy(wordset,(LPTSTR)(LPCTSTR)str);
	}else if(ziji==3){
		n=0;
		for(i=1;i<=7;i++){
			for(j=1;j<=94;j++){
				wordset[n]=i+0xA0;
				wordset[n+1]=j+0xA0;
				n+=2;
			}
		}
		for(j=33;j<=94;j++){
			wordset[n]=(char)0xA8;
			wordset[n+1]=j+0xA0;
			n+=2;
		}
		for(j=1;j<=94;j++){
			wordset[n]=(char)0xA9;
			wordset[n+1]=j+0xA0;
			n+=2;
		}
		wordset[n]='\0';
	}else if(ziji==4){
		n=0;
		wordset[n]=(char)0xA1;
		wordset[n+1]=(char)0xA1;
		n+=2;
		for(i=16;i<=55;i++){
			for(j=1;j<=94;j++){
				wordset[n]=i+0xA0;
				wordset[n+1]=j+0xA0;
				n+=2;
			}
		}
		wordset[n]='\0';
	}else if(ziji==5){
		n=0;
		wordset[n]=(char)0xA1;
		wordset[n+1]=(char)0xA1;
		n+=2;
		for(i=56;i<=87;i++){
			for(j=1;j<=94;j++){
				wordset[n]=i+0xA0;
				wordset[n+1]=j+0xA0;
				n+=2;
			}
		}
		wordset[n]='\0';
	}else if(ziji==6){
		n=0;
		wordset[n]=(char)0xA1;
		wordset[n+1]=(char)0xA1;
		n+=2;
		for(i=16;i<=87;i++){
			for(j=1;j<=94;j++){
				wordset[n]=i+0xA0;
				wordset[n+1]=j+0xA0;
				n+=2;
			}
		}
		wordset[n]='\0';
	}else if(ziji==7){
		n=0;
		for(i=1;i<=7;i++){
			for(j=1;j<=94;j++){
				wordset[n]=i+0xA0;
				wordset[n+1]=j+0xA0;
				n+=2;
			}
		}
		for(j=33;j<=94;j++){
			wordset[n]=(char)0xA8;
			wordset[n+1]=j+0xA0;
			n+=2;
		}
		for(j=1;j<=94;j++){
			wordset[n]=(char)0xA9;
			wordset[n+1]=j+0xA0;
			n+=2;
		}
		for(i=16;i<=87;i++){
			for(j=1;j<=94;j++){
				wordset[n]=i+0xA0;
				wordset[n+1]=j+0xA0;
				n+=2;
			}
		}
		wordset[n]='\0';
	}
	pchsetLeng=0;
	if(ziji<=2){
		for(n=0;wordset[n]!='\0' && n<65537;n++){
			wordn[0]=wordset[n];
			wordn[1]='\0';
			getPchCh(wordn,pchsetLeng);
			pchsetLeng++;
		}
	}else if(ziji<=7){
		getPchEn(" ",0);
		for(n=0;wordset[n]!='\0' && n<65536;n+=2){
			wordn[0]=wordset[n];
			wordn[1]=wordset[n+1];
			wordn[2]='\0';
			getPchCh(wordn,pchsetLeng);
			pchsetLeng++;
		}
	}
	//MessageBox(wordset);
	return wordset;
}
CString CImageToWordsView::identifyGrid(int ziji,char *wordset,int col,int row,int gridHeight,int rate){
	UINT roweor;//图片点阵与文字的行按位异或结果
	UINT picpch[32];//图片点阵
	int i=0,j=0;//循环变量
	UINT sum=0;//图片比文字多出部分的面积与文字比图片多出部分的面积的加权和
	UINT summin=102400;//sum的最小值
	UINT summini=0;//sum最小值对应的字符点阵号
	CString str;
	char wordi[3];
	if(col>=2 && col<wordGrid[row][1]-1 && row>=0 && row<wordGridLengr && pchsetLeng<=65537){
		getPchPic(picpch,gridHeight,-wtfont.lfHeight,wordGrid[row][col+1]-wordGrid[row][col],wordGrid[row][col],wordGrid[row][0]);
		for(i=0;i<pchsetLeng;i++){
			sum=0;
			for(j=0;j<32;j++){
				roweor=picpch[j]^pchset[i][j];

				sum+=bitCount(picpch[j]&roweor)*rate;
				sum+=bitCount(pchset[i][j]&roweor)*(100-rate);


			}
			if(sum<summin){
				summin=sum;
				summini=i;
			}
		}
	}
	if(ziji<=2 && summini<65537){
		wordi[0]=wordset[summini];
		wordi[1]='\0';
	}else if(ziji<=7 && summini*2+1<65537){
		wordi[0]=wordset[summini*2];
		wordi[1]=wordset[summini*2+1];
		wordi[2]='\0';
	}
	str=wordi;
	return str;
}
UINT CImageToWordsView::bitCount(UINT i){
	i=i-((i>>1)&0x55555555);
	i=(i&0x33333333)+((i>>2)&0x33333333);
	i=(i+(i>>4))&0x0f0f0f0f;
	i=i+(i>>8);
	i=i+(i>>16);
	return i&0x3f;
}

void CImageToWordsView::OnFileSave() 
{
	// TODO: Add your command handler code here
	CImageToWordsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->filename==""){
		if(!externalFilterMode){
			OnFileSaveAs();
		}
		return;
	}
	CString filenameSave=pDoc->filename;
	if(filenameSave.Right(4) ==_T(".bmp") || filenameSave.Right(4) ==_T(".BMP")){       
		//判断文件扩展名
		m_Image.Save(filenameSave,Gdiplus::ImageFormatBMP);
	}else if(filenameSave.Right(4) ==_T(".jpg") || filenameSave.Right(4) ==_T(".jpeg") || filenameSave.Right(4) ==_T(".JPG") || filenameSave.Right(4) ==_T(".JPEG")){
		m_Image.Save(filenameSave,Gdiplus::ImageFormatJPEG);
	}else if(filenameSave.Right(4) ==_T(".png") || filenameSave.Right(4) ==_T(".PNG")){
		m_Image.Save(filenameSave,Gdiplus::ImageFormatPNG);
	}
	//openNew=false;
	
}

void CImageToWordsView::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	CImageToWordsDoc* pDoc = GetDocument();
	CFileDialog dlg(FALSE,NULL,NULL,NULL,"BMP文件(*.bmp)|*.bmp|JPG文件(*.jpg;jpeg)|*.jpg;*.jpeg|PNG文件(*.png)|*.png||");
	int nStructSize = 0;
    DWORD dwVersion, dwWindowsMajorVersion, dwWindwosMinorVersion;
    dwVersion = GetVersion();
    dwWindowsMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwWindwosMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
    if(dwVersion < 0x80000000)
    {
    nStructSize = 88; //2k,xp下显示新的版本
    }
    else
    {
    nStructSize = 76; //98下显示老版本，如图1
    }
    dlg.m_ofn.lStructSize = nStructSize; //------用来检测目前的操作系统的版本信息
	CString filenameSave="",extnameSave="";
	//typedef HRESULT (*ImageSaveFunc)(char *pszFileName, REFGUID guidFileType= GUID_NULL);
	//HINSTANCE m_hModule;
	//ImageSaveFunc m_funImageSave=NULL;
	dlg.m_ofn.nFilterIndex=3;
	if(dlg.DoModal()==IDOK){
		filenameSave.Format(_T("%s"),dlg.GetPathName());
		//extnameSave = dlg.GetFileExt(); //返回选定文件的扩展文件名
		if(dlg.m_ofn.nFilterIndex==1){          
			//此处可以获取扩展名下拉框是采用的哪种过滤串
			if(filenameSave.Right(4) !=_T(".bmp")){       
				//判断文件扩展名
				filenameSave += _T(".bmp");
			}
			m_Image.Save(filenameSave,Gdiplus::ImageFormatBMP);
		}else if(dlg.m_ofn.nFilterIndex==2){
			if(filenameSave.Right(4) !=_T(".jpg") && filenameSave.Right(4) !=_T(".jpeg")){ 
				filenameSave += _T(".jpg");
			}
			m_Image.Save(filenameSave,Gdiplus::ImageFormatJPEG);
		}else if(dlg.m_ofn.nFilterIndex==3){
			if(filenameSave.Right(4) !=_T(".png")){
				filenameSave += _T(".png");
			}
			m_Image.Save(filenameSave,Gdiplus::ImageFormatPNG);
		}
		pDoc->filename.Format(_T("%s"),(LPTSTR)(LPCTSTR)(dlg.GetPathName()));
		pDoc->extname = dlg.GetFileExt(); //返回选定文件的扩展文件名

		int i=0,j=0;
		undoi=-1;
		undoimax=-1;
		undort=false;
		for(i=0;i<undoMaxTimes;i++){
			if(!undoImage[i].IsNull()){
				undoImage[i].Destroy();
			}
			//undoImage[i].Create(wid,hei,m_Image.GetBPP()>24?m_Image.GetBPP():24);
		}

		i=pDoc->filename.ReverseFind(_T('\\'));
		j=pDoc->filename.ReverseFind(_T('/'));
		int k=i>=j?i:j;
		CString filenameStr2=_T("无标题");
		if(k>=0){
			filenameStr2=pDoc->filename.Right(pDoc->filename.GetLength()-k-1);
		}else{
			filenameStr2=pDoc->filename;
		}
		CMainFrame* pMf = (CMainFrame*)AfxGetMainWnd();
		pMf->SetWindowText(filenameStr2+_T(" - ImageToWords"));
	}
	
}

void CImageToWordsView::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::OnMenuscale() 
{
	// TODO: Add your command handler code here
	CImageToWordsDoc* pDoc = GetDocument();
	CScaleInput dlg;
	if(dlg.DoModal()==IDOK){		
		cloneImage();
		preshow=false;
		Invalidate();
	}else{
		if(p_Image.GetWidth()!=wid || p_Image.GetHeight()!=hei){
			p_Image.Destroy();
			p_Image.Create(wid,hei,m_Image.GetBPP());
		}
		if(t_Image.GetWidth()!=wid || t_Image.GetHeight()!=hei){
			t_Image.Destroy();
			t_Image.Create(wid,hei,m_Image.GetBPP());
		}
		preshow=false;
		Invalidate();
	}
}

void CImageToWordsView::OnUpdateMenuscale(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}
void CImageToWordsView::ScaleFilter(int nw,int nh,int zcd,int zm){
	p_Image.Destroy();
	p_Image.Create(nw,nh,m_Image.GetBPP());
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);//预览图指针
	int i=0,j=0,k=0,l=0,m=0,n=0;
	int ixb1=0,iyb1=0;
	int ix=0,iy=0;
	int ix1=0,iy1=0;
	int ix2=0,iy2=0;
	int dx=0,dy=0;
	float x=0.0f,y=0.0f;	
	int r=0,g=0,b=0,r2=0,g2=0,b2=0;
	int sumarea=0,sumarea2=0,rate=0;
	int xzcd=zcd%3;
	int yzcd=zcd/3;
	int ld=0,ld0=0;
	//int colour;
	if(zm==0){
		for(j=0;j<nh;j++){
			for(i=0;i<nw;i++){
				x=(float)i*wid/nw;
				y=(float)j*hei/nh;
				switch(xzcd){
					case 0:
						ix=(int)x;
					case 1:
						ix=(int)(x+0.5);
					case 2:
						ix=(i%wid!=0)?(int)(x+1):int(x);
				}
				switch(yzcd){
					case 0:
						iy=(int)y;
					case 1:
						iy=(int)(y+0.5);
					case 2:
						iy=(j%wid!=0)?(int)(y+1):int(y);
				}
				if(ix<0){
					ix=0;
				}
				if(ix>=wid){
					ix=wid-1;
				}
				if(iy<0){
					iy=0;
				}
				if(iy>=hei){
					iy=hei-1;
				}
				mByte=(BYTE *)m_Image.GetPixelAddress(ix,iy);
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
				pByte[2]=mByte[2];				
				pByte[1]=mByte[1];
				pByte[0]=mByte[0];
			}
		}
	}else if(zm==1){
		if(wid<=nw && hei<=nh){
			for(j=0;j<nh;j++){
				for(i=0;i<nw;i++){				
					x=(float)i*wid/nw;
					y=(float)j*hei/nh;
					ix=(int)x;
					iy=(int)y;
					dx=(int)((x-(float)ix)*256);
					dy=(int)((y-(float)iy)*256);
					ix1=ix+1;
					iy1=iy+1;
					if(ix>=wid || ix<0){
						ix=wid-1;
					}
					if(ix1>=wid || ix1<0){
						ix1=wid-1;
					}
					if(iy>=hei || iy<0){
						iy=hei-1;
					}
					if(iy1>=hei || iy1<0){
						iy1=hei-1;
					}
					mByte=(BYTE *)m_Image.GetPixelAddress(ix,iy);
					r=(256-dx)*(256-dy)*(int)(*(mByte+2));
					g=(256-dx)*(256-dy)*(int)(*(mByte+1));
					b=(256-dx)*(256-dy)*(int)(*mByte);
					mByte=(BYTE *)m_Image.GetPixelAddress(ix1,iy);
					r+=dx*(256-dy)*(int)(*(mByte+2));
					g+=dx*(256-dy)*(int)(*(mByte+1));
					b+=dx*(256-dy)*(int)(*mByte);
					mByte=(BYTE *)m_Image.GetPixelAddress(ix,iy1);
					r+=(256-dx)*dy*(int)(*(mByte+2));
					g+=(256-dx)*dy*(int)(*(mByte+1));
					b+=(256-dx)*dy*(int)(*mByte);
					mByte=(BYTE *)m_Image.GetPixelAddress(ix1,iy1);
					r+=dx*dy*(int)(*(mByte+2));
					g+=dx*dy*(int)(*(mByte+1));
					b+=dx*dy*(int)(*mByte);
					r=r>>16;
					g=g>>16;
					b=b>>16;
					if (r>255) {
						r=255;
					} else if (r<0) {
						r=0;
					}			
					if (g>255) {
						g=255;
					} else if (g<0) {
						g=0;
					}		
					if (b>255) {
						b=255;
					} else if (b<0) {
						b=0;
					}
					pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
					*pByte=(BYTE)b;
					pByte++;
					*pByte=(BYTE)g;
					pByte++;
					*pByte=(BYTE)r;
				}
			}
		}else/* if(wid>=nw && hei>=nh)*/{
			for(j=0;j<nh;j++){
				iy=j*hei/nh;
				iy1=(j+1)*hei/nh;
				if(iy>=iy1){iy1=iy+1;}
				for(i=0;i<nw;i++){
					ix=i*wid/nw;
					ix1=(i+1)*wid/nw;
					if(ix>=ix1){ix1=ix+1;}
					r=0;
					g=0;
					b=0;
					sumarea=0;
					for(l=iy;l<iy1;l++){
						for(k=ix;k<ix1;k++){
							if(k<wid && l<hei && k>=0 && l>=0){
								mByte=(BYTE *)m_Image.GetPixelAddress(k,l);
								r+=*(mByte+2);
								g+=*(mByte+1);
								b+=*mByte;
								sumarea++;
							}						
						}
					}
					if(wid<nw){
						r2=0;
						g2=0;
						b2=0;
						sumarea2=0;
						for(l=iy;l<iy1;l++){
							for(k=ix1;k<=ix1;k++){
								if(k<wid && l<hei && k>=0 && l>=0){
									mByte=(BYTE *)m_Image.GetPixelAddress(k,l);
									r2+=*(mByte+2);
									g2+=*(mByte+1);
									b2+=*mByte;
									sumarea2++;
								}							
							}
						}
						rate=i*wid*256/nw-i*wid/nw*256;
					}else if(hei<nh){
						r2=0;
						g2=0;
						b2=0;
						sumarea2=0;
						for(l=iy1;l<=iy1;l++){
							for(k=ix;k<ix1;k++){
								if(k<wid && l<hei && k>=0 && l>=0){
									mByte=(BYTE *)m_Image.GetPixelAddress(k,l);
									r2+=*(mByte+2);
									g2+=*(mByte+1);
									b2+=*mByte;
									sumarea2++;
								}							
							}
						}
						rate=j*hei*256/nh-j*hei/nh*256;
					}else{
						rate=0;
					}
					if(sumarea!=0){
						if(rate<=0 || sumarea2==0){
							r/=sumarea;
							g/=sumarea;
							b/=sumarea;
						}else if(sumarea2!=0){
							r=((256-rate)*r/sumarea+rate*r2/sumarea2)/256;
							g=((256-rate)*g/sumarea+rate*g2/sumarea2)/256;
							b=((256-rate)*b/sumarea+rate*b2/sumarea2)/256;
						}
						if (r>255) {
							r=255;
						} else if (r<0) {
							r=0;
						}			
						if (g>255) {
							g=255;
						} else if (g<0) {
							g=0;
						}		
						if (b>255) {
							b=255;
						} else if (b<0) {
							b=0;
						}
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
						*pByte=(BYTE)b;
						pByte++;
						*pByte=(BYTE)g;
						pByte++;
						*pByte=(BYTE)r;
					}
				}
			}
		}
	}else if(zm==2){
	}else if(zm==3){
		if(wid<nw && hei<nh){
			for(j=0;j<nh;j++){
				for(i=0;i<nw;i++){				
					x=(float)i*wid/nw;
					y=(float)j*hei/nh;
					ix=(int)x;
					iy=(int)y;
					dx=(int)((x-(float)ix)*256);
					dy=(int)((y-(float)iy)*256);
					ix1=ix+1;
					iy1=iy+1;
					if(ix>=wid || ix<0){
						ix=wid-1;
					}
					if(ix1>=wid || ix1<0){
						ix1=wid-1;
					}
					if(iy>=hei || iy<0){
						iy=hei-1;
					}
					if(iy1>=hei || iy1<0){
						iy1=hei-1;
					}
					pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
					mByte=(BYTE *)m_Image.GetPixelAddress(ix,iy);					
					ld0=mByte[2]*3+mByte[1]*6+(*mByte);		
					pByte[2]=mByte[2];
					pByte[1]=mByte[1];
					*pByte=*mByte;

					mByte=(BYTE *)m_Image.GetPixelAddress(ix1,iy);
					ld=mByte[2]*3+mByte[1]*6+(*mByte);
					if(ld>ld0){
						ld0=ld;
						pByte[2]=mByte[2];
						pByte[1]=mByte[1];
						*pByte=*mByte;
					}
					
					mByte=(BYTE *)m_Image.GetPixelAddress(ix,iy1);
					ld=mByte[2]*3+mByte[1]*6+(*mByte);
					if(ld>ld0){
						ld0=ld;
						pByte[2]=mByte[2];
						pByte[1]=mByte[1];
						*pByte=*mByte;
					}

					mByte=(BYTE *)m_Image.GetPixelAddress(ix1,iy1);
					
					ld=mByte[2]*3+mByte[1]*6+(*mByte);
					if(ld>ld0){
						ld0=ld;
						pByte[2]=mByte[2];
						pByte[1]=mByte[1];
						*pByte=*mByte;
					}
				}
			}
		}else/* if(wid>=nw && hei>=nh)*/{
			for(j=0;j<nh;j++){
				iy=j*hei/nh;
				iy1=(j+1)*hei/nh;
				if(iy>=iy1){iy1=iy+1;}
				for(i=0;i<nw;i++){
					ix=i*wid/nw;
					ix1=(i+1)*wid/nw;
					if(ix>=ix1){ix1=ix+1;}
					r=0;
					g=0;
					b=0;
					ld0=2551;
					ld=2551;		
					for(l=iy;l<iy1;l++){
						for(k=ix;k<ix1;k++){
							if(k<wid && l<hei && k>=0 && l>=0){
								mByte=(BYTE *)m_Image.GetPixelAddress(k,l);								
								ld=mByte[2]*3+mByte[1]*6+(*mByte);
								if(ld<ld0){
									ld0=ld;
									m=k;
									n=l;
								}
							}						
						}
					}
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					r=mByte[2];
					g=mByte[1];
					b=*mByte;
					if(wid<nw){
						r2=0;
						g2=0;
						b2=0;
						ld0=2551;
						ld=2551;
						for(l=iy;l<iy1;l++){
							for(k=ix1;k<=ix1;k++){
								if(k<wid && l<hei && k>=0 && l>=0){
									mByte=(BYTE *)m_Image.GetPixelAddress(k,l);									
									ld=mByte[2]*3+mByte[1]*6+(*mByte);
									if(ld<ld0){
										ld0=ld;
										m=k;
										n=l;
									}
								}						
							}
						}
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						r2=mByte[2];
						g2=mByte[1];
						b2=*mByte;
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
						pByte[2]=r>r2?r:r2;
						pByte[1]=g>g2?g:g2;
						*pByte=b>b2?b:b2;
					}else if(hei<nh){
						r2=0;
						g2=0;
						b2=0;
						ld0=2551;
						ld=2551;
						for(l=iy1;l<=iy1;l++){
							for(k=ix;k<ix1;k++){
								if(k<wid && l<hei && k>=0 && l>=0){
									mByte=(BYTE *)m_Image.GetPixelAddress(k,l);									
									ld=mByte[2]*3+mByte[1]*6+(*mByte);
									if(ld<ld0){
										ld0=ld;
										m=k;
										n=l;
									}
								}							
							}
						}
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						r2=mByte[2];
						g2=mByte[1];
						b2=*mByte;
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
						pByte[2]=r>r2?r:r2;
						pByte[1]=g>g2?g:g2;
						*pByte=b>b2?b:b2;
					}else{
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
						pByte[2]=r;
						pByte[1]=g;
						*pByte=b;
					}
				}
			}
		}
	}else if(zm==4){
			if(wid<nw && hei<nh){
			for(j=0;j<nh;j++){
				for(i=0;i<nw;i++){				
					x=(float)i*wid/nw;
					y=(float)j*hei/nh;
					ix=(int)x;
					iy=(int)y;
					dx=(int)((x-(float)ix)*256);
					dy=(int)((y-(float)iy)*256);
					ix1=ix+1;
					iy1=iy+1;
					if(ix>=wid || ix<0){
						ix=wid-1;
					}
					if(ix1>=wid || ix1<0){
						ix1=wid-1;
					}
					if(iy>=hei || iy<0){
						iy=hei-1;
					}
					if(iy1>=hei || iy1<0){
						iy1=hei-1;
					}
					pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
					mByte=(BYTE *)m_Image.GetPixelAddress(ix,iy);					
					ld0=mByte[2]*3+mByte[1]*6+(*mByte);		
					pByte[2]=mByte[2];
					pByte[1]=mByte[1];
					*pByte=*mByte;

					mByte=(BYTE *)m_Image.GetPixelAddress(ix1,iy);
					ld=mByte[2]*3+mByte[1]*6+(*mByte);
					if(ld<ld0){
						ld0=ld;
						pByte[2]=mByte[2];
						pByte[1]=mByte[1];
						*pByte=*mByte;
					}
					
					mByte=(BYTE *)m_Image.GetPixelAddress(ix,iy1);
					ld=mByte[2]*3+mByte[1]*6+(*mByte);
					if(ld<ld0){
						ld0=ld;
						pByte[2]=mByte[2];
						pByte[1]=mByte[1];
						*pByte=*mByte;
					}

					mByte=(BYTE *)m_Image.GetPixelAddress(ix1,iy1);
					
					ld=mByte[2]*3+mByte[1]*6+(*mByte);
					if(ld<ld0){
						ld0=ld;
						pByte[2]=mByte[2];
						pByte[1]=mByte[1];
						*pByte=*mByte;
					}
				}
			}
		}else/* if(wid>=nw && hei>=nh)*/{
			for(j=0;j<nh;j++){
				iy=j*hei/nh;
				iy1=(j+1)*hei/nh;
				if(iy>=iy1){iy1=iy+1;}
				for(i=0;i<nw;i++){
					ix=i*wid/nw;
					ix1=(i+1)*wid/nw;
					if(ix>=ix1){ix1=ix+1;}
					r=0;
					g=0;
					b=0;
					ld0=-1;
					ld=-1;		
					for(l=iy;l<iy1;l++){
						for(k=ix;k<ix1;k++){
							if(k<wid && l<hei && k>=0 && l>=0){
								mByte=(BYTE *)m_Image.GetPixelAddress(k,l);								
								ld=mByte[2]*3+mByte[1]*6+(*mByte);
								if(ld>ld0){
									ld0=ld;
									m=k;
									n=l;
								}
							}						
						}
					}
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					r=mByte[2];
					g=mByte[1];
					b=*mByte;
					if(wid<nw){
						r2=0;
						g2=0;
						b2=0;
						ld0=-1;
						ld=-1;
						for(l=iy;l<iy1;l++){
							for(k=ix1;k<=ix1;k++){
								if(k<wid && l<hei && k>=0 && l>=0){
									mByte=(BYTE *)m_Image.GetPixelAddress(k,l);									
									ld=mByte[2]*3+mByte[1]*6+(*mByte);
									if(ld>ld0){
										ld0=ld;
										m=k;
										n=l;
									}
								}						
							}
						}
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						r2=mByte[2];
						g2=mByte[1];
						b2=*mByte;
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
						pByte[2]=r<r2?r:r2;
						pByte[1]=g<g2?g:g2;
						*pByte=b<b2?b:b2;
					}else if(hei<nh){
						r2=0;
						g2=0;
						b2=0;
						ld0=-1;
						ld=-1;
						for(l=iy1;l<=iy1;l++){
							for(k=ix;k<ix1;k++){
								if(k<wid && l<hei && k>=0 && l>=0){
									mByte=(BYTE *)m_Image.GetPixelAddress(k,l);									
									ld=mByte[2]*3+mByte[1]*6+(*mByte);
									if(ld>ld0){
										ld0=ld;
										m=k;
										n=l;
									}
								}							
							}
						}
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						r2=mByte[2];
						g2=mByte[1];
						b2=*mByte;
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
						pByte[2]=r<r2?r:r2;
						pByte[1]=g<g2?g:g2;
						*pByte=b<b2?b:b2;
					}else{
						pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
						pByte[2]=r;
						pByte[1]=g;
						*pByte=b;
					}
				}
			}
		}
	}
	preshow=true;
	tempshow=false;
	Invalidate();
}

void CImageToWordsView::OnMenutrim() 
{
	// TODO: Add your command handler code here
	CImageToWordsDoc* pDoc = GetDocument();
	CTrimInput dlg;
	if(dlg.DoModal()==IDOK){		
		cloneImage();
		preshow=false;
		Invalidate();
	}else{
		if(p_Image.GetWidth()!=wid || p_Image.GetHeight()!=hei){
			p_Image.Destroy();
			p_Image.Create(wid,hei,m_Image.GetBPP());
		}
		if(t_Image.GetWidth()!=wid || t_Image.GetHeight()!=hei){
			t_Image.Destroy();
			t_Image.Create(wid,hei,m_Image.GetBPP());
		}
		preshow=false;
		Invalidate();
	}
}

void CImageToWordsView::OnUpdateMenutrim(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::TrimFilter(int nw,int nh,int offsx,int offsy,COLORREF bkgColour,bool willRepeat){
	p_Image.Destroy();
	p_Image.Create(nw,nh,m_Image.GetBPP());
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);//预览图指针
	int i=0,j=0,k=0,l=0;
	for(j=0;j<nh;j++){
		for(i=0;i<nw;i++){
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			if(i-offsx>=0 && i-offsx<wid && j-offsy>=0 && j-offsy<hei){
				mByte=(BYTE *)m_Image.GetPixelAddress(i-offsx,j-offsy);				
				*pByte=*mByte;
				*pByte++;
				*mByte++;
				*pByte=*mByte;
				*pByte++;
				*mByte++;
				*pByte=*mByte;
			}else if(willRepeat){
				k=(i-offsx)%wid;
				l=(j-offsy)%hei;
				if(k<0){
					k+=wid;
				}
				if(l<0){
					l+=hei;
				}
				mByte=(BYTE *)m_Image.GetPixelAddress(k,l);				
				*pByte=*mByte;
				*pByte++;
				*mByte++;
				*pByte=*mByte;
				*pByte++;
				*mByte++;
				*pByte=*mByte;
			}else{
				*pByte=GetBValue(bkgColour);
				*(pByte+1)=GetGValue(bkgColour);
				*(pByte+2)=GetRValue(bkgColour);
			}
		}
	}
	preshow=true;
	Invalidate();
}

void CImageToWordsView::OnQianbi() 
{
	// TODO: Add your command handler code here
	toolMode=1;
}

void CImageToWordsView::OnUpdateQianbi(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::OnMinimumfi() 
{
	// TODO: Add your command handler code here	
	CMinimumInput dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateMinimumfi(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::MinimumFilter(int rc2,bool isCircle){
	int i=0,j=0,k=0,l=0,m=0,n=0;//循环变量
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);;//预览图指针
	int leng=rc2>0?rc2+1:2;//样本所在方框的边长
	int r=rc2>0?(rc2+1)/2:1;//样本半径
	int ldmin=2551,minm=0,minn=0;//最小亮度，最小亮度对应坐标
	int colour;//转换的中间变量
	bool minAtLeftEdge=false;//最小值是否在左边缘

	int *leftEdge=NULL;
	int *rightEdge=NULL;
	
	if(isCircle && rc2>0){
		leftEdge=new int[leng];
		rightEdge=new int[leng];

		for(l=0;l<leng;l++){
			leftEdge[l]=1;
			rightEdge[l]=1;
			for(k=0;k<leng;k++){
				m=k-r;
				n=l-r;
				if(m*m+n*n<=r*r){
					if(leftEdge[l]>=1){
						leftEdge[l]=m;
					}
					rightEdge[l]=m;
				}
			}
		}
	}
	

	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			if(i>0 && rc2>0){
				minAtLeftEdge=false;
				l=minn-j+r;
				m=minm-(i-1);
				if(m<=-r){
					minAtLeftEdge=true;
				}
				if(!minAtLeftEdge && isCircle){
					if(l>=0 && l<leng && m<=leftEdge[l]){
						minAtLeftEdge=true;
					}
				}
			}

			if(rc2>0 && (i<=0 || minAtLeftEdge)){
				ldmin=2551;
				for(l=0;l<leng;l++){
					for(k=0;k<leng;k++){
						if(!isCircle || (k-r)*(k-r)+(l-r)*(l-r)<=r*r){
							m=k+i-r;
							n=l+j-r;
							if(m>=0 && n>=0 && m<wid && n<hei){
								mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
								colour=mByte[2]*3+mByte[1]*6+mByte[0];
								if(ldmin>colour){
									ldmin=colour;
									minm=m;
									minn=n;
								}
							}
						}
					}
				}
			}else if(rc2>0 && isCircle){
				for(l=0;l<leng;l++){
					n=j+l-r;
					if(n<0 ||  n>=hei){
						continue;
					}
					m=i+rightEdge[l];
					if(m>=0 && m<wid){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						colour=mByte[2]*3+mByte[1]*6+mByte[0];
						if(ldmin>colour){
							ldmin=colour;
							minm=m;
							minn=n;
						}
					}
				}
			}else if(rc2>0 && i-r+leng-1<wid && i-r+leng-1>=0){
				m=i-r+leng-1;
				for(l=0;l<leng;l++){
					n=j+l-r;
					if(n<0 ||  n>=hei){
						continue;
					}
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					colour=mByte[2]*3+mByte[1]*6+mByte[0];
					if(ldmin>colour){
						ldmin=colour;
						minm=m;
						minn=n;
					}
				}
			}else{
				ldmin=2551;
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				colour=mByte[2]*3+mByte[1]*6+mByte[0];
				if(ldmin>colour){
					ldmin=colour;
					minm=i;
					minn=j;
				}
				m=isCircle?i+1:i;
				n=isCircle?j:j+1;
				if(m>=0 && n>=0 && m<wid && n<hei){
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					colour=mByte[2]*3+mByte[1]*6+mByte[0];
					if(ldmin>colour){
						ldmin=colour;
						minm=m;
						minn=n;
					}
				}
			}
			mByte=(BYTE *)m_Image.GetPixelAddress(minm,minn);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);				
			
			
			*pByte=*mByte;
			pByte++;
			mByte++;

			*pByte=*mByte;
			pByte++;
			mByte++;

			*pByte=*mByte;
		}
	}

	if(leftEdge!=NULL){
		delete []leftEdge;
		leftEdge=NULL;
	}
	if(rightEdge!=NULL){
		delete []rightEdge;
		rightEdge=NULL;
	}

	preshow=true;
	Invalidate(FALSE);	
}

void CImageToWordsView::OnMaximumfi() 
{
	// TODO: Add your command handler code here	
	CMaximumInput dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateMaximumfi(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::MaximumFilter(int rc2,bool isCircle){
	int i=0,j=0,k=0,l=0,m=0,n=0;//循环变量
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);;//预览图指针
	int leng=rc2>0?rc2+1:2;//样本所在方框的边长
	int r=rc2>0?(rc2+1)/2:1;//样本半径
	int ldmax=-1,maxm=0,maxn=0;//最小亮度，最小亮度对应坐标
	int colour;//转换的中间变量
	bool maxAtLeftEdge=false;//最大值是否在左边缘

	int *leftEdge=NULL;
	int *rightEdge=NULL;
	
	if(isCircle && rc2>0){
		leftEdge=new int[leng];
		rightEdge=new int[leng];

		for(l=0;l<leng;l++){
			leftEdge[l]=1;
			rightEdge[l]=1;
			for(k=0;k<leng;k++){
				m=k-r;
				n=l-r;
				if(m*m+n*n<=r*r){
					if(leftEdge[l]>=1){
						leftEdge[l]=m;
					}
					rightEdge[l]=m;
				}
			}
		}
	}

	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){

			if(i>0 && rc2>0){
				maxAtLeftEdge=false;
				l=maxn-j+r;
				m=maxm-(i-1);
				if(m<=-r){
					maxAtLeftEdge=true;
				}
				if(!maxAtLeftEdge && isCircle){
					if(l>=0 && l<leng && m<=leftEdge[l]){
						maxAtLeftEdge=true;
					}
				}
			}
			
			if(rc2>0 && (i<=0 || maxAtLeftEdge)){
				ldmax=-1;
				for(l=0;l<leng;l++){
					for(k=0;k<leng;k++){
						if(!isCircle || (k-r)*(k-r)+(l-r)*(l-r)<=r*r){
							m=k+i-r;
							n=l+j-r;
							if(m>=0 && n>=0 && m<wid && n<hei){
								mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
								colour=mByte[2]*3+mByte[1]*6+mByte[0];
								if(ldmax<colour){
									ldmax=colour;
									maxm=m;
									maxn=n;
								}
							}
						}
					}
				}
			}else if(rc2>0 && isCircle){
				for(l=0;l<leng;l++){
					n=j+l-r;
					if(n<0 ||  n>=hei){
						continue;
					}
					m=i+rightEdge[l];
					if(m>=0 && m<wid){
						mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
						colour=mByte[2]*3+mByte[1]*6+mByte[0];
						if(ldmax<colour){
							ldmax=colour;
							maxm=m;
							maxn=n;
						}
					}
				}
			}else if(rc2>0 && i-r+leng-1<wid && i-r+leng-1>=0){
				m=i-r+leng-1;
				for(l=0;l<leng;l++){
					n=j+l-r;
					if(n<0 ||  n>=hei){
						continue;
					}
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					colour=mByte[2]*3+mByte[1]*6+mByte[0];
					if(ldmax<colour){
						ldmax=colour;
						maxm=m;
						maxn=n;
					}
				}
			}else{
				ldmax=-1;
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				colour=mByte[2]*3+mByte[1]*6+mByte[0];
				if(ldmax<colour){
					ldmax=colour;
					maxm=i;
					maxn=j;
				}
				m=isCircle?i:i+1;
				n=isCircle?j+1:j;
				if(m>=0 && n>=0 && m<wid && n<hei){
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					colour=mByte[2]*3+mByte[1]*6+mByte[0];
					if(ldmax<colour){
						ldmax=colour;
						maxm=m;
						maxn=n;
					}
				}
			}
			mByte=(BYTE *)m_Image.GetPixelAddress(maxm,maxn);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);				
			
			
			*pByte=*mByte;
			pByte++;
			mByte++;

			*pByte=*mByte;
			pByte++;
			mByte++;

			*pByte=*mByte;
		}
	}
	preshow=true;
	Invalidate(FALSE);	
}

void OnKuosanOK(CDialog *dialog,CImageToWordsView *pView){
	CDiffuseInput *dlg=dynamic_cast<CDiffuseInput *>(dialog);	
	if(dlg==NULL){
		return;
	}
	if(dlg->m_c2==TRUE){
		if(dlg->m_c1==FALSE){
			pView->DiffuseFilter(dlg->bjc2,dlg->m_r1==0?false:true);
		}else{
			pView->ColourOffsetFilter(dlg->offset);
		}
	}
}

void CImageToWordsView::OnKuosan() 
{
	// TODO: Add your command handler code here	
	CDiffuseInput dlg;
	openMenuCommon(dlg,OnKuosanOK);
}

void CImageToWordsView::OnUpdateKuosan(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::DiffuseFilter(int rc2,bool isCircle){
	int i=0,j=0,k=0,l=0,m=0,n=0;//循环变量
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);;//预览图指针
	int leng=rc2+1;//样本所在方框的边长
	int r=(rc2+1)/2;//样本半径
	int circleIndex[441];
	int circleIndexLeng=0;
	if(isCircle){
		circleIndexLeng=0;
		for(l=0;l<leng;l++){
			for(k=0;k<leng;k++){
				if((k-r)*(k-r)+(l-r)*(l-r)<=r*r && circleIndexLeng<441){
					circleIndex[circleIndexLeng]=l*leng+k;
					circleIndexLeng++;
				}
			}
		}
	}
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			if(isCircle){
				k=(int)(rand()%circleIndexLeng);
				m=circleIndex[k]%leng+i-r;
				n=circleIndex[k]/leng+j-r;
			}else{
				m=(int)(rand()%leng)+i-r;
				n=(int)(rand()%leng)+j-r;
			}
			if(m<0){
				m=0;
			}else if(m>=wid){
				m=wid-1;
			}
			if(n<0){
				n=0;
			}else if(n>=hei){
				n=hei-1;
			}
			mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);				
			
			
			*pByte=*mByte;
			pByte++;
			mByte++;

			*pByte=*mByte;
			pByte++;
			mByte++;

			*pByte=*mByte;
		}
	}
	preshow=true;
	Invalidate(FALSE);	
}

void CImageToWordsView::ColourOffsetFilter(int offs){
	int i=0,j=0;//循环变量
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);//预览图指针
	int crand=0;//生成的随机数
	int crandarg=offs*2+1;//随机数的最大值加一（即颜色的最大偏移量的两倍加一）
	int colour=0;//转换的中间变量	
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);				
			
			colour=*mByte;
			crand=(int)(rand()%crandarg);
			colour=colour+crand-offs;
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}			
			pByte++;
			mByte++;
			
			colour=*mByte;
			crand=(int)(rand()%crandarg);
			colour=colour+crand-offs;
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}	
			pByte++;
			mByte++;

			colour=*mByte;
			crand=(int)(rand()%crandarg);
			colour=colour+crand-offs;
			if(colour<=0) {*pByte=0;}
			else if(colour>=255) {*pByte=255;}
			else {*pByte=colour;}
		}
	}
	preshow=true;
	Invalidate(FALSE);
}

void CImageToWordsView::OnZhongzhilvbo() 
{
	// TODO: Add your command handler code here	
	CZhongZhiLvBo dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateZhongzhilvbo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::sortInt(int *arr,int leng){
	int i,j,k=0;
	int temp;
	static int stack[1024];
	int stackTop=0;
	int stackTopMax=1020;	
	stack[stackTop]=0;
	stack[stackTop+1]=leng-1;
	stackTop+=2;
	int mini,maxj;
	bool flag=true;
	bool flagprev=true;
	while(stackTop>1 && stackTop<stackTopMax){
		stackTop-=2;
		mini=stack[stackTop];
		maxj=stack[stackTop+1];			
		if(maxj-mini>=2){
			k=(maxj-mini+1)>>1;
			temp=arr[mini+k];
			arr[mini+k]=arr[mini];
			arr[mini]=temp;
		}else if(maxj-mini==1 && arr[mini]>arr[maxj]){
			temp=arr[maxj];
			arr[maxj]=arr[mini];
			arr[mini]=temp;		
			continue;
		}else if(maxj-mini<=0){
			continue;
		}
		
		flag=true;
		flagprev=true;

		i=mini;
		j=maxj;
		k=mini;
		while(i<=j){
			flagprev=flag;
			if(flag && arr[j]<arr[k]){
				temp=arr[k];
				arr[k]=arr[j];
				arr[j]=temp;
				k=j;
				flag=!flag;
			}else if(!flag && arr[i]>arr[k]){
				temp=arr[k];
				arr[k]=arr[i];
				arr[i]=temp;
				k=i;
				flag=!flag;
			}
			if(flagprev){
				j--;
			}else{
				i++;
			}	
		}

		if(k>mini+1){
			stack[stackTop]=mini;
			stack[stackTop+1]=k-1;
			stackTop+=2;
		}
		if(k<maxj-1){
			stack[stackTop]=k+1;
			stack[stackTop+1]=maxj;
			stackTop+=2;
		}
	}
}

void CImageToWordsView::sortTable(int **arr,int leng){
	int i,j,k;
	int *temp;
	if(leng>3){
		k=leng>>1;
		temp=arr[k];
		arr[k]=arr[0];
		arr[0]=temp;
	}else if(leng==2 && arr[0][0]>arr[1][0]){
		temp=arr[1];
		arr[1]=arr[0];
		arr[0]=temp;
		return;
	}else if(leng<=1){
		return;
	}
	i=0;
	j=leng-1;
	bool flag=true;
	bool flagprev=true;

	i=0;
	j=leng-1;
	k=0;
	while(i<=j){
		flagprev=flag;
		if(flag && arr[j][0]<arr[k][0]){
			temp=arr[k];
			arr[k]=arr[j];
			arr[j]=temp;
			k=j;
			flag=!flag;
		}else if(!flag && arr[i][0]>arr[k][0]){
			temp=arr[k];
			arr[k]=arr[i];
			arr[i]=temp;
			k=i;
			flag=!flag;
		}
		if(flagprev){
			j--;
		}else{
			i++;
		}		
	}
	if(k>1){
		sortTable(arr,k);
	}
	if(k<leng-2){
		sortTable(arr+k+1,leng-k-1);
	}
}

int CImageToWordsView::mergeSortUInt(unsigned int *arr,int leng,unsigned int *arrTemp,int step0,int *exceptArray,int exceptArrayLeng){
	int i,j,k=0;
	int maxGroupi;
	int maxGroupj;
	int step=step0;
	int step2=(step<<1);
	bool arrTempIsNull=false;
	if(arrTemp==NULL){
		arrTempIsNull=true;
		arrTemp=new unsigned int[leng];
	}
	unsigned int *arr0=arr;
	unsigned int *arrt=arrTemp;
	unsigned int *tempArr=NULL;
	bool outputSrc=true;
	int a;
	int b;
	while(step<leng){
		i=0;
		j=step;
		k=0;
		step2=(step<<1);
		maxGroupi=step;
		maxGroupj=step2;
		while(i<leng && k<leng){
			if(exceptArray!=NULL && i<maxGroupi){
				a=(int)(arr0[i]>>5&0x1f);
				b=(int)(arr0[i]&0x1f);
				if(i>=maxGroupi && b>=0 && b<exceptArrayLeng && a==exceptArray[b]){
					i++;
					continue;
				}
			}
			if(j>=leng){
				arrt[k]=arr0[i];
				i++;
			}else if(j>=maxGroupj){
				arrt[k]=arr0[i];
				i++;
			}else if(i>=maxGroupi){
				arrt[k]=arr0[j];
				j++;
			}else if(arr0[i]<=arr0[j]){
				arrt[k]=arr0[i];
				i++;
			}else{
				arrt[k]=arr0[j];
				j++;
			}
			
			if(i>=maxGroupi && j>=maxGroupj){
				i+=step;
				j+=step;
				maxGroupi+=step2;
				maxGroupj+=step2;
			}
			k++;
		}
		
		tempArr=arr0;
		arr0=arrt;
		arrt=tempArr;
		outputSrc=!outputSrc;
		step<<=1;
	}
	if(arrTempIsNull && arrTemp!=NULL){
		delete []arrTemp;
		arrTemp=NULL;
	}
	arr0=NULL;
	arrt=NULL;
	return outputSrc?-k:k;
}

void CImageToWordsView::ZhongZhiLvBoFilter(int bc,int bl,int bl2,double power,int shape,bool sort){
	int i=0,j=0,k=0,l=0,m=0,n=0,p=0,q=0;//循环变量
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);//预览图指针
	BYTE* tByte=(BYTE *)t_Image.GetPixelAddress(0,0);//暂存图指针
	int colour;//转换的中间变量
	int colourmax;//转换的中间变量
	unsigned int *srcColour=new unsigned int[bc*bc+bc];
	unsigned int *tempColour=new unsigned int[bc*bc+bc];
	unsigned int *exchangeColour=NULL;
	int srcColourLeng=0;
	BYTE br,bg,bb;
		
	int r=bc/2;
	bool isCircle=(shape==1);
	
	int *leftEdge=new int[bc];
	int *rightEdge=new int[bc];

	for(l=0;l<bc;l++){
		leftEdge[l]=bc;
		rightEdge[l]=-1;
		for(k=0;k<bc;k++){
			m=k-r;
			n=l-r;
			if(!isCircle || m*m+n*n<=r*r){
				if(leftEdge[l]>=bc){
					leftEdge[l]=k;
				}
				rightEdge[l]=k;
			}
		}
		rightEdge[l]+=1;
	}

	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);				
			if(r>0){
				if(sort){
					if(i==0){
						srcColourLeng=0;
						for(l=0;l<bc;l++){
							for(k=0;k<bc;k++){
								if(!isCircle || (k-r)*(k-r)+(l-r)*(l-r)<=r*r){
									m=k+i-r;
									n=l+j-r;
									if(m>=0 && n>=0 && m<wid && n<hei){
										mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
										colour=(mByte[2]*77+mByte[1]*150+mByte[0]*29)>>8;
										srcColour[srcColourLeng]=colour<<22;
										srcColour[srcColourLeng]|=(mByte[1]>>4)<<18;
										srcColour[srcColourLeng]|=(mByte[0]>>4)<<18;
										srcColour[srcColourLeng]|=(mByte[0]>>4)<<18;
									}
								}
							}
						}
						sortInt((int *)srcColour,srcColourLeng<=441?srcColourLeng:441);
					}
					colour=srcColour[srcColourLeng>>1]&((1<<10)-1);
					tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
					tByte[0]=colour&255;
					tByte[1]=colour>>8&255;
					tByte[2]=colour>>16&255;
					p++;					
				}else{
					tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
					colour=tByte[0]+(tByte[1]<<8)+(tByte[2]<<16);
				}
				m=(colour&31)+i-r;
				n=(colour>>5)+j-r;				
				if(m>=0 && n>=0 && m<wid && n<hei){
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
					*pByte=*mByte;
					*(pByte+1)=*(mByte+1);
					*(pByte+2)=*(mByte+2);
					mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
					colourmax=pByte[0]>mByte[0]?pByte[0]-mByte[0]:mByte[0]-pByte[0];
					colour=pByte[1]>mByte[1]?pByte[1]-mByte[1]:mByte[1]-pByte[1];
					colourmax=colourmax<colour?colour:colourmax;
					colour=pByte[2]>mByte[2]?pByte[2]-mByte[2]:mByte[2]-pByte[2];
					colourmax=colourmax<colour?colour:colourmax;
					if(bl>0){
						if(colourmax>bl){
							bb=(mByte[0]-pByte[0])*pow(bl/(double)colourmax,(double)power)+pByte[0];
							bg=(mByte[1]-pByte[1])*pow(bl/(double)colourmax,(double)power)+pByte[1];
							br=(mByte[2]-pByte[2])*pow(bl/(double)colourmax,(double)power)+pByte[2];
						}else{
							bb=mByte[0];
							bg=mByte[1];
							br=mByte[2];						
						}
						if(bl2<255){
							colourmax=pByte[0]>bb?pByte[0]-bb:bb-pByte[0];
							colour=pByte[1]>bg?pByte[1]-bg:bg-pByte[1];
							colourmax=colourmax<colour?colour:colourmax;
							colour=pByte[2]>br?pByte[2]-br:br-pByte[1];
							colourmax=colourmax<colour?colour:colourmax;
							if(colourmax<255-bl2){
								pByte[0]=(bb-pByte[0])*pow(colourmax/(255.0-bl2),(double)power)+pByte[0];
								pByte[1]=(bg-pByte[1])*pow(colourmax/(255.0-bl2),(double)power)+pByte[1];
								pByte[2]=(br-pByte[2])*pow(colourmax/(255.0-bl2),(double)power)+pByte[2];
							}else{
								pByte[0]=bb;
								pByte[1]=bg;
								pByte[2]=br;
							}
						}else{
							pByte[0]=bb;
							pByte[1]=bg;
							pByte[2]=br;
						}
					}										
				}
			}else{
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
				*pByte=*mByte;
				*(pByte+1)=*(mByte+1);
				*(pByte+2)=*(mByte+2);
				if(sort){				
					tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
					tByte[0]=0;
					tByte[1]=0;
					tByte[2]=0;
				}
			}
		}
	}
	delete []srcColour;
	delete []tempColour;
	delete []leftEdge;
	delete []rightEdge;
	preshow=true;
	Invalidate(FALSE);
}

void CImageToWordsView::ZhongZhiLvBoFilterOld(int bc,int bl,int bl2,double power,int shape,bool sort){
	int i=0,j=0,k=0,l=0,m=0,n=0,p=0,q=0;//循环变量
	BYTE* mByte=(BYTE *)m_Image.GetPixelAddress(0,0);//原图指针
	BYTE* pByte=(BYTE *)p_Image.GetPixelAddress(0,0);//预览图指针
	int colour;//转换的中间变量
	int colourmax;//转换的中间变量
	int srcColour[441];
	int srcColourLeng=0;
	static int *cp=new int[17];
	static int cpl=17;
	BYTE br,bg,bb;
	if(cpl!=wid*hei){
		cpl=wid*hei;
		delete []cp;
		cp=new int[cpl];
		sort=true;
	}	
	int r=bc/2;
	bool isCircle=(shape==1);	
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);				
			if(r>0){
				if(sort){
					srcColourLeng=0;
					for(l=0;l<bc;l++){
						for(k=0;k<bc;k++){
							if(!isCircle || (k-r)*(k-r)+(l-r)*(l-r)<=r*r){
								m=k+i-r;
								n=l+j-r;
								if(m>=0 && n>=0 && m<wid && n<hei){
									mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
									colour=mByte[2]*6+mByte[1]*12+mByte[0]*2+1;
									srcColour[srcColourLeng]=(colour<<10)|l<<5|k;									
									srcColourLeng++;
								}
							}
						}
					}
					sortInt(srcColour,srcColourLeng<=441?srcColourLeng:441);
					colour=srcColour[srcColourLeng>>1]&((1<<10)-1);
					cp[p]=colour;
					p++;					
				}else{
					colour=cp[j*wid+i];
				}
				m=(colour&31)+i-r;
				n=(colour>>5)+j-r;				
				if(m>=0 && n>=0 && m<wid && n<hei){
					mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
					pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
					*pByte=*mByte;
					*(pByte+1)=*(mByte+1);
					*(pByte+2)=*(mByte+2);
					mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
					colourmax=pByte[0]>mByte[0]?pByte[0]-mByte[0]:mByte[0]-pByte[0];
					colour=pByte[1]>mByte[1]?pByte[1]-mByte[1]:mByte[1]-pByte[1];
					colourmax=colourmax<colour?colour:colourmax;
					colour=pByte[2]>mByte[2]?pByte[2]-mByte[2]:mByte[2]-pByte[2];
					colourmax=colourmax<colour?colour:colourmax;
					if(bl>0){
						if(colourmax>bl){
							bb=(mByte[0]-pByte[0])*pow(bl/(double)colourmax,(double)power)+pByte[0];
							bg=(mByte[1]-pByte[1])*pow(bl/(double)colourmax,(double)power)+pByte[1];
							br=(mByte[2]-pByte[2])*pow(bl/(double)colourmax,(double)power)+pByte[2];
						}else{
							bb=mByte[0];
							bg=mByte[1];
							br=mByte[2];						
						}
						if(bl2<255){
							colourmax=pByte[0]>bb?pByte[0]-bb:bb-pByte[0];
							colour=pByte[1]>bg?pByte[1]-bg:bg-pByte[1];
							colourmax=colourmax<colour?colour:colourmax;
							colour=pByte[2]>br?pByte[2]-br:br-pByte[1];
							colourmax=colourmax<colour?colour:colourmax;
							if(colourmax<255-bl2){
								pByte[0]=(bb-pByte[0])*pow(colourmax/(255.0-bl2),(double)power)+pByte[0];
								pByte[1]=(bg-pByte[1])*pow(colourmax/(255.0-bl2),(double)power)+pByte[1];
								pByte[2]=(br-pByte[2])*pow(colourmax/(255.0-bl2),(double)power)+pByte[2];
							}else{
								pByte[0]=bb;
								pByte[1]=bg;
								pByte[2]=br;
							}
						}else{
							pByte[0]=bb;
							pByte[1]=bg;
							pByte[2]=br;
						}
					}										
				}
			}else{
				mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);	
				*pByte=*mByte;
				*(pByte+1)=*(mByte+1);
				*(pByte+2)=*(mByte+2);
				if(sort){				
					cp[p]=0;
					p++;
				}
			}
		}
	}
	preshow=true;
	Invalidate(FALSE);
}

void CImageToWordsView::OnDropFiles(HDROP hDropInfo) 
{
	// TODO: Add your message handler code here and/or call default
	if(externalFilterMode){
		if(MessageBox("在被外部加载的模式下无法执行“打开”命令，是否进行重启？","ImageToWords",MB_YESNO)==IDYES){
			restartApp();
		}
		return;
	}

	CImageToWordsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	char fn[1024];
	::DragQueryFile(hDropInfo, 0, fn, 1023);
	pDoc->filename.Format(_T("%s"),fn);
	int i=0;
	int j=-1;
	int k=0;
	int leng=strlen(fn);
	if(leng>1023){
		leng=1023;
	}
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
		pDoc->extname.Format("%s",fn+j);
	}else{
		pDoc->extname="";
	}
	openFile();
	Invalidate();
	i=pDoc->filename.ReverseFind(_T('\\'));
	j=pDoc->filename.ReverseFind(_T('/'));
	k=i>=j?i:j;
	CString filenameStr2=_T("无标题");
	if(k>=0){
		filenameStr2=pDoc->filename.Right(pDoc->filename.GetLength()-k-1);
	}else{
		filenameStr2=pDoc->filename;
	}
	CMainFrame* pMf = (CMainFrame*)AfxGetMainWnd();
	pMf->SetWindowText(filenameStr2+_T(" - ImageToWords"));
	CScrollView::OnDropFiles(hDropInfo);
}

void CImageToWordsView::OnFileNew() 
{
	// TODO: Add your command handler code here
	if(externalFilterMode){
		if(MessageBox("在被外部加载的模式下无法执行“新建”命令，是否进行重启？","ImageToWords",MB_YESNO)==IDYES){
			restartApp();
		}
		return;
	}
	

	CImageToWordsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	copymx0=-1;
	copymy0=-1;
	copydx=0;
	copydy=0;

	pDoc->filename="";
	pDoc->extname="";

	int i=0;
	int j=0;
	if(!m_Image.IsNull()){
		m_Image.Destroy();
	}
	if(!p_Image.IsNull()){
		p_Image.Destroy();
	}
	if(!t_Image.IsNull()){
		t_Image.Destroy();
	}
	m_Image.Create(800,600,24);
	p_Image.Create(800,600,24);
	t_Image.Create(800,600,24);
	wid=m_Image.GetWidth();
	hei=m_Image.GetHeight();
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			m_Image.SetPixelInt(i,j,0xffffff);
		}
	}
	resumePreview();
	undoi=-1;
	undoimax=-1;
	undort=false;
	for(i=0;i<undoMaxTimes;i++){
		if(!undoImage[i].IsNull()){
			undoImage[i].Destroy();
		}
		//undoImage[i].Create(wid,hei,m_Image.GetBPP()>24?m_Image.GetBPP():24);
	}
	
	SetScrollSizes(MM_TEXT,CSize(wid,hei));
	delete []imageInfo;
	imageInfo=new BYTE[wid*hei];
	for(i=0;i<wid*hei;i++){
		imageInfo[i]=255;
	}
	for(i=0;i<wid*hei;i++){
		imageInfo[i]=255;
	}
	recordUndo();
	Invalidate();
	
	CMainFrame* pMf = (CMainFrame*)AfxGetMainWnd();
	pMf->SetWindowText(_T("无标题 - ImageToWords"));
}

void CImageToWordsView::Texture1FilterPreload(bool willRepaint){
	int i=0,j=0,k=0,l=0;
	BYTE* mByte;
	BYTE* pByte;
	BYTE* tByte;
	int widh=wid>>1;
	int heih=hei>>1;
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			k=i+widh;
			l=j+heih;
			if(k>=wid){
				k-=wid;
			}
			if(l>=hei){
				l-=hei;
			}
            mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(k,l);
			tByte=(BYTE *)t_Image.GetPixelAddress(k,l);
			*pByte=*mByte;
			*tByte=*mByte;
			pByte++;
			tByte++;
			mByte++;
			*pByte=*mByte;
			*tByte=*mByte;
			pByte++;
			tByte++;
			mByte++;
			*pByte=*mByte;
			*tByte=*mByte;
		}
	}
	if(willRepaint){
		preshow=true;
		tempshow=false;
		Invalidate(FALSE);
	}
}



void CImageToWordsView::Texture1Filter(int offset,int rate,int direction){
	Texture1FilterPreload(false);
	int i=0,j=0;
	BYTE* pByte;
	BYTE* tByte;
	offset++;
	int widh=wid>>1;
	int heih=hei>>1;
	int maxOffset;
	if(direction==1){
		maxOffset=widh-1;
	}else if(direction==2){
		maxOffset=heih-1;
	}else{
		maxOffset=widh-1<=heih-1?widh-1:heih-1;
	}
	if(offset>maxOffset){
		offset=maxOffset;
	}
	if(offset<=1){
		preshow=true;
		tempshow=false;
		Invalidate(FALSE);
		return;
	}
	int x1=(widh-offset)*(100-rate)/100;
	int y1=(heih-offset)*(100-rate)/100;
	int x2=widh+offset-1;
	int y2=heih+offset-1;

	int x3=(widh-offset)*rate/100+widh+offset-1;
	int y3=(heih-offset)*(100-rate)/100;
	int x4=widh-offset;
	int y4=heih+offset-1;

	int x5=(widh-offset)*(100-rate)/100;
	int y5=(heih-offset)*rate/100+heih+offset-1;
	int x6=widh+offset-1;
	int y6=heih-offset;

	int x7=(widh-offset)*rate/100+widh+offset-1;
	int y7=(heih-offset)*rate/100+heih+offset-1;
	int x8=widh-offset;
	int y8=heih-offset;

	double scalex1=(x2-x1)/(double)(widh-1-x1);
	double scaley1=(y2-y1)/(double)(heih-1-y1);

	double scalex3=(x4-x3)/(double)(widh-x3);
	double scaley3=(y4-y3)/(double)(heih-1-y3);

	double scalex5=(x6-x5)/(double)(widh-1-x5);
	double scaley5=(y6-y5)/(double)(heih-y5);

	double scalex7=(x8-x7)/(double)(widh-x7);
	double scaley7=(y8-y7)/(double)(heih-y7);

	double px0=0,py0=0;
	double prate=0,prate2=0;
	int r=0,g=0,b=0;
	int r1=0,g1=0,b1=0;
	int r2=0,g2=0,b2=0;
	if(direction==0 || direction==1){
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
				tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
				if(i<x1 || i>x3){
					r=tByte[2];
					g=tByte[1];
					b=tByte[0];
				}else if(i>=x1 && i<x4){
					px0=i+(1-scalex1)/(scalex1*(x2-x1))*(i-x1)*(i-x1);
					if(px0<0){
						px0=0;
					}
					if(px0>=wid-1){
						px0=wid-1;
					}

					prate=px0-(int)px0;

					tByte=(BYTE *)t_Image.GetPixelAddress((int)px0,j);
					r1=tByte[2];
					g1=tByte[1];
					b1=tByte[0];
					if((int)px0+1<wid){
						tByte=(BYTE *)t_Image.GetPixelAddress((int)px0+1,j);
						r2=tByte[2];
						g2=tByte[1];
						b2=tByte[0];
					}else{
						r2=r1;
						g2=g1;
						b2=b1;
					}
					r=r1*(1-prate)+r2*prate+0.5;
					g=g1*(1-prate)+g2*prate+0.5;
					b=b1*(1-prate)+b2*prate+0.5;
				}else if(i>x2 && i<=x3){
					px0=i+(1-scalex3)/(scalex3*(x4-x3))*(i-x3)*(i-x3);
					if(px0<0){
						px0=0;
					}
					if(px0>=wid-1){
						px0=wid-1;
					}

					prate=px0-(int)px0;

					tByte=(BYTE *)t_Image.GetPixelAddress((int)px0,j);
					r1=tByte[2];
					g1=tByte[1];
					b1=tByte[0];
					if((int)px0+1<wid){
						tByte=(BYTE *)t_Image.GetPixelAddress((int)px0+1,j);
						r2=tByte[2];
						g2=tByte[1];
						b2=tByte[0];
					}else{
						r2=r1;
						g2=g1;
						b2=b1;
					}
					r=r1*(1-prate)+r2*prate+0.5;
					g=g1*(1-prate)+g2*prate+0.5;
					b=b1*(1-prate)+b2*prate+0.5;
				}else{
					px0=i+(1-scalex1)/(scalex1*(x2-x1))*(i-x1)*(i-x1);
					if(px0<0){
						px0=0;
					}
					if(px0>=wid-1){
						px0=wid-1;
					}

					prate=px0-(int)px0;
					prate2=(i-x4)/(double)(x2-x4);

					tByte=(BYTE *)t_Image.GetPixelAddress((int)px0,j);
					r1=tByte[2];
					g1=tByte[1];
					b1=tByte[0];
					if((int)px0+1<wid){
						tByte=(BYTE *)t_Image.GetPixelAddress((int)px0+1,j);
						r2=tByte[2];
						g2=tByte[1];
						b2=tByte[0];
					}else{
						r2=r1;
						g2=g1;
						b2=b1;
					}
					r=(1-prate2)*(r1*(1-prate)+r2*prate)+0.5;
					g=(1-prate2)*(g1*(1-prate)+g2*prate)+0.5;
					b=(1-prate2)*(b1*(1-prate)+b2*prate)+0.5;

					px0=i+(1-scalex3)/(scalex3*(x4-x3))*(i-x3)*(i-x3);
					if(px0<0){
						px0=0;
					}
					if(px0>=wid-1){
						px0=wid-1;
					}

					prate=px0-(int)px0;

					tByte=(BYTE *)t_Image.GetPixelAddress((int)px0,j);
					r1=tByte[2];
					g1=tByte[1];
					b1=tByte[0];
					if((int)px0+1<wid){
						tByte=(BYTE *)t_Image.GetPixelAddress((int)px0+1,j);
						r2=tByte[2];
						g2=tByte[1];
						b2=tByte[0];
					}else{
						r2=r1;
						g2=g1;
						b2=b1;
					}
					r+=prate2*(r1*(1-prate)+r2*prate)+0.5;
					g+=prate2*(g1*(1-prate)+g2*prate)+0.5;
					b+=prate2*(b1*(1-prate)+b2*prate)+0.5;
				}

				if(r<0){
					r=0;
				}
				if(r>255){
					r=255;
				}
				if(g<0){
					g=0;
				}
				if(g>255){
					g=255;
				}
				if(b<0){
					b=0;
				}
				if(b>255){
					b=255;
				}
				pByte[2]=r;
				pByte[1]=g;
				pByte[0]=b;
			}
		}
	}
	if(direction==0){
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
				tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
				tByte[2]=pByte[2];
				tByte[1]=pByte[1];
				tByte[0]=pByte[0];
			}
		}
	}
	if(direction==0 || direction==2){
		for(j=0;j<hei;j++){
			for(i=0;i<wid;i++){
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
				tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
				if(j<y1 || j>y5){
					r=tByte[2];
					g=tByte[1];
					b=tByte[0];
				}else if(j>=y1 && j<y6){
					py0=j+(1-scaley1)/(scaley1*(y2-y1))*(j-y1)*(j-y1);
					if(py0<0){
						py0=0;
					}
					if(py0>=hei-1){
						py0=hei-1;
					}

					prate=py0-(int)py0;

					tByte=(BYTE *)t_Image.GetPixelAddress(i,(int)py0);
					r1=tByte[2];
					g1=tByte[1];
					b1=tByte[0];
					if((int)py0+1<hei){
						tByte=(BYTE *)t_Image.GetPixelAddress(i,(int)py0+1);
						r2=tByte[2];
						g2=tByte[1];
						b2=tByte[0];
					}else{
						r2=r1;
						g2=g1;
						b2=b1;
					}
					r=r1*(1-prate)+r2*prate+0.5;
					g=g1*(1-prate)+g2*prate+0.5;
					b=b1*(1-prate)+b2*prate+0.5;
				}else if(j>y2 && j<=y5){
					py0=j+(1-scaley5)/(scaley5*(y6-y5))*(j-y5)*(j-y5);
					if(py0<0){
						py0=0;
					}
					if(py0>=hei-1){
						py0=hei-1;
					}

					prate=py0-(int)py0;

					tByte=(BYTE *)t_Image.GetPixelAddress(i,(int)py0);
					r1=tByte[2];
					g1=tByte[1];
					b1=tByte[0];
					if((int)py0+1<hei){
						tByte=(BYTE *)t_Image.GetPixelAddress(i,(int)py0+1);
						r2=tByte[2];
						g2=tByte[1];
						b2=tByte[0];
					}else{
						r2=r1;
						g2=g1;
						b2=b1;
					}
					r=r1*(1-prate)+r2*prate+0.5;
					g=g1*(1-prate)+g2*prate+0.5;
					b=b1*(1-prate)+b2*prate+0.5;
				}else{
					py0=j+(1-scaley1)/(scaley1*(y2-y1))*(j-y1)*(j-y1);
					if(py0<0){
						py0=0;
					}
					if(py0>=hei-1){
						py0=hei-1;
					}

					prate=py0-(int)py0;
					prate2=(j-y6)/(double)(y2-y6);

					tByte=(BYTE *)t_Image.GetPixelAddress(i,(int)py0);
					r1=tByte[2];
					g1=tByte[1];
					b1=tByte[0];
					if((int)py0+1<hei){
						tByte=(BYTE *)t_Image.GetPixelAddress(i,(int)py0+1);
						r2=tByte[2];
						g2=tByte[1];
						b2=tByte[0];
					}else{
						r2=r1;
						g2=g1;
						b2=b1;
					}
					r=(1-prate2)*(r1*(1-prate)+r2*prate)+0.5;
					g=(1-prate2)*(g1*(1-prate)+g2*prate)+0.5;
					b=(1-prate2)*(b1*(1-prate)+b2*prate)+0.5;

					py0=j+(1-scaley5)/(scaley5*(y6-y5))*(j-y5)*(j-y5);
					if(py0<0){
						py0=0;
					}
					if(py0>=hei-1){
						py0=hei-1;
					}

					prate=py0-(int)py0;

					tByte=(BYTE *)t_Image.GetPixelAddress(i,(int)py0);
					r1=tByte[2];
					g1=tByte[1];
					b1=tByte[0];
					if((int)py0+1<hei){
						tByte=(BYTE *)t_Image.GetPixelAddress(i,(int)py0+1);
						r2=tByte[2];
						g2=tByte[1];
						b2=tByte[0];
					}else{
						r2=r1;
						g2=g1;
						b2=b1;
					}
					r+=prate2*(r1*(1-prate)+r2*prate)+0.5;
					g+=prate2*(g1*(1-prate)+g2*prate)+0.5;
					b+=prate2*(b1*(1-prate)+b2*prate)+0.5;
				}

				if(r<0){
					r=0;
				}
				if(r>255){
					r=255;
				}
				if(g<0){
					g=0;
				}
				if(g>255){
					g=255;
				}
				if(b<0){
					b=0;
				}
				if(b>255){
					b=255;
				}
				pByte[2]=r;
				pByte[1]=g;
				pByte[0]=b;
			}
		}
	}
	preshow=true;
	tempshow=false;
	Invalidate(FALSE);
}

void OnApplyTexture1Filter(CDialog *dialog,CImageToWordsView *pView){
	int i=0,j=0,k=0,l=0;
	BYTE* pByte;
	BYTE* tByte;
	int wid0=pView->wid;
	int hei0=pView->hei;
	int widh=wid0>>1;
	int heih=hei0>>1;
	for(j=0;j<hei0;j++){
		for(i=0;i<wid0;i++){
			pByte=(BYTE *)pView->p_Image.GetPixelAddress(i,j);
			tByte=(BYTE *)pView->t_Image.GetPixelAddress(i,j);
			*tByte=*pByte;
			pByte++;
			tByte++;
			*tByte=*pByte;
			pByte++;
			tByte++;
			*tByte=*pByte;
		}
	}
	for(j=0;j<hei0;j++){
		for(i=0;i<wid0;i++){
			k=i+widh;
			l=j+heih;
			if(k>=wid0){
				k-=wid0;
			}
			if(l>=hei0){
				l-=hei0;
			}
			pByte=(BYTE *)pView->p_Image.GetPixelAddress(i,j);
			tByte=(BYTE *)pView->t_Image.GetPixelAddress(k,l);
			*pByte=*tByte;
			pByte++;
			tByte++;
			*pByte=*tByte;
			pByte++;
			tByte++;
			*pByte=*tByte;
		}
	}
}


void CImageToWordsView::OnTexture1() 
{
	// TODO: Add your command handler code here
	CTexture1Input dlg;
	openMenuCommon(dlg,OnApplyTexture1Filter);
}

void CImageToWordsView::OnUpdateTexture1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}


void CImageToWordsView::OnMenuperspective() 
{
	// TODO: Add your command handler code here
	CPerspectiveInput dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateMenuperspective(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::PerspectiveFilter(int scale,int offset){
	int i=0,j=0;
	BYTE* mByte;
	BYTE* pByte;
	double PI=3.141592653589793;
	double x0=(tan(scale*0.5*PI/180)+tan(offset*PI/180))*hei;
	double xt=(-tan(scale*0.5*PI/180)+tan(offset*PI/180))*hei+wid-1;
	if(x0+1>xt){
		double xmid=(x0+xt)*0.5;
		x0=xmid-0.5;
		xt=xmid+0.5;
	}
	double li,i0,it;
	double px0,py0,pratex,pratey;
	int r,g,b;
	int r1,g1,b1;
	int r2,g2,b2;
	int r3,g3,b3;
	int r4,g4,b4;
	if(hei<=1){
		return;
	}
	for(j=0;j<hei;j++){
		li = (hei-1) / ( (hei-1-j)/(xt-x0) + j/(double)(wid-1) );

		py0=scale==0?j:(hei-1)*( (li-xt+x0)/(wid-1-xt+x0) );
		if(py0<0){
			py0=0;
		}
		if(py0>=hei-1){
			py0=hei-1;
		}
		pratey=py0-int(py0);

		i0=x0*(hei-py0-1)/(hei-1);
		it=(xt-wid+1)*(hei-py0-1)/(hei-1)+wid-1;
		for(i=0;i<wid;i++){
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			px0=i*(it-i0)/(wid-1)+i0;
			if(px0<0){
				px0=0;
			}
			if(px0>=wid-1){
				px0=wid-1;
			}
			
			pratex=px0-int(px0);

			mByte=(BYTE *)m_Image.GetPixelAddress((int)px0,(int)py0);
			r1=mByte[2];
			g1=mByte[1];
			b1=mByte[0];

			if((int)px0+1<wid){
				mByte=(BYTE *)m_Image.GetPixelAddress((int)px0+1,(int)py0);
				r2=mByte[2];
				g2=mByte[1];
				b2=mByte[0];
			}else{
				r2=r1;
				g2=g1;
				b2=b1;
			}

			if((int)py0+1<hei){
				mByte=(BYTE *)m_Image.GetPixelAddress((int)px0,(int)py0+1);
				r3=mByte[2];
				g3=mByte[1];
				b3=mByte[0];
			}else{
				r3=r1;
				g3=g1;
				b3=b1;
			}

			if((int)px0+1<wid && (int)py0+1<hei){
				mByte=(BYTE *)m_Image.GetPixelAddress((int)px0+1,(int)py0+1);
				r4=mByte[2];
				g4=mByte[1];
				b4=mByte[0];
			}else if((int)px0+1<wid){
				r4=r2;
				g4=g2;
				b4=b2;
			}else if((int)py0+1<hei){
				r4=r3;
				g4=g3;
				b4=b3;
			}else{
				r4=r1;
				g4=g1;
				b4=b1;
			}


			r=(r1*(1-pratex)+r2*pratex)*(1-pratey)+(r3*(1-pratex)+r4*pratex)*pratey;
			g=(g1*(1-pratex)+g2*pratex)*(1-pratey)+(g3*(1-pratex)+g4*pratex)*pratey;
			b=(b1*(1-pratex)+b2*pratex)*(1-pratey)+(b3*(1-pratex)+b4*pratex)*pratey;
			
			if(r<0){
				r=0;
			}
			if(r>255){
				r=255;
			}
			if(g<0){
				g=0;
			}
			if(g>255){
				g=255;
			}
			if(b<0){
				b=0;
			}
			if(b>255){
				b=255;
			}
			pByte[2]=r;
			pByte[1]=g;
			pByte[0]=b;
		}
	}
	
	preshow=true;
	tempshow=false;
	Invalidate(FALSE);
}

void CImageToWordsView::OnMenurotate() 
{
	// TODO: Add your command handler code here
	CRotateInput dlg;
	openMenuCommon(dlg);
}

void CImageToWordsView::OnUpdateMenurotate(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::RotateFilter(double angle,int mode,COLORREF bkgColour){
	bool linearMode=false;
	int i=0,j=0;
	BYTE* mByte;
	BYTE* pByte;
	double PI=3.141592653589793;
	double sinangle=-sin(angle*PI/180);
	double cosangle=cos(angle*PI/180);
	double xmid=(wid-1)*0.5;
	double ymid=(hei-1)*0.5;
	double px0,py0,pratex,pratey;
	int r,g,b;
	int r1,g1,b1;
	int r2,g2,b2;
	int r3,g3,b3;
	int r4,g4,b4;
	int r0=GetRValue(bkgColour);
	int g0=GetGValue(bkgColour);
	int b0=GetBValue(bkgColour);
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			px0=(i-xmid)*cosangle-(j-ymid)*sinangle+xmid;
			py0=(i-xmid)*sinangle+(j-ymid)*cosangle+ymid;

			

			pratex=px0-int(px0);
			pratey=py0-int(py0);
			
			if(mode==1){
				if(pratex>0.5){
					px0++;
				}
				if(pratey>0.5){
					py0++;
				}
				if((int)px0>=0 && (int)px0<wid && (int)py0>=0 && (int)py0<hei){
					mByte=(BYTE *)m_Image.GetPixelAddress((int)px0,(int)py0);
					r=mByte[2];
					g=mByte[1];
					b=mByte[0];
				}else{
					r=r0;
					g=g0;
					b=b0;				
				}
				pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
				pByte[2]=r;
				pByte[1]=g;
				pByte[0]=b;
				continue;
			}
			
			if((int)px0>=0 && (int)px0<wid && (int)py0>=0 && (int)py0<hei){
				mByte=(BYTE *)m_Image.GetPixelAddress((int)px0,(int)py0);
				r1=mByte[2];
				g1=mByte[1];
				b1=mByte[0];
			}else{
				r1=r0;
				g1=g0;
				b1=b0;				
			}

			if((int)px0+1>=0 && (int)px0+1<wid && (int)py0>=0 && (int)py0<hei){
				mByte=(BYTE *)m_Image.GetPixelAddress((int)px0+1,(int)py0);
				r2=mByte[2];
				g2=mByte[1];
				b2=mByte[0];
			}else{
				r2=r0;
				g2=g0;
				b2=b0;
			}

			if((int)px0>=0 && (int)px0<wid && (int)py0+1>=0 && (int)py0+1<hei){
				mByte=(BYTE *)m_Image.GetPixelAddress((int)px0,(int)py0+1);
				r3=mByte[2];
				g3=mByte[1];
				b3=mByte[0];
			}else{
				r3=r0;
				g3=g0;
				b3=b0;
			}

			if((int)px0+1>=0 && (int)px0+1<wid && (int)py0+1>=0 && (int)py0+1<hei){
				mByte=(BYTE *)m_Image.GetPixelAddress((int)px0+1,(int)py0+1);
				r4=mByte[2];
				g4=mByte[1];
				b4=mByte[0];
			}else{
				r4=r0;
				g4=g0;
				b4=b0;
			}

			
			r=(r1*(1-pratex)+r2*pratex)*(1-pratey)+(r3*(1-pratex)+r4*pratex)*pratey;
			g=(g1*(1-pratex)+g2*pratex)*(1-pratey)+(g3*(1-pratex)+g4*pratex)*pratey;
			b=(b1*(1-pratex)+b2*pratex)*(1-pratey)+(b3*(1-pratex)+b4*pratex)*pratey;
			
			if(r<0){
				r=0;
			}
			if(r>255){
				r=255;
			}
			if(g<0){
				g=0;
			}
			if(g>255){
				g=255;
			}
			if(b<0){
				b=0;
			}
			if(b>255){
				b=255;
			}

			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			pByte[2]=r;
			pByte[1]=g;
			pByte[0]=b;
		}
	}
	
	preshow=true;
	tempshow=false;
	Invalidate(FALSE);
}

void CImageToWordsView::OnEditPaste() 
{
	// TODO: Add your command handler code here
	if(!OpenClipboard())
	{
		return;
	}
	//获得剪贴板数据
	HBITMAP handle = (HBITMAP)GetClipboardData(CF_BITMAP);
	if(handle==NULL){
		CloseClipboard();
		return;
	}
	CBitmap *bmp = CBitmap::FromHandle(handle);
	if(bmp==NULL){
		CloseClipboard();
		return;
	}
	BITMAP bmpInfo;
	bmp->GetBitmap(&bmpInfo);

	wid=bmpInfo.bmWidth;
	hei=bmpInfo.bmHeight;
	
	
	

	CImageToWordsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->filename="";
	pDoc->extname="";

	int i=0;
	int j=0;
	if(!m_Image.IsNull()){
		m_Image.Destroy();
	}
	if(!p_Image.IsNull()){
		p_Image.Destroy();
	}
	if(!t_Image.IsNull()){
		t_Image.Destroy();
	}
	m_Image.Create(wid,hei,24);
	p_Image.Create(wid,hei,24);
	t_Image.Create(wid,hei,24);

	CImageDC imageDC(m_Image);
	CDC bmpDC;
	bmpDC.CreateCompatibleDC(NULL);
	bmpDC.SelectObject(bmp);
	::BitBlt(imageDC,0,0,wid,hei,bmpDC,0,0,SRCCOPY);
	bmpDC.DeleteDC();

	CloseClipboard();

	resumePreview();
	undoi=-1;
	undoimax=-1;
	undort=false;
	for(i=0;i<undoMaxTimes;i++){
		if(!undoImage[i].IsNull()){
			undoImage[i].Destroy();
		}
		//undoImage[i].Create(wid,hei,m_Image.GetBPP()>24?m_Image.GetBPP():24);
	}
	
	SetScrollSizes(MM_TEXT,CSize(wid,hei));
	delete []imageInfo;
	imageInfo=new BYTE[wid*hei];
	for(i=0;i<wid*hei;i++){
		imageInfo[i]=255;
	}
	for(i=0;i<wid*hei;i++){
		imageInfo[i]=255;
	}
	recordUndo();
	Invalidate();
	CMainFrame* pMf = (CMainFrame*)AfxGetMainWnd();
	pMf->SetWindowText(_T("无标题 - ImageToWords"));
}

void CImageToWordsView::OnEditCopy() 
{
	// TODO: Add your command handler code here
	if(m_Image.IsNull() || !OpenClipboard()){
		return;
	}
	EmptyClipboard();
	CBitmap * bmp = new CBitmap();
	CClientDC cdc(AfxGetMainWnd());
	
	CDC dc;
	dc.CreateCompatibleDC(&cdc);
	bmp->CreateCompatibleBitmap(&cdc,wid,hei);
	dc.SelectObject(bmp);
	
	m_Image.Draw(dc,0,0);

	//复制数据到剪贴板
	SetClipboardData(CF_BITMAP,bmp->m_hObject);
	CloseClipboard();
	dc.DeleteDC();
	bmp->DeleteObject();
	delete bmp;
}

void CImageToWordsView::OnEditCut() 
{
	// TODO: Add your command handler code here
	OnEditCopy();
	OnFileNew();
}

void CImageToWordsView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint pointScroll=GetScrollPosition();
	mx0=pointScroll.x+point.x;
	my0=pointScroll.y+point.y;
	mx02=mx0;
	my02=my0;
	mxp=mx0;
	myp=my0;
	linePos=0.0;
	static CMainFrame *pMf=NULL;
	BYTE *mByte=NULL;
	
	if(toolMode!=0){
		if(pMf==NULL){
			pMf=(CMainFrame *)AfxGetMainWnd();
		}
		if(pMf==NULL){
			CScrollView::OnLButtonDown(nFlags, point);
			return;
		}
		pMf->m_wndDlgBar.updateVariables();		
	}
	if(toolMode==-1 && mx0>=0 && mx0<wid && my0>=0 && my0<hei){
		mByte=(BYTE *)m_Image.GetPixelAddress(mx0,my0);
		pMf->m_wndDlgBar.color=mByte[2]<<16|mByte[1]<<8|mByte[0];
		pMf->m_wndDlgBar.updateInterface();
	}
	if(toolMode==1){
		resumePreview();
		clearTempImage();
		if(pMf->m_wndDlgBar.m_check1==FALSE){
			drawPoint(mx0,my0,pMf->m_wndDlgBar.color,pMf->m_wndDlgBar.m_e1,pMf->m_wndDlgBar.m_e2,100);
		}
		preshow=true;
		Invalidate(FALSE);
		painting=true;
	}
	if(toolMode==2){
		if((nFlags&MK_SHIFT)!=0){
			copymx0=mx0;
			copymy0=my0;
			copydx=0;
			copydy=0;
			resumePreview();
		}else if(copymx0>=0 && copymy0>=0){
			if(copydx==0 && copydy==0){
				copydx=mx0-copymx0;
				copydy=my0-copymy0;
			}
			resumePreview();
			clearTempImage();
			if(pMf->m_wndDlgBar.m_check1==FALSE){
				drawPoint(mx0,my0,pMf->m_wndDlgBar.color,pMf->m_wndDlgBar.m_e1,pMf->m_wndDlgBar.m_e2,100);
			}
			preshow=true;
			Invalidate(FALSE);
			painting=true;
		}else{
			MessageBox("按住Shift键点击鼠标以确定仿制原点");
		}
	}
	CScrollView::OnLButtonDown(nFlags, point);
}

void CImageToWordsView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	mouseX=point.x;
	mouseY=point.y;
	//Invalidate();
	if((nFlags&MK_LBUTTON)==0 || !painting){
		CScrollView::OnMouseMove(nFlags, point);
		return;
	}

	static CMainFrame *pMf=NULL;
	if(pMf==NULL){
		pMf=(CMainFrame *)AfxGetMainWnd();
	}
	if(pMf==NULL){
		CScrollView::OnMouseMove(nFlags, point);
		return;
	}
	

	CPoint pointScroll=GetScrollPosition();
	int mxt=pointScroll.x+point.x;
	int myt=pointScroll.y+point.y;
	double intervalt=pMf->m_wndDlgBar.m_e1*0.25;
	if(intervalt<1){
		intervalt=1;
	}
	double dx,dy,d,t;
	float pxt,pyt;
	if(toolMode==1 || toolMode==2 && (copydx!=0 || copydy!=0)){
		//resumePreview();
		//clearTempImage();
		//drawLine(mxp,myp,mxt,myt,0,10,0,100);
		mxp=mxt;
		myp=myt;
		/*if(abs(mxt-mx0)>5 || abs(myt-my0)>5){
			drawLine(mx0,my0,mxt,myt,pMf->m_wndDlgBar.color,pMf->m_wndDlgBar.m_e1,pMf->m_wndDlgBar.m_e2,100);
			mx0=mxt;
			my0=myt;
		}*/
		if(mxt!=mx0 || myt!=my0){
			if(pMf->m_wndDlgBar.m_check1==FALSE){
				dx=mxt-mx0;
				dy=myt-my0;
				d=sqrt(dx*dx+dy*dy);			
				if(linePos==0.0){
					linePos-=intervalt;
				}
				linePos+=d;
				while(linePos>=0.0){
					t=(d-linePos)/d;
					pxt=(float)(mx0+t*dx);
					pyt=(float)(my0+t*dy);
					if(toolMode==1){
						drawPoint(pxt,pyt,pMf->m_wndDlgBar.color,pMf->m_wndDlgBar.m_e1,pMf->m_wndDlgBar.m_e2,100);
					}else if(toolMode==2){
						copyPoint(pxt,pyt,copydx,copydy,pMf->m_wndDlgBar.m_e1,pMf->m_wndDlgBar.m_e2,100);
					}
					linePos-=intervalt;
				}
			}else if(mx02!=mx0 || my02!=my0){
				dx=(mxt+mx0)*0.5-(mx0+mx02)*0.5;
				dy=(myt+my0)*0.5-(my0+my02)*0.5;
				d=sqrt(dx*dx+dy*dy);
				linePos+=d;
				while(linePos>=0.0){
					t=(d-linePos)/d;
					pxt=(float)((mx0+mx02)*0.5+t*dx);
					pyt=(float)((my0+my02)*0.5+t*dy);
					if(toolMode==1){
						drawPoint(pxt,pyt,pMf->m_wndDlgBar.color,pMf->m_wndDlgBar.m_e1,pMf->m_wndDlgBar.m_e2,100);
					}else if(toolMode==2){
						copyPoint(pxt,pyt,copydx,copydy,pMf->m_wndDlgBar.m_e1,pMf->m_wndDlgBar.m_e2,100);
					}
					linePos-=intervalt;
				}
				mx02=mx0;
				my02=my0;
			}else{
				mx02=mx0;
				my02=my0;
			}			
			mx0=mxt;
			my0=myt;
		}

		preshow=true;
		Invalidate(FALSE);
	}
	CScrollView::OnMouseMove(nFlags, point);
}

void CImageToWordsView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint pointScroll=GetScrollPosition();
	int mxt=pointScroll.x+point.x;
	int myt=pointScroll.y+point.y;
	if(toolMode>0){
		cloneImage();
		Invalidate(FALSE);
	}
	linePos=0.0;
	painting=false;
	CScrollView::OnLButtonUp(nFlags, point);
}

void CImageToWordsView::clearTempImage(){
	//清空暂存图像（填充为黑色）
	int i=0,j=0;
	BYTE* tByte;
	if(t_Image.IsNull()){
		t_Image.Create(wid,hei,24);
	}else if(wid!=t_Image.GetWidth() || hei!=t_Image.GetHeight()){
		t_Image.Destroy();
		t_Image.Create(wid,hei,24);
	}
	for(j=0;j<hei;j++){
		for(i=0;i<wid;i++){
			tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
			*tByte=0;
			tByte[1]=0;
			tByte[2]=0;
		}
	}
}


void CImageToWordsView::drawPoint(float px,float py,int color0,float size,float hardness,float alpha){
	//画点
	if(size<=0){
		return;
	}
	float edgeRate=0.625f;
	float rate=hardness*0.01f;
	
	int pxi=(int)px;
	int pyi=(int)py;
	float pxoffset=px-(float)pxi;
	float pyoffset=py-(float)pyi;
	if(pxoffset>0.5f){
		pxoffset-=1.0f;
		pxi++;
	}else if(pxoffset<=-0.5f){
		pxoffset+=1.0f;
		pxi--;
	}
	if(pyoffset>0.5f){
		pyoffset-=1.0f;
		pyi++;
	}else if(pyoffset<=-0.5f){
		pyoffset+=1.0f;
		pyi--;
	}

	float pxoffseta=pxoffset>=0?pxoffset:-pxoffset;
	float pyoffseta=pyoffset>=0?pyoffset:-pyoffset;
	float poffset=pxoffseta>=pyoffseta?pxoffseta:pyoffseta;
	
	float r0f=size*0.5;
	float rf=size<100 ? r0f+r0f*edgeRate*(1.0f-rate)+poffset : r0f+poffset;
	int r = rf==(float)(int)(rf) ? (int)(rf) : int(rf+1);
	float r2f=rf*rf;
	
	
	float dx=0.0f;
	float dy=0.0f;
	float d2=0.0f;
	float d=0.0f;
	float drt=0.0f;
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	float value=0.0f;
	int c0r=color0>>16&0xff;
	int c0g=color0>>8&0xff;
	int c0b=color0&0xff;
	int lumt=0;
	int rt=0;
	int gt=0;
	int bt=0;

	int alphat=(int)(alpha*0.01f*255.0f+0.5f);
	if(alphat<0){
		alphat=0;
	}else if(alphat>255){
		alphat=255;
	}
	BYTE *mByte=NULL;
	BYTE *pByte=NULL;
	BYTE *tByte=NULL;

	//CString str;
	//str.Format("%d %d %d",c0r,c0g,c0b);
	//AfxGetMainWnd()->SetWindowText(str);

	for(j=-r;j<=r;j++){
		for(i=-r;i<=r;i++){
			k=pxi+i;
			l=pyi+j;
			if(k<0 || k>=wid || l<0 || l>=hei){
				continue;
			}
			
			dx=(float)i-pxoffset;
			dy=(float)j-pyoffset;
			d2=dx*dx+dy*dy;
			if(d2>r2f){
				continue;
			}
			d=sqrt(d2);
			mByte=(BYTE *)m_Image.GetPixelAddress(k,l);
			pByte=(BYTE *)p_Image.GetPixelAddress(k,l);
			tByte=(BYTE *)t_Image.GetPixelAddress(k,l);

			if(d<=rate*rf || hardness>=100){
				value=1.0f;
			}else if(d>rf){
				value=0;
			}else{
				drt=(rf-d)/(rf*(1.0f-rate));
				value=(-2.0f*drt+3.0f)*drt*drt;
				if(value<0){
					value=0;
				}else if(value>1.0f){
					value=1.0f;
				}
			}
			lumt=alphat-(alphat-tByte[0])*(1.0f-value);
			if(lumt<0){
				lumt=0;
			}
			if(lumt>alphat){
				lumt=alphat;
			}
			tByte[0]=lumt;
			rt=(mByte[2]*(255-lumt)+c0r*lumt)/255;
			gt=(mByte[1]*(255-lumt)+c0g*lumt)/255;
			bt=(mByte[0]*(255-lumt)+c0b*lumt)/255;
			if(rt<0){
				rt=0;
			}
			if(rt>255){
				rt=255;
			}
			if(gt<0){
				gt=0;
			}
			if(gt>255){
				gt=255;
			}
			if(bt<0){
				bt=0;
			}
			if(bt>255){
				bt=255;
			}
			pByte[2]=rt;
			pByte[1]=gt;
			pByte[0]=bt;
		}
	}
}

void CImageToWordsView::copyPoint(float px,float py,int copydx0,int copydy0,float size,float hardness,float alpha){
	//画点
	if(size<=0){
		return;
	}
	float edgeRate=0.625f;
	float rate=hardness*0.01f;
	
	int pxi=(int)px;
	int pyi=(int)py;
	float pxoffset=px-(float)pxi;
	float pyoffset=py-(float)pyi;
	if(pxoffset>0.5f){
		pxoffset-=1.0f;
		pxi++;
	}else if(pxoffset<=-0.5f){
		pxoffset+=1.0f;
		pxi--;
	}
	if(pyoffset>0.5f){
		pyoffset-=1.0f;
		pyi++;
	}else if(pyoffset<=-0.5f){
		pyoffset+=1.0f;
		pyi--;
	}

	float pxoffseta=pxoffset>=0?pxoffset:-pxoffset;
	float pyoffseta=pyoffset>=0?pyoffset:-pyoffset;
	float poffset=pxoffseta>=pyoffseta?pxoffseta:pyoffseta;
	
	float r0f=size*0.5;
	float rf=size<100 ? r0f+r0f*edgeRate*(1.0f-rate)+poffset : r0f+poffset;
	int r = rf==(float)(int)(rf) ? (int)(rf) : int(rf+1);
	float r2f=rf*rf;
	
	
	float dx=0.0f;
	float dy=0.0f;
	float d2=0.0f;
	float d=0.0f;
	float drt=0.0f;
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	int m=0;
	int n=0;
	float value=0.0f;
	int lumt=0;
	int rt=0;
	int gt=0;
	int bt=0;

	int alphat=(int)(alpha*0.01f*255.0f+0.5f);
	if(alphat<0){
		alphat=0;
	}else if(alphat>255){
		alphat=255;
	}
	BYTE *mByte=NULL;
	BYTE *mBytet=NULL;
	BYTE *pByte=NULL;
	BYTE *tByte=NULL;

	//CString str;
	//str.Format("%d %d %d",c0r,c0g,c0b);
	//AfxGetMainWnd()->SetWindowText(str);

	for(j=-r;j<=r;j++){
		for(i=-r;i<=r;i++){
			k=pxi+i;
			l=pyi+j;
			if(k<0 || k>=wid || l<0 || l>=hei){
				continue;
			}
			m=k-copydx;
			n=l-copydy;
			if(m<0 || m>=wid || n<0 || n>=hei){
				continue;
			}
			
			dx=(float)i-pxoffset;
			dy=(float)j-pyoffset;
			d2=dx*dx+dy*dy;
			if(d2>r2f){
				continue;
			}
			d=sqrt(d2);
			mByte=(BYTE *)m_Image.GetPixelAddress(m,n);
			mBytet=(BYTE *)m_Image.GetPixelAddress(k,l);
			pByte=(BYTE *)p_Image.GetPixelAddress(k,l);
			tByte=(BYTE *)t_Image.GetPixelAddress(k,l);

			if(d<=rate*rf || hardness>=100){
				value=1.0f;
			}else if(d>rf){
				value=0;
			}else{
				drt=(rf-d)/(rf*(1.0f-rate));
				value=(-2.0f*drt+3.0f)*drt*drt;
				if(value<0){
					value=0;
				}else if(value>1.0f){
					value=1.0f;
				}
			}
			lumt=alphat-(alphat-tByte[0])*(1.0f-value);
			if(lumt<0){
				lumt=0;
			}
			if(lumt>alphat){
				lumt=alphat;
			}
			tByte[0]=lumt;
			rt=(mBytet[2]*(255-lumt)+mByte[2]*lumt)/255;
			gt=(mBytet[1]*(255-lumt)+mByte[1]*lumt)/255;
			bt=(mBytet[0]*(255-lumt)+mByte[0]*lumt)/255;
			if(rt<0){
				rt=0;
			}
			if(rt>255){
				rt=255;
			}
			if(gt<0){
				gt=0;
			}
			if(gt>255){
				gt=255;
			}
			if(bt<0){
				bt=0;
			}
			if(bt>255){
				bt=255;
			}
			pByte[2]=rt;
			pByte[1]=gt;
			pByte[0]=bt;
		}
	}
}

void CImageToWordsView::drawPointOld(int px,int py,int color0,int r0,int rate0,int alpha0){
	//画点
	if(r0<=0){
		return;
	}
	float edgeRate=0.625f;
	float rate=rate0*0.01f;
	float r0f=r0>1?r0-0.5f:r0;
	float rf=rate0<100 ? r0f+r0f*edgeRate*(1.0f-rate) : r0f;
	int r;
	if(rate0<100){
		r = rf==(float)(int)(rf) ? (int)(rf) : int(rf+1);
	}else{
		r=r0-1;
	}
	int r2=r*r;
	int alpha=(alpha0*255+50)/100;
	if(alpha<0){
		alpha=0;
	}else if(alpha>255){
		alpha=255;
	}
	int d2=0;
	float d=0.0f;
	float drt=0.0f;
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	int value0=0;
	int value=0;
	int c0r=color0>>16&0xff;
	int c0g=color0>>8&0xff;
	int c0b=color0&0xff;
	int rt=0;
	int gt=0;
	int bt=0;
	BYTE *mByte=NULL;
	BYTE *pByte=NULL;
	BYTE *tByte=NULL;
	for(j=-r;j<=r;j++){
		for(i=-r;i<=r;i++){
			k=px+i;
			l=py+j;
			if(k<0 || k>=wid || l<0 || l>=hei){
				continue;
			}
			d2=i*i+j*j;
			if(d2>r2){
				continue;
			}
			//d=(float)sqrt((i+0.5f)*(i+0.5f)+(j+0.5f)*(j+0.5f));
			d=sqrt(d2);
			mByte=(BYTE *)m_Image.GetPixelAddress(k,l);
			pByte=(BYTE *)p_Image.GetPixelAddress(k,l);
			tByte=(BYTE *)t_Image.GetPixelAddress(k,l);
			value0=tByte[0];

			if(d<=rate*rf || rate0>=100){
				value=alpha;
			}else if(d>rf){
				value=0;
			}else{
				drt=(rf-d)/(rf*(1.0f-rate));
				value=(int)((-2.0f*drt+3.0f)*drt*drt*(float)alpha+0.5f);
				if(value<0){
					value=0;
				}else if(value>alpha){
					value=alpha;
				}
			}
			if(value>value0){
				tByte[0]=value;
				rt=(mByte[2]*(255-value)+c0r*value)/255;
				gt=(mByte[1]*(255-value)+c0g*value)/255;
				bt=(mByte[0]*(255-value)+c0b*value)/255;
				if(rt<0){
					rt=0;
				}
				if(rt>255){
					rt=255;
				}
				if(gt<0){
					gt=0;
				}
				if(gt>255){
					gt=255;
				}
				if(bt<0){
					bt=0;
				}
				if(bt>255){
					bt=255;
				}
				pByte[2]=rt;
				pByte[1]=gt;
				pByte[0]=bt;
			}
		}
	}
}



void CImageToWordsView::drawLine(float x0,float y0,int xt,int yt,int color0,int d0,int rate0,int alpha0){
	//画线
	if(d0<=0){
		d0=1;
	}
	
	if(x0==xt && y0==yt){
		//drawPoint(xt,yt,color0,r0,rate0,alpha0);
		return;
	}
	int i=0;
	int j=0;
	float edgeRate=0.625f;
	float rate=rate0*0.01f;
	float r0f=d0*0.5;
	float rf=rate0<100 ? r0f+r0f*(1.0f-edgeRate)*(1.0f-rate) : r0f;
	float smoothOffset=1.0f;
	float rfmin2=rf*rf;//rf-smoothOffset>0?(rf-smoothOffset)*(rf-smoothOffset):0;
	if(d0==1){
		smoothOffset=rate0>50?0.29f:0.5f;
		rfmin2=rf-smoothOffset>0?(rf-smoothOffset)*(rf-smoothOffset):0;
	}
	float rfmax2=(rf+smoothOffset)*(rf+smoothOffset);

	float lx=(float)(xt-x0);
	float ly=(float)(yt-y0);
	float l2=lx*lx+ly*ly;
	float l1=sqrt(l2);
	
	float vx=0.0f;
	float vy=0.0f;
	float pos=0.0f;
	
	float d2=0.0f;
	float d=0.0f;
	float drt=0.0f;
	int r=(int)(rf+1);

	int r2=r*r;
	int alpha=(alpha0*255+50)/100;
	if(alpha<0){
		alpha=0;
	}else if(alpha>255){
		alpha=255;
	}

	int size=r*(100-rate0)/50+1;
	if((size&1)==0){
		size++;
	}
	if(size>2000-1){
		size=2000-1;
	}
	int sizeh=size>>1;
	static float blurArray[2000];
	float sumarea=0.0f;
	for(i=0;i<size;i++){
		d=(float)(i-(size-1)*0.5)/size;
		blurArray[i]=0.25f-d*d;
		sumarea+=blurArray[i];
	}
	
	
	

	int value=0;
	int c0r=color0>>16&0xff;
	int c0g=color0>>8&0xff;
	int c0b=color0&0xff;
	int rt=0;
	int gt=0;
	int bt=0;
	BYTE *mByte=NULL;
	BYTE *pByte=NULL;
	BYTE *tByte=NULL;
	int xmin=(x0<=xt?x0:xt)-r;
	int ymin=(y0<=yt?y0:yt)-r;
	int xmax=(x0>xt?x0:xt)+r;
	int ymax=(y0>yt?y0:yt)+r;
	if(xmin<0){
		xmin=0;
	}
	if(xmax<0){
		xmax=0;
	}
	if(ymin<0){
		ymin=0;
	}
	if(ymax<0){
		ymax=0;
	}
	if(xmin>=wid){
		xmin=wid-1;
	}
	if(xmax>=wid){
		xmax=wid-1;
	}
	if(ymin>=hei){
		ymin=hei-1;
	}
	if(ymax>=hei){
		ymax=hei-1;
	}
	
	for(j=ymin;j<=ymax;j++){
		for(i=xmin;i<=xmax;i++){
			vx=(float)(i-x0);
			vy=(float)(j-y0);
			//v=(float)sqrt(vx*vx+vy*vy);
			pos=(vx*lx+vy*ly)/l2;
			if(pos<0.0f){
				d2=vx*vx+vy*vy;
				//d=(float)sqrt(d2);
			}else if(pos<=1.0f){
				d=(vx*ly-lx*vy)/l1;
				if(d<0.0f){
					d=-d;
				}
				d2=d*d;
			}else{
				vx=(float)(i-xt);
				vy=(float)(j-yt);
				d2=vx*vx+vy*vy;
				//d=(float)sqrt(d2);
			}
			if(d2>=rfmax2){
				continue;
			}
			
			tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
			if(d2<=rfmin2){
				value=255;
			}else if(d2<rfmax2){
				value=(int)(255.0f*(rfmax2-d2)/(rfmax2-rfmin2)+0.5f);
				if(value<0){
					value=0;
				}
				if(value>255){
					value=255;
				}
			}else{
				value=0;
			}
		
			if(tByte[0]<value){
				tByte[0]=value;
			}
			tByte[1]=1;
		}
	}
	xmin=(x0<=xt?x0:xt)-r-3*size/2;
	ymin=(y0<=yt?y0:yt)-r-3*size/2;
	xmax=(x0>xt?x0:xt)+r+3*size/2+1;
	ymax=(y0>yt?y0:yt)+r+3*size/2+1;
	if(xmin<0){
		xmin=0;
	}
	if(xmax<0){
		xmax=0;
	}
	if(ymin<0){
		ymin=0;
	}
	if(ymax<0){
		ymax=0;
	}
	if(xmin>=wid){
		xmin=wid-1;
	}
	if(xmax>=wid){
		xmax=wid-1;
	}
	if(ymin>=hei){
		ymin=hei-1;
	}
	if(ymax>=hei){
		ymax=hei-1;
	}
	int k=0;
	int l=0;
	float sum=0;
	for(j=ymin;j<=ymax;j++){
		for(i=xmin;i<=xmax;i++){
			sum=0;
			for(k=0;k<size;k++){
				l=i+k-sizeh;
				if(l<0){
					l=0;
				}else if(l>=wid){
					l=wid-1;
				}
				tByte=(BYTE *)t_Image.GetPixelAddress(l,j);
				sum+=tByte[0]*blurArray[k];
			}
			value=(int)(sum/sumarea+0.5f);
			if(value<0){
				value=0;
			}
			if(value>255){
				value=255;
			}
			tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
			tByte[2]=value;
		}
	}
	xmin=(x0<=xt?x0:xt)-r-size;
	ymin=(y0<=yt?y0:yt)-r-size;
	xmax=(x0>xt?x0:xt)+r+size+1;
	ymax=(y0>yt?y0:yt)+r+size+1;
	if(xmin<0){
		xmin=0;
	}
	if(xmax<0){
		xmax=0;
	}
	if(ymin<0){
		ymin=0;
	}
	if(ymax<0){
		ymax=0;
	}
	if(xmin>=wid){
		xmin=wid-1;
	}
	if(xmax>=wid){
		xmax=wid-1;
	}
	if(ymin>=hei){
		ymin=hei-1;
	}
	if(ymax>=hei){
		ymax=hei-1;
	}
	
	for(j=ymin;j<=ymax;j++){
		for(i=xmin;i<=xmax;i++){
			sum=0;
			for(k=0;k<size;k++){
				l=j+k-sizeh;
				if(l<0){
					l=0;
				}else if(l>=wid){
					l=wid-1;
				}
				tByte=(BYTE *)t_Image.GetPixelAddress(i,l);
				sum+=tByte[2]*blurArray[k];
			}
			value=(int)(sum*alpha/(sumarea*255.0f)+0.5f);
			if(value<0){
				value=0;
			}
			if(value>255){
				value=255;
			}
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			rt=(mByte[2]*(255-value)+c0r*value)/255;
			gt=(mByte[1]*(255-value)+c0g*value)/255;
			bt=(mByte[0]*(255-value)+c0b*value)/255;
			if(rt<0){
				rt=0;
			}
			if(rt>255){
				rt=255;
			}
			if(gt<0){
				gt=0;
			}
			if(gt>255){
				gt=255;
			}
			if(bt<0){
				bt=0;
			}
			if(bt>255){
				bt=255;
			}
			pByte[2]=rt;
			pByte[1]=gt;
			pByte[0]=bt;
		}
	}
}


void CImageToWordsView::drawLineOld(int x0,int y0,int xt,int yt,int color0,int r0,int rate0,int alpha0){
	//画线
	if(r0<=0){
		return;
	}
	
	if(x0==xt && y0==yt){
		//drawPoint(xt,yt,color0,r0,rate0,alpha0);
		return;
	}

	float edgeRate=0.613f;
	float rate=rate0*0.01f;
	float r0f=r0>1?r0-0.5f:r0;
	float rf=rate0<100 ? r0f+r0f*edgeRate*(1.0f-rate) : r0f;
	int r;
	if(rate0<100){
		r = rf==(float)(int)(rf) ? (int)(rf) : int(rf+1);
	}else{
		r=r0-1;
	}
	int r2=r*r;
	int alpha=(alpha0*255+50)/100;
	if(alpha<0){
		alpha=0;
	}else if(alpha>255){
		alpha=255;
	}
	
	float lx=(float)(xt-x0);
	float ly=(float)(yt-y0);
	float l2=lx*lx+ly*ly;
	float l=sqrt(l2);
	
	float vx=0.0f;
	float vy=0.0f;
	float pos=0.0f;
	
	float d2=0.0f;
	float d=0.0f;
	float drt=0.0f;
	int i=0;
	int j=0;
	int value0=0;
	int value=0;
	int c0r=color0>>16&0xff;
	int c0g=color0>>8&0xff;
	int c0b=color0&0xff;
	int rt=0;
	int gt=0;
	int bt=0;
	BYTE *mByte=NULL;
	BYTE *pByte=NULL;
	BYTE *tByte=NULL;
	int xmin=(x0<=xt?x0:xt)-r;
	int ymin=(y0<=yt?y0:yt)-r;
	int xmax=(x0>xt?x0:xt)+r;
	int ymax=(y0>yt?y0:yt)+r;
	for(j=ymin;j<=ymax;j++){
		for(i=xmin;i<=xmax;i++){
			if(i<0 || i>=wid || j<0 || j>=hei){
				continue;
			}
			vx=(float)(i-x0);
			vy=(float)(j-y0);
			//v=(float)sqrt(vx*vx+vy*vy);
			pos=(vx*lx+vy*ly)/l2;
			if(pos<0.0f){
				d2=vx*vx+vy*vy;
				if(d2>r2){
					continue;
				}
				d=(float)sqrt(d2);
			}else if(pos<=1.0f){
				d=(vx*ly-lx*vy)/l;
				if(d<0.0f){
					d=-d;
				}
				d2=d*d;
				if(d2>r2){
					continue;
				}
			}else{
				vx=(float)(i-xt);
				vy=(float)(j-yt);
				d2=vx*vx+vy*vy;
				if(d2>r2){
					continue;
				}
				d=(float)sqrt(d2);
			}
			mByte=(BYTE *)m_Image.GetPixelAddress(i,j);
			pByte=(BYTE *)p_Image.GetPixelAddress(i,j);
			tByte=(BYTE *)t_Image.GetPixelAddress(i,j);
			value0=tByte[0];

			if(d<=rate*rf || rate0>=100){
				value=alpha;
			}else if(d>rf){
				value=0;
			}else{
				drt=(rf-d)/(rf*(1.0f-rate));
				value=(int)((-2.0f*drt+3.0f)*drt*drt*(float)alpha+0.5f);
				if(value<0){
					value=0;
				}else if(value>alpha){
					value=alpha;
				}
			}
			if(value>value0){
				tByte[0]=value;
				rt=(mByte[2]*(255-value)+c0r*value)/255;
				gt=(mByte[1]*(255-value)+c0g*value)/255;
				bt=(mByte[0]*(255-value)+c0b*value)/255;
				if(rt<0){
					rt=0;
				}
				if(rt>255){
					rt=255;
				}
				if(gt<0){
					gt=0;
				}
				if(gt>255){
					gt=255;
				}
				if(bt<0){
					bt=0;
				}
				if(bt>255){
					bt=255;
				}
				pByte[2]=rt;
				pByte[1]=gt;
				pByte[0]=bt;
			}
			
			
		}
	}
}

void CImageToWordsView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CMainFrame *pMf=NULL;
	if(nChar==219 || nChar==221){
		pMf=(CMainFrame *)AfxGetMainWnd();
		if(pMf==NULL){
			CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
			return;
		}
		if(nChar==219){
			pMf->m_wndDlgBar.m_e1--;
		}
		if(nChar==221){
			pMf->m_wndDlgBar.m_e1++;
		}
		if(pMf->m_wndDlgBar.m_e1<1){
			pMf->m_wndDlgBar.m_e1=1;
		}else if(pMf->m_wndDlgBar.m_e1>50){
			pMf->m_wndDlgBar.m_e1=50;
		}
		pMf->m_wndDlgBar.updateInterface();
	}
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CImageToWordsView::OnFuzhigongju() 
{
	// TODO: Add your command handler code here
	toolMode=2;
}

void CImageToWordsView::OnUpdateFuzhigongju(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::OnRouhua() 
{
	// TODO: Add your command handler code here
	CMainFrame *pMf=NULL;
	if(pMf==NULL){
		pMf=(CMainFrame *)AfxGetMainWnd();
	}
	if(pMf==NULL){
		return;
	}
	CEdit *pEdit=(CEdit *)(pMf->m_wndDlgBar.GetDlgItem(IDC_EDIT2));
	pEdit->SetFocus();
    pEdit->SetSel(0,-1);
	
}

void CImageToWordsView::OnUpdateRouhua(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}

void CImageToWordsView::OnTiaoseban() 
{
	// TODO: Add your command handler code here
	CMainFrame *pMf=NULL;
	if(pMf==NULL){
		pMf=(CMainFrame *)AfxGetMainWnd();
	}
	if(pMf==NULL){
		return;
	}
	pMf->m_wndDlgBar.OnButton1();
}

void CImageToWordsView::OnUpdateTiaoseban(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CImageToWordsView::OnDiguan() 
{
	// TODO: Add your command handler code here
	toolMode=-1;
}

void CImageToWordsView::OnUpdateDiguan(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	updateMenuCommon(pCmdUI);
}
