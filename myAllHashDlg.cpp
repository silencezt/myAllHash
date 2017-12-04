// myAllHashDlg.cpp : implementation file
//

#include "stdafx.h"
#include "myAllHash.h"
#include "myAllHashDlg.h"
#include "afxmt.h"
#include "MyCryptogramHead.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


struct	myControl
{
	CButton * BFile  ;
	CButton * BRun  ;
	CButton * BRes  ;
	CButton * Radio1  ;
	CButton * Radio2  ;
	CButton * CheckALL ;
	CButton * CheckMD4  ;
	CButton * CheckMD5  ;
	CButton * CheckSHA1  ;
	CButton * CheckSHA224;
	CButton * CheckSHA256;
	CButton * CheckSHA384;
	CButton * CheckSHA512;
	CButton	* CheckRIPE128 ;
	CButton	* CheckRIPE160 ;
	CButton	* CheckRIPE256 ;
	CButton	* CheckRIPE320 ;
	CEdit	* MD4 ;
	CEdit	* MD5 ;
	CEdit	* SHA1 ;
	CEdit	* SHA224 ;
	CEdit	* SHA256 ;
	CEdit	* SHA384 ;
	CEdit	* SHA512 ;
	CEdit	* RIPE128 ;
	CEdit	* RIPE160 ;
	CEdit	* RIPE256 ;
	CEdit	* RIPE320 ;

	CEdit	* TIME1 ;
	CEdit	* TIME2 ;
	CEdit	* TIME3 ;
	CEdit	* TIME4 ;
	CEdit	* TIME5 ;
	CEdit	* TIME6 ;
	CEdit	* TIME7 ;
	CEdit	* TIME8 ;
	CEdit	* TIME9 ;
	CEdit	* TIME10 ;
	CEdit	* TIME11 ;

	CEdit	* PERTIME1 ;
	CEdit	* PERTIME2 ;
	CEdit	* PERTIME3 ;
	CEdit	* PERTIME4 ;
	CEdit	* PERTIME5 ;
	CEdit	* PERTIME6 ;
	CEdit	* PERTIME7 ;
	CEdit	* PERTIME8 ;
	CEdit	* PERTIME9 ;
	CEdit	* PERTIME10 ;
	CEdit	* PERTIME11 ;
}TheControl;

BYTE	* TheData ;
DWORD	LenOfData(0) ;

CSemaphore	semaphore(12,12); 
CEvent		event[11];
CString		CSFile ;
BYTE		IsFILE(0) ;
BYTE		NumOfHash(11) ;


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
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyAllHashDlg dialog

