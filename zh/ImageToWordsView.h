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
	CImage *undoImage;//��ǰͼ��
	int undoMaxTimes;
	int undoi;//�����¼������ͼƬ��
	int undoimax;//һ�鳷��ǰ����¼������ͼƬ��
	bool undort;//��һ����¼������ͼƬ���Ƿ�ع�0�����ܲ����Ƿ񳬹�undoMaxTimes��
// Attributes
public:
	CImageToWordsDoc* GetDocument();
	//COLORREF prePoints[10][4096][4096];//��ǰͼ��
	//COLORREF curp[4096][4096];//��ǰͼ��
	//COLORREF pvp[4096][4096];//Ԥ��ͼ��
	int wid;//ͼƬ���
	int hei;//ͼƬ�߶�
	
	CImage m_Image;//��ǰͼ��
	CImage p_Image;//Ԥ��ͼ��
	CImage t_Image;//�ݴ�ͼ��
	bool preshow;//�Ƿ���ʾԤ��ͼ��
	bool tempshow;//�Ƿ���ʾ�ݴ�ͼ��
	int mouseX,mouseY;//�������
	int sx0,sy0;//ͼƬ���Ͻ��ڻ�����ʾ��λ��
	int mx0,my0;//�������
	int mx02,my02;//�������
	int mxp,myp;//�������
	int copymx0,copymy0;//����Դ
	int copydx,copydy;
	bool painting;//�Ƿ����ڻ���
	double linePos;//����ʱ�ı��λ��
	int toolMode;//����ģʽ��0��ͷ��1���ʣ�
	BYTE *imageInfo;//ͼƬ���ص���Χ��Ϣ
	int wordGrid[2052][1026];//���ָ�����Ϣ
	int wordGridLengr;//���ָ�����Ϣ����
	LOGFONT wtfont;//������Ϣ
	//CFont wtcf;//������Ϣ��Ӧ��CFont���ֶ����º��ã�
	UINT pchset[65537][32];//�ַ�����
	int pchsetLeng;//�ַ����󼯳�
	CImage ti;//�ַ�ͼƬ
	bool firstFontInfo;
