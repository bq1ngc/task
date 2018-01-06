// Shape.cpp : 实现文件
//

#include "stdafx.h"
#include "Drawing.h"
#include "Shape.h"
#include "Math.h"


CShape::CShape()
{
}
CShape::~CShape()
{
}
//正方形
IMPLEMENT_SERIAL(CSquare, CObject, 1)//实现类CSquare的序列化指定版本为1
void CSquare::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
	}
}

CSquare::CSquare()
{
	OrgX = 400;//原点
	OrgY = 400;
	width = 100;
}

CSquare::CSquare(int x,int y,int w)
{
	OrgX = x;
	OrgY = y;
	width = w;
	BorderWidth = 1;
	BorderColor = RGB(255, 0, 0);
	BorderType = PS_SOLID;
	FillType = HS_DIAGCROSS;
	FillColor = RGB(255, 0, 0);
	Type = SQUARE;
}

void CSquare::Draw(CDC* pDC)//绘制图形函数
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width / 2, OrgY + width / 2);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CSquare::IsMatched(CPoint pnt)//图元匹配函数
{
	if( (OrgX-width/2<=pnt.x && pnt.x<=OrgX+width/2) && ( OrgY-width/2 <= pnt.y && pnt.y <= OrgY+width/2 ) )
		return true;
	else
		return false;
}
void CSquare::SetDate(int x, int y, int w, int h, int a) 
{
	OrgX = x;
	OrgY = y;
	width = w;
};


//矩形
IMPLEMENT_SERIAL(CRectangle, CObject, 1)//实现类CSquare的序列化指定版本为1
void CRectangle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
		ar << height;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
		ar >> height;
	}
}
CRectangle::CRectangle()
{
	OrgX = 400;//原点
	OrgY = 400;
	width = 200;
	height = 100;
}

CRectangle::CRectangle(int x, int y, int w ,int h)
{
	OrgX = x;
	OrgY = y;
	width = w;
	height = h;
	BorderWidth = 1;
	BorderColor = RGB(255, 0, 0);
	BorderType = PS_SOLID;
	FillType = HS_DIAGCROSS;
	FillColor = RGB(255, 0, 0);
	Type = RECTANGLE;
}

void CRectangle::Draw(CDC* pDC)//绘制图形函数
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width / 2, OrgY + height / 2);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CRectangle::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((OrgX - width / 2 <= pnt.x && pnt.x <= OrgX + width / 2) && (OrgY - height / 2 <= pnt.y && pnt.y <= OrgY + height / 2))
		return true;
	else
		return false;
}
void CRectangle::SetDate(int x, int y, int w, int h, int a)
{
	OrgX = x;
	OrgY = y;
	width = w;
	height = h;
};



//三角形
IMPLEMENT_SERIAL(CTriangle, CObject, 1)//实现类CSquare的序列化指定版本为1
void CTriangle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
		ar << height;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
		ar >> height;
	}
}
CTriangle::CTriangle()
{
	OrgX = 400;//原点
	OrgY = 400;
	width = 200;
	height = 100;
}

CTriangle::CTriangle(int x, int y, int w, int h)
{
	OrgX = x;
	OrgY = y;
	width = w;
	height = h;
	BorderWidth = 1;
	BorderColor = RGB(255, 0, 0);
	BorderType = PS_SOLID;
	FillType = HS_DIAGCROSS;
	FillColor = RGB(255, 0, 0);
	Type = TRIANGLE;
}

void CTriangle::Draw(CDC* pDC)//绘制图形函数
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	
	POINT polygon[3] = {
		{OrgX,OrgY-2*height/3},
		{OrgX-width/2,OrgY+height/3},
		{OrgX+width/2,OrgY+height/3}
	};
	pDC->Polygon(polygon,3);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CTriangle::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((OrgX - width/2 <= pnt.x && pnt.x <= OrgX + width/2) && ((OrgY - 2 * height / 3) <= pnt.y && pnt.y <= OrgY + height / 3) && ( pnt.y-OrgY+(2.0/3.0)*height+2.0*height/width*(pnt.x-OrgX) )>=0 && (pnt.y - OrgY + (2.0 / 3.0)*height - 2.0*height / width * (pnt.x - OrgX)) >= 0)
		return true;
	else
		return false;
}
void CTriangle::SetDate(int x, int y, int w, int h, int a)
{
	OrgX = x;
	OrgY = y;
	width = w;
	height = h;
};




