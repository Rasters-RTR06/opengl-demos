
#define GOLD 0.859, 0.616, 0.051
#define SKIN 0.286, 0.231, 0.196
#define PITAMBER 0.7765, 0.5686, 0.3373
#define stBLACK 0.0, 0.0, 0.0
#define WHITE 1, 1, 1

void stmukut(float originx, float originy, float resize, float angle)
{
	glPushMatrix();
	glRotatef( angle, 0.0f, 0.0f, 1.0f);
	// CROWN
	// Triangle 1
	glBegin(GL_TRIANGLES);
	glColor3f(GOLD);
	glVertex2f(originx + -0.496*resize, originy + 0.728*resize);
	glVertex2f(originx + -0.309*resize, originy + 0.861*resize);
	glVertex2f(originx + -0.109*resize, originy + 0.743*resize);
	glEnd();
	// Triangle 2
	glBegin(GL_TRIANGLES);
	glVertex2f(originx + -0.496*resize, originy + 0.728*resize);
	glVertex2f(originx + -0.526*resize, originy + 0.796*resize);
	glVertex2f(originx + -0.417*resize, originy + 0.728*resize);
	glEnd();
	// Triangle 3
	glBegin(GL_TRIANGLES);
	glVertex2f(originx + -0.109*resize, originy + 0.743*resize);
	glVertex2f(originx + -0.074*resize, originy + 0.883*resize);
	glVertex2f(originx + -0.143*resize, originy + 0.740*resize);
	glEnd();
	// Triangle 4
	glBegin(GL_TRIANGLES);
	glColor3f(0.341, 0.659, 0.224);
	glVertex2f(originx + -0.470*resize, originy + 0.865*resize);
	glVertex2f(originx + -0.483*resize, originy + 0.825*resize);
	glVertex2f(originx + -0.413*resize, originy + 0.846*resize);
	glEnd();
	// Triangle 5
	glBegin(GL_TRIANGLES);
	glColor3f(0.031, 0.035, 0.729);
	glVertex2f(originx + -0.483*resize, originy + 0.825*resize);
	glVertex2f(originx + -0.426*resize, originy + 0.806*resize);
	glVertex2f(originx + -0.413*resize, originy + 0.846*resize);
	glEnd();
	// Polygon 6
	glBegin(GL_POLYGON);
	glColor3f(GOLD);
	glVertex2f(originx + -0.496*resize, originy + 0.728*resize);
	glVertex2f(originx + -0.109*resize, originy + 0.743*resize);
	glVertex2f(originx + -0.104*resize, originy + 0.796*resize);
	glVertex2f(originx + -0.513*resize, originy + 0.777*resize);
	glEnd();
	// Polygon 7
	glBegin(GL_POLYGON);
	glVertex2f(originx + -0.496*resize, originy + 0.728*resize);
	glVertex2f(originx + -0.443*resize, originy + 0.808*resize);
	glVertex2f(originx + -0.383*resize, originy + 0.824*resize);
	glVertex2f(originx + -0.230*resize, originy + 0.830*resize);
	glVertex2f(originx + -0.161*resize, originy + 0.824*resize);
	glVertex2f(originx + -0.109*resize, originy + 0.743*resize);
	glEnd();
	// Polygon 8
	glBegin(GL_POLYGON);
	glVertex2f(originx + -0.496*resize, originy + 0.728*resize);
	glVertex2f(originx + -0.374*resize, originy + 0.842*resize);
	glVertex2f(originx + -0.243*resize, originy + 0.849*resize);
	glVertex2f(originx + -0.109*resize, originy + 0.743*resize);
	glEnd();
	glPopMatrix();
}

