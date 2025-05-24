#include <stdlib.h>
#include <gl/GL.h>

// only call drawRain()

// variable declarations
// rain effect
#define RAIN_COUNT 500

typedef struct {
	float x, y, z;
	float speed;
} RainDrop;

RainDrop rain[RAIN_COUNT];



void reset_drop(RainDrop* drop) {
    drop->x = (rand() % 200 - 100) / 10.0f;
    drop->y = (rand() % 100) / 10.0f + 10.0f;
    drop->z = 0.0f;
    drop->speed = 0.1f + ((float)rand() / (float)(RAND_MAX / 0.2f));
}

void init_rain() {
    for (int i = 0; i < RAIN_COUNT; ++i) {
        reset_drop(&rain[i]);
    }
}

void update_rain() {
    for (int i = 0; i < RAIN_COUNT; ++i) {
        rain[i].y -= rain[i].speed;
        if (rain[i].y < -10.0f) {
            reset_drop(&rain[i]);
        }
    }
}

void drawRain(void) {
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // White raindrops
    for (int i = 0; i < RAIN_COUNT; ++i) {
        glVertex3f(rain[i].x, rain[i].y, rain[i].z);
        glVertex3f(rain[i].x, rain[i].y + 0.2f, rain[i].z);
    }
    glEnd();
}
