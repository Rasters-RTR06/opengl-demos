void drawPolygon(SHAPE shape, SCALING scalingFactor, TRANSLATION translationFactor, REFLECTION reflectionFactor)
{
    glColor4f(shape.color.rValue > 1 ? (shape.color.rValue / 255.0f) : shape.color.rValue,
        shape.color.gValue > 1 ? (shape.color.gValue / 255.0f) : shape.color.gValue,
        shape.color.bValue > 1 ? (shape.color.bValue / 255.0f) : shape.color.bValue,
        shape.color.aValue > 1 ? 1 : shape.color.aValue);
    glBegin(GL_POLYGON);

    for (int i = 0; i < shape.noOfPoints; i++)
    {
        MY_POINT newPoint = { shape.points[i].x, shape.points[i].y, shape.points[i].z };
        newPoint = scalePoint(newPoint, scalingFactor);
        newPoint = translatePoint(newPoint, translationFactor);
        newPoint = reflectPoint(newPoint, reflectionFactor);

        glVertex3f((GLfloat)(newPoint.x), (GLfloat)(newPoint.y), (GLfloat)(newPoint.z));
    }

    glEnd();
}

void drawEllipse(COLOR color,
     ANGLE angle,
     SCALING scalingFactor,
     TRANSLATION translationFactor,
     REFLECTION reflectionFactor,
     RADIUS radius,
     float rotationAngle)
{
    float ObjX = 0.0f;
    float ObjY = 0.0f;
    float ObjAngle = 0.0f;

    glColor4f(color.rValue > 1 ? (color.rValue / 255.0f) : color.rValue,
        color.gValue > 1 ? (color.gValue / 255.0f) : color.gValue,
        color.bValue > 1 ? (color.bValue / 255.0f) : color.bValue,
        color.aValue > 1 ? 1 : color.aValue);

    if (angle.z != 0.0f) 
    {
        glLineWidth((angle.z < 0) ? (-1.0f * angle.z) : angle.z);
        glBegin(GL_LINE_STRIP);
    } 
    else
    {
        glBegin(GL_TRIANGLE_FAN);
    }
    for (ObjAngle = angle.x; ObjAngle <= angle.y; ObjAngle += 0.001f)
    {
        ObjX = radius.x * cos(ObjAngle);
        ObjY = radius.y * sin(ObjAngle);

        MY_POINT newPoint = { ObjX, ObjY, 0};
        newPoint = rotatePoint(newPoint, rotationAngle);
        newPoint = scalePoint(newPoint, scalingFactor);
        newPoint = translatePoint(newPoint, translationFactor);
        newPoint = reflectPoint(newPoint, reflectionFactor);

        glVertex3f(newPoint.x, newPoint.y, newPoint.z);
    }
    glEnd();
}

void drawLine(COLOR color, float thickness, MY_POINT start, MY_POINT end)
{
    glColor4f(color.rValue > 1 ? (color.rValue / 255.0f) : color.rValue,
        color.gValue > 1 ? (color.gValue / 255.0f) : color.gValue,
        color.bValue > 1 ? (color.bValue / 255.0f) : color.bValue,
        color.aValue > 1 ? 1 : color.aValue);

    glLineWidth((thickness < 0) ? (-1.0f * thickness) : thickness);
    glBegin(GL_LINES);
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(end.x, end.y, end.z);
    glEnd();
}