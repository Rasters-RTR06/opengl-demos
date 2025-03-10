BOOL showAtroMediComp = TRUE;
BOOL showAstre = FALSE;
BOOL swapRE = FALSE;
BOOL moveAstreToCentre = FALSE;
BOOL showRasterAnimation = FALSE;
BOOL liftRasters = FALSE;
BOOL showRasterGropPresents = FALSE;

BOOL flag1 = FALSE;
BOOL flag2 = FALSE;

COLOR color = { 1.0f, 0.0f, 0.0f, 1.0f };
MY_POINT start = { -0.75f, -0.15f, 0.0f };
MY_POINT posR, posE;

float astroMediCompOpacity = 1.0f;
int counter = 0;
float characterHeight = 0.3;
float thickness = 100.0f;
float spacing = 0.03f;
int timeToSwapR = 100;

void updateIntro()
{
	if ((counter >= 100) && (showAtroMediComp == TRUE))
	{
		astroMediCompOpacity -= 0.01f;
		if (astroMediCompOpacity < 0.0f)
		{
			start.x = -0.75f;
			color.aValue = 1.0f;
			showAtroMediComp = FALSE;
			showAstre = TRUE;
			counter = 0;
		}
	}
	else if (showAstre == TRUE)
	{
		if ((start.x + getWordwidth("ASTR", characterHeight, spacing)) < posE.x && flag2 == FALSE)
		{
			start.x += 0.01f;
		}
		else if (moveAstreToCentre == FALSE && swapRE == FALSE)
		{
			flag2 = TRUE;
			moveAstreToCentre = TRUE;
		}
		else if (moveAstreToCentre == TRUE && swapRE == FALSE)
		{
			float center = (spacing - (getWordwidth("RASTER", characterHeight, spacing)) / 2.0f) + getCharacterWidth('R', characterHeight);
			if (start.x < center && moveAstreToCentre == TRUE)
			{
				posE.x += 0.01f;
				start.x += 0.01f;
			}
			else
			{
				posR = start;
				posR.x += getWordwidth("AST", characterHeight, spacing);
				moveAstreToCentre = FALSE;
				swapRE = TRUE;
			}			
		}
		else if (swapRE == TRUE)
		{
			if (posR.x < (start.x + getWordwidth("ASTE", characterHeight, spacing)))
				posR.x += 0.01f;
			else
				flag1 = TRUE;

			if (posE.x > (start.x + getWordwidth("AST", characterHeight, spacing)))
				posE.x -= 0.01f;
			else
				flag2 = TRUE;
			
			if (flag1 == TRUE && flag2 == TRUE)
			{				
				posR.x = start.x + getWordwidth("ASTE", characterHeight, spacing);
				showAstre = FALSE;
				showRasterAnimation = TRUE;
				counter = 0;
				flag1 = FALSE;
				flag2 = FALSE;
			}
		}
	}
	else if (showRasterAnimation == TRUE)
	{
		if (timeToSwapR >= 0.0001f)
		{
			counter++;
			if (counter >= timeToSwapR)
			{
				counter = 0;
				timeToSwapR = timeToSwapR / 3;
				float lastRX = start.x + getWordwidth("ASTE", characterHeight, spacing);
				if (posR.x <= (lastRX + 0.1f) &&
					posR.x >= (lastRX - 0.1f))
				{
					posR.x = start.x - getCharacterWidth('R', characterHeight);
					posR.x -= spacing;
				}
				else
				{
					posR.x = lastRX;
				}
			}
		}
		else 
		{
			start.x -= getCharacterWidth('R', characterHeight);
			start.x -= spacing;
			showRasterAnimation = FALSE;
			liftRasters = TRUE;
		}
	}
	else if (liftRasters == TRUE)
	{
		if (start.y <= (1.0f - (0.22 + characterHeight)))
		{
			start.y += 0.01f;
		}
		else
		{
			liftRasters = FALSE;
			showRasterGropPresents = TRUE;
		}
	}
	else if (counter <= 100 && showRasterGropPresents == FALSE)
		counter++;
}

void drawIntro()
{
	if (showAtroMediComp)
	{
		drawAstromedicomp();
	}
	else if (showAstre)
	{
		drawAstre();
	}
	else if (showRasterAnimation || liftRasters)
	{
		drawRasters();
	}
	else if (showRasterGropPresents)
	{
		drawRasterGroupPresents();
	}
}

void drawAstromedicomp()
{
	color.aValue = 1.0f;
	start.x = -0.75f;
	drawWord("ASTR", characterHeight, start, color, thickness, spacing);

	start.x += getWordwidth("ASTR", characterHeight, spacing);
	color.aValue = astroMediCompOpacity;
	drawCharacter('O', characterHeight, start, color, thickness);

	start.x += getCharacterWidth('o', characterHeight);
	start.x += spacing;
	drawCharacter('M', characterHeight, start, color, thickness);

	start.x += getCharacterWidth('m', characterHeight);
	start.x += spacing;
	color.aValue = 1;
	posE = start;
	drawCharacter('E', characterHeight, start, color, thickness);

	start.x += getCharacterWidth('e', characterHeight);
	start.x += spacing;
	color.aValue = astroMediCompOpacity;
	drawWord("DICOMP", characterHeight, start, color, thickness, spacing);
}

void drawAstre()
{
	if (moveAstreToCentre == TRUE)
	{
		drawWord("ASTRE", characterHeight, start, color, thickness, spacing);
	}
	else if (swapRE == TRUE)
	{
		drawWord("AST", characterHeight, start, color, thickness, spacing);
		drawCharacter('E', characterHeight, posE, color, thickness);
		drawCharacter('R', characterHeight, posR, color, thickness);
	}
	else if (moveAstreToCentre == FALSE && swapRE == FALSE)
	{
		drawWord("ASTR", characterHeight, start, color, thickness, spacing);
		drawCharacter('E', characterHeight, posE, color, thickness);
	}
}

void drawRasters()
{
	if(showRasterAnimation)
	{
		drawWord("ASTE", characterHeight, start, color, thickness, spacing);
		drawCharacter('R', characterHeight, posR, color, thickness);
	}
	else if (liftRasters)
	{
		drawWord("RASTER", characterHeight, start, color, thickness, spacing);
	}
}

void drawRasterGroupPresents()
{
	start.x = -(getWordwidth("RASTER", characterHeight, spacing) / 2);
	start.y = (1.0f - (0.22 + characterHeight));
	drawWord("RASTER", characterHeight, start, color, thickness, spacing);

	start.x = -(getWordwidth("GROUP", characterHeight, spacing) / 2);
	start.y -= (1.0f - (0.12 + characterHeight));
	drawWord("GROUP", characterHeight, start, color, thickness, spacing);

	start.x = -(getWordwidth("PRESENTS", characterHeight, spacing) / 2);
	start.y -= (1.0f - (0.12 + characterHeight));
	drawWord("PRESENTS", characterHeight, start, color, thickness, spacing);
}