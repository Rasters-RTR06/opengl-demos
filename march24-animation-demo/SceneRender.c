#include "../common/common.h"
#include "scene1/elephant.c"
#include "scene1/chamelon.c"
#include "scene1/chamelontounge_mov.c"
#include "scene1/butterfly.c"
#include "../common/props/cranes.c"
#include "../common/props/patternedDeers.c"
#include "../common/props/plainDeers.c"
#include "../common/props/peacock.c"
#include "../common/props/fullkrushna.c"
#include "../common/props/horse.c"
#include "../common/props/ant.c"
// #include "../common/props/SandeshText.c"
// #include "../common/props/Sahadev.c"
#include "../common/props/nikhilsSandeshtxt.c"
#include "Scene6_2Render.h"
#include "../common/props/krishnastanding.c"
#include "../common/props/tutaribai.c"
#include "../common/props/flowers.c"
#include "../common/props/Slogan.c"
#include "../common/props/plate.c"
#include "Scene4.c"
#include "../common/props/SimpleHut.c"
#include "../common/props/endcredits.c"
/*******************************/

/* TYPE DEFINITIONS AND DECLARATIONS */
/******************************/

extern float pointResize;

// Scene structure definition for Chain of Responsibility pattern
typedef struct Scene
{
    void (*render)(void);                    // Function to render the scene
    void (*update)(void);                    // Function to update the scene
    BOOL (*shouldTransition)(BOOL iSkipped); // Function to check if transition to next scene is needed
    struct Scene *nextScene;                 // Pointer to next scene in the chain
} Scene;

// External scene variables
Scene *currentScene = NULL;

// Scene-specific globals
BOOL bCallTounge = FALSE;
BOOL bCallElephant = FALSE;
BOOL bCallButterfly = FALSE;
BOOL bCallSandesh = FALSE;

// scene 5 specific
BOOL bShowRotatingPlants = FALSE;
BOOL bShriKrishnaEntry = FALSE;
BOOL bShowLake = FALSE;
BOOL bShowCranes = FALSE;
BOOL bShowPatternedDeers = FALSE;
BOOL bShowFlowers = FALSE;
BOOL bShowPeacock = FALSE;
BOOL bShowChamelon = FALSE;

float flowerRotateAngle = 0.0f;
TRANSLATION krishnaScene5Translation = {0.0f, 0.0f, 0.0f};
TRANSLATION rathScene5Translation = {0.0f, 0.0f, 0.0f};
TRANSLATION horseScene5Translation = {0.0f, 0.0f, 0.0f};

// scene 7 specific variable
float scaleSlogan = 0.0f;

// Scene management functions declarations
void initScenes(void);
void updateCurrentScene(UINT iTimeElapsed);
void renderCurrentScene(void);
void logSceneTransition(UINT iTimeElapsed);

/*******************************/
/* SCENE FUNCTION DECLARATIONS */
/******************************/

// Forward declarations for scene functions
void scene0Render(void);
void scene0Update(void);
BOOL scene0ShouldTransition(BOOL iSkipped);
void PrabhatRender(void);
void PrabhatUpdate(void);
BOOL PrabhatShouldTransition(BOOL iSkipped);
void scene1Render(void);
void scene1Update(void);
BOOL scene1ShouldTransition(BOOL iSkipped);
void scene2Render(void);
void scene2Update(void);
BOOL scene2ShouldTransition(BOOL iSkipped);
void scene3Render(void);
void scene3Update(void);
BOOL scene3ShouldTransition(BOOL iSkipped);
void scene4Render(void);
void scene4Update(void);
BOOL scene4ShouldTransition(BOOL iSkipped);
void scene5Render(void);
void scene5Update(void);
BOOL scene5ShouldTransition(BOOL iSkipped);
void scene6_1Render(void);
void scene6_1Update(void);
BOOL scene6_1ShouldTransition(BOOL iSkipped);
void scene6_2Render(void);
void scene6_2Update(void);
BOOL scene6_2ShouldTransition(BOOL iSkipped);

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

void scene7Render(void);
void scene7Update(void);
BOOL scene7ShouldTransition(BOOL iSkipped);

void outroRender(void);
void outroUpdate(void);
BOOL outroShouldTransition(BOOL iSkipped);

/*******************************/
/* SCENE MANAGEMENT VARIABLES */
/******************************/

// Scene management variables
Scene scene0 = {scene0Render, scene0Update, scene0ShouldTransition, NULL};
Scene Prabhat = {PrabhatRender, PrabhatUpdate, PrabhatShouldTransition, NULL};
Scene scene1 = {scene1Render, scene1Update, scene1ShouldTransition, NULL};
Scene scene2 = {scene2Render, scene2Update, scene2ShouldTransition, NULL};
Scene scene3 = {scene3Render, scene3Update, scene3ShouldTransition, NULL};
Scene scene4 = {scene4Render, scene4Update, scene4ShouldTransition, NULL};
Scene scene5;
Scene scene6_1;
Scene scene6_2 = {scene6_2Render, scene6_2Update, scene6_2ShouldTransition, NULL};

// My code start here
Scene scene6_4_1 = {scene6_4_1Render, scene6_4_1Update, scene6_4_1ShouldTransition, NULL};
Scene scene6_4_2 = {scene6_4_2Render, scene6_4_2Update, scene6_4_2ShouldTransition, NULL};
Scene scene6_4_3 = {scene6_4_3Render, scene6_4_3Update, scene6_4_3ShouldTransition, NULL};
Scene scene6_4_4 = {scene6_4_4Render, scene6_4_4Update, scene6_4_4ShouldTransition, NULL};
Scene scene6_4_5 = {scene6_4_5Render, scene6_4_5Update, scene6_4_5ShouldTransition, NULL};
Scene scene6_4_6 = {scene6_4_6Render, scene6_4_6Update, scene6_4_6ShouldTransition, NULL};

Scene scene7 = {scene7Render, scene7Update, scene7ShouldTransition, NULL};
Scene scene6_5;

Scene outro = {outroRender, outroUpdate, outroShouldTransition, NULL};

// External global variables from Raster.c
extern FILE *gpFile;
extern UINT iTimeElapsed;

TRANSLATION rathTranslation;
TRANSLATION cameraTranslationScene6_5;
SCALING scalingScene6_5;

TRANSLATION rathTranslationScene6_1;
TRANSLATION cameraTranslationScene6_1;
SCALING scalingScene6_1;

/*******************************/
/* SCENE MANAGEMENT FUNCTIONS */
/******************************/

