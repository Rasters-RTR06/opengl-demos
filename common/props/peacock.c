
//Use drawPeacock() function to 

//User Defined global function declarations
void drawPeacock(float originx, float originy, float resize);
void drawPeacockNeck(MY_POINT OriginPeacock, float resize);
void drawPeacockHead(MY_POINT OriginPeacock, float resize);
void drawPeacockEyesAndNose(MY_POINT OriginPeacock, float resize);
void drawPeacockBody(MY_POINT OriginPeacock, float resize);
void drawPeacockLegs(MY_POINT OriginPeacock, float resize);

void drawPeacockWings(MY_POINT OriginPeacock, float resize);

void drawCircleWithColor_Peacock(float, float, float, float, float, float, float, float, int, float resize);

void drawPeacock(float originx, float originy, float resize)
{
	MY_POINT OriginPeacock;
	OriginPeacock.x = originx;
	OriginPeacock.y = originy;
	OriginPeacock.z = 0.0;
	
	//float originx, float originy, float resize;

	drawPeacockWings(OriginPeacock, resize);

	drawPeacockHead(OriginPeacock, resize);
	drawPeacockEyesAndNose(OriginPeacock, resize);
	drawPeacockNeck(OriginPeacock, resize);
	drawPeacockBody(OriginPeacock, resize);
	drawPeacockLegs(OriginPeacock, resize);
}

void drawPeacockHead(MY_POINT OriginPeacock, float resize)
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
	glVertex3f(PeacockHeadTop.points[0].x * resize, PeacockHeadTop.points[0].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockHeadTop.points[1].x * resize, PeacockHeadTop.points[1].y * resize, 0.0f * resize);
	glVertex3f(PeacockHeadTop.points[2].x * resize, PeacockHeadTop.points[2].y * resize, 0.0f * resize);
	glVertex3f(PeacockHeadTop.points[3].x * resize, PeacockHeadTop.points[3].y * resize, 0.0f * resize);
	glEnd();

	PeacockHead.color.rValue = 0.005f;
	PeacockHead.color.gValue = 0.182f;
	PeacockHead.color.bValue = 0.825f;
	PeacockHead.color.rValue = 1.000f;

	drawCircleWithColor_Peacock(OriginPeacock.x * resize + -0.0, OriginPeacock.y * resize + 0.55, 0.09, 0.030, 0.005f, 00.182f, 00.825f, 1, 1, resize);




}

