
//Use drawPeacock() function to 

//User Defined global function declarations
void drawPeacock(void);
void drawNeck(MY_POINT OriginPeacock);
void drawHead(MY_POINT OriginPeacock);
void drawEyesAndNose(MY_POINT OriginPeacock);
void drawBody(MY_POINT OriginPeacock);
void drawLegs(MY_POINT OriginPeacock);

void drawWings(MY_POINT OriginPeacock);

void drawCircleWithColor(float, float, float, float, float, float, float, float, int);

void drawPeacock(void)
{
	MY_POINT OriginPeacock;
	OriginPeacock.x = 0.0;
	OriginPeacock.y = 0.0;
	OriginPeacock.z = 0.0;
	
	drawWings(OriginPeacock);

	drawHead(OriginPeacock);
	drawEyesAndNose(OriginPeacock);
	drawNeck(OriginPeacock);
	drawBody(OriginPeacock);
	drawLegs(OriginPeacock);
}

void drawHead(MY_POINT OriginPeacock)
{
	SHAPE PeacockHead, PeacockHeadTop;
	PeacockHeadTop.noOfPoints = 4;
	PeacockHead.noOfPoints = 6;
	//DrawHeadTop

	PeacockHeadTop.points[0].x = OriginPeacock.x + (-0.001f);
	PeacockHeadTop.points[0].y = OriginPeacock.y + 0.65f;
	PeacockHeadTop.points[0].z = OriginPeacock.z + 0.00f;

	PeacockHeadTop.points[1].x = OriginPeacock.x + (-0.01f);
	PeacockHeadTop.points[1].y = OriginPeacock.y + 0.75f;
	PeacockHeadTop.points[1].z = OriginPeacock.z + 0.00f;

	PeacockHeadTop.points[2].x = OriginPeacock.x + (0.01f);
	PeacockHeadTop.points[2].y = OriginPeacock.y + 0.75f;
	PeacockHeadTop.points[2].z = OriginPeacock.z + 0.00f;

	PeacockHeadTop.points[3].x = OriginPeacock.x + 0.001f;
	PeacockHeadTop.points[3].y = OriginPeacock.y + 0.65f;
	PeacockHeadTop.points[3].z = OriginPeacock.z + 0.00f;
	//Draw Tura(Head Design)
	glColor3f(0.917f, 0.823f, 0.545f);
	glBegin(GL_POLYGON);
	glVertex3f(PeacockHeadTop.points[0].x, PeacockHeadTop.points[0].y, 0.0f); //Bottom Left
	glVertex3f(PeacockHeadTop.points[1].x, PeacockHeadTop.points[1].y, 0.0f);
	glVertex3f(PeacockHeadTop.points[2].x, PeacockHeadTop.points[2].y, 0.0f);
	glVertex3f(PeacockHeadTop.points[3].x, PeacockHeadTop.points[3].y, 0.0f);
	glEnd();
	
	PeacockHead.color.rValue = 0.005f;
	PeacockHead.color.gValue = 0.182f;
	PeacockHead.color.bValue = 0.825f;
	PeacockHead.color.rValue = 1.000f;
	
	PeacockHead.points[0].x = OriginPeacock.x + (-0.02f);
	PeacockHead.points[0].y = OriginPeacock.y + 0.50f;
	PeacockHead.points[0].z = OriginPeacock.z + 0.00f;
	
	PeacockHead.points[1].x = OriginPeacock.x + (-0.04f);
	PeacockHead.points[1].y = OriginPeacock.y + 0.55f;
	PeacockHead.points[1].z = OriginPeacock.z + 0.00f;
	
	PeacockHead.points[2].x = OriginPeacock.x + (-0.02f);
	PeacockHead.points[2].y = OriginPeacock.y + 0.65f;
	PeacockHead.points[2].z = OriginPeacock.z + 0.00f;
	
	PeacockHead.points[3].x = OriginPeacock.x + 0.02f;
	PeacockHead.points[3].y = OriginPeacock.y + 0.65f;
	PeacockHead.points[3].z = OriginPeacock.z + 0.00f;

	PeacockHead.points[4].x = OriginPeacock.x + 0.04f;
	PeacockHead.points[4].y = OriginPeacock.y + 0.55f;
	PeacockHead.points[4].z = OriginPeacock.z + 0.00f;

	PeacockHead.points[5].x = OriginPeacock.x + 0.02f;
	PeacockHead.points[5].y = OriginPeacock.y + 0.50f;
	PeacockHead.points[5].z = OriginPeacock.z + 0.00f;


	glColor3f(0.005f, 0.182f, 0.825f);
	glBegin(GL_POLYGON);
	glVertex3f(PeacockHead.points[0].x, PeacockHead.points[0].y, 0.0f); //Bottom Left
	glVertex3f(PeacockHead.points[1].x, PeacockHead.points[1].y, 0.0f);
	glVertex3f(PeacockHead.points[2].x, PeacockHead.points[2].y, 0.0f);
	glVertex3f(PeacockHead.points[3].x, PeacockHead.points[3].y, 0.0f);
	glVertex3f(PeacockHead.points[4].x, PeacockHead.points[4].y, 0.0f);
	glVertex3f(PeacockHead.points[5].x, PeacockHead.points[5].y, 0.0f);
	glEnd();
}

