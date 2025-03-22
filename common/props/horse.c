void drawHorse(float originx, float originy, float resize)
{
	// EarDark
	glBegin(GL_TRIANGLES);
	glColor3f(0.6275, 0.4157, 0.2078);
	glVertex2f((originx - 0.743) * resize, (originy + 0.302) * resize);
	glVertex2f((originx - 0.788) * resize, (originy + 0.344) * resize);
	glVertex2f((originx - 0.767) * resize, (originy + 0.277) * resize);
	glEnd();






	// EarLight
	glBegin(GL_TRIANGLES);
	glColor3f(0.7647, 0.4667, 0.2118);
	glVertex2f((originx - 0.676) * resize, (originy + 0.263) * resize);
	glVertex2f((originx - 0.730) * resize, (originy + 0.349) * resize);
	glVertex2f((originx - 0.702) * resize, (originy + 0.262) * resize);
	glEnd();



	// Face
	glBegin(GL_POLYGON);
	glColor3f(0.7451, 0.4392, 0.1843);
	glVertex2f((originx - 0.668) * resize, (originy + -0.088) * resize);
	glVertex2f((originx - 0.721) * resize, (originy + 0.104) * resize);
	glVertex2f((originx - 0.602) * resize, (originy + 0.223) * resize);
	glVertex2f((originx - 0.476) * resize, (originy + 0.086) * resize);
	glVertex2f((originx - 0.502) * resize, (originy + -0.002) * resize);
	glVertex2f((originx - 0.530) * resize, (originy + -0.040) * resize);
	glVertex2f((originx - 0.595) * resize, (originy + -0.077) * resize);
	glVertex2f((originx - 0.642) * resize, (originy + -0.102) * resize);
	glEnd();
	// Neck
	glBegin(GL_POLYGON);
	glColor3f(0.7451, 0.4392, 0.1843);
	glVertex2f((originx - 0.602) * resize, (originy + 0.223) * resize);
	glVertex2f((originx - 0.676) * resize, (originy + 0.263) * resize);
	glVertex2f((originx - 0.743) * resize, (originy + 0.302) * resize);
	glVertex2f((originx - 0.804) * resize, (originy + 0.245) * resize);
	glVertex2f((originx - 0.880) * resize, (originy + 0.160) * resize);
	glVertex2f((originx - 0.915) * resize, (originy + 0.122) * resize);
	glVertex2f((originx - 0.912) * resize, (originy + 0.091) * resize);
	glVertex2f((originx - 0.894) * resize, (originy + 0.071) * resize);
	glVertex2f((originx - 0.865) * resize, (originy + 0.062) * resize);
	glVertex2f((originx - 0.834) * resize, (originy + 0.080) * resize);
	glVertex2f((originx - 0.758) * resize, (originy + 0.103) * resize);
	glVertex2f((originx - 0.721) * resize, (originy + 0.104) * resize);
	glVertex2f((originx - 0.659) * resize, (originy + 0.161) * resize);
	glEnd();

	// Body
	glBegin(GL_POLYGON);
	glColor3f(0.7451, 0.4392, 0.1843);
	glVertex2f((originx - 0.177) * resize, (originy + -0.221) * resize);
	glVertex2f((originx - 0.037) * resize, (originy + -0.262) * resize);
	glVertex2f((originx - -0.009) * resize, (originy + -0.102) * resize);
	glVertex2f((originx - 0.021) * resize, (originy + -0.015) * resize);
	glVertex2f((originx - 0.064) * resize, (originy + 0.013) * resize);
	glVertex2f((originx - 0.134) * resize, (originy + 0.040) * resize);
	glVertex2f((originx - 0.314) * resize, (originy + 0.013) * resize);
	glVertex2f((originx - 0.431) * resize, (originy + 0.055) * resize);
	glVertex2f((originx - 0.462) * resize, (originy + -0.042) * resize);
	glVertex2f((originx - 0.472) * resize, (originy + -0.080) * resize);
	glVertex2f((originx - 0.177) * resize, (originy + -0.221) * resize);
	glEnd();

	// Neckband
	glBegin(GL_POLYGON);
	glColor3f(0.3412, 0.4118, 0.3059);
	glVertex2f((originx - 0.431) * resize, (originy + 0.055) * resize);
	glVertex2f((originx - 0.476) * resize, (originy + 0.086) * resize);
	glVertex2f((originx - 0.502) * resize, (originy + -0.002) * resize);
	glVertex2f((originx - 0.530) * resize, (originy + -0.040) * resize);
	glVertex2f((originx - 0.595) * resize, (originy + -0.077) * resize);
	glVertex2f((originx - 0.642) * resize, (originy + -0.102) * resize);
	glVertex2f((originx - 0.668) * resize, (originy + -0.088) * resize);
	glVertex2f((originx - 0.666) * resize, (originy + -0.143) * resize);
	glVertex2f((originx - 0.634) * resize, (originy + -0.156) * resize);
	glVertex2f((originx - 0.581) * resize, (originy + -0.143) * resize);
	glVertex2f((originx - 0.489) * resize, (originy + -0.106) * resize);
	glVertex2f((originx - 0.472) * resize, (originy + -0.080) * resize);
	glVertex2f((originx - 0.448) * resize, (originy + -0.005) * resize);
	glVertex2f((originx - 0.431) * resize, (originy + 0.055) * resize);
	glEnd();

	// LEGS
	glBegin(GL_POLYGON);
	glColor3f(0.7451, 0.4392, 0.1843);
	glVertex2f((originx - 0.401) * resize, (originy + -0.182) * resize);
	glVertex2f((originx - 0.472) * resize, (originy + -0.080) * resize);
	glVertex2f((originx - 0.489) * resize, (originy + -0.106) * resize);
	glVertex2f((originx - 0.581) * resize, (originy + -0.143) * resize);
	glVertex2f((originx - 0.550) * resize, (originy + -0.260) * resize);
	glVertex2f((originx - 0.450) * resize, (originy + -0.260) * resize);
	glVertex2f((originx - 0.401) * resize, (originy + -0.182) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.7451, 0.4392, 0.1843);
	glVertex2f((originx - 0.450) * resize, (originy + -0.260) * resize);
	glVertex2f((originx - 0.476) * resize, (originy + -0.459) * resize);
	glVertex2f((originx - 0.504) * resize, (originy + -0.461) * resize);
	glVertex2f((originx - 0.550) * resize, (originy + -0.260) * resize);
	glVertex2f((originx - 0.450) * resize, (originy + -0.260) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.7451, 0.4392, 0.1843);
	glVertex2f((originx - 0.476) * resize, (originy + -0.459) * resize);
	glVertex2f((originx - 0.467) * resize, (originy + -0.593) * resize);
	glVertex2f((originx - 0.504) * resize, (originy + -0.598) * resize);
	glVertex2f((originx - 0.504) * resize, (originy + -0.461) * resize);
	glVertex2f((originx - 0.476) * resize, (originy + -0.459) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.4706, 0.2392, 0.1020);
	glVertex2f((originx - 0.581) * resize, (originy + -0.143) * resize);
	glVertex2f((originx - 0.634) * resize, (originy + -0.156) * resize);
	glVertex2f((originx - 0.666) * resize, (originy + -0.143) * resize);
	glVertex2f((originx - 0.596) * resize, (originy + -0.378) * resize);
	glVertex2f((originx - 0.551) * resize, (originy + -0.380) * resize);
	glVertex2f((originx - 0.550) * resize, (originy + -0.260) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.4392, 0.2431, 0.1176);
	glVertex2f((originx - 0.551) * resize, (originy + -0.380) * resize);
	glVertex2f((originx - 0.551) * resize, (originy + -0.574) * resize);
	glVertex2f((originx - 0.583) * resize, (originy + -0.573) * resize);
	glVertex2f((originx - 0.596) * resize, (originy + -0.378) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.7451, 0.4392, 0.1843);
	glVertex2f((originx - 0.037) * resize, (originy + -0.262) * resize);
	glVertex2f((originx - (-0.006)) * resize, (originy + -0.430) * resize);
	glVertex2f((originx - 0.029) * resize, (originy + -0.490) * resize);
	glVertex2f((originx - 0.051) * resize, (originy + -0.381) * resize);
	glVertex2f((originx - 0.177) * resize, (originy + -0.221) * resize);
	glVertex2f((originx - 0.037) * resize, (originy + -0.262) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.4157, 0.2235, 0.1137);
	glVertex2f((originx - 0.177) * resize, (originy + -0.221) * resize);
	glVertex2f((originx - 0.095) * resize, (originy + -0.394) * resize);
	glVertex2f((originx - 0.136) * resize, (originy + -0.577) * resize);
	glVertex2f((originx - 0.169) * resize, (originy + -0.561) * resize);
	glVertex2f((originx - 0.142) * resize, (originy + -0.409) * resize);
	glVertex2f((originx - 0.269) * resize, (originy + -0.241) * resize);
	glVertex2f((originx - 0.177) * resize, (originy + -0.221) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.7451, 0.4392, 0.1843);
	glVertex2f((originx - (-0.006)) * resize, (originy + -0.430) * resize);
	glVertex2f((originx - 0.010) * resize, (originy + -0.638) * resize);
	glVertex2f((originx - 0.050) * resize, (originy + -0.623) * resize);
	glVertex2f((originx - 0.029) * resize, (originy + -0.490) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.4431, 0.2549, 0.1451);
	glVertex2f((originx - 0.136) * resize, (originy + -0.577) * resize);
	glVertex2f((originx - 0.160) * resize, (originy + -0.624) * resize);
	glVertex2f((originx - 0.199) * resize, (originy + -0.611) * resize);
	glVertex2f((originx - 0.169) * resize, (originy + -0.561) * resize);
	glVertex2f((originx - 0.136) * resize, (originy + -0.577) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.7333, 0.5294, 0.3333);
	glVertex2f((originx - 0.467) * resize, (originy + -0.593) * resize);
	glVertex2f((originx - 0.480) * resize, (originy + -0.650) * resize);
	glVertex2f((originx - 0.520) * resize, (originy + -0.630) * resize);
	glVertex2f((originx - 0.504) * resize, (originy + -0.598) * resize);
	glVertex2f((originx - 0.467) * resize, (originy + -0.593) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.4627, 0.2902, 0.1765);
	glVertex2f((originx - 0.551) * resize, (originy + -0.574) * resize);
	glVertex2f((originx - 0.572) * resize, (originy + -0.632) * resize);
	glVertex2f((originx - 0.611) * resize, (originy + -0.613) * resize);
	glVertex2f((originx - 0.583) * resize, (originy + -0.573) * resize);
	glVertex2f((originx - 0.551) * resize, (originy + -0.574) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.3725, 0.4471, 0.3216);
	glVertex2f((originx - 0.480) * resize, (originy + -0.650) * resize);
	glVertex2f((originx - 0.483) * resize, (originy + -0.681) * resize);
	glVertex2f((originx - 0.544) * resize, (originy + -0.687) * resize);
	glVertex2f((originx - 0.520) * resize, (originy + -0.630) * resize);
	glVertex2f((originx - 0.480) * resize, (originy + -0.650) * resize);
	glEnd();

	// Talpaay
	glBegin(GL_POLYGON);
	glColor3f(0.2510, 0.2902, 0.2235);
	glVertex2f((originx - 0.572) * resize, (originy + -0.632) * resize);
	glVertex2f((originx - 0.571) * resize, (originy + -0.663) * resize);
	glVertex2f((originx - 0.633) * resize, (originy + -0.665) * resize);
	glVertex2f((originx - 0.611) * resize, (originy + -0.613) * resize);
	glVertex2f((originx - 0.572) * resize, (originy + -0.632) * resize);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1882, 0.2353, 0.1882);
	glVertex2f((originx - 0.160) * resize, (originy + -0.624) * resize);
	glVertex2f((originx - 0.160) * resize, (originy + -0.655) * resize);
	glVertex2f((originx - 0.221) * resize, (originy + -0.654) * resize);
	glVertex2f((originx - 0.199) * resize, (originy + -0.611) * resize);
	glVertex2f((originx - 0.160) * resize, (originy + -0.624) * resize);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.3529, 0.4431, 0.3333);
	glVertex2f((originx - 0.010) * resize, (originy + -0.638) * resize);
	glVertex2f((originx - 0.010) * resize, (originy + -0.671) * resize);
	glVertex2f((originx - 0.069) * resize, (originy + -0.669) * resize);
	glVertex2f((originx - 0.050) * resize, (originy + -0.623) * resize);
	glVertex2f((originx - 0.010) * resize, (originy + -0.638) * resize);
	glEnd();

	// Tail
	glBegin(GL_POLYGON);
	glColor3f(0.3098, 0.3804, 0.2784);
	glVertex2f((originx - 0.064) * resize, (originy + 0.013) * resize);
	glVertex2f((originx - (-0.006)) * resize, (originy + 0.022) * resize);
	glVertex2f((originx - (-0.065)) * resize, (originy + -0.053) * resize);
	glVertex2f((originx - (-0.091)) * resize, (originy + -0.418) * resize);
	glVertex2f((originx - (-0.035)) * resize, (originy + -0.439) * resize);
	glVertex2f((originx - (-0.009)) * resize, (originy + -0.102) * resize);
	glVertex2f((originx - 0.021) * resize, (originy + -0.015) * resize);
	glVertex2f((originx - 0.064) * resize, (originy + 0.013) * resize);
	glEnd();

	// Hairs
	glBegin(GL_POLYGON);
	glColor3f(0.3373, 0.4196, 0.3020);
	glVertex2f((originx - 0.476) * resize, (originy + 0.086) * resize);
	glVertex2f((originx - 0.447) * resize, (originy + 0.088) * resize);
	glVertex2f((originx - 0.522) * resize, (originy + 0.205) * resize);
	glVertex2f((originx - 0.594) * resize, (originy + 0.255) * resize);
	glVertex2f((originx - 0.692) * resize, (originy + 0.291) * resize);
	glVertex2f((originx - 0.676) * resize, (originy + 0.263) * resize);
	glVertex2f((originx - 0.602) * resize, (originy + 0.223) * resize);
	glEnd();

	// Eye
	glBegin(GL_TRIANGLES);
	glColor3f(0.1373, 0.1020, 0.0902);
	glVertex2f((originx - 0.740) * resize, (originy + 0.232) * resize);
	glVertex2f((originx - 0.747) * resize, (originy + 0.189) * resize);
	glVertex2f((originx - 0.782) * resize, (originy + 0.232) * resize);
	glEnd();

	// Nose
	glBegin(GL_TRIANGLES);
	glColor3f(0.1255, 0.1020, 0.0824);
	glVertex2f((originx - 0.895) * resize, (originy + 0.124) * resize);
	glVertex2f((originx - 0.874) * resize, (originy + 0.107) * resize);
	glVertex2f((originx - 0.892) * resize, (originy + 0.097) * resize);
	glEnd();

	// Stomach
	glBegin(GL_TRIANGLES);
	glColor3f(0.7451, 0.4392, 0.1843);
	glVertex2f((originx - 0.472) * resize, (originy + -0.080) * resize);
	glVertex2f((originx - 0.177) * resize, (originy + -0.221) * resize);
	glVertex2f((originx - 0.339) * resize, (originy + -0.272) * resize);
	glEnd();

}
