
// 2016302590184View.cpp : CMy2016302590184View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2016302590184.h"
#endif

#include "2016302590184Doc.h"
#include "2016302590184View.h"
#include "DrawCharDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CMFCStatusBar m_wndStatusBar;

// CMy2016302590184View

IMPLEMENT_DYNCREATE(CMy2016302590184View, CView)

BEGIN_MESSAGE_MAP(CMy2016302590184View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2016302590184View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_DDALINE, &CMy2016302590184View::OnDrawDdaline)
	ON_COMMAND(ID_DRAW_BCIRCLE, &CMy2016302590184View::OnDrawBcircle)
	ON_COMMAND(ID_DRAW_PNCIRCLE, &CMy2016302590184View::OnDrawPncircle)
	ON_COMMAND(ID_CURVE_BEZIER, &CMy2016302590184View::OnCurveBezier)
//	ON_WM_NCLBUTTONDBLCLK()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_DRAW_MIDLINE, &CMy2016302590184View::OnDrawMidline)
	ON_COMMAND(ID_DRAWCHAR, &CMy2016302590184View::OnDrawChar)
	ON_COMMAND(ID_CURVE_BSAMPLE, &CMy2016302590184View::OnCurveBsample)
	ON_COMMAND(ID_TRANS_MOVE, &CMy2016302590184View::OnTransMove)
	ON_COMMAND(ID_TRANS_SYMMETRY, &CMy2016302590184View::OnTransSymmetry)
	ON_COMMAND(ID_FILL_SEED, &CMy2016302590184View::OnFillSeed)
	ON_COMMAND(ID_EDGE_FILL, &CMy2016302590184View::OnEdgeFill)
	ON_COMMAND(ID_FILL_SCANLINE, &CMy2016302590184View::OnFillScanline)
	ON_COMMAND(ID_CUT_CS, &CMy2016302590184View::OnCutCs)
	ON_COMMAND(ID_CUT_POLYGON, &CMy2016302590184View::OnCutPolygon)
	ON_COMMAND(ID_CUTCIRCLE, &CMy2016302590184View::OnCutcircle)
	ON_COMMAND(ID_TRANS_ROTATE, &CMy2016302590184View::OnTransRotate)
	ON_COMMAND(ID_TRANS_ZOOM, &CMy2016302590184View::OnTransZoom)
	ON_COMMAND(ID_CURVE_HERMITE, &CMy2016302590184View::OnCurveHermite)
	ON_COMMAND(ID_CUT_MIDDLE, &CMy2016302590184View::OnCutMiddle)
	ON_COMMAND(ID_CUT_LIANG, &CMy2016302590184View::OnCutLiang)
END_MESSAGE_MAP()

// CMy2016302590184View ����/����

CMy2016302590184View::CMy2016302590184View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy2016302590184View::~CMy2016302590184View()
{
}

BOOL CMy2016302590184View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2016302590184View ����

void CMy2016302590184View::OnDraw(CDC* /*pDC*/)
{
	CMy2016302590184Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2016302590184View ��ӡ


void CMy2016302590184View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2016302590184View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2016302590184View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2016302590184View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CMy2016302590184View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2016302590184View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2016302590184View ���

#ifdef _DEBUG
void CMy2016302590184View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2016302590184View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2016302590184Doc* CMy2016302590184View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2016302590184Doc)));
	return (CMy2016302590184Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2016302590184View ��Ϣ�������
/**********************************************windows�¼���������**************************************************/
/*Windows ϵͳ����������¼����簴���̣�����꣬�򿪡��رմ��ڵȣ���ϵͳ�У� �������� WM_��ͷ�ı�����ʶ��Windows ϵͳ
 *�Զ�������е���Щ�¼�����ĳһ�¼����� ʱ���簴����������ϵͳ����֪ͨӦ�ó���Ӧ�ó����л�����¼�������Ӧ�����
 *��Ӧ�� ��Ҫ���ʵ�֡�*********************************************************************************************/

void CMy2016302590184View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
    CClientDC ht(this); //���嵱ǰ��ͼ�豸
   ////////////////////////////////////////////////////////////////////////// DDA ֱ�ߺ��е㻭�߷�
	if ( MenuID == 1 || MenuID == 2 )
    { 
        if (PressNum == 0)
        {   //��һ�ΰ�������һ�㱣�����ĵ���������
            pDoc->group[PressNum] = point;
            PressNum++;    
			mPointOrign = point;
			mPointOld = point; // ��¼��һ��
			SetCapture(); 
        }
		/////////////////////////////////////////////////////////////////////////// DDA ֱ��
        else if (PressNum == 1 && MenuID == 1)
        {   //�ڶ��ΰ��������ڶ��㣬���ĵ��໭��
            pDoc->group[PressNum] = point;
            PressNum = 0;//����ͼ 
            pDoc->DDALine(&ht);
            ReleaseCapture();
        }
		/////////////////////////////////////////////////////////////////////////// �е㻭�߷�
		else if(PressNum == 1 && MenuID == 2)
		{
			pDoc->group[PressNum] = point;
            PressNum = 0;//����ͼ 
            pDoc->MidLine(&ht);
            ReleaseCapture();
		}
	}

	////////////////////////////////////////////////////////////////////////////// Bresenham Բ 
	if (MenuID == 3 || MenuID == 4 || MenuID == 33)
	{ 
		if (PressNum == 0)
		{//��һ�ΰ�������һ�㱣���� mPointOrign 
			pDoc->group[PressNum] = point;
			PressNum++;
			mPointOrign = point;
			mPointOld = point; //��¼��һ�� 
			SetCapture();
		}
		else if (PressNum == 1 && MenuID == 3)
		{//�ڶ��ΰ��������ĵ��໭Բ����ͼ 
			pDoc->group[PressNum] = point;
			PressNum = 0;
			pDoc->BCircle(&ht, mPointOrign, point); ReleaseCapture();
		}
		else if (PressNum == 1 && MenuID == 4)
        {//�ڶ��ΰ������û�Բ����ͼ
            PressNum = 0;
			pDoc->ZCircle(&ht, mPointOrign, point); ReleaseCapture();
        }
///////////////////////////////////////////////////////////////////////////////////////////// Բ�ü�
		else if(PressNum == 1 && MenuID == 33) 					
		{
			pDoc->group[PressNum] = point;
			PressNum = 0;
			pDoc->CircleCut(&ht);
			ReleaseCapture();
		}

	}
	///////////////////////////////////////////////////////////// Bezier ����  B��������  Hermite����
	if(MenuID == 5 || MenuID == 7 || MenuID == 9)
	{ // ѡ�㲢��ʮ�ֱ�־ 
		pDoc->group[pDoc->PointNum++] = point; 
		ht.MoveTo(point.x-5,point.y); 
		ht.LineTo(point.x+5,point.y); 
		ht.MoveTo(point.x,point.y-5); 
		ht.LineTo(point.x,point.y+5); 
		SetCapture(); 
		PressNum = 1; 
	} 

	if(MenuID == 6 && PressNum == 0)
	{//  �ڿ��Ƶ������У����Ѱ��
		for(int i = 0; i<pDoc->PointNum;i++) 
		{ 
			if((point.x>=pDoc->group[i].x-5)&&(point.x<=pDoc->group[i].x+5) &&(point.y>=pDoc->group[i].y-5)&&(point.y<=pDoc->group[i].y+5)) 
			{ 
				SaveNumber = i;
				PressNum=1;
			}
		}
	}
	if(MenuID == 6 && PressNum == 1) PressNum = 0; 

	///////////////////////////////////////////////////////////////////////////////  ƽ�� 
	if(MenuID == 11) { 
    if(PressNum == 0){ 
	    PressNum++; 
        mPointOrign = point; 
        mPointOld = point; //��¼��һ�� 
        SetCapture(); 
    } 
    else if(PressNum == 1)
	{	//�������������ƽ����
        for(int i = 0; i<pDoc->PointNum;i++)//����ƽ����������ͼ������
        {
            pDoc->group[i].x += point.x - mPointOrign.x; 
            pDoc->group[i].y += point.y-mPointOrign.y; 
        } 
        ht.MoveTo(mPointOrign);//������Ƥ��
        ht.LineTo(point); 
        pDoc->DrawGraph(&ht);//������ͼ�� 
        ReleaseCapture();
        PressNum = 0; 
	} }

	/////////////////////////////////////////////////////////////////////////////// ��ת
	if(MenuID == 12) 
	{ 
		if(PressNum == 0)
		{ 
			PressNum++; 
            mPointOrign = point; 
            mPointOld = point; // ��¼��һ�� 
			r1 = mPointOld;
            SetCapture(); 
        } 
        else if(PressNum == 1)
		{
			cpt = point;
			mPointOrign = cpt; 
			PressNum++;
		}
		else if(PressNum == 2)
		{
			pDoc->Rotate(r1, cpt, point); // ������ת�任
			pDoc->DrawGraph(&ht); // ������ͼ�� 
            ReleaseCapture();
            PressNum = 0; 
		}
	}

	///////////////////////////////////////////////////////////////////////////// ����
	if(MenuID == 13)
	{
		 if(PressNum == 0)
		 {
			 PressNum++; 
             mPointOrign = point; 
             mPointOld = point; //��¼��һ��
			 r1 = mPointOld;
             SetCapture(); 
         } 
         else if(PressNum == 1)
	     {	//����������������ű���
			 float sx, sy, x, y;
			 sx = (-(double)r1.x + point.x)/100.0;
			 sy = (point.y - (double)r1.y)/100.0;   
			for(int i=0;i<pDoc->PointNum;i++) // ������ͼ������
			{
			   x = (pDoc->group[i].x - r1.x)*sx + r1.x;
		       y = (pDoc->group[i].y - r1.y)*sy + r1.y;
               pDoc->group[i].x = x;
			   pDoc->group[i].y = y; 
			}
             ht.MoveTo(mPointOrign);//������Ƥ��
             ht.LineTo(point); 
             pDoc->DrawGraph(&ht);//������ͼ�� 
             ReleaseCapture();
             PressNum = 0; 
		 }
	}

	///////////////////////////////////////////////////////////////////////// �ԳƱ任 
	if(MenuID == 15) 
	{ 
    if(PressNum == 0){ 
        PressNum++; 
        mPointOrign = point; 
        mPointOld = point; // ��¼��һ�� 
        SetCapture(); 
    } 
    else if(PressNum == 1){ 
        pDoc->Symmetry(mPointOrign, point); // ���жԳƱ任
        pDoc->DrawGraph(&ht); // ������ͼ�� 
        ReleaseCapture();
        PressNum = 0; 
	} }

	//////////////////////////////////////////////////////////////////// �������:���߽�
	if(MenuID == 20) { // �������:���߽�
    if(PressNum == 0){ 
        mPointOrign = point; mPointOld = point; 
        mPointOld1 = point; //��¼��һ�� 
        PressNum++; 
        SetCapture();
    }
    else{ 
        ht.MoveTo(mPointOrign); // ������Ƥ�� 
        ht.LineTo(point); 
        pDoc->group[0] = mPointOrign; // ���� DDA ֱ�ߺ������߽� 
		pDoc->group[1] = point; 
        pDoc->DDALine(&ht);
        mPointOrign = point; 
        mPointOld = point; 
        PressNum++; 
    } } 
	if(MenuID == 21) 
	{ // ȷ�����ӵ㣬��� 
		pDoc->SeedFill(&ht, point);
		PressNum = 0; 
		MenuID = 20;//���þ������������ʽ
	}

	////////////////////////////////////////////////////////// ��Ե��� ɨ������� ����βü�
	if(MenuID == 22 || MenuID == 23 || MenuID == 25) 
	{ // ��Ե���ѡ���� 
		pDoc->group[PressNum++] = point; 
		pDoc->PointNum++; 
		mPointOrign = point; 
		mPointOld = point; 
		SetCapture(); 
	} 
	/////////////////////////////////////////////////////// Cohen-sutherland �ü��㷨 
	if(MenuID == 24) 
	{ // Cohen-sutherland �ü��㷨 
		if(PressNum == 0)
		{ 
			mPointOrign = point; 
			mPointOld = point; 
			PressNum++; 
			SetCapture(); 
		} 
		else 
		{ 
			pDoc->CohenSutherland(&ht, mPointOrign, point);
			ReleaseCapture();
			PressNum = 0; 
		}
	} 
	/////////////////////////////////////////////////////////////// ���Ѷ�-Barsky�㷨
	if(MenuID == 34) { // liang�ü��㷨 
		if(PressNum == 0){ 
			mPointOrign = point; 
			mPointOld = point; 
			PressNum++; 
			SetCapture(); 
		} 
		else 
		{ 
			pDoc->Liang(&ht, mPointOrign, point);
			ReleaseCapture();
			PressNum = 0; 
		} 
	} 
	/////////////////////////////////////////////////////////////// middle �ü��㷨
	if(MenuID == 35) { 
		if(PressNum == 0){
			mPointOrign=point;
			mPointOld=point;
			PressNum++;
			SetCapture();
		}
		else
		{
			pDoc->MiddleCut(&ht, mPointOrign, point);
			ReleaseCapture();
			PressNum = 0;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy2016302590184View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
    CClientDC ht(this); //���嵱ǰ��ͼ�豸
    OnPrepareDC(&ht);
    ht.DPtoLP(&point);
	/////////////////////////////////////////////////////////////////////////////// Bezier ���� 
    /////////////////////////////////////////////////////////////////////////////// B ���� ����
	/////////////////////////////////////////////////////////////////////////////// Hermite����
	if (MenuID == 5 || MenuID == 7 || MenuID == 9 && pDoc->PointNum > 3)
	{
		if (MenuID == 5)
		{//���� Bezier ���� 
			pDoc->Bezier(&ht, 1);
			MenuID = 6; //������Ĳ�����Ϊ�޸Ŀ��Ƶ�λ��
		}
		else if(MenuID==7)
		{
			pDoc->BSample(&ht, 1);
			MenuID = 8;
		}
		else if (MenuID==9)
		{
			pDoc->Hermite(&ht, 1);
			MenuID = 10;
		}
		PressNum = 0;
	}

	//////////////////////////////////////////////////////////////////////////////////// ������� 
	if(MenuID == 20 && PressNum > 0) 
	{ //  ������� 
		ht.MoveTo(mPointOrign);//������Ƥ��
		ht.LineTo(point); 
		pDoc->group[0] = mPointOld1;//��ն����
		pDoc->group[1] = mPointOrign; 
		pDoc->DDALine(&ht);
		PressNum = 0; MenuID = 21;//�ı������ʽΪ���ӵ�ѡȡ
		ReleaseCapture(); 
	} 

	/////////////////////////////////////////////////////////////////////////////////// ��Ե���
	if( MenuID == 22 ) { // ��Ե���ѡ����� 
    pDoc->group[PressNum] = pDoc->group[0]; 
	pDoc->PointNum++; 
    ht.MoveTo(pDoc->group[PressNum-1]);
    ht.LineTo(pDoc->group[0]); 
    for(int i = 0; i < PressNum; i++) 
    ht.LineTo(pDoc->group[i+1]); 
	pDoc->EdgeFill(&ht);
    PressNum = 0; pDoc->PointNum=0;  ReleaseCapture(); 
} 
	////////////////////////////////////////////////////////////////////////////////// ɨ�������
	if(MenuID == 23){ 
    pDoc->group[PressNum]=pDoc->group[0]; //��ն����
    ht.MoveTo(pDoc->group[PressNum-1]); //����
    ht.LineTo(pDoc->group[0]); 
    for(int i = 0; i < PressNum; i++) //���� 
    ht.LineTo(pDoc->group[i+1]); 
	CPen pen(PS_SOLID,1, RGB(255,0,0));//���ö���α߽���ɫ�������ʣ� 
    CPen* pOldPen = ht.SelectObject(&pen);
    CBrush brush(RGB(0,255,0));	//���ö���������ɫ������ˢ��
    CBrush* pOldBrush = ht.SelectObject(&brush);
    ht.SetROP2(R2_COPYPEN);	//����ֱ�ӻ���ʽ
    ht.Polygon(pDoc->group,PressNum);//���ö����ɨ������亯�� 
    ht.SelectObject(pOldPen);//�ָ�ϵͳ�Ļ��ʡ���ˢ��ɫ���� 
    ht.SelectObject(pOldBrush); 
    PressNum=0; pDoc->PointNum = 0;//��ʼ��������Ϊ��һ�β�����׼�� 
    ReleaseCapture(); 
} 

	//////////////////////////////////////////////////////////////////////////// ����βü� 
	if(MenuID == 25) { 
    pDoc->group[PressNum]=pDoc->group[0];//����һ��������Ϊ���һ������ 
    pDoc->PointNum=PressNum;	//��¼��������
    ht.MoveTo(pDoc->group[PressNum-1]); ht.LineTo(pDoc->group[0]); 
    pDoc->PolygonCut(&ht);
    PressNum=0;pDoc->PointNum = 0; 
    ReleaseCapture(); 
  }

	CView::OnRButtonDown(nFlags, point);
}


void CMy2016302590184View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
	int xx, yy;
	char p1[20];
	xx = point.x;
	yy = point.y;
	sprintf(p1, "%4d", xx);
	m_wndStatusBar.SetPaneText(2, p1, TRUE);
	sprintf(p1, "%4d", yy);
	m_wndStatusBar.SetPaneText(3, p1, TRUE);
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDC.DPtoLP(&point); 
	pDC.SetROP2(R2_NOT); // �������ʽ 
	xx=point.x;yy=point.y; 
	sprintf(p1,"%4d", xx);
	m_wndStatusBar.SetPaneText(2,p1,TRUE); 
	sprintf(p1,"%4d", yy);
	m_wndStatusBar.SetPaneText(3,p1,TRUE); 
	if( (MenuID == 1 || MenuID == 2 || MenuID == 11 || MenuID == 12 || MenuID == 13 || MenuID == 15 || MenuID == 20 || MenuID == 22 || MenuID == 23 || MenuID == 21 ||MenuID == 24 || MenuID == 25 || MenuID == 34 || MenuID == 35 ) && PressNum > 0)
	{ 
		if(mPointOld!=point)
		{ 
			pDC.MoveTo(mPointOrign);    
			pDC.LineTo(mPointOld); // ������ 
			pDC.MoveTo(mPointOrign);   
			pDC.LineTo(point);     // ������ 
			mPointOld = point; 
		} 
	}

	if (( MenuID == 3 || MenuID==4 || MenuID == 33 ) && PressNum == 1)
    {
        pDC.SelectStockObject(NULL_BRUSH);//������Բ 
        if (mPointOld != point)
        {
            double r = (int)sqrt((double)(mPointOrign.x - mPointOld.x) * (mPointOrign.x - mPointOld.x) + (mPointOrign.y - mPointOld.y) * (mPointOrign.y - mPointOld.y));
			pDC.Ellipse(mPointOrign.x - r, mPointOrign.y - r, mPointOrign.x + r, mPointOrign.y + r);//����Բ 
            r = (int)sqrt((double)(mPointOrign.x - point.x) * (mPointOrign.x - point.x) + (mPointOrign.y - point.y) * (mPointOrign.y - point.y));
            pDC.Ellipse(mPointOrign.x - r, mPointOrign.y - r, mPointOrign.x + r, mPointOrign.y + r);//����Բ 
            mPointOld = point;
        }
    }
	if(MenuID == 6 && PressNum > 0)
	{ 
		if(pDoc->group[SaveNumber] != point) 
		{ 
			pDC.MoveTo(pDoc->group[SaveNumber].x-5,pDoc->group[SaveNumber].y);
			pDC.LineTo(pDoc->group[SaveNumber].x+5,pDoc->group[SaveNumber].y); 
			pDC.MoveTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y-5); 
            pDC.LineTo(pDoc->group[SaveNumber].x,pDoc->group[SaveNumber].y+5); 
            pDoc->Bezier(&pDC,1);//����ʮ�ֱ�־�;��� 
            pDC.MoveTo(point.x-5, point.y); 
            pDC.LineTo(point.x+5, point.y); 
            pDC.MoveTo(point.x, point.y-5); 
            pDC.LineTo(point.x, point.y+5); 
            pDoc->group[SaveNumber] = point; // ��¼�¿��Ƶ� 
            pDoc->Bezier(&pDC,1); // ��ʮ�ֱ�־�������� 
         } 
    }

	CView::OnMouseMove(nFlags, point);
}


