void butterfly(float originx, float originy, float resize)
{
	// Triangle 1
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(originx + 0*resize, originy + 1*resize);
	glVertex2f(originx + -1*resize, originy + -1*resize);
	glVertex2f(originx + 1*resize, originy + -1*resize);
	glEnd();
}

void updateButterfly(void)
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
