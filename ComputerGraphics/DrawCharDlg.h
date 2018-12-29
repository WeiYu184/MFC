#pragma once


// CDrawCharDlg 对话框

class CDrawCharDlg : public CDialog
{
	DECLARE_DYNAMIC(CDrawCharDlg)

public:
	CDrawCharDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDrawCharDlg();

// 对话框数据
	CFont m_fnt; // 保存字体
	COLORREF m_clrText; // 保存颜色
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_strString;
	int m_nX;
	int m_nY;
	afx_msg void OnBnClickedBfont();
};