void CMy2016302590184View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDC.DPtoLP(&point);
    pDC.SetROP2(R2_NOT); // �������ʽ 
	/////////////////////////////////////////////////////// Beizer ����
    if (MenuID == 6)
    {
        for (int i = 0; i < pDoc->PointNum; i++)
        {//�������й�� 
            pDC.MoveTo(pDoc->group[i].x - 5, pDoc->group[i].y);
            pDC.LineTo(pDoc->group[i].x + 5, pDoc->group[i].y);
            pDC.MoveTo(pDoc->group[i].x, pDoc->group[i].y - 5);
            pDC.LineTo(pDoc->group[i].x, pDoc->group[i].y + 5);
        }
        pDoc->Bezier(&pDC, 0);//���� Bezier ���� 

        MenuID = 5; //������Ĳ����Ļ� Bezier ���߷�ʽ
        PressNum = 0;
        pDoc->PointNum = 0;
        ReleaseCapture();
    }

	/////////////////////////////////////////////////////// B ���� ����
    if (MenuID == 8)
    {
        for (int i = 0; i < pDoc->PointNum; i++)
        {//�������й�� 
            pDC.MoveTo(pDoc->group[i].x - 5, pDoc->group[i].y);
            pDC.LineTo(pDoc->group[i].x + 5, pDoc->group[i].y);
            pDC.MoveTo(pDoc->group[i].x, pDoc->group[i].y - 5);
            pDC.LineTo(pDoc->group[i].x, pDoc->group[i].y + 5);
        }
        pDoc->BSample(&pDC, 0);//���� B ���� ����

        MenuID = 7; //������Ĳ����Ļ� B ���� ���߷�ʽ
        PressNum = 0;
        pDoc->PointNum = 0;
        ReleaseCapture();
    }

	//////////////////////////////////////////////////////// Hermite����
	 if (MenuID == 10)
    {
        for (int i = 0; i < pDoc->PointNum; i++)
        {//�������й�� 
            pDC.MoveTo(pDoc->group[i].x - 5, pDoc->group[i].y);
            pDC.LineTo(pDoc->group[i].x + 5, pDoc->group[i].y);
            pDC.MoveTo(pDoc->group[i].x, pDoc->group[i].y - 5);
            pDC.LineTo(pDoc->group[i].x, pDoc->group[i].y + 5);
        }
        pDoc->Hermite(&pDC, 0);//���� Hermite ���� 

        MenuID = 9; //������Ĳ����Ļ� Hermite ���߷�ʽ
        PressNum = 0;
        pDoc->PointNum = 0;
        ReleaseCapture();
    }

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2016302590184View::OnDrawDdaline()
{
	// TODO: �ڴ���������������
	PressNum = 0; MenuID = 1;
}