// Initialize the scene chain
void initScenes(void)
{
    // function prototypes
    void renderScene6_5(void);
    void updateScene6_5(void);
    BOOL shouldTransitionScene6_5(BOOL);

    // code
    scene5 = (Scene){scene5Render, scene5Update, scene5ShouldTransition, NULL};
    scene6_1 = (Scene){scene6_1Render, scene6_1Update, scene6_1ShouldTransition, NULL};
    scene6_5 = (Scene){
        renderScene6_5,
        updateScene6_5,
        shouldTransitionScene6_5,
        NULL};

    scene0.nextScene = &Prabhat;
    Prabhat.nextScene = &scene1;
    scene1.nextScene = &scene2;
    scene2.nextScene = &scene3;
    scene3.nextScene = &scene4;
    scene4.nextScene = &scene5;
    scene5.nextScene = &scene6_1;
    scene6_1.nextScene = &scene6_2;
    scene6_2.nextScene = &scene6_4_1;
    scene6_4_1.nextScene = &scene6_4_2;
    scene6_4_2.nextScene = &scene6_4_3;
    scene6_4_3.nextScene = &scene6_4_4;
    scene6_4_4.nextScene = &scene6_4_5;
    scene6_4_5.nextScene = &scene6_4_6;
    scene6_4_6.nextScene = &scene6_5;
    scene6_5.nextScene = &scene7; // Fixed: Added & to get the address of scene7
    scene7.nextScene = &outro;    // End of chain
    outro.nextScene = NULL;

    currentScene = &scene0; // Start with scene 1

    cameraTranslationScene6_5 = (TRANSLATION){0.0f, 0.0f, 0.0f};
    scalingScene6_5 = (SCALING){1.0f, 1.0f, 1.0f};

    cameraTranslationScene6_1 = (TRANSLATION){0.0f, 0.0f, 0.0f};
    rathTranslationScene6_1 = (TRANSLATION){1.0f * scalingScene6_1.x, 0.0f * scalingScene6_1.y, 0.0f};
    scalingScene6_1 = (SCALING){1.0f, 1.0f, 1.0f};

    cameraTranslationScene6_2 = (TRANSLATION){0.0f, 0.0f, 0.0f};
    scalingScene6_2 = (SCALING){1.0f, 1.0f, 1.0f};

    pointResize = 1.0f;

    FILE *fp = fopen("./sandeshfinal.wav", "r");
    bool is_exist = false;
    if (fp != NULL)
    {
        is_exist = true;
        fclose(fp); // close the file
    }
    if (is_exist == true)
    {
        PlaySound("./sandeshfinal.wav", NULL, SND_ASYNC | SND_FILENAME);
    }
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

/***************************************************************** */

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
    /*  drawRoom();
      drawBheem(0.2f ,0.0f,0.6f, 0.0f,0.0f);
      drawYudhishthir(-0.1f,0.0f,0.6,1.0f);
      drawSahadev(-0.3f, 0.0f, 0.6, 0.0f);
      drawYuthishteer(-0.4f,-0.2f,0.6,0.0f,1.0f);
      drawYuthishteer(0.1f,0.0f,0.6,0.0f,1.0f);

      sittingkrishna(0.6, -0.1f, 0.3);
      drawDraupadi(D_cordinate, -0.3f, 0.6f, 3.0f, 1.0f);
      DrawPlateEP(P_cordinate,-0.45f,0.4f);
     // Add plate;
     */
    drawRoom();
    // drawNakul(0.45, -0.3, 0.5, 1, 1);
    // drawDraupadi(0.30, -0.3, 0.5, 1, 1);
    /* drawBheem(0.2f ,0.0f,0.6f, 0.0f, 1);
     drawNakul(-0.1f,0.0f,0.6,1.0f, 1);

     drawArjun(-0.4f,-0.2f,0.6,0.0f, 1, 0);
     drawNakul(0.1f,0.0f,0.6,0.0f, 1);
     drawSahadev(-0.3f, 0.0f, 0.6, 0.0f, 1, 0);
    */
    drawBheem(0.145f, 0.13f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_GESTURE);
    drawArjun(0.30f, -0.05f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_GESTURE, HIDE_BOW_ARROW);
    drawYudhishthir(0.42f, -0.20f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_FOLDED);

    drawSahadev(-0.25f, -0.05f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_FOLDED, HIDE_BOW_ARROW);
    drawNakul(-0.05f, -0.20f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_FOLDED);
    sittingkrishna(0.6, -0.1f, 0.3);

    drawDraupadi(D_cordinate, -0.3f, 0.6f, 3.0f, 1.0f);
    DrawPlateEP(P_cordinate, -0.45f, 0.4f);
}

void scene6_4_1Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed)
    {
    case 1350:
        move = TRUE;
        break;
    }
    // Update specific elements
    if (move == TRUE)
        updateD_Pos();
}

BOOL scene6_4_1ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 1430;
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
    int iThresholdTime = 20;
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
    drawBheem(0.145f, 0.13f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_GESTURE);
    drawArjun(0.30f, -0.05f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_GESTURE, HIDE_BOW_ARROW);
    drawYudhishthir(0.42f, -0.20f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_FOLDED);

    drawSahadev(-0.25f, -0.05f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_FOLDED, HIDE_BOW_ARROW);
    drawNakul(-0.05f, -0.20f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_FOLDED);
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
    int iThresholdTime = 20;
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
    drawRiceGrain(0.0, 0.1);
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
    drawBheem(1.9f, 0.0f, 1.6f, CHARACTER_SITTING, CHARACTER_HAND_GESTURE);
    drawArjun(0.6f, 0.1f, 1.6, CHARACTER_SITTING, CHARACTER_HAND_GESTURE, HIDE_BOW_ARROW);
    drawYudhishthir(0.2f, 0.0f, 1.6, CHARACTER_SITTING, CHARACTER_HAND_FOLDED);

    drawSahadev(1.5f, 0.0f, 1.6, CHARACTER_SITTING, CHARACTER_HAND_FOLDED, HIDE_BOW_ARROW);
    drawNakul(0.9f, -0.4f, 1.6, CHARACTER_SITTING, CHARACTER_HAND_FOLDED);
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

    sittingkrishna(0.6, -0.1f, 1.6);
}

void scene6_4_6Update(void)
{
}

