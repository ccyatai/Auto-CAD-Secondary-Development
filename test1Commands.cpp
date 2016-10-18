//
// ObjectARX defined commands

#include "StdAfx.h"
#include "StdArx.h"
#include "CreateEntity.h"
#include "InputDlg.h"

// This is command 'MESHCYLINDER'
void LCRtestMeshCylinder()
{
	// TODO: Implement the command
    EraseAll();
	CInputDlg dlg;
	dlg.m_center1X = DocVars.docData().center1.x;
	dlg.m_center1Y = DocVars.docData().center1.y;
	dlg.m_center1Z = DocVars.docData().center1.z;
	dlg.m_center2X = DocVars.docData().center2.x;
	dlg.m_center2Y = DocVars.docData().center2.y;
	dlg.m_center2Z = DocVars.docData().center2.z;
	dlg.m_radius = DocVars.docData().radius;
	dlg.m_axisnum = DocVars.docData().axisnum;
	dlg.m_circlenum = DocVars.docData().circlenum;

	if(dlg.DoModal() == IDOK)
	{
		DocVars.docData().center1.x = dlg.m_center1X;
		DocVars.docData().center1.y = dlg.m_center1Y;
		DocVars.docData().center1.z = dlg.m_center1Z;
		DocVars.docData().center2.x = dlg.m_center2X;
		DocVars.docData().center2.y = dlg.m_center2Y;
		DocVars.docData().center2.z = dlg.m_center2Z;
		DocVars.docData().radius = dlg.m_radius;
		DocVars.docData().axisnum = dlg.m_axisnum;
		DocVars.docData().circlenum = dlg.m_circlenum;
	}
	DocVars.docData().draw();
}

