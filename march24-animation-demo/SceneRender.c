#include "../common/common.h"
#include "scene1/elephant.c"
#include "scene1/chamelon.c"
#include "scene1/chamelontounge_mov.c"
#include "scene1/butterfly.c"

/*******************************/
/* TYPE DEFINITIONS AND DECLARATIONS */
/******************************/

// Scene structure definition for Chain of Responsibility pattern
typedef struct Scene
{
    void (*render)(void);                    // Function to render the scene
    void (*update)(void);                    // Function to update the scene
    BOOL (*shouldTransition)(BOOL iSkipped); // Function to check if transition to next scene is needed
    struct Scene *nextScene;                 // Pointer to next scene in the chain
} Scene;

extern float D_cordinate;

// External scene variables
Scene *currentScene = NULL;

// Scene-specific globals
BOOL bCallTounge = FALSE;
BOOL bCallElephant = FALSE;
BOOL bCallButterfly = FALSE;

// Scene management functions declarations
void initScenes(void);
void updateCurrentScene(UINT iTimeElapsed);
void renderCurrentScene(void);
void logSceneTransition(UINT iTimeElapsed);

/*******************************/
/* SCENE FUNCTION DECLARATIONS */
/******************************/

// Forward declarations for scene functions
void scene6_4_1Render(void);
void scene6_4_1Update(void);
BOOL scene6_4_1ShouldTransition(BOOL iSkipped);

void scene6_4_2Render(void);
void scene6_4_2Update(void);
BOOL scene6_4_2ShouldTransition(BOOL iSkipped);

void scene6_4_3Render(void);
void scene6_4_3Update(void);
BOOL scene6_4_3ShouldTransition(BOOL iSkipped);

void scene6_4_4Render(void);
void scene6_4_4Update(void);
BOOL scene6_4_4ShouldTransition(BOOL iSkipped);

void scene6_4_5Render(void);
void scene6_4_5Update(void);
BOOL scene6_4_5ShouldTransition(BOOL iSkipped);

void scene6_4_6Render(void);
void scene6_4_6Update(void);
BOOL scene6_4_6ShouldTransition(BOOL iSkipped);

void scene2Render(void);
void scene2Update(void);
BOOL scene2ShouldTransition(BOOL iSkipped);

/*******************************/
/* SCENE MANAGEMENT VARIABLES */
/******************************/

// Scene management variables
Scene scene1 = {scene6_4_1Render, scene6_4_1Update, scene6_4_1ShouldTransition, NULL};
Scene scene3 = {scene6_4_2Render, scene6_4_2Update, scene6_4_2ShouldTransition, NULL};
Scene scene4 = {scene6_4_3Render, scene6_4_3Update, scene6_4_3ShouldTransition, NULL};
Scene scene5 = {scene6_4_4Render, scene6_4_4Update, scene6_4_4ShouldTransition, NULL};
Scene scene6 = {scene6_4_5Render, scene6_4_5Update, scene6_4_5ShouldTransition, NULL};
Scene scene7 = {scene6_4_6Render, scene6_4_6Update, scene6_4_6ShouldTransition, NULL};
Scene scene2 = {scene2Render, scene2Update, scene2ShouldTransition, NULL};

// External global variables from Raster.c
extern FILE *gpFile;
extern UINT iTimeElapsed;

/*******************************/
/* SCENE MANAGEMENT FUNCTIONS */
/******************************/

// Initialize the scene chain
void initScenes(void)
{
    scene1.nextScene = &scene3;
    scene3.nextScene = &scene4;
    scene4.nextScene = &scene5;
    scene5.nextScene = &scene6;
    scene6.nextScene = &scene7;
    scene7.nextScene = &scene2;
    scene2.nextScene = NULL; // End of chain
    currentScene = &scene1;  // Start with scene 1
}

// Update the current scene
void updateCurrentScene(UINT timeElapsed)
{
    if (currentScene)
    {
        // Call the current scene's update function
        if (currentScene->update)
        {
            currentScene->update();
        }

        if (currentScene->shouldTransition && currentScene->shouldTransition(FALSE))
        {
            if (currentScene->nextScene)
            {
                logSceneTransition(timeElapsed);
                currentScene = currentScene->nextScene;
            }
        }
    }
}

// Render the current scene
void renderCurrentScene(void)
{
    if (currentScene && currentScene->render)
    {
        currentScene->render();
    }
}

// Log scene transition
void logSceneTransition(UINT timeElapsed)
{
    if (gpFile)
    {
        fprintf(gpFile, "Transitioning to next scene at time %d seconds\n", timeElapsed);
    }
}

/*******************************/
/* SCENE 6_4_1 IMPLEMENTATION */
/******************************/

float D_cordinate = -0.4f;
float P_cordinate = -0.8f;
BOOL move = FALSE;

void updateD_Pos(void)
{
    D_cordinate += 0.06f;
    P_cordinate += 0.06f;
    if (D_cordinate > 0.6f)
    {
        move = FALSE;
    }
}