BOOL scene6_4_6ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 30;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if (flag)
    {
        iTimeElapsed = 1620;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/**************************************************************** */

/*******************************/
/* SCENE 0 IMPLEMENTATION */
/******************************/
void scene0Render(void)
{
    drawIntro();
}

void scene0Update(void)
{
    updateIntro();
}

BOOL scene0ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 200;
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
/* PRABHAT IMPLEMENTATION */
/******************************/
void PrabhatRender(void)
{
    drawGround();
    drawTutariWithAnimation(0, 0, 1);
}

void PrabhatUpdate(void)
{
    updateTutariBai(iTimeElapsed);
}

BOOL PrabhatShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 260;
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
/* SCENE 1 IMPLEMENTATION */
/******************************/
void scene1Render(void)
{
    drawGround();
    // drawDenseForrest();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 1.5f, 0.0f);
    drawFrontTrees();
    glLoadIdentity();

    elephant();

    drawFrontTrees();

    drawButterfly(butterflyX, butterflyY, 0.6f, butterflyRotation);
    toungeMovement();
    // chamelon(1.5f, -0.35f, 0.2);

    updateSandesh(bCallSandesh, 1.0f);
}

void scene1Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed)
    {
    case 30:
        bCallTounge = TRUE;
        break;
    case 45:
        bCallButterfly = TRUE;
        bCallElephant = TRUE;
        break;
    case 80:
        bCallSandesh = TRUE; // Hide Sandesh message before scene transition
        break;
    }

    // Update specific elements
    if (bCallTounge == TRUE)
        updateTounge();

    if (bCallElephant == TRUE)
        updateElephant();

    if (bCallButterfly)
        updateButterfly();
}

BOOL scene1ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 200;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        // flag = TRUE;
    }
    /*if (flag)
    {
        iTimeElapsed = 0;
    }*/
    // Transition to the next scene after 15 seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 2 IMPLEMENTATION */
/******************************/
//
// void scene2Render(void)
//{
//    // Draw scene 2 elements
//     drawGround();
//    // Add scene 2 specific rendering
//}
//
// void scene2Update(void)
//{
//    // Update scene 2 elements
//}
//
// BOOL scene2ShouldTransition(BOOL iSkipped)
//{
//    int iThresholdTime = 460;
//    BOOL flag = FALSE;
//    if (iSkipped || (iTimeElapsed >= iThresholdTime))
//    {
//        iTimeElapsed = 0;
//        iTimeElapsed += iThresholdTime;
//        flag = TRUE;
//    }
//    if(flag)
//    {
//        iTimeElapsed = 0;
//    }
//    // Transition to the next scene after 15 seconds
//    return (flag);
//
//
/*******************************/
/* SCENE 2 IMPLEMENTATION */
/******************************/

void scene2Render(void)
{
    // bush colors and positions for the bottom plants.
    struct Color darkGreen = {0.004f, 0.114f, 0.165f};
    struct Color yellowish = {0.735f, 0.625f, 0.455f};
    float startX = -1.0f; // Small bush left start
    float endX = 1.0f;    // Small bush left start
    float spacing = 0.2f; // Distance between plants

    // Define phase durations (in seconds).
    const float zoomOutDuration = 5.0f;       // Phase 0: Zoom out from top right.
    const float waitAfterZoomOut = 6.0f;      // Phase 1: Wait after zoom out.
    const float zoomInDuration = 4.0f;        // Phase 2: Zoom in centered.
    const float waitAfterZoomIn = 4.0f;       // Phase 3: Wait after zoom in.
    const float leftMoveZoomDuration = 10.0f; // Phase 4: While moving left, zoom out over this duration.

    // Zoom factors.
    const float zoomInFactor = 6.0f;  // Fully zoomed in.
    const float zoomOutFactor = 1.1f; // Zoomed out state.

    // Speed for camera left movement.
    const float cameraSpeed = 0.01f;

    // Phase definitions:
    // Phase 0: Zoom out from top right.
    // Phase 1: Wait after zoom out.
    // Phase 2: Zoom in centered.
    // Phase 3: Wait after zoom in.
    // Phase 4: Move camera to the left while zooming out.
    static int phase = 0;
    static clock_t phaseStartTime = 0;
    static float cameraOffset = -1.0f; // leftward camera movement.

    // Initialize phase start time on the first call.
    if (phaseStartTime == 0)
        phaseStartTime = clock();

    // Get elapsed time (in seconds) for the current phase.
    clock_t currentTime = clock();
    float elapsed = ((float)(currentTime - phaseStartTime)) / CLOCKS_PER_SEC;

    float currentZoom = 1.0f;

    if (phase == 0)
    {
        // Phase 0: Zoom out from the top right.
        if (elapsed < zoomOutDuration)
        {
            currentZoom = zoomInFactor - (zoomInFactor - zoomOutFactor) * (elapsed / zoomOutDuration);
        }
        else
        {
            currentZoom = zoomOutFactor;
            phase = 1; // Transition to Phase 1.
            phaseStartTime = clock();
        }
    }
    else if (phase == 1)
    {
        // Phase 1: Wait after zoom out.
        currentZoom = zoomOutFactor;
        if (elapsed >= waitAfterZoomOut)
        {
            phase = 2; // Transition to Phase 2.
            phaseStartTime = clock();
        }
    }
    else if (phase == 2)
    {
        // Phase 2: Zoom in centered.
        if (elapsed < zoomInDuration)
        {
            currentZoom = zoomOutFactor + (zoomInFactor - zoomOutFactor) * (elapsed / zoomInDuration);
        }
        else
        {
            currentZoom = zoomInFactor;
            phase = 3; // Transition to Phase 3.
            phaseStartTime = clock();
        }
    }
    else if (phase == 3)
    {
        // Phase 3: Wait after zoom in.
        currentZoom = zoomInFactor;
        if (elapsed >= waitAfterZoomIn)
        {
            phase = 4; // Transition to Phase 4.
            phaseStartTime = clock();
        }
    }
    else if (phase == 4)
    {
        // Phase 4: Move camera to the left.
        if (elapsed < leftMoveZoomDuration)
        {
            currentZoom = zoomInFactor - (zoomInFactor - zoomOutFactor) * (elapsed / leftMoveZoomDuration);
        }
        else
        {
            currentZoom = zoomOutFactor;
        }
        cameraOffset = cameraSpeed * elapsed;
        glPushMatrix();
        glTranslatef(-1.0f, 0.0f, 0.0f);
        drawGround();
        glPopMatrix();
    }

    pointResize = currentZoom;

    // Set up the transformation matrix.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (phase == 0 || phase == 1)
    {
        // For Phases 0 and 1 (zoom out and wait), use the top right pivot (1,1).
        glTranslatef(1.0f, 1.0f, 0.0f);
        glScalef(currentZoom, currentZoom, 1.0f);
        glTranslatef(-1.0f, -1.0f, 0.0f);
    }
    else
    {
        // For Phases 2, 3, and 4.
        glTranslatef(0.0f, -0.3f, 0.0f);
        glScalef(currentZoom, currentZoom, 1.0f);
        glTranslatef(-0.0f, 0.3f, 0.0f);
        if (phase == 4)
        {
            // Move camera to left
            glTranslatef(cameraOffset, 0.0f, 0.0f);
        }
    }

    // Draw scene elements.
    drawGround();
    drawYudhishthir(0.45, -0.3, 0.5, 1, 1);
    drawDraupadi(0.30, -0.3, 0.5, 1, 1);
    drawBheem(0.15, -0.3, 0.45, 1, 1);
    drawArjun(0.00, -0.3, 0.5, 1, 1, 0);
    drawNakul(-0.20, -0.3, 0.5, 1, 1);
    drawSahadev(-0.35, -0.3, 0.5, 1, 1, 0);
    drawDenseForrest();

    if (phase == 0 || (phase == 1 && elapsed < 2.0f))
    {
        for (float x = startX; x <= endX; x += spacing)
        {
            drawCompactPlant(x, -1.0f, darkGreen, yellowish);
        }
        drawTallNarrowPlant(-0.3f, -1.0f, darkGreen, yellowish);
    }
    else if ((phase == 1 && elapsed >= 2.0f) || phase >= 2)
    {
        drawFrontTrees();
    }
}

