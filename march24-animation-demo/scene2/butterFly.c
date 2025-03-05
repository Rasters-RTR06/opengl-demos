void drawRightWing(void);
void drawLeftWing(void);
void drawRightHalfOfBody();
void drawLeftHalfOfBody();

void drawTriangle(struct Triangle, float, float, float);
void drawQuadrilateral(struct Quadrilateral, float, float, float);
void drawPentagon(struct Pentagon, float, float, float);

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

struct Pentagon
{
	float p1x;
	float p1y;

	float p2x;
	float p2y;

	float p3x;
	float p3y;

	float p4x;
	float p4y;

	float p5x;
	float p5y;
};

void drawRightWing()
{
	struct Triangle t;
	struct Quadrilateral q;
	float r = 0.0f, g = 0.0f, b = 0.0f;
	
	//Right side of the wing
	r = 0.216f, g = 0.612f, b = 0.89f;	//0.216, 0.612, 0.89	//1
	t.p1x = 0.3f;   t.p1y = 0.2f;	
	t.p2x = 0.073f; t.p2y = 0.13f;	//0.073,0.13
	t.p3x = 0.13f;  t.p3y = 0.0f;	
	drawTriangle(t,r,g,b);

	r = 0.314f, g = 0.757f, b = 0.976f;	//0.314, 0.757, 0.976	//2
	t.p1x = 0.3f;   t.p1y = 0.2f;
	t.p2x = 0.073f; t.p2y = 0.13f;	
	t.p3x = 0.174f; t.p3y = 0.473f;	//0.174,0.473
	drawTriangle(t, r, g, b);

	r = 0.251f, g = 0.667f, b = 0.91f;	//0.251, 0.667, 0.91	//3
	t.p1x = 0.3f;   t.p1y = 0.2f;	
	t.p2x = 0.174f; t.p2y = 0.473f;	//0.175,0.473
	t.p3x = 0.4f;   t.p3y = 0.55f; //0.4,0.55
	drawTriangle(t, r, g, b);

	r = 0.173f, g = 0.435f, b = 0.761f;	//0.173, 0.435, 0.761	//4
	t.p1x = 0.3f;   t.p1y = 0.2f;	
	t.p2x = 0.4f;   t.p2y = 0.55f;	//0.17,0.47
	t.p3x = 0.55f;  t.p3y = 0.2f; //0.545,0.724
	drawTriangle(t, r, g, b);

	r = 0.051f, g = 0.078f, b = 0.31f;	//0.051, 0.078, 0.31	//Yellow T
	t.p1x = 0.4f;   t.p1y = 0.55f;
	t.p2x = 0.174f; t.p2y = 0.473f;	//0.17,0.47
	t.p3x = 0.55f;  t.p3y = 0.73f; //0.545,0.724
	drawTriangle(t, r, g, b);

	r = 0.176f, g = 0.573f, b = 0.804f;	//0.176, 0.573, 0.804	//5
	t.p1x = 0.3f;  t.p1y = 0.2f;	 
	t.p2x = 0.55f; t.p2y = 0.2f;	
	t.p3x = 0.5f;  t.p3y = 0.0f;
	drawTriangle(t, r, g, b);

	r = 0.212f, g = 0.847f, b = 0.965f;	//0.212, 0.847, 0.965	//6
	t.p1x = 0.3f;  t.p1y = 0.2f;		
	t.p2x = 0.5f;  t.p2y = 0.0f;		
	t.p3x = 0.13f; t.p3y = 0.0f;		
	drawTriangle(t, r, g, b);

	//0.66,0.55
	r = 0.09f, g = 0.243f, b = 0.482f;	//0.09, 0.243, 0.482	//1
	t.p1x = 0.66f; t.p1y = 0.55f;
	t.p2x = 0.40f; t.p2y = 0.55f;
	t.p3x = 0.55f; t.p3y = 0.2f;
	drawTriangle(t, r, g, b);

	r = 0.11f, g = 0.141f, b = 0.325f;	//0.11, 0.141, 0.325	//2
	t.p1x = 0.66f; t.p1y = 0.55f;
	t.p2x = 0.4f;  t.p2y = 0.55f;
	t.p3x = 0.55f; t.p3y = 0.73f;
	drawTriangle(t, r, g, b);
	
	r = 0.188f, g = 0.204f, b = 0.31f;	//0.188, 0.204, 0.31	//3
	t.p1x = 0.66f;  t.p1y = 0.55f;
	t.p2x = 0.55f;  t.p2y = 0.73f;
	t.p3x = 0.77f;  t.p3y = 0.75f;
	drawTriangle(t, r, g, b);

	r = 0.188f, g = 0.204f, b = 0.31f;	//0.188, 0.204, 0.31	//4
	t.p1x = 0.66f;  t.p1y = 0.55f;
	t.p2x = 0.77f;  t.p2y = 0.75f;
	t.p3x = 0.85f;  t.p3y = 0.4f;
	drawTriangle(t, r, g, b);

	r = 0.137f, g = 0.157f, b = 0.251f;	//0.137, 0.157, 0.251	//5
	t.p1x = 0.66f;  t.p1y = 0.55f;
	t.p2x = 0.85f;  t.p2y = 0.4f;
	t.p3x = 0.7f;  t.p3y = 0.1f;
	drawTriangle(t, r, g, b);

	r = 0.094f, g = 0.051f, b = 0.18f;	//0.094, 0.051, 0.18	//5
	q.p1x = 0.66f;  q.p1y = 0.55f;
	q.p2x = 0.7f;  q.p2y = 0.1f;
	q.p3x = 0.5f;   q.p3y = 0.0f;
	q.p4x = 0.55f;   q.p4y = 0.2f;
	drawQuadrilateral(q, r, g, b);

	//Bottom part of right wing
	r = 0.212f, g = 0.776f, b = 0.965f;	//0.212, 0.776, 0.965	//1 : orange
	t.p1x = 0.3f;  t.p1y = -0.27f;
	t.p2x = 0.07f; t.p2y = -0.12f;
	t.p3x = 0.13f; t.p3y = 0.0f;
	drawTriangle(t, r, g, b);

	r = 0.129f, g = 0.62f, b = 0.792f;	//0.129, 0.62, 0.792	//2 : orange
	t.p1x = 0.3f;  t.p1y = -0.27f;
	t.p2x = 0.13f; t.p2y = 0.0f;	
	t.p3x = 0.53f; t.p3y = -0.32f;//0.53,-0.32
	drawTriangle(t, r, g, b);

	r = 0.114f, g = 0.612f, b = 0.773f;	//0.114, 0.612, 0.773	//3 : orange
	t.p1x = 0.3f;  t.p1y = -0.27f;
	t.p2x = 0.13f; t.p2y = 0.0f;	//0.22,-0.63
	t.p3x = 0.53f; t.p3y = -0.32f;
	drawTriangle(t, r, g, b);

	r = 0.133f, g = 0.804f, b = 0.914f;	//0.133, 0.804, 0.914	//3 : orange
	t.p1x = 0.3f;  t.p1y = -0.27f;
	t.p2x = 0.53f; t.p2y = -0.32f;	//0.22,-0.63
	t.p3x = 0.22f; t.p3y = -0.63f;
	drawTriangle(t, r, g, b);

	r = 0.263f, g = 0.957f, b = 0.988f;	//0.263, 0.957, 0.988	//4 : orange
	t.p1x = 0.3f;  t.p1y = -0.27f;
	t.p2x = 0.22f; t.p2y = -0.63f;	//0.22,-0.63
	t.p3x = 0.07f; t.p3y = -0.12f;
	drawTriangle(t, r, g, b);

	//0.53,-0.32
	r = 0.188f, g = 0.549f, b = 0.835f;	//0.188, 0.549, 0.835	//1 : yellow
	t.p1x = 0.53f;  t.p1y = -0.32f;
	t.p2x = 0.13f;  t.p2y = 0.0f;	
	t.p3x = 0.5f;  t.p3y = -0.0f;
	drawTriangle(t, r, g, b);

	r = 0.125f, g = 0.494f, b = 0.596f;	//0.125, 0.494, 0.596	//2 : yellow
	t.p1x = 0.53f;  t.p1y = -0.32f;
	t.p2x = 0.5f;  t.p2y = 0.00f;
	t.p3x = 0.655f;  t.p3y = -0.24f;	//0.655,-0.24
	drawTriangle(t, r, g, b);

	r = 0.125f, g = 0.494f, b = 0.596f;	//0.157, 0.596, 0.745	//3 : yellow
	t.p1x = 0.53f;  t.p1y = -0.32f;
	t.p2x = 0.655f;  t.p2y = -0.24f;
	t.p3x = 0.49f;  t.p3y = -0.72f;	//0.49,-0.72
	drawTriangle(t, r, g, b);

	r = 0.2f, g = 0.702f, b = 0.878f;	//0.2, 0.702, 0.878	//4 : yellow
	t.p1x = 0.53f;  t.p1y = -0.32f;
	t.p2x = 0.49f;  t.p2y = -0.72f;
	t.p3x = 0.22f;  t.p3y = -0.63f;	//
	drawTriangle(t, r, g, b);

	//tip of bottom
	r = 0.141f, g = 0.227f, b = 0.424f;	//0.141, 0.227, 0.424	//4 : yellow
	t.p1x = 0.22f;  t.p1y = -0.63f;
	t.p2x = 0.49f;  t.p2y = -0.72f;//
	t.p3x = 0.3f;  t.p3y = -0.8f;	
	drawTriangle(t, r, g, b);

	r = 0.031f, g = 0.063f, b = 0.318f;	//0.031, 0.063, 0.318	//4 : yellow
	t.p1x = 0.3f;  t.p1y = -0.8f;
	t.p2x = 0.49f;  t.p2y = -0.72f;//	//0.49,-0.93
	t.p3x = 0.5f;  t.p3y = -0.93f;
	drawTriangle(t, r, g, b);
}

