#pragma once
#include "resource.h"
#include "afxwin.h"

// CRectDialog �Ի���

class CRectDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CRectDialog)

public:
	CRectDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRectDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCal();
	CEdit m_editWidth;
	afx_msg void OnBnClickedButton1();
	CEdit m_editHeight;
	CEdit m_editArea;
};
