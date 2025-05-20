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

extern FILE *gpFile = NULL; // File pointer for logging
Scene *currentScene = NULL; // Current scene in the chain

// Scene management functions declarations
void initScenes(void);
void updateCurrentScene(UINT iTimeElapsed);
void renderCurrentScene(void);
void logSceneTransition(UINT iTimeElapsed);

/*******************************/
/* SCENE MANAGEMENT FUNCTIONS */
/******************************/

// Initialize the scene chain
void initScenes(void)
{
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
