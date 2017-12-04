// myAllHash.h : main header file for the MYALLHASH application
//

#if !defined(AFX_MYALLHASH_H__101C0702_9841_42BD_88A0_D8DE352AD5B2__INCLUDED_)
#define AFX_MYALLHASH_H__101C0702_9841_42BD_88A0_D8DE352AD5B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include"Include\\USkin.h"
#pragma comment(lib, "LIB\\USkin.lib")


/////////////////////////////////////////////////////////////////////////////
// CMyAllHashApp:
// See myAllHash.cpp for the implementation of this class
//
typedef  BOOL (__stdcall *PFNUSkinInit)( PCHAR lpszUserName,PCHAR lpszRegCode,PCHAR lpszFileName );

typedef BOOL  (__stdcall * PFNUSkinExit)();
typedef BOOL  (__stdcall * PFNUSkinLoadSkin)(PCHAR lpszFileName);


class CMyAllHashApp : public CWinApp
{
public:
	CMyAllHashApp();

		HMODULE hModuleUSkin ;
		PFNUSkinInit USkinInit;
		PFNUSkinExit USkinExit;
		 PFNUSkinLoadSkin USkinLoadSkin;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyAllHashApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyAllHashApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYALLHASH_H__101C0702_9841_42BD_88A0_D8DE352AD5B2__INCLUDED_)
