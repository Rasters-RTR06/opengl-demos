void drawArrow(float x, float y, float scale, float rotation) {
	// Set up an orthographic projection.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	// Switch to modelview matrix and reset.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Translate the arrow to the specified (x, y) position.
	glTranslatef(x, y, 0.0f);

	// Rotate the arrow by the given angle (in degrees) about the Z-axis.
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);

	// Scale the arrow by the provided scale factor.
	glScalef(scale * 0.7f, scale * 0.7f, scale);

	glColor3f(1.0f, 1.0f, 1.0f);  // White

	glBegin(GL_LINES);
	glVertex2f(-0.8f, 0.0f);
	glVertex2f(0.4f, 0.0f);
	glEnd();

	// Rectangle #1 (Upper)
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.85f, 0.08f);
	glVertex2f(-0.75f, 0.08f);
	glVertex2f(-0.65f, 0.01f);
	glVertex2f(-0.75f, 0.01f);
	glEnd();

	// Rectangle #2 (Upper)
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.725f, 0.08f);
	glVertex2f(-0.625f, 0.08f);
	glVertex2f(-0.525f, 0.01f);
	glVertex2f(-0.625f, 0.01f);
	glEnd();

	// Rectangle #3 (Upper)
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.6f, 0.08f);
	glVertex2f(-0.5f, 0.08f);
	glVertex2f(-0.4f, 0.01f);
	glVertex2f(-0.5f, 0.01f);
	glEnd();

	// Rectangle #1 (Lower)
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.85f, -0.09f);
	glVertex2f(-0.75f, -0.09f);
	glVertex2f(-0.65f, -0.02f);
	glVertex2f(-0.75f, -0.02f);
	glEnd();

	// Rectangle #2 (Lower)
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.725f, -0.09f);
	glVertex2f(-0.625f, -0.09f);
	glVertex2f(-0.525f, -0.02f);
	glVertex2f(-0.625f, -0.02f);
	glEnd();

	// Rectangle #3 (Lower)
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.6f, -0.09f);
	glVertex2f(-0.5f, -0.09f);
	glVertex2f(-0.4f, -0.02f);
	glVertex2f(-0.5f, -0.02f);
	glEnd();

	// --- Arrow Tip ---
	// Tip is attached at the shaft's new endpoint (0.4)
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.4f, 0.0f);   // Base of the tip (aligned with shaft)
	glVertex2f(0.2f, 0.2f);   // Upper side point
	glVertex2f(0.6f, 0.0f);   // Tip point (extending to the right)
	glVertex2f(0.2f, -0.2f);  // Lower side point
	glVertex2f(0.4f, 0.0f);   // Base again
	glEnd();
	
	glLoadIdentity();
}
