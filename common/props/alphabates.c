void drawWord(char* word, float height, MY_POINT start, COLOR color, float thickness, float spacing)
{
    float currentCharStartX = start.x;
    float currentCharStartY = start.y;

    int i = 0;
    while (word[i] != '\0')
    {
        if (i != 0)
        {
            currentCharStartX += getCharacterWidth(word[i - 1], height);
            currentCharStartX += spacing;
        }

        if (currentCharStartX + getCharacterWidth(word[i], height) >= 1.0f)
        {
            currentCharStartX = -1.0f + spacing;
            currentCharStartY -= height;
            currentCharStartY -= spacing;
        }
        if ((currentCharStartY - height) <= -1.0f)
            break;

        start.x = currentCharStartX;
        start.y = currentCharStartY;
        drawCharacter(word[i], height, start, color, thickness);
        i++;
    }
}

float getCharacterWidth(char character, float height)
{
    switch (character) {
    case 'A': case 'a':
    case 'B': case 'b':
    case 'C': case 'c':
    case 'D': case 'd':
    case 'E': case 'e':
    case 'F': case 'f':
    case 'G': case 'g':
    case 'H': case 'h':
    case 'I': case 'i':
    case 'J': case 'j':
    case 'K': case 'k':
    case 'L': case 'l':
    case 'M': case 'm':
    case 'N': case 'n':
    case 'O': case 'o':
    case 'P': case 'p':
    case 'Q': case 'q':
    case 'R': case 'r':
    case 'S': case 's':
    case 'T': case 't':
    case 'U': case 'u':
    case 'V': case 'v':
    case 'W': case 'w':
    case 'X': case 'x':
    case 'Y': case 'y':
    case 'Z': case 'z':
        return (height / 2.0f) * (9.0f / 16.0f);
        
    case '\\':
    case '-':
        return (height / 3.0f) * (9.0f / 16.0f);

    case ':':
    case '\'':
        return (height / 5.0f) * (9.0f / 16.0f);

    default:
        return (0.0f);
    }
}

float getWordwidth(char* word, float height, float spacing)
{
    float width = 0.0f;
    for (int i = 0; word[i] != '\0'; i++)
    {
        width += getCharacterWidth(word[i], height);
        width += spacing;
    }
    return width;
}

COLOR getRandomColor()
{
    COLOR color = { 1, 1, 1, 1 };
    return color;
}