void drawPeacockEyesAndNose(MY_POINT OriginPeacock, float resize)
{
	SHAPE PeacockEyesNose;
	PeacockEyesNose.noOfPoints = 5;
	//Draw Eyes
	//Left Eye
	drawCircleWithColor_Peacock(OriginPeacock.x * resize + -0.02, OriginPeacock.y * resize + 0.60, 0.010, 0.010, 01.0f, 01.0f, 01.0f, 1, 1, resize);
	drawCircleWithColor_Peacock(OriginPeacock.x * resize + -0.02, OriginPeacock.y * resize + 0.60, 0.005, 0.005, 00.0f, 00.0f, 00.0f, 1, 1, resize);

	//Right Eye
	drawCircleWithColor_Peacock(OriginPeacock.x * resize + 0.02, OriginPeacock.y * resize + 0.60, 0.010, 0.010, 01.0f, 01.0f, 01.0f, 1, 1, resize);
	drawCircleWithColor_Peacock(OriginPeacock.x * resize + 0.02, OriginPeacock.y * resize + 0.60, 0.005, 0.005, 00.0f, 00.0f, 00.0f, 1, 1, resize);

	PeacockEyesNose.color.rValue = 0.878f;
	PeacockEyesNose.color.gValue = 0.807f;
	PeacockEyesNose.color.bValue = 0.878f;

	PeacockEyesNose.points[0].x = OriginPeacock.x + (0.00f);
	PeacockEyesNose.points[0].y = OriginPeacock.y + 0.52f;
	PeacockEyesNose.points[0].z = OriginPeacock.z + 0.00f;

	PeacockEyesNose.points[1].x = OriginPeacock.x + (-0.015f);
	PeacockEyesNose.points[1].y = OriginPeacock.y + 0.55f;
	PeacockEyesNose.points[1].z = OriginPeacock.z + 0.00f;

	PeacockEyesNose.points[2].x = OriginPeacock.x + (-0.001f);
	PeacockEyesNose.points[2].y = OriginPeacock.y + 0.60f;
	PeacockEyesNose.points[2].z = OriginPeacock.z + 0.00f;

	PeacockEyesNose.points[3].x = OriginPeacock.x + 0.001f;
	PeacockEyesNose.points[3].y = OriginPeacock.y + 0.60f;
	PeacockEyesNose.points[3].z = OriginPeacock.z + 0.00f;

	PeacockEyesNose.points[4].x = OriginPeacock.x + 0.015f;
	PeacockEyesNose.points[4].y = OriginPeacock.y + 0.55f;
	PeacockEyesNose.points[4].z = OriginPeacock.z + 0.00f;

	//DrawNose
	glColor3f(0.878f, 0.807f, 0.878f);
	glBegin(GL_POLYGON);
	glVertex3f(PeacockEyesNose.points[0].x * resize, PeacockEyesNose.points[0].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockEyesNose.points[1].x * resize, PeacockEyesNose.points[1].y * resize, 0.0f * resize);
	glVertex3f(PeacockEyesNose.points[2].x * resize, PeacockEyesNose.points[2].y * resize, 0.0f * resize);
	glVertex3f(PeacockEyesNose.points[3].x * resize, PeacockEyesNose.points[3].y * resize, 0.0f * resize);
	glVertex3f(PeacockEyesNose.points[4].x * resize, PeacockEyesNose.points[4].y * resize, 0.0f * resize);
	glEnd();
}

void drawPeacockNeck(MY_POINT OriginPeacock, float resize)
{
	//Draw Neck
	SHAPE Peacockneck;
	Peacockneck.noOfPoints = 4;

	Peacockneck.color.rValue = 0.035f;
	Peacockneck.color.gValue = 0.282f;
	Peacockneck.color.bValue = 0.925f;
	Peacockneck.color.rValue = 1.000f;

	Peacockneck.points[0].x = OriginPeacock.x + (-0.02f);
	Peacockneck.points[0].y = OriginPeacock.y + 0.00f;
	Peacockneck.points[0].z = OriginPeacock.z + 0.00f;

	Peacockneck.points[1].x = OriginPeacock.x + (-0.02f);
	Peacockneck.points[1].y = OriginPeacock.y + 0.50f;
	Peacockneck.points[1].z = OriginPeacock.z + 0.00f;

	Peacockneck.points[2].x = OriginPeacock.x + 0.02f;
	Peacockneck.points[2].y = OriginPeacock.y + 0.50f;
	Peacockneck.points[2].z = OriginPeacock.z + 0.00f;

	Peacockneck.points[3].x = OriginPeacock.x + 0.02f;
	Peacockneck.points[3].y = OriginPeacock.y + 0.00f;
	Peacockneck.points[3].z = OriginPeacock.z + 0.00f;


	glBegin(GL_POLYGON);
	glColor3f(0.035f, 0.282f, 0.925f);
	glVertex3f(Peacockneck.points[0].x * resize, Peacockneck.points[0].y * resize, 0.0f * resize); //Bottom Left
	glColor3f(0.007f, 0.16f, 0.282f);
	glVertex3f(Peacockneck.points[1].x * resize, Peacockneck.points[1].y * resize, 0.0f * resize);
	glColor3f(0.007f, 0.16f, 0.282f);
	glVertex3f(Peacockneck.points[2].x * resize, Peacockneck.points[2].y * resize, 0.0f * resize);
	glColor3f(0.035f, 0.282f, 0.925f);
	glVertex3f(Peacockneck.points[3].x * resize, Peacockneck.points[3].y * resize, 0.0f * resize);
	glEnd();
}

