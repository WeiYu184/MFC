
// 2016302590184Doc.cpp : CMy2016302590184Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2016302590184.h"
#endif

#include "2016302590184Doc.h"

#include <propkey.h>
#define XMIN 100 //定义的窗口参数符号，符号只要在被使用前定义即可 
#define XMAX 400 
#define YMIN 100 
#define YMAX 300 

#define LEFT 1 //定义的几个常数符号 
#define RIGHT 2 
#define BOTTOM 4 
#define TOP 8 


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy2016302590184Doc

IMPLEMENT_DYNCREATE(CMy2016302590184Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy2016302590184Doc, CDocument)
	ON_COMMAND(ID_GraphColor, &CMy2016302590184Doc::OnGraphcolor)
END_MESSAGE_MAP()


// CMy2016302590184Doc 构造/析构

CMy2016302590184Doc::CMy2016302590184Doc()
{
	// TODO: 在此添加一次性构造代码
	  m_crColor = RGB(0, 0, 0);
}

CMy2016302590184Doc::~CMy2016302590184Doc()
{
}

BOOL CMy2016302590184Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMy2016302590184Doc 序列化

void CMy2016302590184Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMy2016302590184Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMy2016302590184Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMy2016302590184Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy2016302590184Doc 诊断

#ifdef _DEBUG
void CMy2016302590184Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy2016302590184Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy2016302590184Doc 命令
void CMy2016302590184Doc::DDALine(CClientDC* DCPoint)
{
	int x, x0, y0, x1, y1, flag;
    float m, y;
    DCPoint->SetROP2(R2_COPYPEN); //绘图方法为直接画 
                                  //直线端点由鼠标确定后存放在 group[0]、group[1] 
    x0 = group[0].x; y0 = group[0].y;
    x1 = group[1].x; y1 = group[1].y;
    if (x0 == x1 && y0 == y1) return;
    if (x0 == x1)//垂直线 
    {
        if (y0 > y1)
        {
            x = y0; y0 = y1; y1 = x;
        }
        for (x = y0; x <= y1; x++)
        {
            DCPoint->SetPixel(x0, x, m_crColor);
        }
        return;
    }
    if (y0 == y1)//水平线 
    {
        if (x0 > x1)
        {
            x = x0; x0 = x1; x1 = x;
        }
        for (x = x0; x <= x1; x++)
        {
            DCPoint->SetPixel(x, y0, m_crColor);
        }
        return;
    }
    if (x0 > x1)
    {
        x = x0; x0 = x1; x1 = x;//交换起始、终止点 
		x = y0; y0 = y1; y1 = x; 
    }
    flag = 0;
    if (x1 - x0 > y1 - y0 && y1 - y0 > 0) flag = 1;
    if (x1 - x0 > y0 - y1 && y0 - y1 > 0)
    {
        flag = 2; y0 = -y0; y1 = -y1;
    }
    if (y1 - y0 > x1 - x0)
    {
        flag = 3; x = x0; x0 = y0; y0 = x; x = x1; x1 = y1; y1 = x;
    }
    if (y0 - y1 > x1 - x0)
    {
        flag = 4; x = x0; x0 = -y0; y0 = x; x = x1; x1 = -y1; y1 = x;
    }
    m = (float)(y1 - y0) / (float)(x1 - x0);
    for (x = x0, y = (float)y0; x <= x1; x++, y = y + m)
    {
        if (flag == 1) DCPoint->SetPixel(x, int(y),  m_crColor);
        if (flag == 2) DCPoint->SetPixel(x, -int(y),  m_crColor);
        if (flag == 3) DCPoint->SetPixel(int(y), x,  m_crColor);
        if (flag == 4) DCPoint->SetPixel(int(y), -x,  m_crColor);
    }
}

// 中点画线法
void CMy2016302590184Doc::MidLine(CClientDC* DCPoint)
{
	int x, y, x0, y0, x1, y1, flag;
	int a, b, delta1, delta2, d;
    DCPoint->SetROP2(R2_COPYPEN); //绘图方法为直接画 
    x0 = group[0].x; y0 = group[0].y;
    x1 = group[1].x; y1 = group[1].y;  //直线端点由鼠标确定后存放在 group[0]、group[1]
	a = y0 - y1; b = x1 - x0;
	x = x0; y = y0;
	int cx = (b >= 0 ? 1 : (b = -b, -1));  
    int cy = (a <= 0 ? 1 : (a = -a, -1));  
	if (a == 0 && b == 0) return;
	if ( b == 0 ) // 竖直线
	{
        if (y0 > y1) x = y0; y0 = y1; y1 = x;
        for ( x = y0; x <= y1; x++ ) DCPoint->SetPixel(x0, x, m_crColor);
        return;
    }
	if( a == 0 ) // 水平线
	 {
        if (x0 > x1)
        {
            x = x0; x0 = x1; x1 = x; 
        }
        for (x = x1; x <= x0; x++) DCPoint->SetPixel(x, y0, m_crColor);
        return;
    }
	if ( -a <= b )     // 斜率绝对值 <= 1  
    {  
        d = a + a + b;  
        delta1 = a + a;  
        delta2 =a + a + b + b;
        while(x != x1)  
        {  
            if (d < 0)  
                y += cy, d += delta2;  
            else  
                d += delta1;  
            x += cx;  
           DCPoint->SetPixel(x, y, m_crColor);
        }  
    }  
    else            // 斜率绝对值 > 1  
    {  
        d = b + b + a;   
        delta1 = b + b;  
        delta2 =  b + b + a + a;  
        while(y != y1)   
        {   
            if(d < 0)  
                d += delta1;   
            else   
                x += cx, d += delta2;   
            y += cy;   
            DCPoint->SetPixel(x, y, m_crColor);
        }   
    }  
}

