# SANDESH DEMO [for 24 MARCH 2025]

!!! MUST READ !!!

[ USING AI TO WRITE THE FOLLOWING TEXT TO AVOID ANY MISCOMMUNICATION ]
### Quick URL's
### Quick URLs

*   Spreadsheet: [https://docs.google.com/spreadsheets/d/1EOz-s97FK4etPZI86mG54PqIOzZLotIQroWeTNsb\_DM/edit?usp=sharing](https://docs.google.com/spreadsheets/d/1EOz-s97FK4etPZI86mG54PqIOzZLotIQroWeTNsb_DM/edit?usp=sharing)
*   Original SANDESH Video: [https://www.youtube.com/watch?v=sLHsg2lMgm4](https://www.youtube.com/watch?v=sLHsg2lMgm4)
*   Planned Edit: (Refer to spreadsheet)


### How Scene Works Explained
**Scene Rendering**
Raster.c

 1. **`Raster.c`** is the entry point of the application. It initializes OpenGL, creates a window, and starts the game loop that we working with.
 
2.  **`display` (Raster.c):** Inside the main loop, the `display` function is called. This function clears the OpenGL buffers and then calls `renderCurrentScene()`.
3.  **`renderCurrentScene` (SceneRender.c):** This function checks if a `currentScene` is set. If so, it calls the `render()` function associated with the current scene (e.g., `scene1Render()`).
4.  **`scene1Render` (SceneRender.c):** The `scene1Render` function (or the render function of any other active scene) contains the specific OpenGL drawing calls to render the elements of that scene (ground, elephant, chameleon, etc.).

**Chain of Responsibility**

The Chain of Responsibility pattern is implemented using the `Scene` struct and the `nextScene` pointer.

*   **`Scene` struct:** Each scene is represented by a `Scene` struct, which contains function pointers for `render`, `update`, and `shouldTransition`, as well as a pointer to the next scene (`nextScene`).
*   **`nextScene` pointer:** The `nextScene` pointer in each `Scene` struct allows you to chain scenes together. For example, `scene1.nextScene` points to `scene2`.
*   **`currentScene` variable:** The `currentScene` variable in 

SceneRender.c

 keeps track of the currently active scene.
*   **`initScenes` (SceneRender.c):** This function sets up the chain by linking the scenes together.
*   **`updateCurrentScene` (SceneRender.c):** This function checks if the current scene should transition to the next scene using the `shouldTransition` function. If `shouldTransition` returns `TRUE`, the `currentScene` pointer is updated to point to the next scene in the chain.
*   **`updateCurrentScene` (SceneRender.c):** Also Updates Positions, and values of assets used in our Scene1Render. we pass it `iTimeElapsed` to keep our demo relative to time. 
1 SECOND = 1000 MS. (5s=5000ms, 140s = 140000ms and so on...)

### Scene Skipping (Raster.c)

*   **'S' Key Press:** In the `WndProc` function within 

Raster.c

, the `WM_CHAR` message is handled. When the user presses the 'S' or 's' key, the code checks if a scene transition should be forced.
*   **`currentScene` Check:** It verifies that `currentScene` is not `NULL` and that the `shouldTransition` function and `nextScene` pointer of the current scene are also valid.
*   **Forced Transition:** If all checks pass, `currentScene->shouldTransition(TRUE)` is called. The `TRUE` argument indicates that the transition is being skipped/forced.
*   **Scene Update:** If `shouldTransition` returns `TRUE`, the `currentScene` is updated to `currentScene->nextScene`, effectively skipping to the next scene.

**`shouldTransition` Function (SceneRender.c)**

*   **Purpose:** The `shouldTransition` function (e.g., `scene1ShouldTransition`, `scene2ShouldTransition`) determines whether a scene should transition to the next scene in the chain.
*   **Time-Based Transition:** The primary mechanism for transition is based on `iTimeElapsed`. Each scene has a `iThresholdTime`. If `iTimeElapsed` is greater than or equal to `iThresholdTime`, the function returns `TRUE`, indicating that a transition should occur.
*   **Skipped Parameter:** The `iSkipped` parameter allows the function to behave differently when a scene skip is requested. If `iSkipped` is `TRUE`, the `iTimeElapsed` is reset and incremented by `iThresholdTime` to force the transition.
*   **Return Value:** The function returns `TRUE` if a transition should occur, and `FALSE` otherwise.
