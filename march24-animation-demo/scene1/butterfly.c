// Global variables for butterfly animation
static float butterflyX = -0.4f;       // Starting X position
static float butterflyY = -0.07f;      // Fixed Y position
static float butterflyRotation = 0.0f; // Starting rotation angle


void updateButterfly(void)
{
	// Move butterfly to the right
	// Check if the butterfly has reached a certain X position before tilting
	if (butterflyX < 1.5f)
	{
		butterflyX += 0.03f;
		butterflyY += 0.03f; // Move butterfly slightly up
	}
	butterflyRotation = 20; // Starting rotation angle

}




struct Triangle
{
	float p1x;	//top x
	float p1y;	//top y
	float p2x;	//left x
	float p2y;	//left y
	float p3x;	//right x
	float p3y;	//right y
};

struct Quadrilateral
{
	float p1x;
	float p1y;

	float p2x;
	float p2y;

	float p3x;
	float p3y;

	float p4x;
	float p4y;
};

// Update these function declarations to include parameters
void drawRightWing(float originx, float originy, float resize, float rotationAngle);
void drawLeftWing(float originx, float originy, float resize, float rotationAngle);
void drawRightHalfOfBody(float originx, float originy, float resize, float rotationAngle);
void drawLeftHalfOfBody(float originx, float originy, float resize, float rotationAngle);

void drawTriangle(struct Triangle t, float r, float g, float b, float rotationAngle);
void drawQuadrilateral(struct Quadrilateral q, float r, float g, float b, float rotationAngle);

void drawButterfly(float originx, float originy, float resize, float rotationAngle);