void scene2Update(void)
{

    // Update scene 2 elements
    updateDenseForrest();
    updateFrontForrest();
}

BOOL scene2ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 460;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    if (iTimeElapsed >= iThresholdTime)
    {
        iTimeElapsed = 460;
        return TRUE;
    }
    else
        return FALSE;
}

void scene3Render(void)
{
    // Phase durations (in seconds)
    const float waitDuration = 1.0f;   // Phase 1: Stay still.
    const float zoomInDuration = 4.0f; // Phase 2: Zoom in.

    // Zoom factors.
    const float zoomOutFactor = 1.1f; // Zoom level during the still phase.
    const float zoomInFactor = 4.0f;  // Fully zoomed-in state.

    // Static phase tracking variables.
    // Phase 1: Stay still, Phase 2: Zoom in.
    static int phase = 1;
    static clock_t phaseStartTime = 0;

    // phase start time
    if (phaseStartTime == 0)
        phaseStartTime = clock();

    // Compute elapsed time (in seconds) for the current phase.
    clock_t currentTime = clock();
    float elapsed = ((float)(currentTime - phaseStartTime)) / CLOCKS_PER_SEC;

    // Determine the current zoom factor.
    float currentZoom = zoomOutFactor;
    if (phase == 1)
    {
        // Phase 1: Stay still with constant zoomOutFactor.
        currentZoom = zoomOutFactor;
        if (elapsed >= waitDuration)
        {
            phase = 2; // Transition to zoom-in phase.
            phaseStartTime = clock();
        }
    }
    else if (phase == 2)
    {
        // Phase 2: Gradually zoom in.
        if (elapsed < zoomInDuration)
        {
            currentZoom = zoomOutFactor + (zoomInFactor - zoomOutFactor) * (elapsed / zoomInDuration);
        }
        else
        {
            currentZoom = zoomInFactor;
        }
    }

    pointResize = currentZoom;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-0.70f, 0.20f, 0.0f);
    glScalef(currentZoom, currentZoom, 1.0f);
    glTranslatef(0.70f, -0.20f, 0.0f);

    // Draw scene elements.
    drawGround();
    drawDenseForrest();
    // drawRightPatternedDeer(0.9, 0.7, 0.05);
    //  drawLeftPatternedDeer(0.4, 0.7, 0.05);

    partUpperHut(-0.6f, 0.3f, 0.34f, 0.15f, 0.52f, 0.45f, 0.19f, 1);
    partLowerHut(0.1f, 0.0f, 1.0f);

    drawDraupadi(-0.2, 0.0, 0.5, 1, 1);
    drawTopDeerNearDraupadi(0.4f, 0.4f, 0.50f);
    drawBottomDeerNearDraupadi(0.1f, -0.3f, 0.50f);
    drawFrontTrees();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void scene3Update(void)
{

    // Update scene 3 elements
}

BOOL scene3ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 520;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 2 min 14 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 4 IMPLEMENTATION */
/******************************/
void scene4Render(void)
{
    sceneFourRender();
}

void scene4Update(void)
{
    sceneFourUpdate(iTimeElapsed - 520); //  as sceneFourUpdate consider times from start or zero so we need to pass time from zero for update of scene 4
                                         //  i.e. iTimeElapsed - (start time of scene 4 or end time of previous scene)
                                         //  i.e. iTimeElapsed - (iThresholdTime for previous scene) === iTimeElapsed - 520
}

BOOL scene4ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 720; //  The sompletion time of scene4 is considered as 20 sec
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 5 IMPLEMENTATION */
/******************************/
float riverMovX = 0.0f;

void drawRiver(float fSpawnAt[2], float fScaleBy)
{
    // river wave
    riverMovX += 0.005f;
    if (riverMovX > 2.0f * PI)
    {
        riverMovX = 0.0f;
    }
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.11, 0.443, 0.502);

    float riverY = -0.5f * fScaleBy + fSpawnAt[1];
    float amplitude = 0.03f * fScaleBy;
    float wavelength = 5.0f / fScaleBy;

    // Water Blue
    for (float x = -1.0f * fScaleBy + fSpawnAt[0]; x <= 1.0f * fScaleBy + fSpawnAt[0]; x += 0.01f * fScaleBy)
    {
        float y = riverY + amplitude * sin(wavelength * (x - fSpawnAt[0]) / fScaleBy + riverMovX);

        glVertex2f(x, y);
        glVertex2f(x, riverY - 0.15f * fScaleBy);
    }
    glEnd();

    // Water Reflection white
    glBegin(GL_QUAD_STRIP);
    glColor4f(0.6f, 0.8f, 1.0f, 0.3f);
    for (float x = -1.0f * fScaleBy + fSpawnAt[0]; x <= 1.0f * fScaleBy + fSpawnAt[0]; x += 0.01f * fScaleBy)
    {
        float y = riverY + amplitude * 0.5f * sin(wavelength * (x - fSpawnAt[0]) / fScaleBy + riverMovX + PI);
        y = y - 0.05f * fScaleBy;
        glVertex2f(x, y);
        glVertex2f(x, y - 0.02f);
    }
    glEnd();
}

