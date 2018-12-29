
// 2016302590184View.cpp : CMy2016302590184View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CMy2016302590184View 构造/析构

CMy2016302590184View::CMy2016302590184View()
{
	// TODO: 在此处添加构造代码

}

CMy2016302590184View::~CMy2016302590184View()
{
}

BOOL CMy2016302590184View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2016302590184View 绘制

void CMy2016302590184View::OnDraw(CDC* /*pDC*/)
{
	CMy2016302590184Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2016302590184View 打印


void CMy2016302590184View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2016302590184View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2016302590184View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2016302590184View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CMy2016302590184View 诊断

#ifdef _DEBUG
void CMy2016302590184View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2016302590184View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2016302590184Doc* CMy2016302590184View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2016302590184Doc)));
	return (CMy2016302590184Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2016302590184View 消息处理程序
/**********************************************windows事件驱动机制**************************************************/
/*Windows 系统设置了许多事件，如按键盘，动鼠标，打开、关闭窗口等，在系统中， 它们用以 WM_开头的变量标识。Windows 系统
 *自动检测所有的这些事件，当某一事件发生 时，如按下鼠标左键，系统马上通知应用程序，应用程序有机会对事件做出反应。如何
 *反应， 需要编程实现。*********************************************************************************************/

void CMy2016302590184View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
    CClientDC ht(this); //定义当前绘图设备
   ////////////////////////////////////////////////////////////////////////// DDA 直线和中点画线法
	if ( MenuID == 1 || MenuID == 2 )
    { 
        if (PressNum == 0)
        {   //第一次按键将第一点保留在文档类数组中
            pDoc->group[PressNum] = point;
            PressNum++;    
			mPointOrign = point;
			mPointOld = point; // 记录第一点
			SetCapture(); 
        }
		/////////////////////////////////////////////////////////////////////////// DDA 直线
        else if (PressNum == 1 && MenuID == 1)
        {   //第二次按键保留第二点，用文档类画线
            pDoc->group[PressNum] = point;
            PressNum = 0;//程序画图 
            pDoc->DDALine(&ht);
            ReleaseCapture();
        }
		/////////////////////////////////////////////////////////////////////////// 中点画线法
		else if(PressNum == 1 && MenuID == 2)
		{
			pDoc->group[PressNum] = point;
            PressNum = 0;//程序画图 
            pDoc->MidLine(&ht);
            ReleaseCapture();
		}
	}

	////////////////////////////////////////////////////////////////////////////// Bresenham 圆 
	if (MenuID == 3 || MenuID == 4 || MenuID == 33)
	{ 
		if (PressNum == 0)
		{//第一次按键将第一点保留在 mPointOrign 
			pDoc->group[PressNum] = point;
			PressNum++;
			mPointOrign = point;
			mPointOld = point; //记录第一点 
			SetCapture();
		}
		else if (PressNum == 1 && MenuID == 3)
		{//第二次按键调用文档类画圆程序画图 
			pDoc->group[PressNum] = point;
			PressNum = 0;
			pDoc->BCircle(&ht, mPointOrign, point); ReleaseCapture();
		}
		else if (PressNum == 1 && MenuID == 4)
        {//第二次按键调用画圆程序画图
            PressNum = 0;
			pDoc->ZCircle(&ht, mPointOrign, point); ReleaseCapture();
        }
///////////////////////////////////////////////////////////////////////////////////////////// 圆裁剪
		else if(PressNum == 1 && MenuID == 33) 					
		{
			pDoc->group[PressNum] = point;
			PressNum = 0;
			pDoc->CircleCut(&ht);
			ReleaseCapture();
		}

	}
	///////////////////////////////////////////////////////////// Bezier 曲线  B样条曲线  Hermite曲线
	if(MenuID == 5 || MenuID == 7 || MenuID == 9)
	{ // 选点并做十字标志 
		pDoc->group[pDoc->PointNum++] = point; 
		ht.MoveTo(point.x-5,point.y); 
		ht.LineTo(point.x+5,point.y); 
		ht.MoveTo(point.x,point.y-5); 
		ht.LineTo(point.x,point.y+5); 
		SetCapture(); 
		PressNum = 1; 
	} 

	if(MenuID == 6 && PressNum == 0)
	{//  在控制点数组中，逐个寻找
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

	///////////////////////////////////////////////////////////////////////////////  平移 
	if(MenuID == 11) { 
    if(PressNum == 0){ 
	    PressNum++; 
        mPointOrign = point; 
        mPointOld = point; //记录第一点 
        SetCapture(); 
    } 
    else if(PressNum == 1)
	{	//根据两点间距计算平移量
        for(int i = 0; i<pDoc->PointNum;i++)//根据平移量计算新图形坐标
        {
            pDoc->group[i].x += point.x - mPointOrign.x; 
            pDoc->group[i].y += point.y-mPointOrign.y; 
        } 
        ht.MoveTo(mPointOrign);//擦除橡皮筋
        ht.LineTo(point); 
        pDoc->DrawGraph(&ht);//生成新图形 
        ReleaseCapture();
        PressNum = 0; 
	} }

	/////////////////////////////////////////////////////////////////////////////// 旋转
	if(MenuID == 12) 
	{ 
		if(PressNum == 0)
		{ 
			PressNum++; 
            mPointOrign = point; 
            mPointOld = point; // 记录第一点 
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
			pDoc->Rotate(r1, cpt, point); // 进行旋转变换
			pDoc->DrawGraph(&ht); // 生成新图形 
            ReleaseCapture();
            PressNum = 0; 
		}
	}

	///////////////////////////////////////////////////////////////////////////// 缩放
	if(MenuID == 13)
	{
		 if(PressNum == 0)
		 {
			 PressNum++; 
             mPointOrign = point; 
             mPointOld = point; //记录第一点
			 r1 = mPointOld;
             SetCapture(); 
         } 
         else if(PressNum == 1)
	     {	//根据两点间距计算缩放比例
			 float sx, sy, x, y;
			 sx = (-(double)r1.x + point.x)/100.0;
			 sy = (point.y - (double)r1.y)/100.0;   
			for(int i=0;i<pDoc->PointNum;i++) // 计算新图形坐标
			{
			   x = (pDoc->group[i].x - r1.x)*sx + r1.x;
		       y = (pDoc->group[i].y - r1.y)*sy + r1.y;
               pDoc->group[i].x = x;
			   pDoc->group[i].y = y; 
			}
             ht.MoveTo(mPointOrign);//擦除橡皮筋
             ht.LineTo(point); 
             pDoc->DrawGraph(&ht);//生成新图形 
             ReleaseCapture();
             PressNum = 0; 
		 }
	}

	///////////////////////////////////////////////////////////////////////// 对称变换 
	if(MenuID == 15) 
	{ 
    if(PressNum == 0){ 
        PressNum++; 
        mPointOrign = point; 
        mPointOld = point; // 记录第一点 
        SetCapture(); 
    } 
    else if(PressNum == 1){ 
        pDoc->Symmetry(mPointOrign, point); // 进行对称变换
        pDoc->DrawGraph(&ht); // 生成新图形 
        ReleaseCapture();
        PressNum = 0; 
	} }

	//////////////////////////////////////////////////////////////////// 种子填充:画边界
	if(MenuID == 20) { // 种子填充:画边界
    if(PressNum == 0){ 
        mPointOrign = point; mPointOld = point; 
        mPointOld1 = point; //记录第一点 
        PressNum++; 
        SetCapture();
    }
    else{ 
        ht.MoveTo(mPointOrign); // 擦除橡皮筋 
        ht.LineTo(point); 
        pDoc->group[0] = mPointOrign; // 借助 DDA 直线函数画边界 
		pDoc->group[1] = point; 
        pDoc->DDALine(&ht);
        mPointOrign = point; 
        mPointOld = point; 
        PressNum++; 
    } } 
	if(MenuID == 21) 
	{ // 确定种子点，填充 
		pDoc->SeedFill(&ht, point);
		PressNum = 0; 
		MenuID = 20;//设置决定顶点操作方式
	}

	////////////////////////////////////////////////////////// 边缘填充 扫描线填充 多边形裁剪
	if(MenuID == 22 || MenuID == 23 || MenuID == 25) 
	{ // 边缘填充选顶点 
		pDoc->group[PressNum++] = point; 
		pDoc->PointNum++; 
		mPointOrign = point; 
		mPointOld = point; 
		SetCapture(); 
	} 
	/////////////////////////////////////////////////////// Cohen-sutherland 裁剪算法 
	if(MenuID == 24) 
	{ // Cohen-sutherland 裁剪算法 
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
	/////////////////////////////////////////////////////////////// 梁友栋-Barsky算法
	if(MenuID == 34) { // liang裁剪算法 
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
	/////////////////////////////////////////////////////////////// middle 裁剪算法
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
    CClientDC ht(this); //定义当前绘图设备
    OnPrepareDC(&ht);
    ht.DPtoLP(&point);
	/////////////////////////////////////////////////////////////////////////////// Bezier 函数 
    /////////////////////////////////////////////////////////////////////////////// B 样条 曲线
	/////////////////////////////////////////////////////////////////////////////// Hermite曲线
	if (MenuID == 5 || MenuID == 7 || MenuID == 9 && pDoc->PointNum > 3)
	{
		if (MenuID == 5)
		{//绘制 Bezier 函数 
			pDoc->Bezier(&ht, 1);
			MenuID = 6; //将下面的操作改为修改控制点位置
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

	//////////////////////////////////////////////////////////////////////////////////// 种子填充 
	if(MenuID == 20 && PressNum > 0) 
	{ //  种子填充 
		ht.MoveTo(mPointOrign);//擦除橡皮筋
		ht.LineTo(point); 
		pDoc->group[0] = mPointOld1;//封闭多边形
		pDoc->group[1] = mPointOrign; 
		pDoc->DDALine(&ht);
		PressNum = 0; MenuID = 21;//改变操作方式为种子点选取
		ReleaseCapture(); 
	} 

	/////////////////////////////////////////////////////////////////////////////////// 边缘填充
	if( MenuID == 22 ) { // 边缘填充选点结束 
    pDoc->group[PressNum] = pDoc->group[0]; 
	pDoc->PointNum++; 
    ht.MoveTo(pDoc->group[PressNum-1]);
    ht.LineTo(pDoc->group[0]); 
    for(int i = 0; i < PressNum; i++) 
    ht.LineTo(pDoc->group[i+1]); 
	pDoc->EdgeFill(&ht);
    PressNum = 0; pDoc->PointNum=0;  ReleaseCapture(); 
} 
	////////////////////////////////////////////////////////////////////////////////// 扫描线填充
	if(MenuID == 23){ 
    pDoc->group[PressNum]=pDoc->group[0]; //封闭多边形
    ht.MoveTo(pDoc->group[PressNum-1]); //擦除
    ht.LineTo(pDoc->group[0]); 
    for(int i = 0; i < PressNum; i++) //擦除 
    ht.LineTo(pDoc->group[i+1]); 
	CPen pen(PS_SOLID,1, RGB(255,0,0));//设置多边形边界颜色（即画笔） 
    CPen* pOldPen = ht.SelectObject(&pen);
    CBrush brush(RGB(0,255,0));	//设置多边形填充颜色（即画刷）
    CBrush* pOldBrush = ht.SelectObject(&brush);
    ht.SetROP2(R2_COPYPEN);	//设置直接画方式
    ht.Polygon(pDoc->group,PressNum);//调用多边形扫描线填充函数 
    ht.SelectObject(pOldPen);//恢复系统的画笔、画刷颜色设置 
    ht.SelectObject(pOldBrush); 
    PressNum=0; pDoc->PointNum = 0;//初始化参数，为下一次操作做准备 
    ReleaseCapture(); 
} 

	//////////////////////////////////////////////////////////////////////////// 多边形裁剪 
	if(MenuID == 25) { 
    pDoc->group[PressNum]=pDoc->group[0];//将第一个顶点作为最后一个顶点 
    pDoc->PointNum=PressNum;	//记录顶点数量
    ht.MoveTo(pDoc->group[PressNum-1]); ht.LineTo(pDoc->group[0]); 
    pDoc->PolygonCut(&ht);
    PressNum=0;pDoc->PointNum = 0; 
    ReleaseCapture(); 
  }

	CView::OnRButtonDown(nFlags, point);
}


void CMy2016302590184View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
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
	pDC.SetROP2(R2_NOT); // 设置异或方式 
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
			pDC.LineTo(mPointOld); // 擦旧线 
			pDC.MoveTo(mPointOrign);   
			pDC.LineTo(point);     // 画新线 
			mPointOld = point; 
		} 
	}

	if (( MenuID == 3 || MenuID==4 || MenuID == 33 ) && PressNum == 1)
    {
        pDC.SelectStockObject(NULL_BRUSH);//画空心圆 
        if (mPointOld != point)
        {
            double r = (int)sqrt((double)(mPointOrign.x - mPointOld.x) * (mPointOrign.x - mPointOld.x) + (mPointOrign.y - mPointOld.y) * (mPointOrign.y - mPointOld.y));
			pDC.Ellipse(mPointOrign.x - r, mPointOrign.y - r, mPointOrign.x + r, mPointOrign.y + r);//擦旧圆 
            r = (int)sqrt((double)(mPointOrign.x - point.x) * (mPointOrign.x - point.x) + (mPointOrign.y - point.y) * (mPointOrign.y - point.y));
            pDC.Ellipse(mPointOrign.x - r, mPointOrign.y - r, mPointOrign.x + r, mPointOrign.y + r);//画新圆 
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
            pDoc->Bezier(&pDC,1);//擦除十字标志和旧线 
            pDC.MoveTo(point.x-5, point.y); 
            pDC.LineTo(point.x+5, point.y); 
            pDC.MoveTo(point.x, point.y-5); 
            pDC.LineTo(point.x, point.y+5); 
            pDoc->group[SaveNumber] = point; // 记录新控制点 
            pDoc->Bezier(&pDC,1); // 画十字标志和新曲线 
         } 
    }

	CView::OnMouseMove(nFlags, point);
}


void CMy2016302590184View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDC.DPtoLP(&point);
    pDC.SetROP2(R2_NOT); // 设置异或方式 
	/////////////////////////////////////////////////////// Beizer 曲线
    if (MenuID == 6)
    {
        for (int i = 0; i < pDoc->PointNum; i++)
        {//消除所有光标 
            pDC.MoveTo(pDoc->group[i].x - 5, pDoc->group[i].y);
            pDC.LineTo(pDoc->group[i].x + 5, pDoc->group[i].y);
            pDC.MoveTo(pDoc->group[i].x, pDoc->group[i].y - 5);
            pDC.LineTo(pDoc->group[i].x, pDoc->group[i].y + 5);
        }
        pDoc->Bezier(&pDC, 0);//绘制 Bezier 函数 

        MenuID = 5; //将下面的操作改回 Bezier 曲线方式
        PressNum = 0;
        pDoc->PointNum = 0;
        ReleaseCapture();
    }

	/////////////////////////////////////////////////////// B 样条 曲线
    if (MenuID == 8)
    {
        for (int i = 0; i < pDoc->PointNum; i++)
        {//消除所有光标 
            pDC.MoveTo(pDoc->group[i].x - 5, pDoc->group[i].y);
            pDC.LineTo(pDoc->group[i].x + 5, pDoc->group[i].y);
            pDC.MoveTo(pDoc->group[i].x, pDoc->group[i].y - 5);
            pDC.LineTo(pDoc->group[i].x, pDoc->group[i].y + 5);
        }
        pDoc->BSample(&pDC, 0);//绘制 B 样条 曲线

        MenuID = 7; //将下面的操作改回 B 样条 曲线方式
        PressNum = 0;
        pDoc->PointNum = 0;
        ReleaseCapture();
    }

	//////////////////////////////////////////////////////// Hermite曲线
	 if (MenuID == 10)
    {
        for (int i = 0; i < pDoc->PointNum; i++)
        {//消除所有光标 
            pDC.MoveTo(pDoc->group[i].x - 5, pDoc->group[i].y);
            pDC.LineTo(pDoc->group[i].x + 5, pDoc->group[i].y);
            pDC.MoveTo(pDoc->group[i].x, pDoc->group[i].y - 5);
            pDC.LineTo(pDoc->group[i].x, pDoc->group[i].y + 5);
        }
        pDoc->Hermite(&pDC, 0);//绘制 Hermite 曲线 

        MenuID = 9; //将下面的操作改回 Hermite 曲线方式
        PressNum = 0;
        pDoc->PointNum = 0;
        ReleaseCapture();
    }

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2016302590184View::OnDrawDdaline()
{
	// TODO: 在此添加命令处理程序代码
	PressNum = 0; MenuID = 1;
}

void CMy2016302590184View::OnDrawMidline()
{
	// TODO: 在此添加命令处理程序代码
	PressNum = 0; MenuID = 2;
}

void CMy2016302590184View::OnDrawBcircle()
{
	// TODO: 在此添加命令处理程序代码
	PressNum = 0; MenuID = 3;
}

void CMy2016302590184View::OnDrawPncircle()
{
	// TODO: 在此添加命令处理程序代码
	PressNum = 0; MenuID = 4;
}

void CMy2016302590184View::OnCurveBezier()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
	pDoc->PointNum = 0; //初始化 
	PressNum = 0; MenuID = 5;
}

void CMy2016302590184View::OnCurveBsample()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
	pDoc->PointNum = 0; //初始化 
	PressNum = 0; MenuID = 7;
}