void drawRightWing(float originx, float originy, float resize, float rotationAngle)
{
	struct Triangle t;
	struct Quadrilateral q;
	float r = 0.0f, g = 0.0f, b = 0.0f;

	//Right side of the wing
	r = 0.216f, g = 0.612f, b = 0.89f;	//1
	t.p1x = originx + (0.3f) * resize;   t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (0.073f) * resize; t.p2y = originy + (0.13f) * resize;	
	t.p3x = originx + (0.13f) * resize;  t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.314f, g = 0.757f, b = 0.976f;	//2
	t.p1x = originx + (0.3f) * resize;  t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (0.073f) * resize;  t.p2y = originy + (0.13f) * resize;
	t.p3x = originx + (0.174f) * resize;  t.p3y = originy + (0.473f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.251f, g = 0.667f, b = 0.91f;	//3
	t.p1x = originx + (0.3f) * resize;    t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (0.174f) * resize;    t.p2y = originy + (0.473f) * resize;	
	t.p3x = originx + (0.4f) * resize;    t.p3y = originy + (0.55f) * resize; 
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.173f, g = 0.435f, b = 0.761f;	//4
	t.p1x = originx + (0.3f) * resize;   t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (0.4f) * resize;   t.p2y = originy + (0.55f) * resize;	
	t.p3x = originx + (0.55f) * resize;  t.p3y = originy + (0.2f) * resize; 
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.051f, g = 0.078f, b = 0.31f;	
	t.p1x = originx + (0.4f) * resize;  t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (0.174f) * resize;  t.p2y = originy + (0.473f) * resize;	
	t.p3x = originx + (0.55f) * resize;  t.p3y = originy + (0.73f) * resize; 
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.176f, g = 0.573f, b = 0.804f;	//5
	t.p1x = originx + (0.3f) * resize;  t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (0.55f) * resize;  t.p2y = originy + (0.2f) * resize;
	t.p3x = originx + (0.5f) * resize;  t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.212f, g = 0.847f, b = 0.965f;	//6
	t.p1x = originx + (0.3f) * resize;  t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (0.5f) * resize;  t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (0.13f) * resize;  t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	//0.66,0.55
	r = 0.09f, g = 0.243f, b = 0.482f;	//1
	t.p1x = originx + (0.66f) * resize; t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (0.40f) * resize; t.p2y = originy + (0.55f) * resize;
	t.p3x = originx + (0.55f) * resize; t.p3y = originy + (0.2f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.11f, g = 0.141f, b = 0.325f;	//2
	t.p1x = originx + (0.66f) * resize; t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (0.4f) * resize;  t.p2y = originy + (0.55f) * resize;
	t.p3x = originx + (0.55f) * resize; t.p3y = originy + (0.73f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.188f, g = 0.204f, b = 0.31f;	//3
	t.p1x = originx + (0.66f) * resize;  t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (0.55f) * resize;  t.p2y = originy + (0.73f) * resize;
	t.p3x = originx + (0.77f) * resize;  t.p3y = originy + (0.75f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.188f, g = 0.204f, b = 0.31f;	//4
	t.p1x = originx + (0.66f) * resize;  t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (0.77f) * resize;  t.p2y = originy + (0.75f) * resize;
	t.p3x = originx + (0.85f) * resize;  t.p3y = originy + (0.4f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.137f, g = 0.157f, b = 0.251f;	//5
	t.p1x = originx + (0.66f) * resize;  t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (0.85f) * resize;  t.p2y = originy + (0.4f) * resize;
	t.p3x = originx + (0.7f) * resize;  t.p3y = originy + (0.1f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.094f, g = 0.051f, b = 0.18f;	
	q.p1x = originx + (0.66f) * resize;  q.p1y = originy + (0.55f) * resize;
	q.p2x = originx + (0.7f) * resize;  q.p2y = originy + (0.1f) * resize;
	q.p3x = originx + (0.5f) * resize;  q.p3y = originy + (0.0f) * resize;
	q.p4x = originx + (0.55f) * resize;  q.p4y = originy + (0.2f) * resize;
	drawQuadrilateral(q, r, g, b, rotationAngle);

	//Bottom part of right wing
	r = 0.212f, g = 0.776f, b = 0.965f;	
	t.p1x = originx + (0.3f) * resize; t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (0.07f) * resize; t.p2y = originy + (-0.12f) * resize;
	t.p3x = originx + (0.13f) * resize; t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.129f, g = 0.62f, b = 0.792f;	
	t.p1x = originx + (0.3f) * resize; t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (0.13f) * resize; t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (0.53f) * resize; t.p3y = originy + (-0.32f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.114f, g = 0.612f, b = 0.773f;	
	t.p1x = originx + (0.3f) * resize;  t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (0.13f) * resize; t.p2y = originy + (0.0f) * resize;	
	t.p3x = originx + (0.53f) * resize; t.p3y = originy + (-0.32f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.133f, g = 0.804f, b = 0.914f;	
	t.p1x = originx + (0.3f) * resize;  t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (0.53f) * resize; t.p2y = originy + (-0.32f) * resize;	
	t.p3x = originx + (0.22f) * resize; t.p3y = originy + (-0.63f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.263f, g = 0.957f, b = 0.988f;	
	t.p1x = originx + (0.3f) * resize; t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (0.22f) * resize; t.p2y = originy + (-0.63f) * resize;	
	t.p3x = originx + (0.07f) * resize; t.p3y = originy + (-0.12f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	//0.53,-0.32
	r = 0.188f, g = 0.549f, b = 0.835f;	
	t.p1x = originx + (0.53f) * resize;  t.p1y = originy + (-0.32f) * resize;
	t.p2x = originx + (0.13f) * resize;  t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (0.5f) * resize;  t.p3y = originy + (-0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.125f, g = 0.494f, b = 0.596f;	
	t.p1x = originx + (0.53f) * resize;   t.p1y = originy + (-0.32f) * resize;
	t.p2x = originx + (0.5f) * resize;     t.p2y = originy + (0.00f) * resize;
	t.p3x = originx + (0.655f) * resize;   t.p3y = originy + (-0.24f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.125f, g = 0.494f, b = 0.596f;	
	t.p1x = originx + (0.53f) * resize;  t.p1y = originy + (-0.32f) * resize;
	t.p2x = originx + (0.655f) * resize;  t.p2y = originy + (-0.24f) * resize;
	t.p3x = originx + (0.49f) * resize;  t.p3y = originy + (-0.72f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.2f, g = 0.702f, b = 0.878f;	
	t.p1x = originx + (0.53f) * resize;  t.p1y = originy + (-0.32f) * resize;
	t.p2x = originx + (0.49f) * resize;  t.p2y = originy + (-0.72f) * resize;
	t.p3x = originx + (0.22f) * resize;  t.p3y = originy + (-0.63f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	//tip of bottom
	r = 0.141f, g = 0.227f, b = 0.424f;	
	t.p1x = originx + (0.22f) * resize;  t.p1y = originy + (-0.63f) * resize;
	t.p2x = originx + (0.49f) * resize;  t.p2y = originy + (-0.72f) * resize;
	t.p3x = originx + (0.3f) * resize;  t.p3y = originy + (-0.8f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.031f, g = 0.063f, b = 0.318f;	
	t.p1x = originx + (0.3f) * resize;    t.p1y = originy + (-0.8f) * resize;
	t.p2x = originx + (0.49f) * resize;   t.p2y = originy + (-0.72f) * resize;
	t.p3x = originx + (0.5f) * resize;   t.p3y = originy + (-0.93f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);
}

void drawLeftWing(float originx, float originy, float resize,float rotationAngle)
{
	struct Triangle t;
	struct Quadrilateral q;
	float r = 0.0f, g = 0.0f, b = 0.0f;

	//Left side of the wing
	r = 0.216f, g = 0.612f, b = 0.89f;		//1
	t.p1x = originx + (-0.3f) * resize;   t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (-0.073f) * resize;   t.p2y = originy + (0.13f) * resize;	
	t.p3x = originx + (-0.13f) * resize;   t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.314f, g = 0.757f, b = 0.976f;		//2
	t.p1x = originx + (-0.3f) * resize; t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (-0.073f) * resize; t.p2y = originy + (0.13f) * resize;
	t.p3x = originx + (-0.174f) * resize; t.p3y = originy + (0.473f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.251f, g = 0.667f, b = 0.91f;		//3
	t.p1x = originx + (-0.3f) * resize;   t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (-0.174f) * resize;   t.p2y = originy + (0.473f) * resize;	
	t.p3x = originx + (-0.4f) * resize;   t.p3y = originy + (0.55f) * resize; 
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.173f, g = 0.435f, b = 0.761f;		//4
	t.p1x = originx + (-0.3f) * resize;   t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (-0.4f) * resize;   t.p2y = originy + (0.55f) * resize;	
	t.p3x = originx + (-0.55f) * resize;   t.p3y = originy + (0.2f) * resize; 
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.051f, g = 0.078f, b = 0.31f;		
	t.p1x = originx + (-0.4f) * resize;   t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (-0.174f) * resize;   t.p2y = originy + (0.473f) * resize;	
	t.p3x = originx + (-0.55f) * resize;   t.p3y = originy + (0.73f) * resize; 
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.176f, g = 0.573f, b = 0.804f;		//5
	t.p1x = originx + (-0.3f) * resize;  t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (-0.55f) * resize; t.p2y = originy + (0.2f) * resize;
	t.p3x = originx + (-0.5f) * resize;  t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.212f, g = 0.847f, b = 0.965f;		//6
	t.p1x = originx + (-0.3f) * resize;  t.p1y = originy + (0.2f) * resize;
	t.p2x = originx + (-0.5f) * resize;  t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (-0.13f) * resize; t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	
	r = 0.09f, g = 0.243f, b = 0.482f;		//1
	t.p1x = originx + (-0.66f) * resize; t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (-0.40f) * resize; t.p2y = originy + (0.55f) * resize;
	t.p3x = originx + (-0.55f) * resize; t.p3y = originy + (0.2f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.11f, g = 0.141f, b = 0.325f;		//2
	t.p1x = originx + (-0.66f) * resize; t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (-0.4f) * resize;  t.p2y = originy + (0.55f) * resize;
	t.p3x = originx + (-0.55f) * resize; t.p3y = originy + (0.73f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.188f, g = 0.204f, b = 0.31f;		//3
	t.p1x = originx + (-0.66f) * resize;  t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (-0.55f) * resize;  t.p2y = originy + (0.73f) * resize;
	t.p3x = originx + (-0.77f) * resize;  t.p3y = originy + (0.75f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.188f, g = 0.204f, b = 0.31f;		//4
	t.p1x = originx + (-0.66f) * resize;  t.p1y = originy + (0.55f) * resize;
	t.p2x = originx + (-0.77f) * resize;  t.p2y = originy + (0.75f) * resize;
	t.p3x = originx + (-0.85f) * resize;  t.p3y = originy + (0.4f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.137f, g = 0.157f, b = 0.251f;		
	t.p1x = originx + (-0.66f) * resize;  t.p1y = originy + (0.55f)* resize;
	t.p2x = originx + (-0.85f) * resize;  t.p2y = originy + (0.4f) * resize;
	t.p3x = originx + (-0.7f)  * resize;  t.p3y = originy + (0.1f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.094f, g = 0.051f, b = 0.18f;		//5
	q.p1x = originx + (-0.66f) * resize;  q.p1y = originy + (0.55f) * resize;
	q.p2x = originx + (-0.7f) * resize;  q.p2y = originy + (0.1f) * resize;
	q.p3x = originx + (-0.5f) * resize;  q.p3y = originy + (0.0f) * resize;
	q.p4x = originx + (-0.55f) * resize;  q.p4y = originy + (0.2f) * resize;
	drawQuadrilateral(q, r, g, b, rotationAngle);

	//Bottom part of right wing
	r = 0.212f, g = 0.776f, b = 0.965f;	
	t.p1x = originx + (-0.3f) * resize;  t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (-0.07f) * resize; t.p2y = originy + (-0.12f) * resize;
	t.p3x = originx + (-0.13f) * resize; t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.129f, g = 0.62f, b = 0.792f;	
	t.p1x = originx + (-0.3f) * resize; t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (-0.13f) * resize; t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (-0.53f) * resize; t.p3y = originy + (-0.32f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.114f, g = 0.612f, b = 0.773f;	
	t.p1x = originx + (-0.3f) * resize;  t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (-0.13f) * resize;  t.p2y = originy + (0.0f) * resize;	
	t.p3x = originx + (-0.53f) * resize;  t.p3y = originy + (-0.32f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.133f, g = 0.804f, b = 0.914f;	
	t.p1x = originx + (-0.3f) * resize;  t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (-0.53f) * resize; t.p2y = originy + (-0.32f) * resize;	
	t.p3x = originx + (-0.22f) * resize; t.p3y = originy + (-0.63f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.263f, g = 0.957f, b = 0.988f;	
	t.p1x = originx + (-0.3f) * resize;  t.p1y = originy + (-0.27f) * resize;
	t.p2x = originx + (-0.22f) * resize; t.p2y = originy + (-0.63f) * resize;	
	t.p3x = originx + (-0.07f) * resize; t.p3y = originy + (-0.12f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	
	r = 0.188f, g = 0.549f, b = 0.835f;	
	t.p1x = originx + (-0.53f) * resize;  t.p1y = originy + (-0.32f) * resize;
	t.p2x = originx + (-0.13f) * resize;  t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (-0.5f) * resize;  t.p3y = originy + (-0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.125f, g = 0.494f, b = 0.596f;	
	t.p1x = originx + (-0.53f) * resize;   t.p1y = originy + (-0.32f) * resize;
	t.p2x = originx + (-0.5f) * resize;    t.p2y = originy + (0.00f) * resize;
	t.p3x = originx + (-0.655f) * resize;  t.p3y = originy + (-0.24f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.125f, g = 0.494f, b = 0.596f;	
	t.p1x = originx + (-0.53f) * resize;  t.p1y = originy + (-0.32f) * resize;
	t.p2x = originx + (-0.655f) * resize; t.p2y = originy + (-0.24f) * resize;
	t.p3x = originx + (-0.49f) * resize;  t.p3y = originy + (-0.72f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.2f, g = 0.702f, b = 0.878f;	
	t.p1x = originx + (-0.53f) * resize;  t.p1y = originy + (-0.32f) * resize;
	t.p2x = originx + (-0.49f) * resize;  t.p2y = originy + (-0.72f) * resize;
	t.p3x = originx + (-0.22f) * resize;  t.p3y = originy + (-0.63f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	//tip of bottom
	r = 0.141f, g = 0.227f, b = 0.424f;	
	t.p1x = originx + (-0.22f) * resize;  t.p1y = originy + (-0.63f) * resize;
	t.p2x = originx + (-0.49f) * resize;  t.p2y = originy + (-0.72f) * resize;
	t.p3x = originx + (-0.3f) * resize;   t.p3y = originy + (-0.8f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.031f, g = 0.063f, b = 0.318f;	
	t.p1x = originx + (-0.3f) * resize;  t.p1y = originy + (-0.8f) * resize;
	t.p2x = originx + (-0.49f) * resize;  t.p2y = originy + (-0.72f) * resize;
	t.p3x = originx + (-0.5f) * resize;  t.p3y = originy + (-0.93f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);
}

void drawRightHalfOfBody(float originx, float originy, float resize,float rotationAngle)
{
	struct Quadrilateral q;
	struct Triangle t;
	float r = 0.0f, g = 0.0f, b = 0.0f;
	r = 0.071f, g = 0.071f, b = 0.18f;		//1
	t.p1x = originx + (0.0f) * resize;   t.p1y = originy + (0.3f) * resize;
	t.p2x = originx + (0.0f) * resize;   t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (0.073f) * resize; t.p3y = originy + (0.123f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);


	r = 0.094f, g = 0.278f, b = 0.392f;	//2
	t.p1x = originx + (0.073f) * resize;   t.p1y = originy + (0.13f) * resize;
	t.p2x = originx + (0.0f) * resize;   t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (0.13f) * resize;   t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.09f, g = 0.337f, b = 0.388f; 	//3
	t.p1x = originx + (0.13f) * resize; t.p1y = originy + (0.0f) * resize;
	t.p2x = originx + (0.0f) * resize; t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (0.057f) * resize; t.p3y = originy + (-0.114f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.071f, g = 0.075f, b = 0.161f; //4
	t.p1x = originx + (0.057f) * resize; t.p1y = originy + (-0.114f) * resize;
	t.p2x = originx + (0.0f) * resize;   t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (0.0f) * resize;   t.p3y = originy + (-0.4f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.098f, g = 0.2f, b = 0.204f;
	t.p1x = originx + (0.042f) * resize; t.p1y = originy + (-0.191f) * resize;
	t.p2x = originx + (0.0f) * resize;   t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (0.0f) * resize;   t.p3y = originy + (-0.42f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.043f, g = 0.047f, b = 0.165f;
	t.p1x = originx + (0.073f) * resize; t.p1y = originy + (0.528f) * resize;
	t.p2x = originx + (0.0f) * resize;   t.p2y = originy + (0.3f) * resize;
	t.p3x = originx + (0.073f) * resize; t.p3y = originy + (0.467f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);
}

void drawLeftHalfOfBody(float originx, float originy, float resize, float rotationAngle)
{
	struct Quadrilateral q;
	struct Triangle t;
	float r = 0.0f, g = 0.0f, b = 0.0f;
	r = 0.071f, g = 0.071f, b = 0.18f;	
	t.p1x = originx + (0.0f) * resize;    t.p1y = originy + (0.3f) * resize;	
	t.p2x = originx + (0.0f) * resize;    t.p2y = originy + (0.0f) * resize;	
	t.p3x = originx + (-0.073f) * resize; t.p3y = originy + (0.123f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);


	r = 0.094f, g = 0.278f, b = 0.392f;	//2
	t.p1x = originx + (-0.073f) * resize; t.p1y = originy + (0.13f) * resize;
	t.p2x = originx + (0.0f) * resize;    t.p2y = originy + (0.0f) * resize;
	t.p3x = originx + (-0.13f) * resize;  t.p3y = originy + (0.0f) * resize;
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.09f, g = 0.337f, b = 0.388f; 
	t.p1x = originx + (-0.13f) * resize;  t.p1y = originy + (0.0f) * resize;	
	t.p2x = originx + (0.0f) * resize;    t.p2y = originy + (0.0f) * resize;	
	t.p3x = originx + (-0.057f) * resize; t.p3y = originy + (-0.114f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.071f, g = 0.075f, b = 0.161f; 
	t.p1x = originx + (-0.057f) * resize; t.p1y = originy + (-0.114f) * resize;	
	t.p2x = originx + (0.0f) * resize;    t.p2y = originy + (0.0f) * resize;	
	t.p3x = originx + (0.0f) * resize;    t.p3y = originy + (-0.4f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.098f, g = 0.2f, b = 0.204f; 
	t.p1x = originx + (-0.042f) * resize; t.p1y = originy + (-0.191f) * resize;	
	t.p2x = originx + (0.0f) * resize;    t.p2y = originy + (0.0f) * resize;	
	t.p3x = originx + (0.0f) * resize;    t.p3y = originy + (-0.42f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);

	r = 0.043f, g = 0.047f, b = 0.165f; 
	t.p1x = originx + (-0.073f) * resize; t.p1y = originy + (0.528f) * resize;	
	t.p2x = originx + (0.0f) * resize;    t.p2y = originy + (0.3f) * resize;	
	t.p3x = originx + (-0.073f) * resize; t.p3y = originy + (0.467f) * resize;	
	drawTriangle(t, r, g, b, rotationAngle);
}

void drawTriangle(struct Triangle t, float r, float g, float b, float rotationAngle)
{
	float x = 0.0f;
	float y = 0.0f;
	float resize = 1.0f;

	glBegin(GL_TRIANGLES);

	glColor3f(r, g, b);
	MY_POINT p1 = {x + (t.p1x) * resize, y + (t.p1y) * resize, 0.0f};
	p1 = rotatePoint(p1, rotationAngle);
	glVertex3f(p1.x, p1.y, p1.z);

	glColor3f(r, g, b);
	MY_POINT p2 = {x + (t.p2x) * resize, y + (t.p2y) * resize, 0.0f};
	p2 = rotatePoint(p2, rotationAngle);
	glVertex3f(p2.x, p2.y, p2.z);

	glColor3f(r, g, b);
	MY_POINT p3 = {x + (t.p3x) * resize, y + (t.p3y) * resize, 0.0f};
	p3 = rotatePoint(p3, rotationAngle);
	glVertex3f(p3.x, p3.y, p3.z);

	glEnd();
}

void drawQuadrilateral(struct Quadrilateral q, float r, float g, float b, float rotationAngle)
{
	float x = 0.0f;
	float y = 0.0f;
	float resize = 1.0f;

	glBegin(GL_QUADS);

	glColor3f(r, g, b);
	MY_POINT p1 = {x + (q.p1x) * resize, y + (q.p1y) * resize, 0.0f};
	p1 = rotatePoint(p1, rotationAngle);
	glVertex3f(p1.x, p1.y, p1.z);

	glColor3f(r, g, b);
	MY_POINT p2 = {x + (q.p2x) * resize, y + (q.p2y) * resize, 0.0f};
	p2 = rotatePoint(p2, rotationAngle);
	glVertex3f(p2.x, p2.y, p2.z);

	glColor3f(r, g, b);
	MY_POINT p3 = {x + (q.p3x) * resize, y + (q.p3y) * resize, 0.0f};
	p3 = rotatePoint(p3, rotationAngle);
	glVertex3f(p3.x, p3.y, p3.z);

	glColor3f(r, g, b);
	MY_POINT p4 = {x + (q.p4x) * resize, y + (q.p4y) * resize, 0.0f};
	p4 = rotatePoint(p4, rotationAngle);
	glVertex3f(p4.x, p4.y, p4.z);

	glEnd();
}



void drawButterfly(float originx, float originy, float resize, float rotationAngle)
{
	drawRightHalfOfBody(originx, originy, resize, rotationAngle);
	drawLeftHalfOfBody(originx, originy, resize, rotationAngle);
	drawRightWing(originx, originy, resize, rotationAngle);
	drawLeftWing(originx, originy, resize, rotationAngle);
}

