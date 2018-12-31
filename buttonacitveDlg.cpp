// buttonacitveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "buttonacitve.h"
#include "buttonacitveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
BOOL ontop=TRUE;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonacitveDlg dialog

CButtonacitveDlg::CButtonacitveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CButtonacitveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CButtonacitveDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonacitveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CButtonacitveDlg)
	DDX_Control(pDX, IDC_EDIT_WINNAME, m_edit_winname);
	DDX_Control(pDX, IDC_CHECK_ONTOP, m_check_ontop);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CButtonacitveDlg, CDialog)
	//{{AFX_MSG_MAP(CButtonacitveDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_ACTIVE, OnButtonActive)
	ON_BN_CLICKED(IDC_CHECK_ONTOP, OnCheckOntop)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonacitveDlg message handlers

BOOL CButtonacitveDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_check_ontop.SetCheck(TRUE);
	CRect windowRect;
	GetWindowRect(windowRect);
	::SetWindowPos(m_hWnd,HWND_TOPMOST,(::GetSystemMetrics(SM_CXSCREEN)-250)/2,(::GetSystemMetrics(SM_CYSCREEN)-50)/2,windowRect.Width(),windowRect.Height(),SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON4)->SetWindowText(_T("http://hi.baidu.com/yanzi52351"));
	GetDlgItem(IDC_BUTTON5)->SetWindowText(_T("http://www.kilter.tk"));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CButtonacitveDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CButtonacitveDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CButtonacitveDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
BOOL CALLBACK EnumChildProc(
							HWND hwnd,      // handle to child window
							LPARAM lParam   // application-defined value
)
{
	if(!IsWindowEnabled(hwnd))
	{
		EnableWindow(hwnd,TRUE);
	}
	return TRUE;
}
HWND top_win;
char name[101];
void CButtonacitveDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	top_win=::GetForegroundWindow();
	::GetWindowText(top_win,name,100);
	m_edit_winname.SetWindowText(name);
	EnumChildWindows(top_win,EnumChildProc,NULL);
	CDialog::OnTimer(nIDEvent);
}
bool start=false;
void CButtonacitveDlg::OnButtonActive() 
{
	// TODO: Add your control notification handler code here
	if(!start)
	{
		start=true;
		GetDlgItem(IDC_BUTTON_ACTIVE)->SetWindowText("Í£Ö¹");
		SetTimer(1,200,NULL);
	}
	else
	{
		start=false;
		GetDlgItem(IDC_BUTTON_ACTIVE)->SetWindowText("¼¤»î");
		KillTimer(1);
	}

}
void CButtonacitveDlg::StayOnTop(bool on)
{
	CRect windowRect;
	GetWindowRect(windowRect);
	if(on)
	{
		::SetWindowPos(m_hWnd,HWND_TOPMOST,windowRect.left,windowRect.top,windowRect.Width(),windowRect.Height(),SWP_SHOWWINDOW);
	}
	else
	{
		::SetWindowPos(m_hWnd,HWND_NOTOPMOST,windowRect.left,windowRect.top,windowRect.Width(),windowRect.Height(),SWP_SHOWWINDOW);
	}

}
void CButtonacitveDlg::OnCheckOntop() 
{
	// TODO: Add your control notification handler code here
	if(ontop)
	{
		m_check_ontop.SetCheck(!ontop);
		StayOnTop(false);
	}
	else
	{
		m_check_ontop.SetCheck(!ontop);
		StayOnTop(true);
	}
	ontop=!ontop;
	
}

HBRUSH CButtonacitveDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	HBRUSH b;
	if(nCtlColor==CTLCOLOR_LISTBOX)
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkColor(RGB(135,135,255));
		b=CreateSolidBrush(RGB(135,135,255));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_SCROLLBAR)
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(192,192,192));
		b=CreateSolidBrush(RGB(192,192,192));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_EDIT)
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkColor(RGB(135,135,255));
		b=CreateSolidBrush(RGB(135,135,255));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetTextColor(RGB(128,64,64));
		pDC->SetBkColor(RGB(160,180,220));
		b=CreateSolidBrush(RGB(160,180,220));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_DLG)
	{
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkColor(RGB(160,180,220));
		b=CreateSolidBrush(RGB(160,180,220));
		return b;
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CButtonacitveDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,"open",_T("http://hi.baidu.com/yanzi52351"),NULL,NULL,SW_SHOW);
}

void CButtonacitveDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here

	ShellExecute(NULL,"open",_T("http://www.kilter.tk"),NULL,NULL,SW_SHOW);
}

HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	HBRUSH b;
	if(nCtlColor==CTLCOLOR_LISTBOX)
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkColor(RGB(135,135,255));
		b=CreateSolidBrush(RGB(135,135,255));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_SCROLLBAR)
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(192,192,192));
		b=CreateSolidBrush(RGB(192,192,192));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_EDIT)
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkColor(RGB(135,135,255));
		b=CreateSolidBrush(RGB(135,135,255));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetTextColor(RGB(128,64,64));
		pDC->SetBkColor(RGB(160,180,220));
		b=CreateSolidBrush(RGB(160,180,220));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_DLG)
	{
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkColor(RGB(160,180,220));
		b=CreateSolidBrush(RGB(160,180,220));
		return b;
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CButtonacitveDlg::OnButtonHelp() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg abu;
	abu.DoModal();
}
