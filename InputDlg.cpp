// InputDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "resource.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog


CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputDlg)
	m_center1X = 0.0;
	m_center1Y = 0.0;
	m_center1Z = 0.0;
	m_center2Y = 0.0;
	m_center2Z = 0.0;
	m_radius = 0.0;
	m_axisnum = 0;
	m_circlenum = 0;
	m_center2X = 0.0;
	//}}AFX_DATA_INIT
}


void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputDlg)
	DDX_Text(pDX, IDC_EDIT1, m_center1X);
	DDX_Text(pDX, IDC_EDIT2, m_center1Y);
	DDX_Text(pDX, IDC_EDIT3, m_center1Z);
	DDX_Text(pDX, IDC_EDIT5, m_center2Y);
	DDX_Text(pDX, IDC_EDIT6, m_center2Z);
	DDX_Text(pDX, IDC_EDIT7, m_radius);
	DDX_Text(pDX, IDC_EDIT8, m_axisnum);
	DDX_Text(pDX, IDC_EDIT9, m_circlenum);
	DDX_Text(pDX, IDC_EDIT4, m_center2X);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
	//{{AFX_MSG_MAP(CInputDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputDlg message handlers
