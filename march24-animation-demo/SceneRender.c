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
#include "../common/props/SandeshText.c"
#include "../common/props/Sahadev.c"
#include "../common/props/nikhilsSandeshtxt.c"
#include "Scene6_2Render.h"
#include "../common/props/krishnastanding.c"
#include "../common/props/flowers.c"



/*******************************/ 

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
void scene1Render(void);
void scene1Update(void);
BOOL scene1ShouldTransition(BOOL iSkipped);
void scene2Render(void);
void scene2Update(void);
BOOL scene2ShouldTransition(BOOL iSkipped);
void scene3Render(void);
void scene3Update(void);
BOOL scene3ShouldTransition(BOOL iSkipped);
void scene5Render(void);
void scene5Update(void);
BOOL scene5ShouldTransition(BOOL iSkipped);
void scene6_2Render(void);
void scene6_2Update(void);
BOOL scene6_2ShouldTransition(BOOL iSkipped);

/*******************************/
/* SCENE MANAGEMENT VARIABLES */
/******************************/

// Scene management variables
Scene scene0 = {scene0Render, scene0Update, scene0ShouldTransition, NULL};
Scene scene1 = {scene1Render, scene1Update, scene1ShouldTransition, NULL};
Scene scene2 = {scene2Render, scene2Update, scene2ShouldTransition, NULL};
Scene scene3 = {scene3Render, scene3Update, scene3ShouldTransition, NULL};
Scene scene5;
Scene scene6_2 = {scene6_2Render, scene6_2Update, scene6_2ShouldTransition, NULL};
Scene scene6_5;

// External global variables from Raster.c
extern FILE *gpFile;
extern UINT iTimeElapsed;

TRANSLATION rathTranslation;
TRANSLATION cameraTranslationScene6_5;
SCALING scalingScene6_5;

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
    scene6_5 = (Scene){
        renderScene6_5,
        updateScene6_5,
        shouldTransitionScene6_5,
        NULL};

    scene0.nextScene = &scene1;
    scene1.nextScene = &scene2;
    scene2.nextScene = &scene3;
    scene3.nextScene = &scene5;
    scene5.nextScene = &scene6_2;
    scene6_2.nextScene = NULL;// End of chain
    currentScene = &scene2;   // Start with scene 1
    scene6_2.nextScene = &scene6_5;
    scene6_5.nextScene = NULL; // End of chain
    currentScene = &scene0;    // Start with scene 1

    cameraTranslationScene6_5 = (TRANSLATION){0.0f, 0.0f, 0.0f};
    scalingScene6_5 = (SCALING){1.0f, 1.0f, 1.0f};
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
/* SCENE 1 IMPLEMENTATION */
/******************************/
void scene1Render(void)
{
    drawGround();
    // drawDenseForrest();
    // drawFrontTrees();
    elephant();
    drawButterfly(butterflyX, butterflyY, 0.6f, butterflyRotation);
    toungeMovement();
    //chamelon(1.5f, -0.35f, 0.2);
    
    updateSandesh(bCallSandesh, 1.0f);
}

void scene1Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed) {
        case 30:
            bCallTounge = TRUE;
            break;
        case 40:
            bCallButterfly = TRUE;
            bCallElephant = TRUE;
            break;
        case 100:
            bCallSandesh = TRUE;  // Hide Sandesh message before scene transition
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
    int iThresholdTime = 150;
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
     drawGround();
    // Add scene 2 specific rendering
}

void scene2Update(void)
{
    // Update scene 2 elements
}

BOOL scene2ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 460;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if(flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);


/*******************************/ 
/* SCENE 2 IMPLEMENTATION */
/******************************/

