//common variables
struct RGBColor {
	float rColorValue;
	float gColorValue;
	float bColorValue;
	float aColorValue;
};


void drawLetterStroke(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, float scalingFactor, float xOffset, float yOffset, int segments)
{
	x0 = x0 / scalingFactor - xOffset;
	x1 = x1 / scalingFactor - xOffset;
	x2 = x2 / scalingFactor - xOffset;
	x3 = x3 / scalingFactor - xOffset;

	y0 = y0 / scalingFactor - yOffset;
	y1 = y1 / scalingFactor - yOffset;
	y2 = y2 / scalingFactor - yOffset;
	y3 = y3 / scalingFactor - yOffset;

	glVertex2f(x0, y0);
	for (int i = 0; i <= segments; i++) {
		float t = (float)i / (float)segments;
		float x = (1 - t) * (1 - t) * (1 - t) * x0 + 3 * (1 - t) * (1 - t) * t * x1 + 3 * (1 - t) * t * t * x2 + t * t * t * x3;
		float y = (1 - t) * (1 - t) * (1 - t) * y0 + 3 * (1 - t) * (1 - t) * t * y1 + 3 * (1 - t) * t * t * y2 + t * t * t * y3;
		glVertex2f(x, y);
	}
}

void drawLetterSa(float scalingFactor, float xOffset, float yOffset, struct RGBColor letterColor, struct RGBColor backgroundColor)
{
	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.06f, 0.16f, 0.05f, 0.07f, -0.15f, 0.07f, -0.16f, 0.16f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.06f, 0.16f, 0.05f, 0.25f, -0.15f, 0.25f, -0.16f, 0.16f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper Tip
	drawLetterStroke(-0.7f, 0.12f, -0.8f, 0.11f, -0.8f, 0.01f, -0.65f, 0.0612f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//Sa upper outer stroke
	drawLetterStroke(-0.7f, 0.12f, -0.5f, 0.18f, -0.3f, 0.01f, -0.35f, -0.08f, scalingFactor, xOffset, yOffset, 1000);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.08f / scalingFactor - yOffset);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.56f, -0.08f, -0.5f, -0.04f, -0.5f, 0.00f, -0.56f, 0.04f, scalingFactor, xOffset, yOffset, 1000);
	drawLetterStroke(-0.56f, 0.04f, -0.58f, 0.061f, -0.59f, 0.062f, -0.7f, 0.053f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Middle horizontal stick
	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.08f / scalingFactor - yOffset);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.08f / scalingFactor - yOffset);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glEnd();

	//Maatra line
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.06f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.06f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.05f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.08f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.07f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.78f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.50f / scalingFactor - yOffset);
	glVertex2f(-0.40f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glEnd();

	//Big stroke below stick
	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.19f, -0.19f, 0.10f, -0.47f, -0.10f, -0.47f, -0.38f, -0.26f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Left Below stroke
	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.40f, -0.45f, -0.63f, -0.12f, -0.71f, -0.10f, -0.78f, -0.14f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.78f, -0.14f, -0.82f, -0.16f, -0.82f, -0.05f, -0.78f, -0.07f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	//Little stroke for stick
	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.16f, -0.17f, -0.18f, -0.24f, -0.22f, -0.27f, -0.24f, -0.29f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.29f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.50f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.35f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.30f, -0.355f, -0.38f, -0.21f, -0.47f, -0.18f, -0.50f, -0.14f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.23f / scalingFactor - yOffset);
	glVertex2f(0.19f / scalingFactor - xOffset, -0.19f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.19f / scalingFactor - yOffset);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.56f, -0.08f, -0.58f, -0.09f, -0.69f, -0.092f, -0.8f, -0.07f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();
}