void CMy2016302590184Doc::BCircle(CClientDC* DCPoint, CPoint p1, CPoint p2)
{/*
    int r, d, x, y, x0, y0;
    DCPoint->SetROP2(R2_COPYPEN); //绘图方法为直接画 
    r = (int)sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); x = 0; y = r; d = 3 - 2 * r; x0 = p1.x; y0 = p1.y;
    while (x < y || x == y)
    {
        DCPoint->SetPixel(x + x0, y + y0,  m_crColor);
        DCPoint->SetPixel(-x + x0, y + y0,  m_crColor);
        DCPoint->SetPixel(x + x0, -y + y0,  m_crColor);
        DCPoint->SetPixel(-x + x0, -y + y0,  m_crColor);
        DCPoint->SetPixel(y + x0, x + y0,  m_crColor);
        DCPoint->SetPixel(-y + x0, x + y0,  m_crColor);
        DCPoint->SetPixel(y + x0, -x + y0,  m_crColor);
        DCPoint->SetPixel(-y + x0, -x + y0,  m_crColor);
        x = x + 1;
        if (d < 0 || d == 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            y = y - 1; d = d + 4 * (x - y) + 10;
        }
    }*/
	CRect rc;
    bool a = DCPoint->GetBoundsRect(&rc, 0);
    BCircle(DCPoint, &rc, p1, p2);
}

