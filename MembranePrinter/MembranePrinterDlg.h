// MembranePrinterDlg.h : header file
//

#if !defined(AFX_MEMBRANEPRINTERDLG_H__85C2FF2B_4BB5_4B8B_B39F_2BA63298B443__INCLUDED_)
#define AFX_MEMBRANEPRINTERDLG_H__85C2FF2B_4BB5_4B8B_B39F_2BA63298B443__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMembranePrinterDlg dialog

class CMembranePrinterDlg : public CDialog
{
// Construction
public:
	CMembranePrinterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMembranePrinterDlg)

	//Tags defined for input going from top of dialog to bottom
//The tags allow the program to read in the user input. 
	enum { IDD = IDD_MEMBRANEPRINTER_DIALOG };
	int		m_Input1;
	int		m_Input2;
	int		m_Input3;
	int		m_Input4;
	int		m_Input5;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMembranePrinterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMembranePrinterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMBRANEPRINTERDLG_H__85C2FF2B_4BB5_4B8B_B39F_2BA63298B443__INCLUDED_)
