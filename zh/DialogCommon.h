// DialogCommon.h: interface for the CDialogCommon class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#if !defined(AFX_DIALOGCOMMON_H__1B3594A2_86B0_4748_8EF4_910E33B0A38F__INCLUDED_)
#define AFX_DIALOGCOMMON_H__1B3594A2_86B0_4748_8EF4_910E33B0A38F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CDialogCommon  
{
public:
	CDialogCommon();
	virtual ~CDialogCommon();
	void static initScroll(int leng,...)
	{
		va_list ap;
		int i;
		va_start(ap,leng);
		CScrollBar **m_s=new CScrollBar*[leng];
		SCROLLINFO si;
		for(i=0;i<leng;i++){
			m_s[i]=va_arg(ap,CScrollBar *);
		}
		for(i=0;i<leng;i++){
			si.fMask=SIF_ALL;						
			si.nMin=0;
			si.nPage=1;
			si.nPos=va_arg(ap,int);
			si.nMax=va_arg(ap,int);
			(m_s[i])->SetScrollInfo(&si,true);
		}
		va_end(ap);
		delete []m_s;
	}
	void static onHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
	{
		int stepl=1;
		int stepp=5;		
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
	}
	void static updateText(int leng,...)
	{
		va_list ap;
		int i,j;
		
		va_start(ap,leng);
		char str[50];
		CString cstr="";
		CStatic **m_l=new CStatic*[leng];
		for(i=0;i<leng;i++){
			m_l[i]=va_arg(ap,CStatic *);
		}
		for(i=0;i<leng;i++){			
			m_l[i]->GetWindowText(str,49);
			for(j=0;str[j]!='\0' && j<50;j++){
				if(str[j]=='(' || str[j]==':'){
					str[j]='\0';
					//cstr.Format("%s():"
				}
			}
		}
		
		va_end(ap);
		delete []m_l;
	}

};

#endif // !defined(AFX_DIALOGCOMMON_H__1B3594A2_86B0_4748_8EF4_910E33B0A38F__INCLUDED_)
