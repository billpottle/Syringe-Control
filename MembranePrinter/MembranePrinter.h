// MembranePrinter.h : main header file for the MEMBRANEPRINTER application
//

#if !defined(AFX_MEMBRANEPRINTER_H__8852B406_69EF_41FA_B045_0EB81D79E91B__INCLUDED_)
#define AFX_MEMBRANEPRINTER_H__8852B406_69EF_41FA_B045_0EB81D79E91B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMembranePrinterApp:
// See MembranePrinter.cpp for the implementation of this class
//

class CMembranePrinterApp : public CWinApp
{
public:
	CMembranePrinterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMembranePrinterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMembranePrinterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMBRANEPRINTER_H__8852B406_69EF_41FA_B045_0EB81D79E91B__INCLUDED_)
