
// MFCDialogView.cpp : CMFCDialogView ���ʵ��
//

#include "stdafx.h"
#include "RectDialog.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCDialog.h"
#endif

#include "MFCDialogDoc.h"
#include "MFCDialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDialogView

IMPLEMENT_DYNCREATE(CMFCDialogView, CView)

BEGIN_MESSAGE_MAP(CMFCDialogView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_SELECTFILE, &CMFCDialogView::OnFileSelectfile)
	ON_COMMAND(ID_FILE_RECT, &CMFCDialogView::OnFileRect)
	ON_COMMAND(ID_FILE_RECT_OTHER, &CMFCDialogView::OnFileRectOther)
END_MESSAGE_MAP()

// CMFCDialogView ����/����

CMFCDialogView::CMFCDialogView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFCDialogView::~CMFCDialogView()
{
}

BOOL CMFCDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCDialogView ����

void CMFCDialogView::OnDraw(CDC* /*pDC*/)
{
	CMFCDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCDialogView ��ӡ

BOOL CMFCDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFCDialogView ���

#ifdef _DEBUG
void CMFCDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDialogDoc* CMFCDialogView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDialogDoc)));
	return (CMFCDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDialogView ��Ϣ�������

//��ѡ���ļ�������
void CMFCDialogView::OnFileSelectfile()
{
	// TODO:  �ڴ���������������
	CString filter;
	filter = "�ı��ļ�(*.txt)|*.txt|C++�ļ�(*.h,*.cpp)|*.h;*.cpp||";
	CFileDialog dlg(TRUE,NULL ,NULL, OFN_HIDEREADONLY, filter);

	if (dlg.DoModal() == IDOK){
		CString str,fileName;
		str = dlg.GetPathName();
		fileName = dlg.GetFileName();

		char filePath[] = "FilePath";
		MessageBox(str);
		MessageBox(fileName);
	}


}


void CMFCDialogView::OnFileRect()
{
	// TODO:  �ڴ���������������
	CRectDialog *dlg = new CRectDialog;
	dlg->Create( IDD_DIALOG1);
	dlg->ShowWindow(SW_NORMAL);

}

//����һ�ַ�ʽ
void CMFCDialogView::OnFileRectOther()
{
	// TODO:  �ڴ���������������
	CRectDialog dlg;
	dlg.DoModal();
}
