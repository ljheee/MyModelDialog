
// MFCDialog.h : MFCDialog Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCDialogApp:
// �йش����ʵ�֣������ MFCDialog.cpp
//

class CMFCDialogApp : public CWinApp
{
public:
	CMFCDialogApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCDialogApp theApp;
