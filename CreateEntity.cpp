#include "stdafx.h"
#include "dbents.h"
#include "acutmem.h"
#include "CreateEntity.h"

AcDbObjectId CreateLine(AcGePoint3d start, AcGePoint3d end, 
						Adesk::UInt16 color, char* layer)
{
	AcDbLine* pLine = new AcDbLine(start,end);
	pLine->setColorIndex(color);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,
		AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId lineId;
	pBlockTableRecord->appendAcDbEntity(lineId, pLine);

	pBlockTableRecord->close();
	pLine->setLayer(layer);
	pLine->close();

	return lineId;
}

AcDbObjectId CreatePolyline(AcGePoint3dArray *vertices, 
							Adesk::UInt16 color, char* layer)
{
	AcDb2dPolyline* pPline = new AcDb2dPolyline(
		AcDb::k2dSimplePoly, *vertices, 0.0, Adesk::kTrue);
	pPline->setColorIndex(color);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,
		AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId plineId;
	pBlockTableRecord->appendAcDbEntity(plineId, pPline);

	pBlockTableRecord->close();
	pPline->setLayer(layer);
	pPline->close();

	return plineId;
}

AcDbObjectId CreateCircle(AcGePoint3d center, double radius, 
						  Adesk::UInt16 color, char* layer)
{
	AcGeVector3d v(0,0,1);
	AcDbCircle* pCircle = new AcDbCircle(center, v, radius);
	pCircle->setColorIndex(color);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,
		AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId circleId;
	pBlockTableRecord->appendAcDbEntity(circleId, pCircle);

	pBlockTableRecord->close();
	pCircle->setLayer(layer);
	pCircle->close();

	return circleId;
}
#include "dbelipse.h"
AcDbObjectId CreateEllipse(AcGePoint3d center, AcGeVector3d majorAxis, double radiusRatio, Adesk::UInt16 color, char* layer)
{
	AcGeVector3d v(0,0,1);
	AcDbEllipse* pEllipse = new AcDbEllipse(center, v, majorAxis, radiusRatio);
	pEllipse->setColorIndex(color);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId ellipseId;
	pBlockTableRecord->appendAcDbEntity(ellipseId, pEllipse);

	pBlockTableRecord->close();
	pEllipse->setLayer(layer);
	pEllipse->close();

	return ellipseId;
}

AcDbObjectId CreateArc(AcGePoint3d center, double radius,
					   double startAng, double endAng, 
					   Adesk::UInt16 color, char* layer)
{
	AcDbArc* pArc = new AcDbArc(center,radius,startAng,endAng);
	pArc->setColorIndex(color);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,
		AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId arcId;
	pBlockTableRecord->appendAcDbEntity(arcId, pArc);

	pBlockTableRecord->close();
	pArc->setLayer(layer);
	pArc->close();

	return arcId;
}

AcDbObjectId CreateText(AcGePoint3d point, char* text, double h,
						Adesk::UInt16 color, char* layer)
{
	AcDbText* pText = new AcDbText(point,text,AcDbObjectId::kNull,h,0);
	pText->setColorIndex(color);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId textId;
	pBlockTableRecord->appendAcDbEntity(textId, pText);

	pBlockTableRecord->close();
	pText->setLayer(layer);
	pText->close();

	return textId;
}

AcDbObjectId CreateText(AcGePoint3d point, char* text, double h,
						Adesk::UInt16 color, char* layer, char* style)
{
	AcDbTextStyleTable *pTable;
	AcDbObjectId sId;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pTable,AcDb::kForWrite);
	if(pTable->getAt(style,sId) != Acad::eOk) 
	{
		pTable->close();
		return CreateText(point,text,h,color,layer);
	}
	pTable->close();

	AcDbText* pText = new AcDbText(point,text,sId,h,0);
	pText->setColorIndex(color);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId textId;
	pBlockTableRecord->appendAcDbEntity(textId, pText);

	pBlockTableRecord->close();
	pText->setLayer(layer);
	pText->close();

	return textId;
}

