// Type.cpp : 实现文件
//

#include "stdafx.h"
#include "Drawing.h"
#include "Type.h"
#include "afxdialogex.h"
#include "Shape.h"


// CType 对话框

IMPLEMENT_DYNAMIC(CType, CDialogEx)

CType::CType(CWnd* pParent /*=NULL*/)
	: CDialogEx(CType::IDD, pParent)
{
	m_Angle = 30;
	m_Height = 100;
	m_Width = 200;
	m_LineWidt = 1;
	m_OrgX = 200;
	m_OrgY = 200;
	m_strTYType = _T("");
	m_intListType = 0;
	m_intFillType = 0;
	color_Fill = RGB(205, 20, 0);  //color
	color_Line = RGB(255, 0, 0);  //
}

CType::~CType()
{
}

void CType::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Angele, m_Angle);
	DDV_MinMaxInt(pDX, m_Angle, 0, 360);
	DDX_Text(pDX, IDC_Height, m_Height);
	DDV_MinMaxInt(pDX, m_Height, 0, 999999);
	DDX_Text(pDX, IDC_LineWidth, m_LineWidt);
	DDV_MinMaxInt(pDX, m_LineWidt, 0, 999999);
	DDX_Text(pDX, IDC_OrgX, m_OrgX);
	DDV_MinMaxInt(pDX, m_OrgX, 0, 999999);
	DDX_Text(pDX, IDC_OrgY, m_OrgY);
	DDV_MinMaxInt(pDX, m_OrgY, 0, 999999);
	DDX_Text(pDX, IDC_Width, m_Width);
	DDV_MinMaxInt(pDX, m_Width, 0, 9999999);
	DDX_Control(pDX, IDC_TYType, m_TYType);
	DDX_Control(pDX, IDC_FillType, m_FillType);
	DDX_Control(pDX, IDC_LineType, m_LineType);
	DDX_CBString(pDX, IDC_TYType, m_strTYType);
	DDX_LBIndex(pDX, IDC_LineType, m_intListType);
	DDX_LBIndex(pDX, IDC_FillType, m_intFillType);
}


BEGIN_MESSAGE_MAP(CType, CDialogEx)
	ON_BN_CLICKED(IDOK, &CType::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_TYType, &CType::OnCbnSelchangeTytype)
	ON_BN_CLICKED(IDC_LineColorBUTTON, &CType::OnBnClickedLinecolorbutton)
	ON_BN_CLICKED(IDC_FillColorBUTTON, &CType::OnBnClickedFillcolorbutton)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CType 消息处理程序
char *coure_Type[]={
	"正方形","矩形","三角形", "圆", "椭圆","文字"
};
char *coure_Line[]={
	  "PS_SOLID", "PS_DASH", "PS_DOT"
};
char *coure_Fill[]={
	"HS_DIAGCROSS", "HS_CROSS", "HS_BDIAGONAL"
};

BOOL CType::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for (int i=0;i<6;i++)
	{
		m_TYType.AddString(coure_Type[i]);
	}
	int ind = ((CDrawingApp *)AfxGetApp())->m_index;
	m_TYType.SetCurSel(ind);
	if(ind==5)
		GetDlgItem(IDC_Angele)->ShowWindow(TRUE),GetDlgItem(IDC_STATIC00)->ShowWindow(TRUE);
	for (int i=0;i<3;i++)
	{
		m_LineType.AddString(coure_Line[i]);
		m_FillType.AddString(coure_Fill[i]);
	}
	m_LineType.SetCurSel(0);
	m_FillType.SetCurSel(0);
	((CDrawingApp *)AfxGetApp())->m_index = m_TYType.GetCurSel();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CType::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();

	CDialogEx::OnOK();
}


void CType::OnCbnSelchangeTytype()
{
	// TODO: 在此添加控件通知处理程序代码
	int isSel=((CDrawingApp *)AfxGetApp())->m_index = m_TYType.GetCurSel();
	switch (isSel)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		GetDlgItem(IDC_Angele)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC00)->ShowWindow(FALSE);
		break;
	case 5:
		GetDlgItem(IDC_Angele)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC00)->ShowWindow(TRUE);
		break;
	}
}


void CType::OnBnClickedLinecolorbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	color_Line = RGB(255, 0, 0);//初始化
	CColorDialog colorDlg(color_Line);
	if (IDOK == colorDlg.DoModal())
	{
		color_Line = colorDlg.GetColor();
		Invalidate(TRUE);
	}
}


void CType::OnBnClickedFillcolorbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CColorDialog colorDlg(color_Fill);
	if (IDOK == colorDlg.DoModal())
	{
		color_Fill = colorDlg.GetColor();
		Invalidate(TRUE);
	}
}


HBRUSH CType::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_LineColor)//如果是编辑框
	{
		pDC->SetBkColor(color_Line);//设置字体背景颜色
	}
	if (pWnd->GetDlgCtrlID() == IDC_FillColor)//如果是编辑框
	{
		pDC->SetBkColor(color_Fill);//设置字体背景颜色
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