//圆形
IMPLEMENT_SERIAL(CCircle, CObject, 1)//实现类CSquare的序列化指定版本为1
void CCircle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
	}
}
CCircle::CCircle()
{
	OrgX = 400;//原点
	OrgY = 400;
	width = 200;
}

CCircle::CCircle(int x, int y, int w)
{
	OrgX = x;
	OrgY = y;
	width = w;
	BorderWidth = 1;
	BorderColor = RGB(255, 0, 0);
	BorderType = PS_SOLID;
	FillType = HS_DIAGCROSS;
	FillColor = RGB(255, 0, 0);
	Type = CIRCLE;
}

void CCircle::Draw(CDC* pDC)//绘制图形函数
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Ellipse(OrgX-width/2,OrgY-width/2,OrgX+width/2,OrgY+width/2);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CCircle::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((pow (double(pnt.x-OrgX),2)+pow(double(pnt.y-OrgY),2))<=pow(double(width/2),2))
		return true;
	else
		return false;
}
void CCircle::SetDate(int x, int y, int w, int h, int a)
{
	OrgX = x;
	OrgY = y;
	width = w;
};




//椭圆
IMPLEMENT_SERIAL(CEllipse, CObject, 1)//实现类CSquare的序列化指定版本为1
void CEllipse::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
		ar << height;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
		ar >> height;
	}
}
CEllipse::CEllipse()
{
	OrgX = 400;//原点
	OrgY = 400;
	width = 200;
	height = 100;
}

CEllipse::CEllipse(int x, int y, int w ,int h)
{
	OrgX = x;
	OrgY = y;
	width = w;
	height = h;
	BorderWidth = 1;
	BorderColor = RGB(255, 0, 0);
	BorderType = PS_SOLID;
	FillType = HS_DIAGCROSS;
	FillColor = RGB(255, 0, 0);
	Type = ELLIPSE;
}

void CEllipse::Draw(CDC* pDC)//绘制图形函数
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Ellipse(OrgX - width / 2, OrgY - height / 2, OrgX + width / 2, OrgY + height / 2);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool CEllipse::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((pow(double(pnt.x-OrgX),2)/pow(double(width/2),2)+pow(double(pnt.y-OrgY),2)/pow(double(height/2),2))<=1)
		return true;
	else
		return false;
}
void CEllipse::SetDate(int x, int y, int w, int h, int a)
{
	OrgX = x;
	OrgY = y;
	width = w;
	height = h;
};



//文本
IMPLEMENT_SERIAL(CText, CObject, 1)//实现类CSquare的序列化指定版本为1
void CText::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
		ar << height;
		ar << angle;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
		ar >> height;
		ar >> angle;
	}
}
CText::CText()
{
	OrgX = 400;//原点
	OrgY = 400;
	width = 200;
	angle = 100;
}

CText::CText(int x, int y, int w, int h, int a)
{
	OrgX = x;
	OrgY = y;
	width = w;
	height = h;
	angle = a;
	BorderWidth = 1;
	BorderColor = RGB(255, 0, 0);
	BorderType = PS_SOLID;
	FillType = HS_DIAGCROSS;
	FillColor = RGB(255, 0, 0);
	Type = TEXT;
}

void CText::Draw(CDC* pDC)//绘制图形函数
{
	CFont * pNewFont = new CFont;
	CFont *pOldFont;
	pNewFont->CreateFont(height,width,angle*10,0,200,FALSE,0,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH&FF_SWISS,"Aerial");
	pOldFont = (CFont *)pDC->SelectObject(pNewFont);
	pDC->SetTextColor(BorderColor);
	pDC->TextOutA(OrgX, OrgY, "CText CText!");

}

bool CText::IsMatched(CPoint pnt)//图元匹配函数
{
	if ( ( pnt.y-OrgY+tan((angle/180.0)*M_PI)*(pnt.x-OrgX))>=0 && (pnt.y-OrgY-1/(tan(angle/180.0* M_PI))*(pnt.x-OrgX))<= 0  && ( pnt.y-OrgY+tan((angle/180.0)*M_PI)*(pnt.x-OrgX))<=height/cos(angle/180.0*M_PI) && (pnt.y-OrgY-1/(tan(angle/180.0* M_PI))*(pnt.x-OrgX))>= (-(width*12 /*字符数，动态字符可用GetLength()获得*/)/sin(angle/180.0*M_PI)))
		return true;
	else
		return false;
}
void CText::SetDate(int x, int y, int w, int h, int a)
{
	OrgX = x;
	OrgY = y;
	width = w;
	height = h;
	angle = a;
};
