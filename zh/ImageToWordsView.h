// ImageToWordsView.h : interface of the CImageToWordsView class
//
/////////////////////////////////////////////////////////////////////////////
#include "ImageToWordsDoc.h"
#if !defined(AFX_IMAGETOWORDSVIEW_H__C2FD52BB_A14B_4C7B_ABFA_5F929CA2EB39__INCLUDED_)
#define AFX_IMAGETOWORDSVIEW_H__C2FD52BB_A14B_4C7B_ABFA_5F929CA2EB39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CImageToWordsView : public CScrollView
{
protected: // create from serialization only
	CImageToWordsView();
	DECLARE_DYNCREATE(CImageToWordsView)
	CImage *undoImage;//以前图像
	int undoMaxTimes;
	int undoi;//最近记录撤销的图片号
	int undoimax;//一组撤销前最后记录撤销的图片号
	bool undort;//下一个记录撤销的图片号是否回过0（即总步数是否超过undoMaxTimes）
// Attributes
public:
	CImageToWordsDoc* GetDocument();
	//COLORREF prePoints[10][4096][4096];//以前图像
	//COLORREF curp[4096][4096];//当前图像
	//COLORREF pvp[4096][4096];//预览图像
	int wid;//图片宽度
	int hei;//图片高度
	
	CImage m_Image;//当前图像
	CImage p_Image;//预览图像
	CImage t_Image;//暂存图像
	bool preshow;//是否显示预览图像
	bool tempshow;//是否显示暂存图像
	int mouseX,mouseY;//鼠标坐标
	int sx0,sy0;//图片左上角在画面显示的位置
	int mx0,my0;//鼠标坐标
	int mx02,my02;//鼠标坐标
	int mxp,myp;//鼠标坐标
	int copymx0,copymy0;//仿制源
	int copydx,copydy;
	bool painting;//是否正在绘制
	double linePos;//画线时的标点位置
	int toolMode;//工具模式（0箭头，1画笔）
	BYTE *imageInfo;//图片像素点周围信息
	int wordGrid[2052][1026];//文字格子信息
	int wordGridLengr;//文字格子信息行数
	LOGFONT wtfont;//字体信息
	//CFont wtcf;//字体信息对应的CFont（手动更新后用）
	UINT pchset[65537][32];//字符点阵集
	int pchsetLeng;//字符点阵集长
	CImage ti;//字符图片
	bool firstFontInfo;
// Operations
public:
	bool hasValidImage();//是否有有效的图像
	void openFile();//打开图像文件
	bool openMenuCommon(CDialog &dlg,void (*myFilter)(CDialog*,CImageToWordsView*)=NULL);//一般的打开菜单界面操作
	void updateMenuCommon(CCmdUI* pCmdUI);//一般的更新菜单界面操作（没有文件打开时菜单项置灰）
	void BalanceFilter(int ld,float dbd,int sx,float bhd);//平衡滤镜
	void SejieFilter(int inb,double ing,int inw,int outb,int outw,int channel);//色阶滤镜
	void GrayenFilter(int wr,int wg,int wb,float scd);//灰度滤镜（Grayen应为Discolor）
	void YuzhiFilter(int yz,float dbd);//阈值滤镜	
	void RuihuaFilter(int r,float sl,int yz,BOOL smooth);//锐化滤镜
	void BlurFilter(int r,int yz,int rb,BOOL smooth,BOOL roundSample);//模糊滤镜
	void EdgeFilter1(int r,float sl,int rate,int bkg,int cofs);//边缘滤镜（周围比较）
	void ChuzaFilter(int num,int yz,int hx);//除杂滤镜
	void ConvolutionFilter(float *arr,float offset,int leng,int lengc,int midi,int midj);//卷积滤镜
	void ConvolutionFilter(float *arr,float offset,int leng,int lengc,int midi,int midj,bool rable,bool gable,bool bable);//带通道选择的卷积滤镜
	void ScaleFilter(int nw,int nh,int zcd,int zm);//缩放滤镜（新宽度，新高度，注册点，放大/缩小算法）
	void TrimFilter(int nw,int nh,int offsx,int offsy,COLORREF bkgColour,bool willRepeat);//裁剪滤镜（新宽度，新高度，横向偏移，纵向偏移，背景颜色）
	void MinimumFilter(int rc2,bool isCircle);
	void MaximumFilter(int rc2,bool isCircle);
	void DiffuseFilter(int rc2,bool isCircle);
	void ColourOffsetFilter(int offs);
	void wtPreDraw(float (&arr)[10],CRect rect,float size);//文字转换前在p_Image上计算并画上黑白图（或黑白马赛克图）和格子wordGrid（arr：参数信息，rect：选区，size：马赛克格子大小）
	double* toHSL(BYTE &r,BYTE &g,BYTE &b);//RGB转HSL
	BYTE* fromHSL(double &h,double &s,double &l);//HSL转RGB
	BYTE toRgbMid(double q1,double q2,double hue);//HSL转RGB中间函数
	void previewHeibaien(int yz);//预览图像黑白化
	void cloneImage();//p_Image信息拷贝到m_Image并记录
	void resumePreview();//m_Image信息拷贝到p_Image
	void statZft(int channel,int (&pinshu)[256]);//统计m_Image各明暗度的频数，用于直方图
	void recordUndo();//记录到以前图片，用于撤销
	BYTE chuzaCheck(int x,int y,int yz);//检测周围像素与中心像素的差值的临界情况
	int getPchCh(CString str,int pos=-1,LOGFONT *lf=NULL);//获得不带边缘字符点阵（返回不带边缘字符的宽度（像素））
	int getPchEn(CString str,int pos=-1,LOGFONT *lf=NULL);//获得带边缘字符点阵（返回带边缘字符的宽度（像素））
	void getPchPic(UINT (&arr)[32],int srcHeight,int fontHeight,int srcWidth,int x0,int y0);//获得与字符点阵相对应的图片点阵
	char* getPchs(int ziji);//获得某个字集的字符点阵组给pchset
	CString identifyGrid(int ziji,char *wordset,int col,int row,int gridHeight,int rate);//识别某个框内的字（字集号，候选字符数组指针，列号，行号，格子高，文字超出与不到的平衡）（需先getPchs）
	UINT bitCount(UINT i);//统计无符号32位二进制整数中1的个数
	double normalDistribution(double x,double y,double r,double change);//正态分布
	void sortInt(int *arr,int leng);//对整型数据进行快速排序（数组名，数组长）
	void sortTable(int **arr,int leng);//对整型二维数组（需要用整形指针数组作为中介进行转换）数据按第一列进行排序（数组名，数组长，附加数组名，开始时的步数，要排除的数组）
	int mergeSortUInt(unsigned int *arr,int leng,unsigned int *arrTemp=NULL,int step0=1,int *exceptArray=NULL,int exceptArrayLeng=0);//对整型数据进行归并排序（要排序数组名，数组长，附加的数组名（跟要排序数组等长），开始步长，要排除的条件数组，要排除的条件数组长），返回数组的新长度，如果最终结果落在要排序数组上时还会乘以-1。
	void ZhongZhiLvBoFilter(int bc,int bl,int bl2,double power,int shape,bool sort=true);//中值滤波滤镜（边长，半径，系数，形状）
	void ZhongZhiLvBoFilterOld(int bc,int bl,int bl2,double power,int shape,bool sort=true);//中值滤波滤镜（边长，半径，系数，形状）
	
	void Texture1FilterPreload(bool willRepaint=true);//无缝贴图滤镜预加载（是否重绘）
	void Texture1Filter(int offset,int rate,int direction);//无缝贴图滤镜（需要事先执行Texture1FilterPreload进行预处理）（重合像素，缩放起始，方向限制（0:横向和纵向；1:横向；2:纵向））
	void PerspectiveFilter(int scale,int offset);//透视图变成俯视平面图滤镜（缩放角度，左右偏移角度）
	void RotateFilter(double angle,int mode,COLORREF bkgColour);
	void clearTempImage();//清空暂存图像（填充为黑色）
	void drawPointOld(int px,int py,int color0,int r0,int rate0,int alpha0);//画点
	void drawPoint(float px,float py,int color0,float size,float hardness,float alpha);//画点
	void drawLineOld(int x0,int y0,int xt,int yt,int color0,int r0,int rate0,int alpha0);//画线
	void drawLine(float x0,float y0,int xt,int yt,int color0,int r0,int rate0,int alpha0);//画线
	void copyPoint(float px,float py,int copydx0,int copydy0,float size,float hardness,float alpha);//仿制点
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageToWordsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageToWordsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
public:
	//{{AFX_MSG(CImageToWordsView)
	afx_msg void OnFileOpen();
	afx_msg void OnBalance();
	afx_msg void OnUpdateBalance(CCmdUI* pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSejie();
	afx_msg void OnUpdateSejie(CCmdUI* pCmdUI);
	afx_msg void OnFanxiang();
	afx_msg void OnUpdateFanxiang(CCmdUI* pCmdUI);
	afx_msg void OnGrayen();
	afx_msg void OnUpdateGrayen(CCmdUI* pCmdUI);
	afx_msg void OnYuzhi();
	afx_msg void OnUpdateYuzhi(CCmdUI* pCmdUI);
	afx_msg void OnTidu();
	afx_msg void OnUpdateTidu(CCmdUI* pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnEditRedo();
	afx_msg void OnUpdateEditRedo(CCmdUI* pCmdUI);
	afx_msg void OnRuihua();
	afx_msg void OnUpdateRuihua(CCmdUI* pCmdUI);
	afx_msg void OnBlur();
	afx_msg void OnUpdateBlur(CCmdUI* pCmdUI);
	afx_msg void OnChuza();
	afx_msg void OnUpdateChuza(CCmdUI* pCmdUI);
	afx_msg void OnZdyfi();
	afx_msg void OnUpdateZdyfi(CCmdUI* pCmdUI);
	afx_msg void OnEdge();
	afx_msg void OnUpdateEdge(CCmdUI* pCmdUI);
	afx_msg void OnStablelize();
	afx_msg void OnUpdateStablelize(CCmdUI* pCmdUI);
	afx_msg void OnWordstransform();
	afx_msg void OnUpdateWordstransform(CCmdUI* pCmdUI);
	afx_msg void OnMenuscale();
	afx_msg void OnUpdateMenuscale(CCmdUI* pCmdUI);
	afx_msg void OnQianbi();
	afx_msg void OnUpdateQianbi(CCmdUI* pCmdUI);
	afx_msg void OnFileSave();
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnFileSaveAs();
	afx_msg void OnUpdateFileSaveAs(CCmdUI* pCmdUI);
	afx_msg void OnMenutrim();
	afx_msg void OnUpdateMenutrim(CCmdUI* pCmdUI);
	afx_msg void OnMinimumfi();
	afx_msg void OnUpdateMinimumfi(CCmdUI* pCmdUI);
	afx_msg void OnMaximumfi();
	afx_msg void OnUpdateMaximumfi(CCmdUI* pCmdUI);
	afx_msg void OnKuosan();
	afx_msg void OnUpdateKuosan(CCmdUI* pCmdUI);
	afx_msg void OnZhongzhilvbo();
	afx_msg void OnUpdateZhongzhilvbo(CCmdUI* pCmdUI);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnFileNew();
	afx_msg void OnTexture1();
	afx_msg void OnUpdateTexture1(CCmdUI* pCmdUI);
	afx_msg void OnMenuperspective();
	afx_msg void OnUpdateMenuperspective(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMenurotate();
	afx_msg void OnUpdateMenurotate(CCmdUI* pCmdUI);
	afx_msg void OnFuzhigongju();
	afx_msg void OnUpdateFuzhigongju(CCmdUI* pCmdUI);
	afx_msg void OnRouhua();
	afx_msg void OnUpdateRouhua(CCmdUI* pCmdUI);
	afx_msg void OnTiaoseban();
	afx_msg void OnUpdateTiaoseban(CCmdUI* pCmdUI);
	afx_msg void OnDiguan();
	afx_msg void OnUpdateDiguan(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ImageToWordsView.cpp
inline CImageToWordsDoc* CImageToWordsView::GetDocument()
   { return (CImageToWordsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETOWORDSVIEW_H__C2FD52BB_A14B_4C7B_ABFA_5F929CA2EB39__INCLUDED_)