void drawLeftWing()
{
	struct Triangle t;
	struct Quadrilateral q;
	float r = 0.0f, g = 0.0f, b = 0.0f;

	//Right side of the wing
	r = 0.216f, g = 0.612f, b = 0.89f;	//0.216, 0.612, 0.89	//1
	t.p1x = -0.3f;   t.p1y = 0.2f;
	t.p2x = -0.073f; t.p2y = 0.13f;	//0.073,0.13
	t.p3x = -0.13f;  t.p3y = 0.0f;
	drawTriangle(t, r, g, b);

	r = 0.314f, g = 0.757f, b = 0.976f;	//0.314, 0.757, 0.976	//2
	t.p1x = -0.3f;   t.p1y = 0.2f;
	t.p2x = -0.073f; t.p2y = 0.13f;
	t.p3x = -0.174f; t.p3y = 0.473f;	//0.174,0.473
	drawTriangle(t, r, g, b);

	r = 0.251f, g = 0.667f, b = 0.91f;	//0.251, 0.667, 0.91	//3
	t.p1x = -0.3f;   t.p1y = 0.2f;
	t.p2x = -0.174f; t.p2y = 0.473f;	//0.175,0.473
	t.p3x = -0.4f;   t.p3y = 0.55f; //0.4,0.55
	drawTriangle(t, r, g, b);

	r = 0.173f, g = 0.435f, b = 0.761f;	//0.173, 0.435, 0.761	//4
	t.p1x = -0.3f;   t.p1y = 0.2f;
	t.p2x = -0.4f;   t.p2y = 0.55f;	//0.17,0.47
	t.p3x = -0.55f;  t.p3y = 0.2f; //0.545,0.724
	drawTriangle(t, r, g, b);

	r = 0.051f, g = 0.078f, b = 0.31f;	//0.051, 0.078, 0.31	//Yellow T
	t.p1x = -0.4f;   t.p1y = 0.55f;
	t.p2x = -0.174f; t.p2y = 0.473f;	//0.17,0.47
	t.p3x = -0.55f;  t.p3y = 0.73f; //0.545,0.724
	drawTriangle(t, r, g, b);

	r = 0.176f, g = 0.573f, b = 0.804f;	//0.176, 0.573, 0.804	//5
	t.p1x = -0.3f;  t.p1y = 0.2f;
	t.p2x = -0.55f; t.p2y = 0.2f;
	t.p3x = -0.5f;  t.p3y = 0.0f;
	drawTriangle(t, r, g, b);

	r = 0.212f, g = 0.847f, b = 0.965f;	//0.212, 0.847, 0.965	//6
	t.p1x = -0.3f;  t.p1y = 0.2f;
	t.p2x = -0.5f;  t.p2y = 0.0f;
	t.p3x = -0.13f; t.p3y = 0.0f;
	drawTriangle(t, r, g, b);

	//0.66,0.55
	r = 0.09f, g = 0.243f, b = 0.482f;	//0.09, 0.243, 0.482	//1
	t.p1x = -0.66f; t.p1y = 0.55f;
	t.p2x = -0.40f; t.p2y = 0.55f;
	t.p3x = -0.55f; t.p3y = 0.2f;
	drawTriangle(t, r, g, b);

	r = 0.11f, g = 0.141f, b = 0.325f;	//0.11, 0.141, 0.325	//2
	t.p1x = -0.66f; t.p1y = 0.55f;
	t.p2x = -0.4f;  t.p2y = 0.55f;
	t.p3x = -0.55f; t.p3y = 0.73f;
	drawTriangle(t, r, g, b);

	r = 0.188f, g = 0.204f, b = 0.31f;	//0.188, 0.204, 0.31	//3
	t.p1x = -0.66f;  t.p1y = 0.55f;
	t.p2x = -0.55f;  t.p2y = 0.73f;
	t.p3x = -0.77f;  t.p3y = 0.75f;
	drawTriangle(t, r, g, b);

	r = 0.188f, g = 0.204f, b = 0.31f;	//0.188, 0.204, 0.31	//4
	t.p1x = -0.66f;  t.p1y = 0.55f;
	t.p2x = -0.77f;  t.p2y = 0.75f;
	t.p3x = -0.85f;  t.p3y = 0.4f;
	drawTriangle(t, r, g, b);

	r = 0.137f, g = 0.157f, b = 0.251f;	//0.137, 0.157, 0.251	//5
	t.p1x = -0.66f;  t.p1y = 0.55f;
	t.p2x = -0.85f;  t.p2y = 0.4f;
	t.p3x = -0.7f;  t.p3y = 0.1f;
	drawTriangle(t, r, g, b);

	r = 0.094f, g = 0.051f, b = 0.18f;	//0.094, 0.051, 0.18	//5
	q.p1x = -0.66f;  q.p1y = 0.55f;
	q.p2x = -0.7f;  q.p2y = 0.1f;
	q.p3x = -0.5f;   q.p3y = 0.0f;
	q.p4x = -0.55f;   q.p4y = 0.2f;
	drawQuadrilateral(q, r, g, b);

	//Bottom part of right wing
	r = 0.212f, g = 0.776f, b = 0.965f;	//0.212, 0.776, 0.965	//1 : orange
	t.p1x = -0.3f;  t.p1y = -0.27f;
	t.p2x = -0.07f; t.p2y = -0.12f;
	t.p3x = -0.13f; t.p3y = 0.0f;
	drawTriangle(t, r, g, b);

	r = 0.129f, g = 0.62f, b = 0.792f;	//0.129, 0.62, 0.792	//2 : orange
	t.p1x = -0.3f;  t.p1y = -0.27f;
	t.p2x = -0.13f; t.p2y = 0.0f;
	t.p3x = -0.53f; t.p3y = -0.32f;//0.53,-0.32
	drawTriangle(t, r, g, b);

	r = 0.114f, g = 0.612f, b = 0.773f;	//0.114, 0.612, 0.773	//3 : orange
	t.p1x = -0.3f;  t.p1y = -0.27f;
	t.p2x = -0.13f; t.p2y = 0.0f;	//0.22,-0.63
	t.p3x = -0.53f; t.p3y = -0.32f;
	drawTriangle(t, r, g, b);

	r = 0.133f, g = 0.804f, b = 0.914f;	//0.133, 0.804, 0.914	//3 : orange
	t.p1x = -0.3f;  t.p1y = -0.27f;
	t.p2x = -0.53f; t.p2y = -0.32f;	//0.22,-0.63
	t.p3x = -0.22f; t.p3y = -0.63f;
	drawTriangle(t, r, g, b);

	r = 0.263f, g = 0.957f, b = 0.988f;	//0.263, 0.957, 0.988	//4 : orange
	t.p1x = -0.3f;  t.p1y = -0.27f;
	t.p2x = -0.22f; t.p2y = -0.63f;	//0.22,-0.63
	t.p3x = -0.07f; t.p3y = -0.12f;
	drawTriangle(t, r, g, b);

	//0.53,-0.32
	r = 0.188f, g = 0.549f, b = 0.835f;	//0.188, 0.549, 0.835	//1 : yellow
	t.p1x = -0.53f;  t.p1y = -0.32f;
	t.p2x = -0.13f;  t.p2y = 0.0f;
	t.p3x = -0.5f;  t.p3y = -0.0f;
	drawTriangle(t, r, g, b);

	r = 0.125f, g = 0.494f, b = 0.596f;	//0.125, 0.494, 0.596	//2 : yellow
	t.p1x = -0.53f;  t.p1y = -0.32f;
	t.p2x = -0.5f;  t.p2y = 0.00f;
	t.p3x = -0.655f;  t.p3y = -0.24f;	//0.655,-0.24
	drawTriangle(t, r, g, b);

	r = 0.125f, g = 0.494f, b = 0.596f;	//0.157, 0.596, 0.745	//3 : yellow
	t.p1x = -0.53f;  t.p1y = -0.32f;
	t.p2x = -0.655f;  t.p2y = -0.24f;
	t.p3x = -0.49f;  t.p3y = -0.72f;	//0.49,-0.72
	drawTriangle(t, r, g, b);

	r = 0.2f, g = 0.702f, b = 0.878f;	//0.2, 0.702, 0.878	//4 : yellow
	t.p1x = -0.53f;  t.p1y = -0.32f;
	t.p2x = -0.49f;  t.p2y = -0.72f;
	t.p3x = -0.22f;  t.p3y = -0.63f;	//
	drawTriangle(t, r, g, b);

	//tip of bottom
	r = 0.141f, g = 0.227f, b = 0.424f;	//0.141, 0.227, 0.424	//4 : yellow
	t.p1x = -0.22f;  t.p1y = -0.63f;
	t.p2x = -0.49f;  t.p2y = -0.72f;//
	t.p3x = -0.3f;  t.p3y = -0.8f;
	drawTriangle(t, r, g, b);

	r = 0.031f, g = 0.063f, b = 0.318f;	//0.031, 0.063, 0.318	//4 : yellow
	t.p1x = -0.3f;  t.p1y = -0.8f;
	t.p2x = -0.49f;  t.p2y = -0.72f;//	//0.49,-0.93
	t.p3x = -0.5f;  t.p3y = -0.93f;
	drawTriangle(t, r, g, b);
}

