#define GOLD 0.859, 0.616, 0.051
#define SKIN 0.286, 0.231, 0.196
#define PITAMBER 0.7765, 0.5686, 0.3373
#define siBLACK 0, 0, 0
#define WHITE 1, 1, 1

void mukut(float originx, float originy, float resize)
{
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

}

void sittingkrishna(float originx, float originy, float resize)
{

	// Face
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + 0.052*resize, originy + 0.560*resize);
	glVertex2f(originx + -0.329*resize, originy + 0.570*resize);
	glVertex2f(originx + -0.329*resize, originy + 0.448*resize);
	glVertex2f(originx + -0.329*resize, originy + 0.346*resize);
	glVertex2f(originx + -0.292*resize, originy + 0.305*resize);
	glVertex2f(originx + -0.269*resize, originy + 0.290*resize);
	glVertex2f(originx + -0.174*resize, originy + 0.287*resize);
	glVertex2f(originx + -0.186*resize, originy + 0.237*resize);
	glVertex2f(originx + -0.106*resize, originy + 0.159*resize);
	glVertex2f(originx + 0.022*resize, originy + 0.255*resize);
	glVertex2f(originx + -0.004*resize, originy + 0.290*resize);
	glVertex2f(originx + -0.008*resize, originy + 0.343*resize);
	glVertex2f(originx + 0.079*resize, originy + 0.461*resize);
	glEnd();
	// Body
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.186*resize, originy + 0.237*resize);
	glVertex2f(originx + -0.252*resize, originy + 0.224*resize);
	glVertex2f(originx + -0.310*resize, originy + 0.179*resize);
	glVertex2f(originx + -0.358*resize, originy + 0.108*resize);
	glVertex2f(originx + -0.376*resize, originy + -0.048*resize);
	glVertex2f(originx + -0.362*resize, originy + -0.350*resize);
	glVertex2f(originx + -0.348*resize, originy + -0.503*resize);
	glVertex2f(originx + -0.145*resize, originy + -0.475*resize);
	glVertex2f(originx + 0.030*resize, originy + -0.463*resize);
	glVertex2f(originx + 0.257*resize, originy + -0.393*resize);
	glVertex2f(originx + 0.260*resize, originy + -0.073*resize);
	glVertex2f(originx + 0.257*resize, originy + 0.099*resize);
	glVertex2f(originx + 0.233*resize, originy + 0.182*resize);
	glVertex2f(originx + 0.164*resize, originy + 0.210*resize);
	glVertex2f(originx + 0.022*resize, originy + 0.255*resize);
	glVertex2f(originx + -0.106*resize, originy + 0.159*resize);
	glEnd();
	// HandLines
	glBegin(GL_LINE_STRIP);
	glColor3f(siBLACK);
	glVertex2f(originx + 0.116*resize, originy + -0.147*resize);
	glVertex2f(originx + 0.082*resize, originy + -0.305*resize);
	glVertex2f(originx + -0.008*resize, originy + -0.353*resize);
	glVertex2f(originx + -0.166*resize, originy + -0.393*resize);
	glEnd();


	// HandLine
	glBegin(GL_LINE_STRIP);
	glColor3f(siBLACK);
	glVertex2f(originx + -0.259*resize, originy + -0.132*resize);
	glVertex2f(originx + -0.248*resize, originy + -0.314*resize);
	glVertex2f(originx + -0.248*resize, originy + -0.396*resize);
	glVertex2f(originx + -0.341*resize, originy + -0.367*resize);
	glEnd();
	// Elbow
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.341*resize, originy + -0.367*resize);
	glVertex2f(originx + -0.348*resize, originy + -0.203*resize);
	glVertex2f(originx + -0.475*resize, originy + -0.152*resize);
	glVertex2f(originx + -0.589*resize, originy + -0.209*resize);
	glEnd();
	// Wrist
	glBegin(GL_POLYGON);
	glColor3f(GOLD);
	glVertex2f(originx + -0.475*resize, originy + -0.152*resize);
	glVertex2f(originx + -0.558*resize, originy + -0.050*resize);
	glVertex2f(originx + -0.647*resize, originy + -0.067*resize);
	glVertex2f(originx + -0.589*resize, originy + -0.209*resize);
	glEnd();
	// Hand
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.558*resize, originy + -0.050*resize);
	glVertex2f(originx + -0.496*resize, originy + 0.167*resize);
	glVertex2f(originx + -0.568*resize, originy + 0.116*resize);
	glVertex2f(originx + -0.589*resize, originy + 0.235*resize);
	glVertex2f(originx + -0.650*resize, originy + 0.221*resize);
	glVertex2f(originx + -0.661*resize, originy + 0.063*resize);
	glVertex2f(originx + -0.647*resize, originy + -0.067*resize);
	glEnd();

	// foot
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + 0.281*resize, originy + -0.970*resize);
	glVertex2f(originx + 0.319*resize, originy + -0.913*resize);
	glVertex2f(originx + 0.277*resize, originy + -0.859*resize);
	glVertex2f(originx + 0.281*resize, originy + -0.769*resize);
	glVertex2f(originx + 0.257*resize, originy + -0.718*resize);
	glVertex2f(originx + 0.174*resize, originy + -0.707*resize);
	glVertex2f(originx + 0.102*resize, originy + -0.777*resize);
	glVertex2f(originx + 0.164*resize, originy + -0.811*resize);
	glVertex2f(originx + 0.198*resize, originy + -0.876*resize);
	glVertex2f(originx + 0.198*resize, originy + -0.944*resize);
	glVertex2f(originx + 0.202*resize, originy + -0.970*resize);
	glEnd();
	// leg
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + 0.102*resize, originy + -0.777*resize);
	glVertex2f(originx + 0.174*resize, originy + -0.707*resize);
	glVertex2f(originx + -0.565*resize, originy + -0.591*resize);
	glVertex2f(originx + -0.578*resize, originy + -0.715*resize);
	glEnd();

	// Another Leg
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + 0.123*resize, originy + -0.537*resize);
	glVertex2f(originx + -0.094*resize, originy + -0.789*resize);
	glVertex2f(originx + -0.039*resize, originy + -0.908*resize);
	glVertex2f(originx + -0.018*resize, originy + -0.973*resize);
	glVertex2f(originx + 0.075*resize, originy + -0.973*resize);
	glVertex2f(originx + 0.071*resize, originy + -0.806*resize);
	glVertex2f(originx + 0.240*resize, originy + -0.642*resize);
	glEnd();

	// SovalaBelowThigh
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + -0.125*resize, originy + -0.837*resize);
	glVertex2f(originx + -0.255*resize, originy + -0.684*resize);
	glVertex2f(originx + -0.334*resize, originy + -0.628*resize);
	glVertex2f(originx + -0.513*resize, originy + -0.562*resize);
	glVertex2f(originx + -0.726*resize, originy + -0.543*resize);
	glVertex2f(originx + -0.774*resize, originy + -0.664*resize);
	glVertex2f(originx + -0.595*resize, originy + -0.755*resize);
	glVertex2f(originx + -0.365*resize, originy + -0.814*resize);
	glEnd();

	// sovalaabove
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + 0.123*resize, originy + -0.537*resize);
	glVertex2f(originx + 0.095*resize, originy + -0.444*resize);
	glVertex2f(originx + 0.030*resize, originy + -0.463*resize);
	glVertex2f(originx + -0.145*resize, originy + -0.475*resize);
	glVertex2f(originx + -0.348*resize, originy + -0.503*resize);
	glVertex2f(originx + -0.468*resize, originy + -0.514*resize);
	glVertex2f(originx + -0.537*resize, originy + -0.512*resize);
	glVertex2f(originx + -0.726*resize, originy + -0.543*resize);
	glVertex2f(originx + -0.513*resize, originy + -0.562*resize);
	glVertex2f(originx + -0.417*resize, originy + -0.591*resize);
	glVertex2f(originx + -0.334*resize, originy + -0.628*resize);
	glVertex2f(originx + 0.002*resize, originy + -0.681*resize);
	glEnd();

	// OthersideSovala
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + 0.545*resize, originy + -0.104*resize);
	glVertex2f(originx + 0.442*resize, originy + -0.067*resize);
	glVertex2f(originx + 0.350*resize, originy + -0.082*resize);
	glVertex2f(originx + 0.260*resize, originy + -0.152*resize);
	glVertex2f(originx + 0.257*resize, originy + -0.393*resize);
	glVertex2f(originx + 0.095*resize, originy + -0.444*resize);
	glVertex2f(originx + 0.123*resize, originy + -0.537*resize);
	glVertex2f(originx + 0.150*resize, originy + -0.630*resize);
	glVertex2f(originx + 0.243*resize, originy + -0.693*resize);
	glVertex2f(originx + 0.305*resize, originy + -0.727*resize);
	glVertex2f(originx + 0.635*resize, originy + -0.316*resize);
	glVertex2f(originx + 0.645*resize, originy + -0.237*resize);
	glVertex2f(originx + 0.624*resize, originy + -0.161*resize);
	glEnd();

	// fold
	glBegin(GL_LINE_STRIP);
	glColor3f(siBLACK);
	glVertex2f(originx + -0.125*resize, originy + -0.837*resize);
	glVertex2f(originx + -0.255*resize, originy + -0.684*resize);
	glVertex2f(originx + -0.334*resize, originy + -0.628*resize);
	glVertex2f(originx + -0.417*resize, originy + -0.591*resize);
	glVertex2f(originx + -0.513*resize, originy + -0.562*resize);
	glEnd();

	// Uparna
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + -0.186*resize, originy + 0.237*resize);
	glVertex2f(originx + -0.252*resize, originy + 0.224*resize);
	glVertex2f(originx + -0.310*resize, originy + 0.179*resize);
	glVertex2f(originx + -0.358*resize, originy + 0.108*resize);
	glVertex2f(originx + -0.540*resize, originy + -0.084*resize);
	glVertex2f(originx + -0.984*resize, originy + -0.701*resize);
	glVertex2f(originx + -0.874*resize, originy + -0.741*resize);
	glVertex2f(originx + -0.729*resize, originy + -0.749*resize);
	glVertex2f(originx + -0.640*resize, originy + -0.746*resize);
	glVertex2f(originx + -0.489*resize, originy + -0.314*resize);
	glVertex2f(originx + -0.376*resize, originy + -0.048*resize);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(siBLACK);
	glVertex2f(originx + -0.186*resize, originy + 0.237*resize);
	glVertex2f(originx + -0.252*resize, originy + 0.224*resize);
	glVertex2f(originx + -0.310*resize, originy + 0.179*resize);
	glVertex2f(originx + -0.358*resize, originy + 0.108*resize);
	glVertex2f(originx + -0.540*resize, originy + -0.084*resize);
	glVertex2f(originx + -0.984*resize, originy + -0.701*resize);
	glVertex2f(originx + -0.874*resize, originy + -0.741*resize);
	glVertex2f(originx + -0.729*resize, originy + -0.749*resize);
	glVertex2f(originx + -0.640*resize, originy + -0.746*resize);
	glVertex2f(originx + -0.489*resize, originy + -0.314*resize);
	glVertex2f(originx + -0.376*resize, originy + -0.048*resize);
	glEnd();

	// Polygon 18
	glBegin(GL_POLYGON);
	glColor3f(0.4667, 0.3098, 0.2941);
	glVertex2f(originx + -0.358*resize, originy + 0.068*resize);
	glVertex2f(originx + -0.510*resize, originy + -0.124*resize);
	glVertex2f(originx + -0.877*resize, originy + -0.724*resize);
	glEnd();
	// Polygon 19
	glBegin(GL_POLYGON);
	glColor3f(0.4667, 0.3098, 0.2941);
	glVertex2f(originx + -0.729*resize, originy + -0.749*resize);
	glVertex2f(originx + -0.513*resize, originy + -0.282*resize);
	glVertex2f(originx + -0.355*resize, originy + 0.026*resize);
	glEnd();
	// Polygon 20
	glBegin(GL_POLYGON);
	glColor3f(0.4667, 0.3098, 0.2941);
	glVertex2f(originx + -0.798*resize, originy + -0.446*resize);
	glVertex2f(originx + -0.568*resize, originy + -0.531*resize);
	glVertex2f(originx + -0.685*resize, originy + -0.514*resize);
	glEnd();
	// Polygon 21
	glBegin(GL_POLYGON);
	glColor3f(0.4667, 0.3098, 0.2941);
	glVertex2f(originx + -0.829*resize, originy + -0.489*resize);
	glVertex2f(originx + -0.589*resize, originy + -0.582*resize);
	glVertex2f(originx + -0.602*resize, originy + -0.639*resize);
	glVertex2f(originx + -0.894*resize, originy + -0.568*resize);
	glEnd();


	// Locket
	glBegin(GL_POLYGON);
	glColor3f(GOLD);
	glVertex2f(originx + -0.081*resize, originy + 0.011*resize);
	glVertex2f(originx + -0.070*resize, originy + -0.003*resize);
	glVertex2f(originx + -0.087*resize, originy + -0.014*resize);
	glVertex2f(originx + -0.108*resize, originy + 0.003*resize);
	glEnd();
	// Polygon 1
	glBegin(GL_LINE_STRIP);
	glColor3f(GOLD);
	glVertex2f(originx + -0.235*resize, originy + 0.226*resize);
	glVertex2f(originx + -0.197*resize, originy + 0.099*resize);
	glVertex2f(originx + -0.091*resize, originy + -0.000*resize);
	glVertex2f(originx + -0.009*resize, originy + 0.028*resize);
	glVertex2f(originx + 0.057*resize, originy + 0.090*resize);
	glVertex2f(originx + 0.105*resize, originy + 0.206*resize);
	glVertex2f(originx + 0.108*resize, originy + 0.226*resize);
	glEnd();
	// Janeu
	glBegin(GL_LINE_STRIP);
	glColor3f(WHITE);
	glVertex2f(originx + 0.149*resize, originy + 0.212*resize);
	glVertex2f(originx + 0.108*resize, originy + 0.093*resize);
	glVertex2f(originx + -0.022*resize, originy + -0.215*resize);
	glVertex2f(originx + -0.142*resize, originy + -0.370*resize);
	glVertex2f(originx + -0.232*resize, originy + -0.458*resize);
	glEnd();

	// Wrist
	glBegin(GL_POLYGON);
	glColor3f(GOLD);
	glVertex2f(originx + -0.341*resize, originy + -0.413*resize);
	glVertex2f(originx + -0.166*resize, originy + -0.393*resize);
	glVertex2f(originx + -0.145*resize, originy + -0.475*resize);
	glVertex2f(originx + -0.348*resize, originy + -0.503*resize);
	glEnd();

	// Hand
	glBegin(GL_POLYGON);
	glColor3f(SKIN);
	glVertex2f(originx + -0.341*resize, originy + -0.413*resize);
	glVertex2f(originx + -0.482*resize, originy + -0.396*resize);
	glVertex2f(originx + -0.485*resize, originy + -0.410*resize);
	glVertex2f(originx + -0.441*resize, originy + -0.432*resize);
	glVertex2f(originx + -0.637*resize, originy + -0.421*resize);
	glVertex2f(originx + -0.657*resize, originy + -0.480*resize);
	glVertex2f(originx + -0.537*resize, originy + -0.512*resize);
	glVertex2f(originx + -0.468*resize, originy + -0.514*resize);
	glVertex2f(originx + -0.348*resize, originy + -0.503*resize);
	glEnd();


	// OtherSideUparna
	glBegin(GL_POLYGON);
	glColor3f(PITAMBER);
	glVertex2f(originx + 0.879*resize, originy + -0.517*resize);
	glVertex2f(originx + 0.350*resize, originy + -0.082*resize);
	glVertex2f(originx + 0.233*resize, originy + 0.182*resize);
	glVertex2f(originx + 0.164*resize, originy + 0.210*resize);
	glVertex2f(originx + 0.022*resize, originy + 0.255*resize);
	glVertex2f(originx + 0.810*resize, originy + -0.973*resize);
	glEnd();
	// Polygon 23
	glBegin(GL_POLYGON);
	glColor3f(0.4667, 0.3098, 0.2941);
	glVertex2f(originx + 0.319*resize, originy + -0.149*resize);
	glVertex2f(originx + 0.535*resize, originy + -0.458*resize);
	glVertex2f(originx + 0.827*resize, originy + -0.766*resize);
	glEnd();
	// Polygon 24
	glBegin(GL_POLYGON);
	glColor3f(0.4667, 0.3098, 0.2941);
	glVertex2f(originx + 0.367*resize, originy + -0.144*resize);
	glVertex2f(originx + 0.590*resize, originy + -0.370*resize);
	glVertex2f(originx + 0.855*resize, originy + -0.571*resize);
	glEnd();
	// Polygon 25
	glBegin(GL_POLYGON);
	glColor3f(0.4667, 0.3098, 0.2941);
	glVertex2f(originx + 0.752*resize, originy + -0.421*resize);
	glVertex2f(originx + 0.631*resize, originy + -0.704*resize);
	glVertex2f(originx + 0.700*resize, originy + -0.633*resize);
	glEnd();
	// Polygon 26
	glBegin(GL_POLYGON);
	glColor3f(0.4667, 0.3098, 0.2941);
	glVertex2f(originx + 0.676*resize, originy + -0.763*resize);
	glVertex2f(originx + 0.810*resize, originy + -0.463*resize);
	glVertex2f(originx + 0.879*resize, originy + -0.517*resize);
	glVertex2f(originx + 0.734*resize, originy + -0.862*resize);
	glEnd();

	// wala
	glBegin(GL_LINE_STRIP);
	glColor3f(GOLD);
	glVertex2f(originx + -0.022*resize, originy + -0.712*resize);
	glVertex2f(originx + -0.002*resize, originy + -0.757*resize);
	glVertex2f(originx + 0.046*resize, originy + -0.782*resize);
	glVertex2f(originx + 0.091*resize, originy + -0.768*resize);
	glEnd();

	// Smile
	glBegin(GL_LINE_STRIP);
	glColor3f(siBLACK);
	glVertex2f(originx + -0.283*resize, originy + 0.308*resize);
	glVertex2f(originx + -0.249*resize, originy + 0.336*resize);
	glVertex2f(originx + -0.249*resize, originy + 0.336*resize);
	glEnd();
	// Nose Line
	glBegin(GL_LINE_STRIP);
	glColor3f(siBLACK);
	glVertex2f(originx + -0.304*resize, originy + 0.336*resize);
	glVertex2f(originx + -0.283*resize, originy + 0.342*resize);
	glVertex2f(originx + -0.280*resize, originy + 0.364*resize);
	glEnd();

	// EYE
	// Triangle 2
	glBegin(GL_TRIANGLES);
	glColor3f(WHITE);
	glVertex2f(originx + -0.249*resize, originy + 0.477*resize);
	glVertex2f(originx + -0.328*resize, originy + 0.452*resize);
	glVertex2f(originx + -0.256*resize, originy + 0.424*resize);
	glEnd();
	// Triangle 3
	glBegin(GL_TRIANGLES);
	glColor3f(siBLACK);
	glVertex2f(originx + -0.328*resize, originy + 0.452*resize);
	glVertex2f(originx + -0.249*resize, originy + 0.477*resize);
	glVertex2f(originx + -0.269*resize, originy + 0.446*resize);
	glEnd();
	// EYE
	glBegin(GL_TRIANGLES);
	glColor3f(WHITE);
	glVertex2f(originx + -0.249*resize, originy + 0.477*resize);
	glVertex2f(originx + -0.256*resize, originy + 0.424*resize);
	glVertex2f(originx + -0.070*resize, originy + 0.469*resize);
	glEnd();

	mukut(originx + 0.165 * resize, originy -0.18 * resize,resize );
}
