
// KMeansDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CKMeansDlg �Ի���




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


// CKMeansDlg ��Ϣ�������

BOOL CKMeansDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
  	m_KSample.AddString(_T("ѡ��ǰK������"));
    m_KSample.AddString(_T("ѡ���K������"));
    m_KSample.AddString(_T("���ѡ��K������"));
    // Ĭ��ѡ���һ��   
    m_KSample.SetCurSel(0);   
    SetDlgItemText(IDC_COMBO1, _T("ѡ��ǰK������"));   
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CKMeansDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CKMeansDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKMeansDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// �������ļ�
	UpdateData(TRUE);
	CFileDialog dlg(TRUE, _T("txt"),NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"(*.txt)|*.txt||");
	 if (IDOK == dlg.DoModal())   
    {   
        // ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
        DataFileName = dlg.GetPathName();   
        SetDlgItemText(IDC_EDIT2, DataFileName);   
    }   
	//UpdateData(FALSE);

	// ���������ļ��ڵ�����
	FILE* fp1 = fopen(DataFileName, "r");
	if(!fp1) MessageBox("û���ļ�!");
	char buf[1000];
    int lineCnt = 0; 
    while (fgets(buf, 1000,fp1)) lineCnt++; // �ۼ�����
	rewind(fp1);
	data = new Data[lineCnt];
	for(int i = 0; i < lineCnt; i++)
		fscanf(fp1, "%d %lf %lf\n", &data[i].num, &data[i].x, &data[i].y); 
	fclose(fp1);

	// ��data����K-Means����
	K_Sample0 = new Data[m_K];
	K_Sample1 = new Data[m_K];
    memset(K_Sample1,0, sizeof(Data));
	_class = new Class[m_K];  // ��ʱ����ÿ������ĵ��
	double* F = new double[m_K];        // ���ڼ��㷶��
	memset(_class, 0, sizeof(Class)); // ��ʼ���洢��
	for(int i = 0; i < m_K; i++) _class[i].n_cnt = 0;

	// ѡ���ʼK���������ĵķ�ʽ
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

	// K-Means�㷨
	int Flag = 0; // �㷨�����ı�־

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

		// ���¼����������
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

		// �ж��Ƿ�����
		for(int i = 0; i<m_K; i++)
		{
			if(memcmp(&K_Sample0[i],&K_Sample1[i],sizeof(Data)) == 0) Flag++;
		}
		if(Flag == m_K) break;
		else Flag = 0;
	}
	delete[]K_Sample0;
	delete[]K_Sample1;
	// д�����ļ�
}


void CKMeansDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    CString strWeb;   
    int nSel;   
  
    // ��ȡ��Ͽ�ؼ����б����ѡ���������
    nSel = m_KSample.GetCurSel();   
    // ����ѡ����������ȡ�����ַ���   
    m_KSample.GetLBText(nSel, strWeb);   
    // ����Ͽ���ѡ�е��ַ�����ʾ��IDC_SEL_WEB_EDIT�༭����   
    SetDlgItemText(IDC_COMBO1, strWeb);   

}


void CKMeansDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt||");   
    // ���챣���ļ��Ի���   
    CFileDialog fileDlg(FALSE, _T("txt"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);   
  
    // ��ʾ�����ļ��Ի���   
    if (IDOK == fileDlg.DoModal())   
    {   
        // ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
        ResultFileName = fileDlg.GetPathName();   
        SetDlgItemText(IDC_EDIT3, ResultFileName);   
    }   

	// д�����ļ�
	FILE* fp2 = fopen(ResultFileName, "w");
	for(int i = 0; i < m_K; i++)
	{
		fprintf(fp2, "��%d�ࣺ\n", i+1);
		for(int j = 0; j < _class[i].n_cnt; j++)
		{
			fprintf(fp2, "%d %lf %lf\n", data[_class[i].numb[j]].num, data[_class[i].numb[j]].x,  data[_class[i].numb[j]].y);
		}
	}
	fclose(fp2);
	delete[]data;
	delete[]_class;
}
