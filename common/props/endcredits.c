float fCharachterHeight = 0.07f;
float fThickness = 2.0f;
float fLeftMargin = -0.9f;
float fCenterMargin = -0.5f;
float fCharSpacing = 0.01f;
float fDownSpacing = 0.12f;

float fgetDownfCharSpacing(int i)
{
    return 0.85 - (i * fDownSpacing);
}

void drawNikhil(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Nikhil   Sathe", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawAyush(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Ayush   Jaiswal", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawHimanshu(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Himanshu   Choudhari", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawVinayak(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Vinayak   Mali", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawNitin(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Nitin   Kolapkar", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawBhagyashree(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Bhagyashree   Chavan", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawVighnesh(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Vighnesh   Nair", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawImran(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Imran   Khan   Pathan", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawBhushan(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Bhushan   Rane", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawVishal(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Vishal   Kamble", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawRadhika(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Radhika   Vishwakarma", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawVaibhav(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Vaibhav   Ile", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawShripad(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Shripad   Bhatlawande", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawShailesh(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Shailesh   Ubhe", fCharachterHeight, start, color, fThickness, fCharSpacing);
}
void drawGLText(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Raster   Group   Leader:", fCharachterHeight, start, color, fThickness, fCharSpacing);
}
void drawFilmsDivision(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Films   Division   Classic: Sandesh", fCharachterHeight, start, color, fThickness, fCharSpacing);
}

void drawLinkinDescription(float x, float y)
{
    start.x = x;
    start.y = y;
    drawWord("Link   in   Video   Description", fCharachterHeight, start, color, fThickness, fCharSpacing);
}
void drawSandeshReference()
{
    drawFilmsDivision(fCenterMargin, fgetDownfCharSpacing(0));
    drawLinkinDescription(fCenterMargin, fgetDownfCharSpacing(2));
}

void drawRasterGroupLeader()
{
    drawGLText(fCenterMargin, fgetDownfCharSpacing(0));
    drawShailesh(fCenterMargin, fgetDownfCharSpacing(1));
}


void drawMemberNames()
{
    drawAyush(fLeftMargin, fgetDownfCharSpacing(0)); 
    drawImran(fLeftMargin, fgetDownfCharSpacing(1));
    drawBhagyashree(fLeftMargin, fgetDownfCharSpacing(2));
    drawVaibhav(fLeftMargin, fgetDownfCharSpacing(3));
    drawRadhika(fLeftMargin, fgetDownfCharSpacing(4));
    drawVighnesh(fLeftMargin, fgetDownfCharSpacing(5));
    drawNitin(fLeftMargin, fgetDownfCharSpacing(6));
    drawVishal(fLeftMargin, fgetDownfCharSpacing(7));
    drawVinayak(fLeftMargin, fgetDownfCharSpacing(8));
    drawHimanshu(fLeftMargin, fgetDownfCharSpacing(9));
    drawBhushan(fLeftMargin, fgetDownfCharSpacing(10));
    drawShripad(fLeftMargin, fgetDownfCharSpacing(11));
    drawNikhil(fLeftMargin, fgetDownfCharSpacing(12));

}