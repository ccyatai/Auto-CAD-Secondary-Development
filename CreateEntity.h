AcDbObjectId CreateEllipse(AcGePoint3d center, AcGeVector3d majorAxis, double radiusRatio, Adesk::UInt16 color, char* layer);
AcDbObjectId CreateLine(AcGePoint3d start, AcGePoint3d end, 
						Adesk::UInt16 color, char* layer);
AcDbObjectId CreatePolyline(AcGePoint3dArray *vertices, 
							Adesk::UInt16 color, char* layer);
AcDbObjectId CreateCircle(AcGePoint3d center, double radius, 
						  Adesk::UInt16 color, char* layer);
AcDbObjectId CreateArc(AcGePoint3d center, double radius,
					   double startAng, double endAng, 
					   Adesk::UInt16 color, char* layer);
AcDbObjectId CreateText(AcGePoint3d point, char* text, double h,
						Adesk::UInt16 color, char* layer);
AcDbObjectId CreateText(AcGePoint3d point, char* text, double h,
						Adesk::UInt16 color, char* layer, char* style);
AcDbObjectId CreateSolid(AcGePoint3d pt1,
						 AcGePoint3d pt2,
						 AcGePoint3d pt3,
						 AcGePoint3d pt4,
						 Adesk::UInt16 color, 
						 char* layer);
void AddTextStyle(char* name, char* font);
void AddLayer(char* name, Adesk::UInt16 color);
void SetLayerColor(char* name, Adesk::UInt16 color);
void SetLayerOff(char* name, bool isOff);
void EraseAll();
void DeleteLayerEntities(char* name);
