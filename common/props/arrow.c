void drawArrow(void)
{
    glPushMatrix();
    glTranslatef(0.3f, -0.3f, 0.0f);
    glRotatef(400.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.5f, 0.35f, 0.05f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glEnd();
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.35f, 0.05f);
    glVertex2f(0.35f, -0.05f);
    glEnd();
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.05f, 0.03f);
    glVertex2f(0.05f, -0.03f);
    glEnd();
    glPopMatrix();
}