float fSpawnPos1[2] = {0.0f, 1.25f};
float fSpawnPos2[2] = {0.0f, 1.15f};
float fSpawnPos3[2] = {0.0f, 1.05f};
float fSpawnPos4[2] = {0.0f, 0.95f};
float fSpawnPos5[2] = {0.0f, 0.85f};
void scene5Render(void)
{
    /*
    Elements' Sequence :
                1. Rotating plants at time 1.13 (73 seconds)
                2. lake and cranes, Bhagvan shrikrishna ki sawari   at time 1.16 (76 seconds)
                3. Patterned deers at time  1.24 (84 seconds)
                4. Flowers  - Jungle me mangal chaaya at time 1.27 (87 seconds)
                5. Peacock at time 1.33 (95 seconds)

    */
    // Draw scene 5 elements
    // drawGround();
    if (bShowRotatingPlants == TRUE)
    {
        drawGround();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 1.5f, 0.0f);
        drawFrontTrees();
        glLoadIdentity();
        drawRiver(fSpawnPos1, 1.2f);
        drawRiver(fSpawnPos2, 1.2f);
        drawRiver(fSpawnPos3, 1.2f);
        drawRiver(fSpawnPos4, 1.2f);
        drawRiver(fSpawnPos5, 1.2f);

        drawCraneOne(-0.6f, 0.2f, 0.6f);
        drawCraneTwo(0.2f, 0.2f, 0.6f);
        drawFrontTrees();
    }
    if (bShriKrishnaEntry = TRUE && bShowLake == TRUE && bShowCranes == TRUE)
    {
        // lake and cranes
        drawGround();
        // drawDenseForrest();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 1.5f, 0.0f);
        drawFrontTrees();
        glLoadIdentity();
        drawRiver(fSpawnPos1, 1.2f);
        drawRiver(fSpawnPos2, 1.2f);
        drawRiver(fSpawnPos3, 1.2f);
        drawRiver(fSpawnPos4, 1.2f);
        drawRiver(fSpawnPos5, 1.2f);

        drawCraneOne(-0.6f, 0.2f, 0.6f);
        drawCraneTwo(0.2f, 0.2f, 0.6f);

        // Shri-Krishna
        KrishnaRath(-0.2f + krishnaScene5Translation.x, 0.0f + krishnaScene5Translation.y, 0.30f);
        // Rath
        rath((MY_POINT){0.0f, -0.5f, 0.8f}, rathScene5Translation, (SCALING){1.2f, 1.2f, 1.2f});
        drawHorse(-0.5f + horseScene5Translation.x, -0.3f + horseScene5Translation.y, 0.6f);
        drawFrontTrees();
    }

    if (bShowFlowers == TRUE)
    {
        drawGround();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glScalef(0.2f, 0.2f, 0.0f);
        glRotatef(flowerRotateAngle, 0.0f, 0.0f, 1.0f);
        drawCurve();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glScalef(1.0f, 1.0f, 1.0f);

        drawFrontTrees();
    }
    if (bShowPatternedDeers == TRUE)
    {
        drawGround();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 1.5f, 0.0f);
        drawFrontTrees();
        glLoadIdentity();

        drawRightPatternedDeer(0.0f, 0.0f, 0.5f);
        drawLeftPatternedDeer(-0.4f, 0.0f, 0.5f);
        drawFrontTrees();
    }
    if (bShowPeacock == TRUE)
    {
        drawGround();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 1.5f, 0.0f);
        drawFrontTrees();
        glLoadIdentity();

        drawPeacock(0.0f, 0.0f, 0.8f);
        drawAnt(0.5f, -0.15f, 0.3f);
        drawAnt(-0.5f, -0.15f, 0.3f);
    }
    if (bShowChamelon == TRUE)
    {
        drawGround();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 1.5f, 0.0f);
        drawFrontTrees();
        glLoadIdentity();

        chamelon(0.5f, -0.0f, 0.2);
    }
}

void scene5Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed)
    {
    case 720:
        bShowRotatingPlants = TRUE;

        break;
    case 740:
        bShowRotatingPlants = FALSE;
        bShriKrishnaEntry = TRUE;
        bMoveRath = TRUE;
        // to make whose chariot dissaper before it enters from right side of the screen
        krishnaScene5Translation.x = 1.6f;
        rathScene5Translation.x = 1.6f;
        horseScene5Translation.x = 1.6f;
        bShowLake = TRUE;
        bShowCranes = TRUE;
        break;

    case 790:
        bShriKrishnaEntry = FALSE;
        bMoveRath = FALSE;
        bShowLake = FALSE;
        bShowCranes = FALSE;
        bShowPatternedDeers = TRUE;
        break;
    case 830:
        bShowPatternedDeers = FALSE;
        bShowFlowers = TRUE;
        break;
    case 850:
        bShowFlowers = FALSE;
        bShowPeacock = TRUE;
        break;
    case 900:
        bShowPeacock = FALSE;
        bShowChamelon = TRUE;
        break;
    }

    pointResize = 1.0f;

    // Update specific elements
    if (bShowRotatingPlants == TRUE)
    {
        flowerRotateAngle += 0.01f;
    }
    if (bShriKrishnaEntry == TRUE)
    {
        krishnaScene5Translation.x -= 0.01f;
        rathScene5Translation.x -= 0.01f;
        horseScene5Translation.x -= 0.01f;
    }
    if (bShowFlowers == TRUE)
    {
        // rotating flowers
    }
    if (bShowPeacock == TRUE)
    {
        // dancing peacock
    }
}

BOOL scene5ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 950;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 1 min 35 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 6_1 IMPLEMENTATION */
/*
 * scene starts at 95 secs
 * 950: krishna comes on chariot for 2 secs
 * 970: scene zooms out and shows krishna with some pandavs, zooming out time 2 secs
 * 990: scene translates towards left for 4 secs and pauses when draupadi appears, showing all pandavas
 * 1030: zoom in draupadi takes 3 secs
 */
/******************************/

void drawChariotScene6_1()
{
    // MY_POINT startPosition = {0.859f + rathTranslationScene6_1.x, -0.47f + rathTranslationScene6_1.y, 0.0f + rathTranslationScene6_1.z};
    MY_POINT startPosition = {0.859f, -0.47f, 0.0f};
    SCALING scaleBy = {0.8f, 0.8f, 0.8f};

    // KrishnaStanding(0.75f + rathTranslationScene6_1.x, -0.1f + rathTranslationScene6_1.y, 0.2f);
    KrishnaRath(0.75f + rathTranslationScene6_1.x, -0.1f + rathTranslationScene6_1.y, 0.22f);

    drawHorse(0.5f + rathTranslationScene6_1.x, -0.25f + rathTranslationScene6_1.y, 0.5f);
    rath(startPosition, rathTranslationScene6_1, scaleBy);
}

