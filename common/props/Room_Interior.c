#include "../common.h"
// Use drawRoom() function to draw

// User Defined global function declarations
void drawRoom(void);

void drawRoom(void)
{
	// Upper wall (aged wood texture with darker, muted green)
	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.2f, 0.15f);  // Darker, aged green
	glVertex3f(1.5f, 1.0f, 0.0f);  // Top right
	glVertex3f(-1.5f, 1.0f, 0.0f); // Top left
	glVertex3f(-1.5f, 0.0f, 0.0f); // Bottom left
	glVertex3f(1.5f, 0.0f, 0.0f);  // Bottom right
	glEnd();

	// Lower floor (worn stone or dirt floor with earthy tones)
	glBegin(GL_POLYGON);
	glColor3f(0.45f, 0.35f, 0.25f); // Muted brown for ancient floor
	glVertex3f(1.5f, 0.0f, 0.0f);	// Top right
	glVertex3f(-1.5f, 0.0f, 0.0f);	// Top left
	glVertex3f(-1.5f, -1.0f, 0.0f); // Bottom left
	glVertex3f(1.5f, -1.0f, 0.0f);	// Bottom right
	glEnd();

	// Wooden beam across ceiling (aged wood)
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glColor3f(0.3f, 0.2f, 0.1f);	// Dark brown wood
	glVertex3f(-0.9f, 0.85f, 0.0f); // Left
	glVertex3f(0.9f, 0.85f, 0.0f);	// Right
	glEnd();

	// Wall texture (vertical wood grain lines)
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glColor3f(0.05f, 0.15f, 0.1f); // Slightly darker than wall
	for (float x = -0.8f; x <= 0.8f; x += 0.2f)
	{
		glVertex3f(x, 0.9f, 0.0f);
		glVertex3f(x, 0.0f, 0.0f);
	}
	glEnd();

	// Hanging vines from ceiling (simplified)
	glLineWidth(2.0f);
	glBegin(GL_LINES);
	glColor3f(0.2f, 0.3f, 0.1f);   // Dark green
	glVertex3f(-0.6f, 0.9f, 0.0f); // Top
	glVertex3f(-0.6f, 0.7f, 0.0f); // Bottom
	glVertex3f(-0.5f, 0.9f, 0.0f);
	glVertex3f(-0.5f, 0.75f, 0.0f);
	glVertex3f(0.4f, 0.9f, 0.0f);
	glVertex3f(0.4f, 0.65f, 0.0f);
	glEnd();

	//// Small shelf or ledge on wall
	//glBegin(GL_QUADS);
	//glColor3f(0.3f, 0.2f, 0.1f);	// Matching wood beam
	//glVertex3f(0.5f, -0.2f, 0.0f);	// Top right
	//glVertex3f(0.7f, -0.2f, 0.0f);	// Top left
	//glVertex3f(0.7f, -0.25f, 0.0f); // Bottom left
	//glVertex3f(0.5f, -0.25f, 0.0f); // Bottom right
	//glEnd();

	// Floor cracks (to simulate age)
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glColor3f(0.3f, 0.25f, 0.2f); // Slightly darker than floor
	glVertex3f(0.0f, -0.1f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(-0.3f, -0.4f, 0.0f);
	glVertex3f(-0.5f, -0.6f, 0.0f);
	glEnd();
}
