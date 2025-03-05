void drawRightPatternedDeer(float, float, float);
void drawLeftPatternedDeer(float, float, float);
void drawCraneOne(float,float,float);
void drawCraneTwo(float, float, float);
void drawCircleScene2(float , float , float, float, float, float, float, int);
void drawRightPatternedDeer(float originx, float originy, float resize)
{	
	//Face
	glBegin(GL_POLYGON);
	glColor3f(0.682f, 0.302f, 0.341f);
	glVertex3f(originx + (0.32f) * resize, originy + (0.44f) * resize, 0.0f);
	glColor3f(0.6, 0.424, 0.259);
	glVertex3f(originx + (0.14f) * resize, originy + (0.46f) * resize, 0.0f);
	glVertex3f(originx + (0.06f) * resize, originy + (0.44f) * resize, 0.0f);
	glColor3f(0.6, 0.424, 0.259);
	glVertex3f(originx + (-0.02f) * resize, originy + (0.3f) * resize, 0.0f);
	glColor3f(0.769, 0.29, 0.353);
	glVertex3f(originx + (0.114f) * resize, originy + (0.298f) * resize, 0.0f);
	glVertex3f(originx + (0.254f) * resize, originy + (0.349f) * resize, 0.0f);
	glVertex3f(originx + (0.34f) * resize, originy + (0.38f) * resize, 0.0f);
	glEnd();

	//Nose 
	glBegin(GL_POLYGON);
	glColor3f(0.169f, 0.137f, 0.22f);
	glVertex3f(originx + (0.32f)*resize,  originy + (0.44f)*resize, 0.0f);
	glVertex3f(originx + (0.35f)*resize,  originy + (0.43f)*resize, 0.0f);
	glVertex3f(originx + (0.357f)*resize, originy + (0.419f)*resize, 0.0f);
	glVertex3f(originx + (0.356f)*resize, originy + (0.386f)*resize, 0.0f);
	glVertex3f(originx + (0.347f)*resize, originy + (0.379f)*resize, 0.0f);
	glVertex3f(originx + (0.34f) * resize,originy + (0.38f) * resize, 0.0f);
	glEnd();

	//ears - Base
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.424, 0.259);
	glVertex3f(originx + (0.06f) * resize, originy + (0.44f) * resize, 0.0f);
	glVertex3f(originx + (0.02f)*resize,   originy + (0.48f)*resize, 0.0f);
	glVertex3f(originx + (0.135f)*resize,  originy + (0.536f)*resize, 0.0f);
	glVertex3f(originx + (0.14f)*resize,   originy + (0.46f)*resize, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES); //left ear
	glColor3f(0.6, 0.424, 0.259);
	glVertex3f(originx + (0.02f)*resize, originy + (0.48f)*resize, 0.0f);
	glColor3f(0.89f, 0.337f, 0.439f);
	glVertex3f(originx + (0.03f)*resize, originy + (0.6f)*resize, 0.0f);
	glVertex3f(originx + (0.1f)*resize, originy + (0.5f)*resize, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES); //right ear
	glColor3f(0.6, 0.424, 0.259);
	glVertex3f(originx + (0.06f) * resize, originy + (0.48f) * resize, 0.0f);
	glColor3f(0.949f, 0.525f, 0.435f);
	glVertex3f(originx + (0.08f) * resize, originy + (0.62f) * resize, 0.0f);
	glColor3f(0.6, 0.424, 0.259);
	glVertex3f(originx + (0.135f) * resize, originy + (0.536f) * resize, 0.0f);
	glEnd();

	//neck
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.424, 0.259);
	glVertex3f(originx + (-0.02f) * resize, originy + (0.3f) * resize, 0.0f);
	glColor3f(0.847f, 0.384f, 0.384f);
	glVertex3f(originx + (-0.05f) * resize, originy + (0.2f) * resize, 0.0f);
	glVertex3f(originx + (-0.05f) * resize, originy + (0.0f) * resize, 0.0f);
	glVertex3f(originx + (0.16f) * resize,  originy + (-0.033f) * resize, 0.0f);
	glVertex3f(originx + (0.111f) * resize, originy + (0.093f) * resize, 0.0f);
	glVertex3f(originx + (0.104f) * resize, originy + (0.209f) * resize, 0.0f);
	glColor3f(0.6, 0.424, 0.259);
	glVertex3f(originx + (0.108f) * resize, originy + (0.3f) * resize, 0.0f);
	glEnd();

	//Body
	glBegin(GL_POLYGON);
	glColor3f(0.847f, 0.384f, 0.384f);
	glVertex3f(originx + (-0.05f) * resize, originy + (0.0f) * resize, 0.0f);
	glVertex3f(originx + (0.0f) * resize, originy + (-0.25f) * resize, 0.0f);
	glColor3f(0.639, 0.447, 0.235);
	glVertex3f(originx + (0.062f) * resize, originy + (-0.345f) * resize, 0.0f);
	glColor3f(0.639, 0.447, 0.235);
	glVertex3f(originx + (0.35f) * resize, originy + (-0.4f) * resize, 0.0f);
	glColor3f(0.639, 0.447, 0.235);
	glVertex3f(originx + (0.76f) * resize, originy + (-0.333f) * resize, 0.0f);
	glColor3f(0.639, 0.447, 0.235);
	glVertex3f(originx + (0.84f) * resize, originy + (-0.204f) * resize, 0.0f);
	glColor3f(0.871f, 0.514f, 0.369f);
	glVertex3f(originx + (0.84f) * resize, originy + (-0.133f) * resize, 0.0f);
	glColor3f(0.71f, 0.333f, 0.318f);
	glVertex3f(originx + (0.7f) * resize, originy + (-0.065f) * resize, 0.0f);
	glColor3f(0.89f, 0.494f, 0.376f);
	glVertex3f(originx + (0.5f) * resize, originy + (-0.025f) * resize, 0.0f);
	glColor3f(0.847f, 0.384f, 0.384f);
	glVertex3f(originx + (0.16f) * resize, originy + (-0.033f) * resize, 0.0f);
	glEnd();


	glBegin(GL_QUADS);	//dumadlelya payacha varcha half part
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.0f) * resize, originy + (-0.25f) * resize, 0.0f);
	glColor3f(0.8f, 0.514f, 0.341f);
	glVertex3f(originx + (-0.15f) * resize, originy + (-0.55f) * resize, 0.0f); //dumad
	glVertex3f(originx + (-0.1f) * resize, originy + (-0.55f) * resize, 0.0f);
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.05f) * resize, originy + (-0.3f) * resize, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);	//dumadlelya payacha khalacha half part
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (-0.15f) * resize, originy + (-0.55f) * resize, 0.0f); //dumad
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (-0.1f) * resize, originy + (-0.55f) * resize, 0.0f);
	glVertex3f(originx + (0.07f) * resize, originy + (-0.86f) * resize, 0.0f);
	glColor3f(0.196f, 0.094f, 0.075f);
	glVertex3f(originx + (0.06f) * resize, originy + (-0.87f) * resize, 0.0f);
	glEnd();

	glBegin(GL_QUADS);	//straight front leg - upper half part
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.064f) * resize, originy + (-0.35f) * resize, 0.0f);
	glColor3f(0.8f, 0.298f, 0.388f);
	glVertex3f(originx + (0.17f) * resize, originy + (-0.69f) * resize, 0.0f);
	glVertex3f(originx + (0.2f) * resize, originy + (-0.69f) * resize, 0.0f);
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.184f) * resize, originy + (-0.31f) * resize, 0.0f);
	glEnd();


	glBegin(GL_QUADS);	//straight front leg - lower half part
	glColor3f(0.8f, 0.298f, 0.388f);
	glVertex3f(originx + (0.17f) * resize, originy + (-0.69f) * resize, 0.0f);
	glColor3f(0.271f, 0.161f, 0.086f);
	glVertex3f(originx + (0.22f) * resize, originy + (-0.98f) * resize, 0.0f);
	glVertex3f(originx + (0.24f) * resize, originy + (-0.98f) * resize, 0.0f);
	glColor3f(0.812f, 0.353f, 0.38f);
	glVertex3f(originx + (0.2f) * resize, originy + (-0.69f) * resize, 0.0f);
	glEnd();
	
	//Hind legs left side
	//upper half part
	glBegin(GL_QUADS);
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.556f) * resize, originy + (-0.36f) * resize, 0.0f);
	glColor3f(0.69f, 0.298f, 0.286f);
	glVertex3f(originx + (0.625f) * resize, originy + (-0.6f) * resize, 0.0f);
	glVertex3f(originx + (0.68f) * resize, originy + (-0.6f) * resize, 0.0f);
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.68f) * resize, originy +  (-0.34f) * resize, 0.0f);
	glEnd();

	//lower side
	glBegin(GL_QUADS);
	glColor3f(0.69f, 0.298f, 0.286f);
	glVertex3f(originx + (0.625f) * resize, originy + (-0.6f) * resize, 0.0f);
	glColor3f(0.196f, 0.094f, 0.075f);
	glVertex3f(originx + (0.56f) * resize, originy + (-0.96f) * resize, 0.0f);
	glVertex3f(originx + (0.58f) * resize, originy + (-0.96f) * resize, 0.0f);
	glColor3f(0.69f, 0.298f, 0.286f);
	glVertex3f(originx + (0.68f) * resize, originy + (-0.6f) * resize, 0.0f);
	glEnd();


	//Hind legs right side
	//upper half part
	glBegin(GL_QUADS);
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.65f) * resize,  originy + (-0.36f) * resize, 0.0f);
	glVertex3f(originx + (0.77f) * resize,  originy + (-0.57f) * resize, 0.0f);
	glVertex3f(originx + (0.812f) * resize, originy + (-0.519f) * resize, 0.0f);
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.744f) * resize, originy + (-0.32f) * resize, 0.0f);
	glEnd();

	//lower side
	glBegin(GL_QUADS);
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.77f) * resize, originy + (-0.57f) * resize, 0.0f);
	glColor3f(0.196f, 0.094f, 0.075f);
	glVertex3f(originx + (0.849f) * resize, originy + (-0.97f) * resize, 0.0f);
	glVertex3f(originx + (0.87f) * resize, originy + (-0.97f) * resize, 0.0f);
	glColor3f(0.639f, 0.447f, 0.235f);
	glVertex3f(originx + (0.812f) * resize, originy + (-0.519f) * resize, 0.0f);
	glEnd();

	
	//Tail
	glBegin(GL_POLYGON);
	glColor3f(0.851f, 0.525f, 0.369f);
	glVertex3f((originx + 0.831f) * resize, originy + (-0.201f) * resize, 0.0f);
	glColor3f(0.467f, 0.184f, 0.196f);
	glVertex3f((originx + 0.89f ) * resize, originy + (-0.272f) * resize, 0.0f);
	glColor3f(0.894, 0.557, 0.4);
	glVertex3f((originx + 0.929f) * resize, originy + (-0.283f) * resize, 0.0f);
	glVertex3f((originx + 0.931f) * resize, originy + (-0.24f) * resize, 0.0f);
	glVertex3f((originx + 0.88f ) * resize, originy + (-0.16f) * resize, 0.0f);
	glColor3f(0.851f, 0.525f, 0.369f);
	glVertex3f((originx + 0.84f ) * resize, originy + (-0.14f) * resize, 0.0f);
	glEnd();

	//Eye
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx + (0.10f) * resize, originy + (0.36f) * resize, 0.0f);
	glVertex3f(originx + (0.17f) * resize, originy + (0.39f) * resize, 0.0f);
	glVertex3f(originx + (0.202f) * resize,originy + (0.38f) * resize, 0.0f);
	glVertex3f(originx + (0.16f) * resize, originy + (0.35f) * resize, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(originx + (0.10f) * resize, originy + (0.36f) * resize, 0.0f);
	glVertex3f(originx + (0.17f) * resize, originy + (0.39f) * resize, 0.0f);
	glVertex3f(originx + (0.16f) * resize, originy + (0.35f) * resize, 0.0f);
	glEnd();
}