void CMy2016302590184Doc::ZCircle(CClientDC* DCPoint, CPoint p1, CPoint p2)
{
    int r, d, x, y, x0, y0;
    DCPoint->SetROP2(R2_COPYPEN); //绘图方法为直接画 
    r = (int)sqrt((double)((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
    d = 0; x0 = p1.x; y0 = p1.y; x = x0; y = y0 + r;

    while (y > y0)
    {
        DCPoint->SetPixel(x, y, m_crColor);
        DCPoint->SetPixel(-x + 2 * x0, y,  m_crColor);
        DCPoint->SetPixel(x, -y + 2 * y0,  m_crColor);
        DCPoint->SetPixel(-x + 2 * x0, -y + 2 * y0,  m_crColor);
        if (d < 0)
        {
            x++; d = d + 2 * (x - x0) + 1;
        }
        else
        {
            y--; d = d - 2 * (y - y0) + 1;
        }
    }

}

void CMy2016302590184Doc::Bezier(CClientDC* pDC, int mode)
{
    CPoint p[1000];//设置一个数组存储完整的 Bezier 曲线控制点 
    int i, j;
    i = 0; j = 0;
    p[i++] = group[j++];//先将第 1，2 号点存入数组 
	p[i++] = group[j++]; 
    while (j <= PointNum - 2)//存入奇、偶号点，生成并存入插入点 
    {
        p[i++] = group[j++];
        p[i].x = (group[j].x + group[j - 1].x) / 2;
        p[i++].y = (group[j].y + group[j - 1].y) / 2;
        p[i++] = group[j++];
    };
    for (j = 0; j < i - 3; j += 3)//控制点分组，分别生成各段曲线 
        Bezier_4(pDC, mode, p[j], p[j + 1], p[j + 2], p[j + 3]);
}

void CMy2016302590184Doc::Bezier_4(CClientDC* pDC, int mode, CPoint p1, CPoint p2, CPoint p3, CPoint p4)
{
    int I, n;
    CPoint p;
    double t1, t2, t3, t4, dt;
    CPen pen;
    n = 10;
    if (mode)//mode=1时，以异或方式画可擦除的黑色曲线，用于调整形状
    {
        pDC->SetROP2(R2_NOT);
        pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    }
    else//mode=0 时，画红色的正式曲线 
    {
        pDC->SetROP2(R2_COPYPEN);
        pen.CreatePen(PS_SOLID, 1,  m_crColor);
    }
    CPen* pOldPen = pDC->SelectObject(&pen);
    dt = 1.0 / n;//参数 t 的间隔，分 10 段，即用 10 段直线表示一段曲线 
	pDC->MoveTo(p1);//移到起点 
    for (int i = 1; i <= n; i++)//用 Bezier 参数方程计算曲线上等间隔的 10 个点 
    {
        t1 = (1.0 - i * dt) * (1.0 - i * dt) * (1.0 - i * dt);  //计算(1-t)3
        t2 = i * dt * (1.0 - i * dt) * (1.0 - i * dt);  //计算 t (1-t) 2
        t3 = i * dt * i * dt * (1.0 - i * dt);  //计算 t2 (1-t)
        t4 = i * dt * i * dt * i * dt;  //计算 t3
        p.x = (int)(t1 * p1.x + 3 * t2 * p2.x + 3 * t3 * p3.x + t4 * p4.x);
        p.y = (int)(t1 * p1.y + 3 * t2 * p2.y + 3 * t3 * p3.y + t4 * p4.y); 
		pDC->LineTo(p);
    }
    pDC->SelectObject(pOldPen);
}

void CMy2016302590184Doc::BSample(CClientDC *pDC,int mode) 

{ 
	CPoint p[1000];//设置一个数组存储完整的 Bsample 曲线控制点 
	int i,j; 
	i=0;j=0; 
	p[i++]=group[j++];//先将第 1，2 号点存入数组 
	p[i++]=group[j++]; 
	while(j<=PointNum-2)//存入奇、偶号点，生成并存入插入点 
	{ 
		p[i++]=group[j++]; 
		p[i].x=(group[j].x+group[j-1].x)/2; 
		p[i++].y=(group[j].y+group[j-1].y)/2; 
		p[i++]=group[j++]; 
	}; 
	for(j=0;j<i-3;j++)//控制点分组，分别生成各段曲线 
		BSample_4(pDC,mode,p[j],p[j+1],p[j+2],p[j+3]); 
} 

void CMy2016302590184Doc::BSample_4(CClientDC *pDC,int mode,CPoint p1,CPoint p2,CPoint p3,CPoint p4) 
{ 
	int i,n; 
	CPoint p; 
	double t1,t2,t3,t4,dt; 
	CPen pen; 
	n=10;//参数 t 的间隔，分 10 段，即用 10 段直线表示一段曲线 
	if(mode)//mode=1 时，以异或方式画可擦除的黑色曲线，用于调整形状 
	{ 
		//pDC->SetROP2(R2_NOT); 
		pen.CreatePen(PS_SOLID,1,RGB(0,0,0)); 
	} 

	else//mode=0 时，画红色的正式曲线 
	{ 
		pDC->SetROP2(R2_COPYPEN); 
		pen.CreatePen(PS_SOLID,1, m_crColor); 
	} 
	CPen *pOldPen=pDC->SelectObject(&pen); 
	dt=1.0/n; 
	i=0; 
	t1=(1.0-i*dt)*(1.0-i*dt)*(1.0-i*dt)/6; //计算(1-t)3 
	t2=3*i*dt*(1.0-i*dt)*(1.0-i*dt)-3*i*dt+4; //计算 t (1-t) 2 
	t3=3*i*dt*i*dt*(1.0-i*dt)+3*i*dt+1; //计算 t2 (1-t) 
	t4=i*dt*i*dt*i*dt/6; //计算 t3 
	t3/=6; 
	t2/=6; 
	p.x=(int)(t1*p1.x+t2*p2.x+t3*p3.x+t4*p4.x); 
	p.y=(int)(t1*p1.y+t2*p2.y+t3*p3.y+t4*p4.y); 
	pDC->MoveTo(p);//移到起点 
	for(i=1;i<=n;i++)//用 Bsample 参数方程计算曲线上等间隔的 10 个点 
	{ 
		t1=(1.0-i*dt)*(1.0-i*dt)*(1.0-i*dt)/6; //计算(1-t)3 
		t2=3*i*dt*(1.0-i*dt)*(1.0-i*dt)-3*i*dt+4; //计算 t (1-t) 2 
		t3=3*i*dt*i*dt*(1.0-i*dt)+3*i*dt+1; //计算 t2 (1-t) 
		t4=i*dt*i*dt*i*dt/6; //计算 t3 
		t3/=6; 
		t2/=6; 
		p.x=(int)(t1*p1.x+t2*p2.x+t3*p3.x+t4*p4.x); 
		p.y=(int)(t1*p1.y+t2*p2.y+t3*p3.y+t4*p4.y); 
		pDC->LineTo(p); 
	} 
	pDC->SelectObject(pOldPen); 
} 

void CMy2016302590184Doc::Hermite(CClientDC* pDC, int mode)
{
	CPoint p[1000];//设置一个数组存储完整的 Bsample 曲线控制点 
	int i,j; 
	i=0;j=0; 
	p[i++]=group[j++];//先将第 1，2 号点存入数组 
	p[i++]=group[j++]; 
	while(j<=PointNum-2)//存入奇、偶号点，生成并存入插入点 
	{ 
		p[i++]=group[j++]; 
		p[i].x=(group[j].x+group[j-1].x)/2; 
		p[i++].y=(group[j].y+group[j-1].y)/2; 
		p[i++]=group[j++]; 
	}; 
	for(j=0;j<i-3;j++) Hermite_4(pDC,mode,p[j],p[j+1],p[j+2],p[j+3]);  //控制点分组，分别生成各段曲线 
}

void CMy2016302590184Doc::Hermite_4(CClientDC *pDC,int mode,CPoint p1,CPoint p2,CPoint p3,CPoint p4)
{
	int i,n; 
	CPoint p; 
	double a1,a2,a3,a4,dt; 
	CPen pen; 
	n=157;//参数 t 的间隔，分 10 段，即用 10 段直线表示一段曲线 
	if(mode)//mode=1 时，以异或方式画可擦除的黑色曲线，用于调整形状 
	{ 
		//pDC->SetROP2(R2_NOT); 
		pen.CreatePen(PS_SOLID,1,RGB(0,0,0)); 
	} 
	else//mode=0 时，画红色的正式曲线 
	{ 
		pDC->SetROP2(R2_COPYPEN); 
		pen.CreatePen(PS_SOLID,1,m_crColor); 
	} 
	CPen *pOldPen=pDC->SelectObject(&pen); 
	dt=1.0/n; 
	int k0x=(p2.x-p1.x);
	int k0y=p2.y-p1.y;
	int k1x=(p4.x-p3.x);
	int k1y=(p4.y-p3.y);
	pDC->MoveTo(p2);
	for (int i = 0; i < n; i++)
	{
		float t = i * 1.0f / n;
		float t2 = t * t;
		float t3 = t2 * t;

		a1 = (2 * t3 - 3 * t2 + 1);
		a2 = (-2 * t3 + 3 * t2);
		a3 = (t3 - 2 * t2 + t);
		a4 = (t3 - t2);
		p.x=(int)(a1*p2.x+a2*p3.x+a3*k0x+a4*k1x);
		p.y=(int)(a1*p2.y+a2*p3.y+a3*k0y+a4*k1y);
		pDC->LineTo(p);
	}
	pDC->SelectObject(pOldPen); 
}

void CMy2016302590184Doc::OnGraphcolor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg(m_crColor);//创建对话框对象，并让其默认颜色为
                                //上一次选择的颜色
    if (dlg.DoModal() == IDOK)
        m_crColor = dlg.GetColor();
}

void CMy2016302590184Doc::GenerateGraph(CClientDC* pDC)
{
    group[0].x = 100; group[0].y = 100;//图形数据准备 
	group[1].x = 200; group[1].y = 100; 
    group[2].x = 200; group[2].y = 200;
    group[3].x = 100; group[3].y = 200;
    group[4].x = 100; group[4].y = 100;
    PointNum = 5;
    DrawGraph(pDC);//画图形
}

void CMy2016302590184Doc::DrawGraph(CClientDC* pDC)
{
    int i;
    CPen pen,*pOldPen;
    pDC->SetROP2(R2_COPYPEN);
    pen.CreatePen(PS_SOLID, 1, m_crColor); 
	pOldPen = pDC->SelectObject(&pen);
    pDC->MoveTo(group[0]);
    for (i = 1; i < PointNum; i++)
        pDC->LineTo(group[i]);
    pDC->SelectObject(pOldPen);
}

void CMy2016302590184Doc::Symmetry(CPoint p1, CPoint p2)
{
    float a[3][3],b[3][3],c[3][3]; 
    float sa, ca, x, y;
    int i;
    ca=(p2.x-p1.x)/sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));//cosα 
    sa=(p2.y-p1.y)/sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)); //sinα 
    c[0][0]=1;c[0][1]=0;c[0][2]=-p1.x;//矩阵 1 
    c[1][0]=0;c[1][1]=1;c[1][2]=-p1.y; 
    c[2][0]=0;c[2][1]=0;c[2][2]=1; 
    b[0][0]=ca;b[0][1]=sa;b[0][2]=0; //矩阵 2 
    b[1][0]=-sa;b[1][1]=ca;b[1][2]=0; 
    b[2][0]=0;b[2][1]=0;b[2][2]=1; 
    a[0][0]=b[0][0]* c[0][0]+b[0][1]* c[1][0]+b[0][2]* c[2][0]; //矩阵 1、2 合并 
	a[0][1]=b[0][0]* c[0][1]+b[0][1]* c[1][1]+b[0][2]* c[2][1]; 
    a[0][2]=b[0][0]* c[0][2]+b[0][1]* c[1][2]+b[0][2]* c[2][2]; 
    a[1][0]=b[1][0]* c[0][0]+b[1][1]* c[1][0]+b[1][2]* c[2][0]; 
    a[1][1]=b[1][0]* c[0][1]+b[1][1]* c[1][1]+b[1][2]* c[2][1]; 
    a[1][2]=b[1][0]* c[0][2]+b[1][1]* c[1][2]+b[1][2]* c[2][2]; 
    a[2][0]=b[2][0]* c[0][0]+b[2][1]* c[1][0]+b[2][2]* c[2][0]; 
    a[2][1]=b[2][0]* c[0][1]+b[2][1]* c[1][1]+b[2][2]* c[2][1]; 
    a[2][2]=b[2][0]* c[0][2]+b[2][1]* c[1][2]+b[2][2]* c[2][2]; 
    b[0][0]=1;b[0][1]=0;b[0][2]=0; //矩阵 3 
    b[1][0]=0;b[1][1]=-1;b[1][2]=0; 
    b[2][0]=0;b[2][1]=0;b[2][2]=1; 
    c[0][0]=b[0][0]* a[0][0]+b[0][1]* a[1][0]+b[0][2]* a[2][0]; //矩阵 1、2、3 	合并 
    c[0][1]=b[0][0]* a[0][1]+b[0][1]* a[1][1]+b[0][2]* a[2][1]; 
    c[0][2]=b[0][0]* a[0][2]+b[0][1]* a[1][2]+b[0][2]* a[2][2]; 
    c[1][0]=b[1][0]* a[0][0]+b[1][1]* a[1][0]+b[1][2]* a[2][0]; 
    c[1][1]=b[1][0]* a[0][1]+b[1][1]* a[1][1]+b[1][2]* a[2][1]; 
 
    c[1][2]=b[1][0]* a[0][2]+b[1][1]* a[1][2]+b[1][2]* a[2][2]; 
	c[2][0]=b[2][0]* a[0][0]+b[2][1]* a[1][0]+b[2][2]* a[2][0]; 
	c[2][1]=b[2][0]* a[0][1]+b[2][1]* a[1][1]+b[2][2]* a[2][1]; 
	c[2][2]=b[2][0]* a[0][2]+b[2][1]* a[1][2]+b[2][2]* a[2][2]; 
	b[0][0]=ca;b[0][1]=-sa;b[0][2]=0; //矩阵 4 
    b[1][0]=sa;b[1][1]=ca;b[1][2]=0; 
    b[2][0]=0; b[2][1]=0; b[2][2]=1; 
    a[0][0]=b[0][0]* c[0][0]+b[0][1]* c[1][0]+b[0][2]* c[2][0]; //矩阵 1、2、3、4合并 
    a[0][1]=b[0][0]* c[0][1]+b[0][1]* c[1][1]+b[0][2]* c[2][1]; 
    a[0][2]=b[0][0]* c[0][2]+b[0][1]* c[1][2]+b[0][2]* c[2][2]; 
    a[1][0]=b[1][0]* c[0][0]+b[1][1]* c[1][0]+b[1][2]* c[2][0]; 
    a[1][1]=b[1][0]* c[0][1]+b[1][1]* c[1][1]+b[1][2]* c[2][1]; 
    a[1][2]=b[1][0]* c[0][2]+b[1][1]* c[1][2]+b[1][2]* c[2][2]; 
    a[2][0]=b[2][0]* c[0][0]+b[2][1]* c[1][0]+b[2][2]* c[2][0]; 
    a[2][1]=b[2][0]* c[0][1]+b[2][1]* c[1][1]+b[2][2]* c[2][1]; 
    a[2][2]=b[2][0]* c[0][2]+b[2][1]* c[1][2]+b[2][2]* c[2][2]; 
    b[0][0]=1;b[0][1]=0;b[0][2]=p1.x; //矩阵 5 
    b[1][0]=0;b[1][1]=1;b[1][2]=p1.y; 
    b[2][0]=0;b[2][1]=0;b[2][2]=1; 
    c[0][0]=b[0][0]* a[0][0]+b[0][1]* a[1][0]+b[0][2]* a[2][0];//所有矩阵合并 
    c[0][1]=b[0][0]* a[0][1]+b[0][1]* a[1][1]+b[0][2]* a[2][1]; 
    c[0][2]=b[0][0]* a[0][2]+b[0][1]* a[1][2]+b[0][2]* a[2][2]; 
    c[1][0]=b[1][0]* a[0][0]+b[1][1]* a[1][0]+b[1][2]* a[2][0]; 
    c[1][1]=b[1][0]* a[0][1]+b[1][1]* a[1][1]+b[1][2]* a[2][1]; 
    c[1][2]=b[1][0]* a[0][2]+b[1][1]* a[1][2]+b[1][2]* a[2][2]; 
    c[2][0]=b[2][0]* a[0][0]+b[2][1]* a[1][0]+b[2][2]* a[2][0]; 
    c[2][1]=b[2][0]* a[0][1]+b[2][1]* a[1][1]+b[2][2]* a[2][1]; 
    c[2][2]=b[2][0]* a[0][2]+b[2][1]* a[1][2]+b[2][2]* a[2][2]; 
    for(i=0;i<PointNum;i++) //利用复合矩阵对所有图形点坐标进行变换 
    { 
        x=c[0][0]* group[i].x+c[0][1]* group[i].y+c[0][2]; 
		y=c[1][0]* group[i].x+c[1][1]* group[i].y+c[1][2]; 
        group[i].x=x; 
		group[i].y=y; 
    } 
} 

