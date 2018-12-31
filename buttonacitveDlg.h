// buttonacitveDlg.h : header file
//

#if !defined(AFX_BUTTONACITVEDLG_H__41F66DCD_89AE_45EF_AA56_BFAF07278E1D__INCLUDED_)
#define AFX_BUTTONACITVEDLG_H__41F66DCD_89AE_45EF_AA56_BFAF07278E1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CButtonacitveDlg dialog

class CButtonacitveDlg : public CDialog
{
// Construction
public:
	CButtonacitveDlg(CWnd* pParent = NULL);	// standard constructor
	void StayOnTop(bool on);
// Dialog Data
	//{{AFX_DATA(CButtonacitveDlg)
	enum { IDD = IDD_BUTTONACITVE_DIALOG };
	CEdit	m_edit_winname;
	CButton	m_check_ontop;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonacitveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CButtonacitveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonActive();
	afx_msg void OnCheckOntop();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButtonHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONACITVEDLG_H__41F66DCD_89AE_45EF_AA56_BFAF07278E1D__INCLUDED_)
