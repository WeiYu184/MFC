
// 图形绘制类View.cpp : C图形绘制类View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "图形绘制类.h"
#endif

#include "图形绘制类Doc.h"
#include "图形绘制类View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C图形绘制类View

IMPLEMENT_DYNCREATE(C图形绘制类View, CView)

BEGIN_MESSAGE_MAP(C图形绘制类View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C图形绘制类View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C图形绘制类View 构造/析构

C图形绘制类View::C图形绘制类View()
{
	// TODO: 在此处添加构造代码

}

C图形绘制类View::~C图形绘制类View()
{
}

BOOL C图形绘制类View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C图形绘制类View 绘制

void C图形绘制类View::OnDraw(CDC* /*pDC*/)
{
	C图形绘制类Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C图形绘制类View 打印


void C图形绘制类View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C图形绘制类View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C图形绘制类View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C图形绘制类View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C图形绘制类View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C图形绘制类View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C图形绘制类View 诊断

#ifdef _DEBUG
void C图形绘制类View::AssertValid() const
{
	CView::AssertValid();
}

void C图形绘制类View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C图形绘制类Doc* C图形绘制类View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C图形绘制类Doc)));
	return (C图形绘制类Doc*)m_pDocument;
}
#endif //_DEBUG


// C图形绘制类View 消息处理程序
