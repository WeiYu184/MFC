#pragma once


// CDrawCharDlg �Ի���

class CDrawCharDlg : public CDialog
{
	DECLARE_DYNAMIC(CDrawCharDlg)

public:
	CDrawCharDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDrawCharDlg();

// �Ի�������
	CFont m_fnt; // ��������
	COLORREF m_clrText; // ������ɫ
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_strString;
	int m_nX;
	int m_nY;
	afx_msg void OnBnClickedBfont();
};
