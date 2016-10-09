// RectDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCDialog.h"
#include "RectDialog.h"
#include "afxdialogex.h"


// CRectDialog 对话框

IMPLEMENT_DYNAMIC(CRectDialog, CDialogEx)

CRectDialog::CRectDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRectDialog::IDD, pParent)
{

}

CRectDialog::~CRectDialog()
{
}

void CRectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_WIDTH, m_editWidth);
	DDX_Control(pDX, IDC_EDIT_HIGHT, m_editHeight);
	DDX_Control(pDX, IDC_EDIT_AREA, m_editArea);
}


BEGIN_MESSAGE_MAP(CRectDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CAL, &CRectDialog::OnBnClickedButtonCal)
	ON_BN_CLICKED(IDC_BUTTON1, &CRectDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CRectDialog 消息处理程序

//此button在Dialog里。直接从控件获取值
void CRectDialog::OnBnClickedButtonCal()
{
	char ch1[10], ch2[10], ch3[10];
	
	int width, height, area;

	::GetWindowText(::GetDlgItem(m_hWnd, IDC_EDIT_WIDTH), ch1, 10);
	::GetWindowText(::GetDlgItem(m_hWnd, IDC_EDIT_HIGHT), ch2, 10);

	width = atoi(ch1);
	height = atoi(ch2);
	area = width*height;

	_itoa_s(area , ch3 , 10);
	::SetWindowText(::GetDlgItem(m_hWnd , IDC_EDIT_AREA), ch3);
}

//另外一种获取编辑框中数值的方式。给编辑框--"添加变量":变量和控件关联
void CRectDialog::OnBnClickedButton1()
{
	char ch1[10], ch2[10], ch3[10];
	int width, height, area;

	int nChars = m_editWidth.LineLength(m_editWidth.LineIndex(0));
	m_editWidth.GetLine(0, ch1, nChars);

	m_editWidth.GetWindowTextA(ch1 ,10);
	m_editHeight.GetWindowTextA(ch2 ,10);

	//类型转换：array --->int
	width = atoi(ch1);
	height = atoi(ch2);
	area = width*height;

	_itoa_s(area, ch3, 10);

	m_editArea.SetWindowTextA(ch3);
}
