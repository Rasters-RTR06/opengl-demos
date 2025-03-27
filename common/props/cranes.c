void drawCraneOne(float,float,float);
void drawCraneTwo(float, float, float);
void drawCircleCranes(float , float , float, float, float, float, float, int);
void drawStone(float, float, float);

void drawCraneOne(float originx, float originy, float resize) //left side crane
{
	drawStone(originx + (0.0f) * resize, originy + (-0.1f) * resize, 0.2f);
	drawStone(originx + (1.8f) * resize, originy + (0.0f) * resize, 0.18f);	//extra stone rightmost
	//Body
	glBegin(GL_QUADS);
	glColor3f(0.925f, 0.922f, 0.933f);
	glVertex3f(originx + (0.023f) * resize, originy + (0.153f) * resize, 0.0f);
	glVertex3f(originx + (0.105f) * resize, originy + (0.237f) * resize, 0.0f);
	glVertex3f(originx + (0.1f)   * resize, originy + (0.2f)   * resize, 0.0f);
	glVertex3f(originx + (0.06f)  * resize, originy + (0.15f)  * resize, 0.0f);
	glEnd();

	//wing
	glBegin(GL_TRIANGLES);	
	glColor3f(0.925f, 0.922f, 0.933f);
	glVertex3f(originx + (0.055f) * resize, originy + (0.187f) * resize, 0.0f);
	glVertex3f(originx + (0.022f) * resize, originy + (0.19f) * resize, 0.0f);
	glVertex3f(originx + (0.10f) * resize,  originy + (0.226f) * resize, 0.0f);
	glEnd();

	//Tail
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.925f, 0.922f, 0.933f);
	glVertex3f(originx + (0.04f) * resize, originy + (0.16f) * resize, 0.0f);
	glVertex3f(originx + (0.0f) * resize,  originy + (0.12f) * resize, 0.0f);
	glEnd();

	//Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.925f, 0.922f, 0.933f);
	glVertex3f(originx + (0.097f) * resize, originy + (0.22f) * resize, 0.0f);
	glVertex3f(originx + (0.12f) * resize,  originy + (0.3f) * resize, 0.0f);
	glEnd();

	//Head
	//drawCircleCranes(originx + (0.38f)*resize, originy + (0.9f)* resize, 0.03f, 0.04, 0.49f, 0.722f, 0.42f, 1);
	drawCircleCranes(originx + (0.12f) * resize, originy + (0.3f) * resize, 0.015f, 0.015f, 0.925f, 0.922f, 0.933f, 1);

	//drawCircleCranes(originx + (0.38f)*resize, originy + (0.9f)* resize, 0.03f, 0.04, 0.49f, 0.722f, 0.42f, 1);
	//drawCircleCranes(originx + (0.12f) * resize, originy + (0.3f) * resize, 0.015f, 0.015f, 0.925f, 0.922f, 0.933f, 1);


	//Beak
	glBegin(GL_TRIANGLES);	
	glColor3f(0.847f, 0.58f, 0.337f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.315f) * resize, 0.0f);
	glVertex3f(originx + (0.165f) * resize,  originy + (0.307f) * resize, 0.0f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.295f) * resize, 0.0f);
	glEnd();

	//Eye
	glPointSize(3);	
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx + (0.128f) * resize, originy + (0.304f) * resize, 0.0f);
	glEnd();

	// right leg
	glLineWidth(3);
	glBegin(GL_LINES);	
	glColor3f(0.494f, 0.51f, 0.486f);
	glVertex3f(originx + (0.07f) * resize,  originy + (0.161f) * resize, 0.0f);
	glVertex3f(originx + (0.064f) * resize, originy + (0.026f) * resize, 0.0f);
	glEnd();

	// left leg
	glBegin(GL_LINES);	
	glColor3f(0.494f, 0.51f, 0.486f);
	glVertex3f(originx + (0.06f) * resize, originy + (0.152f) * resize, 0.0f);
	glVertex3f(originx + (0.0f) * resize,  originy + (0.04f) * resize, 0.0f);
	glEnd();
}

