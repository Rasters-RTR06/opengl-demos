// #define GOLD 0.859, 0.616, 0.051
// #define SKIN 0.286, 0.231, 0.196
// #define PITAMBER 0.7765, 0.5686, 0.3373

// void KrishnaRath(float originx, float originy, float resize)
// {
//     //set matrix to model view mode
//     glMatrixMode(GL_MODELVIEW);

//     //set it to identity matrix
//     glLoadIdentity();
//     glScalef(0.3f, 0.3f, 0.5f);	// x axis rotation

// // CROWN
// // Triangle 1
// glBegin(GL_TRIANGLES);
// glColor3f(GOLD);
// glVertex2f(-0.496, 0.728);
// glVertex2f(-0.309, 0.861);
// glVertex2f(-0.109, 0.743);
// glEnd();
// // Triangle 2
// glBegin(GL_TRIANGLES);
// glVertex2f(-0.496, 0.728);
// glVertex2f(-0.526, 0.796);
// glVertex2f(-0.417, 0.728);
// glEnd();
// // Triangle 3
// glBegin(GL_TRIANGLES);
// glVertex2f(-0.109, 0.743);
// glVertex2f(-0.074, 0.883);
// glVertex2f(-0.143, 0.740);
// glEnd();
// // Triangle 4
// glBegin(GL_TRIANGLES);
// glColor3f(0.341, 0.659, 0.224);
// glVertex2f(-0.470, 0.865);
// glVertex2f(-0.483, 0.825);
// glVertex2f(-0.413, 0.846);
// glEnd();
// // Triangle 5
// glBegin(GL_TRIANGLES);
// glColor3f(0.031, 0.035, 0.729);
// glVertex2f(-0.483, 0.825);
// glVertex2f(-0.426, 0.806);
// glVertex2f(-0.413, 0.846);
// glEnd();
// // Polygon 6
// glBegin(GL_POLYGON);
// glColor3f(GOLD);
// glVertex2f(-0.496, 0.728);
// glVertex2f(-0.109, 0.743);
// glVertex2f(-0.104, 0.796);
// glVertex2f(-0.513, 0.777);
// glEnd();
// // Polygon 7
// glBegin(GL_POLYGON);
// glVertex2f(-0.496, 0.728);
// glVertex2f(-0.443, 0.808);
// glVertex2f(-0.383, 0.824);
// glVertex2f(-0.230, 0.830);
// glVertex2f(-0.161, 0.824);
// glVertex2f(-0.109, 0.743);
// glEnd();
// // Polygon 8
// glBegin(GL_POLYGON);
// glVertex2f(-0.496, 0.728);
// glVertex2f(-0.374, 0.842);
// glVertex2f(-0.243, 0.849);
// glVertex2f(-0.109, 0.743);
// glEnd();

// // FACE
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(-0.470, 0.716);
// glVertex2f(-0.452, 0.607);
// glVertex2f(-0.470, 0.567);
// glVertex2f(-0.435, 0.558);
// glVertex2f(-0.361, 0.518);
// glVertex2f(-0.317, 0.515);
// glVertex2f(-0.291, 0.471);
// glVertex2f(-0.209, 0.465);
// glVertex2f(-0.143, 0.496);
// glVertex2f(-0.170, 0.558);
// glVertex2f(-0.161, 0.601);
// glVertex2f(-0.100, 0.641);
// glVertex2f(-0.122, 0.737);
// glVertex2f(-0.326, 0.740);
// glVertex2f(-0.470, 0.716);
// glEnd();

// // CHEST
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(-0.291, 0.471);
// glVertex2f(-0.391, 0.193);
// glVertex2f(0.157, 0.289);
// glVertex2f(-0.143, 0.496);
// glVertex2f(-0.209, 0.465);
// glVertex2f(-0.291, 0.471);
// glEnd();
// // ABDAMON
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(-0.391, 0.193);
// glVertex2f(-0.148, -0.088);
// glVertex2f(0.226, -0.029);
// glVertex2f(0.157, 0.289);
// glVertex2f(-0.391, 0.193);
// glEnd();

// glLineWidth(1);
// // Janaeu
// glBegin(GL_LINE_STRIP);
// glColor3f(1, 0.8, 0.8);
// glVertex2f(-0.026, 0.515);
// glVertex2f(-0.091, 0.295);
// glVertex2f(-0.135, 0.165);
// glVertex2f(-0.183, 0.000);
// glEnd();
// glLineWidth(6);
// // Necklece
// glBegin(GL_LINE_STRIP);
// glColor3f(GOLD);
// glVertex2f(-0.374, 0.459);
// glVertex2f(-0.309, 0.366);
// glVertex2f(-0.183, 0.258);
// glVertex2f(-0.087, 0.351);
// glVertex2f(-0.074, 0.437);
// glVertex2f(-0.070, 0.505);
// glVertex2f(-0.061, 0.500);
// glEnd();

// glBegin(GL_POLYGON);
// glColor3f(GOLD);
// glVertex2f(-0.209, 0.264);
// glVertex2f(-0.200, 0.292);
// glVertex2f(-0.165, 0.301);
// glVertex2f(-0.130, 0.283);
// glVertex2f(-0.122, 0.255);
// glVertex2f(-0.148, 0.236);
// glVertex2f(-0.187, 0.246);
// glEnd();

// glLineWidth(1);
// // BOTTOM INSIDE
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(-0.148, -0.088);
// glVertex2f(-0.157, -0.768);
// glVertex2f(-0.017, -0.753);
// glVertex2f(-0.009, -0.601);
// glVertex2f(0.161, -0.555);
// glVertex2f(0.291, -0.685);
// glVertex2f(0.417, -0.669);
// glVertex2f(0.343, -0.422);
// glVertex2f(0.370, -0.168);
// glVertex2f(0.226, -0.029);
// glEnd();
// // RIGHT FOOT
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(-0.157, -0.768);
// glVertex2f(-0.174, -0.815);
// glVertex2f(-0.378, -0.867);
// glVertex2f(-0.365, -0.901);
// glVertex2f(-0.304, -0.920);
// glVertex2f(-0.187, -0.879);
// glVertex2f(-0.048, -0.852);
// glVertex2f(0.022, -0.808);
// glVertex2f(0.043, -0.790);
// glVertex2f(-0.017, -0.753);
// glVertex2f(-0.157, -0.768);
// glEnd();
// // LEFT FOOT
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(0.291, -0.685);
// glVertex2f(0.283, -0.762);
// glVertex2f(0.257, -0.796);
// glVertex2f(0.378, -0.787);
// glVertex2f(0.448, -0.691);
// glVertex2f(0.417, -0.669);
// glVertex2f(0.291, -0.685);
// glEnd();

// // Wala 1
// glBegin(GL_LINE_STRIP);
// glColor3f(GOLD);
// glVertex2f(-0.157, -0.740);
// glVertex2f(-0.087, -0.747);
// glVertex2f(-0.009, -0.722);
// glEnd();
// // Wala 2
// glBegin(GL_LINE_STRIP);
// glColor3f(GOLD);
// glVertex2f(0.265, -0.669);
// glVertex2f(0.343, -0.669);
// glVertex2f(0.410, -0.638);
// glEnd();

// // RIGHT SHOULDER AND ELBOW
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(-0.396, 0.261);
// glVertex2f(-0.400, 0.150);
// glVertex2f(-0.622, 0.017);
// glVertex2f(-0.557, -0.051);
// glVertex2f(-0.335, 0.045);
// glVertex2f(-0.309, 0.178);
// glEnd();
// // WRIST BAND
// glBegin(GL_POLYGON);
// glColor3f(GOLD);
// glVertex2f(-0.622, 0.017);
// glVertex2f(-0.717, -0.032);
// glVertex2f(-0.674, -0.091);
// glVertex2f(-0.557, -0.051);
// glEnd();
// // RIGHT HAND
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(-0.717, -0.032);
// glVertex2f(-0.787, -0.082);
// glVertex2f(-0.865, -0.178);
// glVertex2f(-0.822, -0.230);
// glVertex2f(-0.757, -0.246);
// glVertex2f(-0.722, -0.212);
// glVertex2f(-0.739, -0.178);
// glVertex2f(-0.739, -0.128);
// glVertex2f(-0.674, -0.091);
// glVertex2f(-0.717, -0.032);
// glEnd();

// // SOVALA
// glBegin(GL_POLYGON);
// glColor3f(PITAMBER);
// glVertex2f(-0.188, -0.075);
// glVertex2f(-0.188, -0.245);
// glVertex2f(-0.193, -0.436);
// glVertex2f(-0.174, -0.643);
// glVertex2f(-0.154, -0.667);
// glVertex2f(-0.016, -0.596);
// glVertex2f(0.157, -0.551);
// glVertex2f(0.195, -0.585);
// glVertex2f(0.276, -0.551);
// glVertex2f(0.305, -0.456);
// glVertex2f(0.343, -0.429);
// glVertex2f(0.358, -0.272);
// glVertex2f(0.386, -0.177);
// glVertex2f(0.415, -0.130);
// glVertex2f(0.420, -0.085);
// glVertex2f(0.381, -0.045);
// glVertex2f(0.310, 0.010);
// glVertex2f(0.257, 0.054);
// glVertex2f(0.195, 0.068);
// glVertex2f(0.114, 0.030);
// glVertex2f(0.080, -0.034);
// glVertex2f(0.018, -0.045);
// glVertex2f(-0.097, -0.048);
// glVertex2f(-0.178, -0.055);
// glEnd();

// // Line 1
// glBegin(GL_LINE_STRIP);
// glColor3f(0.0, 0.0, 0.0);
// glVertex2f(0.037, -0.123);
// glVertex2f(0.099, -0.201);
// glVertex2f(0.152, -0.255);
// glVertex2f(0.291, -0.300);
// glEnd();
// // Line 2
// glBegin(GL_LINE_STRIP);
// glColor3f(0.0, 0.0, 0.0);
// glVertex2f(-0.006, -0.286);
// glVertex2f(0.003, -0.422);
// glVertex2f(0.032, -0.521);
// glVertex2f(0.066, -0.568);
// glEnd();
// // Line 3
// glBegin(GL_LINE_STRIP);
// glColor3f(0.0, 0.0, 0.0);
// glVertex2f(0.066, -0.337);
// glVertex2f(0.104, -0.463);
// glVertex2f(0.157, -0.551);
// glEnd();

// // LEFT HAND
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(-0.222, -0.014);
// glVertex2f(-0.317, -0.079);
// glVertex2f(-0.357, -0.128);
// glVertex2f(-0.335, -0.196);
// glVertex2f(-0.243, -0.181);
// glVertex2f(-0.278, -0.150);
// glVertex2f(-0.200, -0.079);
// glVertex2f(-0.152, -0.057);
// glEnd();
// // WRIST BAND
// glBegin(GL_POLYGON);
// glColor3f(GOLD);
// glVertex2f(-0.222, -0.014);
// glVertex2f(-0.113, 0.036);
// glVertex2f(-0.083, -0.026);
// glVertex2f(-0.152, -0.057);
// glEnd();
// // LEFT SHOULDER AND ELBOW
// glBegin(GL_POLYGON);
// glColor3f(SKIN);
// glVertex2f(-0.113, 0.036);
// glVertex2f(0.048, 0.131);
// glVertex2f(0.035, 0.264);
// glVertex2f(0.157, 0.289);
// glVertex2f(0.152, 0.091);
// glVertex2f(-0.083, -0.026);
// glEnd();
// // UPARNA
// glBegin(GL_POLYGON);
// glColor3f(PITAMBER);
// glVertex2f(-0.157, 0.527);
// glVertex2f(-0.009, 0.515);
// glVertex2f(0.104, 0.450);
// glVertex2f(0.170, 0.363);
// glVertex2f(0.226, 0.255);
// glVertex2f(0.257, 0.128);
// glVertex2f(0.374, 0.063);
// glVertex2f(0.526, 0.002);
// glVertex2f(0.765, -0.054);
// glVertex2f(0.683, -0.311);
// glVertex2f(0.400, -0.181);
// glVertex2f(0.248, -0.051);
// glVertex2f(0.152, 0.091);
// glVertex2f(0.139, 0.193);
// glVertex2f(0.070, 0.295);
// glVertex2f(0.022, 0.369);
// glVertex2f(0.022, 0.422);
// glVertex2f(-0.048, 0.505);
// glEnd();
// // UPARNA
// glBegin(GL_POLYGON);
// glColor3f(PITAMBER);
// glVertex2f(-0.157, 0.527);
// glVertex2f(-0.143, 0.496);
// glVertex2f(0.022, 0.369);
// glVertex2f(0.022, 0.422);
// glVertex2f(-0.048, 0.505);
// glVertex2f(-0.157, 0.527);
// glEnd();
// // UPARNA
// glBegin(GL_POLYGON);
// glColor3f(PITAMBER);
// glVertex2f(-0.317, 0.515);
// glVertex2f(-0.404, 0.453);
// glVertex2f(-0.478, 0.308);
// glVertex2f(-0.483, 0.125);
// glVertex2f(-0.478, -0.036);
// glVertex2f(-0.583, -0.484);
// glVertex2f(-0.300, -0.385);
// glVertex2f(-0.357, -0.246);
// glVertex2f(-0.383, 0.011);
// glVertex2f(-0.387, 0.236);
// glVertex2f(-0.291, 0.471);
// glVertex2f(-0.317, 0.515);
// glEnd();

// // EYES
//     // Triangle 1
// glBegin(GL_TRIANGLES);
// glColor3f(1, 1, 1);
// glVertex2f(-0.430, 0.663);
// glVertex2f(-0.417, 0.620);
// glVertex2f(-0.230, 0.660);
// glEnd();
// // Triangle 2
// glBegin(GL_TRIANGLES);
// glColor3f(0.2431, 0.1608, 0.2235);
// glVertex2f(-0.430, 0.663);
// glVertex2f(-0.378, 0.660);
// glVertex2f(-0.417, 0.620);
// glEnd();

// glMatrixMode(GL_MODELVIEW);

// //set it to identity matrix
// glLoadIdentity();
// glScalef(1.0f, 1.0f, 1.0f);	// x axis rotation

// }

#define GOLD 0.859, 0.616, 0.051
#define SKIN 0.286, 0.231, 0.196
#define PITAMBER 0.7765, 0.5686, 0.3373

void KrishnaRath(float originx, float originy, float resize)
{


    // CROWN
    // Triangle 1
    glBegin(GL_TRIANGLES);
    glColor3f(GOLD);
    glVertex2f(originx + (-0.496 * resize), originy + (0.728 * resize));
    glVertex2f(originx + (-0.309 * resize), originy + (0.861 * resize));
    glVertex2f(originx + (-0.109 * resize), originy + (0.743 * resize));
    glEnd();
    // Triangle 2
    glBegin(GL_TRIANGLES);
    glVertex2f(originx + (-0.496 * resize), originy + (0.728 * resize));
    glVertex2f(originx + (-0.526 * resize), originy + (0.796 * resize));
    glVertex2f(originx + (-0.417 * resize), originy + (0.728 * resize));
    glEnd();
    // Triangle 3
    glBegin(GL_TRIANGLES);
    glVertex2f(originx + (-0.109 * resize), originy + (0.743 * resize));
    glVertex2f(originx + (-0.074 * resize), originy + (0.883 * resize));
    glVertex2f(originx + (-0.143 * resize), originy + (0.740 * resize));
    glEnd();
    // Triangle 4
    glBegin(GL_TRIANGLES);
    glColor3f(0.341, 0.659, 0.224);
    glVertex2f(originx + (-0.470 * resize), originy + (0.865 * resize));
    glVertex2f(originx + (-0.483 * resize), originy + (0.825 * resize));
    glVertex2f(originx + (-0.413 * resize), originy + (0.846 * resize));
    glEnd();
    // Triangle 5
    glBegin(GL_TRIANGLES);
    glColor3f(0.031, 0.035, 0.729);
    glVertex2f(originx + (-0.483 * resize), originy + (0.825 * resize));
    glVertex2f(originx + (-0.426 * resize), originy + (0.806 * resize));
    glVertex2f(originx + (-0.413 * resize), originy + (0.846 * resize));
    glEnd();
    // Polygon 6
    glBegin(GL_POLYGON);
    glColor3f(GOLD);
    glVertex2f(originx + (-0.496 * resize), originy + (0.728 * resize));
    glVertex2f(originx + (-0.109 * resize), originy + (0.743 * resize));
    glVertex2f(originx + (-0.104 * resize), originy + (0.796 * resize));
    glVertex2f(originx + (-0.513 * resize), originy + (0.777 * resize));
    glEnd();
    // Polygon 7
    glBegin(GL_POLYGON);
    glVertex2f(originx + (-0.496 * resize), originy + (0.728 * resize));
    glVertex2f(originx + (-0.443 * resize), originy + (0.808 * resize));
    glVertex2f(originx + (-0.383 * resize), originy + (0.824 * resize));
    glVertex2f(originx + (-0.230 * resize), originy + (0.830 * resize));
    glVertex2f(originx + (-0.161 * resize), originy + (0.824 * resize));
    glVertex2f(originx + (-0.109 * resize), originy + (0.743 * resize));
    glEnd();
    // Polygon 8
    glBegin(GL_POLYGON);
    glVertex2f(originx + (-0.496 * resize), originy + (0.728 * resize));
    glVertex2f(originx + (-0.374 * resize), originy + (0.842 * resize));
    glVertex2f(originx + (-0.243 * resize), originy + (0.849 * resize));
    glVertex2f(originx + (-0.109 * resize), originy + (0.743 * resize));
    glEnd();

    // FACE
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (-0.470 * resize), originy + (0.716 * resize));
    glVertex2f(originx + (-0.452 * resize), originy + (0.607 * resize));
    glVertex2f(originx + (-0.470 * resize), originy + (0.567 * resize));
    glVertex2f(originx + (-0.435 * resize), originy + (0.558 * resize));
    glVertex2f(originx + (-0.361 * resize), originy + (0.518 * resize));
    glVertex2f(originx + (-0.317 * resize), originy + (0.515 * resize));
    glVertex2f(originx + (-0.291 * resize), originy + (0.471 * resize));
    glVertex2f(originx + (-0.209 * resize), originy + (0.465 * resize));
    glVertex2f(originx + (-0.143 * resize), originy + (0.496 * resize));
    glVertex2f(originx + (-0.170 * resize), originy + (0.558 * resize));
    glVertex2f(originx + (-0.161 * resize), originy + (0.601 * resize));
    glVertex2f(originx + (-0.100 * resize), originy + (0.641 * resize));
    glVertex2f(originx + (-0.122 * resize), originy + (0.737 * resize));
    glVertex2f(originx + (-0.326 * resize), originy + (0.740 * resize));
    glVertex2f(originx + (-0.470 * resize), originy + (0.716 * resize));
    glEnd();

    // CHEST
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (-0.291 * resize), originy + (0.471 * resize));
    glVertex2f(originx + (-0.391 * resize), originy + (0.193 * resize));
    glVertex2f(originx + (0.157 * resize), originy + (0.289 * resize));
    glVertex2f(originx + (-0.143 * resize), originy + (0.496 * resize));
    glVertex2f(originx + (-0.209 * resize), originy + (0.465 * resize));
    glVertex2f(originx + (-0.291 * resize), originy + (0.471 * resize));
    glEnd();

    // ABDOMEN
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (-0.391 * resize), originy + (0.193 * resize));
    glVertex2f(originx + (-0.148 * resize), originy + (-0.088 * resize));
    glVertex2f(originx + (0.226 * resize), originy + (-0.029 * resize));
    glVertex2f(originx + (0.157 * resize), originy + (0.289 * resize));
    glVertex2f(originx + (-0.391 * resize), originy + (0.193 * resize));
    glEnd();

    glLineWidth(1);
    // Janaeu
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 0.8, 0.8);
    glVertex2f(originx + (-0.026 * resize), originy + (0.515 * resize));
    glVertex2f(originx + (-0.091 * resize), originy + (0.295 * resize));
    glVertex2f(originx + (-0.135 * resize), originy + (0.165 * resize));
    glVertex2f(originx + (-0.183 * resize), originy + (0.000 * resize));
    glEnd();

    glLineWidth(6);
    // Necklace
    glBegin(GL_LINE_STRIP);
    glColor3f(GOLD);
    glVertex2f(originx + (-0.374 * resize), originy + (0.459 * resize));
    glVertex2f(originx + (-0.309 * resize), originy + (0.366 * resize));
    glVertex2f(originx + (-0.183 * resize), originy + (0.258 * resize));
    glVertex2f(originx + (-0.087 * resize), originy + (0.351 * resize));
    glVertex2f(originx + (-0.074 * resize), originy + (0.437 * resize));
    glVertex2f(originx + (-0.070 * resize), originy + (0.505 * resize));
    glVertex2f(originx + (-0.061 * resize), originy + (0.500 * resize));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(GOLD);
    glVertex2f(originx + (-0.209 * resize), originy + (0.264 * resize));
    glVertex2f(originx + (-0.200 * resize), originy + (0.292 * resize));
    glVertex2f(originx + (-0.165 * resize), originy + (0.301 * resize));
    glVertex2f(originx + (-0.130 * resize), originy + (0.283 * resize));
    glVertex2f(originx + (-0.122 * resize), originy + (0.255 * resize));
    glVertex2f(originx + (-0.148 * resize), originy + (0.236 * resize));
    glVertex2f(originx + (-0.187 * resize), originy + (0.246 * resize));
    glEnd();

    glLineWidth(1);
    // BOTTOM INSIDE
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (-0.148 * resize), originy + (-0.088 * resize));
    glVertex2f(originx + (-0.157 * resize), originy + (-0.768 * resize));
    glVertex2f(originx + (-0.017 * resize), originy + (-0.753 * resize));
    glVertex2f(originx + (-0.009 * resize), originy + (-0.601 * resize));
    glVertex2f(originx + (0.161 * resize), originy + (-0.555 * resize));
    glVertex2f(originx + (0.291 * resize), originy + (-0.685 * resize));
    glVertex2f(originx + (0.417 * resize), originy + (-0.669 * resize));
    glVertex2f(originx + (0.343 * resize), originy + (-0.422 * resize));
    glVertex2f(originx + (0.370 * resize), originy + (-0.168 * resize));
    glVertex2f(originx + (0.226 * resize), originy + (-0.029 * resize));
    glEnd();

    // RIGHT FOOT
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (-0.157 * resize), originy + (-0.768 * resize));
    glVertex2f(originx + (-0.174 * resize), originy + (-0.815 * resize));
    glVertex2f(originx + (-0.378 * resize), originy + (-0.867 * resize));
    glVertex2f(originx + (-0.365 * resize), originy + (-0.901 * resize));
    glVertex2f(originx + (-0.304 * resize), originy + (-0.920 * resize));
    glVertex2f(originx + (-0.187 * resize), originy + (-0.879 * resize));
    glVertex2f(originx + (-0.048 * resize), originy + (-0.852 * resize));
    glVertex2f(originx + (0.022 * resize), originy + (-0.808 * resize));
    glVertex2f(originx + (0.043 * resize), originy + (-0.790 * resize));
    glVertex2f(originx + (-0.017 * resize), originy + (-0.753 * resize));
    glVertex2f(originx + (-0.157 * resize), originy + (-0.768 * resize));
    glEnd();

    // LEFT FOOT
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (0.291 * resize), originy + (-0.685 * resize));
    glVertex2f(originx + (0.283 * resize), originy + (-0.762 * resize));
    glVertex2f(originx + (0.257 * resize), originy + (-0.796 * resize));
    glVertex2f(originx + (0.378 * resize), originy + (-0.787 * resize));
    glVertex2f(originx + (0.448 * resize), originy + (-0.691 * resize));
    glVertex2f(originx + (0.417 * resize), originy + (-0.669 * resize));
    glVertex2f(originx + (0.291 * resize), originy + (-0.685 * resize));
    glEnd();

    // Wala 1
    glBegin(GL_LINE_STRIP);
    glColor3f(GOLD);
    glVertex2f(originx + (-0.157 * resize), originy + (-0.740 * resize));
    glVertex2f(originx + (-0.087 * resize), originy + (-0.747 * resize));
    glVertex2f(originx + (-0.009 * resize), originy + (-0.722 * resize));
    glEnd();

    // Wala 2
    glBegin(GL_LINE_STRIP);
    glColor3f(GOLD);
    glVertex2f(originx + (0.265 * resize), originy + (-0.669 * resize));
    glVertex2f(originx + (0.343 * resize), originy + (-0.669 * resize));
    glVertex2f(originx + (0.410 * resize), originy + (-0.638 * resize));
    glEnd();

    // RIGHT SHOULDER AND ELBOW
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (-0.396 * resize), originy + (0.261 * resize));
    glVertex2f(originx + (-0.400 * resize), originy + (0.150 * resize));
    glVertex2f(originx + (-0.622 * resize), originy + (0.017 * resize));
    glVertex2f(originx + (-0.557 * resize), originy + (-0.051 * resize));
    glVertex2f(originx + (-0.335 * resize), originy + (0.045 * resize));
    glVertex2f(originx + (-0.309 * resize), originy + (0.178 * resize));
    glEnd();

    // WRIST BAND
    glBegin(GL_POLYGON);
    glColor3f(GOLD);
    glVertex2f(originx + (-0.622 * resize), originy + (0.017 * resize));
    glVertex2f(originx + (-0.717 * resize), originy + (-0.032 * resize));
    glVertex2f(originx + (-0.674 * resize), originy + (-0.091 * resize));
    glVertex2f(originx + (-0.557 * resize), originy + (-0.051 * resize));
    glEnd();

    // RIGHT HAND
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (-0.717 * resize), originy + (-0.032 * resize));
    glVertex2f(originx + (-0.787 * resize), originy + (-0.082 * resize));
    glVertex2f(originx + (-0.865 * resize), originy + (-0.178 * resize));
    glVertex2f(originx + (-0.822 * resize), originy + (-0.230 * resize));
    glVertex2f(originx + (-0.757 * resize), originy + (-0.246 * resize));
    glVertex2f(originx + (-0.722 * resize), originy + (-0.212 * resize));
    glVertex2f(originx + (-0.739 * resize), originy + (-0.178 * resize));
    glVertex2f(originx + (-0.739 * resize), originy + (-0.128 * resize));
    glVertex2f(originx + (-0.674 * resize), originy + (-0.091 * resize));
    glVertex2f(originx + (-0.717 * resize), originy + (-0.032 * resize));
    glEnd();

    // SOVALA
    glBegin(GL_POLYGON);
    glColor3f(PITAMBER);
    glVertex2f(originx + (-0.188 * resize), originy + (-0.075 * resize));
    glVertex2f(originx + (-0.188 * resize), originy + (-0.245 * resize));
    glVertex2f(originx + (-0.193 * resize), originy + (-0.436 * resize));
    glVertex2f(originx + (-0.174 * resize), originy + (-0.643 * resize));
    glVertex2f(originx + (-0.154 * resize), originy + (-0.667 * resize));
    glVertex2f(originx + (-0.016 * resize), originy + (-0.596 * resize));
    glVertex2f(originx + (0.157 * resize), originy + (-0.551 * resize));
    glVertex2f(originx + (0.195 * resize), originy + (-0.585 * resize));
    glVertex2f(originx + (0.276 * resize), originy + (-0.551 * resize));
    glVertex2f(originx + (0.305 * resize), originy + (-0.456 * resize));
    glVertex2f(originx + (0.343 * resize), originy + (-0.429 * resize));
    glVertex2f(originx + (0.358 * resize), originy + (-0.272 * resize));
    glVertex2f(originx + (0.386 * resize), originy + (-0.177 * resize));
    glVertex2f(originx + (0.415 * resize), originy + (-0.130 * resize));
    glVertex2f(originx + (0.420 * resize), originy + (-0.085 * resize));
    glVertex2f(originx + (0.381 * resize), originy + (-0.045 * resize));
    glVertex2f(originx + (0.310 * resize), originy + (0.010 * resize));
    glVertex2f(originx + (0.257 * resize), originy + (0.054 * resize));
    glVertex2f(originx + (0.195 * resize), originy + (0.068 * resize));
    glVertex2f(originx + (0.114 * resize), originy + (0.030 * resize));
    glVertex2f(originx + (0.080 * resize), originy + (-0.034 * resize));
    glVertex2f(originx + (0.018 * resize), originy + (-0.045 * resize));
    glVertex2f(originx + (-0.097 * resize), originy + (-0.048 * resize));
    glVertex2f(originx + (-0.178 * resize), originy + (-0.055 * resize));
    glEnd();

    // Line 1
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(originx + (0.037 * resize), originy + (-0.123 * resize));
    glVertex2f(originx + (0.099 * resize), originy + (-0.201 * resize));
    glVertex2f(originx + (0.152 * resize), originy + (-0.255 * resize));
    glVertex2f(originx + (0.291 * resize), originy + (-0.300 * resize));
    glEnd();

    // Line 2
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(originx + (-0.006 * resize), originy + (-0.286 * resize));
    glVertex2f(originx + (0.003 * resize), originy + (-0.422 * resize));
    glVertex2f(originx + (0.032 * resize), originy + (-0.521 * resize));
    glVertex2f(originx + (0.066 * resize), originy + (-0.568 * resize));
    glEnd();

    // Line 3
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(originx + (0.066 * resize), originy + (-0.337 * resize));
    glVertex2f(originx + (0.104 * resize), originy + (-0.463 * resize));
    glVertex2f(originx + (0.157 * resize), originy + (-0.551 * resize));
    glEnd();

    // LEFT HAND
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (-0.222 * resize), originy + (-0.014 * resize));
    glVertex2f(originx + (-0.317 * resize), originy + (-0.079 * resize));
    glVertex2f(originx + (-0.357 * resize), originy + (-0.128 * resize));
    glVertex2f(originx + (-0.335 * resize), originy + (-0.196 * resize));
    glVertex2f(originx + (-0.243 * resize), originy + (-0.181 * resize));
    glVertex2f(originx + (-0.278 * resize), originy + (-0.150 * resize));
    glVertex2f(originx + (-0.200 * resize), originy + (-0.079 * resize));
    glVertex2f(originx + (-0.152 * resize), originy + (-0.057 * resize));
    glEnd();

    // WRIST BAND
    glBegin(GL_POLYGON);
    glColor3f(GOLD);
    glVertex2f(originx + (-0.222 * resize), originy + (-0.014 * resize));
    glVertex2f(originx + (-0.113 * resize), originy + (0.036 * resize));
    glVertex2f(originx + (-0.083 * resize), originy + (-0.026 * resize));
    glVertex2f(originx + (-0.152 * resize), originy + (-0.057 * resize));
    glEnd();

    // LEFT SHOULDER AND ELBOW
    glBegin(GL_POLYGON);
    glColor3f(SKIN);
    glVertex2f(originx + (-0.113 * resize), originy + (0.036 * resize));
    glVertex2f(originx + (0.048 * resize), originy + (0.131 * resize));
    glVertex2f(originx + (0.035 * resize), originy + (0.264 * resize));
    glVertex2f(originx + (0.157 * resize), originy + (0.289 * resize));
    glVertex2f(originx + (0.152 * resize), originy + (0.091 * resize));
    glVertex2f(originx + (-0.083 * resize), originy + (-0.026 * resize));
    glEnd();

    // UPARNA 1
    glBegin(GL_POLYGON);
    glColor3f(PITAMBER);
    glVertex2f(originx + (-0.157 * resize), originy + (0.527 * resize));
    glVertex2f(originx + (-0.009 * resize), originy + (0.515 * resize));
    glVertex2f(originx + (0.104 * resize), originy + (0.450 * resize));
    glVertex2f(originx + (0.170 * resize), originy + (0.363 * resize));
    glVertex2f(originx + (0.226 * resize), originy + (0.255 * resize));
    glVertex2f(originx + (0.257 * resize), originy + (0.128 * resize));
    glVertex2f(originx + (0.374 * resize), originy + (0.063 * resize));
    glVertex2f(originx + (0.526 * resize), originy + (0.002 * resize));
    glVertex2f(originx + (0.765 * resize), originy + (-0.054 * resize));
    glVertex2f(originx + (0.683 * resize), originy + (-0.311 * resize));
    glVertex2f(originx + (0.400 * resize), originy + (-0.181 * resize));
    glVertex2f(originx + (0.248 * resize), originy + (-0.051 * resize));
    glVertex2f(originx + (0.152 * resize), originy + (0.091 * resize));
    glVertex2f(originx + (0.139 * resize), originy + (0.193 * resize));
    glVertex2f(originx + (0.070 * resize), originy + (0.295 * resize));
    glVertex2f(originx + (0.022 * resize), originy + (0.369 * resize));
    glVertex2f(originx + (0.022 * resize), originy + (0.422 * resize));
    glVertex2f(originx + (-0.048 * resize), originy + (0.505 * resize));
    glEnd();

    // UPARNA 2
    glBegin(GL_POLYGON);
    glColor3f(PITAMBER);
    glVertex2f(originx + (-0.157 * resize), originy + (0.527 * resize));
    glVertex2f(originx + (-0.143 * resize), originy + (0.496 * resize));
    glVertex2f(originx + (0.022 * resize), originy + (0.369 * resize));
    glVertex2f(originx + (0.022 * resize), originy + (0.422 * resize));
    glVertex2f(originx + (-0.048 * resize), originy + (0.505 * resize));
    glVertex2f(originx + (-0.157 * resize), originy + (0.527 * resize));
    glEnd();

    // UPARNA 3
    glBegin(GL_POLYGON);
    glColor3f(PITAMBER);
    glVertex2f(originx + (-0.317 * resize), originy + (0.515 * resize));
    glVertex2f(originx + (-0.404 * resize), originy + (0.453 * resize));
    glVertex2f(originx + (-0.478 * resize), originy + (0.308 * resize));
    glVertex2f(originx + (-0.483 * resize), originy + (0.125 * resize));
    glVertex2f(originx + (-0.478 * resize), originy + (-0.036 * resize));
    glVertex2f(originx + (-0.583 * resize), originy + (-0.484 * resize));
    glVertex2f(originx + (-0.300 * resize), originy + (-0.385 * resize));
    glVertex2f(originx + (-0.357 * resize), originy + (-0.246 * resize));
    glVertex2f(originx + (-0.383 * resize), originy + (0.011 * resize));
    glVertex2f(originx + (-0.387 * resize), originy + (0.236 * resize));
    glVertex2f(originx + (-0.291 * resize), originy + (0.471 * resize));
    glVertex2f(originx + (-0.317 * resize), originy + (0.515 * resize));
    glEnd();

    // EYES
    // Triangle 1
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1);
    glVertex2f(originx + (-0.430 * resize), originy + (0.663 * resize));
    glVertex2f(originx + (-0.417 * resize), originy + (0.620 * resize));
    glVertex2f(originx + (-0.230 * resize), originy + (0.660 * resize));
    glEnd();

    // Triangle 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.2431, 0.1608, 0.2235);
    glVertex2f(originx + (-0.430 * resize), originy + (0.663 * resize));
    glVertex2f(originx + (-0.378 * resize), originy + (0.660 * resize));
    glVertex2f(originx + (-0.417 * resize), originy + (0.620 * resize));
    glEnd();

}
