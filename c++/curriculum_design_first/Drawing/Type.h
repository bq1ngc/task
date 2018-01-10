#pragma once


// CType 对话框

class CType : public CDialogEx
{
	DECLARE_DYNAMIC(CType)

public:
	CType(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CType();
	COLORREF color_Fill;  //color
	COLORREF color_Line;  //
	int indexx;
	bool isOR = 0;
// 对话框数据
	enum { IDD = IDD_Type };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_Angle;
	int m_Height;
	int m_LineWidt;
	int m_OrgX;
	int m_OrgY;
	int m_Width;
	virtual BOOL OnInitDialog();
	CComboBox m_TYType;
	CListBox m_FillType;
	CListBox m_LineType;
	CString m_strTYType;
	afx_msg void OnBnClickedOk();
	int m_intListType;
	int m_intFillType;
	afx_msg void OnCbnSelchangeTytype();
	afx_msg void OnBnClickedLinecolorbutton();
	afx_msg void OnBnClickedFillcolorbutton();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CString m_Text;
};