CMyAllHashDlg::CMyAllHashDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyAllHashDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyAllHashDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyAllHashDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyAllHashDlg)
	DDX_Control(pDX, IDC_BUTTON_RESULT, m_BUTTON_RES);
	DDX_Control(pDX, IDC_CHECK_ALL, m_CHECK_ALL);
	DDX_Control(pDX, IDC_EDIT_RIPE320, m_EDIT_RIPE320);
	DDX_Control(pDX, IDC_EDIT_RIPE256, m_EDIT_RIPE256);
	DDX_Control(pDX, IDC_EDIT_RIPE160, m_EDIT_RIPE160);
	DDX_Control(pDX, IDC_EDIT_RIPE128, m_EDIT_RIPE128);
	DDX_Control(pDX, IDC_CHECK_RIPE320, m_CHECK_RIPE320);
	DDX_Control(pDX, IDC_CHECK_RIPE256, m_CHECK_RIPE256);
	DDX_Control(pDX, IDC_CHECK_RIPE160, m_CHECK_RIPE160);
	DDX_Control(pDX, IDC_CHECK_RIPE128, m_CHECK_RIPE128);
	DDX_Control(pDX, IDC_CHECK_SHA512, m_CHECK_SHA512);
	DDX_Control(pDX, IDC_CHECK_SHA384, m_CHECK_SHA384);
	DDX_Control(pDX, IDC_CHECK_SHA256, m_CHECK_SHA256);
	DDX_Control(pDX, IDC_CHECK_SHA224, m_CHECK_SHA224);
	DDX_Control(pDX, IDC_CHECK_SHA1, m_CHECK_SHA1);
	DDX_Control(pDX, IDC_CHECK_MD5, m_CHECK_MD5);
	DDX_Control(pDX, IDC_CHECK_MD4, m_CHECK_MD4);
	DDX_Control(pDX, IDC_EDIT_SHA512, m_EDIT_SHA512);
	DDX_Control(pDX, IDC_EDIT_SHA384, m_EDIT_SHA384);
	DDX_Control(pDX, IDC_EDIT_SHA256, m_EDIT_SHA256);
	DDX_Control(pDX, IDC_EDIT_SHA224, m_EDIT_SHA224);
	DDX_Control(pDX, IDC_EDIT_SHA1, m_EDIT_SHA1);
	DDX_Control(pDX, IDC_EDIT_MD5, m_EDIT_MD5);
	DDX_Control(pDX, IDC_EDIT_MD4, m_EDIT_MD4);
	DDX_Control(pDX, IDC_EDIT_STR, m_EDIT_STR);
	DDX_Control(pDX, IDC_BUTTON_RUN, m_BUTTON_RUN);
	DDX_Control(pDX, IDC_BUTTON_FILE, m_BUTTON_FILE);
	DDX_Control(pDX, IDC_EDIT_FILE, m_EDIT_FILE);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyAllHashDlg, CDialog)
	//{{AFX_MSG_MAP(CMyAllHashDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_STR, OnRadioStr)
	ON_BN_CLICKED(IDC_RADIO_FILE, OnRadioFile)
	ON_BN_CLICKED(IDC_CHECK_MD4, OnCheckMd4)
	ON_BN_CLICKED(IDC_CHECK_MD5, OnCheckMd5)
	ON_BN_CLICKED(IDC_CHECK_SHA1, OnCheckSha1)
	ON_BN_CLICKED(IDC_CHECK_SHA224, OnCheckSha224)
	ON_BN_CLICKED(IDC_CHECK_SHA256, OnCheckSha256)
	ON_BN_CLICKED(IDC_CHECK_SHA384, OnCheckSha384)
	ON_BN_CLICKED(IDC_CHECK_SHA512, OnCheckSha512)
	ON_BN_CLICKED(IDC_BUTTON_RUN, OnButtonRun)
	ON_BN_CLICKED(IDC_BUTTON_FILE, OnButtonFile)
	ON_EN_CHANGE(IDC_EDIT_STR, OnChangeEditStr)
	ON_EN_CHANGE(IDC_EDIT_FILE, OnChangeEditFile)
	ON_BN_CLICKED(IDC_BUTTON_BYE, OnButtonBye)
	ON_BN_CLICKED(IDC_CHECK_RIPE128, OnCheckRipe128)
	ON_BN_CLICKED(IDC_CHECK_RIPE160, OnCheckRipe160)
	ON_BN_CLICKED(IDC_CHECK_RIPE256, OnCheckRipe256)
	ON_BN_CLICKED(IDC_CHECK_RIPE320, OnCheckRipe320)
	ON_BN_CLICKED(IDC_CHECK_ALL, OnCheckAll)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, OnButtonResult)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyAllHashDlg message handlers

