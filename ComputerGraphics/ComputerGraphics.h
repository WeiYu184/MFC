
// 2016302590184.h : 2016302590184 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
# include "math.h" 

// CMy2016302590184App:
// �йش����ʵ�֣������ 2016302590184.cpp
//

class CMy2016302590184App : public CWinAppEx
{
public:
	CMy2016302590184App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2016302590184App theApp;