void drawCraneTwo(float originx, float originy, float resize) // right side crane
{
	drawStone(originx + (0.0f) * resize, originy + (0.0f) * resize, 0.1f);
	//Body
	glBegin(GL_QUADS);
	glColor3f(0.925f, 0.922f, 0.933f);
	glVertex3f(originx - (0.023f) * resize, originy + (0.153f) * resize, 0.0f);
	glVertex3f(originx - (0.105f) * resize, originy + (0.237f) * resize, 0.0f);
	glVertex3f(originx - (0.1f)   * resize, originy + (0.2f)   * resize, 0.0f);
	glVertex3f(originx - (0.06f)  * resize, originy + (0.15f)  * resize, 0.0f);
	glEnd();

	//Tail
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.925f, 0.922f, 0.933f);
	glVertex3f(originx - (0.04f) * resize, originy + (0.16f) * resize, 0.0f);
	glVertex3f(originx - (0.0f)  * resize, originy + (0.12f) * resize, 0.0f);
	glEnd();

	//Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.925f, 0.922f, 0.933f);
	glVertex3f(originx - (0.097f) * resize, originy + (0.22f) * resize, 0.0f);
	glVertex3f(originx - (0.12f) * resize,  originy + (0.3f) * resize, 0.0f);
	glEnd();

	//Head
	//drawCircleCranes(originx + (0.38f) * resize, originy + (0.9f) * resize, 0.03f, 0.04, 0.49f, 0.722f, 0.42f, 1);
	drawCircleCranes(originx - (0.12f) * resize, originy + (0.3f) * resize, 0.015f, 0.015f, 0.925f, 0.922f, 0.933f, 1);

	/*COLOR color = { 0.49f, 0.722f, 0.42f , 0.0f};
	ANGLE angle = { 0.0f, 0.0f , 0.0f };
	SCALING scalingFactor = {resize,resize,resize};
	TRANSLATION translationFactor = { originx + (0.12f) , originy + (0.3f) };
	REFLECTION reflectionFactor = { -1, 1, 0 };
	RADIUS radius = { 0.02f, 0.02f ,0.0f };
	drawEllipse(color, angle,scalingFactor,translationFactor,reflectionFactor,radius,0.0f);*/
	//drawCircleCranes(originx + (0.38f) * resize, originy + (0.9f) * resize, 0.03f, 0.04, 0.49f, 0.722f, 0.42f, 1);
	//drawCircleCranes(originx - (0.12f) * resize, originy + (0.3f) * resize, 0.02f, 0.02f, 0.49f, 0.722f, 0.42f, 1);

	/*COLOR color = { 0.49f, 0.722f, 0.42f , 0.0f};
	ANGLE angle = { 0.0f, 0.0f , 0.0f };
	SCALING scalingFactor = {resize,resize,resize};
	TRANSLATION translationFactor = { originx + (0.12f) , originy + (0.3f) };
	REFLECTION reflectionFactor = { -1, 1, 0 };
	RADIUS radius = { 0.02f, 0.02f ,0.0f };
	drawEllipse(color, angle,scalingFactor,translationFactor,reflectionFactor,radius,0.0f);*/

	//beak
	glBegin(GL_TRIANGLES);	
	glColor3f(0.847f, 0.58f, 0.337f);
	glVertex3f(originx - (0.135f) * resize, originy + (0.315f) * resize, 0.0f);
	glVertex3f(originx - (0.165f) * resize,  originy + (0.307f) * resize, 0.0f);
	glVertex3f(originx - (0.135f) * resize, originy + (0.295f) * resize, 0.0f);
	glEnd();

	//Eye
	glPointSize(3);	
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx - (0.128f) * resize, originy + (0.304f) * resize, 0.0f);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);	// right leg
	glColor3f(0.494f, 0.51f, 0.486f);
	glVertex3f(originx - (0.07f) * resize,  originy + (0.161f) * resize, 0.0f);
	glVertex3f(originx - (0.064f) * resize, originy + (0.026f) * resize, 0.0f);
	glEnd();

	glBegin(GL_LINES);	// left leg
	glColor3f(0.494f, 0.51f, 0.486f);
	glVertex3f(originx - (0.06f)*resize, originy + (0.149f)*resize, 0.0f);
	glVertex3f(originx - (0.03f)*resize, originy + (0.043f)*resize, 0.0f);
	glEnd();
}

void drawCircleCranes(float centerX, float centerY, float radiusH, float radiusV, float r, float g, float b, int fill)
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

	glColor3f(r, g, b);
	for (ObjAngle = (0.00f); ObjAngle <= (2.0f * PI); ObjAngle += 0.01f)

	{
		ObjX = centerX + radiusH * cos(ObjAngle);
		ObjY = centerY + radiusV * sin(ObjAngle);
		glVertex2f(ObjX, ObjY);
	}

	glEnd();
}

void drawStone(float originx, float originy, float resize)
{
	glBegin(GL_POLYGON);
	glColor3f(0.161, 0.161, 0.161);
	glVertex3f(originx - (0.0f) * resize, originy + (-0.2f) * resize, 0.0f);
	glVertex3f(originx - (-0.6f) * resize, originy + (-0.2f) * resize, 0.0f);
	glColor3f(0.212f, 0.212f, 0.212f);
	glVertex3f(originx - (-0.72f) * resize, originy + (-0.1f) * resize, 0.0f);
	glColor3f(0.275f, 0.275f, 0.275f);
	glVertex3f(originx - (-0.62f) * resize, originy + (0.21f) * resize, 0.0f);
	glColor3f(0.282f, 0.282f, 0.282f);
	glVertex3f(originx - (-0.36f) * resize, originy + (0.49f) * resize, 0.0f);
	
	glVertex3f(originx - (-0.203f) * resize, originy + (0.647f) * resize, 0.0f);
	glColor3f(0.357f, 0.357f, 0.357f);
	glVertex3f(originx - (0.12f) * resize, originy + (0.62f) * resize, 0.0f);
	glVertex3f(originx - (0.58f) * resize, originy + (0.333f) * resize, 0.0f);
	glColor3f(0.282f, 0.282f, 0.282f);
	glVertex3f(originx - (0.73f) * resize, originy + (0.13f) * resize, 0.0f);
	glColor3f(0.118f, 0.118f, 0.118f);
	glVertex3f(originx - (0.8f) * resize, originy + (-0.2f) * resize, 0.0f);
	glEnd();
}