void drawPeacockBody(MY_POINT OriginPeacock, float resize)
{
	SHAPE PeacockLeftBody;
	PeacockLeftBody.noOfPoints = 3;

	SHAPE PeacockRightBody;
	PeacockRightBody.noOfPoints = 3;

	PeacockLeftBody.points[0].x = OriginPeacock.x + (-0.07f);
	PeacockLeftBody.points[0].y = OriginPeacock.y + 0.05f;
	PeacockLeftBody.points[0].z = OriginPeacock.z + 0.00f;

	PeacockLeftBody.points[1].x = OriginPeacock.x + (-0.02f);
	PeacockLeftBody.points[1].y = OriginPeacock.y + 0.50f;
	PeacockLeftBody.points[1].z = OriginPeacock.z + 0.00f;

	PeacockLeftBody.points[2].x = OriginPeacock.x + (-0.02f);
	PeacockLeftBody.points[2].y = OriginPeacock.y + 0.00f;
	PeacockLeftBody.points[2].z = OriginPeacock.z + 0.00f;

	PeacockRightBody.points[0].x = OriginPeacock.x + (0.07f);
	PeacockRightBody.points[0].y = OriginPeacock.y + 0.05f;
	PeacockRightBody.points[0].z = OriginPeacock.z + 0.00f;

	PeacockRightBody.points[1].x = OriginPeacock.x + (0.02f);
	PeacockRightBody.points[1].y = OriginPeacock.y + 0.50f;
	PeacockRightBody.points[1].z = OriginPeacock.z + 0.00f;

	PeacockRightBody.points[2].x = OriginPeacock.x + (0.02f);
	PeacockRightBody.points[2].y = OriginPeacock.y + 0.00f;
	PeacockRightBody.points[2].z = OriginPeacock.z + 0.00f;

	drawCircleWithColor_Peacock(OriginPeacock.x * resize + -0.09, OriginPeacock.y * resize + -0.15, 0.080, 0.0950, 0.403f, 0.235f, 0.023f, 1, 1, resize);
	drawCircleWithColor_Peacock(OriginPeacock.x * resize + 0.09, OriginPeacock.y * resize + -0.15, 0.080, 0.0950, 0.403f, 0.235f, 0.023f, 1, 1, resize);


	drawCircleWithColor_Peacock(OriginPeacock.x * resize + -0.06, OriginPeacock.y * resize + -0.10, 0.120, 0.090, 0.984f, 0.737f, 0.023f, 1, 1, resize);
	drawCircleWithColor_Peacock(OriginPeacock.x * resize + 0.06, OriginPeacock.y * resize + -0.10, 0.120, 0.090, 0.984f, 0.737f, 0.023f, 1, 1, resize);


	//DrawLeftBody
	glBegin(GL_TRIANGLES);
	glColor3f(0.047f, 0.556f, 0.658f);
	//glVertex3f(fOriginX + -0.11f, fOriginY + 0.05f, 0.0f); //Bottom Left
	glVertex3f(PeacockLeftBody.points[0].x * resize, PeacockLeftBody.points[0].y * resize, 0.0f); //Bottom Left
	glColor3f(0.00f, 0.360f, 0.560f);
	//glVertex3f(fOriginX + -0.02f, fOriginY + 0.50f, 0.0f);
	glVertex3f(PeacockLeftBody.points[1].x * resize, PeacockLeftBody.points[1].y * resize, 0.0f);
	glColor3f(0.031f, 0.588f, 0.690f);
	//glVertex3f(fOriginX + -0.07f, fOriginY + 0.00f, 0.0f);
	glVertex3f(PeacockLeftBody.points[2].x * resize, PeacockLeftBody.points[2].y * resize, 0.0f);
	glEnd();

	//DrawRightBody
	glBegin(GL_TRIANGLES);
	glColor3f(0.047f, 0.556f, 0.658f);
	//glVertex3f(fOriginX + 0.11f, fOriginY + 0.05f, 0.0f); //Bottom Left
	glVertex3f(PeacockRightBody.points[0].x * resize, PeacockRightBody.points[0].y * resize, 0.0f); //Bottom Left
	glColor3f(0.00f, 0.360f, 0.560f);
	//glVertex3f(fOriginX + 0.02f, fOriginY + 0.50f, 0.0f);
	glVertex3f(PeacockRightBody.points[1].x * resize, PeacockRightBody.points[1].y * resize, 0.0f);
	glColor3f(0.031f, 0.588f, 0.690f);
	//glVertex3f(fOriginX + 0.07f, fOriginY + 0.00f, 0.0f);
	glVertex3f(PeacockRightBody.points[2].x * resize, PeacockRightBody.points[2].y * resize, 0.0f);
	glEnd();


	//Draw Lower Body


	glColor3f(0.135f, 0.282f, 0.925f);
	glBegin(GL_POLYGON);
	glVertex3f(-0.070f * resize, 0.05f  * resize, 0.0f * resize); //Bottom Left
	glVertex3f(-0.15f  * resize, -0.20f * resize, 0.0f * resize); //Bottom Left
	glVertex3f(0.15f   * resize, -0.20f * resize, 0.0f * resize); //Bottom Left
	glVertex3f(0.070f  * resize, 0.05f  * resize, 0.0f * resize); //Bottom Left
	glEnd();


	//Blue Lower body portion
	drawCircleWithColor_Peacock(OriginPeacock.x * resize + -0.06, OriginPeacock.y * resize + -0.20, 0.050, 0.090, 0.135f, 0.282f, 0.925f, 1, 1, resize);
	drawCircleWithColor_Peacock(OriginPeacock.x * resize + 0.06, OriginPeacock.y * resize + -0.20, 0.050, 0.090, 0.135f, 0.282f, 0.925f, 1, 1, resize);

}


