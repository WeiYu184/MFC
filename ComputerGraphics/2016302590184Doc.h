
// 2016302590184Doc.h : CMy2016302590184Doc ��Ľӿ�
//


#pragma once


class CMy2016302590184Doc : public CDocument
{
protected: // �������л�����
	CMy2016302590184Doc();
	DECLARE_DYNCREATE(CMy2016302590184Doc)

// ����
public:
	CPoint group[100];	//��������
    COLORREF m_crColor;//����ͼ����ɫ

	int PointNum;
// ����
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

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy2016302590184Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnGraphcolor();
	// �е㻭�߷�
};
