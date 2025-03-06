extern float fToungeStretch = 0;
extern float fToungeDirection = -1.0f;

void toungeMovement(void)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	for (float x = 0.0f; x >= fToungeStretch; x-=0.01f)
	{
		float y = (cos(fToungeStretch * log(-0.75f*x))/8.5f);
		glVertex2f(x+1.0f, y);
		glVertex2f(x+1.0f, y-0.05f);
	}
	glEnd();
}

void updateTounge(void)
{

	fToungeStretch += 0.03f * fToungeDirection;   // Increment with fToungeDirection

	if (fToungeStretch >= 1.0f) {
		fToungeStretch = 1.0f;
		fToungeDirection = -1.0f; // Change fToungeDirection to negative
	} else if (fToungeStretch <= -1.0f) {
		fToungeStretch = -1.0f;
		fToungeDirection = 1.0f;  // Change fToungeDirection to positive
	}


}

