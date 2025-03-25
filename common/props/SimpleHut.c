void partUpperHut(float, float, float, float, float, float, float, int);

void partUpperHut(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, int fill)
{
    float ObjX = 0.0f;
    float ObjY = 0.0f;
    float ObjAngle = 0.0f;

    // Circle
    if (fill == 1)
    {
        glBegin(GL_POLYGON);
    }
    else
    {
        glBegin(GL_POINTS);
    }

    for (ObjAngle = (0.00f); ObjAngle <= (2.0f * PI); ObjAngle += 0.01f)

    {
        ObjX = x + radius_hor * sin(ObjAngle);
        ObjY = y + radius_vert * cos(ObjAngle);

        glColor3f(r, g, b);

        glVertex2f(ObjX, ObjY);
    }
    glEnd();
}

void partLowerHut(float originx, float originy, float resize)
{
    // Wall
    glBegin(GL_POLYGON);
    glColor3f(0.52f, 0.45f, 0.19f);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.30f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.30f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy - 0.30f) * resize);
    glVertex2f((originx - 0.85f) * resize, (originy - 0.30f) * resize);
    glEnd();

    // Hut lining
    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.77f) * resize, (originy + 0.60f) * resize);
    glVertex2f((originx - 0.63f) * resize, (originy + 0.60f) * resize);
    glVertex2f((originx - 0.613f) * resize, (originy + 0.58f) * resize);
    glVertex2f((originx - 0.787f) * resize, (originy + 0.58f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.81f) * resize, (originy + 0.53f) * resize);
    glVertex2f((originx - 0.59f) * resize, (originy + 0.53f) * resize);
    glVertex2f((originx - 0.58f) * resize, (originy + 0.51f) * resize);
    glVertex2f((originx - 0.82f) * resize, (originy + 0.51f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.833f) * resize, (originy + 0.46f) * resize);
    glVertex2f((originx - 0.567f) * resize, (originy + 0.46f) * resize);
    glVertex2f((originx - 0.563f) * resize, (originy + 0.44f) * resize);
    glVertex2f((originx - 0.838f) * resize, (originy + 0.44f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.845f) * resize, (originy + 0.39f) * resize);
    glVertex2f((originx - 0.554f) * resize, (originy + 0.39f) * resize);
    glVertex2f((originx - 0.553f) * resize, (originy + 0.37f) * resize);
    glVertex2f((originx - 0.848f) * resize, (originy + 0.37f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.32f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.32f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.30f) * resize);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.30f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.24f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.24f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.22f) * resize);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.22f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.16f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.16f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.14f) * resize);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.14f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.08f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.08f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.06f) * resize);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.06f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.85f) * resize, (originy + 0.00f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy + 0.00f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy - 0.02f) * resize);
    glVertex2f((originx - 0.85f) * resize, (originy - 0.02f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.85f) * resize, (originy - 0.08f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy - 0.08f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy - 0.10f) * resize);
    glVertex2f((originx - 0.85f) * resize, (originy - 0.10f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.85f) * resize, (originy - 0.16f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy - 0.16f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy - 0.18f) * resize);
    glVertex2f((originx - 0.85f) * resize, (originy - 0.18f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.17f, 0.18f, 0.18f);
    glVertex2f((originx - 0.85f) * resize, (originy - 0.25f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy - 0.25f) * resize);
    glVertex2f((originx - 0.55f) * resize, (originy - 0.27f) * resize);
    glVertex2f((originx - 0.85f) * resize, (originy - 0.27f) * resize);
    glEnd();

    // Door
    glBegin(GL_POLYGON);
    glColor3f(0.36f, 0.26f, 0.04f);
    glVertex2f((originx - 0.78f) * resize, (originy - 0.30f) * resize);
    glVertex2f((originx - 0.78f) * resize, (originy + 0.18f) * resize);
    glVertex2f((originx - 0.62f) * resize, (originy + 0.18f) * resize);
    glVertex2f((originx - 0.62f) * resize, (originy - 0.30f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.01f, 0.10f, 0.06f);
    glVertex2f((originx - 0.77f) * resize, (originy - 0.28f) * resize);
    glVertex2f((originx - 0.77f) * resize, (originy + 0.16f) * resize);
    glVertex2f((originx - 0.63f) * resize, (originy + 0.16f) * resize);
    glVertex2f((originx - 0.63f) * resize, (originy - 0.28f) * resize);
    glEnd();

    // foundation
    glBegin(GL_POLYGON);
    glColor3f(0.23f, 0.16f, 0.02f);
    glVertex2f((originx - 0.90f) * resize, (originy - 0.30f) * resize);
    glVertex2f((originx - 0.90f) * resize, (originy - 0.34f) * resize);
    glVertex2f((originx - 0.50f) * resize, (originy - 0.34f) * resize);
    glVertex2f((originx - 0.50f) * resize, (originy - 0.30f) * resize);
    glEnd();

    // Top triangles
    glBegin(GL_POLYGON);
    glColor3f(0.36f, 0.26f, 0.04f);
    glVertex2f((originx - 0.70f) * resize, (originy + 0.70f) * resize);
    glVertex2f((originx - 0.725f) * resize, (originy + 0.66f) * resize);
    glVertex2f((originx - 0.675f) * resize, (originy + 0.66f) * resize);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.36f, 0.26f, 0.04f);
    glVertex2f((originx - 0.70f) * resize, (originy + 0.64f) * resize);
    glVertex2f((originx - 0.71f) * resize, (originy + 0.66f) * resize);
    glVertex2f((originx - 0.69f) * resize, (originy + 0.66f) * resize);
    glEnd();
}

// #include "../common.h" // Assuming PI is defined here

// void partUpperHut(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, int fill)
// {
//     float ObjX = 0.0f;
//     float ObjY = 0.0f;
//     float ObjAngle = 0.0f;

//     // Circle (extended left by increasing radius_hor)
//     if (fill == 1)
//     {
//         glBegin(GL_POLYGON);
//     }
//     else
//     {
//         glBegin(GL_POINTS);
//     }

//     glColor3f(r, g, b);
//     for (ObjAngle = 0.00f; ObjAngle <= (2.0f * PI); ObjAngle += 0.01f)
//     {
//         ObjX = x + (radius_hor * sin(ObjAngle));
//         ObjY = y + (radius_vert * cos(ObjAngle));
//         glVertex2f(ObjX, ObjY);
//     }
//     glEnd();
// }

// void partLowerHut(float originx, float originy, float resize)
// {
//     // Wall (extended left from -0.85f to -0.95f)
//     glBegin(GL_POLYGON);
//     glColor3f(0.52f, 0.45f, 0.19f);
//     glVertex2f(originx + (-0.95f * resize), originy + (0.30f * resize)); // Extended left
//     glVertex2f(originx + (-0.55f * resize), originy + (0.30f * resize));
//     glVertex2f(originx + (-0.55f * resize), originy + (-0.30f * resize));
//     glVertex2f(originx + (-0.95f * resize), originy + (-0.30f * resize)); // Extended left
//     glEnd();

//     // Hut lining (adjusted left coordinates to match new wall)
//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.87f * resize), originy + (0.60f * resize)); // Adjusted from -0.77f
//     glVertex2f(originx + (-0.63f * resize), originy + (0.60f * resize));
//     glVertex2f(originx + (-0.613f * resize), originy + (0.58f * resize));
//     glVertex2f(originx + (-0.897f * resize), originy + (0.58f * resize)); // Adjusted from -0.787f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.91f * resize), originy + (0.53f * resize)); // Adjusted from -0.81f
//     glVertex2f(originx + (-0.59f * resize), originy + (0.53f * resize));
//     glVertex2f(originx + (-0.58f * resize), originy + (0.51f * resize));
//     glVertex2f(originx + (-0.92f * resize), originy + (0.51f * resize)); // Adjusted from -0.82f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.933f * resize), originy + (0.46f * resize)); // Adjusted from -0.833f
//     glVertex2f(originx + (-0.567f * resize), originy + (0.46f * resize));
//     glVertex2f(originx + (-0.563f * resize), originy + (0.44f * resize));
//     glVertex2f(originx + (-0.938f * resize), originy + (0.44f * resize)); // Adjusted from -0.838f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.945f * resize), originy + (0.39f * resize)); // Adjusted from -0.845f
//     glVertex2f(originx + (-0.554f * resize), originy + (0.39f * resize));
//     glVertex2f(originx + (-0.553f * resize), originy + (0.37f * resize));
//     glVertex2f(originx + (-0.948f * resize), originy + (0.37f * resize)); // Adjusted from -0.848f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.95f * resize), originy + (0.32f * resize)); // Adjusted from -0.85f
//     glVertex2f(originx + (-0.55f * resize), originy + (0.32f * resize));
//     glVertex2f(originx + (-0.55f * resize), originy + (0.30f * resize));
//     glVertex2f(originx + (-0.95f * resize), originy + (0.30f * resize)); // Adjusted from -0.85f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.95f * resize), originy + (0.24f * resize)); // Adjusted from -0.85f
//     glVertex2f(originx + (-0.55f * resize), originy + (0.24f * resize));
//     glVertex2f(originx + (-0.55f * resize), originy + (0.22f * resize));
//     glVertex2f(originx + (-0.95f * resize), originy + (0.22f * resize)); // Adjusted from -0.85f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.95f * resize), originy + (0.16f * resize)); // Adjusted from -0.85f
//     glVertex2f(originx + (-0.55f * resize), originy + (0.16f * resize));
//     glVertex2f(originx + (-0.55f * resize), originy + (0.14f * resize));
//     glVertex2f(originx + (-0.95f * resize), originy + (0.14f * resize)); // Adjusted from -0.85f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.95f * resize), originy + (0.08f * resize)); // Adjusted from -0.85f
//     glVertex2f(originx + (-0.55f * resize), originy + (0.08f * resize));
//     glVertex2f(originx + (-0.55f * resize), originy + (0.06f * resize));
//     glVertex2f(originx + (-0.95f * resize), originy + (0.06f * resize)); // Adjusted from -0.85f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.95f * resize), originy + (0.00f * resize)); // Adjusted from -0.85f
//     glVertex2f(originx + (-0.55f * resize), originy + (0.00f * resize));
//     glVertex2f(originx + (-0.55f * resize), originy + (-0.02f * resize));
//     glVertex2f(originx + (-0.95f * resize), originy + (-0.02f * resize)); // Adjusted from -0.85f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.95f * resize), originy + (-0.08f * resize)); // Adjusted from -0.85f
//     glVertex2f(originx + (-0.55f * resize), originy + (-0.08f * resize));
//     glVertex2f(originx + (-0.55f * resize), originy + (-0.10f * resize));
//     glVertex2f(originx + (-0.95f * resize), originy + (-0.10f * resize)); // Adjusted from -0.85f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.95f * resize), originy + (-0.16f * resize)); // Adjusted from -0.85f
//     glVertex2f(originx + (-0.55f * resize), originy + (-0.16f * resize));
//     glVertex2f(originx + (-0.55f * resize), originy + (-0.18f * resize));
//     glVertex2f(originx + (-0.95f * resize), originy + (-0.18f * resize)); // Adjusted from -0.85f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.17f, 0.18f, 0.18f);
//     glVertex2f(originx + (-0.95f * resize), originy + (-0.25f * resize)); // Adjusted from -0.85f
//     glVertex2f(originx + (-0.55f * resize), originy + (-0.25f * resize));
//     glVertex2f(originx + (-0.55f * resize), originy + (-0.27f * resize));
//     glVertex2f(originx + (-0.95f * resize), originy + (-0.27f * resize)); // Adjusted from -0.85f
//     glEnd();

