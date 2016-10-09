
// MFCDialogView.h : CMFCDialogView ��Ľӿ�
//

#pragma once


class CMFCDialogView : public CView
{
protected: // �������л�����
	CMFCDialogView();
	DECLARE_DYNCREATE(CMFCDialogView)

// ����
public:
	CMFCDialogDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileSelectfile();
	afx_msg void OnFileRect();
	afx_msg void OnFileRectOther();
};

#ifndef _DEBUG  // MFCDialogView.cpp �еĵ��԰汾
inline CMFCDialogDoc* CMFCDialogView::GetDocument() const
   { return reinterpret_cast<CMFCDialogDoc*>(m_pDocument); }
#endif