BOOL CMyAllHashDlg::OnInitDialog()
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
	TheControl.BFile	=	& m_BUTTON_FILE ;
	TheControl.BRun		=	& m_BUTTON_RUN ;
	TheControl.BRes		=	& m_BUTTON_RES ;
	TheControl.MD4		=	& m_EDIT_MD4 ;
	TheControl.MD5		=	& m_EDIT_MD5 ;
	TheControl.SHA1		=	& m_EDIT_SHA1 ;
	TheControl.SHA224	=	& m_EDIT_SHA224 ;
	TheControl.SHA256	=	& m_EDIT_SHA256 ;
	TheControl.SHA384	=	& m_EDIT_SHA384 ;
	TheControl.SHA512	=	& m_EDIT_SHA512 ;
	TheControl.RIPE128	=	& m_EDIT_RIPE128 ;
	TheControl.RIPE160	=	& m_EDIT_RIPE160 ;
	TheControl.RIPE256	=	& m_EDIT_RIPE256 ;
	TheControl.RIPE320	=	& m_EDIT_RIPE320 ;
	TheControl.Radio1	=	((CButton*)GetDlgItem(IDC_RADIO_STR)) ;
	TheControl.Radio2	=	((CButton*)GetDlgItem(IDC_RADIO_FILE)) ;
	TheControl.CheckALL		=	& m_CHECK_ALL ;
	TheControl.CheckMD4		=	& m_CHECK_MD4 ;
	TheControl.CheckMD5		=	& m_CHECK_MD5 ;
	TheControl.CheckSHA1	=	& m_CHECK_SHA1 ;
	TheControl.CheckSHA224	=	& m_CHECK_SHA224 ;
	TheControl.CheckSHA256	=	& m_CHECK_SHA256 ;
	TheControl.CheckSHA384	=	& m_CHECK_SHA384 ;
	TheControl.CheckSHA512	=	& m_CHECK_SHA512 ;
	TheControl.CheckRIPE128	=	& m_CHECK_RIPE128 ;
	TheControl.CheckRIPE160	=	& m_CHECK_RIPE160 ;
	TheControl.CheckRIPE256	=	& m_CHECK_RIPE256 ;
	TheControl.CheckRIPE320	=	& m_CHECK_RIPE320 ;

	TheControl.TIME1	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME1)) ;
	TheControl.TIME2	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME2)) ;
	TheControl.TIME3	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME3)) ;
	TheControl.TIME4	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME4)) ;
	TheControl.TIME5	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME5)) ;
	TheControl.TIME6	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME6)) ;
	TheControl.TIME7	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME7)) ;
	TheControl.TIME8	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME8)) ;
	TheControl.TIME9	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME9)) ;
	TheControl.TIME10	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME10)) ;
	TheControl.TIME11	=	((CEdit*)GetDlgItem(IDC_EDIT_TIME11)) ;

	TheControl.PERTIME1	=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME1)) ;
	TheControl.PERTIME2	=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME2)) ;
	TheControl.PERTIME3	=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME3)) ;
	TheControl.PERTIME4	=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME4)) ;
	TheControl.PERTIME5	=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME5)) ;
	TheControl.PERTIME6	=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME6)) ;
	TheControl.PERTIME7	=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME7)) ;
	TheControl.PERTIME8	=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME8)) ;
	TheControl.PERTIME9	=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME9)) ;
	TheControl.PERTIME10=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME10)) ;
	TheControl.PERTIME11=	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME11)) ;

	GetDlgItem(IDC_BUTTON_FILE)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_RUN)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_RESULT)->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_RADIO_STR))->SetCheck(BST_CHECKED);

	SETALLCHECK(TRUE);

	GetDlgItem(IDC_EDIT_STR)->SetWindowText( "" );
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyAllHashDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyAllHashDlg::OnPaint() 
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
HCURSOR CMyAllHashDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyAllHashDlg::OnRadioStr() 
{
	// TODO: Add your control notification handler code here
	IsFILE	=	0 ;
	GetDlgItem(IDC_BUTTON_FILE)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_RUN)->EnableWindow(false);
	GetDlgItem(IDC_EDIT_STR)->EnableWindow(true);
	SetDlgItemText( IDC_EDIT_FILE, "" );
	SetDlgItemText( IDC_EDIT_STR, "" );
	CSFile	=	"" ;
	
}

void CMyAllHashDlg::OnRadioFile() 
{
	// TODO: Add your control notification handler code here
	IsFILE	=	1 ;	
	GetDlgItem(IDC_BUTTON_FILE)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_RUN)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_STR)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_RESULT)->EnableWindow(false);
	SetDlgItemText( IDC_EDIT_STR, "" );

}