void scene6_4_1Render(void)
{
    drawRoom();
    drawBheem(0.2f, 0.0f, 0.6f, 0.0f, 0.0f);
    drawYuthishteer(-0.1f, 0.0f, 0.6, 0.0f, 1.0f);
    drawYuthishteer(-0.3f, 0.0f, 0.6, 0.0f, 1.0f);
    drawYuthishteer(-0.4f, -0.2f, 0.6, 0.0f, 1.0f);

    drawYudhishthir(0.1f, 0.0f, 0.6, 0);

    sittingkrishna(0.6, -0.1f, 0.3);
    drawDraupadi(D_cordinate, -0.3f, 0.6f, 3.0f, 1.0f);
    DrawPlateEP(P_cordinate, -0.45f, 0.4f);
    // Add plate;
}

void scene6_4_1Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed)
    {
    case 10:
        move = TRUE;
        break;
    }
    // Update specific elements
    if (move == TRUE)
        updateD_Pos();
}

BOOL scene6_4_1ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 90;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if (flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/
/* SCENE 6_4_2 IMPLEMENTATION */
/******************************/

void scene6_4_2Render(void)
{
    drawRoom();
    sittingkrishna(0.6, -0.1f, 0.7);
    drawDraupadi(0.58, 0.1f, 1.6f, 3.0f, 0.0f);
    DrawPlateEP(-0.3, -0.25f, 0.9f);
    // drawRiceGrain(-0.2, -0.15);
}

void scene6_4_2Update(void)
{
    // Update scene 2 elements
}

BOOL scene6_4_2ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 50;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if (flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/
/* SCENE 6_4_3 IMPLEMENTATION */
/******************************/

void scene6_4_3Render(void)
{
    drawRoom();
    drawBheem(0.2f, 0.0f, 0.6f, 0.0f, 0.0f);
    drawYuthishteer(-0.1f, 0.0f, 0.6, 0.0f, 1.0f);
    drawYuthishteer(-0.3f, 0.0f, 0.6, 0.0f, 1.0f);
    drawYuthishteer(-0.4f, -0.2f, 0.6, 0.0f, 1.0f);

    drawYudhishthir(0.1f, 0.0f, 0.6, 0);

    sittingkrishna(0.6, -0.1f, 0.3);
    drawDraupadi(0.5f, -0.2f, 0.6f, 3.0f, 0.0f);
    DrawPlateEP(0.1f, -0.35f, 0.4f);
    // Add plate;
}

void scene6_4_3Update(void)
{
}

BOOL scene6_4_3ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 40;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if (flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/
/* SCENE 6_4_4 IMPLEMENTATION */
/******************************/
float hX_cordinate = 1.0f;
float hY_cordinate = 1.0f;
BOOL handmove = FALSE;

void updateH_Pos(void)
{
    hX_cordinate -= 0.1f;
    hY_cordinate -= 0.1f;
    if (hX_cordinate < 0.47f)
    {
        handmove = FALSE;
    }
}

void scene6_4_4Render(void)
{
    drawRoom();
    DrawPlateEP(0.0, 0.0f, 1.9f);
    // KrishnaHand(0.47,0.25f,0.5f);
    KrishnaHand(hX_cordinate, hY_cordinate, 0.5f);
    drawRiceGrain(0.0, 0.0);
}

void scene6_4_4Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed)
    {
    case 20:
        handmove = TRUE;
        break;
    }
    // Update specific elements
    if (handmove == TRUE)
        updateH_Pos();
}

BOOL scene6_4_4ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 50;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if (flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/
/* SCENE 6_4_5 IMPLEMENTATION */
/******************************/

void scene6_4_5Render(void)
{
    drawRoom();
    drawBheem(1.9f, 0.0f, 1.6f, 0.0f, 0.0f);
    drawYuthishteer(0.6f, 0.1f, 1.6, 0.0f, 1.0f);
    drawYuthishteer(0.2f, 0.0f, 1.6, 0.0f, 1.0f);
    drawYuthishteer(1.5f, 0.0f, 1.6, 0.0f, 1.0f);
    
    drawYudhishthir(0.9f, -0.4f, 1.6, 0);
}

void scene6_4_5Update(void)
{
}

BOOL scene6_4_5ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 90;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if (flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/
/* SCENE 6_4_6 IMPLEMENTATION */
/******************************/

void scene6_4_6Render(void)
{
    drawRoom();

    sittingkrishna(0.6, -0.1f, 0.3);
}

void scene6_4_6Update(void)
{
}

BOOL scene6_4_6ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 90;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if (flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/
/* SCENE 2 IMPLEMENTATION */
/******************************/

void scene2Render(void)
{
    // Draw scene 2 elements
    // drawGround();
    // Add scene 2 specific rendering
}

void scene2Update(void)
{
    // Update scene 2 elements
}

BOOL scene2ShouldTransition(BOOL iSkipped)
{
    // 20 Sec is Temporarily set for testing
    int iThresholdTime = 200;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return TRUE;
}