void CMy2016302590184View::OnDrawMidline()
{
	// TODO: �ڴ���������������
	PressNum = 0; MenuID = 2;
}

void CMy2016302590184View::OnDrawBcircle()
{
	// TODO: �ڴ���������������
	PressNum = 0; MenuID = 3;
}

void CMy2016302590184View::OnDrawPncircle()
{
	// TODO: �ڴ���������������
	PressNum = 0; MenuID = 4;
}

void CMy2016302590184View::OnCurveBezier()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
	pDoc->PointNum = 0; //��ʼ�� 
	PressNum = 0; MenuID = 5;
}

void CMy2016302590184View::OnCurveBsample()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
	pDoc->PointNum = 0; //��ʼ�� 
	PressNum = 0; MenuID = 7;
}

void CMy2016302590184View::OnCurveHermite()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
	pDoc->PointNum = 0; //��ʼ�� 
	PressNum = 0; MenuID = 9;
}

void CMy2016302590184View::OnDrawChar()
{
	// TODO: �ڴ���������������
	CDC* pDC = GetDC();
    CDrawCharDlg dlg;
    if (dlg.DoModal() == IDOK)
    {
        CFont* pfntOld = pDC->SelectObject(&dlg.m_fnt);      // ���������
        pDC->SetTextColor(dlg.m_clrText);                    // ������ɫ
        pDC->TextOut(dlg.m_nX, dlg.m_nY, dlg.m_strString);   // ������Ļ��
        pDC->SelectObject(pfntOld);                          // ��ԭ������
    }
    ReleaseDC(pDC);
}

