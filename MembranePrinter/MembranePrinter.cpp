// MembranePrinter.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MembranePrinter.h"
#include "MembranePrinterDlg.h"
#include "printercontroller.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMembranePrinterApp

BEGIN_MESSAGE_MAP(CMembranePrinterApp, CWinApp)
	//{{AFX_MSG_MAP(CMembranePrinterApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMembranePrinterApp construction

CMembranePrinterApp::CMembranePrinterApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMembranePrinterApp object

CMembranePrinterApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMembranePrinterApp initialization

BOOL CMembranePrinterApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
//Create new printercontroller and Dialog window
	printercontroller pc1;
	CMembranePrinterDlg dlg;
	m_pMainWnd = &dlg;

	//Supply default input parameters to make typing easier
	dlg.m_Input1=1;
	dlg.m_Input2=200;
	dlg.m_Input3=0;
	dlg.m_Input4=30;
	dlg.m_Input5=1;
	
	//DoModal automatically updates the values in the keys corresponding to the 
	//system parameters input by the user
	
	dlg.DoModal( );

	//now set the appropriate values in the printercontroller object
	pc1.setValues(dlg.m_Input1, dlg.m_Input2, dlg.m_Input4, dlg.m_Input5, dlg.m_Input3);
	//run the system
	pc1.run();



	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