void KrishnaStanding(float originx, float originy, float resize)
{

	// CHEST
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.093*resize, originy + 0.364*resize);
	glVertex2f(originx + -0.214*resize, originy + 0.340*resize);
	glVertex2f(originx + -0.265*resize, originy + 0.308*resize);
	glVertex2f(originx + -0.298*resize, originy + 0.252*resize);
	glVertex2f(originx + -0.391*resize, originy + 0.056*resize);
	glVertex2f(originx + 0.428*resize, originy + -0.056*resize);
	glVertex2f(originx + 0.414*resize, originy + 0.062*resize);
	glVertex2f(originx + 0.409*resize, originy + 0.196*resize);
	glVertex2f(originx + 0.386*resize, originy + 0.249*resize);
	glVertex2f(originx + 0.344*resize, originy + 0.293*resize);
	glVertex2f(originx + 0.274*resize, originy + 0.328*resize);
	glVertex2f(originx + 0.195*resize, originy + 0.358*resize);
	glVertex2f(originx + 0.144*resize, originy + 0.370*resize);
	glVertex2f(originx + 0.009*resize, originy + 0.308*resize);
	glEnd();
	// face
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.167*resize, originy + 0.660*resize);
	glVertex2f(originx + -0.200*resize, originy + 0.563*resize);
	glVertex2f(originx + -0.233*resize, originy + 0.516*resize);
	glVertex2f(originx + -0.191*resize, originy + 0.516*resize);
	glVertex2f(originx + -0.205*resize, originy + 0.463*resize);
	glVertex2f(originx + -0.070*resize, originy + 0.422*resize);
	glVertex2f(originx + -0.093*resize, originy + 0.364*resize);
	glVertex2f(originx + 0.009*resize, originy + 0.308*resize);
	glVertex2f(originx + 0.144*resize, originy + 0.370*resize);
	glVertex2f(originx + 0.140*resize, originy + 0.413*resize);
	glVertex2f(originx + 0.219*resize, originy + 0.504*resize);
	glVertex2f(originx + 0.233*resize, originy + 0.610*resize);
	glVertex2f(originx + 0.019*resize, originy + 0.657*resize);
	glEnd();

	// SMILE
	glLineWidth(1.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(stBLACK);
	glVertex2f(originx + -0.205*resize, originy + 0.463*resize);
	glVertex2f(originx + -0.158*resize, originy + 0.472*resize);
	glEnd();

	// abdoman
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.186*resize, originy + 0.029*resize);
	glVertex2f(originx + -0.149*resize, originy + -0.150*resize);
	glVertex2f(originx + -0.140*resize, originy + -0.220*resize);
	glVertex2f(originx + -0.009*resize, originy + -0.252*resize);
	glVertex2f(originx + 0.177*resize, originy + -0.214*resize);
	glVertex2f(originx + 0.247*resize, originy + -0.023*resize);
	glEnd();

	// ELBOW
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + 0.247*resize, originy + -0.023*resize);
	glVertex2f(originx + 0.265*resize, originy + -0.155*resize);
	glVertex2f(originx + 0.484*resize, originy + -0.164*resize);
	glVertex2f(originx + 0.428*resize, originy + -0.056*resize);
	glEnd();
	// ELBOW
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + 0.265*resize, originy + -0.155*resize);
	glVertex2f(originx + 0.493*resize, originy + -0.375*resize);
	glVertex2f(originx + 0.595*resize, originy + -0.334*resize);
	glVertex2f(originx + 0.484*resize, originy + -0.164*resize);
	glEnd();
	// wrist
	glBegin(GL_POLYGON);
	glColor3f(GOLD);
	glVertex2f(originx + 0.493*resize, originy + -0.375*resize);
	glVertex2f(originx + 0.567*resize, originy + -0.431*resize);
	glVertex2f(originx + 0.674*resize, originy + -0.408*resize);
	glVertex2f(originx + 0.595*resize, originy + -0.334*resize);
	glEnd();

	// flute
	glBegin(GL_QUADS);
	glColor3f(stBLACK);
	glVertex2f(originx + 0.288*resize, originy + -0.554*resize);
	glVertex2f(originx + 0.949*resize, originy + -0.396*resize);
	glVertex2f(originx + 0.947*resize, originy + -0.392*resize);
	glVertex2f(originx + 0.286*resize, originy + -0.550*resize);

	glEnd();

	// PALm
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + 0.567*resize, originy + -0.431*resize);
	glVertex2f(originx + 0.591*resize, originy + -0.472*resize);
	glVertex2f(originx + 0.581*resize, originy + -0.507*resize);
	glVertex2f(originx + 0.670*resize, originy + -0.531*resize);
	glVertex2f(originx + 0.730*resize, originy + -0.466*resize);
	glVertex2f(originx + 0.674*resize, originy + -0.408*resize);
	glEnd();

	// otherelebow
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.186*resize, originy + 0.029*resize);
	glVertex2f(originx + -0.223*resize, originy + -0.103*resize);
	glVertex2f(originx + -0.349*resize, originy + -0.150*resize);
	glVertex2f(originx + -0.391*resize, originy + 0.056*resize);
	glEnd();
	// otherelebow
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.391*resize, originy + 0.056*resize);
	glVertex2f(originx + -0.474*resize, originy + 0.132*resize);
	glVertex2f(originx + -0.609*resize, originy + 0.106*resize);
	glVertex2f(originx + -0.451*resize, originy + -0.088*resize);
	glEnd();
	// otherelbow
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.391*resize, originy + 0.056*resize);
	glVertex2f(originx + -0.451*resize, originy + -0.088*resize);
	glVertex2f(originx + -0.349*resize, originy + -0.150*resize);
	glEnd();
	// palm
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.553*resize, originy + 0.235*resize);
	glVertex2f(originx + -0.600*resize, originy + 0.287*resize);
	glVertex2f(originx + -0.577*resize, originy + 0.478*resize);
	glVertex2f(originx + -0.609*resize, originy + 0.519*resize);
	glVertex2f(originx + -0.670*resize, originy + 0.352*resize);
	glVertex2f(originx + -0.712*resize, originy + 0.390*resize);
	glVertex2f(originx + -0.707*resize, originy + 0.273*resize);
	glVertex2f(originx + -0.670*resize, originy + 0.220*resize);
	glEnd();
	// WRISTANOTHER
	glBegin(GL_POLYGON);
	glColor3f(GOLD);
	glVertex2f(originx + -0.474*resize, originy + 0.132*resize);
	glVertex2f(originx + -0.553*resize, originy + 0.235*resize);
	glVertex2f(originx + -0.670*resize, originy + 0.220*resize);
	glVertex2f(originx + -0.609*resize, originy + 0.106*resize);
	glEnd();

	// Sovala
	glBegin(GL_TRIANGLES);
	glColor3f(PITAMBER);
	glVertex2f(originx + -0.139*resize, originy + -0.219*resize);
	glVertex2f(originx + -0.251*resize, originy + -0.263*resize);
	glVertex2f(originx + -0.009*resize, originy + -0.252*resize);
	glEnd();
	// Sovala
	glBegin(GL_TRIANGLES);
	glColor3f(PITAMBER);
	glVertex2f(originx +  0.176*resize, originy + -0.214*resize);
	glVertex2f(originx +  0.339*resize, originy + -0.258*resize);
	glVertex2f(originx + -0.009*resize, originy + -0.252*resize);
	glEnd();


	// Sovala
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + -0.009*resize, originy + -0.252*resize);
	glVertex2f(originx + -0.251*resize, originy + -0.263*resize);
	glVertex2f(originx + -0.353*resize, originy + -0.431*resize);
	glVertex2f(originx + -0.409*resize, originy + -0.639*resize);
	glVertex2f(originx + -0.427*resize, originy + -0.759*resize);
	glVertex2f(originx + -0.148*resize, originy + -0.750*resize);
	glVertex2f(originx + 0.037*resize, originy +  -0.741*resize);
	glVertex2f(originx + 0.302*resize, originy +  -0.747*resize);
	glVertex2f(originx + 0.358*resize, originy +  -0.548*resize);
	glVertex2f(originx + 0.339*resize, originy +  -0.258*resize);
	glEnd();
	// Sovala
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + -0.428*resize, originy + -0.760*resize);
	glVertex2f(originx + -0.414*resize, originy + -0.900*resize);
	glVertex2f(originx + -0.270*resize, originy + -0.862*resize);
	glVertex2f(originx + -0.149*resize, originy + -0.751*resize);
	glEnd();
	// Sovala
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + 0.037*resize, originy + -0.742*resize);
	glVertex2f(originx + 0.158*resize, originy + -0.897*resize);
	glVertex2f(originx + 0.270*resize, originy + -0.836*resize);
	glVertex2f(originx + 0.302*resize, originy + -0.748*resize);
	glEnd();
	// Leg
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.149*resize, originy + -0.751*resize);
	glVertex2f(originx + -0.270*resize, originy + -0.862*resize);
	glVertex2f(originx + -0.414*resize, originy + -0.900*resize);
	glVertex2f(originx + -0.419*resize, originy + -1.047*resize);
	glVertex2f(originx + -0.237*resize, originy + -1.062*resize);
	glEnd();
	// Leg
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + 0.302*resize, originy + -0.748*resize);
	glVertex2f(originx + 0.270*resize, originy + -0.836*resize);
	glVertex2f(originx + 0.158*resize, originy + -0.897*resize);
	glVertex2f(originx + 0.237*resize, originy + -1.050*resize);
	glVertex2f(originx + 0.400*resize, originy + -1.035*resize);
	glEnd();
	// Leg
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.419*resize, originy + -1.047*resize);
	glVertex2f(originx + -0.605*resize, originy + -1.067*resize);
	glVertex2f(originx + -0.600*resize, originy + -1.114*resize);
	glVertex2f(originx + -0.265*resize, originy + -1.141*resize);
	glVertex2f(originx + -0.237*resize, originy + -1.062*resize);
	glEnd();
	// Leg
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + 0.237*resize, originy + -1.050*resize);
	glVertex2f(originx + 0.107*resize, originy + -1.076*resize);
	glVertex2f(originx + 0.098*resize, originy + -1.132*resize);
	glVertex2f(originx + 0.395*resize, originy + -1.114*resize);
	glVertex2f(originx + 0.400*resize, originy + -1.035*resize);
	glEnd();

	// wala
	glBegin(GL_LINE_STRIP);
	glColor3f(GOLD);
	glVertex2f(originx + 0.223*resize, originy + -1.023*resize);
	glVertex2f(originx + 0.321*resize, originy + -1.026*resize);
	glVertex2f(originx + 0.395*resize, originy + -1.006*resize);
	glEnd();

	// wala
	glBegin(GL_LINE_STRIP);
	glColor3f(GOLD);
	glVertex2f(originx + -0.419*resize, originy + -1.026*resize);
	glVertex2f(originx + -0.330*resize, originy + -1.041*resize);
	glVertex2f(originx + -0.228*resize, originy + -1.035*resize);
	glEnd();


	// Janeu
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	glColor3f(WHITE);
	glVertex2f(originx + 0.274*resize, originy + 0.328*resize);
	glVertex2f(originx + 0.167*resize, originy + 0.100*resize);
	glVertex2f(originx + -0.023*resize, originy + -0.109*resize);
	glVertex2f(originx + -0.140*resize, originy + -0.220*resize);
	glEnd();
	// UPARANA
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + 0.428*resize, originy + -0.056*resize);
	glVertex2f(originx + 0.340*resize, originy + -0.258*resize);
	glVertex2f(originx + 0.391*resize, originy + -0.519*resize);
	glVertex2f(originx + 0.540*resize, originy + -0.469*resize);
	glVertex2f(originx + 0.493*resize, originy + -0.375*resize);
	glEnd();
	// UPARANA
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + 0.391*resize, originy + -0.519*resize);
	glVertex2f(originx + 0.581*resize, originy + -0.883*resize);
	glVertex2f(originx + 0.805*resize, originy + -0.710*resize);
	glVertex2f(originx + 0.540*resize, originy + -0.469*resize);
	glEnd();
	// UPARANA
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + 0.247*resize, originy + -0.023*resize);
	glVertex2f(originx + 0.414*resize, originy + 0.062*resize);
	glVertex2f(originx + 0.409*resize, originy + 0.196*resize);
	glEnd();

	// UPARANA
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + -0.093*resize, originy + 0.364*resize);
	glVertex2f(originx + -0.214*resize, originy + 0.340*resize);
	glVertex2f(originx + -0.265*resize, originy + 0.308*resize);
	glVertex2f(originx + -0.298*resize, originy + 0.252*resize);
	glVertex2f(originx + -0.391*resize, originy + 0.056*resize);
	glVertex2f(originx + -0.186*resize, originy + 0.029*resize);
	glEnd();

	// UPARANA
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + -0.391*resize, originy + 0.056*resize);
	glVertex2f(originx + -0.451*resize, originy + -0.088*resize);
	glVertex2f(originx + -0.623*resize, originy + -0.557*resize);
	glVertex2f(originx + -0.665*resize, originy + -0.713*resize);
	glVertex2f(originx + -0.609*resize, originy + -0.748*resize);
	glVertex2f(originx + -0.447*resize, originy + -0.674*resize);
	glVertex2f(originx + -0.186*resize, originy + 0.029*resize);
	glEnd();

	// EYE
	glBegin(GL_TRIANGLES);
	glColor3f(stBLACK);
	glVertex2f(originx + -0.163*resize, originy + 0.587*resize);
	glVertex2f(originx + -0.084*resize, originy + 0.592*resize);
	glVertex2f(originx + -0.153*resize, originy + 0.563*resize);
	glEnd();
	// EYE
	glBegin(GL_TRIANGLES);
	glColor3f(WHITE);
	glVertex2f(originx + -0.153*resize, originy + 0.563*resize);
	glVertex2f(originx + 0.065*resize, originy + 0.566*resize);
	glVertex2f(originx + -0.084*resize, originy + 0.592*resize);
	glEnd();


	stmukut(originx +0.22*resize, originy-0.11*resize, resize, -10);

}