void drawRightHalfOfBody()
{
	struct Quadrilateral q;
	struct Pentagon p;
	struct Triangle t;
	float r = 0.0f, g = 0.0f, b = 0.0f;
	r = 0.071f, g = 0.071f, b = 0.18f;	//0.071, 0.071, 0.18	//1
	t.p1x = 0.0f; t.p1y = 0.3f;	//0,0.377
	t.p2x = 0.0f; t.p2y = 0.0f;	//
	t.p3x = 0.073f; t.p3y = 0.123f;	//0.073,0.123
	drawTriangle(t, r, g, b);

	
	r = 0.094f, g = 0.278f, b = 0.392f;	//0.094, 0.278, 0.392	//2
	t.p1x = 0.073f; t.p1y = 0.13f;	//0.073,0.13
	t.p2x = 0.0f; t.p2y = 0.0f;		//0,0
	t.p3x = 0.13f; t.p3y = 0.0f;	//0.14,0.067
	drawTriangle(t, r, g, b);

	r = 0.09f, g = 0.337f, b = 0.388f; //0.09, 0.337, 0.388	//3
	t.p1x = 0.13f; t.p1y = 0.0f;	//0,0.377
	t.p2x = 0.0f; t.p2y = 0.0f;		//0.02,0.08
	t.p3x = 0.057f; t.p3y = -0.114f;	//0.057,-0.114
	drawTriangle(t, r, g, b);

	r = 0.071f, g = 0.075f, b = 0.161f; //0.09, 0.337, 0.388	//4
	t.p1x = 0.057f; t.p1y = -0.114f;	//0,0.377
	t.p2x = 0.0f; t.p2y = 0.0f;		//0.02,0.08
	t.p3x = 0.0f; t.p3y = -0.4f;	//
	drawTriangle(t, r, g, b);

	r = 0.098f, g = 0.2f, b = 0.204f; //0.098, 0.2, 0.204
	t.p1x = 0.042f; t.p1y = -0.191f;	//0,0.377
	t.p2x = 0.0f; t.p2y = 0.0f;		//0.02,0.08
	t.p3x = 0.0f; t.p3y = -0.42f;	//0.042,-0.191
	drawTriangle(t, r, g, b);

	r = 0.043f, g = 0.047f, b = 0.165f; //0.043, 0.047, 0.165
	t.p1x = 0.073f; t.p1y = 0.528f;	//0.09,0.528
	t.p2x = 0.0f; t.p2y = 0.3f;		//0,0.327
	t.p3x = 0.073f; t.p3y = 0.467f;		//0.095,0.467
	drawTriangle(t, r, g, b);
}
void drawLeftHalfOfBody()
{
	struct Quadrilateral q;
	struct Pentagon p;
	struct Triangle t;
	float r = 0.0f, g = 0.0f, b = 0.0f;
	r = 0.071f, g = 0.071f, b = 0.18f;	//0.071, 0.071, 0.18	//1
	t.p1x = 0.0f;    t.p1y = 0.3f;	//0,0.377
	t.p2x = 0.0f;    t.p2y = 0.0f;	//
	t.p3x = -0.073f; t.p3y = 0.123f;	//0.073,0.123
	drawTriangle(t, r, g, b);


	r = 0.094f, g = 0.278f, b = 0.392f;	//0.094, 0.278, 0.392	//2
	t.p1x = -0.073f; t.p1y = 0.13f;	//0.073,0.13
	t.p2x = 0.0f; t.p2y = 0.0f;		//0,0
	t.p3x = -0.13f; t.p3y = 0.0f;	//0.14,0.067
	drawTriangle(t, r, g, b);

	r = 0.09f, g = 0.337f, b = 0.388f; //0.09, 0.337, 0.388	//3
	t.p1x = -0.13f; t.p1y = 0.0f;	//0,0.377
	t.p2x = 0.0f; t.p2y = 0.0f;		//0.02,0.08
	t.p3x = -0.057f; t.p3y = -0.114f;	//0.057,-0.114
	drawTriangle(t, r, g, b);

	r = 0.071f, g = 0.075f, b = 0.161f; //0.09, 0.337, 0.388	//4
	t.p1x = -0.057f; t.p1y = -0.114f;	//0,0.377
	t.p2x = 0.0f; t.p2y = 0.0f;		//0.02,0.08
	t.p3x = 0.0f; t.p3y = -0.4f;	//
	drawTriangle(t, r, g, b);

	r = 0.098f, g = 0.2f, b = 0.204f; //0.098, 0.2, 0.204
	t.p1x = -0.042f; t.p1y = -0.191f;	//0,0.377
	t.p2x = 0.0f; t.p2y = 0.0f;		//0.02,0.08
	t.p3x = 0.0f; t.p3y = -0.42f;	//0.042,-0.191
	drawTriangle(t, r, g, b);

	r = 0.043f, g = 0.047f, b = 0.165f; //0.043, 0.047, 0.165
	t.p1x = -0.073f; t.p1y = 0.528f;	//0.09,0.528
	t.p2x = 0.0f; t.p2y = 0.3f;		//0,0.327
	t.p3x = -0.073f; t.p3y = 0.467f;		//0.095,0.467
	drawTriangle(t, r, g, b);
}

