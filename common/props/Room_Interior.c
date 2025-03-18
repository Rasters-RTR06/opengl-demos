
//Use drawRoom() function to draw

//User Defined global function declarations
void drawRoom(void);

void drawRoom(void)
{
	glBegin(GL_POLYGON);
	glColor3f(0.003f, 0.270f, 0.215f);
	glVertex3f(0.9f, 0.9f, 0.0f); //Origin 
	glColor3f(0.003f, 0.270f, 0.215f);
	glVertex3f(-0.9f, 0.9f, 0.0f); //top left
	glColor3f(0.003f, 0.270f, 0.215f);
	glVertex3f(-0.9f, 0.0f, 0.0f); //top left
	glColor3f(0.003f, 0.270f, 0.215f);
	glVertex3f(0.9f, 0.0f, 0.0f); //top left
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.772f, 0.780f, 0.439f);
	glVertex3f(0.9f, 0.0f, 0.0f); //top left
	glColor3f(0.772f, 0.780f, 0.439f);
	glVertex3f(-0.9f, 0.0f, 0.0f); //top left
	glColor3f(0.772f, 0.780f, 0.439f);
	glVertex3f(-0.9f, -0.9f, 0.0f); //top left
	glColor3f(0.772f, 0.780f, 0.439f);
	glVertex3f(0.9f, -0.9f, 0.0f); //Origin 
	glEnd();

}