//     // Door (adjusted left side slightly to maintain proportion)
//     glBegin(GL_POLYGON);
//     glColor3f(0.36f, 0.26f, 0.04f);
//     glVertex2f(originx + (-0.88f * resize), originy + (-0.30f * resize)); // Adjusted from -0.78f
//     glVertex2f(originx + (-0.88f * resize), originy + (0.18f * resize));  // Adjusted from -0.78f
//     glVertex2f(originx + (-0.62f * resize), originy + (0.18f * resize));
//     glVertex2f(originx + (-0.62f * resize), originy + (-0.30f * resize));
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.01f, 0.10f, 0.06f);
//     glVertex2f(originx + (-0.87f * resize), originy + (-0.28f * resize)); // Adjusted from -0.77f
//     glVertex2f(originx + (-0.87f * resize), originy + (0.16f * resize));  // Adjusted from -0.77f
//     glVertex2f(originx + (-0.63f * resize), originy + (0.16f * resize));
//     glVertex2f(originx + (-0.63f * resize), originy + (-0.28f * resize));
//     glEnd();

//     // Foundation (extended left to match wall)
//     glBegin(GL_POLYGON);
//     glColor3f(0.23f, 0.16f, 0.02f);
//     glVertex2f(originx + (-1.00f * resize), originy + (-0.30f * resize)); // Extended from -0.90f
//     glVertex2f(originx + (-1.00f * resize), originy + (-0.34f * resize)); // Extended from -0.90f
//     glVertex2f(originx + (-0.50f * resize), originy + (-0.34f * resize));
//     glVertex2f(originx + (-0.50f * resize), originy + (-0.30f * resize));
//     glEnd();

//     // Top triangles (shifted left and adjusted to match extended roof)
//     glBegin(GL_POLYGON);
//     glColor3f(0.36f, 0.26f, 0.04f);
//     glVertex2f(originx + (-0.75f * resize), originy + (0.70f * resize));  // Adjusted from -0.70f
//     glVertex2f(originx + (-0.775f * resize), originy + (0.66f * resize)); // Adjusted from -0.725f
//     glVertex2f(originx + (-0.725f * resize), originy + (0.66f * resize)); // Adjusted from -0.675f
//     glEnd();

//     glBegin(GL_POLYGON);
//     glColor3f(0.36f, 0.26f, 0.04f);
//     glVertex2f(originx + (-0.75f * resize), originy + (0.64f * resize)); // Adjusted from -0.70f
//     glVertex2f(originx + (-0.76f * resize), originy + (0.66f * resize)); // Adjusted from -0.71f
//     glVertex2f(originx + (-0.74f * resize), originy + (0.66f * resize)); // Adjusted from -0.69f
//     glEnd();
// }
