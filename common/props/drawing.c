void drawPolygon(SHAPE shape, struct MY_POINT scalingFactor, struct MY_POINT translationFactor, struct MY_POINT reflectionFactor)
{
    glColor3f(shape.rValue > 1 ? (shape.rValue / 255.0f) : shape.rValue,
        shape.gValue > 1 ? (shape.gValue / 255.0f) : shape.gValue,
        shape.bValue > 1 ? (shape.bValue / 255.0f) : shape.bValue);
    glBegin(GL_POLYGON);

    for (int i = 0; i < shape.noOfPoints; i++)
    {
        struct MY_POINT newPoint = { shape.points[i].x, shape.points[i].y, shape.points[i].z };
        newPoint = scalePoint(newPoint, scalingFactor);
        newPoint = translatePoint(newPoint, translationFactor);
        newPoint = reflectPoint(newPoint, reflectionFactor);

        glVertex3f((GLfloat)(newPoint.x), (GLfloat)(newPoint.y), (GLfloat)(newPoint.z));
    }

    glEnd();
}