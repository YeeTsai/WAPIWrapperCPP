
// WindQuantCppSample.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWindQuantCppSampleApp:
// �йش����ʵ�֣������ WindQuantCppSample.cpp
//

class CWindQuantCppSampleApp : public CWinApp
{
public:
	CWindQuantCppSampleApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWindQuantCppSampleApp theApp;