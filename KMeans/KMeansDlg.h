
// KMeansDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CKMeansDlg 对话框
class CKMeansDlg : public CDialogEx
{
// 构造
public:
	CKMeansDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_KMEANS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	// 选择的数据文件的路径
	CString DataFileName;
	// 初始聚类中心数
	int m_K;
	// 初始聚类中心的选择方式
	CComboBoxEx KSample;
	// 选择初始聚类中心的方式
	CComboBox m_KSample;
	afx_msg void OnCbnSelchangeCombo1();
	// 结果文件的路径
	CString ResultFileName;
	afx_msg void OnBnClickedButton2();
};