void CMy2016302590184View::OnCurveHermite()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
	pDoc->PointNum = 0; //初始化 
	PressNum = 0; MenuID = 9;
}

void CMy2016302590184View::OnDrawChar()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
    CDrawCharDlg dlg;
    if (dlg.DoModal() == IDOK)
    {
        CFont* pfntOld = pDC->SelectObject(&dlg.m_fnt);      // 保存旧字体
        pDC->SetTextColor(dlg.m_clrText);                    // 设置颜色
        pDC->TextOut(dlg.m_nX, dlg.m_nY, dlg.m_strString);   // 画到屏幕上
        pDC->SelectObject(pfntOld);                          // 还原旧字体
    }
    ReleaseDC(pDC);
}

void CMy2016302590184View::OnTransMove()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
	CClientDC pDC(this); 
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);//调用文档类函数在屏幕上生成图形 
	PressNum = 0; 
	MenuID = 11; 
}

void CMy2016302590184View::OnTransRotate()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
	CClientDC pDC(this); 
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);//调用文档类函数在屏幕上生成图形 
	PressNum = 0; MenuID = 12;
}

void CMy2016302590184View::OnTransZoom()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
	CClientDC pDC(this); 
	OnPrepareDC(&pDC);
	pDoc->GenerateGraph(&pDC);//调用文档类函数在屏幕上生成图形 
	PressNum = 0; MenuID = 13;
}