void scene6_1Render()
{
    // function prototyes
    void drawChariotScene6_1();

    // set it to identity matrix
    glLoadIdentity();

    // Draw scene elements.
    drawGround();

    // set it to identity matrix
    glLoadIdentity();

    // translate
    glTranslatef(cameraTranslationScene6_1.x, cameraTranslationScene6_1.y, cameraTranslationScene6_1.z);
    glScalef(scalingScene6_1.x, scalingScene6_1.y, scalingScene6_1.z);

    drawDenseForrest();

    partUpperHut(-1.0f, 0.3f, 0.34f, 0.15f, 0.52f, 0.45f, 0.19f, 1);
    partLowerHut(-0.3f, 0.0f, 1.0f);

    drawYudhishthir(0.15, -0.1, 0.5, 1, 1);
    drawBheem(0.00, -0.1, 0.5, 1, 1);
    drawArjun(-0.15, -0.1, 0.5, 1, 1, 0);
    drawNakul(-0.30, -0.1, 0.5, 1, 1);
    drawSahadev(-0.45, -0.1, 0.5, 1, 1, 0);
    drawDraupadi(-0.60, 0.1, 0.5, 1, 1);

    drawChariotScene6_1();

    drawFrontTrees();
}

void scene6_1Update()
{
    static GLboolean zoomOutKrishna = FALSE;
    static GLboolean translateKrishna = FALSE;
    static GLboolean sceneTranslateLeft = FALSE;
    static GLboolean zoomInDraupadi = FALSE;

    static int callCount = 0;

    switch (iTimeElapsed)
    {
    case 950:
        translateKrishna = TRUE;
        bMoveRath = TRUE;
        scalingScene6_1 = (SCALING){4.0f, 4.0f, 4.0f};
        cameraTranslationScene6_1 = (TRANSLATION){-0.7f * scalingScene6_1.x, 0.0f * scalingScene6_1.y, 0.0f};
        rathTranslationScene6_1 = (TRANSLATION){0.4f * scalingScene6_1.x, 0.0f * scalingScene6_1.y, 0.0f};
        break;

    case 980:
        translateKrishna = FALSE;
        bMoveRath = FALSE;
        zoomOutKrishna = TRUE;
        scalingScene6_1 = (SCALING){4.0f, 4.0f, 4.0f};
        cameraTranslationScene6_1 = (TRANSLATION){-0.7f * scalingScene6_1.x, 0.0f * scalingScene6_1.y, 0.0f};
        rathTranslationScene6_1 = (TRANSLATION){0.0f * scalingScene6_1.x, 0.0f * scalingScene6_1.y, 0.0f};
        break;

    case 1030:
        sceneTranslateLeft = FALSE;
        zoomInDraupadi = TRUE;
        scalingScene6_1 = (SCALING){1.0f, 1.0f, 1.0f};
        cameraTranslationScene6_1 = (TRANSLATION){0.0f * scalingScene6_1.x, 0.0f * scalingScene6_1.y, 0.0f};
        rathTranslationScene6_1 = (TRANSLATION){0.0f * scalingScene6_1.x, 0.0f * scalingScene6_1.y, 0.0f};
        break;

    default:
        break;
    }

    pointResize = scalingScene6_1.x;

    if (translateKrishna == TRUE)
    {
        callCount++;
        if (rathTranslationScene6_1.x >= 0.0f)
        {
            rathTranslationScene6_1.x -= (0.008f * scalingScene6_1.x);
        }
    }

    if (zoomOutKrishna == TRUE)
    {
        float startTime = 980.0f;
        float endTime = 1030.0f;
        float t = (float)(iTimeElapsed - startTime) / (endTime - startTime); // Normalized time [0,1]
        if (t > 1.0f)
            t = 1.0f;

        // Initial and target values
        float startScale = 4.0f;
        float targetScale = 1.0f;
        float startCamX = -0.7f * 4.0f; // From previous phase
        float targetCamX = 0.0f;
        float startCamY = 0.0f;
        float targetCamY = 0.0f;

        // Smoothstep interpolation for natural easing
        float smoothT = t * t * (3.0f - 2.0f * t); // Smoothstep formula

        scalingScene6_1.x = startScale + (targetScale - startScale) * smoothT;
        scalingScene6_1.y = scalingScene6_1.x; // Uniform scaling
        scalingScene6_1.z = scalingScene6_1.x;
        cameraTranslationScene6_1.x = startCamX + (targetCamX - startCamX) * smoothT;
        cameraTranslationScene6_1.y = startCamY + (targetCamY - startCamY) * smoothT;
        rathTranslationScene6_1.x = 0.0f;
    }

    if (zoomInDraupadi == TRUE)
    {
        float startTime = 1030.0f;
        float endTime = 1080.0f;                                             // Assuming zoom completes by 1080, adjust as needed
        float t = (float)(iTimeElapsed - startTime) / (endTime - startTime); // Normalized time [0,1]
        if (t > 1.0f)
            t = 1.0f;

        // Initial and target values
        float startScale = 1.0f;
        float targetScale = 4.0f;
        float startCamX = 0.0f;
        float targetCamX = 0.8f * 4.0f; // Adjusted to match target

        // Smoothstep interpolation
        float smoothT = t * t * (3.0f - 2.0f * t);

        scalingScene6_1.x = startScale + (targetScale - startScale) * smoothT;
        scalingScene6_1.y = scalingScene6_1.x;
        scalingScene6_1.z = scalingScene6_1.x;
        cameraTranslationScene6_1.x = startCamX + (targetCamX - startCamX) * smoothT;
        cameraTranslationScene6_1.y = 0.0f; // No vertical movement
        rathTranslationScene6_1.x = 0.0f;
    }

    fprintf(gpFile, "update scene 6_1: iTimeElapsed: %d :: callCount: %d", iTimeElapsed, callCount);
}