void scene2Render(void)
{
    // Define phase durations (in seconds).
    const float zoomOutDuration = 5.0f;   // Phase 0: Zoom out from top right.
    const float waitAfterZoomOut = 6.0;  // Phase 1: Wait after zoom out.
    const float zoomInDuration = 4.0f;   // Phase 2: Zoom in centered.
    const float waitAfterZoomIn = 4.0f;   // Phase 3: Wait after zoom in.
    const float leftMoveZoomDuration = 3.0f;   // Phase 4: While moving left, zoom out over this duration.

    // Zoom factors.
    const float zoomInFactor = 5.0f;  // Fully zoomed in.
    const float zoomOutFactor = 1.1f;  // Zoomed out state.

    // Speed for camera left movement.
    const float cameraSpeed = 0.01f; // Units per second.

    // Phase definitions:
    // Phase 0: Zoom out from top right.
    // Phase 1: Wait after zoom out.
    // Phase 2: Zoom in centered.
    // Phase 3: Wait after zoom in.
    // Phase 4: Move camera to the left while zooming out.
    static int phase = 0;
    static clock_t phaseStartTime = 0;
    static float cameraOffset = 0.0f; // Accumulated offset for leftward camera movement.

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
        // Phase 4: Move camera to the left 
        if (elapsed < leftMoveZoomDuration)
        {
            currentZoom = zoomInFactor - (zoomInFactor - zoomOutFactor) * (elapsed / leftMoveZoomDuration);
        }
        else
        {
            currentZoom = zoomOutFactor;
        }
        cameraOffset = cameraSpeed * elapsed;
    }

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
        // For Phases 2, 3, and 4
        glTranslatef(0.3f, -0.4f, 0.0f);
        glScalef(currentZoom, currentZoom, 1.0f);
        glTranslatef(-0.3f, 0.4f, 0.0f);
        if (phase == 4)
        {
            // To simulate the camera moving left, translate the scene to the right.
            glTranslatef(cameraOffset, 0.0f, 0.0f);
        }
    }

    // Draw scene elements.
    drawGround();
    drawDraupadi(0.5, -0.3, 0.5, 1, 1);
    drawBheem(0.3, -0.3, 0.5, 1);
    drawArjun(0.1, -0.3, 0.5, 1);
    drawNakul(-0.1, -0.3, 0.5, 1);
    drawSahadev(-0.3, -0.3, 0.5, 1);
    drawDenseForrest();
    drawFrontTrees();
}





void scene2Update(void)
{
    

    // Update scene 2 elements
    updateDenseForrest();
    updateFrontForrest();

}

BOOL scene2ShouldTransition(BOOL iSkipped)
{
    // 20 Sec is Temporarily set for testing
    int iThresholdTime = 460;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return (iTimeElapsed >= iThresholdTime);

}

void scene3Render(void)
{
    // Draw scene 3 elements
    // Add scene 3 specific rendering
}

void scene3Update(void)
{
    // Update scene 3 elements
}

BOOL scene3ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 720;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 2 min 14 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 5 IMPLEMENTATION */
/******************************/

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
        drawDenseForrest();
    }
    if (bShriKrishnaEntry = TRUE && bShowLake == TRUE && bShowCranes == TRUE)
    {
        // lake and cranes
        drawGround();
        drawDenseForrest();

        drawCraneOne(0.4f, -0.2f, 0.9f);
        drawCraneTwo(0.8f, 0.0f, 0.9f);

        // Shri-Krishna
        KrishnaRath(-0.8f, -0.3f, 0.50f);
        // Rath
        MY_POINT startPosition = {0.2f, -0.5f, 0.8f};
        SCALING scaleBy = {1.3f, 1.3f, 1.3f};
        rath(startPosition, rathTranslation, scaleBy);
        drawHorse(-0.3f, -0.5f, 0.8f);
        drawFrontTrees();
    }

    if (bShowFlowers == TRUE)
    {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glScalef(0.2f, 0.2f, 0.0f);
        drawCurve();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glScalef(1.0f, 1.0f, 1.0f);
    }
    if (bShowPatternedDeers == TRUE)
    {
        drawGround();
        drawDenseForrest();
        drawRightPatternedDeer(0.0f, 0.0f, 0.5f);
        drawLeftPatternedDeer(-0.4f, 0.0f, 0.5f);
    }
    if (bShowPeacock == TRUE)
    {
        drawGround();
        drawDenseForrest();
        drawPeacock(0.0f, 0.0f, 0.8f);
    }
}

