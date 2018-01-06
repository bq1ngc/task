# task

作业记录  
代码在线运行：https://ideone.com

## 目录

* [Instantclick.js改版](//github.com/XinRoom/task/blob/master/js/instantclick.js)
* [Python树](//github.com/XinRoom/task/blob/master/python/tree.py)
* [第一次c++课程设计-Drawing](//github.com/XinRoom/task/tree/master/c++/curriculum_design_first)

# 第一次c++课程设计

>本项目使用VS2010创建，VS2017库版本，可兼容VS2010，VS2010在项目属性修改平台工具集版本即可  
  
*如要下载项目，返回到task根项目下载整个仓库，从中解压本目录后再运行*

## 设计目的

参加本课程设计的同学已经学习了《C语言程序设计》和《面向对象可视化编程》两门课程，现在需要通过一个相对实际性的开发过程来巩固与鉴定一下学习成效，可以查看离实际需要还有哪些部分没有完全掌握，需要加强；另外本课程设计可以提供一个稍微具有规模的程序开发的例子，让同学们可以体会到程序的构思、编码以及调试的完整过程，最后并总结课程设计的过程。

## 课程设计的内容与设计思路

本课程设计要求编制一个简单的图形编辑的系统，可以添加、修改与删除图形元素，以形成图形画面。  
  
**具体要求如下：**  
  
1. 支持图元为简单的6种图形，图上的黑点给图元的原点，w 为宽度width ，h 为高度height，r 为半径radius，a 为字符角度angle。这些为这些图元需要保存的参数，另外，每个图元是否填充，用什么模式填充。
![xinroom](https://raw.githubusercontent.com/XinRoom/task/master/c++/curriculum_design_first/static/图片1.jpg)

2. 采用单文档方式，文档中存储图形画面的各个图元数据，视图负责图形的绘制。
3. 文档支持图形的序列化（连载），提供新建、打开、保存等操作。
4. 视图除了绘制图形，还提供图形交互，能够按住Ctrl 键再鼠标左键单击来创建图元，鼠标左键双击编辑修改图元属性，鼠标右键双击删除图元。
5. 图元创建与修改时的参数由参数对话框来编辑。创建时以鼠标左击时光标的所在位置作为基点来创建图元。
![xinroom](https://raw.githubusercontent.com/XinRoom/task/master/c++/curriculum_design_first/static/图片2.jpg)
6. 使用图元基础类shape 作为所有六个图元类的基类，设计派生各个具体的图形类，要求支持上述功能。
![xinroom](https://raw.githubusercontent.com/XinRoom/task/master/c++/curriculum_design_first/static/图片3.jpg)
![xinroom](https://raw.githubusercontent.com/XinRoom/task/master/c++/curriculum_design_first/static/图片4.jpg)

## 设计思路

如上图所示，主要通过CShape的虚函数统一实现，用对话框类设置相关数据。  
解释一下整个运行框架：  
**Shape**类存放图形的绘制、修改等函数；**DrawingDoc**用于存放图形数据序列；**DrawingView**用于绘制图像、响应用户操作；**Type**是新建的图源设置对话框的类，用于存放用户设置数据  
  
**一个简单的思路图**  
![xinroom](https://raw.githubusercontent.com/XinRoom/task/master/c++/curriculum_design_first/static/图片6.jpg)

## 效果如下

![xinroom](https://raw.githubusercontent.com/XinRoom/task/master/c++/curriculum_design_first/static/图片5.jpg)

## 主要文件和函数

### Shape.h

```
class CShape : public CObject
{
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
...
}
```

### Shape.cpp

。。。

### DrawView.cpp

```
void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
    if ((nFlags&MK_CONTROL) == MK_CONTROL)//Ctrl键按下
    {
        if(dlg.DoModal()==IDOK)
        {
            int index = ((CDrawingApp *)AfxGetApp())->m_index;  //获取索引
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
            ...
            }
        }
    }
    else
    {   //左键单击更新图像
        for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
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
    //右键双击删除图像
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
```

### Type.cpp //设置对话框

```
BOOL CType::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  在此添加额外的初始化
    for (int i=0;i<6;i++)
    {
    m_TYType.AddString(coure_Type[i]);
    }
    int ind = ((CDrawingApp *)AfxGetApp())->m_index;
    m_TYType.SetCurSel(ind);
    if(ind==5)
    GetDlgItem(IDC_Angele)->ShowWindow(TRUE),GetDlgItem(IDC_STATIC00)->ShowWindow(TRUE);
    for (int i=0;i<3;i++)
    {
    m_LineType.AddString(coure_Line[i]);
        m_FillType.AddString(coure_Fill[i]);
    }
    m_LineType.SetCurSel(0);
    m_FillType.SetCurSel(0);
    ((CDrawingApp *)AfxGetApp())->m_index = m_TYType.GetCurSel();
    return TRUE;  // return TRUE unless you set the focus to a control
    // 异常: OCX 属性页应返回 FALSE
}

void CType::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    UpdateData();

    CDialogEx::OnOK();
}

void CType::OnCbnSelchangeTytype()
{
    // TODO: 在此添加控件通知处理程序代码
    int isSel=((CDrawingApp *)AfxGetApp())->m_index = m_TYType.GetCurSel();
    switch (isSel)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        GetDlgItem(IDC_Angele)->ShowWindow(FALSE);
        GetDlgItem(IDC_STATIC00)->ShowWindow(FALSE);
        break;
    case 5:
        GetDlgItem(IDC_Angele)->ShowWindow(TRUE);
        GetDlgItem(IDC_STATIC00)->ShowWindow(TRUE);
        break;
    }
}
...
```