AcDbObjectId CreateSolid(AcGePoint3d pt1,
						 AcGePoint3d pt2,
						 AcGePoint3d pt3,
						 AcGePoint3d pt4,
						 Adesk::UInt16 color, 
						 char* layer)
{
	AcDbSolid* pSolid = new AcDbSolid(pt1,pt2,pt3,pt4);
	pSolid->setColorIndex(color);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,
		AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId solidId;
	pBlockTableRecord->appendAcDbEntity(solidId, pSolid);

	pBlockTableRecord->close();
	pSolid->setLayer(layer);
	pSolid->close();

	return solidId;
}

void AddTextStyle(char* name, char* font)
{
	AcDbTextStyleTable *pTable;
	AcDbTextStyleTableRecord *pRecord;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pTable,AcDb::kForWrite);

	if(! pTable->has(name)) 
	{
		pRecord = new AcDbTextStyleTableRecord;
		pRecord->setName(name);
		pRecord->setFont(font,false,false,1,DEFAULT_PITCH);
		pTable->add(pRecord);
		pRecord->close();
	}
	pTable->close();
}

void AddLayer(char* name, Adesk::UInt16 color)
{
	AcDbLayerTable *pLayerTbl;
	AcDbLayerTableRecord *pLayerTblRcd;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pLayerTbl,AcDb::kForWrite); 

	if(! pLayerTbl->has(name)) 
	{
		pLayerTblRcd = new AcDbLayerTableRecord;
		pLayerTblRcd->setName(name);
		pLayerTblRcd->setIsFrozen(0);
		pLayerTblRcd->setIsOff(0);
		pLayerTblRcd->setVPDFLT(0);
		pLayerTblRcd->setIsLocked(0);

		AcCmColor COLOR;
		COLOR.setColorIndex(color);
		pLayerTblRcd->setColor(COLOR);

		pLayerTbl->add(pLayerTblRcd);
	}
	else 
	{
		pLayerTbl->getAt(name,pLayerTblRcd,AcDb::kForWrite,false);
		AcCmColor COLOR;
		COLOR.setColorIndex(color);
		pLayerTblRcd->setColor(COLOR);

	}
	pLayerTblRcd->close();
	pLayerTbl->close();
}

void SetLayerColor(char* name, Adesk::UInt16 color)
{
	AcDbLayerTable *pLayerTbl;
	AcDbLayerTableRecord *pLayerTblRcd;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pLayerTbl,AcDb::kForWrite); 

	if( pLayerTbl->has(name) ) 
	{
		pLayerTbl->getAt(name,pLayerTblRcd,AcDb::kForWrite,false);
		AcCmColor COLOR;
		COLOR.setColorIndex(color);
		pLayerTblRcd->setColor(COLOR);
	}
	pLayerTblRcd->close();
	pLayerTbl->close();
}

void SetLayerOff(char* name, bool isOff)
{
	AcDbLayerTable *pLayerTbl;
	AcDbLayerTableRecord *pLayerTblRcd;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pLayerTbl,AcDb::kForWrite); 

	if( pLayerTbl->has(name) ) 
	{
		pLayerTbl->getAt(name,pLayerTblRcd,AcDb::kForWrite,false);
		pLayerTblRcd->setIsOff(isOff);
	}
	pLayerTblRcd->close();
	pLayerTbl->close();
}

void EraseAll()
{
	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,
		AcDb::kForWrite);

	AcDbBlockTableRecordIterator *pIter;
	pBlockTableRecord->newIterator(pIter);
	AcDbEntity *pEnt;
	for(;!pIter->done();pIter->step())
	{
		pIter->getEntity(pEnt, AcDb::kForWrite);
		pEnt->erase();
		pEnt->close();
	}

	delete pIter;
	pBlockTableRecord->close();
	pBlockTable->close();
}

void DeleteLayerEntities(char* name)
{
	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable,AcDb::kForRead); 
	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,pBlockTableRecord,AcDb::kForWrite);

	AcDbBlockTableRecordIterator *pIter;
	pBlockTableRecord->newIterator(pIter);
	AcDbEntity *pEnt;
	char* layerName;
	for(;!pIter->done();pIter->step())
	{
		pIter->getEntity(pEnt, AcDb::kForWrite);
		layerName = pEnt->layer();
		if(strcmp(layerName,name) == 0) pEnt->erase();
		pEnt->close();
		acutDelString(layerName);
	}
	delete pIter;
	pBlockTableRecord->close();
	pBlockTable->close();
}

	