void drawLeftPatternedDeer(float originx, float originy, float resize)
{
	//Face
	glBegin(GL_POLYGON);
	glColor3f(0.867f, 0.478f, 0.365f);
	glVertex3f(originx + (-0.055f) * resize, originy + (0.48f) * resize, 0.0f);
	glColor3f(0.784f, 0.408f, 0.365f);
	glVertex3f(originx + (-0.19f) * resize, originy + (0.55f) * resize, 0.0f);
	glColor3f(0.714, 0.31, 0.31);
	glVertex3f(originx + (-0.26f) * resize, originy + (0.58f) * resize, 0.0f);
	glColor3f(0.82, 0.404, 0.353);
	glVertex3f(originx + (-0.37f) * resize, originy + (0.50f) * resize, 0.0f);
	glColor3f(0.851, 0.549, 0.463);
	glVertex3f(originx + (-0.24f) * resize, originy + (0.41f) * resize, 0.0f);
	glVertex3f(originx + (-0.14f) * resize, originy + (0.41f) * resize, 0.0f);
	glColor3f(0.867f, 0.478f, 0.365f);
	glVertex3f(originx + (-0.055f) * resize, originy + (0.431f) * resize, 0.0f);
	glEnd();

	//Nose
	glBegin(GL_QUADS);
	glColor3f(0.169f, 0.137f, 0.22f);
	glVertex3f(originx + (-0.055f)*resize, originy + (0.48f)*resize, 0.0f);
	glVertex3f(originx + (-0.031f)*resize, originy + (0.46f)*resize, 0.0f);
	glVertex3f(originx + (-0.034f)*resize, originy + (0.44f)*resize, 0.0f);
	glVertex3f(originx + (-0.055f)*resize, originy + (0.431f)*resize, 0.0f);
	glEnd();

	//Ears - Base
	glBegin(GL_QUADS);
	glColor3f(0.871f, 0.51f, 0.376f);
	glVertex3f(originx + (-0.26f) * resize, originy + (0.58f) * resize, 0.0f);
	glColor3f(0.784f, 0.404f, 0.361f);
	glVertex3f(originx + (-0.245f)* resize, originy + (0.653f) * resize, 0.0f);
	glColor3f(0.784f, 0.404f, 0.361f);
	glVertex3f(originx + (-0.38f) * resize, originy +(0.58f) * resize, 0.0f);
	glColor3f(0.737f, 0.349f, 0.333f);
	glVertex3f(originx + (-0.36f)* resize, originy + (0.51f) * resize, 0.0f);
	glEnd();

	//right ear
	glBegin(GL_TRIANGLES); 
	glColor3f(0.784f, 0.404f, 0.361f);
	glVertex3f(originx + (-0.245f) * resize, originy + (0.653f) * resize, 0.0f);
	glColor3f(0.812f, 0.392f, 0.412f);
	glVertex3f(originx + (-0.29f) * resize, originy + (0.71f) * resize, 0.0f);
	glColor3f(0.784f, 0.404f, 0.361f);
	glVertex3f(originx + (-0.31f) * resize, originy + (0.61f) * resize, 0.0f);
	glEnd();

	//left ear
	glBegin(GL_TRIANGLES); 
	glColor3f(0.784f, 0.404f, 0.361f);
	glVertex3f(originx + (-0.31f) * resize, originy + (0.61f) * resize, 0.0f);
	glColor3f(0.812f, 0.392f, 0.412f);
	glVertex3f(originx + (-0.34f ) * resize, originy + (0.7f) * resize, 0.0f);
	glColor3f(0.784f, 0.404f, 0.361f);
	glVertex3f(originx + (-0.38f) * resize, originy + (0.58f) * resize, 0.0f);
	glEnd();

	//neck
	glBegin(GL_POLYGON);
	glColor3f(0.82f, 0.404f, 0.353f);
	glVertex3f(originx + (-0.37f) * resize, originy + (0.50f) * resize, 0.0f);
	glColor3f(0.824f, 0.451f, 0.361f);
	glVertex3f(originx + (-0.39f) * resize, originy + (0.41f) * resize, 0.0f);
	glColor3f(0.929f, 0.624f, 0.412f);
	glVertex3f(originx + (-0.4f) * resize, originy + (0.25f) * resize, 0.0f);
	glColor3f(0.769f, 0.42f, 0.341f);
	glVertex3f(originx + (-0.5f) * resize, originy + (0.08f) * resize, 0.0f);
	glColor3f(0.882f, 0.553f, 0.396f);
	glVertex3f(originx + (-0.3f) * resize, originy + (0.03f) * resize, 0.0f);
	glColor3f(0.941f, 0.635f, 0.463f);
	glVertex3f(originx + (-0.27f) * resize, originy + (0.17f) * resize, 0.0f);
	glColor3f(0.788f, 0.467f, 0.396f);
	glVertex3f(originx + (-0.24f) * resize, originy + (0.41f) * resize, 0.0f);
	glEnd();

	
	//Body
	glBegin(GL_POLYGON);
	glColor3f(0.788, 0.435, 0.349);
	glVertex3f(originx + (-0.5f) * resize, originy + (0.08f) * resize, 0.0f);
	glColor3f(0.894, 0.612, 0.412);
	glVertex3f(originx + (-0.77f) * resize, originy + (0.10f) * resize, 0.0f);
	glColor3f(0.773, 0.424, 0.325);
	glVertex3f(originx + (-0.93f) * resize, originy + (0.076f) * resize, 0.0f);
	glColor3f(0.765, 0.396, 0.286);
	glVertex3f(originx + (-0.96f) * resize, originy + (0.0f) * resize, 0.0f);	
	glVertex3f(originx + (-0.99f) * resize, originy + (-0.15f) * resize, 0.0f);

	glVertex3f(originx + (-0.97f) * resize, originy + (-0.22f) * resize, 0.0f);
	glColor3f(0.855, 0.58, 0.341);	 
	glVertex3f(originx + (-0.84f) * resize, originy + (-0.27f) * resize, 0.0f);
	glColor3f(0.859, 0.612, 0.408);
	glVertex3f(originx + (-0.42f) * resize, originy + (-0.25f) * resize, 0.0f);
	glVertex3f(originx + (-0.3f) * resize, originy + (-0.2f) * resize, 0.0f);
	glColor3f(0.875, 0.537, 0.392);
	glVertex3f(originx + (-0.3f) * resize, originy + (0.03f) * resize, 0.0f);
	glEnd();

	//Tail
	glBegin(GL_QUADS);
	glColor3f(0.765, 0.396, 0.286);
	glVertex3f(originx + (-0.93f) * resize, originy + (0.07f) * resize, 0.0f);
	glVertex3f(originx + (-0.998f) * resize, originy + (-0.047f) * resize, 0.0f);
	glVertex3f(originx + (-0.994f) * resize, originy + (-0.066f) * resize, 0.0f);
	glColor3f(0.522, 0.2, 0.224);
	glVertex3f(originx + (-0.95f) * resize, originy + (-0.05f) * resize, 0.0f);
	glEnd();


	//Front legs
	glBegin(GL_QUADS);	//Folded Leg
	glColor3f(0.855, 0.596, 0.4);
	glVertex3f(originx + (-0.38f) * resize, originy + (-0.23f) * resize, 0.0f);
	glColor3f(0.647, 0.369, 0.278);
	glVertex3f(originx + (-0.31f) * resize, originy + (-0.6f) * resize, 0.0f);
	glVertex3f(originx + (-0.28f) * resize, originy + (-0.6f) * resize, 0.0f);
	glColor3f(0.855, 0.596, 0.4);
	glVertex3f(originx + (-0.3f) * resize, originy + (-0.2f) * resize, 0.0f);
	glEnd();

	glBegin(GL_QUADS);	//Folded Leg - Middle
	glColor3f(0.647, 0.369, 0.278);
	glVertex3f(originx + (-0.31f) * resize, originy + (-0.6f) * resize, 0.0f); 
	glColor3f(0.224, 0.129, 0.047);
	glVertex3f(originx + (-0.42f) * resize, originy + (-0.9f) * resize, 0.0f);
	glVertex3f(originx + (-0.4f) * resize, originy + (-0.9f) * resize, 0.0f);
	glColor3f(0.647, 0.369, 0.278);
	glVertex3f(originx + (-0.28f) * resize, originy + (-0.6f) * resize, 0.0f);
	glEnd();

	glBegin(GL_QUADS);	//straight front leg 
	glColor3f(0.847, 0.584, 0.4);
	glVertex3f(originx + (-0.45f) * resize, originy + (-0.23f) * resize, 0.0f);
	glColor3f(0.224, 0.129, 0.047);
	glVertex3f(originx + (-0.54f) * resize, originy + (-0.9f) * resize, 0.0f);
	glVertex3f(originx + (-0.53f) * resize, originy + (-0.9f) * resize, 0.0f);
	glColor3f(0.847, 0.584, 0.4);
	glVertex3f(originx + (-0.36f) * resize, originy + (-0.23f) * resize, 0.0f);
	glEnd();


	//Hind legs left side
	//upper half part
	glBegin(GL_QUADS);
	glColor3f(0.765, 0.396, 0.286);
	glVertex3f(originx + (-0.90f) * resize, originy + (-0.24f) * resize, 0.0f);
	glColor3f(0.812, 0.576, 0.314);
	glVertex3f(originx + (-0.95f) * resize, originy + (-0.48f) * resize, 0.0f);
	glVertex3f(originx + (-0.9f) * resize, originy + (-0.48f) * resize, 0.0f);
	glColor3f(0.765, 0.396, 0.286);
	glVertex3f(originx + (-0.83f) * resize, originy + (-0.27f) * resize, 0.0f);
	glEnd();

	//lower part
	glBegin(GL_QUADS);
	glColor3f(0.812, 0.576, 0.314);
	glVertex3f(originx + (-0.95f) * resize, originy + (-0.48f) * resize, 0.0f);
	glColor3f(0.188, 0.122, 0.067);
	glVertex3f(originx + (-0.83f) * resize, originy + (-0.95f) * resize, 0.0f);
	glVertex3f(originx + (-0.82f) * resize, originy + (-0.95f) * resize, 0.0f);
	glColor3f(0.812, 0.576, 0.314);
	glVertex3f(originx + (-0.9f) * resize, originy + (-0.48f) * resize, 0.0f);
	glEnd();

	
	//Hind legs right side
	//upper half part

	glBegin(GL_QUADS);
	glColor3f(0.769, 0.404, 0.29);
	glVertex3f(originx + (-0.96f) * resize, originy + (-0.22f) * resize, 0.0f);
	glVertex3f(originx + (-1.0f) * resize, originy + (-0.48f) * resize, 0.0f);
	glVertex3f(originx + (-0.96f) * resize, originy + (-0.48f) * resize, 0.0f);
	glColor3f(0.855, 0.58, 0.341);
	glVertex3f(originx + (-0.89f) * resize, originy + (-0.25f) * resize, 0.0f);
	glEnd();

	//lower part
	glBegin(GL_QUADS);
	glColor3f(0.78, 0.427, 0.298);
	glVertex3f(originx + (-1.00f) * resize, originy + (-0.48f) * resize, 0.0f);
	glColor3f(0.188, 0.122, 0.067);
	glVertex3f(originx + (-0.90f) * resize, originy + (-0.95f) * resize, 0.0f);
	glVertex3f(originx + (-0.92f) * resize, originy + (-0.95f) * resize, 0.0f);
	glColor3f(0.78, 0.427, 0.298);
	glVertex3f(originx + (-0.96f) * resize, originy + (-0.48f) * resize, 0.0f);
	glEnd();

	// Eye
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(originx + (-0.179f) * resize, originy + (0.476f) * resize, 0.0f);
	glVertex3f(originx + (-0.213f) * resize, originy + (0.489f) * resize, 0.0f);
	glVertex3f(originx + (-0.26f) * resize, originy + (0.46f) * resize, 0.0f);
	glVertex3f(originx + (-0.209f) * resize, originy + (0.458f) * resize, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx + (-0.179f) * resize, originy + (0.476f) * resize, 0.0f);
	glVertex3f(originx + (-0.213f) * resize, originy + (0.489f) * resize, 0.0f);
	glVertex3f(originx + (-0.209f) * resize, originy + (0.458f) * resize, 0.0f);
	glEnd();

}

void drawCraneOne(float originx, float originy, float resize)
{
	//Body
	glBegin(GL_QUADS);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.023f) * resize, originy + (0.153f) * resize, 0.0f);
	glVertex3f(originx + (0.105f) * resize, originy + (0.237f) * resize, 0.0f);
	glVertex3f(originx + (0.1f)   * resize, originy + (0.2f)   * resize, 0.0f);
	glVertex3f(originx + (0.06f)  * resize, originy + (0.15f)  * resize, 0.0f);
	glEnd();

	//wing
	glBegin(GL_TRIANGLES);	
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.055f) * resize, originy + (0.187f) * resize, 0.0f);
	glVertex3f(originx + (0.022f) * resize, originy + (0.19f) * resize, 0.0f);
	glVertex3f(originx + (0.10f) * resize,  originy + (0.226f) * resize, 0.0f);
	glEnd();

	//Tail
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.04f) * resize, originy + (0.16f) * resize, 0.0f);
	glVertex3f(originx + (0.0f) * resize,  originy + (0.12f) * resize, 0.0f);
	glEnd();

	//Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.097f) * resize, originy + (0.22f) * resize, 0.0f);
	glVertex3f(originx + (0.12f) * resize,  originy + (0.3f) * resize, 0.0f);
	glEnd();

	//Head
	drawCircleScene2(0.38f, 0.9f, 0.03f, 0.04, 0.49f, 0.722f, 0.42f, 1);

	//Beak
	glBegin(GL_TRIANGLES);	
	glColor3f(0.0f, 0.282f, 0.2f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.31f) * resize, 0.0f);
	glVertex3f(originx + (0.16f) * resize,  originy + (0.307f) * resize, 0.0f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.30f) * resize, 0.0f);
	glEnd();

	//Eye
	glPointSize(5);	
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx + (0.128f) * resize, originy + (0.304f) * resize, 0.0f);
	glEnd();

	// right leg
	glLineWidth(3);
	glBegin(GL_LINES);	
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.07f) * resize,  originy + (0.161f) * resize, 0.0f);
	glVertex3f(originx + (0.064f) * resize, originy + (0.026f) * resize, 0.0f);
	glEnd();

	// left leg
	glBegin(GL_LINES);	
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.06f) * resize, originy + (0.152f) * resize, 0.0f);
	glVertex3f(originx + (0.0f) * resize,  originy + (0.04f) * resize, 0.0f);
	glEnd();
}