void CMy2016302590184View::OnTransSymmetry()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDoc->GenerateGraph(&pDC);
    PressNum = 0; 
	MenuID = 15;
}

void CMy2016302590184View::OnFillSeed()
{
	// TODO: 在此添加命令处理程序代码
	PressNum = 0; MenuID = 20;
}

void CMy2016302590184View::OnEdgeFill()
{
	// TODO: 在此添加命令处理程序代码
	PressNum = 0; MenuID = 22;
}

void CMy2016302590184View::OnFillScanline()
{
	// TODO: 在此添加命令处理程序代码
	 CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针 
    pDoc->PointNum = 0;//实际上不需要该变量，但为了借鉴边缘填充的部分功 
                       //能，与边缘填充保持一致 
	PressNum = 0; 
	MenuID = 23;
}

void CMy2016302590184View::OnCutCs()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDoc->DrawWindow(&pDC);
	PressNum = 0; 
	MenuID = 24;
}

void CMy2016302590184View::OnCutPolygon()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDoc->DrawWindow(&pDC);
    PressNum = 0; 
	MenuID = 25;
}

void CMy2016302590184View::OnCutcircle()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针
    CClientDC pDC(this);
    OnPrepareDC(&pDC);
    pDoc->DrawWindow(&pDC);
    PressNum = 0; MenuID = 33;

}

void CMy2016302590184View::OnCutLiang()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum = 0; MenuID = 34;
}

void CMy2016302590184View::OnCutMiddle()
{
	// TODO: 在此添加命令处理程序代码
	CMy2016302590184Doc* pDoc = GetDocument(); //获得文档类指针
	CClientDC pDC(this);
	OnPrepareDC(&pDC);
	pDoc->DrawWindow(&pDC);
	PressNum = 0;  MenuID = 35;
}