void drawEyesAndNose(MY_POINT OriginPeacock)
{
	SHAPE PeacockEyesNose;
	PeacockEyesNose.noOfPoints = 5;
	//Draw Eyes
	//Left Eye
	drawCircleWithColor(OriginPeacock.x + -0.02, OriginPeacock.y + 0.60, 0.015, 0.015, 00.0f, 00.0f, 00.0f, 1, 1);
	drawCircleWithColor(OriginPeacock.x + -0.02, OriginPeacock.y + 0.60, 0.005, 0.005, 01.0f, 01.0f, 01.0f, 1, 1);

	//Right Eye
	drawCircleWithColor(OriginPeacock.x + 0.02, OriginPeacock.y + 0.60, 0.015, 0.015, 00.0f, 00.0f, 00.0f, 1, 1);
	drawCircleWithColor(OriginPeacock.x + 0.02, OriginPeacock.y + 0.60, 0.005, 0.005, 01.0f, 01.0f, 01.0f, 1, 1);

	PeacockEyesNose.color.rValue = 0.878f;
	PeacockEyesNose.color.gValue = 0.807f;
	PeacockEyesNose.color.bValue = 0.878f;
	PeacockEyesNose.color.rValue = 1.000f;

	PeacockEyesNose.points[0].x = OriginPeacock.x + (0.00f);
	PeacockEyesNose.points[0].y = OriginPeacock.y + 0.50f;
	PeacockEyesNose.points[0].z = OriginPeacock.z + 0.00f;
	
	PeacockEyesNose.points[1].x = OriginPeacock.x + (-0.02f);
	PeacockEyesNose.points[1].y = OriginPeacock.y + 0.55f;
	PeacockEyesNose.points[1].z = OriginPeacock.z + 0.00f;
	
	PeacockEyesNose.points[2].x = OriginPeacock.x + (-0.01f);
	PeacockEyesNose.points[2].y = OriginPeacock.y + 0.60f;
	PeacockEyesNose.points[2].z = OriginPeacock.z + 0.00f;
	
	PeacockEyesNose.points[3].x = OriginPeacock.x + 0.01f;
	PeacockEyesNose.points[3].y = OriginPeacock.y + 0.60f;
	PeacockEyesNose.points[3].z = OriginPeacock.z + 0.00f;
	
	PeacockEyesNose.points[4].x = OriginPeacock.x + 0.02f;
	PeacockEyesNose.points[4].y = OriginPeacock.y + 0.55f;
	PeacockEyesNose.points[4].z = OriginPeacock.z + 0.00f;

	//DrawNose
	glColor3f(0.878f, 0.807f, 0.878f);
	glBegin(GL_POLYGON);
	glVertex3f(PeacockEyesNose.points[0].x, PeacockEyesNose.points[0].y, 0.0f); //Bottom Left
	glVertex3f(PeacockEyesNose.points[1].x, PeacockEyesNose.points[1].y, 0.0f);
	glVertex3f(PeacockEyesNose.points[2].x, PeacockEyesNose.points[2].y, 0.0f);
	glVertex3f(PeacockEyesNose.points[3].x, PeacockEyesNose.points[3].y, 0.0f);
	glVertex3f(PeacockEyesNose.points[4].x, PeacockEyesNose.points[4].y, 0.0f);
	glEnd();  
}