void drawLetterDe(float scalingFactor, float xOffset, float yOffset, struct RGBColor letterColor, struct RGBColor backgroundColor)
{

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);

	glBegin(GL_POLYGON);
	glVertex2f(0.01f / scalingFactor - xOffset, 0.23f / scalingFactor - yOffset);
	glVertex2f(-0.47f / scalingFactor - xOffset, 0.23f / scalingFactor - yOffset);
	glVertex2f(-0.47f / scalingFactor - xOffset, 0.08f / scalingFactor - yOffset);
	glVertex2f(0.12f / scalingFactor - xOffset, 0.08f / scalingFactor - yOffset);
	glEnd();

	//Maatra line
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.06f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.06f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);

	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.13f, 0.08f, -0.28f, 0.14f, -0.33f, 0.28f, -0.45f, 0.08f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);

	glBegin(GL_POLYGON);
	glVertex2f(0.12f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(-0.13f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(-0.13f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(0.12f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.13f, -0.085f, -0.58f, -0.105f, -0.58f, -0.535f, -0.13f, -0.485f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Inner
	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.13f, -0.17f, -0.38f, -0.205f, -0.38f, -0.435f, -0.13f, -0.453f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.30f / scalingFactor - xOffset, -0.37f / scalingFactor - yOffset);
	glVertex2f(-0.13f / scalingFactor - xOffset, -0.37f / scalingFactor - yOffset);
	glVertex2f(-0.13f / scalingFactor - xOffset, -0.58f / scalingFactor - yOffset);
	glVertex2f(0.30f / scalingFactor - xOffset, -0.58f / scalingFactor - yOffset);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.12f, -0.37f, 0.16f, -0.54f, 0.20f, -0.57f, 0.30f, -0.56f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(0.30f / scalingFactor - xOffset, -0.37f / scalingFactor - yOffset);
	glVertex2f(0.12f / scalingFactor - xOffset, -0.37f / scalingFactor - yOffset);
	glVertex2f(0.30f / scalingFactor - xOffset, -0.56f / scalingFactor - yOffset);
	glEnd();
}

void drawLetterSha(float scalingFactor, float xOffset, float yOffset, struct RGBColor letterColor, struct RGBColor backgroundColor)
{
	//Maatra line
	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.13f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.13f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.07f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.07f / scalingFactor - yOffset);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.05f / scalingFactor - xOffset, 0.07f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, 0.07f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.20f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.20f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.16f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.24f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.24f / scalingFactor - yOffset);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.78f / scalingFactor - xOffset, -0.24f / scalingFactor - yOffset);
	glVertex2f(-0.80f / scalingFactor - xOffset, -0.24f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.50f / scalingFactor - yOffset);
	glVertex2f(-0.40f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glEnd();

	//Big stroke below stick
	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.19f, -0.19f, 0.10f, -0.47f, -0.10f, -0.47f, -0.35f, -0.27f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Left Below stroke Decrease Y
	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.40f, -0.45f, -0.63f, -0.22f, -0.71f, -0.26f, -0.78f, -0.24f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.78f, -0.24f, -0.82f, -0.26f, -0.82f, -0.15f, -0.78f, -0.17f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	//Little Stroke for stick
	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.16f, -0.17f, -0.18f, -0.24f, -0.22f, -0.27f, -0.24f, -0.29f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.29f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.50f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.35f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper outer stroke
	drawLetterStroke(-0.6f, 0.16f, -0.20f, 0.18f, -0.18f, -0.15f, -0.35f, -0.30f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper outer stroke
	glVertex2f(-0.35f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper outer stroke
	drawLetterStroke(-0.5f, 0.05f, -0.38f, 0.10f, -0.39f, -0.15f, -0.47f, -0.16f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper Tip
	drawLetterStroke(-0.6f, 0.16f, -0.9f, 0.11f, -0.9f, -0.21f, -0.30f, 0.0f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Middle void
	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper Tip
	drawLetterStroke(-0.4f, 0.04f, -0.7f, 0.25f, -0.7f, -0.15f, -0.4f, 0.04f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.10f, -0.4145f, -0.20f, -0.37f, -0.27f, -0.28f, -0.35f, -0.30f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.23f / scalingFactor - yOffset);
	glVertex2f(0.19f / scalingFactor - xOffset, -0.19f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.19f / scalingFactor - yOffset);
	glEnd();

	glColor4f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue, letterColor.aColorValue);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.434f / scalingFactor - xOffset, -0.142f / scalingFactor - yOffset);
	glVertex2f(-0.35f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glVertex2f(-0.50f / scalingFactor - xOffset, -0.16f / scalingFactor - yOffset);
	glEnd();

	glColor4f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue, backgroundColor.aColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.437f, -0.142f, -0.48f, -0.24f, -0.69f, -0.192f, -0.8f, -0.17f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();
}

void drawSandesh()
{
	// Enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	struct RGBColor letterColor = {1.0f, 1.0f, 1.0f, 1.0f};
	struct RGBColor backgroundColor = {0.008f, 0.275f, 0.231f, 1.0f};
	drawLetterSa(2.6f, 0.27f, 0.0f, letterColor, backgroundColor);
	drawLetterDe(3.0f, 0.0f, 0.0f, letterColor, backgroundColor);
	drawLetterSha(2.6f, -0.395f, 0.0f, letterColor, backgroundColor);
	
	// Disable blending when done (optional, depending on your application)
	glDisable(GL_BLEND);
}