// Operations
public:
	bool hasValidImage();//�Ƿ�����Ч��ͼ��
	void openFile();//��ͼ���ļ�
	bool openMenuCommon(CDialog &dlg,void (*myFilter)(CDialog*,CImageToWordsView*)=NULL);//һ��Ĵ򿪲˵��������
	void updateMenuCommon(CCmdUI* pCmdUI);//һ��ĸ��²˵����������û���ļ���ʱ�˵����ûң�
	void BalanceFilter(int ld,float dbd,int sx,float bhd);//ƽ���˾�
	void SejieFilter(int inb,double ing,int inw,int outb,int outw,int channel);//ɫ���˾�
	void GrayenFilter(int wr,int wg,int wb,float scd);//�Ҷ��˾���GrayenӦΪDiscolor��
	void YuzhiFilter(int yz,float dbd);//��ֵ�˾�	
	void RuihuaFilter(int r,float sl,int yz,BOOL smooth);//���˾�
	void BlurFilter(int r,int yz,int rb,BOOL smooth,BOOL roundSample);//ģ���˾�
	void EdgeFilter1(int r,float sl,int rate,int bkg,int cofs);//��Ե�˾�����Χ�Ƚϣ�
	void ChuzaFilter(int num,int yz,int hx);//�����˾�
	void ConvolutionFilter(float *arr,float offset,int leng,int lengc,int midi,int midj);//����˾�
	void ConvolutionFilter(float *arr,float offset,int leng,int lengc,int midi,int midj,bool rable,bool gable,bool bable);//��ͨ��ѡ��ľ���˾�
	void ScaleFilter(int nw,int nh,int zcd,int zm);//�����˾����¿�ȣ��¸߶ȣ�ע��㣬�Ŵ�/��С�㷨��
	void TrimFilter(int nw,int nh,int offsx,int offsy,COLORREF bkgColour,bool willRepeat);//�ü��˾����¿�ȣ��¸߶ȣ�����ƫ�ƣ�����ƫ�ƣ�������ɫ��
	void MinimumFilter(int rc2,bool isCircle);
	void MaximumFilter(int rc2,bool isCircle);
	void DiffuseFilter(int rc2,bool isCircle);
	void ColourOffsetFilter(int offs);
	void wtPreDraw(float (&arr)[10],CRect rect,float size);//����ת��ǰ��p_Image�ϼ��㲢���Ϻڰ�ͼ����ڰ�������ͼ���͸���wordGrid��arr��������Ϣ��rect��ѡ����size�������˸��Ӵ�С��
	double* toHSL(BYTE &r,BYTE &g,BYTE &b);//RGBתHSL
	BYTE* fromHSL(double &h,double &s,double &l);//HSLתRGB
	BYTE toRgbMid(double q1,double q2,double hue);//HSLתRGB�м亯��
	void previewHeibaien(int yz);//Ԥ��ͼ��ڰ׻�
	void cloneImage();//p_Image��Ϣ������m_Image����¼
	void resumePreview();//m_Image��Ϣ������p_Image
	void statZft(int channel,int (&pinshu)[256]);//ͳ��m_Image�������ȵ�Ƶ��������ֱ��ͼ
	void recordUndo();//��¼����ǰͼƬ�����ڳ���
	BYTE chuzaCheck(int x,int y,int yz);//�����Χ�������������صĲ�ֵ���ٽ����
	int getPchCh(CString str,int pos=-1,LOGFONT *lf=NULL);//��ò�����Ե�ַ����󣨷��ز�����Ե�ַ��Ŀ�ȣ����أ���
	int getPchEn(CString str,int pos=-1,LOGFONT *lf=NULL);//��ô���Ե�ַ����󣨷��ش���Ե�ַ��Ŀ�ȣ����أ���
	void getPchPic(UINT (&arr)[32],int srcHeight,int fontHeight,int srcWidth,int x0,int y0);//������ַ��������Ӧ��ͼƬ����
	char* getPchs(int ziji);//���ĳ���ּ����ַ��������pchset
	CString identifyGrid(int ziji,char *wordset,int col,int row,int gridHeight,int rate);//ʶ��ĳ�����ڵ��֣��ּ��ţ���ѡ�ַ�����ָ�룬�кţ��кţ����Ӹߣ����ֳ����벻����ƽ�⣩������getPchs��
	UINT bitCount(UINT i);//ͳ���޷���32λ������������1�ĸ���
	double normalDistribution(double x,double y,double r,double change);//��̬�ֲ�
	void sortInt(int *arr,int leng);//���������ݽ��п������������������鳤��
	void sortTable(int **arr,int leng);//�����Ͷ�ά���飨��Ҫ������ָ��������Ϊ�н����ת�������ݰ���һ�н������������������鳤����������������ʼʱ�Ĳ�����Ҫ�ų������飩
	int mergeSortUInt(unsigned int *arr,int leng,unsigned int *arrTemp=NULL,int step0=1,int *exceptArray=NULL,int exceptArrayLeng=0);//���������ݽ��й鲢����Ҫ���������������鳤�����ӵ�����������Ҫ��������ȳ�������ʼ������Ҫ�ų����������飬Ҫ�ų����������鳤��������������³��ȣ�������ս������Ҫ����������ʱ�������-1��
	void ZhongZhiLvBoFilter(int bc,int bl,int bl2,double power,int shape,bool sort=true);//��ֵ�˲��˾����߳����뾶��ϵ������״��
	void ZhongZhiLvBoFilterOld(int bc,int bl,int bl2,double power,int shape,bool sort=true);//��ֵ�˲��˾����߳����뾶��ϵ������״��
	
	void Texture1FilterPreload(bool willRepaint=true);//�޷���ͼ�˾�Ԥ���أ��Ƿ��ػ棩
	void Texture1Filter(int offset,int rate,int direction);//�޷���ͼ�˾�����Ҫ����ִ��Texture1FilterPreload����Ԥ�������غ����أ�������ʼ���������ƣ�0:���������1:����2:���򣩣�
	void PerspectiveFilter(int scale,int offset);//͸��ͼ��ɸ���ƽ��ͼ�˾������ŽǶȣ�����ƫ�ƽǶȣ�
	void RotateFilter(double angle,int mode,COLORREF bkgColour);
	void clearTempImage();//����ݴ�ͼ�����Ϊ��ɫ��
	void drawPointOld(int px,int py,int color0,int r0,int rate0,int alpha0);//����
	void drawPoint(float px,float py,int color0,float size,float hardness,float alpha);//����
	void drawLineOld(int x0,int y0,int xt,int yt,int color0,int r0,int rate0,int alpha0);//����
	void drawLine(float x0,float y0,int xt,int yt,int color0,int r0,int rate0,int alpha0);//����
	void copyPoint(float px,float py,int copydx0,int copydy0,float size,float hardness,float alpha);//���Ƶ�
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