void CMy2016302590184Doc::Rotate(CPoint mPointOrign, CPoint cpt, CPoint p)
{
    float sa, ca, x0, y0, a, b, c, x1, y1, x2, y2, x3, y3;
    int i;
	x1 = mPointOrign.x; y1 = mPointOrign.y; x2 = cpt.x; y2 = cpt.y; x3 = p.x; y3 = p.y; 
	a = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	b = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	ca = (c*c+b*b-a*a)/(2*c*b);
	sa = sin(acos(ca));
	PointNum = 5;
	for(i=0;i<PointNum;i++) 
    { 
		x0 = (group[i].x-x2)*ca - (group[i].y-y2)*sa + x2;
		y0 = (group[i].x-x2)*sa + (group[i].y-y2)*ca + y2;
        group[i].x = x0; 
		group[i].y = y0; 
    } 
}

void CMy2016302590184Doc::SeedFill(CClientDC* pDC, CPoint seedpoint)
{
    int savex, xleft, xright, pflag, x, y, num; 
	CPoint stack_ptr[200];//堆栈 
    pDC->SetROP2(R2_COPYPEN); //绘图方法为直接画 
    num = 0; //num 为堆栈中的种子数 
    stack_ptr[num++] = seedpoint;
    while (num > 0)
    {
        x = stack_ptr[--num].x; y = stack_ptr[num].y;
        pDC->SetPixel(x, y, m_crColor);
        savex = x; x++;
        while (pDC->GetPixel(x, y) != m_crColor)//向右填充，直到边界
        {
            pDC->SetPixel(x++, y, m_crColor);
        }
        xright = x - 1; x = savex - 1;
        while (pDC->GetPixel(x, y) != m_crColor)//向左填充，直到边界
        {
            pDC->SetPixel(x--, y, m_crColor);
        }
        xleft = x + 1; x = xleft; y++;//在扫描线下一行搜索未填充区域
        pflag = 1;
        while (x < xright)
        {
            if (pDC->GetPixel(x, y) != m_crColor && pflag == 1)
            {//边界后的第一个未填充区域像素 
                stack_ptr[num].x = x; stack_ptr[num++].y = y; x++;
            }
            if (pDC->GetPixel(x, y) == m_crColor)
                pflag = 1;//pflag=1 表示填充区域或边界 
            else
                pflag = 0;//pflag=0 表示未填充区域 
            x++;
        }
        x = xleft; y -= 2; pflag = 1;//在扫描线上一行搜索未填充区域
        while (x < xright)
        {
            if (pDC->GetPixel(x, y) != m_crColor && pflag == 1)
            {
                stack_ptr[num].x = x; stack_ptr[num++].y = y; x++;
            }
            if (pDC->GetPixel(x, y) == m_crColor)
                pflag = 1;
            else
                pflag = 0;
            x++;
        }
    }
}

