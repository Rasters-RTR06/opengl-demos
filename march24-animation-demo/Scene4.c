void sceneFourRender();
void sceneFourUpdate(UINT elapsedTime);

float arjunOriginX = -0.15f;
float arjunOriginY = -0.3f;

float bheemOriginX = 0.15f;
float bheemOriginY = 0.0f;

float yudhishteerOriginX = 0.45f;
float yudhishteerOriginY = 0.1f;

float sahadevOriginX = 0.8f;
float sahadevOriginY = 0.1f;

float nakulOriginX = 1.15f;
float nakulOriginY = 0.0f;

float draupadiOriginX = -0.15f;
float draupadiOriginY = -0.3f;

float plateOriginX = 0.0f;
float plateOriginY = 0.0f;

float scaleScene = 1.0f;
float sceneOriginX = 0.0f;
float sceneOriginY = 0.0f;

BOOL draupadiGoingBack = FALSE;

void sceneFourRender()
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glScalef(scaleScene, scaleScene, 0.0f);

     glTranslatef(sceneOriginX, sceneOriginY, 0.0f);

     drawRoom();
     drawArjun(arjunOriginX, arjunOriginY, 0.7f, 0, 0, 0);

     drawBheem(bheemOriginX, bheemOriginY, 0.7f, 0, 0);

     glRotatef(180, 0.0f, 1.0f, 0.0f);
     drawSahadev(yudhishteerOriginX + 0.15f, yudhishteerOriginY, 0.7f, 0, 0, 0);
     glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);

     drawSahadev(sahadevOriginX, sahadevOriginY, 0.7f, 0,  0, 0);

     glRotatef(180, 0.0f, 1.0f, 0.0f);
     drawNakul(nakulOriginX - 1.3f, nakulOriginY, 0.7f, 0, 0);
     glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);

     if(draupadiGoingBack)
     {
          glRotatef(180, 0.0f, 1.0f, 0.0f);
          drawDraupadi(draupadiOriginX, draupadiOriginY, 0.7f, 2, 1);
          glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
     }
     else 
          drawDraupadi(draupadiOriginX, draupadiOriginY, 0.7f, 2, 1);
}

void sceneFourUpdate(UINT elapsedTime)
{
     //   [ZOOM IN]
     if(elapsedTime <= 15) 
     {
          scaleScene += 0.005f;
          sceneOriginX += 0.002f;
          sceneOriginY += 0.002f;
     }

     //   [MOVE DROUPADI FORWARD]
     else if (elapsedTime >= 15 && elapsedTime <= 50)
     {
          draupadiOriginX += 0.002f;
          sceneOriginX -= 0.002f;
     }
     else if (elapsedTime >= 50 && elapsedTime <= 75)
     {
          draupadiOriginX += 0.002f;
     }

     //   [FOCUS ON PANDAV]
     else if (elapsedTime == 76)
     {
          scaleScene += 0.5f;
          sceneOriginX -= 0.05f;
          sceneOriginY -= 0.05f;
     }
     else if (elapsedTime >= 80 && elapsedTime <= 90)
     {
          sceneOriginX += 0.004f;
          sceneOriginY -= 0.0005f;
     }

     //   [FOCUS ON PLATES]
     else if (elapsedTime >= 90 && elapsedTime <= 95)
     {
          sceneOriginY += 0.015f;
     }
     else if (elapsedTime >= 95 && elapsedTime <= 105)
     {
          sceneOriginY += 0.0017f;
          sceneOriginX -= 0.0049f;
     }

     //   [FOCUS ON DROUPADI]
     else if (elapsedTime == 106)
     {
          scaleScene += 0.4f;
          sceneOriginX = -0.1f;
          sceneOriginY = 0.25f;
     }
     
     //   [FOCUS ON PANDAV]
     else if (elapsedTime == 116)
     {
          sceneOriginX = -0.3f;
          sceneOriginY = -0.2f;
     }

     //   [SCALE BACK]
     else if(elapsedTime == 126)
     {
          draupadiGoingBack = TRUE;
          sceneOriginX = -0.1f;
          sceneOriginY = 0.0f;
          scaleScene = 1.2f;
     }

     //   [MOVE DROUPADI BACKWARD]
     else if (elapsedTime >= 126 && elapsedTime <= 156)
     {
          draupadiOriginX += 0.001f;
     }
     else if (elapsedTime >= 156)
     {
          draupadiOriginX += 0.001f;
          sceneOriginX += 0.001f;
     }
}