void drawCharacter(char character, float height, MY_POINT start, COLOR color, float thickness)
{
    // get character width
    float width = getCharacterWidth(character, height);

    // the bottom left point is start
    float startX = start.x;
    float startY = start.y;

    //  the top right point is end
    float endX = start.x + width;
    float endY = start.y + height;

    // some default values
    ANGLE angle = { 0, 2 * PI, thickness };
    SCALING scalingFactor = { 1, 1, 0 };
    TRANSLATION translationFactor = start;
    REFLECTION reflectionFactor = { 1, 1, 0 };
    RADIUS radius = { width / 2, height / 2, 0.0f };

    //glColor3f(1, 0, 0);
    //glLineWidth(thickness);
    //glBegin(GL_LINE_LOOP);
    //glVertex3f(startX, startY, 0);
    //glVertex3f(startX, endY, 0);
    //glVertex3f(endX, endY, 0);
    //glVertex3f(endX, startY, 0);
    //glEnd();

    switch (character) {
        case 'A': case 'a':
        {
            MY_POINT end = { startX + (width / 2.0f), startY + height, 0.0f };
            drawLine(color, thickness, start, end);
            MY_POINT startA = { startX + width, startY, 0.0f };
            drawLine(color, thickness, end, startA);
            startA.x = startX + (3.0f * width / 10.0f);
            startA.y = startY + (3.0f * height / 10.0f);
            end.x = startX + (7.0f * width / 10.0f);
            end.y = startY + (3.0f * height / 10.0f);
            drawLine(color, thickness, startA, end);
            break;
        }

        case 'B': case 'b':
        {
            MY_POINT startB = start;
            MY_POINT endB = { startX, endY, 0.0f };
            drawLine(color, thickness, startB, endB);

            angle.y = PI / 2.0f;
            angle.x = -1 * angle.y;
            radius.x = width;
            radius.y = height / 4.0f;
            translationFactor.x = startX;
            translationFactor.y = startY + (3.0f * height / 4.0f);
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);

            translationFactor.y = startY + height / 4.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);
            break;
        }

        case 'C': case 'c':
        {
            angle.x = PI / 4.0f;
            angle.y = 7.0f * angle.x;
            translationFactor.x = startX + width / 2.0f;
            translationFactor.y = startY + height / 2.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);
            break;
        }

        case 'D': case 'd':
        {
            angle.y = PI / 2.0f;
            angle.x = -1 * angle.y;
            translationFactor.x = startX + width / 2.0f;
            translationFactor.y = startY + height / 2.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);

            MY_POINT startD = start;
            MY_POINT endD = { startX + width / 2.0f, startY, 0.0f };
            drawLine(color, thickness, startD, endD);

            startD.y = endY;
            endD.y = endY;
            drawLine(color, thickness, startD, endD);

            startD.x = startX + width / 6.0f;
            endD.x = startX + width / 6.0f;
            endD.y = startY;
            drawLine(color, thickness, startD, endD);
            break;
        }

        case 'E': case 'e':
        {
            MY_POINT startE = start;
            MY_POINT endE = {startX + width, startY, 0.0f};
            drawLine(color, thickness, startE, endE);

            endE.x = startX;
            endE.y = startY + height;
            drawLine(color, thickness, startE, endE);

            startE.x = endX;
            startE.y = endY;
            drawLine(color, thickness, startE, endE);

            startE.x = startX + (2.0f * width / 3.0f);
            startE.y = startY + height / 2.0f;
            endE.x = startX;
            endE.y = startY + height / 2.0f;
            drawLine(color, thickness, startE, endE);
            break;
        }

        case 'F': case 'f':
        {
            MY_POINT startF = start;
            MY_POINT endF = { startX, startY + height, 0.0f };
            drawLine(color, thickness, startF, endF);

            startF.x = endX;
            startF.y = endY;
            drawLine(color, thickness, startF, endF);

            startF.x = startX + (2.0f * width / 3.0f);
            startF.y = startY + height / 2.0f;
            endF.x = startX;
            endF.y = startY + height / 2.0f;
            drawLine(color, thickness, startF, endF);
            break;
        }

        case 'G': case 'g':
        {
            angle.x = PI / 4.0f;
            angle.y = 7.0f * angle.x;
            translationFactor.x = startX + width / 2.0f;
            translationFactor.y = startY + height / 2.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);

            MY_POINT startG = {startX + width / 2.0f, startY + height / 2.0f, 0.0f};
            MY_POINT endG = {endX , startY + height / 2.0f, 0.0f};
            drawLine(color, thickness, startG, endG);

            startG.x = endX - width / 6.0f;
            startG.y = startY;
            endG.x = endX - width / 6.0f;
            drawLine(color, thickness, startG, endG);
            break;
        }

        case 'H': case 'h':
        {
            MY_POINT startH = start;
            MY_POINT endH = {startX, endY, 0.0f};
            drawLine(color, thickness, startH, endH);

            startH.x = endX;
            endH.x = endX;
            endH.y = endY;
            drawLine(color, thickness, startH, endH);

            startH.x = startX;
            startH.y = startY + height / 2.0f;
            endH.x = endX;
            endH.y = endY - height / 2.0f;
            drawLine(color, thickness, startH, endH);
            break;
        }

        case 'I': case 'i':
        {
            MY_POINT startI = start;
            MY_POINT endI = {endX, startY, 0.0f};
            drawLine(color, thickness, startI, endI);

            startI.y = endY;
            endI.y = endY;
            drawLine(color, thickness, startI, endI);

            startI.y = startY;
            startI.x = startX + width / 2.0f;
            endI.x = startX + width / 2.0f;
            drawLine(color, thickness, startI, endI);
            break;
        }

        case 'J': case 'j':
        {
            MY_POINT startJ = {startX, endY, 0.0f};
            MY_POINT endJ = { endX, endY, 0.0f };
            drawLine(color, thickness, startJ, endJ);

            startJ.x = endX - width / 8.0f;
            startJ.y = startY + height / 4.0f;
            endJ.x = endX - width / 8.0f;
            drawLine(color, thickness, startJ, endJ);

            angle.x = PI;
            angle.y = 2 * PI;
            translationFactor.x = startX + (7 * width / 8.0f) / 2.0f;
            translationFactor.y = startY + (height / 4.0f);
            radius.x = (7 * width / 8.0f) / 2.0f;
            radius.y = height / 4.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);
            break;
        }

        case 'K': case 'k':
        {
            MY_POINT startK = start;
            MY_POINT endK = { startX, startY + height, 0.0f };
            drawLine(color, thickness, startK, endK);

            startK.y = startY + height / 2.0f;
            endK.x = endX;
            drawLine(color, thickness, startK, endK);

            endK.y = startY;
            drawLine(color, thickness, startK, endK);
            break;
        }

        case 'L': case 'l':
        {
            MY_POINT startL = start;
            MY_POINT endL = { startX, startY + height, 0.0f };
            drawLine(color, thickness, startL, endL);

            endL.y = startY;
            endL.x = endX;
            drawLine(color, thickness, startL, endL);
            break;
        }

        case 'M': case 'm':
        {
            MY_POINT startM = start;
            MY_POINT endM = { startX, endY, 0.0f };
            MY_POINT centerM = {startX + width / 2.0f, startY + height / 2.0f, 0.0f};
            drawLine(color, thickness, startM, endM);
            drawLine(color, thickness, centerM, endM);

            startM.x = endX;
            endM.x = endX;
            endM.y = endY;
            drawLine(color, thickness, startM, endM);
            drawLine(color, thickness, centerM, endM);
            break;
        }

        case 'N': case 'n':
        {
            MY_POINT startN = start;
            MY_POINT endN = { startX, endY, 0.0f };
            drawLine(color, thickness, startN, endN);

            endN.x = endX;
            endN.y = endY;
            startN.x = endX;
            drawLine(color, thickness, startN, endN);

            startN.x = startX;
            startN.y = endY;
            endN.y = startY;
            drawLine(color, thickness, startN, endN);
            break;
        }

        case 'O': case 'o':
        {
            angle.x = 0;
            angle.y = 2 * PI;
            translationFactor.x = startX + width / 2.0f;
            translationFactor.y = startY + height / 2.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);
            break;
        }

        case 'P': case 'p':
        {
            MY_POINT startP = start;
            MY_POINT endP = { startX, endY, 0.0f };
            drawLine(color, thickness, startP, endP);

            angle.y = PI / 2.0f;
            angle.x = -1 * angle.y;
            translationFactor.x = startX;
            translationFactor.y = startY + (3.0f * height / 4.0f);
            radius.x = width;
            radius.y = height / 4.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);
            break;
        }

        case 'Q': case 'q':
        {
            angle.x = 0;
            angle.y = 2 * PI;
            translationFactor.x = startX + width / 2.0f;
            translationFactor.y = startY + height / 2.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);

            MY_POINT centerQ = { startX + width / 2.0f, startY + height / 2.0f, 0.0f };;
            MY_POINT endQ = { endX, startY, 0.0f };
            drawLine(color, thickness, centerQ, endQ);
            break;
        }

        case 'R': case 'r':
        {
            MY_POINT startR = start;
            MY_POINT endR = { startX, endY, 0.0f };
            drawLine(color, thickness, startR, endR);

            startR.x = endX;
            endR.y = startY + height / 2.0f;
            drawLine(color, thickness, startR, endR);

            angle.y = PI / 2.0f;
            angle.x = -1 * angle.y;
            translationFactor.x = startX;
            translationFactor.y = startY + (3.0f * height / 4.0f);
            radius.x = width;
            radius.y = height / 4.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);
            break;
        }

        case 'S': case 's':
        {
            radius.x = width / 2.0f;
            radius.y = height / 3.0f;
            angle.x = PI;
            angle.y = 2 * PI;
            translationFactor.x = startX + width / 2.0f;
            translationFactor.y = startY + height / 3.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);

            angle.x = 0;
            angle.y = PI;
            translationFactor.x = startX + width / 2.0f;
            translationFactor.y = startY + (2 * height / 3.0f);
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);

            MY_POINT startS = { startX, translationFactor.y, 0.0f };
            MY_POINT endS = { startX + width, startY + height / 3.0f, 0.0f };
            drawLine(color, thickness, startS, endS);
            break;
        }

        case 'T': case 't':
        {
            MY_POINT startT = {startX + width / 2.0f, startY, 0.0f};
            MY_POINT endT = { startX + width / 2.0f, endY, 0.0f };
            drawLine(color, thickness, startT, endT);

            startT.x = startX;
            startT.y = endY;
            endT.x = endX;
            drawLine(color, thickness, startT, endT);
            break;
        }

        case 'U': case 'u':
        {
            MY_POINT startU = { startX, endY, 0.0f };
            MY_POINT endU = { startX, startY + height / 3.0f, 0.0f };
            drawLine(color, thickness, startU, endU);

            startU.x = endX;
            endU.x = endX;
            drawLine(color, thickness, startU, endU);

            angle.x = PI;
            angle.y = 2 * PI;
            translationFactor.x = startX + width / 2.0f;
            translationFactor.y = startY + height / 3.0f;
            radius.x = width / 2.0f;
            radius.y = height / 3.0f;
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);
            break;
        }

        case 'V': case 'v':
        {
            MY_POINT startV = { startX, endY, 0.0f };
            MY_POINT endV = { startX + width / 2.0f, startY, 0.0f };
            drawLine(color, thickness, startV, endV);

            startV.x = endX;
            startV.y = endY;
            drawLine(color, thickness, startV, endV);
            break;
        }

        case 'W': case 'w':
        {
            MY_POINT startW = start;
            MY_POINT endW = { startX, endY, 0.0f };
            MY_POINT centerW = { startX + width / 2.0f, startY + height / 2.0f, 0.0f };
            drawLine(color, thickness, startW, endW);
            drawLine(color, thickness, centerW, startW);

            startW.x = endX;
            endW.x = endX;
            endW.y = endY;
            drawLine(color, thickness, startW, endW);
            drawLine(color, thickness, centerW, startW);
            break;
        }

        case 'X': case 'x':
        {
            MY_POINT sX = start;
            MY_POINT eX = {endX, endY, 0.0f};
            drawLine(color, thickness, sX, eX);

            sX.y = endY;
            eX.y = startY;
            drawLine(color, thickness, sX, eX);
            break;
        }

        case 'Y': case 'y':
        {
            MY_POINT sY = {startX, endY, 0.0f};
            MY_POINT centerY = { startX + width / 2.0f, startY + height / 2.0f, 0.0f };
            drawLine(color, thickness, sY, centerY);

            sY.x = endX;
            drawLine(color, thickness, sY, centerY);

            sY.x = centerY.x;
            sY.y = startY;
            drawLine(color, thickness, sY, centerY);
            break;
        }

        case 'Z': case 'z':
        {
            MY_POINT startZ = start;
            MY_POINT endZ = {endX, startY, 0.0f};
            drawLine(color, thickness, startZ, endZ);

            endZ.y = endY;
            drawLine(color, thickness, startZ, endZ);

            startZ.y = endY;
            drawLine(color, thickness, startZ, endZ);
            break;
        }

        case ':':
        {
            MY_POINT colonDot1 = {(startX + endX) / 2.0f, startY + height / 4.0f, start.z};
            MY_POINT colonDot2 = {(startX + endX) / 2.0f, startY + 3.0f * height / 4.0f, start.z};

            glEnable(GL_POINT_SMOOTH);
            glPointSize(thickness <= 10.0f ? thickness : thickness / 4.0f);
            glBegin(GL_POINTS);
            glVertex3f(colonDot1.x, colonDot1.y, colonDot1.z);
            glVertex3f(colonDot2.x, colonDot2.y, colonDot2.z);
            glEnd();
            glDisable(GL_POINT_SMOOTH);
            break;
        }
        
        case '\'':
        {
            MY_POINT startSigleQuote = {(startX + endX) / 2.0f, endY, 0.0f};
            radius.x = 0.04f;
            radius.y = 0.09f;
            angle.x =  -1 * PI / 4.0f;
            angle.y = PI / 10.0f;

            translationFactor.x = startSigleQuote.x - radius.x;
            translationFactor.y = endY;

            glEnable(GL_POINT_SMOOTH);
            glPointSize(thickness <= 10.0f ? thickness : thickness / 4.0f);
            glBegin(GL_POINTS);
            glVertex3f(startSigleQuote.x, startSigleQuote.y, startSigleQuote.z);
            glEnd();
            glDisable(GL_POINT_SMOOTH);
            
            drawEllipse(color, angle, scalingFactor, translationFactor, reflectionFactor, radius, 0.0f);
            break;
        }

        case '\\':
        {
            MY_POINT startSlash = {startX, endY, 0.0f};
            MY_POINT endSlash = {endX, startY, 0.0f};

            drawLine(color, thickness, startSlash, endSlash);
            break;
        }

        case '-':
        {
            MY_POINT startDash = {startX, startY + height / 2.0f, 0.0f};
            MY_POINT endDash = {endX, startY + height / 2.0f, 0.0f};
            drawLine(color, thickness, startDash, endDash);
            break;
        }
    }
}