void drawPeacockLegs(MY_POINT OriginPeacock, float resize)
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
	PeacockLeftUpperLeg.points[0].y = OriginPeacock.y + (-0.50f);
	PeacockLeftUpperLeg.points[0].z = OriginPeacock.z + 0.00f;

	PeacockLeftUpperLeg.points[1].x = OriginPeacock.x + (-0.11f);
	PeacockLeftUpperLeg.points[1].y = OriginPeacock.y + -0.24f;
	PeacockLeftUpperLeg.points[1].z = OriginPeacock.z + 0.00f;

	PeacockLeftUpperLeg.points[2].x = OriginPeacock.x + (-0.07f);
	PeacockLeftUpperLeg.points[2].y = OriginPeacock.y + -0.25f;
	PeacockLeftUpperLeg.points[2].z = OriginPeacock.z + 0.00f;

	//DrawLeftLegUpperPart
	glBegin(GL_TRIANGLES);
	glColor3f(0.917f, 0.823f, 0.545f);
	glVertex3f(PeacockLeftUpperLeg.points[0].x * resize, PeacockLeftUpperLeg.points[0].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockLeftUpperLeg.points[1].x * resize, PeacockLeftUpperLeg.points[1].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockLeftUpperLeg.points[2].x * resize, PeacockLeftUpperLeg.points[2].y * resize, 0.0f * resize); //Bottom Left
	glEnd();

	PeacockRightUpperLeg.points[0].x = OriginPeacock.x + (0.07f);
	PeacockRightUpperLeg.points[0].y = OriginPeacock.y + (-0.50f);
	PeacockRightUpperLeg.points[0].z = OriginPeacock.z + 0.00f;

	PeacockRightUpperLeg.points[1].x = OriginPeacock.x + (0.11f);
	PeacockRightUpperLeg.points[1].y = OriginPeacock.y + -0.24f;
	PeacockRightUpperLeg.points[1].z = OriginPeacock.z + 0.00f;

	PeacockRightUpperLeg.points[2].x = OriginPeacock.x + (0.07f);
	PeacockRightUpperLeg.points[2].y = OriginPeacock.y + -0.25f;
	PeacockRightUpperLeg.points[2].z = OriginPeacock.z + 0.00f;

	//DrawLeftLegUpperPart
	glBegin(GL_TRIANGLES);
	glColor3f(0.917f, 0.823f, 0.545f);
	glVertex3f(PeacockRightUpperLeg.points[0].x * resize, PeacockRightUpperLeg.points[0].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockRightUpperLeg.points[1].x * resize, PeacockRightUpperLeg.points[1].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockRightUpperLeg.points[2].x * resize, PeacockRightUpperLeg.points[2].y * resize, 0.0f * resize); //Bottom Left
	glEnd();


	PeacockLeftLowerLeg.points[0].x = OriginPeacock.x + (-0.07f);
	PeacockLeftLowerLeg.points[0].y = OriginPeacock.y + (-0.50f);
	PeacockLeftLowerLeg.points[0].z = OriginPeacock.z + 0.00f;

	PeacockLeftLowerLeg.points[1].x = OriginPeacock.x + (-0.14f);
	PeacockLeftLowerLeg.points[1].y = OriginPeacock.y + (-0.50f);
	PeacockLeftLowerLeg.points[1].z = OriginPeacock.z + 0.00f;

	PeacockLeftLowerLeg.points[2].x = OriginPeacock.x + (-0.10f);
	PeacockLeftLowerLeg.points[2].y = OriginPeacock.y + (-0.55f);
	PeacockLeftLowerLeg.points[2].z = OriginPeacock.z + 0.00f;

	//DrawLeftLegUpperPart
	glBegin(GL_TRIANGLES);
	glColor3f(0.917f, 0.823f, 0.545f);
	glVertex3f(PeacockLeftLowerLeg.points[0].x * resize, PeacockLeftLowerLeg.points[0].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockLeftLowerLeg.points[1].x * resize, PeacockLeftLowerLeg.points[1].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockLeftLowerLeg.points[2].x * resize, PeacockLeftLowerLeg.points[2].y * resize, 0.0f * resize); //Bottom Left
	glEnd();

	PeacockRightLowerLeg.points[0].x = OriginPeacock.x + (0.07f);
	PeacockRightLowerLeg.points[0].y = OriginPeacock.y + (-0.50f);
	PeacockRightLowerLeg.points[0].z = OriginPeacock.z + 0.00f;

	PeacockRightLowerLeg.points[1].x = OriginPeacock.x + (0.14f);
	PeacockRightLowerLeg.points[1].y = OriginPeacock.y + (-0.50f);
	PeacockRightLowerLeg.points[1].z = OriginPeacock.z + 0.00f;

	PeacockRightLowerLeg.points[2].x = OriginPeacock.x + (0.10f);
	PeacockRightLowerLeg.points[2].y = OriginPeacock.y + (-0.55f);
	PeacockRightLowerLeg.points[2].z = OriginPeacock.z + 0.00f;

	//DrawLeftLegUpperPart
	glBegin(GL_TRIANGLES);
	glColor3f(0.917f, 0.823f, 0.545f);
	glVertex3f(PeacockRightLowerLeg.points[0].x * resize, PeacockRightLowerLeg.points[0].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockRightLowerLeg.points[1].x * resize, PeacockRightLowerLeg.points[1].y * resize, 0.0f * resize); //Bottom Left
	glVertex3f(PeacockRightLowerLeg.points[2].x * resize, PeacockRightLowerLeg.points[2].y * resize, 0.0f * resize); //Bottom Left
	glEnd();
}

