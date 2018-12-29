
// KMeansDlg.cpp : 实现文件
//

#include <algorithm>
#include "stdafx.h"
#include "KMeans.h"
#include "KMeansDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef struct Data
{
	int num;
	double x,y;
};
static struct Data* data = NULL;
static struct Data* K_Sample0 = NULL;
static struct Data* K_Sample1 = NULL;

struct Class
{
	int numb[20];
	int n_cnt;
};
static struct Class* _class = NULL;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CKMeansDlg 对话框




CKMeansDlg::CKMeansDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CKMeansDlg::IDD, pParent)
	, DataFileName(_T("data file"))
	, m_K(0)
	, ResultFileName(_T("result file"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);  
}

void CKMeansDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, DataFileName);
	DDV_MaxChars(pDX, DataFileName, 50);
	DDX_Text(pDX, IDC_EDIT1, m_K);
	DDV_MinMaxInt(pDX, m_K, 2, 9);
	DDX_Control(pDX, IDC_COMBO1, m_KSample);
	DDX_Text(pDX, IDC_EDIT3, ResultFileName);
	DDV_MaxChars(pDX, ResultFileName, 88);
}

BEGIN_MESSAGE_MAP(CKMeansDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CKMeansDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CKMeansDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CKMeansDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CKMeansDlg 消息处理程序

BOOL CKMeansDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
  	m_KSample.AddString(_T("选择前K个样本"));
    m_KSample.AddString(_T("选择后K个样本"));
    m_KSample.AddString(_T("随机选择K个样本"));
    // 默认选择第一项   
    m_KSample.SetCurSel(0);   
    SetDlgItemText(IDC_COMBO1, _T("选择前K个样本"));   
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CKMeansDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CKMeansDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CKMeansDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKMeansDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 打开数据文件
	UpdateData(TRUE);
	CFileDialog dlg(TRUE, _T("txt"),NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"(*.txt)|*.txt||");
	 if (IDOK == dlg.DoModal())   
    {   
        // 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
        DataFileName = dlg.GetPathName();   
        SetDlgItemText(IDC_EDIT2, DataFileName);   
    }   
	//UpdateData(FALSE);

	// 读入数据文件内的内容
	FILE* fp1 = fopen(DataFileName, "r");
	if(!fp1) MessageBox("没有文件!");
	char buf[1000];
    int lineCnt = 0; 
    while (fgets(buf, 1000,fp1)) lineCnt++; // 累计行数
	rewind(fp1);
	data = new Data[lineCnt];
	for(int i = 0; i < lineCnt; i++)
		fscanf(fp1, "%d %lf %lf\n", &data[i].num, &data[i].x, &data[i].y); 
	fclose(fp1);

	// 对data进行K-Means聚类
	K_Sample0 = new Data[m_K];
	K_Sample1 = new Data[m_K];
    memset(K_Sample1,0, sizeof(Data));
	_class = new Class[m_K];  // 临时储存每个聚类的点号
	double* F = new double[m_K];        // 用于计算范数
	memset(_class, 0, sizeof(Class)); // 初始化存储器
	for(int i = 0; i < m_K; i++) _class[i].n_cnt = 0;

	// 选择初始K个聚类中心的方式
	int nIndex = m_KSample.GetCurSel();
	if(nIndex == 0)
	{
		for(int i = 0; i < m_K; i++) 
		{
			memcpy(&K_Sample0[i], &data[i], sizeof(Data));
		}
	}
	if(nIndex == 1)
	{
		for(int i = 0; i < m_K; i++) 
		{
			memcpy(&K_Sample0[i], &data[lineCnt-1-i], sizeof(Data));
		}
	}
	if(nIndex == 2)
	{
		int *cnt = new int[lineCnt];
		memset(cnt, 1, sizeof(cnt));
		int count = 0, j = 0;
		while(count <= m_K)
		{
			srand((unsigned)time(NULL));
			int rd = rand() % lineCnt;
			if(cnt[rd] != 0){ cnt[rd] = 0; count++;}
		}
		for(int i = 0; i < lineCnt, j < m_K; i++)
		{
			if(cnt[i] == 0) { memcpy(&K_Sample0[j], &data[i], sizeof(Data)); j++;}
		}
	}

	// K-Means算法
	int Flag = 0; // 算法收敛的标志

	while(Flag < m_K)
	{
		memset(_class, 0, sizeof(Class)); 
		for(int i = 0; i<m_K; i++)
			memcpy(&K_Sample1[i],&K_Sample0[i],sizeof(Data));
		for(int i = 0; i < lineCnt; i++)
		{

			for(int j = 0; j < m_K; j++)
			{
				F[j] = sqrt((double)((data[i].x - K_Sample1[j].x)*(data[i].x - K_Sample1[j].x)+(data[i].y - K_Sample1[j].y)*(data[i].y - K_Sample1[j].y)));
			}
			int m = 0;
			for(int j = 0; j < m_K-1; j++)
			{
				if(F[j] < F[j+1]) m = j;
				else m = j+1;
			}
			_class[m].numb[_class[m].n_cnt++] = i;
		}

		// 重新计算聚类中心
		for(int j = 0; j < m_K; j++)
		{
			double meanx = 0, meany = 0;
			for(int k = 0; k < _class[j].n_cnt; k++)
			{
				meanx += data[_class[j].numb[k]].x;
				meany += data[_class[j].numb[k]].y;
			}
			K_Sample0[j].x = meanx / _class[j].n_cnt;
			K_Sample0[j].y = meany / _class[j].n_cnt;
		}

		// 判断是否收敛
		for(int i = 0; i<m_K; i++)
		{
			if(memcmp(&K_Sample0[i],&K_Sample1[i],sizeof(Data)) == 0) Flag++;
		}
		if(Flag == m_K) break;
		else Flag = 0;
	}
	delete[]K_Sample0;
	delete[]K_Sample1;
	// 写入结果文件
}


void CKMeansDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
    CString strWeb;   
    int nSel;   
  
    // 获取组合框控件的列表框中选中项的索引
    nSel = m_KSample.GetCurSel();   
    // 根据选中项索引获取该项字符串   
    m_KSample.GetLBText(nSel, strWeb);   
    // 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
    SetDlgItemText(IDC_COMBO1, strWeb);   

}


void CKMeansDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	 TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt||");   
    // 构造保存文件对话框   
    CFileDialog fileDlg(FALSE, _T("txt"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);   
  
    // 显示保存文件对话框   
    if (IDOK == fileDlg.DoModal())   
    {   
        // 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
        ResultFileName = fileDlg.GetPathName();   
        SetDlgItemText(IDC_EDIT3, ResultFileName);   
    }   

	// 写入结果文件
	FILE* fp2 = fopen(ResultFileName, "w");
	for(int i = 0; i < m_K; i++)
	{
		fprintf(fp2, "第%d类：\n", i+1);
		for(int j = 0; j < _class[i].n_cnt; j++)
		{
			fprintf(fp2, "%d %lf %lf\n", data[_class[i].numb[j]].num, data[_class[i].numb[j]].x,  data[_class[i].numb[j]].y);
		}
	}
	fclose(fp2);
	delete[]data;
	delete[]_class;
}
