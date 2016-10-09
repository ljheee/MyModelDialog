
// MFCDialogView.cpp : CMFCDialogView 类的实现
//

#include "stdafx.h"
#include "RectDialog.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_SELECTFILE, &CMFCDialogView::OnFileSelectfile)
	ON_COMMAND(ID_FILE_RECT, &CMFCDialogView::OnFileRect)
	ON_COMMAND(ID_FILE_RECT_OTHER, &CMFCDialogView::OnFileRectOther)
END_MESSAGE_MAP()

// CMFCDialogView 构造/析构

CMFCDialogView::CMFCDialogView()
{
	// TODO:  在此处添加构造代码

}

CMFCDialogView::~CMFCDialogView()
{
}

BOOL CMFCDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDialogView 绘制

void CMFCDialogView::OnDraw(CDC* /*pDC*/)
{
	CMFCDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFCDialogView 打印

BOOL CMFCDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFCDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFCDialogView 诊断

#ifdef _DEBUG
void CMFCDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDialogDoc* CMFCDialogView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDialogDoc)));
	return (CMFCDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDialogView 消息处理程序

//“选择文件”处理
void CMFCDialogView::OnFileSelectfile()
{
	// TODO:  在此添加命令处理程序代码
	CString filter;
	filter = "文本文件(*.txt)|*.txt|C++文件(*.h,*.cpp)|*.h;*.cpp||";
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
	// TODO:  在此添加命令处理程序代码
	CRectDialog *dlg = new CRectDialog;
	dlg->Create( IDD_DIALOG1);
	dlg->ShowWindow(SW_NORMAL);

}

//另外一种方式
void CMFCDialogView::OnFileRectOther()
{
	// TODO:  在此添加命令处理程序代码
	CRectDialog dlg;
	dlg.DoModal();
}