void drawPeacockWings(MY_POINT OriginPeacock, float resize)
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

	SCALING scaleFactorPoint;
	scaleFactorPoint.x = 1.0f;
	scaleFactorPoint.y = 0.0f;
	scaleFactorPoint.z = 0.0f;

	for (scaleFactorPoint.x = 1.3f; scaleFactorPoint.x >= 1.0f; scaleFactorPoint.x = scaleFactorPoint.x - 0.2f)
	{

		for (int iNoOfWings = 1; iNoOfWings <= 9; iNoOfWings = iNoOfWings + 1)
		{

			glBegin(GL_TRIANGLE_FAN);
			for (int iShape = 0; iShape <= 3; iShape = iShape + 1)
			{

				glColor3f(WingColor[iShape].rValue, WingColor[iShape].gValue, WingColor[iShape].bValue);
				glVertex3f(scalePoint(rotatePoint(Wings.points[iShape], fAngle * iCounter), scaleFactorPoint).x * resize, rotatePoint(Wings.points[iShape], fAngle * iCounter).y * resize, Wings.points[iShape].z * resize); //Origin 
				//glVertex3f(scalePoint(rotatePoint(Wings.points[iShape], fAngle * iCounter), scaleFactorPoint).x * resize, rotatePoint(Wings.points[iShape], fAngle * iCounter).y * resize, Wings.points[iShape].z * resize); //Origin 
			}
			glEnd();

			glBegin(GL_POLYGON);
			for (int iShape = 0; iShape <= 4; iShape = iShape + 1)
			{

				//glColor3f(WingColor[iShape].rValue, WingColor[iShape].gValue, WingColor[iShape].bValue);
				glColor3f(0.784f, 0.788f, 0.321f); //Shade of Yellow
				glVertex3f(scalePoint(rotatePoint(WingDesignYellowPoly.points[iShape], fAngle * iCounter), scaleFactorPoint).x * resize, rotatePoint(WingDesignYellowPoly.points[iShape], fAngle * iCounter).y * resize, WingDesignYellowPoly.points[iShape].z * resize); //Origin 
				//glVertex3f(scalePoint(rotatePoint(WingDesignYellowPoly.points[iShape], fAngle * iCounter), scaleFactorPoint).x * resize, rotatePoint(WingDesignYellowPoly.points[iShape], fAngle * iCounter).y * resize, WingDesignYellowPoly.points[iShape].z * resize); //Origin 
			}
			glEnd();

			glBegin(GL_POLYGON);
			for (int iShape = 0; iShape <= 4; iShape = iShape + 1)
			{

				//glColor3f(WingColor[iShape].rValue, WingColor[iShape].gValue, WingColor[iShape].bValue);
				glColor3f(0.082f, 0.478f, 0.631f); //Shade of Yellow
				glVertex3f(scalePoint(rotatePoint(WingDesignGreenPoly.points[iShape], fAngle * iCounter), scaleFactorPoint).x * resize, rotatePoint(WingDesignGreenPoly.points[iShape], fAngle * iCounter).y * resize, WingDesignGreenPoly.points[iShape].z * resize); //Origin 
			}
			glEnd();

			glBegin(GL_POLYGON);
			for (int iShape = 0; iShape <= 4; iShape = iShape + 1)
			{

				//glColor3f(WingColor[iShape].rValue, WingColor[iShape].gValue, WingColor[iShape].bValue);
				glColor3f(0.254f, 0.258f, 0.623f); //Shade of Yellow
				glVertex3f(scalePoint(rotatePoint(WingDesignPurplePoly.points[iShape], fAngle * iCounter), scaleFactorPoint).x * resize, rotatePoint(WingDesignPurplePoly.points[iShape], fAngle * iCounter).y * resize, WingDesignPurplePoly.points[iShape].z * resize); //Origin 
			}
			glEnd();

			iCounter += 6;
		}
		iCounter = 6;
	}
}

void drawCircleWithColor_Peacock(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, float alpha, int fill, float resize)
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

		glVertex2f(ObjX * resize, ObjY * resize);
	}


	glEnd();

}
