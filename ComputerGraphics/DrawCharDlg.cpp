// DrawCharDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "2016302590184.h"
#include "DrawCharDlg.h"
#include "afxdialogex.h"


// CDrawCharDlg �Ի���

IMPLEMENT_DYNAMIC(CDrawCharDlg, CDialog)

CDrawCharDlg::CDrawCharDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDrawCharDlg::IDD, pParent)
{

	m_strString = _T("");
	m_nX = 0;
	m_nY = 0;
	m_clrText = RGB(0,0,0);
}

CDrawCharDlg::~CDrawCharDlg()
{
}

void CDrawCharDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT, m_strString);
	DDV_MaxChars(pDX, m_strString, 1000);
	DDX_Text(pDX, IDC_X, m_nX);
	DDV_MinMaxInt(pDX, m_nX, 10, 1080);
	DDX_Text(pDX, IDC_Y, m_nY);
	DDV_MinMaxInt(pDX, m_nY, 10, 1080);
}


BEGIN_MESSAGE_MAP(CDrawCharDlg, CDialog)
	ON_EN_CHANGE(IDC_TEXT, &CDrawCharDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BFONT, &CDrawCharDlg::OnBnClickedBfont)
END_MESSAGE_MAP()


// CDrawCharDlg ��Ϣ�������


void CDrawCharDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDrawCharDlg::OnBnClickedBfont()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFontDialog dlg;
    if (dlg.DoModal() == IDOK)
    {
        m_fnt.DeleteObject();
        LOGFONT LogFnt;
        dlg.GetCurrentFont(&LogFnt);       //������ѡ����
        m_fnt.CreateFontIndirect(&LogFnt); //������ѡ����
        m_clrText = dlg.GetColor();        //�����ѡ��ɫ
    }

}
