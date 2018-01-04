#pragma once
#define M_PI 3.14159265358979323846
// CShape 命令目标
enum ElementType { SQUARE, RECTANGLE, TRIANGLE, CIRCLE, ELLIPSE, TEXT };
class CShape : public CObject
{
public:
	CShape();
	virtual ~CShape();
	virtual void Draw(CDC*pDC) = 0;//绘制图元
	virtual bool IsMatched(CPoint pnt) = 0;//点是否落在图形内部
	virtual void Serialize(CArchive& ar) = 0;//序列化
	void SetBase(ElementType T, COLORREF BorderC, int BorderT, int BorderW, COLORREF FillC, int FillT) {
		Type = T;
		BorderColor = BorderC;
		BorderType = BorderT;
		BorderWidth = BorderW;
		FillColor = FillC;
		FillType = FillT;
	};
	virtual void SetDate(int x,int y, int w, int h, int a) = 0;
	ElementType GetDate()
	{
		return Type;
	};
protected:
	ElementType Type;//图元类型
	int OrgX;//原点坐标
	int OrgY;
	COLORREF BorderColor;//边界颜色
	int BorderType;//边界线型实线、虚线、虚点线 PS_SOLID PS_DASH   PS_DOT
	int BorderWidth;//边界宽度
	COLORREF FillColor;//填充颜色
	int FillType;//填充类----实心、双对角、十字交叉  HS_DIAGCROSS  HS_CROSS HS_BDIAGONAL
};

class CSquare : public CShape
{
public:
	CSquare();
	CSquare(int x, int y, int w);
	void Draw(CDC*pDC);//绘制
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
	void SetDate(int x, int y, int w, int h, int a);
private:
	int width;
	DECLARE_SERIAL(CSquare)//声明类CSquare支持序列化
};

//矩形
class CRectangle : public CShape
{
public:
	CRectangle();
	CRectangle(int x, int y, int w ,int h);
	void Draw(CDC*pDC);//绘制
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
	void SetDate(int x, int y, int w, int h, int a);
private:
	int width,height;
	DECLARE_SERIAL(CRectangle)//声明类CRectangle支持序列化
};

//三角
class CTriangle : public CShape
{
public:
	CTriangle();
	CTriangle(int x, int y, int w, int h);
	void Draw(CDC*pDC);//绘制
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
	void SetDate(int x, int y, int w, int h, int a);
private:
	int width, height;
	DECLARE_SERIAL(CTriangle)//声明类CTriangle支持序列化
};

//圆
class CCircle : public CShape
{
public:
	CCircle();
	CCircle(int x, int y, int w);
	void Draw(CDC*pDC);//绘制
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
	void SetDate(int x, int y, int w, int h, int a);
private:
	int width, height;
	DECLARE_SERIAL(CCircle)//声明类CTriangle支持序列化
};

//椭圆
class CEllipse : public CShape
{
public:
	CEllipse();
	CEllipse(int x, int y, int w ,int h);
	void Draw(CDC*pDC);//绘制
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
	void SetDate(int x, int y, int w, int h, int a);
private:
	int width, height;
	DECLARE_SERIAL(CEllipse)//声明类CTriangle支持序列化
};

//文字
class CText : public CShape
{
public:
	CText();
	CText(int x, int y, int w, int h, int a);
	void Draw(CDC*pDC);//绘制
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
	void SetDate(int x, int y, int w, int h, int a);
private:
	int width, height, angle;
	DECLARE_SERIAL(CText)
};