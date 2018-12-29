
// ͼ�λ�����View.cpp : Cͼ�λ�����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ͼ�λ�����.h"
#endif

#include "ͼ�λ�����Doc.h"
#include "ͼ�λ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cͼ�λ�����View

IMPLEMENT_DYNCREATE(Cͼ�λ�����View, CView)

BEGIN_MESSAGE_MAP(Cͼ�λ�����View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cͼ�λ�����View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cͼ�λ�����View ����/����

Cͼ�λ�����View::Cͼ�λ�����View()
{
	// TODO: �ڴ˴���ӹ������

}

Cͼ�λ�����View::~Cͼ�λ�����View()
{
}

BOOL Cͼ�λ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cͼ�λ�����View ����

void Cͼ�λ�����View::OnDraw(CDC* /*pDC*/)
{
	Cͼ�λ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cͼ�λ�����View ��ӡ


void Cͼ�λ�����View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cͼ�λ�����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cͼ�λ�����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cͼ�λ�����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void Cͼ�λ�����View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cͼ�λ�����View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cͼ�λ�����View ���

#ifdef _DEBUG
void Cͼ�λ�����View::AssertValid() const
{
	CView::AssertValid();
}

void Cͼ�λ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cͼ�λ�����Doc* Cͼ�λ�����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cͼ�λ�����Doc)));
	return (Cͼ�λ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// Cͼ�λ�����View ��Ϣ�������
