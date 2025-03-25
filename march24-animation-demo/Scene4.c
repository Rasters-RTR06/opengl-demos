void sceneFourRender();
void sceneFourUpdate(UINT elapsedTime);
void drawPlateScene4(float startX, float startY);

float arjunOriginX = -0.15f;
float arjunOriginY = -0.3f;

float bheemOriginX = 0.19f;
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

float scalePlate = 0.14f;
float scaleScene = 1.0f;
float sceneOriginX = 0.0f;
float sceneOriginY = 0.0f;

BOOL draupadiGoingBack = FALSE;

void sceneFourRender()
{
     drawPlate();
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glTranslatef(sceneOriginX, sceneOriginY, 0.0f);
     glScalef(scaleScene, scaleScene, 0.0f);
     
     drawRoom();

     drawArjun(arjunOriginX, arjunOriginY, 0.7f, 0, 0, 0);
     drawPlateScene4(-0.7, -0.78);

     drawBheem(bheemOriginX, bheemOriginY, 0.7f, 0, 0);
     drawPlateScene4(-0.39, -0.49);

     glRotatef(180, 0.0f, 1.0f, 0.0f);
     drawYudhishthir(yudhishteerOriginX + 0.15f, yudhishteerOriginY, 0.7f, 0, 0);
     glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
     drawPlateScene4(-0.05, -0.35);

     drawSahadev(sahadevOriginX, sahadevOriginY, 0.7f, 0,  0, 0);
     drawPlateScene4(0.3, -0.35);

     glRotatef(180, 0.0f, 1.0f, 0.0f);
     drawNakul(nakulOriginX - 1.3f, nakulOriginY, 0.7f, 0, 0);
     glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
     drawPlateScene4(0.7, -0.45);

     if(draupadiGoingBack)
     {
          glRotatef(180, 0.0f, 1.0f, 0.0f);
          drawDraupadi(draupadiOriginX, draupadiOriginY, 0.7f, 2, 1);
          glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
          // glScalef(0.8f, 0.8f, 0.0f);
          // DrawPlateEP(draupadiOriginX - 0.5f, draupadiOriginY + 0.1f, 0.5f);
          // glScalef(1.0f / 0.8f, 1.0f / 0.8f, 0.0f);
     }
     else 
     {
          // glScalef(0.8f, 0.8f, 0.0f);
          // DrawPlateEP(draupadiOriginX - 0.6f, draupadiOriginY - 0.3f, 0.5f);
          // glScalef(1.0f / 0.8f, 1.0f / 0.8f, 0.0f);
          drawDraupadi(draupadiOriginX, draupadiOriginY, 0.7f, 2, 1);
     }
     
     glLoadIdentity();
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
         if (draupadiOriginX <= 0.95f)
          draupadiOriginX += 0.002f;
     }

     //   [FOCUS ON PANDAV]
     else if (elapsedTime == 76)
     {
          //scaleScene += 0.5f;
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
         //draupadiGoingBack = TRUE;
          //scaleScene += 0.4f;
          sceneOriginX = -0.1f;
          sceneOriginY = 0.25f;
     }
     
     //   [FOCUS ON PANDAV]
     else if (elapsedTime == 116)
     {
          sceneOriginX = -0.3f;
          sceneOriginY = -0.2f;
     }
     else if (elapsedTime == 120)
     {
         
     }

     //   [SCALE BACK]
     else if(elapsedTime == 126)
     {
          //draupadiGoingBack = TRUE;
          sceneOriginX = -0.5f;
          sceneOriginY = 0.2f;
          //scaleScene = 1.2f;
     }

     //   [MOVE DROUPADI BACKWARD]
     //else if (elapsedTime >= 126 && elapsedTime <= 156)
     //{
     //     draupadiOriginX += 0.001f;
     //}
     //else if (elapsedTime >= 156)
     //{
     //     draupadiOriginX += 0.001f;
     //     //sceneOriginX += 0.001f;
     //}
}

void drawPlateScene4(float startX, float startY)
{     
     glTranslatef(startX, startY, 0.0f);
     glScalef(scalePlate, scalePlate, 0.0f);
     drawPlate();
     glScalef(1.0f / scalePlate, 1.0f / scalePlate, 0.0f);
     glTranslatef(-startX, -startY, 0.0f);
}