void CMy2016302590184View::OnTransMove()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
	CClientDC pDC(this); 
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);//�����ĵ��ຯ������Ļ������ͼ�� 
	PressNum = 0; 
	MenuID = 11; 
}

void CMy2016302590184View::OnTransRotate()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
	CClientDC pDC(this); 
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);//�����ĵ��ຯ������Ļ������ͼ�� 
	PressNum = 0; MenuID = 12;
}

void CMy2016302590184View::OnTransZoom()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
	CClientDC pDC(this); 
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);//�����ĵ��ຯ������Ļ������ͼ�� 
	PressNum = 0; MenuID = 13;
}

void CMy2016302590184View::OnTransSymmetry()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ��
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDoc->GenerateGraph(&pDC);
    PressNum = 0; 
	MenuID = 15;
}

void CMy2016302590184View::OnFillSeed()
{
	// TODO: �ڴ���������������
	PressNum = 0; MenuID = 20;
}

void CMy2016302590184View::OnEdgeFill()
{
	// TODO: �ڴ���������������
	PressNum = 0; MenuID = 22;
}

void CMy2016302590184View::OnFillScanline()
{
	// TODO: �ڴ���������������
	 CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ�� 
    pDoc->PointNum = 0;//ʵ���ϲ���Ҫ�ñ�������Ϊ�˽����Ե���Ĳ��ֹ� 
                       //�ܣ����Ե��䱣��һ�� 
	PressNum = 0; 
	MenuID = 23;
}

void CMy2016302590184View::OnCutCs()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ��
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDoc->DrawWindow(&pDC);
	PressNum = 0; 
	MenuID = 24;
}

void CMy2016302590184View::OnCutPolygon()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ��
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDoc->DrawWindow(&pDC);
    PressNum = 0; 
	MenuID = 25;
}

void CMy2016302590184View::OnCutcircle()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ��
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDoc->DrawWindow(&pDC);
    PressNum = 0; MenuID = 33;

}

void CMy2016302590184View::OnCutLiang()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum = 0; MenuID = 34;
}

void CMy2016302590184View::OnCutMiddle()
{
	// TODO: �ڴ���������������
	CMy2016302590184Doc* pDoc = GetDocument(); //����ĵ���ָ��
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum = 0;  MenuID = 35;
}