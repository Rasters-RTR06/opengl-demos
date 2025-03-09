extern float fToungeStretch = 0;
extern float fToungeDirection = -1.0f;
extern BOOL bToungeAnimationComplete = FALSE;

void toungeMovement(void)
{
    // Only render if animation is not complete
    if (!bToungeAnimationComplete) {
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_TRIANGLE_STRIP);
        for (float x = 0.0f; x >= fToungeStretch; x-=0.01f)
        {
            float y = (cos(fToungeStretch * log(-0.75f*x))/8.5f);
            glVertex2f(x+1.0f, y-0.1f);
            glVertex2f(x+1.0f, (y-0.05f)-0.1f);
        }
        glEnd();
    }
}

void updateTounge(void)
{
    // Skip update if animation is already complete
    if (bToungeAnimationComplete) {
        return;
    }

    // Update tongue position
    fToungeStretch += 0.03f * fToungeDirection;

    // Check boundaries
    if (fToungeStretch >= 1.4f) {
        fToungeStretch = 1.4f;
        fToungeDirection = -1.0f; // Change direction to retract
    } else if (fToungeStretch <= -1.4f) {
        fToungeStretch = -1.4f;
        fToungeDirection = 1.0f;
        

        //bToungeAnimationComplete = TRUE;
        
       
    }
    // Animation has completed one full cycle (extend and retract)
    if(fToungeStretch >= 0.79f && fToungeStretch <= 0.81f)
    {
        bToungeAnimationComplete = TRUE;
         // Optional: Log completion to file
        extern FILE* gpFile;
        if (gpFile) {
            fprintf(gpFile, "Tongue animation completed one cycle\n");
        }
    }
}

