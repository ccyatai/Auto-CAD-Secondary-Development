#if !defined(AFX_INPUTDLG_H__C32300F7_1297_4000_86AC_27595C079C5D__INCLUDED_)
#define AFX_INPUTDLG_H__C32300F7_1297_4000_86AC_27595C079C5D__INCLUDED_
#include "resource.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog

class CInputDlg : public CDialog
{
// Construction
public:
	CInputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInputDlg)
	enum { IDD = IDD_DIALOG1 };
	double	m_center1X;
	double	m_center1Y;
	double	m_center1Z;
	double	m_center2Y;
	double	m_center2Z;
	double	m_radius;
	int		m_axisnum;
	int		m_circlenum;
	double	m_center2X;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInputDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDLG_H__C32300F7_1297_4000_86AC_27595C079C5D__INCLUDED_)
