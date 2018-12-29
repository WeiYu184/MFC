
// 2016302590184Doc.h : CMy2016302590184Doc 类的接口
//


#pragma once


class CMy2016302590184Doc : public CDocument
{
protected: // 仅从序列化创建
	CMy2016302590184Doc();
	DECLARE_DYNCREATE(CMy2016302590184Doc)

// 特性
public:
	CPoint group[100];	//定义数组
    COLORREF m_crColor;//保存图形颜色

	int PointNum;
// 操作
public:
	 void DDALine(CClientDC* DCPoint);
	 void MidLine(CClientDC* DCPoint);
	 void BCircle(CClientDC* DCPoint, CPoint p1, CPoint p2);
	 void BCircle(CClientDC* DCPoint, CRect* rc, CPoint p1, CPoint p2);
	 void ZCircle(CClientDC* DCPoint, CPoint p1, CPoint p2);
	 void Bezier(CClientDC* DCPoint, int mode);
	 void Bezier_4(CClientDC* DCPoint, int mode, CPoint p1, CPoint p2, CPoint p3, CPoint p4);
	 void BSample(CClientDC* DCPoint, int mode);
	 void BSample_4(CClientDC *pDC, int mode, CPoint p1, CPoint p2, CPoint p3, CPoint p4); 
	 void Hermite(CClientDC* pDC, int mode);
	 void Hermite_4(CClientDC *pDC,int mode,CPoint p1,CPoint p2,CPoint p3,CPoint p4);
	 void GenerateGraph(CClientDC* DCPoint);
	 void DrawGraph(CClientDC* DCPoint);
	 void Symmetry(CPoint p1,CPoint p2); 
	 void Rotate(CPoint mPointOrign, CPoint cpt, CPoint p);
	 void SeedFill(CClientDC* DCPoint, CPoint p);
	 void EdgeFill(CClientDC* DCPoint);
	 void DrawWindow(CClientDC* DCPoint);
	 void CohenSutherland(CClientDC* DCPoint, CPoint p1, CPoint p2);
	 int encode(int x, int y);
	 void PolygonCut(CClientDC* DCPoint); 
	 void EdgeClipping(int linecode);
	 void CircleCut(CClientDC* DCPoint);
	 void Liang(CClientDC* pDC, CPoint p1, CPoint p2);
	 void MiddleCut(CClientDC* pDC,CPoint p1,CPoint p2);

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMy2016302590184Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnGraphcolor();
	// 中点画线法
};