void drawNeck(MY_POINT OriginPeacock)
{
	//Draw Neck
	SHAPE Peacockneck;
	Peacockneck.noOfPoints = 4;

	Peacockneck.color.rValue = 0.035f;
	Peacockneck.color.gValue = 0.282f;
	Peacockneck.color.bValue = 0.925f;
	Peacockneck.color.rValue = 1.000f;

	Peacockneck.points[0].x = OriginPeacock.x + (-0.07f);
	Peacockneck.points[0].y = OriginPeacock.y + 0.00f;
	Peacockneck.points[0].z = OriginPeacock.z + 0.00f;

	Peacockneck.points[1].x = OriginPeacock.x + (-0.02f);
	Peacockneck.points[1].y = OriginPeacock.y + 0.50f;
	Peacockneck.points[1].z = OriginPeacock.z + 0.00f;

	Peacockneck.points[2].x = OriginPeacock.x + 0.02f;
	Peacockneck.points[2].y = OriginPeacock.y + 0.50f;
	Peacockneck.points[2].z = OriginPeacock.z + 0.00f;

	Peacockneck.points[3].x = OriginPeacock.x + 0.07f;
	Peacockneck.points[3].y = OriginPeacock.y + 0.00f;
	Peacockneck.points[3].z = OriginPeacock.z + 0.00f;


	glColor3f(0.035f, 0.282f, 0.925f);
	glBegin(GL_POLYGON);
	glVertex3f(Peacockneck.points[0].x, Peacockneck.points[0].y, 0.0f); //Bottom Left
	glVertex3f(Peacockneck.points[1].x, Peacockneck.points[1].y, 0.0f);
	glVertex3f(Peacockneck.points[2].x, Peacockneck.points[2].y, 0.0f);
	glVertex3f(Peacockneck.points[3].x, Peacockneck.points[3].y, 0.0f);
	glEnd();
}

void drawBody(MY_POINT OriginPeacock)
{
	SHAPE PeacockLeftBody;
	PeacockLeftBody.noOfPoints = 3;

	SHAPE PeacockRightBody;
	PeacockRightBody.noOfPoints = 3;

	PeacockLeftBody.points[0].x = OriginPeacock.x + (-0.11f);
	PeacockLeftBody.points[0].y = OriginPeacock.y + 0.05f;
	PeacockLeftBody.points[0].z = OriginPeacock.z + 0.00f;

	PeacockLeftBody.points[1].x = OriginPeacock.x + (-0.02f);
	PeacockLeftBody.points[1].y = OriginPeacock.y + 0.50f;
	PeacockLeftBody.points[1].z = OriginPeacock.z + 0.00f;

	PeacockLeftBody.points[2].x = OriginPeacock.x + (-0.07f);
	PeacockLeftBody.points[2].y = OriginPeacock.y + 0.00f;
	PeacockLeftBody.points[2].z = OriginPeacock.z + 0.00f;

	PeacockRightBody.points[0].x = OriginPeacock.x + (0.11f);
	PeacockRightBody.points[0].y = OriginPeacock.y + 0.05f;
	PeacockRightBody.points[0].z = OriginPeacock.z + 0.00f;

	PeacockRightBody.points[1].x = OriginPeacock.x + (0.02f);
	PeacockRightBody.points[1].y = OriginPeacock.y + 0.50f;
	PeacockRightBody.points[1].z = OriginPeacock.z + 0.00f;

	PeacockRightBody.points[2].x = OriginPeacock.x + (0.07f);
	PeacockRightBody.points[2].y = OriginPeacock.y + 0.00f;
	PeacockRightBody.points[2].z = OriginPeacock.z + 0.00f;

	//DrawLeftBody
	glBegin(GL_TRIANGLES);
	glColor3f(0.047f, 0.556f, 0.658f);
	//glVertex3f(fOriginX + -0.11f, fOriginY + 0.05f, 0.0f); //Bottom Left
	glVertex3f(PeacockLeftBody.points[0].x, PeacockLeftBody.points[0].y, 0.0f); //Bottom Left
	glColor3f(0.00f, 0.360f, 0.560f);
	//glVertex3f(fOriginX + -0.02f, fOriginY + 0.50f, 0.0f);
	glVertex3f(PeacockLeftBody.points[1].x, PeacockLeftBody.points[1].y, 0.0f);
	glColor3f(0.031f, 0.588f, 0.690f);
	//glVertex3f(fOriginX + -0.07f, fOriginY + 0.00f, 0.0f);
	glVertex3f(PeacockLeftBody.points[2].x, PeacockLeftBody.points[2].y, 0.0f);
	glEnd();

	//DrawRightBody
	glBegin(GL_TRIANGLES);
	glColor3f(0.047f, 0.556f, 0.658f);
	//glVertex3f(fOriginX + 0.11f, fOriginY + 0.05f, 0.0f); //Bottom Left
	glVertex3f(PeacockRightBody.points[0].x, PeacockRightBody.points[0].y, 0.0f); //Bottom Left
	glColor3f(0.00f, 0.360f, 0.560f);
	//glVertex3f(fOriginX + 0.02f, fOriginY + 0.50f, 0.0f);
	glVertex3f(PeacockRightBody.points[1].x, PeacockRightBody.points[1].y, 0.0f);
	glColor3f(0.031f, 0.588f, 0.690f);
	//glVertex3f(fOriginX + 0.07f, fOriginY + 0.00f, 0.0f);
	glVertex3f(PeacockRightBody.points[2].x, PeacockRightBody.points[2].y, 0.0f);
	glEnd();

}

