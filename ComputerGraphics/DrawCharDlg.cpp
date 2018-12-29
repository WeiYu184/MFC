// DrawCharDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "2016302590184.h"
#include "DrawCharDlg.h"
#include "afxdialogex.h"


// CDrawCharDlg 对话框

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


// CDrawCharDlg 消息处理程序


void CDrawCharDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDrawCharDlg::OnBnClickedBfont()
{
	// TODO: 在此添加控件通知处理程序代码
	CFontDialog dlg;
    if (dlg.DoModal() == IDOK)
    {
        m_fnt.DeleteObject();
        LOGFONT LogFnt;
        dlg.GetCurrentFont(&LogFnt);       //保存所选字体
        m_fnt.CreateFontIndirect(&LogFnt); //创建所选字体
        m_clrText = dlg.GetColor();        //获得所选颜色
    }

}
