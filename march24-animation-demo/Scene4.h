void sceneFourRender();
void sceneFourUpdate(UINT elapsedTime);

float arjunOriginX = -0.15f;
float arjunOriginY = -0.3f;

float bheemOriginX = 0.15f;
float bheemOriginY = -0.1f;

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


void sceneFourRender()
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glScalef(scaleScene, scaleScene, 0.0f);

     glTranslatef(sceneOriginX, sceneOriginY, 0.0f);

     drawRoom();
     drawArjun(arjunOriginX, arjunOriginY, 0.7f, 0);
     drawBheem(bheemOriginX, bheemOriginY, 0.7f, 0);
     drawSahadev(yudhishteerOriginX, yudhishteerOriginY, 0.7f, 0);
     drawSahadev(sahadevOriginX, sahadevOriginY, 0.7f, 0);
     drawNakul(nakulOriginX, nakulOriginY, 0.7f, 0);
     drawDraupadi(draupadiOriginX, draupadiOriginY, 0.7f, 2, 1);

     glLoadIdentity();
     glScalef(0.0f, 0.0f, 0.0f);
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
     else if (elapsedTime >= 76 && elapsedTime <= 85)
     {
          sceneOriginX += 0.005f;
          sceneOriginY -= 0.0005f;
     }

     //   [FOCUS ON PLATES]
     else if (elapsedTime >= 85 && elapsedTime <= 90)
     {
          sceneOriginY += 0.015f;
     }

     //   [MOVE DROUPADI BACKWARD]
     // else if (elapsedTime >= 115 && elapsedTime <= 150)
     // {
     //      draupadiOriginX -= 0.002f;
     //      sceneOriginX += 0.002f;
     // }
     // else if (elapsedTime >= 150 && elapsedTime <= 200)
     // {
     //      draupadiOriginX -= 0.002f;
     // }
}