#include "StdAfx.h"
#include "StdArx.h"
#include "CreateEntity.h"

// The one and only document manager object
// You can use the DocVars object to retrieve
// document specific data throughout your application
AsdkDataManager<CDocData> DocVars;


//
// Implementation of the document data class.
//
CDocData::CDocData()
{
	// NOTE: DO NOT edit the following lines.
	//{{AFX_ARX_DATA_INIT(CDocData)
	//}}AFX_ARX_DATA_INIT

	// TODO: add your own initialization.
	center1.x = 0;
	center1.y = 0;
	center1.z = 300;
	center2.x = 0;
	center2.y = 0;
	center2.z = 0;
	radius = 100;
	axisnum = 10;
	circlenum = 20;	
}

CDocData::CDocData(const CDocData &data)
{
	// TODO: add your own initialization.
	center1.x = 0;
	center1.y = 0;
	center1.z = 300;
	center2.x = 0;
	center2.y = 0;
	center2.z = 0;
	radius = 100;
	axisnum = 10;
	circlenum = 20;	
}

CDocData::~CDocData()
{
	// NOTE: DO NOT edit the following lines.
	//{{AFX_ARX_DATA_DEL(CDocData)
	//}}AFX_ARX_DATA_DEL

	// TODO: clean up.

}

void CDocData::draw()
{
	EraseAll();
	int k;
	double PI=3.1415927;
	AcGeVector3d axis(center2.x-center1.x,center2.y-center1.y,center2.z-center1.z);
	AcGeVector3d radius0,radius1;

	radius0=axis.perpVector();	//����������ȷ�ģ�����������ֻ�����������У�������û�ж�����ϣ����������һ�棬ֻ����һС���ֵķ֣���л���̣�
	radius1=radius0;
	
	AcGePoint3d **pt = new AcGePoint3d*[axisnum+1];					//�����Ķ�ά����
	for(int i=0;i<=axisnum;i++)
		pt[i] = new AcGePoint3d[circlenum];
	for(int j=0;j<=axisnum;j++)
	{
		k=0;
		radius0 = radius1;
		for(k=0;k<circlenum;k++)
		{
			radius0=radius0.rotateBy(2*PI/(double)circlenum,axis);                  
			pt[j][k]=center1+axis*j/(double)axisnum+radius0.normalize()*radius;   //�����е����������������ټ��Ͼ�����������õ���������
		}
	}

	for(j=0;j<=axisnum;j++)                                          //��ÿ��Բ������
	{
		k=0;
		for(k=0;k<circlenum;k++)
		{
			if(k!=circlenum-1)
				CreateLine(pt[j][k],pt[j][k+1],1,"0");
			else
				CreateLine(pt[j][k],pt[j][0],1,"0");
		}
	}

	for(j=0;j<axisnum;j++)                                           //��Բ��Բ֮�������
	{
		for(int k=0;k<circlenum;k++)
		{
			CreateLine(pt[j][k],pt[j+1][k],1,"0");
		}
	}
}
