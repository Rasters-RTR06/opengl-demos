void drawCraneOne(float,float,float);
void drawCraneTwo(float, float, float);
void drawCircleCranes(float , float , float, float, float, float, float, int);

void drawCraneOne(float originx, float originy, float resize)
{
	//Body
	glBegin(GL_QUADS);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.023f) * resize, originy + (0.153f) * resize, 0.0f);
	glVertex3f(originx + (0.105f) * resize, originy + (0.237f) * resize, 0.0f);
	glVertex3f(originx + (0.1f)   * resize, originy + (0.2f)   * resize, 0.0f);
	glVertex3f(originx + (0.06f)  * resize, originy + (0.15f)  * resize, 0.0f);
	glEnd();

	//wing
	glBegin(GL_TRIANGLES);	
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.055f) * resize, originy + (0.187f) * resize, 0.0f);
	glVertex3f(originx + (0.022f) * resize, originy + (0.19f) * resize, 0.0f);
	glVertex3f(originx + (0.10f) * resize,  originy + (0.226f) * resize, 0.0f);
	glEnd();

	//Tail
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.04f) * resize, originy + (0.16f) * resize, 0.0f);
	glVertex3f(originx + (0.0f) * resize,  originy + (0.12f) * resize, 0.0f);
	glEnd();

	//Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.097f) * resize, originy + (0.22f) * resize, 0.0f);
	glVertex3f(originx + (0.12f) * resize,  originy + (0.3f) * resize, 0.0f);
	glEnd();

	//Head
	drawCircleCranes(0.38f, 0.9f, 0.03f, 0.04, 0.49f, 0.722f, 0.42f, 1);

	//Beak
	glBegin(GL_TRIANGLES);	
	glColor3f(0.0f, 0.282f, 0.2f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.31f) * resize, 0.0f);
	glVertex3f(originx + (0.16f) * resize,  originy + (0.307f) * resize, 0.0f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.30f) * resize, 0.0f);
	glEnd();

	//Eye
	glPointSize(5);	
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx + (0.128f) * resize, originy + (0.304f) * resize, 0.0f);
	glEnd();

	// right leg
	glLineWidth(3);
	glBegin(GL_LINES);	
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.07f) * resize,  originy + (0.161f) * resize, 0.0f);
	glVertex3f(originx + (0.064f) * resize, originy + (0.026f) * resize, 0.0f);
	glEnd();

	// left leg
	glBegin(GL_LINES);	
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.06f) * resize, originy + (0.152f) * resize, 0.0f);
	glVertex3f(originx + (0.0f) * resize,  originy + (0.04f) * resize, 0.0f);
	glEnd();
}

void drawCraneTwo(float originx, float originy, float resize)
{
	//Body
	glBegin(GL_QUADS);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.023f) * resize, originy + (0.153f) * resize, 0.0f);
	glVertex3f(originx + (0.105f) * resize, originy + (0.237f) * resize, 0.0f);
	glVertex3f(originx + (0.1f)   * resize, originy + (0.2f)   * resize, 0.0f);
	glVertex3f(originx + (0.06f)  * resize, originy + (0.15f)  * resize, 0.0f);
	glEnd();

	//Tail
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.04f) * resize, originy + (0.16f) * resize, 0.0f);
	glVertex3f(originx + (0.0f)  * resize, originy + (0.12f) * resize, 0.0f);
	glEnd();

	//Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.097f) * resize, originy + (0.22f) * resize, 0.0f);
	glVertex3f(originx + (0.12f) * resize,  originy + (0.3f) * resize, 0.0f);
	glEnd();

	//Head
	drawCircleCranes(0.38f,0.9f, 0.03f, 0.04, 0.49f, 0.722f, 0.42f, 1);

	//beak
	glBegin(GL_TRIANGLES);	
	glColor3f(0.0f, 0.282f, 0.2f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.31f) * resize, 0.0f);
	glVertex3f(originx + (0.16f) * resize,  originy + (0.307f) * resize, 0.0f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.30f) * resize, 0.0f);
	glEnd();

	//Eye
	glPointSize(5);	
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx + (0.128f) * resize, originy + (0.304f) * resize, 0.0f);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);	// right leg
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.07f) * resize,  originy + (0.161f) * resize, 0.0f);
	glVertex3f(originx + (0.064f) * resize, originy + (0.026f) * resize, 0.0f);
	glEnd();

	glBegin(GL_LINES);	// left leg
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.06f)*resize, originy + (0.149f)*resize, 0.0f);
	glVertex3f(originx + (0.03f)*resize, originy + (0.043f)*resize, 0.0f);
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