void drawLegs(MY_POINT OriginPeacock)
{

	SHAPE PeacockLeftUpperLeg;
	PeacockLeftUpperLeg.noOfPoints = 3;

	SHAPE PeacockRightUpperLeg;
	PeacockRightUpperLeg.noOfPoints = 3;

	SHAPE PeacockLeftLowerLeg;
	PeacockLeftLowerLeg.noOfPoints = 3;

	SHAPE PeacockRightLowerLeg;
	PeacockRightLowerLeg.noOfPoints = 3;

	PeacockLeftUpperLeg.points[0].x = OriginPeacock.x + (-0.07f);
	PeacockLeftUpperLeg.points[0].y = OriginPeacock.y + (- 0.20f);
	PeacockLeftUpperLeg.points[0].z = OriginPeacock.z + 0.00f;

	PeacockLeftUpperLeg.points[1].x = OriginPeacock.x + (-0.11f);
	PeacockLeftUpperLeg.points[1].y = OriginPeacock.y + 0.05f;
	PeacockLeftUpperLeg.points[1].z = OriginPeacock.z + 0.00f;

	PeacockLeftUpperLeg.points[2].x = OriginPeacock.x + (-0.07f);
	PeacockLeftUpperLeg.points[2].y = OriginPeacock.y + 0.00f;
	PeacockLeftUpperLeg.points[2].z = OriginPeacock.z + 0.00f;

	//DrawLeftLegUpperPart
	glBegin(GL_TRIANGLES);
	glColor3f(0.917f, 0.823f, 0.545f);
	glVertex3f(PeacockLeftUpperLeg.points[0].x, PeacockLeftUpperLeg.points[0].y, 0.0f); //Bottom Left
	glVertex3f(PeacockLeftUpperLeg.points[1].x, PeacockLeftUpperLeg.points[1].y, 0.0f); //Bottom Left
	glVertex3f(PeacockLeftUpperLeg.points[2].x, PeacockLeftUpperLeg.points[2].y, 0.0f); //Bottom Left
	glEnd();

	PeacockRightUpperLeg.points[0].x = OriginPeacock.x + (0.07f);
	PeacockRightUpperLeg.points[0].y = OriginPeacock.y + (-0.20f);
	PeacockRightUpperLeg.points[0].z = OriginPeacock.z + 0.00f;

	PeacockRightUpperLeg.points[1].x = OriginPeacock.x + (0.11f);
	PeacockRightUpperLeg.points[1].y = OriginPeacock.y + 0.05f;
	PeacockRightUpperLeg.points[1].z = OriginPeacock.z + 0.00f;

	PeacockRightUpperLeg.points[2].x = OriginPeacock.x + (0.07f);
	PeacockRightUpperLeg.points[2].y = OriginPeacock.y + 0.00f;
	PeacockRightUpperLeg.points[2].z = OriginPeacock.z + 0.00f;

	//DrawLeftLegUpperPart
	glBegin(GL_TRIANGLES);
	glColor3f(0.917f, 0.823f, 0.545f);
	glVertex3f(PeacockRightUpperLeg.points[0].x, PeacockRightUpperLeg.points[0].y, 0.0f); //Bottom Left
	glVertex3f(PeacockRightUpperLeg.points[1].x, PeacockRightUpperLeg.points[1].y, 0.0f); //Bottom Left
	glVertex3f(PeacockRightUpperLeg.points[2].x, PeacockRightUpperLeg.points[2].y, 0.0f); //Bottom Left
	glEnd();
	

	PeacockLeftLowerLeg.points[0].x = OriginPeacock.x + (-0.07f);
	PeacockLeftLowerLeg.points[0].y = OriginPeacock.y + (-0.20f);
	PeacockLeftLowerLeg.points[0].z = OriginPeacock.z + 0.00f;

	PeacockLeftLowerLeg.points[1].x = OriginPeacock.x + (-0.14f);
	PeacockLeftLowerLeg.points[1].y = OriginPeacock.y + (-0.20f);
	PeacockLeftLowerLeg.points[1].z = OriginPeacock.z + 0.00f;

	PeacockLeftLowerLeg.points[2].x = OriginPeacock.x + (-0.10f);
	PeacockLeftLowerLeg.points[2].y = OriginPeacock.y + (-0.25f);
	PeacockLeftLowerLeg.points[2].z = OriginPeacock.z + 0.00f;

	//DrawLeftLegUpperPart
	glBegin(GL_TRIANGLES);
	glColor3f(0.917f, 0.823f, 0.545f);
	glVertex3f(PeacockLeftLowerLeg.points[0].x, PeacockLeftLowerLeg.points[0].y, 0.0f); //Bottom Left
	glVertex3f(PeacockLeftLowerLeg.points[1].x, PeacockLeftLowerLeg.points[1].y, 0.0f); //Bottom Left
	glVertex3f(PeacockLeftLowerLeg.points[2].x, PeacockLeftLowerLeg.points[2].y, 0.0f); //Bottom Left
	glEnd();

	PeacockRightLowerLeg.points[0].x = OriginPeacock.x + (0.07f);
	PeacockRightLowerLeg.points[0].y = OriginPeacock.y + (-0.20f);
	PeacockRightLowerLeg.points[0].z = OriginPeacock.z + 0.00f;

	PeacockRightLowerLeg.points[1].x = OriginPeacock.x + (0.14f);
	PeacockRightLowerLeg.points[1].y = OriginPeacock.y + (-0.20f);
	PeacockRightLowerLeg.points[1].z = OriginPeacock.z + 0.00f;

	PeacockRightLowerLeg.points[2].x = OriginPeacock.x + (0.10f);
	PeacockRightLowerLeg.points[2].y = OriginPeacock.y + (-0.25f);
	PeacockRightLowerLeg.points[2].z = OriginPeacock.z + 0.00f;

	//DrawLeftLegUpperPart
	glBegin(GL_TRIANGLES);
	glColor3f(0.917f, 0.823f, 0.545f);
	glVertex3f(PeacockRightLowerLeg.points[0].x, PeacockRightLowerLeg.points[0].y, 0.0f); //Bottom Left
	glVertex3f(PeacockRightLowerLeg.points[1].x, PeacockRightLowerLeg.points[1].y, 0.0f); //Bottom Left
	glVertex3f(PeacockRightLowerLeg.points[2].x, PeacockRightLowerLeg.points[2].y, 0.0f); //Bottom Left
	glEnd();
}

