// EdgeInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "EdgeInput.h"
#include "ImageToWordsView.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEdgeInput dialog


CEdgeInput::CEdgeInput(CWnd* pParent /*=NULL*/)
	: CDialog(CEdgeInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEdgeInput)
	m_co1 = -1;
	m_ch1 = FALSE;
	//}}AFX_DATA_INIT
	angle=0,bkg=255,cofs=0,rate=0;
	bj=1,sl=1;
}


void CEdgeInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEdgeInput)
	DDX_Control(pDX, IDC_STATIC4, m_l4);
	DDX_Control(pDX, IDC_STATIC3, m_l3);
	DDX_Control(pDX, IDC_STATIC2, m_l2);
	DDX_Control(pDX, IDC_STATIC1, m_l1);
	DDX_Control(pDX, IDC_SCROLLBAR4, m_s4);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_s3);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_s2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_s1);
	DDX_CBIndex(pDX, IDC_COMBO1, m_co1);
	DDX_Check(pDX, IDC_CHECK1, m_ch1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEdgeInput, CDialog)
	//{{AFX_MSG_MAP(CEdgeInput)
	ON_WM_HSCROLL()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEdgeInput message handlers

BOOL CEdgeInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	si1.fMask=SIF_ALL;
    si1.nMax=99;
	si1.nMin=0;
	si1.nPage=1;
	si1.nPos=9;
	si2.fMask=SIF_ALL;
    si2.nMax=510;
	si2.nMin=0;
	si2.nPage=1;
	si2.nPos=255;
	si3.fMask=SIF_ALL;
    si3.nMax=200;
	si3.nMin=0;
	si3.nPage=1;
	si3.nPos=100;
	si4.fMask=SIF_ALL;
    si4.nMax=360;
	si4.nMin=0;
	si4.nPage=1;
	si4.nPos=45;
	si5.fMask=SIF_ALL;
	si5.nMax=259;
	si5.nMin=0;
	si5.nPage=1;
	si5.nPos=257;
	m_s1.SetScrollInfo(&si1,true);
	m_s2.SetScrollInfo(&si2,true);
	m_s3.SetScrollInfo(&si3,true);
	m_s4.SetScrollInfo(&si5,true);
	angle=0,bkg=255,cofs=0;
	bj=1,sl=1,rate=1;
	//m_s3.SetScrollPos(510);		
	//CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	//CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	//if(pView->wid<=1152 && pView->hei<=864){		
		m_co1=0;
	//}else{
		//m_co1=1;
	//}
	UpdateData(FALSE);
	updateAndFilter();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEdgeInput::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default

	int stepl=1;
	int stepp=5;
	UpdateData(TRUE);
	switch(nSBCode){
		case SB_LINELEFT:
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()-stepl>0?pScrollBar->GetScrollPos()-stepl:0);
			break;
		case SB_LINERIGHT:
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()+stepl<pScrollBar->GetScrollLimit()?pScrollBar->GetScrollPos()+stepl:pScrollBar->GetScrollLimit());
			break;
		case SB_PAGELEFT:
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()-stepp>0?pScrollBar->GetScrollPos()-stepp:0);
			break;
		case SB_PAGERIGHT:
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()+stepp<pScrollBar->GetScrollLimit()?pScrollBar->GetScrollPos()+stepp:pScrollBar->GetScrollLimit());
			break;
		case SB_THUMBPOSITION: 
			pScrollBar->SetScrollPos(nPos);
			break; 
		case SB_THUMBTRACK: 
			//ScrollWindow((scrollinfo.nPos-nPos)*10,0); 
			//scrollinfo.nPos = nPos; 
			//SetScrollInfo(SB_HORZ,&scrollinfo,SIF_ALL); 
			break; 
		case SB_ENDSCROLL: 
			break;  
	}
	if(nSBCode!=SB_THUMBTRACK && nSBCode!=SB_ENDSCROLL){
		updateAndFilter();
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CEdgeInput::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_co1==0){		
		m_s3.SetScrollInfo(&si3,true);
		//m_s3.SetScrollPos(510);
	}else{
		m_s3.SetScrollInfo(&si4,true);
	}
	if(m_co1!=1){
		m_s1.SetScrollPos(9);
	}
	UpdateData(FALSE);
	updateAndFilter();		
}
void CEdgeInput::updateAndFilter(bool willupdate/*=true*/){
	CFrameWnd *pWnd =(CFrameWnd*)  AfxGetMainWnd(); 
	CImageToWordsView *pView = (CImageToWordsView*)  pWnd->GetActiveView();
	CString str="";
	if(willupdate){
		UpdateData(TRUE);
		if(m_co1!=2){
			bj=(m_s1.GetScrollPos()+1)/10.0f;
		}else{
			bj=(int)((m_s1.GetScrollPos()+10)/10.0f);
		}
		sl=m_s2.GetScrollPos()>255 ? 514/(512-(float)m_s2.GetScrollPos())-1 : 510/(510-(float)m_s2.GetScrollPos())-1;
		if(m_co1==0){
			rate=m_s3.GetScrollPos()-100;
		}else{
			angle=m_s3.GetScrollPos();
		}
		bkg=m_s4.GetScrollPos()-2;
		if(bkg<0){
			cofs=bkg;
			bkg=0;
		}else if(bkg>255){
			cofs=bkg-255;
			bkg=255;
		}else{
			cofs=0;
		}
		if(m_co1!=2){
			str.Format("°ë¾¶(%.1f):",bj);
		}else{
			str.Format("°ë¾¶(%.0f):",bj);
		}
		m_l1.SetWindowText(str);
		str.Format("ÊýÁ¿(%.2f):",sl);
		m_l2.SetWindowText(str);
		if(m_co1==0){
			str.Format("Æ½ºâ(%d):",rate);
		}else{
			str.Format("½Ç¶È(%d):",angle);
		}
		m_l3.SetWindowText(str);
		if(cofs==0){
			str.Format("±³¾°(%d):",bkg);		
		}else{
			str.Format("±³¾°(%d%+d):",bkg,cofs);
		}
		m_l4.SetWindowText(str);
	}
	if(m_co1==0){
		pView->EdgeFilter1((int)(bj+0.5f),sl,rate,bkg,cofs);
	}else if(m_co1==1){
		double angle2=angle*3.141592653589793/180;
		double rx=bj*cos(angle2);
		double ry=bj*sin(angle2);
		int xs=(int)floor(rx);
		int ys=(int)floor(ry);
		float dx=(float)(rx-xs);
		float dy=(float)(ry-ys);
		float arr1[5]={-(1-dx)*(1-dy)*sl,-dx*(1-dy)*sl,-(1-dx)*dy*sl,-dx*dy*sl,sl+cofs};
		pView->ConvolutionFilter(arr1,bkg,5,2,-xs,-ys);
	}else if(m_co1==2){
		/*int r2=(int)bj;
		int leng2=2*r2+1;
		double angle3=angle>180?(angle+45)*3.141592653589793/180:(angle+45-360)*3.141592653589793/180;
		double angle4=angle>180?(angle-45)*3.141592653589793/180:(angle-45-360)*3.141592653589793/180;
		double angle5=(angle+45)*3.141592653589793/180;
		double anglet=0;
		float arr2[441];
		int k,l;
		float sum2=0;
		for(l=0;l<leng2;l++){
			for(k=0;k<leng2;k++){				
				if(k!=r2 && l!=r2){
					anglet=atan2(k-r2,r2-l);
					if(anglet>angle4 ){
						arr2[l*leng2+k]
					}else{

					}
				}
			}
		}
		pView->ConvolutionFilter(arr1,bkg,5,2,-xs,-ys);*/
		pView->resumePreview();
	}
	if(m_ch1==TRUE && willupdate){
		pView->previewHeibaien(128);
	}

}

void CEdgeInput::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);
	updateAndFilter();
}
