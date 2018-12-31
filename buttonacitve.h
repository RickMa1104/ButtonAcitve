// buttonacitve.h : main header file for the BUTTONACITVE application
//

#if !defined(AFX_BUTTONACITVE_H__A93697CC_F065_45F1_8948_4D83EE6E1860__INCLUDED_)
#define AFX_BUTTONACITVE_H__A93697CC_F065_45F1_8948_4D83EE6E1860__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CButtonacitveApp:
// See buttonacitve.cpp for the implementation of this class
//

class CButtonacitveApp : public CWinApp
{
public:
	CButtonacitveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonacitveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CButtonacitveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONACITVE_H__A93697CC_F065_45F1_8948_4D83EE6E1860__INCLUDED_)
