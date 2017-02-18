// CharacterSetInput.cpp : implementation file
//

#include "stdafx.h"
#include "ImageToWords.h"
#include "CharacterSetInput.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCharacterSetInput dialog


CCharacterSetInput::CCharacterSetInput(CWnd* pParent /*=NULL*/)
	: CDialog(CCharacterSetInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCharacterSetInput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCharacterSetInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCharacterSetInput)
	DDX_Control(pDX, IDC_LIST1, m_l1);
	DDX_Control(pDX, IDC_EDIT1, m_e1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCharacterSetInput, CDialog)
	//{{AFX_MSG_MAP(CCharacterSetInput)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharacterSetInput message handlers

BOOL CCharacterSetInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle = m_l1.GetExtendedStyle();
		dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
      dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��
      dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�
     m_l1.SetExtendedStyle(dwStyle); //������չ���
	int nRow=0;
	CRect rect;
	m_l1.GetWindowRect(&rect);
	ScreenToClient(&rect);
	m_l1.InsertColumn( 0, "����", LVCFMT_LEFT, rect.Width()-25);//������
	nRow=m_l1.InsertItem(nRow,"��Ƨ��(��GBK)");
	nRow=m_l1.InsertItem(nRow,"�γ�����");
	nRow=m_l1.InsertItem(nRow,"������");
	nRow=m_l1.InsertItem(nRow,"����ȫ�Ƿ���(��GBK)");
	nRow=m_l1.InsertItem(nRow,"����ȫ�Ƿ���(GB2312)");
	nRow=m_l1.InsertItem(nRow,"���İ�Ƿ���");
	nRow=m_l1.InsertItem(nRow,"Ӣ�ķ���");
	nRow=m_l1.InsertItem(nRow,"��д��ĸ");
	nRow=m_l1.InsertItem(nRow,"Сд��ĸ");
	nRow=m_l1.InsertItem(nRow,"����������");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCharacterSetInput::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int selId;
	char str[65537];
	int leng0;
	m_e1.GetWindowText(str,65537);
	leng0=strlen(str);
	int n=0;
	char i=0,j=0;
      for(n=0; n<m_l1.GetItemCount(); n++)
      {
           if( m_l1.GetItemState(n, LVIS_SELECTED) == LVIS_SELECTED )
           {
                selId=n;
				break;
           }
      }
		n=leng0;
	  switch(selId){
		case 0:
			for(i=0;i<10 && n<65536;i++,n++){
				str[n]='0'+i;
			}
			break;
		case 1:
			for(i=0;i<26 && n<65536;i++,n++){
				str[n]='a'+i;
			}
			break;
		case 2:			
			for(i=0;i<26 && n<65536;i++,n++){
				str[n]='A'+i;
			}
			break;
		case 3:
			for(i=32;i<=47 && n<65536;i++,n++){
				str[n]=i;
			}
			for(i=58;i<=63 && n<65536;i++,n++){
				str[n]=i;
			}
			for(i=91;i<=96 && n<65536;i++,n++){
				str[n]=i;
			}
			for(i=123;i<=126 && n<65536;i++,n++){
				str[n]=i;
			}
			break;
		case 4:
			for(i=1;i<=9 && n<65536;i++){
				for(j=1;j<=94 && n<65536;j++){
					str[n]=i+160;
					n++;
					str[n]=j+160;
					n++;
				}
			}			
			break;
		case 5:
			for(i=1;i<=9 && n<65536;i++){
				for(j=1;j<=94 && n<65536;j++){
					str[n]=i+160;
					n++;
					str[n]=j+160;
					n++;
				}
			}			
			break;
		case 7:
			for(i=16;i<=55 && n<65536;i++){
				for(j=1;j<=94 && n<65536;j++){
					str[n]=i+160;
					n++;
					str[n]=j+160;
					n++;
				}
			}			
			break;
		case 8:
			for(i=56;i<=87 && n<65536;i++){
				for(j=1;j<=94 && n<65536;j++){
					str[n]=i+160;
					n++;
					str[n]=j+160;
					n++;
				}
			}			
			break;
		default:
			n++;
			break;
	  }
	  str[n]='\0';
	  m_e1.SetWindowText(str);
	
	*pResult = 0;
}

void CCharacterSetInput::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CWnd *pWnd,*pWnd2,*pWnd3;
	 int centx,btnw,btnh,listh;
    pWnd = GetDlgItem(IDC_EDIT1);     //��ȡ�ؼ����
	pWnd2 = GetDlgItem(IDCANCEL);
	pWnd3 = GetDlgItem(IDC_LIST1);
    if(nType==1) return;   //����Ǵ�����С����ʲô������
    if(pWnd && pWnd2)//�ж��Ƿ�Ϊ�գ���Ϊ�Ի��򴴽�ʱ����ô˺���������ʱ�ؼ���δ����
    {
      CRect rect,rect2,rect3;   //��ȡ�ؼ��仯ǰ��С
      pWnd->GetWindowRect(&rect);
	  pWnd2->GetWindowRect(&rect2);
		pWnd3->GetWindowRect(&rect3);
      ScreenToClient(&rect);//���ؼ���Сת��Ϊ�ڶԻ����е���������
		ScreenToClient(&rect2);
		ScreenToClient(&rect3);
		centx=cx/2;
		  btnw=rect2.Width();
		  btnh=rect2.Height();
		
		listh=rect3.Height();
		  rect.right=cx-10;      
		  rect.bottom=cy-btnh-15-listh;
		  
		  rect3.bottom=cy-btnh-15;
		  rect3.top=rect.bottom;
		  rect3.right=rect.right;  
		rect2.bottom=cy-7;
		rect2.top=cy-7-btnh;
		rect2.right=centx+btnw/2;
		rect2.left=centx-btnw/2;

		
		pWnd->MoveWindow(rect);//���ÿؼ���С
		pWnd3->MoveWindow(rect3);
		pWnd2->MoveWindow(rect2);
		

		pWnd2 = GetDlgItem(IDC_BUTTON1);
		pWnd2->GetWindowRect(&rect2);
		ScreenToClient(&rect2);
		rect2.bottom=cy-7;
		rect2.top=cy-7-btnh;
		rect2.right=centx+9+3*btnw/2;
		rect2.left=centx+9+btnw/2;
		pWnd2->MoveWindow(rect2);
		

		pWnd2 = GetDlgItem(IDOK);
		pWnd2->GetWindowRect(&rect2);
		ScreenToClient(&rect2);
		rect2.bottom=cy-7;
		rect2.top=cy-7-btnh;
		rect2.right=centx-9-btnw/2;
		rect2.left=centx-9-3*btnw/2;		
		pWnd2->MoveWindow(rect2);
		rect.left=0;
		rect.right=cx;
		rect.bottom=cy;
		rect.top=cy-btnh-15;
		InvalidateRect(rect);
    }
    GetClientRect(&m_rect0);
}