void drawCraneTwo(float originx, float originy, float resize)
{
	//Body
	glBegin(GL_QUADS);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.023f) * resize, originy + (0.153f) * resize, 0.0f);
	glVertex3f(originx + (0.105f) * resize, originy + (0.237f) * resize, 0.0f);
	glVertex3f(originx + (0.1f)   * resize, originy + (0.2f)   * resize, 0.0f);
	glVertex3f(originx + (0.06f)  * resize, originy + (0.15f)  * resize, 0.0f);
	glEnd();

	//Tail
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.04f) * resize, originy + (0.16f) * resize, 0.0f);
	glVertex3f(originx + (0.0f)  * resize, originy + (0.12f) * resize, 0.0f);
	glEnd();

	//Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.097f) * resize, originy + (0.22f) * resize, 0.0f);
	glVertex3f(originx + (0.12f) * resize,  originy + (0.3f) * resize, 0.0f);
	glEnd();

	//Head
	drawCircleScene2(0.38f,0.9f, 0.03f, 0.04, 0.49f, 0.722f, 0.42f, 1);

	//beak
	glBegin(GL_TRIANGLES);	
	glColor3f(0.0f, 0.282f, 0.2f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.31f) * resize, 0.0f);
	glVertex3f(originx + (0.16f) * resize,  originy + (0.307f) * resize, 0.0f);
	glVertex3f(originx + (0.135f) * resize, originy + (0.30f) * resize, 0.0f);
	glEnd();

	//Eye
	glPointSize(5);	
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(originx + (0.128f) * resize, originy + (0.304f) * resize, 0.0f);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);	// right leg
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.07f) * resize,  originy + (0.161f) * resize, 0.0f);
	glVertex3f(originx + (0.064f) * resize, originy + (0.026f) * resize, 0.0f);
	glEnd();

	glBegin(GL_LINES);	// left leg
	glColor3f(0.49f, 0.722f, 0.42f);
	glVertex3f(originx + (0.06f)*resize, originy + (0.149f)*resize, 0.0f);
	glVertex3f(originx + (0.03f)*resize, originy + (0.043f)*resize, 0.0f);
	glEnd();
}

void drawCircleScene2(float centerX, float centerY, float radiusH, float radiusV, float r, float g, float b, int fill)
{
	float ObjX = 0.0f;
	float ObjY = 0.0f;
	float ObjAngle = 0.0f;
	// Circle
	if (fill == 1) {
		glBegin(GL_POLYGON);
	}
	else {
		glBegin(GL_POINTS);
	}

	glColor3f(r, g, b);
	for (ObjAngle = (0.00f); ObjAngle <= (2.0f * PI); ObjAngle += 0.01f)

	{
		ObjX = centerX + radiusH * cos(ObjAngle);
		ObjY = centerY + radiusV * sin(ObjAngle);
		glVertex2f(ObjX, ObjY);
	}

	glEnd();
}
