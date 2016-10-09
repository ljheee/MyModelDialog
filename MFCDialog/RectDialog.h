#pragma once
#include "resource.h"
#include "afxwin.h"

// CRectDialog 对话框

class CRectDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CRectDialog)

public:
	CRectDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRectDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCal();
	CEdit m_editWidth;
	afx_msg void OnBnClickedButton1();
	CEdit m_editHeight;
	CEdit m_editArea;
};