void CMyAllHashDlg::OnCheckAll() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_ALL.GetCheck() == TRUE )
	{
		SETALLCHECK(TRUE);
		CLEARALLEDIT() ;

		NumOfHash = 11 ;
	}
	else
	{
		SETALLCHECK(FALSE);
		CLEARALLEDIT() ;
		GetDlgItem(IDC_BUTTON_RESULT)->EnableWindow(false);
		NumOfHash = 0 ;
	}
}


void CMyAllHashDlg::OnCheckMd4() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_MD4.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_MD4, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckMd5() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_MD5.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_MD5, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckSha1() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_SHA1.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_SHA1, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckSha224() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_SHA224.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_SHA224, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckSha256() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_SHA256.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_SHA256, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckSha384() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_SHA384.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_SHA384, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckSha512() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_SHA512.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_SHA512, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckRipe128() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_RIPE128.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_RIPE128, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckRipe160() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_RIPE160.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_RIPE160, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckRipe256() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_RIPE256.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_RIPE256, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}

void CMyAllHashDlg::OnCheckRipe320() 
{
	// TODO: Add your control notification handler code here
	if( m_CHECK_RIPE320.GetCheck() == false )
	{
		SetDlgItemText( IDC_EDIT_RIPE320, "" );
		((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(FALSE) ;
		NumOfHash	-- ;
	}
	else
		NumOfHash	++	;
}


void CMyAllHashDlg::OnButtonRun() 
{
	// TODO: Add your control notification handler code here
	FILE	* PFile ;
	if( CSFile == "" )
	{
	AfxMessageBox("请先选择一个文件!" );
	return ;
	}
	PFile = fopen( CSFile , "rb" ) ;
	fseek( PFile , 0 , SEEK_END );											//计算文件长度
	LenOfData = ftell( PFile ) ;
	rewind( PFile ) ;
	TheData	=	new BYTE[LenOfData] ;
	fread( TheData , LenOfData , 1 , PFile ) ;
	fclose( PFile ) ;
	MyRun() ;
}

UINT HashMD4(LPVOID pParam)
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[33] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	myMD4_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME1->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME1->SetWindowText(CSTime);

	TheControl.MD4->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[0].SetEvent();
	return 0;
}

UINT HashMD5(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[33] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	myMD5_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME2->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME2->SetWindowText(CSTime);

	TheControl.MD5->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[1].SetEvent();
	return 0;
}

UINT HashSHA1(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[41] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	mySHA1_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME3->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME3->SetWindowText(CSTime);

	TheControl.SHA1->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[2].SetEvent();
	return 0;
}

UINT HashSHA224(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[57] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	mySHA224_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME4->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME4->SetWindowText(CSTime);

	TheControl.SHA224->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[3].SetEvent();
	return 0;
}

UINT HashSHA256(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[65] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	mySHA256_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME5->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME5->SetWindowText(CSTime);

	TheControl.SHA256->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[4].SetEvent();
	return 0;
}

UINT HashSHA384(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[97] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	mySHA384_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME6->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME6->SetWindowText(CSTime);

	TheControl.SHA384->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[5].SetEvent();
	return 0;
}

UINT HashSHA512(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[129] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	mySHA512_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME7->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME7->SetWindowText(CSTime);

	TheControl.SHA512->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[6].SetEvent();
	return 0;
}

UINT HashRIPE128(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[33] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	myRIPEMD128_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME8->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME8->SetWindowText(CSTime);

	TheControl.RIPE128->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[7].SetEvent();
	return 0;
}

UINT HashRIPE160(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[41] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	myRIPEMD160_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME9->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME9->SetWindowText(CSTime);

	TheControl.RIPE160->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[8].SetEvent();
	return 0;
}

UINT HashRIPE256(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[65] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	myRIPEMD256_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME10->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME10->SetWindowText(CSTime);

	TheControl.RIPE256->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[9].SetEvent();
	return 0;
}

UINT HashRIPE320(LPVOID pParam) 
{
	WaitForSingleObject(semaphore.m_hObject,INFINITE);
	char OutPutStr[81] = {0} ;

	CString	CSTime ;
	clock_t		begin , end ;
	begin = clock();
	myRIPEMD320_RunStr( TheData , LenOfData ,  OutPutStr );
	end = clock();		
	CSTime.Format( "%d" , end - begin ) ;
	TheControl.TIME11->SetWindowText(CSTime);
	if( (end - begin) == 0 )
		CSTime.Format( "" ) ;
	else
		CSTime.Format( "%d" ,LenOfData / (end - begin) ) ;
	TheControl.PERTIME11->SetWindowText(CSTime);

	TheControl.RIPE320->SetWindowText( OutPutStr );
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	event[10].SetEvent();
	return 0;
}

UINT FinishDo(LPVOID pParam) 
{
	WaitForSingleObject(event[0].m_hObject,INFINITE);
	WaitForSingleObject(event[1].m_hObject,INFINITE);
	WaitForSingleObject(event[2].m_hObject,INFINITE);
	WaitForSingleObject(event[3].m_hObject,INFINITE);
	WaitForSingleObject(event[4].m_hObject,INFINITE);
	WaitForSingleObject(event[5].m_hObject,INFINITE);
	WaitForSingleObject(event[6].m_hObject,INFINITE);
	WaitForSingleObject(event[7].m_hObject,INFINITE);
	WaitForSingleObject(event[8].m_hObject,INFINITE);
	WaitForSingleObject(event[9].m_hObject,INFINITE);
	WaitForSingleObject(event[10].m_hObject,INFINITE);
	if( IsFILE )
	{
		TheControl.Radio1->EnableWindow(true);
		TheControl.Radio2->EnableWindow(true);
		TheControl.BRun->EnableWindow(true);
		TheControl.CheckALL ->EnableWindow(true);
		TheControl.CheckMD4 ->EnableWindow(true);
		TheControl.CheckMD5 ->EnableWindow(true);
		TheControl.CheckSHA1->EnableWindow(true);
		TheControl.CheckSHA224->EnableWindow(true);
		TheControl.CheckSHA256->EnableWindow(true);
		TheControl.CheckSHA384->EnableWindow(true);
		TheControl.CheckSHA512->EnableWindow(true);
		TheControl.CheckRIPE128->EnableWindow(true);
		TheControl.CheckRIPE160->EnableWindow(true);
		TheControl.CheckRIPE256->EnableWindow(true);
		TheControl.CheckRIPE320->EnableWindow(true);
		
		TheControl.BFile->EnableWindow(true);

	}
	if( NumOfHash != 0 )
		TheControl.BRes->EnableWindow(true);

	delete TheData ;

	event[0].ResetEvent() ;
	event[1].ResetEvent() ;
	event[2].ResetEvent() ;
	event[3].ResetEvent() ;
	event[4].ResetEvent() ;
	event[5].ResetEvent() ;
	event[6].ResetEvent() ;
	event[7].ResetEvent() ;
	event[8].ResetEvent() ;
	event[9].ResetEvent() ;
	event[10].ResetEvent() ;
	ReleaseSemaphore(semaphore.m_hObject,1,NULL);
	return 0;
}

void CMyAllHashDlg::OnButtonFile() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"All Files(*.*)|*.*||",AfxGetMainWnd());
	if(dlg.DoModal()==IDOK)
		CSFile	=	dlg.GetPathName();
	else
		return ;
	SetDlgItemText(IDC_EDIT_FILE , CSFile );	

}