void drawWings(MY_POINT OriginPeacock)
{
	SHAPE Wings, WingDesignYellowPoly, WingDesignGreenPoly, WingDesignPurplePoly;
	COLOR WingColor[4];

	float fAngle = -9.3718;
	int  iCounter = 6;

	Wings.noOfPoints = 3;
	
	Wings.points[0].x = 0.00f;
	Wings.points[0].y = 0.00f;
	Wings.points[0].z = 0.00f;

	Wings.points[1].x = -0.60f;
	Wings.points[1].y = -0.10f;
	Wings.points[1].z = 0.00f;

	Wings.points[2].x = -0.70f;
	Wings.points[2].y = 0.00f;
	Wings.points[2].z = 0.00f;

	Wings.points[3].x = -0.60f;
	Wings.points[3].y = 0.10f;
	Wings.points[3].z = 0.00f;

	WingColor[0].rValue = 0.223f;
	WingColor[0].gValue = 0.717f;
	WingColor[0].bValue = 0.337f;
	WingColor[0].aValue = 1.0f;
	
	WingColor[1].rValue = 0.603f;
	WingColor[1].gValue = 0.815f;
	WingColor[1].bValue = 0.384f;
	WingColor[1].aValue = 1.0f;
	
	WingColor[2].rValue = 0.482f;
	WingColor[2].gValue = 0.725f;
	WingColor[2].bValue = 0.286f;
	WingColor[2].aValue = 1.0f;

	WingColor[3].rValue = 0.482f;
	WingColor[3].gValue = 0.725f;
	WingColor[3].bValue = 0.286f;
	WingColor[3].aValue = 1.0f;
	

	//Draw Yellow Polygon in Feathers
	WingDesignYellowPoly.points[0].x = -0.50f;
	WingDesignYellowPoly.points[0].y = -0.06f;
	WingDesignYellowPoly.points[0].z = 0.00f;

	WingDesignYellowPoly.points[1].x = -0.60f;
	WingDesignYellowPoly.points[1].y = -0.07f;
	WingDesignYellowPoly.points[1].z = 0.00f;

	WingDesignYellowPoly.points[2].x = -0.68f;
	WingDesignYellowPoly.points[2].y = 0.00f;
	WingDesignYellowPoly.points[2].z = 0.00f;

	WingDesignYellowPoly.points[3].x = -0.60f;
	WingDesignYellowPoly.points[3].y = 0.07f;
	WingDesignYellowPoly.points[3].z = 0.00f;

	WingDesignYellowPoly.points[4].x = -0.50f;
	WingDesignYellowPoly.points[4].y = 0.06f;
	WingDesignYellowPoly.points[4].z = 0.00f;

	//Draw Green Polygon in Feathers
	WingDesignGreenPoly.points[0].x = WingDesignYellowPoly.points[0].x + -0.015f;
	WingDesignGreenPoly.points[0].y = WingDesignYellowPoly.points[0].y +  0.020f;
	WingDesignGreenPoly.points[0].z = WingDesignYellowPoly.points[0].z +  0.00f;

	WingDesignGreenPoly.points[1].x = WingDesignYellowPoly.points[1].x +  0.00f;
	WingDesignGreenPoly.points[1].y = WingDesignYellowPoly.points[1].y +  0.020f;
	WingDesignGreenPoly.points[1].z = WingDesignYellowPoly.points[1].z +  0.00f;

	WingDesignGreenPoly.points[2].x = WingDesignYellowPoly.points[2].x +  0.020f;
	WingDesignGreenPoly.points[2].y = WingDesignYellowPoly.points[2].y +  0.00f;
	WingDesignGreenPoly.points[2].z = WingDesignYellowPoly.points[2].z +  0.00f;
	
	WingDesignGreenPoly.points[3].x = WingDesignYellowPoly.points[3].x +  0.00f;
	WingDesignGreenPoly.points[3].y = WingDesignYellowPoly.points[3].y + -0.020f;
	WingDesignGreenPoly.points[3].z = WingDesignYellowPoly.points[3].z +  0.00f;
	
	WingDesignGreenPoly.points[4].x = WingDesignYellowPoly.points[4].x + -0.015f;
	WingDesignGreenPoly.points[4].y = WingDesignYellowPoly.points[4].y + -0.020f;
	WingDesignGreenPoly.points[4].z = WingDesignYellowPoly.points[4].z +  0.00f;

	//Draw Purple Polygon in Feathers
	WingDesignPurplePoly.points[0].x = WingDesignGreenPoly.points[0].x + -0.015f;
	WingDesignPurplePoly.points[0].y = WingDesignGreenPoly.points[0].y +  0.015f; 
	WingDesignPurplePoly.points[0].z = WingDesignGreenPoly.points[0].z +  0.00f; 

	WingDesignPurplePoly.points[1].x = WingDesignGreenPoly.points[1].x +  0.015f; 
	WingDesignPurplePoly.points[1].y = WingDesignGreenPoly.points[1].y +  0.020f; 
	WingDesignPurplePoly.points[1].z = WingDesignGreenPoly.points[1].z +  0.00f; 

	WingDesignPurplePoly.points[2].x = WingDesignGreenPoly.points[2].x +  0.025f; 
	WingDesignPurplePoly.points[2].y = WingDesignGreenPoly.points[2].y +  0.00f; 
	WingDesignPurplePoly.points[2].z = WingDesignGreenPoly.points[2].z +  0.00f; 

	WingDesignPurplePoly.points[3].x = WingDesignGreenPoly.points[3].x +  0.015f; 
	WingDesignPurplePoly.points[3].y = WingDesignGreenPoly.points[3].y + -0.020f;
	WingDesignPurplePoly.points[3].z = WingDesignGreenPoly.points[3].z +  0.00f; 

	WingDesignPurplePoly.points[4].x = WingDesignGreenPoly.points[4].x + -0.015f;
	WingDesignPurplePoly.points[4].y = WingDesignGreenPoly.points[4].y + -0.015f;
	WingDesignPurplePoly.points[4].z = WingDesignGreenPoly.points[4].z +  0.00f; 
	

	for (int iNoOfWings = 1; iNoOfWings <= 9; iNoOfWings = iNoOfWings + 1)
	{

		glBegin(GL_TRIANGLE_FAN);
		for (int iShape = 0; iShape <= 3; iShape = iShape + 1)
		{
			
			glColor3f(WingColor[iShape].rValue, WingColor[iShape].gValue, WingColor[iShape].bValue);
			glVertex3f(rotatePoint(Wings.points[iShape], fAngle * iCounter).x, rotatePoint(Wings.points[iShape], fAngle * iCounter).y, Wings.points[iShape].z); //Origin 
		}
		glEnd();

		glBegin(GL_POLYGON);
		for (int iShape = 0; iShape <= 4; iShape = iShape + 1)
		{

			//glColor3f(WingColor[iShape].rValue, WingColor[iShape].gValue, WingColor[iShape].bValue);
			glColor3f(0.784f, 0.788f, 0.321f); //Shade of Yellow
			glVertex3f(rotatePoint(WingDesignYellowPoly.points[iShape], fAngle * iCounter).x, rotatePoint(WingDesignYellowPoly.points[iShape], fAngle * iCounter).y, WingDesignYellowPoly.points[iShape].z); //Origin 
		}
		glEnd();

		glBegin(GL_POLYGON);
		for (int iShape = 0; iShape <= 4; iShape = iShape + 1)
		{

			//glColor3f(WingColor[iShape].rValue, WingColor[iShape].gValue, WingColor[iShape].bValue);
			glColor3f(0.082f, 0.478f, 0.631f); //Shade of Yellow
			glVertex3f(rotatePoint(WingDesignGreenPoly.points[iShape], fAngle * iCounter).x, rotatePoint(WingDesignGreenPoly.points[iShape], fAngle * iCounter).y, WingDesignGreenPoly.points[iShape].z); //Origin 
		}
		glEnd();

		glBegin(GL_POLYGON);
		for (int iShape = 0; iShape <= 4; iShape = iShape + 1)
		{

			//glColor3f(WingColor[iShape].rValue, WingColor[iShape].gValue, WingColor[iShape].bValue);
			glColor3f(0.254f, 0.258f, 0.623f); //Shade of Yellow
			glVertex3f(rotatePoint(WingDesignPurplePoly.points[iShape], fAngle * iCounter).x, rotatePoint(WingDesignPurplePoly.points[iShape], fAngle * iCounter).y, WingDesignPurplePoly.points[iShape].z); //Origin 
		}
		glEnd();

		iCounter += 6;
	}

}

void drawCircleWithColor(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, float alpha, int fill)
{
	float ObjX = 0.0f;
	float ObjY = 0.0f;
	float ObjAngle = 0.0f;

	// Circle
	if (fill == 1) {
		glBegin(GL_POLYGON);
	}
	else {
		glBegin(GL_POINTS);
	}

	for (ObjAngle = (0.00f); ObjAngle <= (2.0f * PI); ObjAngle += 0.01f)

	{
		ObjX = x + radius_hor * sin(ObjAngle);
		ObjY = y + radius_vert * cos(ObjAngle);

		glColor4f(r, g, b, alpha);

		glVertex2f(ObjX, ObjY);
	}


	glEnd();

}