void CMy2016302590184Doc::EdgeFill(CClientDC* pDC)
{
    int i, xr, x1, y1, x2, y2, y;
    float m, x;
    CPen pen;
    pen.CreatePen(PS_SOLID, 1, m_crColor);
    pDC->SetROP2(R2_XORPEN); //绘图方法为异或 
    CPen* pOldPen = pDC->SelectObject(&pen);
    xr = 0;
    for (i = 0; i < PointNum; i++)//找出边界盒右边界参数
    {
        if (xr < group[i].x) xr = group[i].x;
    }
    for (i = 0; i < PointNum - 1; i++)
    {
        x1 = group[i].x; x2 = group[i + 1].x;//取一条边
        y1 = group[i].y; y2 = group[i + 1].y;
        if (y1 != y2)
        {
            if (y1 > y2)//确保（x1,y1）为下端点
            {
                y = y1; y1 = y2; y2 = y;
                y = x1; x1 = x2; x2 = y;
            }
            m = (float)(x2 - x1) / (float)(y2 - y1); x = x1;//m为相邻扫描线之间边的 x 增量 
            for (y = y1 + 1; y <= y2; y++)
            {
                x += m;//确定边缘点 
                pDC->MoveTo((int)x, y);//从边缘点一直画到边界盒右端 
                pDC->LineTo(xr, y);
            }
        }
    }
    pDC->SelectObject(pOldPen);
}