void CMyAllHashDlg::OnChangeEditStr() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CLEARALLEDIT() ;
	if(GetCheckedRadioButton( IDC_RADIO_STR , IDC_RADIO_FILE ) == IDC_RADIO_STR )
	{
		CString	data ;
		LenOfData	=	m_EDIT_STR.GetWindowTextLength() ;
		TheData	=	new BYTE[LenOfData] ;
		GetDlgItem(IDC_EDIT_STR)->GetWindowText(data);
		memcpy( TheData , data , LenOfData ) ;
		MyRun() ;
	}

	
	// TODO: Add your control notification handler code here
	
}

void CMyAllHashDlg::OnChangeEditFile() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	TheControl.BRes->EnableWindow(false);
	CLEARALLEDIT() ;
	// TODO: Add your control notification handler code here
	
}

void CMyAllHashDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CMyAllHashDlg::OnButtonBye() 
{
	// TODO: Add your control notification handler code here
	if( AfxMessageBox( "是否确定要退出本程序?" , MB_OKCANCEL ) == IDOK )
		CDialog::OnOK();
	else
		return ;
}



void CMyAllHashDlg::OnButtonResult() 
{
	// TODO: Add your control notification handler code here
	CString SaveFilePathName;
	CFileDialog dlg(FALSE,"txt","HashResult",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"Text Files(*.txt)|*.txt||",AfxGetMainWnd());
	if(dlg.DoModal()==IDOK)
		SaveFilePathName=dlg.GetPathName();
	else
		return ;

	CString	SaveData = "" ;
	CString	InPutData = "" ;
	if(GetCheckedRadioButton( IDC_RADIO_STR , IDC_RADIO_FILE ) == IDC_RADIO_STR )
	{
		SaveData	=	"字符串：“" ;
		m_EDIT_STR.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"”\r\n" ;
	}
	else
	{
		m_EDIT_FILE.GetWindowText(InPutData) ;
		SaveData	=	"文件路径:" ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_MD4.GetCheck() == TRUE )
	{
		SaveData	+=	"MD4	:" ;
		m_EDIT_MD4.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_MD5.GetCheck() == TRUE )
	{
		SaveData	+=	"MD5	:" ;
		m_EDIT_MD5.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_SHA1.GetCheck() == TRUE )
	{
		SaveData	+=	"SHA1	:" ;
		m_EDIT_SHA1.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_SHA224.GetCheck() == TRUE )
	{
		SaveData	+=	"SHA224	:" ;
		m_EDIT_SHA224.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_SHA256.GetCheck() == TRUE )
	{
		SaveData	+=	"SHA256	:" ;
		m_EDIT_SHA256.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_SHA384.GetCheck() == TRUE )
	{
		SaveData	+=	"SHA384	:" ;
		m_EDIT_SHA384.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_SHA512.GetCheck() == TRUE )
	{
		SaveData	+=	"SHA512	:" ;
		m_EDIT_SHA512.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_RIPE128.GetCheck() == TRUE )
	{
		SaveData	+=	"RIPE128:" ;
		m_EDIT_RIPE128.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}


	if( m_CHECK_RIPE160.GetCheck() == TRUE )
	{
		SaveData	+=	"RIPE160:" ;
		m_EDIT_RIPE160.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_RIPE256.GetCheck() == TRUE )
	{
		SaveData	+=	"RIPE256:" ;
		m_EDIT_RIPE256.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}

	if( m_CHECK_RIPE320.GetCheck() == TRUE )
	{
		SaveData	+=	"RIPE320:" ;
		m_EDIT_RIPE320.GetWindowText(InPutData) ;
		SaveData	+=	InPutData ;
		SaveData	+=	"\r\n" ;
	}


	FILE	* PSaveFile ;
	PSaveFile = fopen( SaveFilePathName , "wb" );
	fwrite( SaveData , SaveData.GetLength() , 1 , PSaveFile ) ;
	fclose(PSaveFile) ;
	AfxMessageBox( "保存完成!" ) ;
}

void CMyAllHashDlg::MyRun()
{

/*	if(GetCheckedRadioButton( IDC_RADIO_STR , IDC_RADIO_FILE ) == IDC_RADIO_STR )
	{
		CString	data ;
		LenOfData	=	m_EDIT_STR.GetWindowTextLength() ;
		TheData	=	new BYTE[LenOfData] ;
		GetDlgItem(IDC_EDIT_STR)->GetWindowText(data);
		memcpy( TheData , data , LenOfData ) ;
	}
	else
	{
		FILE	* PFile ;
		if( CSFile == "" )
		{
			AfxMessageBox("请先选择一个文件!" );
			return ;
		}
		PFile = fopen( CSFile , "rb" ) ;
		fseek( PFile , 0 , SEEK_END );											//计算文件长度
		LenOfData = ftell( PFile ) ;
		rewind( PFile ) ;
		TheData	=	new BYTE[LenOfData] ;
		fread( TheData , LenOfData , 1 , PFile ) ;
		fclose( PFile ) ;
	}
*/
	if(IsFILE )
	{
		TheControl.Radio1->EnableWindow(false);
		TheControl.Radio2->EnableWindow(false);
		TheControl.BFile->EnableWindow(false);
		TheControl.BRun->EnableWindow(false);
		TheControl.BRes->EnableWindow(false);
		GetDlgItem(IDC_CHECK_ALL)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_MD4)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_MD5)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_SHA1)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_SHA224)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_SHA256)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_SHA384)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_SHA512)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_RIPE128)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_RIPE160)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_RIPE256)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_RIPE320)->EnableWindow(false);
	}

	if( m_CHECK_MD4.GetCheck() == TRUE )
	{
		CWinThread *pHash1=AfxBeginThread(HashMD4,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash1->ResumeThread();
	}
	else
		event[0].SetEvent();

	if( m_CHECK_MD5.GetCheck() == TRUE )
	{
		CWinThread *pHash2=AfxBeginThread(HashMD5,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash2->ResumeThread();
	}
	else
		event[1].SetEvent();

	if( m_CHECK_SHA1.GetCheck() == TRUE )
	{
		CWinThread *pHash3=AfxBeginThread(HashSHA1,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash3->ResumeThread();
	}
	else
		event[2].SetEvent();

	if( m_CHECK_SHA224.GetCheck() == TRUE )
	{
		CWinThread *pHash4=AfxBeginThread(HashSHA224,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash4->ResumeThread();
	}
	else
		event[3].SetEvent();

	if( m_CHECK_SHA256.GetCheck() == TRUE )
	{
		CWinThread *pHash5=AfxBeginThread(HashSHA256,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash5->ResumeThread();
	}
	else
		event[4].SetEvent();

	if( m_CHECK_SHA384.GetCheck() == TRUE )
	{
		CWinThread *pHash6=AfxBeginThread(HashSHA384,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash6->ResumeThread();
	}
	else
		event[5].SetEvent();

	if( m_CHECK_SHA512.GetCheck() == TRUE )
	{
		CWinThread *pHash7=AfxBeginThread(HashSHA512,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash7->ResumeThread();
	}
	else
		event[6].SetEvent();

	if( m_CHECK_RIPE128.GetCheck() == TRUE )
	{
		CWinThread *pHash8=AfxBeginThread(HashRIPE128,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash8->ResumeThread();
	}
	else
		event[7].SetEvent();

	if( m_CHECK_RIPE160.GetCheck() == TRUE )
	{
		CWinThread *pHash9=AfxBeginThread(HashRIPE160,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash9->ResumeThread();
	}
	else
		event[8].SetEvent();

	if( m_CHECK_RIPE256.GetCheck() == TRUE )
	{
		CWinThread *pHash10=AfxBeginThread(HashRIPE256,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash10->ResumeThread();
	}
	else
		event[9].SetEvent();

	if( m_CHECK_RIPE320.GetCheck() == TRUE )
	{
		CWinThread *pHash11=AfxBeginThread(HashRIPE320,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		pHash11->ResumeThread();
	}
	else
		event[10].SetEvent();
	CWinThread *pFinish=AfxBeginThread(FinishDo,&TheControl,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
	pFinish->ResumeThread();
}

void CMyAllHashDlg::OnButtonClear() 
{
	((CEdit*)GetDlgItem(IDC_EDIT_TIME1))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME2))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME3))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME4))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME5))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME6))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME7))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME8))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME9))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME10))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_TIME11))->SetWindowText("");

	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME1))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME2))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME3))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME4))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME5))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME6))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME7))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME8))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME9))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME10))->SetWindowText("");
	((CEdit*)GetDlgItem(IDC_EDIT_PERTIME11))->SetWindowText("");
}
