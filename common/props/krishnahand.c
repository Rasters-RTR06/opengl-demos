#include "../common.h"
void KrishnaHand(float originx, float originy, float resize) 
{
    glColor3f(0.286, 0.231, 0.196);  // Default hand color

    // Polygon 1
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * -0.244, originy + resize * 0.154);
    glVertex2f(originx + resize * 0.045, originy + resize * -0.067);
    glVertex2f(originx + resize * 0.249, originy + resize * -0.193);
    glVertex2f(originx + resize * 0.322, originy + resize * -0.120);
    glVertex2f(originx + resize * 0.390, originy + resize * 0.010);
    glVertex2f(originx + resize * 0.489, originy + resize * 0.110);
    glVertex2f(originx + resize * 0.292, originy + resize * 0.327);
    glVertex2f(originx + resize * 0.136, originy + resize * 0.252);
    glEnd();

    // Polygon 2
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * -0.244, originy + resize * 0.154);
    glVertex2f(originx + resize * -0.443, originy + resize * 0.106);
    glVertex2f(originx + resize * -0.159, originy + resize * -0.071);
    glVertex2f(originx + resize * 0.008, originy + resize * -0.043);
    glEnd();

    // Polygon 3
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * 0.093, originy + resize * -0.098);
    glVertex2f(originx + resize * 0.043, originy + resize * -0.213);
    glVertex2f(originx + resize * -0.073, originy + resize * -0.376);
    glVertex2f(originx + resize * -0.078, originy + resize * -0.453);
    glVertex2f(originx + resize * -0.020, originy + resize * -0.490);
    glVertex2f(originx + resize * 0.025, originy + resize * -0.465);
    glVertex2f(originx + resize * 0.003, originy + resize * -0.433);
    glVertex2f(originx + resize * 0.050, originy + resize * -0.364);
    glVertex2f(originx + resize * 0.108, originy + resize * -0.313);
    glVertex2f(originx + resize * 0.239, originy + resize * -0.215);
    glVertex2f(originx + resize * 0.267, originy + resize * -0.191);
    glVertex2f(originx + resize * 0.093, originy + resize * -0.098);
    glEnd();

    // Polygon 4
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * -0.290, originy + resize * 0.010);
    glVertex2f(originx + resize * -0.751, originy + resize * -0.333);
    glVertex2f(originx + resize * -0.821, originy + resize * -0.372);
    glVertex2f(originx + resize * -0.821, originy + resize * -0.415);
    glVertex2f(originx + resize * -0.804, originy + resize * -0.427);
    glVertex2f(originx + resize * -0.751, originy + resize * -0.415);
    glVertex2f(originx + resize * -0.554, originy + resize * -0.315);
    glVertex2f(originx + resize * -0.257, originy + resize * -0.118);
    glVertex2f(originx + resize * -0.156, originy + resize * -0.059);
    glEnd();

    // Polygon 5
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * -0.373, originy + resize * 0.067);
    glVertex2f(originx + resize * -0.489, originy + resize * -0.079);
    glVertex2f(originx + resize * -0.491, originy + resize * -0.138);
    glVertex2f(originx + resize * -0.272, originy + resize * 0.012);
    glEnd();

    // Polygon 6
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * -0.373, originy + resize * 0.081);
    glVertex2f(originx + resize * -0.592, originy + resize * -0.138);
    glVertex2f(originx + resize * -0.647, originy + resize * -0.152);
    glVertex2f(originx + resize * -0.635, originy + resize * -0.093);
    glVertex2f(originx + resize * -0.574, originy + resize * -0.002);
    glVertex2f(originx + resize * -0.524, originy + resize * 0.085);
    glVertex2f(originx + resize * -0.461, originy + resize * 0.098);
    glVertex2f(originx + resize * -0.416, originy + resize * 0.104);
    glEnd();

    // Polygon 7
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * -0.393, originy + resize * -0.209);
    glVertex2f(originx + resize * -0.378, originy + resize * -0.238);
    glVertex2f(originx + resize * -0.249, originy + resize * -0.242);
    glVertex2f(originx + resize * -0.212, originy + resize * -0.276);
    glVertex2f(originx + resize * -0.217, originy + resize * -0.333);
    glVertex2f(originx + resize * -0.307, originy + resize * -0.337);
    glVertex2f(originx + resize * -0.499, originy + resize * -0.317);
    glVertex2f(originx + resize * -0.524, originy + resize * -0.295);
    glEnd();

    // Polygons 8-11 (Different Colors)
    glColor3f(0.859, 0.616, 0.051);
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * 0.292, originy + resize * 0.327);
    glVertex2f(originx + resize * 0.373, originy + resize * 0.370);
    glVertex2f(originx + resize * 0.562, originy + resize * 0.165);
    glVertex2f(originx + resize * 0.489, originy + resize * 0.110);
    glEnd();

    glColor3f(0.741, 0.541, 0.082);
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * 0.373, originy + resize * 0.370);
    glVertex2f(originx + resize * 0.428, originy + resize * 0.413);
    glVertex2f(originx + resize * 0.625, originy + resize * 0.209);
    glVertex2f(originx + resize * 0.562, originy + resize * 0.165);
    glEnd();

    glColor3f(0.859, 0.616, 0.051);
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * 0.428, originy + resize * 0.413);
    glVertex2f(originx + resize * 0.486, originy + resize * 0.465);
    glVertex2f(originx + resize * 0.720, originy + resize * 0.238);
    glVertex2f(originx + resize * 0.625, originy + resize * 0.209);
    glEnd();

    glColor3f(0.286, 0.231, 0.196);
    glBegin(GL_POLYGON);
    glVertex2f(originx + resize * 0.486, originy + resize * 0.465);
    glVertex2f(originx + resize * 0.935, originy + resize * 0.785);
    glVertex2f(originx + resize * 0.932, originy + resize * 0.335);
    glVertex2f(originx + resize * 0.720, originy + resize * 0.238);
    glEnd();
}

