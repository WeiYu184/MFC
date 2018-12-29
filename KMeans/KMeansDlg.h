
// KMeansDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CKMeansDlg �Ի���
class CKMeansDlg : public CDialogEx
{
// ����
public:
	CKMeansDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_KMEANS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	// ѡ��������ļ���·��
	CString DataFileName;
	// ��ʼ����������
	int m_K;
	// ��ʼ�������ĵ�ѡ��ʽ
	CComboBoxEx KSample;
	// ѡ���ʼ�������ĵķ�ʽ
	CComboBox m_KSample;
	afx_msg void OnCbnSelchangeCombo1();
	// ����ļ���·��
	CString ResultFileName;
	afx_msg void OnBnClickedButton2();
};