void CMy2016302590184Doc::DrawWindow(CClientDC* pDC)
{
    CPen pen;
    pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    CPen* pOldPen = pDC->SelectObject(&pen); pDC->SetROP2(R2_COPYPEN);
    pDC->MoveTo(XMIN, YMIN);
    pDC->LineTo(XMAX, YMIN);
    pDC->LineTo(XMAX, YMAX);
    pDC->LineTo(XMIN, YMAX);
    pDC->LineTo(XMIN, YMIN);
    pDC->SelectObject(pOldPen);
}

void CMy2016302590184Doc::CohenSutherland(CClientDC* pDC, CPoint p1, CPoint p2)
{
    int code1, code2, code, x, y, x1, y1, x2, y2;
    pDC->SetROP2(R2_COPYPEN);
    CPen Pen;
    Pen.CreatePen(PS_SOLID, 2, m_crColor);
    CPen* OldPen = pDC->SelectObject(&Pen);
    x1 = p1.x; y1 = p1.y;
    x2 = p2.x; y2 = p2.y;
    code1 = encode(x1, y1); // 对端点编码 
	code2 = encode(x2, y2); 
    while (code1 != 0 || code2 != 0)
    {
        if ((code1 & code2) != 0) return; //完全不可见 
        code = code1;
        if (code1 == 0)
            code = code2;
        if ((LEFT & code) != 0)//求线段与窗口左边的交点
        {
            x = XMIN;
            y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
        }
        else if ((RIGHT & code) != 0) //求线段与窗口右边的交点
        {
            x = XMAX;
            y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
        }
        else if ((BOTTOM & code) != 0) //求线段与窗口底边的交点
        {
            y = YMIN;
            x = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
        }
        else if ((TOP & code) != 0) //求线段与窗口顶边的交点 
        {
            y = YMAX;
            x = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
        }
        if (code == code1)
        {
            x1 = x; y1 = y; code1 = encode(x, y);
        }
        else
        {
            x2 = x; y2 = y; code2 = encode(x, y);
        }
    }
    pDC->MoveTo(x1, y1);
    pDC->LineTo(x2, y2);
    pDC->SelectObject(OldPen);
}

int CMy2016302590184Doc::encode(int x, int y)
{
    int c;
    c = 0;
    if (x < XMIN) c = c + LEFT;
    else if (x > XMAX) c = c + RIGHT;
    if (y < YMIN) c = c + BOTTOM;
    else if (y > YMAX) c = c + TOP;
    return c;
}

