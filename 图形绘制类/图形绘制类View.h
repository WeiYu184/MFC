
// ͼ�λ�����View.h : Cͼ�λ�����View ��Ľӿ�
//

#pragma once


class Cͼ�λ�����View : public CView
{
protected: // �������л�����
	Cͼ�λ�����View();
	DECLARE_DYNCREATE(Cͼ�λ�����View)

// ����
public:
	Cͼ�λ�����Doc* GetDocument() const;

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
	virtual ~Cͼ�λ�����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ͼ�λ�����View.cpp �еĵ��԰汾
inline Cͼ�λ�����Doc* Cͼ�λ�����View::GetDocument() const
   { return reinterpret_cast<Cͼ�λ�����Doc*>(m_pDocument); }
#endif

