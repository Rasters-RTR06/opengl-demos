
void drawTopDeerNearDraupadi(float, float, float);
void drawBottomDeerNearDraupadi(float, float, float );

void drawTopDeerNearDraupadi(float originx, float originy, float resize)
{
	glBegin(GL_POLYGON);

	//Body
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (-0.2f) * resize,  originy + (0.05f) * resize, 0.0f);	//1
	glVertex3f(originx + (-0.15f) * resize, originy + (-0.05f) * resize, 0.0f); //2
	glVertex3f(originx + (0.15f) * resize,  originy + (-0.058f) * resize, 0.0f);	//3
	glVertex3f(originx + (0.145f) * resize, originy + (0.03f) * resize, 0.0f);	//4	 //tail start here
	glVertex3f(originx + (0.121f) * resize, originy + (0.073f) * resize, 0.0f);	//5
	glVertex3f(originx + (0.0f) * resize,   originy + (0.06f) * resize, 0.0f);
	glVertex3f(originx + (-0.09f) * resize, originy + (0.063f) * resize, 0.0f);
	glEnd();

	//Neck
	glBegin(GL_POLYGON);
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (-0.2f) * resize,   originy + (0.05f) * resize, 0.0f);
	glVertex3f(originx + (-0.173f) * resize, originy + (0.232f) * resize, 0.0f);
	glVertex3f(originx + (-0.125f) * resize, originy + (0.25f) * resize, 0.0f);
	glVertex3f(originx + (-0.119f) * resize, originy + (0.103f) * resize, 0.0f);
	glVertex3f(originx + (-0.09f) * resize,  originy + (0.063f) * resize, 0.0f);
	glEnd();

	//tail
	glBegin(GL_QUADS);	
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (0.128f) * resize, originy + (0.06f) * resize, 0.0f);
	glVertex3f(originx + (0.16f) * resize,  originy + (0.02f) * resize, 0.0f);
	glVertex3f(originx + (0.157f) * resize, originy + (0.014f) * resize, 0.0f);
	glVertex3f(originx + (0.14f) * resize,  originy + (0.02f) * resize, 0.0f);
	glEnd();

	//Front two legs
	glLineWidth(7);
	glBegin(GL_LINES);
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (-0.13f) * resize,  originy + (-0.05f) * resize, 0.0f);
	glVertex3f(originx + (-0.105f) * resize, originy + (-0.281f) * resize, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (-0.105f) * resize, originy + (-0.05f) * resize, 0.0f);
	glVertex3f(originx + (-0.009f) * resize, originy + (-0.242f) * resize, 0.0f);

	glEnd();

	//Hind legs
	glLineWidth(7);
	glBegin(GL_LINES);
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (0.10f) * resize, originy + (-0.054f) * resize, 0.0f);
	glVertex3f(originx + (0.04f) * resize, originy + (-0.24f) * resize, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (0.12f) * resize, originy + (-0.054f) * resize, 0.0f);
	glVertex3f(originx + (0.14f) * resize, originy + (-0.245f) * resize, 0.0f);
	glEnd();


	//Face
	glBegin(GL_POLYGON);
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (-0.16) * resize,  originy + (0.297) * resize, 0.0f);
	glVertex3f(originx + (-0.235) * resize, originy + (0.243) * resize, 0.0f);
	glVertex3f(originx + (-0.23) * resize,  originy + (0.235) * resize, 0.0f);
	glVertex3f(originx + (-0.196) * resize, originy + (0.24) * resize, 0.0f);
	glVertex3f(originx + (-0.175) * resize, originy + (0.236) * resize, 0.0f);
	glVertex3f(originx + (-0.121) * resize, originy + (0.249) * resize, 0.0f);
	glVertex3f(originx + (-0.122) * resize, originy + (0.288) * resize, 0.0f);
	glEnd();

	//Ears
	glLineWidth(7);
	glBegin(GL_LINES);
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (-0.122f) * resize, originy + (0.283f) * resize, 0.0f);
	glVertex3f(originx + (-0.111f) * resize, originy + (0.338f) * resize, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.82f, 0.776f, 0.459f);
	glVertex3f(originx + (-0.155f) * resize, originy + (0.296f) * resize, 0.0f);
	glVertex3f(originx + (-0.156f) * resize, originy + (0.334f) * resize, 0.0f);
	glEnd();

	glPointSize(4.0f);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx + (-0.17) * resize, originy + (0.26) * resize, 0.0f);
	glEnd();
}
void drawBottomDeerNearDraupadi(float originx, float originy, float resize)
{
	glBegin(GL_POLYGON);

	//Body
	glColor3f(0.69f, 0.631f, 0.314f);
	glVertex3f(originx + (-0.16f) * resize, originy + (0.05f) * resize, 0.0f);
	glVertex3f(originx + (-0.13f) * resize, originy + (-0.05f) * resize, 0.0f);
	glVertex3f(originx + (0.13f) * resize,  originy + (-0.058f) * resize, 0.0f); //right legs - hind 
	glVertex3f(originx + (0.16f) * resize,  originy + (0.03f) * resize, 0.0f);	 //tail start here
	glVertex3f(originx + (0.159f) * resize, originy + (0.073f) * resize, 0.0f);
	glVertex3f(originx + (0.165f) * resize, originy + (0.066f) * resize, 0.0f);
	glEnd();

	//tail
	glBegin(GL_QUADS);
	glColor3f(0.69f, 0.631f, 0.314f);
	glVertex3f(originx + (0.16f) * resize,  originy + (0.07f) * resize, 0.0f);
	glVertex3f(originx + (0.183f) * resize, originy + (0.05f) * resize, 0.0f);
	glVertex3f(originx + (0.175f) * resize, originy + (0.033f) * resize, 0.0f);
	glVertex3f(originx + (0.158f) * resize, originy + (0.03f) * resize, 0.0f);
	glEnd();

	//Neck
	glBegin(GL_POLYGON);
	glColor3f(0.69f, 0.631f, 0.314f);
	glVertex3f(originx + (-0.16f) * resize, originy + (0.05f) * resize, 0.0f);
	glVertex3f(originx + (-0.27f) * resize, originy + (-0.093f) * resize, 0.0f);
	glVertex3f(originx + (-0.26f) * resize, originy + (-0.122) * resize, 0.0f);
	glVertex3f(originx + (-0.13f) * resize, originy + (-0.034) * resize, 0.0f);
	glEnd();

	//Face
	glBegin(GL_POLYGON);
	glColor3f(0.69f, 0.631f, 0.314f);
	glVertex3f(originx + (-0.26 ) * resize, originy + (-0.093) * resize, 0.0f);
	glVertex3f(originx + (-0.327) * resize, originy + (-0.117) * resize, 0.0f);
	glVertex3f(originx + (-0.339) * resize, originy + (-0.213) * resize, 0.0f);
	glVertex3f(originx + (-0.32 ) * resize, originy + (-0.22) * resize, 0.0f);
	glVertex3f(originx + (-0.25 ) * resize, originy + (-0.14) * resize, 0.0f);
	glVertex3f(originx + (-0.274) * resize, originy + (-0.123) * resize, 0.0f);
	glEnd();

	//Eye
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx + (-0.29) * resize, originy + ( - 0.147)* resize, 0.0f);
	glEnd();

	//Front two legs
	glLineWidth(9);
	glBegin(GL_LINES);
	glColor3f(0.69f, 0.631f, 0.314f);
	glVertex3f(originx + (-0.13f) * resize,  originy + (-0.04f) * resize, 0.0f);
	glVertex3f(originx + (-0.105f) * resize, originy + (-0.281f) * resize, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.69f, 0.631f, 0.314f);
	glVertex3f(originx + (-0.105f) * resize, originy + (-0.04f) * resize, 0.0f);
	glVertex3f(originx + (-0.009f) * resize, originy + (-0.242f) * resize, 0.0f);
	glEnd();

	//Hind legs
	glBegin(GL_LINES);
	glColor3f(0.69f, 0.631f, 0.314f);
	glVertex3f(originx + (0.073f) * resize, originy + (-0.062f) * resize, 0.0f);
	glVertex3f(originx + (0.038f) * resize, originy + (-0.24f) * resize, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.69f, 0.631f, 0.314f);
	glVertex3f(originx + (0.10f) * resize, originy + (-0.052f) * resize, 0.0f);
	glVertex3f(originx + (0.12f) * resize, originy + (-0.243f) * resize, 0.0f);
	glEnd();

	//Ears
	glLineWidth(7);
	glBegin(GL_LINES);
	glColor3f(0.69f, 0.631f, 0.314f); 
	glVertex3f(originx + (-0.325) * resize, originy + (-0.117) * resize, 0.0f);
	glVertex3f(originx + (-0.378) * resize, originy + (-0.11) * resize, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.69f, 0.631f, 0.314f);
	glVertex3f(originx + (-0.325) * resize, originy + (-0.117) * resize, 0.0f);
	glVertex3f(originx + (-0.352) * resize, originy + (-0.072) * resize, 0.0f);
	glEnd();
}

