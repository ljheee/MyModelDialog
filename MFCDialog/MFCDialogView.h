
// MFCDialogView.h : CMFCDialogView 类的接口
//

#pragma once


class CMFCDialogView : public CView
{
protected: // 仅从序列化创建
	CMFCDialogView();
	DECLARE_DYNCREATE(CMFCDialogView)

// 特性
public:
	CMFCDialogDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileSelectfile();
	afx_msg void OnFileRect();
	afx_msg void OnFileRectOther();
};

#ifndef _DEBUG  // MFCDialogView.cpp 中的调试版本
inline CMFCDialogDoc* CMFCDialogView::GetDocument() const
   { return reinterpret_cast<CMFCDialogDoc*>(m_pDocument); }
#endif