BOOL scene6_1ShouldTransition(BOOL iSceneSkipped)
{
    int iThresholdTime = 1060;
    if (iSceneSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 2 min 14 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 6_2 IMPLEMENTATION */
/*
At 106 - Krishna Close up look and zoom out
At 109 - Pandav and Draupadi Sitting
At 113 - Nakul and Sahadev close up
At 114 - Camera travels to Other 3 brothers
At 116 - Krishna close up
At 118 - Bheem Close up
At 119 - Krishna Face
At 120 - Yudhishteer Face
At 121 - Nakul and Sahadev close up
At 123 - Draupadi Zooming in till 130
At 130 - Slide oved Pandavas
At 132 - Krishna close up
At 133 - Full scene with Drapadi holding Thali till 136
/******************************/

void scene6_2Render()
{
    // set it to identity matrix
    glLoadIdentity();

    // translate triangle backwards by z
    glTranslatef(cameraTranslationScene6_2.x, cameraTranslationScene6_2.y, cameraTranslationScene6_2.z);
    glScalef(scalingScene6_2.x, scalingScene6_2.y, scalingScene6_2.z);

    drawRoom();

    sittingkrishna(0.5f, -0.35f, 0.3f);

    drawBheem(0.145f, 0.13f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_GESTURE);
    drawArjun(0.30f, -0.05f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_GESTURE, HIDE_BOW_ARROW);
    drawYudhishthir(0.42f, -0.20f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_FOLDED);

    drawSahadev(-0.25f, -0.05f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_FOLDED, HIDE_BOW_ARROW);
    drawNakul(-0.05f, -0.20f, 0.7f, CHARACTER_SITTING, CHARACTER_HAND_FOLDED);

    drawDraupadi(-0.2f, -0.35f, 0.7f, g_iHandPositionDraupadi, CHARACTER_STANDING);
    if (g_iHandPositionDraupadi == DRAUPADI_HAND_THALI)
        DrawPlateEP(-0.66f, -0.53f, 0.3f);
}

void scene6_2Update()
{
    static GLboolean translateRightPandav = FALSE;
    static GLboolean zoomIn1Draupadi = FALSE;
    static GLboolean zoomIn2Draupadi = FALSE;

    switch (iTimeElapsed)
    {
    case 1060:
    {
        g_iHandPositionDraupadi = DRAUPADI_HAND_FOLDED;
        scalingScene6_2 = (SCALING){6.0f, 6.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){-0.45f * scalingScene6_2.x, 0.26f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1075:
    {
        scalingScene6_2 = (SCALING){4.0f, 4.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){-0.45f * scalingScene6_2.x, 0.26f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1090:
    {
        scalingScene6_2 = (SCALING){2.0f, 2.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.45f * scalingScene6_2.x, 0.1f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1130:
    {
        scalingScene6_2 = (SCALING){5.0f, 5.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, 0.055f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1140:
    {
        scalingScene6_2 = (SCALING){3.0f, 3.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.30f * scalingScene6_2.x, -0.01f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1160:
    {
        scalingScene6_2 = (SCALING){5.0f, 5.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){-0.45f * scalingScene6_2.x, 0.26f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1180:
    {
        scalingScene6_2 = (SCALING){5.0f, 5.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.45f * scalingScene6_2.x, -0.2f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1190:
    {
        scalingScene6_2 = (SCALING){7.0f, 7.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){-0.40f * scalingScene6_2.x, 0.26f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1200:
    {
        scalingScene6_2 = (SCALING){7.0f, 7.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.028f * scalingScene6_2.x, 0.12f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1210:
    {
        scalingScene6_2 = (SCALING){5.2f, 5.2f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, 0.055f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1230:
    {
        scalingScene6_2 = (SCALING){1.5f, 1.5f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, 0.25f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1245:
    {
        zoomIn1Draupadi = TRUE;
        scalingScene6_2 = (SCALING){1.5f, 1.5f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, 0.25f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1250:
    {
        zoomIn1Draupadi = FALSE;
        scalingScene6_2 = (SCALING){2.5f, 2.5f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, 0.25f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1265:
    {
        zoomIn2Draupadi = TRUE;
        scalingScene6_2 = (SCALING){2.5f, 2.5f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, 0.25f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1270:
    {
        zoomIn2Draupadi = FALSE;
        scalingScene6_2 = (SCALING){3.5f, 3.5f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, 0.25f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1300:
    {
        scalingScene6_2 = (SCALING){4.0f, 4.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, -0.01f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1305:
    {
        translateRightPandav = TRUE;
        scalingScene6_2 = (SCALING){4.0f, 4.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, -0.01f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1310:
    {
        translateRightPandav = FALSE;
        scalingScene6_2 = (SCALING){4.0f, 4.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){0.2f * scalingScene6_2.x, -0.01f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1320:
    {
        scalingScene6_2 = (SCALING){7.0f, 7.0f, 0.0f};
        cameraTranslationScene6_2 = (TRANSLATION){-0.40f * scalingScene6_2.x, 0.26f * scalingScene6_2.y, 0.0f};
        break;
    }
    case 1330:
    case 1340:
        g_iHandPositionDraupadi = DRAUPADI_HAND_THALI;
        cameraTranslationScene6_2 = (TRANSLATION){0.0f, 0.0f, 0.0f};
        scalingScene6_2 = (SCALING){1.0f, 1.0f, 0.0f};
        break;

    default:
        break;
    }

    if (zoomIn1Draupadi == TRUE)
    {
        if (scalingScene6_2.x < 2.45f)
            scalingScene6_2.x += 0.05f;

        if (scalingScene6_2.y < 2.45f)
            scalingScene6_2.y += 0.05f;

        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, 0.25f * scalingScene6_2.y, 0.0f};
    }

    if (zoomIn2Draupadi == TRUE)
    {
        if (scalingScene6_2.x < 3.45f)
            scalingScene6_2.x += 0.05f;

        if (scalingScene6_2.y < 3.45f)
            scalingScene6_2.y += 0.05f;

        cameraTranslationScene6_2 = (TRANSLATION){0.7f * scalingScene6_2.x, 0.25f * scalingScene6_2.y, 0.0f};
    }
    if (translateRightPandav == TRUE)
    {
        float x = cameraTranslationScene6_2.x / scalingScene6_2.x;

        if (x > 0.2f)
            x = x - 0.005f;

        cameraTranslationScene6_2.x = x * scalingScene6_2.x;
    }
}

BOOL scene6_2ShouldTransition(BOOL iSceneSkipped)
{
    int iThresholdTime = 1340;
    // int iThresholdTime = 1620;

    if (iSceneSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 2 min 14 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 6_5 IMPLEMENTATION */
/*
 * At 162: show krishna face (zoomed in) for 2 secs
 * At 164: show pandavs face (zoomed in) for 4 secs translate towards left
 * At 168: show krishna face (zoomed in) again for 1 sec
 * At 169: show pandavs from left to right zooming out (for 6 secs)
 * At 175: translate towards right till krishna appears (for 5 secs)
 * At 180: start zooming in on krishna (for 10 secs)
 */
/******************************/
void renderScene6_5()
{
    void drawRoom(void);
    void drawNakul(float xOrigin, float yOrigin, float scale, int iStanding, int iHandPosition);
    void drawDraupadi(float xOriginDrau, float yOriginDrau, float scale, int iHandPosition, int iStanding);

    glLoadIdentity();

    // translate triangle backwards by z
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(scalingScene6_5.x, scalingScene6_5.y, scalingScene6_5.z);
    drawRoom();

    // set it to identity matrix
    glLoadIdentity();

    // translate
    glTranslatef(cameraTranslationScene6_5.x, cameraTranslationScene6_5.y, cameraTranslationScene6_5.z);
    glScalef(scalingScene6_5.x, scalingScene6_5.y, scalingScene6_5.z);
    // bheem
    drawBheem(-0.3f, 0.0f, 0.7f, 1, CHARACTER_HAND_FOLDED);
    // sahadev
    drawSahadev(-0.1f, 0.0f, 0.7f, 1, CHARACTER_HAND_FOLDED, HIDE_BOW_ARROW);
    // nakul
    drawNakul(0.1f, 0.0f, 0.7f, 1, CHARACTER_HAND_FOLDED);
    // arjun
    drawArjun(0.3f, 0.0f, 0.7f, 1, CHARACTER_HAND_FOLDED, HIDE_BOW_ARROW);
    // yushishtir
    drawNakul(0.5f, 0.0f, 0.7f, 1, CHARACTER_HAND_FOLDED);
    // draupadi
    drawDraupadi(0.7f, 0.0f, 0.7f, 1, 1);
    // krishna
    KrishnaStanding(0.7f, -0.15f, 0.40f);
}

void updateScene6_5()
{
    static GLboolean zoomOutPandav = FALSE;
    static GLboolean zoomInKrishna = FALSE;
    static GLboolean translateRight = FALSE;
    static GLboolean transtateLeft = FALSE;

    switch (iTimeElapsed)
    {
        // show krishna face (zoomed in) for 2 secs
    case 1620:
        scalingScene6_5 = (SCALING){5.0f, 5.0f, 5.0f};
        cameraTranslationScene6_5 = (TRANSLATION){-0.70 * scalingScene6_5.x, -0.1f * scalingScene6_5.y, 0.0f};
        break;

        // show pandavs
    case 1640:
        scalingScene6_5 = (SCALING){5.0f, 5.0f, 5.0f};
        cameraTranslationScene6_5 = (TRANSLATION){-0.2f * scalingScene6_5.x, -0.1f * scalingScene6_5.y, 0.0f};
        break;

        // show pandavs face (zoomed in) for 4 secs translate towards right to left
    case 1650:
        transtateLeft = TRUE;
        scalingScene6_5 = (SCALING){5.0f, 5.0f, 5.0f};
        cameraTranslationScene6_5 = (TRANSLATION){-0.2f * scalingScene6_5.x, -0.1f * scalingScene6_5.y, 0.0f};
        break;

        // show krishna face (zoomed in) again for 1 sec
    case 1690:
        transtateLeft = FALSE;
        scalingScene6_5 = (SCALING){5.0f, 5.0f, 5.0f};
        cameraTranslationScene6_5 = (TRANSLATION){-0.70f * scalingScene6_5.x, -0.1f * scalingScene6_5.y, 0.0f};
        break;

        // show pandavs from left to right zooming out (for 6 secs)
    case 1700:
        zoomOutPandav = TRUE;
        scalingScene6_5 = (SCALING){5.0f, 5.0f, 5.0f};
        cameraTranslationScene6_5 = (TRANSLATION){1.0f * scalingScene6_5.x, -0.1f * scalingScene6_5.y, 0.0f};
        break;

    case 1780:
        zoomOutPandav = FALSE;
        zoomInKrishna = TRUE;
        scalingScene6_5 = (SCALING){1.0f, 1.0f, 1.0f};
        cameraTranslationScene6_5 = (TRANSLATION){0.0f, 0.0f, 0.0f};
        break;

    default:
        break;
    }

    pointResize = scalingScene6_5.x;

    if (zoomOutPandav == TRUE)
    {
        if (cameraTranslationScene6_5.x >= (0.0f))
        {
            cameraTranslationScene6_5.x -= (0.002f * scalingScene6_5.x);
        }

        if (cameraTranslationScene6_5.y <= (0.0f))
        {
            cameraTranslationScene6_5.y += (0.0005f * scalingScene6_5.x);
        }

        if (scalingScene6_5.x >= 1.0f)
        {
            scalingScene6_5.x -= 0.0015;
            scalingScene6_5.y -= 0.0015;
            scalingScene6_5.z -= 0.0015;
        }
    }

    if (transtateLeft == TRUE)
    {
        if (cameraTranslationScene6_5.x <= (1.0f * scalingScene6_5.x))
        {
            cameraTranslationScene6_5.x += (0.003f * scalingScene6_5.x);
        }
    }

    if (zoomInKrishna == TRUE)
    {
        if (cameraTranslationScene6_5.x >= (-0.7f * scalingScene6_5.x))
        {
            cameraTranslationScene6_5.x -= (0.002f * scalingScene6_5.x);
        }

        if (cameraTranslationScene6_5.y >= (-0.1f * scalingScene6_5.y))
        {
            cameraTranslationScene6_5.y -= (0.0005f * scalingScene6_5.y);
        }

        if (scalingScene6_5.x <= 7.0f)
        {
            scalingScene6_5.x += 0.005;
            scalingScene6_5.y += 0.005;
            scalingScene6_5.z += 0.005;
        }
    }
}

BOOL shouldTransitionScene6_5(BOOL iSceneSkipped)
{
    int iThresholdTime = 1870;
    if (iSceneSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 7 IMPLEMENTATION */
/******************************/
void scene7Render(void)
{
    glLoadIdentity();
    drawRoom();
    glScalef(scaleSlogan, scaleSlogan, scaleSlogan);
    drawText(0.2, 0, 1, 255, 255, 0);
}

void scene7Update(void)
{
    if (scaleSlogan <= 0.9f)
    {
        scaleSlogan = scaleSlogan + 0.008f;
    }

    // Check time-based triggers
    switch (iTimeElapsed)
    {
    case 1870:
        break;
    default:
        break;
    }
}

BOOL scene7ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 2080;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 2 min 14 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* OUTRO IMPLEMENTATION */
/******************************/
BOOL bShowMemberNames = FALSE;
BOOL bShowSandeshReference = FALSE;
// BOOL bShowRasterGroupLeader = FALSE;

void outroRender(void)
{
    glLoadIdentity();
    glScalef(1.0f, 1.0f, 1.0f);

    if (bShowMemberNames)
    {
        drawMemberNames();
    }

    // if (bShowSandeshReference)
    // {
    //     drawSandeshReference();
    // }

    // if (bShowRasterGroupLeader)
    // {
    //     drawRasterGroupLeader();
    // }
}

void outroUpdate(void)
{

    switch (iTimeElapsed)
    {
    case 2080:
        bShowMemberNames = TRUE;
        break;
    case 3200:
        bShowMemberNames = TRUE; // FALSE
        break;
    }
}

BOOL outroShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 3500; // Increased to allow more time for credits
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after credits finish
    return (iTimeElapsed >= iThresholdTime);
}