void CMy2016302590184Doc::PolygonCut(CClientDC* pDC)
{
    CPen pen;
    pen.CreatePen(0, 2, RGB(255, 0, 0));
    CPen* OldPen = pDC->SelectObject(&pen); pDC->SetROP2(R2_COPYPEN);
    EdgeClipping(0);    //用第一条窗口边进行裁剪
    EdgeClipping(1);    //用第二条窗口边进行裁剪
    EdgeClipping(2);    //用第三条窗口边进行裁剪
    EdgeClipping(3);    //用第四条窗口边进行裁剪

    pDC->MoveTo(group[0]); //    绘制裁剪多边形 
	for(int i=1;i<=PointNum;i++) 
    pDC->LineTo(group[i]);
    pDC->SelectObject(OldPen);
}

void CMy2016302590184Doc::EdgeClipping(int linecode)
{
    float x, y;
    int n, i, number1;
    CPoint q[200];
    number1 = 0;
    if (linecode == 0)// x=XMIN 
    {
        for (n = 0; n < PointNum; n++)
        {
            if (group[n].x < XMIN && group[n + 1].x < XMIN)//外外，不输出 
            {
            }
            if (group[n].x >= XMIN && group[n + 1].x >= XMIN)//里里，输出后点 
            {
                q[number1++] = group[n + 1];
            }
            if (group[n].x >= XMIN && group[n + 1].x < XMIN)//里外，输出交点 
            {
                y = group[n].y + (float)(group[n + 1].y - group[n].y) / (float)(group[n + 1].x - group[n].x) * (float)(XMIN - group[n].x); 
				q[number1].x = XMIN;
                q[number1++].y = (int)y;
            }
            if (group[n].x < XMIN && group[n + 1].x >= XMIN)//外里，输出交点、后点 
            {
                y = group[n].y + (float)(group[n + 1].y - group[n].y) / (float)(group[n + 1].x - group[n].x) * (float)(XMIN - group[n].x); 
				q[number1].x = XMIN;
                q[number1++].y = (int)y;
                q[number1++] = group[n + 1];
            }
        }
        for (i = 0; i < number1; i++) group[i] = q[i];
        group[number1] = q[0];
        PointNum = number1; number1 = 0;
    }

    if (linecode == 1) //y=YMAX 
    {
        for (n = 0; n < PointNum; n++)
        {
            if (group[n].y >= YMAX && group[n + 1].y >= YMAX)//外外，不输出
            {
            }
            if (group[n].y < YMAX && group[n + 1].y < YMAX)//里里，输出后点
            {
                q[number1++] = group[n + 1];
            }
            if (group[n].y < YMAX && group[n + 1].y >= YMAX)//里外，输出交点
            {
                x = group[n].x + (float)(group[n + 1].x - group[n].x) / (float)(group[n + 1].y - group[n].y) * (float)(YMAX - group[n].y);
                q[number1].x = (int)x;
                q[number1++].y = YMAX;
            }
            if (group[n].y >= YMAX && group[n + 1].y < YMAX)//外里，输出交点、后点
            {
                x = group[n].x + (float)(group[n + 1].x - group[n].x) / (float)(group[n + 1].y - group[n].y) * (float)(YMAX - group[n].y); 
				q[number1].x = (int)x;
                q[number1++].y = YMAX;
                q[number1++] = group[n + 1];
            }
        }
        for (i = 0; i < number1; i++)
        {
            group[i] = q[i];
        }
        group[number1] = q[0];
        PointNum = number1; 
		number1 = 0;
    }

    if (linecode == 2)//x=XMAX 
    {
        for (n = 0; n < PointNum; n++)
        {
            if (group[n].x >= XMAX && group[n + 1].x >= XMAX)//外外，不输出 
            {
            }
            if (group[n].x < XMAX && group[n + 1].x < XMAX)//里里，输出后点 
            {
                q[number1++] = group[n + 1];
            }
            if (group[n].x < XMAX && group[n + 1].x >= XMAX)//里外，输出交点 
            {
                y = group[n].y + (float)(group[n + 1].y - group[n].y) / (float)(group[n + 1].x - group[n].x) * (float)(XMAX - group[n].x); 
				q[number1].x = XMAX;
                q[number1++].y = (int)y;
            }
            if (group[n].x >= XMAX && group[n + 1].x < XMAX)//外里，输出交点、后点 
            {
                y = group[n].y + (float)(group[n + 1].y - group[n].y) / (float)(group[n + 1].x - group[n].x) * (float)(XMAX - group[n].x); 
				q[number1].x = XMAX;
                q[number1++].y = (int)y;
                q[number1++] = group[n + 1];
            }
        }
        for (i = 0; i < number1; i++)
        {
            group[i] = q[i];
        }
        group[number1] = q[0];
        PointNum = number1; 
		number1 = 0;
    }

    if (linecode == 3)// y=YMIN 
    {
        for (int n = 0; n < PointNum; n++)
        {
            if (group[n].y < YMIN && group[n + 1].y < YMIN)//外外，不输出 
            {
            }
            if (group[n].y >= YMIN && group[n + 1].y >= YMIN)//里里，输出后点 
            {
                q[number1++] = group[n + 1];
            }
            if (group[n].y >= YMIN && group[n + 1].y < YMIN)//里外，输出交点 
            {
                x = group[n].x + (float)(group[n + 1].x - group[n].x) / (float)(group[n + 1].y - group[n].y) * (float)(YMIN - group[n].y); 
				q[number1].x = (int)x;
                q[number1++].y = YMIN;
            }
            if (group[n].y < YMIN && group[n + 1].y >= YMIN)//外里，输出交点、后点 
            {
                x = group[n].x + (float)(group[n + 1].x - group[n].x) / (float)(group[n + 1].y - group[n].y) * (float)(YMIN - group[n].y); 
				q[number1].x = (int)x;
                q[number1++].y = YMIN;
                q[number1++] = group[n + 1];
            }
        }
        for (i = 0; i < number1; i++) group[i] = q[i];
        group[number1] = q[0];
        PointNum = number1; 
		number1 = 0;
    }
}