void drawTriangle(struct Triangle t, float r, float g, float b)
{
	float x = 0.0f;
	float y = 0.0f;
	float resize = 1.0f;

	glBegin(GL_TRIANGLES);

	glColor3f(r, g, b);
	glVertex3f(x + (t.p1x) * resize, y + (t.p1y) * resize, 0.0f);
	glColor3f(r, g, b);
	glVertex3f(x + (t.p2x) * resize, y + (t.p2y) * resize, 0.0f);
	glColor3f(r, g, b);
	glVertex3f(x + (t.p3x) * resize, y + (t.p3y) * resize, 0.0f);

	glEnd();
}

void drawQuadrilateral(struct Quadrilateral q, float r, float g, float b)
{
	float x = 0.0f;
	float y = 0.0f;
	float resize = 1.0f;

	glBegin(GL_QUADS);
	//printf("Drawing eye");
	glColor3f(r, g, b);
	glVertex3f(x + (q.p1x) * resize, y + (q.p1y) * resize, 0.0f);
	glColor3f(r, g, b);
	glVertex3f(x + (q.p2x) * resize, y + (q.p2y) * resize, 0.0f);
	glColor3f(r, g, b);
	glVertex3f(x + (q.p3x) * resize, y + (q.p3y) * resize, 0.0f);
	glColor3f(r, g, b);
	glVertex3f(x + (q.p4x) * resize, y + (q.p4y) * resize, 0.0f);

	glEnd();
}

void drawPentagon(struct Pentagon p, float r, float g, float b)
{
	float x = 0.0f;
	float y = 0.0f;
	float resize = 1.0f;

	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex3f(x + (p.p1x) * resize, y + (p.p1y) * resize, 0.0f);
	glColor3f(r, g, b);
	glVertex3f(x + (p.p2x) * resize, y + (p.p2y) * resize, 0.0f);
	glColor3f(r, g, b);
	glVertex3f(x + (p.p3x) * resize, y + (p.p3y) * resize, 0.0f);
	glColor3f(r, g, b);
	glVertex3f(x + (p.p4x) * resize, y + (p.p4y) * resize, 0.0f);
	glColor3f(r, g, b);
	glVertex3f(x + (p.p5x) * resize, y + (p.p5y) * resize, 0.0f);
	glEnd();
}