void scene5Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed)
    {
        case 730:
            bShowRotatingPlants = TRUE;
            break;
        case 760:
            bShowRotatingPlants = FALSE;
            bShriKrishnaEntry = TRUE;
            bShowLake = TRUE;
            bShowCranes = TRUE;
            break;
        case 840:
            bShriKrishnaEntry = FALSE;
            bShowLake = FALSE;
            bShowCranes = FALSE;
            bShowPatternedDeers = TRUE;
            break;
        case 870:
            bShowPatternedDeers = FALSE;
            bShowFlowers = TRUE;
            break;
        case 890:
            bShowFlowers = FALSE;
            bShowPeacock = TRUE;
            break;
        case 900:
            bShowPeacock = FALSE;
            break;
    }
    // Update specific elements
    if (bShowRotatingPlants == TRUE)
    {
        // rotate plants
    }
    if (bShriKrishnaEntry == TRUE)
    {
        // call traslation related function for moving Rath
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
/* SCENE 6_2 IMPLEMENTATION */
/******************************/

void scene6_2Render()
{

    drawRoom();

    sittingkrishna(originxSK, originySK, resizeSK);

    drawArjun(xOriginArjun, yOriginArjun, fScaleFactorArjun, g_iArjunStanding, g_iHandPositionArjun, HIDE_BOW_ARROW);
    drawBheem(xOriginBheem, yOriginBheem, fScaleFactorBheem, g_iBheemStanding, g_iHandPositionBheem);
    // drawYudhishteer(xOriginYudhishteer, yOriginYudhishteer, fScaleFactorYudhishteer, g_iYudhishteerStanding, g_iHandPositionYudhishteer);

    drawSahadev(xOriginSahadev, yOriginSahadev, fScaleFactorSahadev, g_iSahadevStanding, g_iHandPositionSahadev, HIDE_BOW_ARROW);
    drawNakul(xOriginNakul, yOriginNakul, fScaleFactorNakul, g_iNakulStanding, g_iHandPositionNakul);

    drawDraupadi(xOriginDraupadi, yOriginDraupadi, 0.8f, g_iHandPositionDraupadi, g_iStandingDraupadi);
}

void scene6_2Update()
{
    g_iHandPositionDraupadi = DRAUPADI_HAND_FOLDED;
    g_iStandingDraupadi = CHARACTER_STANDING;

    g_iYudhishteerStanding = g_iBheemStanding = g_iArjunStanding = g_iNakulStanding = g_iSahadevStanding = CHARACTER_SITTING;

    g_iHandPositionYudhishteer = g_iHandPositionBheem = g_iHandPositionArjun = CHARACTER_HAND_GESTURE;
    g_iHandPositionNakul = g_iHandPositionSahadev = CHARACTER_HAND_FOLDED;

    fScaleFactorYudhishteer = fScaleFactorBheem = fScaleFactorArjun = fScaleFactorNakul = fScaleFactorSahadev = 0.7f;

    xOriginArjun = 0.05;
    yOriginArjun = 0.1;
    xOriginBheem = 0.2;
    yOriginBheem = 0.0;
    xOriginYudhishteer = 0.4;
    yOriginYudhishteer = -0.2;

    xOriginSahadev = -0.3;
    yOriginSahadev = 0.0;
    xOriginNakul = -0.1;
    yOriginNakul = -0.2;

    xOriginDraupadi = -0.2;
    yOriginDraupadi = -0.3;

    originxSK = 0.5f;
    originySK = -0.3f;
    resizeSK = 0.3f;

    switch (iTimeElapsed)
    {
    case 1060:
        // bMoveDraupadi = TRUE;
        break;
    case 1120:
        bMoveDraupadi = FALSE;
        break;
    default:
        break;
    }

    if (bMoveDraupadi)
    {
        if (xOriginDraupadi >= 0.0)
            xOriginDraupadi += 0.001;
        else
            xOriginDraupadi -= 0.01;
    }
}

BOOL scene6_2ShouldTransition(BOOL iSceneSkipped)
{
    int iThresholdTime = 1620;
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
    // void KrishnaStanding(float originx, float originy, float resize);

    glLoadIdentity();

    // translate triangle backwards by z
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(scalingScene6_5.x, scalingScene6_5.y, scalingScene6_5.z);
    drawRoom();

    // set it to identity matrix
    glLoadIdentity();

    // translate triangle backwards by z
    glTranslatef(cameraTranslationScene6_5.x, cameraTranslationScene6_5.y, cameraTranslationScene6_5.z);
    glScalef(scalingScene6_5.x, scalingScene6_5.y, scalingScene6_5.z);
    // bheem
    drawNakul(-0.3f, 0.0f, 0.7f, 1, 1);
    // sahadev
    drawNakul(-0.1f, 0.0f, 0.7f, 1, 1);
    // nakul
    drawNakul(0.1f, 0.0f, 0.7f, 1, 1);
    // arjun
    drawNakul(0.3f, 0.0f, 0.7f, 1, 1);
    // yushishtir
    drawNakul(0.5f, 0.0f, 0.7f, 1, 1);
    // draupadi
    drawDraupadi(0.7f, 0.0f, 0.7f, 1, 1);
    // krishna
    drawNakul(1.2f, 0.0f, 0.7f, 1, 1);
    // KrishnaStanding(0.5f, 0.0f, 1.0f);
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
        cameraTranslationScene6_5 = (TRANSLATION){-0.70 * scalingScene6_5.x, -0.1f, 0.0f};
        break;

        // show pandavs
    case 1640:
        scalingScene6_5 = (SCALING){5.0f, 5.0f, 5.0f};
        cameraTranslationScene6_5 = (TRANSLATION){-0.2f * scalingScene6_5.x, -0.1f, 0.0f};
        break;

        // show pandavs face (zoomed in) for 4 secs translate towards right to left
    case 1650:
        transtateLeft = TRUE;
        scalingScene6_5 = (SCALING){5.0f, 5.0f, 5.0f};
        cameraTranslationScene6_5 = (TRANSLATION){-0.2f * scalingScene6_5.x, -0.1f, 0.0f};
        break;

        // show krishna face (zoomed in) again for 1 sec
    case 1690:
        transtateLeft = FALSE;
        scalingScene6_5 = (SCALING){5.0f, 5.0f, 5.0f};
        cameraTranslationScene6_5 = (TRANSLATION){-0.70f * scalingScene6_5.x, -0.1f, 0.0f};
        break;

        // show pandavs from left to right zooming out (for 6 secs)
    case 1700:
        zoomOutPandav = TRUE;
        scalingScene6_5 = (SCALING){5.0f, 5.0f, 5.0f};
        cameraTranslationScene6_5 = (TRANSLATION){1.0f * scalingScene6_5.x, 0.0f, 0.0f};
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

    if (zoomOutPandav == TRUE)
    {
        if (cameraTranslationScene6_5.x >= (0.0f))
        {
            cameraTranslationScene6_5.x -= (0.0005f * scalingScene6_5.x);
        }

        if (scalingScene6_5.x >= 1.0f)
        {
            scalingScene6_5.x -= 0.001;
            scalingScene6_5.y -= 0.001;
            scalingScene6_5.z -= 0.001;
        }
    }

    if (transtateLeft == TRUE)
    {
        if (cameraTranslationScene6_5.x <= (1.0f * scalingScene6_5.x))
        {
            cameraTranslationScene6_5.x += (0.0004f * scalingScene6_5.x);
        }
    }

    if (zoomInKrishna == TRUE)
    {
        if (cameraTranslationScene6_5.x >= (-0.7f * scalingScene6_5.x))
        {
            cameraTranslationScene6_5.x -= (0.0003f * scalingScene6_5.x);
        }

        if (cameraTranslationScene6_5.y >= (-0.1f * scalingScene6_5.y))
        {
            cameraTranslationScene6_5.y -= (0.0001f * scalingScene6_5.y);
        }

        if (scalingScene6_5.x <= 7.0f)
        {
            scalingScene6_5.x += 0.001;
            scalingScene6_5.y += 0.001;
            scalingScene6_5.z += 0.001;
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
    return TRUE;
}
