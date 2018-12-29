
// 2016302590184View.h : CMy2016302590184View 类的接口
//

#pragma once


class CMy2016302590184View : public CView
{
protected: // 仅从序列化创建
	int MenuID, PressNum, SaveNumber; // 菜单和子菜单标识
	CPoint mPointOrign, mPointOld,  mPointOld1, r1, cpt; // 橡皮筋实现
	CMy2016302590184View();
	DECLARE_DYNCREATE(CMy2016302590184View)

// 特性
public:
	CMy2016302590184Doc* GetDocument() const;
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
	virtual ~CMy2016302590184View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawDdaline();
	afx_msg void OnDrawBcircle();
	afx_msg void OnDrawPncircle();
	afx_msg void OnCurveBezier();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDrawMidline();
	afx_msg void OnDrawChar();
	afx_msg void OnCurveBsample();
	afx_msg void OnTransMove();
	afx_msg void OnTransSymmetry();
	afx_msg void OnFillSeed();
	afx_msg void OnEdgeFill();
	afx_msg void OnFillScanline();
	afx_msg void OnCutCs();
	afx_msg void OnCutPolygon();
	afx_msg void OnCutcircle();
	afx_msg void OnTransRotate();
	afx_msg void OnTransZoom();
	afx_msg void OnCurveHermite();
	afx_msg void OnCutMiddle();
	afx_msg void OnCutLiang();
};

#ifndef _DEBUG  // 2016302590184View.cpp 中的调试版本
inline CMy2016302590184Doc* CMy2016302590184View::GetDocument() const
   { return reinterpret_cast<CMy2016302590184Doc*>(m_pDocument); }
#endif

