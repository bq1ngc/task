
// DrawingView.cpp : CDrawingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"
#include "DrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "Shape.h"
#include "Type.h"
// CDrawingView

IMPLEMENT_DYNCREATE(CDrawingView, CScrollView)

BEGIN_MESSAGE_MAP(CDrawingView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()

// CDrawingView 构造/析构

CDrawingView::CDrawingView()
{
	// TODO: 在此处添加构造代码

}

CDrawingView::~CDrawingView()
{
}

BOOL CDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CDrawingView 绘制

void CDrawingView::OnDraw(CDC* pDC)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		CShape* p = (CShape*)pDoc->m_Elements[i];
	
		if (p != nullptr)
			p->Draw(pDC);
	}

}

void CDrawingView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CDrawingView 打印


void CDrawingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDrawingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//ClientToScreen(&point);
	//OnContextMenu(this, point);
}

void CDrawingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawingView 诊断

#ifdef _DEBUG
void CDrawingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDrawingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDrawingDoc* CDrawingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingDoc)));
	return (CDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingView 消息处理程序


void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)	return;

	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);//DP->LP进行转换

	CType dlg;
	dlg.m_OrgX = pntLogical.x;
	dlg.m_OrgY = pntLogical.y;
	CShape* p=NULL;

	if ((nFlags&MK_CONTROL) == MK_CONTROL)//Ctrl键按下
	{
		if(dlg.DoModal()==IDOK)
		{
			int index = ((CDrawingApp *)AfxGetApp())->m_index;
			switch (index)
			{
			case 0:
				p = new CSquare(dlg.m_OrgX, dlg.m_OrgY, dlg.m_Width);
				p->SetBase(SQUARE, dlg.color_Line, dlg.m_intListType, dlg.m_LineWidt, dlg.color_Fill, dlg.m_intFillType);
				pDoc->m_Elements.Add(p);
				pDoc->SetModifiedFlag();
				pDoc->UpdateAllViews(NULL);
				break;
			case 1:
				p = new CRectangle(dlg.m_OrgX, dlg.m_OrgY, dlg.m_Width, dlg.m_Height);
				p->SetBase(RECTANGLE, dlg.color_Line, dlg.m_intListType, dlg.m_LineWidt, dlg.color_Fill, dlg.m_intFillType);
				pDoc->m_Elements.Add(p);
				pDoc->SetModifiedFlag();
				pDoc->UpdateAllViews(NULL);
				break;
			case 2:
				p = new CTriangle(dlg.m_OrgX, dlg.m_OrgY, dlg.m_Width, dlg.m_Height);
				p->SetBase(TRIANGLE, dlg.color_Line, dlg.m_intListType, dlg.m_LineWidt, dlg.color_Fill, dlg.m_intFillType);
				pDoc->m_Elements.Add(p);
				pDoc->SetModifiedFlag();
				pDoc->UpdateAllViews(NULL);
				break;
			case 3:
				p = new CCircle(dlg.m_OrgX, dlg.m_OrgY, dlg.m_Width);
				p->SetBase(CIRCLE, dlg.color_Line, dlg.m_intListType, dlg.m_LineWidt, dlg.color_Fill, dlg.m_intFillType);
				pDoc->m_Elements.Add(p);
				pDoc->SetModifiedFlag();
				pDoc->UpdateAllViews(NULL);
				break;
			case 4:
				p = new CEllipse(dlg.m_OrgX, dlg.m_OrgY, dlg.m_Width, dlg.m_Height);
				p->SetBase(ELLIPSE, dlg.color_Line, dlg.m_intListType, dlg.m_LineWidt, dlg.color_Fill, dlg.m_intFillType);
				pDoc->m_Elements.Add(p);
				pDoc->SetModifiedFlag();
				pDoc->UpdateAllViews(NULL);
				break;
			case 5:
				p = new CText(dlg.m_OrgX, dlg.m_OrgY, dlg.m_Width,dlg.m_Height, dlg.m_Angle);
				p->SetBase(TEXT, dlg.color_Line, dlg.m_intListType, dlg.m_LineWidt, dlg.color_Fill, dlg.m_intFillType);
				pDoc->m_Elements.Add(p);
				pDoc->SetModifiedFlag();
				pDoc->UpdateAllViews(NULL);
				break;
			}
		}
	}
	else
	{
		for ( int i = 0; i < pDoc->m_Elements.GetCount(); i++)
		{
			p = (CShape*)pDoc->m_Elements[i];
			if (p != nullptr && p->IsMatched(pntLogical))
			{
				((CDrawingApp *)AfxGetApp())->m_index = p->GetDate();
				if (dlg.DoModal() == IDOK) {
					p->SetBase(p->GetDate(), dlg.color_Line, dlg.m_intListType, dlg.m_LineWidt, dlg.color_Fill, dlg.m_intFillType);
					p->SetDate(dlg.m_OrgX, dlg.m_OrgY, dlg.m_Width, dlg.m_Height, dlg.m_Angle);
					pDoc->SetModifiedFlag();
					pDoc->UpdateAllViews(NULL);
				}
			}
		}
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL);
	}

	CScrollView::OnLButtonDown(nFlags, point);
}


void CDrawingView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc* pDoc = GetDocument();
	int i;
	CShape* p;
	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);//DP->LP进行转换
	for (i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		p = (CShape*)pDoc->m_Elements[i];
		if (p!=nullptr && p->IsMatched(pntLogical))
		{
			pDoc->m_Elements[i] = nullptr;
		}
	}
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllViews(NULL);

	CScrollView::OnRButtonDblClk(nFlags, point);
}
