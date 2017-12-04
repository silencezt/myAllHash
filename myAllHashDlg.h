// myAllHashDlg.h : header file
//

#if !defined(AFX_MYALLHASHDLG_H__3593FEAF_40DC_4DF3_BF18_3875780B4C34__INCLUDED_)
#define AFX_MYALLHASHDLG_H__3593FEAF_40DC_4DF3_BF18_3875780B4C34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



/////////////////////////////////////////////////////////////////////////////
// CMyAllHashDlg dialog
UINT HashMD4(LPVOID pParam) ;
UINT HashMD5(LPVOID pParam) ;
UINT HashSHA1(LPVOID pParam) ;
UINT HashSHA224(LPVOID pParam) ;
UINT HashSHA256(LPVOID pParam) ;
UINT HashSHA384(LPVOID pParam) ;
UINT HashSHA512(LPVOID pParam) ;
UINT HashRIPE128(LPVOID pParam) ;
UINT HashRIPE160(LPVOID pParam) ;
UINT HashRIPE256(LPVOID pParam) ;
UINT HashRIPE320(LPVOID pParam) ;
UINT FinishDo(LPVOID pParam) ;

class CMyAllHashDlg : public CDialog
{
// Construction
public:
	void MyRun();
	CMyAllHashDlg(CWnd* pParent = NULL);	// standard constructor



// Dialog Data
	//{{AFX_DATA(CMyAllHashDlg)
	enum { IDD = IDD_MYALLHASH_DIALOG };
	CButton	m_BUTTON_RES;
	CButton	m_CHECK_ALL;
	CEdit	m_EDIT_RIPE320;
	CEdit	m_EDIT_RIPE256;
	CEdit	m_EDIT_RIPE160;
	CEdit	m_EDIT_RIPE128;
	CButton	m_CHECK_RIPE320;
	CButton	m_CHECK_RIPE256;
	CButton	m_CHECK_RIPE160;
	CButton	m_CHECK_RIPE128;
	CButton	m_CHECK_SHA512;
	CButton	m_CHECK_SHA384;
	CButton	m_CHECK_SHA256;
	CButton	m_CHECK_SHA224;
	CButton	m_CHECK_SHA1;
	CButton	m_CHECK_MD5;
	CButton	m_CHECK_MD4;
	CEdit	m_EDIT_SHA512;
	CEdit	m_EDIT_SHA384;
	CEdit	m_EDIT_SHA256;
	CEdit	m_EDIT_SHA224;
	CEdit	m_EDIT_SHA1;
	CEdit	m_EDIT_MD5;
	CEdit	m_EDIT_MD4;
	CEdit	m_EDIT_STR;
	CButton	m_BUTTON_RUN;
	CButton	m_BUTTON_FILE;
	CEdit	m_EDIT_FILE;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyAllHashDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyAllHashDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadioStr();
	afx_msg void OnRadioFile();
	afx_msg void OnCheckMd4();
	afx_msg void OnCheckMd5();
	afx_msg void OnCheckSha1();
	afx_msg void OnCheckSha224();
	afx_msg void OnCheckSha256();
	afx_msg void OnCheckSha384();
	afx_msg void OnCheckSha512();
	afx_msg void OnButtonRun();
	afx_msg void OnButtonFile();
	afx_msg void OnChangeEditStr();
	afx_msg void OnChangeEditFile();
	virtual void OnCancel();
	afx_msg void OnButtonBye();
	afx_msg void OnCheckRipe128();
	afx_msg void OnCheckRipe160();
	afx_msg void OnCheckRipe256();
	afx_msg void OnCheckRipe320();
	afx_msg void OnCheckAll();
	afx_msg void OnButtonResult();
	afx_msg void OnButtonClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#define CLEARALLEDIT()	{																\
							SetDlgItemText( IDC_EDIT_MD4, "" );							\
							SetDlgItemText( IDC_EDIT_MD5, "" );							\
							SetDlgItemText( IDC_EDIT_SHA1, "" );						\
							SetDlgItemText( IDC_EDIT_SHA224, "" );						\
							SetDlgItemText( IDC_EDIT_SHA256, "" );						\
							SetDlgItemText( IDC_EDIT_SHA384, "" );						\
							SetDlgItemText( IDC_EDIT_SHA512, "" );						\
							SetDlgItemText( IDC_EDIT_RIPE128, "" );						\
							SetDlgItemText( IDC_EDIT_RIPE160, "" );						\
							SetDlgItemText( IDC_EDIT_RIPE256, "" );						\
							SetDlgItemText( IDC_EDIT_RIPE320, "" );						\
						}

#define SETALLCHECK(X)	{																\
	((CButton*)GetDlgItem(IDC_CHECK_ALL))->SetCheck(X) ;								\
	((CButton*)GetDlgItem(IDC_CHECK_MD4))->SetCheck(X) ;								\
	((CButton*)GetDlgItem(IDC_CHECK_MD5))->SetCheck(X) ;								\
	((CButton*)GetDlgItem(IDC_CHECK_SHA1))->SetCheck(X) ;								\
	((CButton*)GetDlgItem(IDC_CHECK_SHA224))->SetCheck(X) ;								\
	((CButton*)GetDlgItem(IDC_CHECK_SHA256))->SetCheck(X) ;								\
	((CButton*)GetDlgItem(IDC_CHECK_SHA384))->SetCheck(X) ;								\
	((CButton*)GetDlgItem(IDC_CHECK_SHA512))->SetCheck(X) ;								\
	((CButton*)GetDlgItem(IDC_CHECK_RIPE128))->SetCheck(X) ;							\
	((CButton*)GetDlgItem(IDC_CHECK_RIPE160))->SetCheck(X) ;							\
	((CButton*)GetDlgItem(IDC_CHECK_RIPE256))->SetCheck(X) ;							\
	((CButton*)GetDlgItem(IDC_CHECK_RIPE320))->SetCheck(X) ;							\
						}


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYALLHASHDLG_H__3593FEAF_40DC_4DF3_BF18_3875780B4C34__INCLUDED_)