void CMy2016302590184Doc::BCircle(CClientDC* DCPoint, CRect* rc, CPoint p1, CPoint p2)
{
    int r, d, x, y, x0, y0;
    DCPoint->SetROP2(R2_COPYPEN); //绘图方法为直接画 
    r = (int)sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    x = 0; y = r; d = 3 - 2 * r; x0 = p1.x; y0 = p1.y;
    while (x < y || x == y)
    {
        if (rc->PtInRect(CPoint(x + x0, y + y0)))   //判断点是否在矩形框内
            DCPoint->SetPixel(x + x0, y + y0, m_crColor);
        if (rc->PtInRect(CPoint(-x + x0, y + y0)))
            DCPoint->SetPixel(-x + x0, y + y0, m_crColor);
        if (rc->PtInRect(CPoint(x + x0, -y + y0)))
            DCPoint->SetPixel(x + x0, -y + y0, m_crColor);
        if (rc->PtInRect(CPoint(-x + x0, -y + y0)))
            DCPoint->SetPixel(-x + x0, -y + y0, m_crColor);
        if (rc->PtInRect(CPoint(y + x0, x + y0)))
            DCPoint->SetPixel(y + x0, x + y0, m_crColor);
        if (rc->PtInRect(CPoint(-y + x0, x + y0)))
            DCPoint->SetPixel(-y + x0, x + y0, m_crColor);
        if (rc->PtInRect(CPoint(y + x0, -x + y0)))
            DCPoint->SetPixel(y + x0, -x + y0, m_crColor);
        if (rc->PtInRect(CPoint(-y + x0, -x + y0)))
            DCPoint->SetPixel(-y + x0, -x + y0, m_crColor);

        x = x + 1;
        if (d < 0 || d == 0) d = d + 4 * x + 6;
        else
        {
            y = y - 1; d = d + 4 * (x - y) + 10;
        }
    }
}

void CMy2016302590184Doc::CircleCut(CClientDC* DCPoint)
{
	//CClientDC* DCPoint, CRect* rc, CPoint p1, CPoint p2
    CRect rc(XMIN, YMIN, XMAX, YMAX);
	BCircle(DCPoint, &rc, group[0], group[1]);
}

void CMy2016302590184Doc::Liang(CClientDC* pDC, CPoint p1, CPoint p2)
{
	float XA, XB, XC, YC, XD, YD, x1, y1, x2, y2, xL, xR, xB, xT, k;
	pDC->SetROP2(R2_COPYPEN);
	CPen Pen;
	Pen.CreatePen(PS_SOLID, 2, m_crColor);
	CPen* OldPen = pDC->SelectObject(&Pen);
	x1 = p1.x; y1 = p1.y;
	x2 = p2.x; y2 = p2.y;
	k = (y2 - y1)/(x2 - x1);
	xL = XMIN;
	xR = XMAX;
	xB = x1 + (YMIN - y1) / k;
	xT = x1 + (YMAX - y1) / k;
	XA = max(xL, min(x1, x2));
	XB = min(xR, max(x1, x2));
	XC = max(XA, min(xB, xT));
	XD = min(XB, max(xB, xT));
	YC = y1 + k * (XC - x1);
	YD = y1 + k * (XD - x1);
	if (XA <= XB && XC <= XD)
	{
		pDC->MoveTo(XC, YC);
		pDC->LineTo(XD, YD);
		pDC->SelectObject(OldPen);
	} 
}

void CMy2016302590184Doc::MiddleCut(CClientDC* pDC,CPoint p1,CPoint p2)
{
	int code1, code2, code, x, y, x1, y1, x2, y2;
	pDC->SetROP2(R2_COPYPEN);
	CPen Pen;
	Pen.CreatePen(PS_SOLID, 2, m_crColor);
	CPen* OldPen = pDC->SelectObject(&Pen);
	x1 = p1.x; y1 = p1.y;
	x2 = p2.x; y2 = p2.y;
	code1 = encode(x1, y1);//对端点编码 
	code2 = encode(x2, y2);
	if(code1 == 0 && code2 == 0){//完全可见
		pDC->MoveTo(p1);
		pDC->LineTo(p2);
		pDC->SelectObject(OldPen);
	}
	else if((code1&code2) != 0) return;     //完全不可见
	else if(x1 - x2 > -2 && x1 - x2 < 2 && y1 - y2 > -2 && y1 - y2 < 2) return;
	else{
		x=(x1+x2)/2;y=(y1+y2)/2;
		CPoint mp;
		mp.x=x;mp.y=y;
		MiddleCut(pDC, p1, mp);
		MiddleCut(pDC, p2, mp);
	}
}

