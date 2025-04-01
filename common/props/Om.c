#define OM_COLOR 1.0, 0.0, 0.0

void drawOM(float originx, float originy, float resize)
{
    // Triangle 1
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.516 * resize, originy + 0.326 * resize);
    glVertex2f(originx + -0.427 * resize, originy + 0.181 * resize);
    glVertex2f(originx + -0.329 * resize, originy + 0.229 * resize);
    glEnd();
    // Triangle 2
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.329 * resize, originy + 0.229 * resize);
    glVertex2f(originx + -0.256 * resize, originy + 0.254 * resize);
    glVertex2f(originx + -0.427 * resize, originy + 0.386 * resize);
    glEnd();
    // Triangle 3
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.516 * resize, originy + 0.326 * resize);
    glVertex2f(originx + -0.427 * resize, originy + 0.386 * resize);
    glVertex2f(originx + -0.329 * resize, originy + 0.229 * resize);
    glEnd();
    // Triangle 4
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.427 * resize, originy + 0.386 * resize);
    glVertex2f(originx + -0.363 * resize, originy + 0.416 * resize);
    glVertex2f(originx + -0.256 * resize, originy + 0.254 * resize);
    glEnd();
    // Triangle 5
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.363 * resize, originy + 0.416 * resize);
    glVertex2f(originx + -0.306 * resize, originy + 0.432 * resize);
    glVertex2f(originx + -0.256 * resize, originy + 0.254 * resize);
    glEnd();
    // Triangle 6
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.306 * resize, originy + 0.432 * resize);
    glVertex2f(originx + -0.256 * resize, originy + 0.441 * resize);
    glVertex2f(originx + -0.256 * resize, originy + 0.254 * resize);
    glEnd();
    // Triangle 7
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.256 * resize, originy + 0.254 * resize);
    glVertex2f(originx + -0.227 * resize, originy + 0.261 * resize);
    glVertex2f(originx + -0.256 * resize, originy + 0.441 * resize);
    glEnd();
    // Triangle 8
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.227 * resize, originy + 0.261 * resize);
    glVertex2f(originx + -0.165 * resize, originy + 0.261 * resize);
    glVertex2f(originx + -0.190 * resize, originy + 0.443 * resize);
    glEnd();
    // Triangle 9
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.256 * resize, originy + 0.441 * resize);
    glVertex2f(originx + -0.190 * resize, originy + 0.443 * resize);
    glVertex2f(originx + -0.227 * resize, originy + 0.261 * resize);
    glEnd();
    // Triangle 10
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.165 * resize, originy + 0.261 * resize);
    glVertex2f(originx + -0.190 * resize, originy + 0.443 * resize);
    glVertex2f(originx + -0.135 * resize, originy + 0.434 * resize);
    glEnd();
    // Triangle 11
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.135 * resize, originy + 0.434 * resize);
    glVertex2f(originx + -0.072 * resize, originy + 0.395 * resize);
    glVertex2f(originx + -0.094 * resize, originy + 0.197 * resize);
    glEnd();
    // Triangle 12
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.094 * resize, originy + 0.197 * resize);
    glVertex2f(originx + -0.008 * resize, originy + 0.197 * resize);
    glVertex2f(originx + -0.072 * resize, originy + 0.395 * resize);
    glEnd();
    // Triangle 13
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.165 * resize, originy + 0.261 * resize);
    glVertex2f(originx + -0.122 * resize, originy + 0.236 * resize);
    glVertex2f(originx + -0.135 * resize, originy + 0.434 * resize);
    glEnd();
    // Triangle 14
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.122 * resize, originy + 0.236 * resize);
    glVertex2f(originx + -0.094 * resize, originy + 0.197 * resize);
    glVertex2f(originx + -0.135 * resize, originy + 0.434 * resize);
    glEnd();
    // Triangle 15
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.094 * resize, originy + 0.197 * resize);
    glVertex2f(originx + -0.097 * resize, originy + 0.167 * resize);
    glVertex2f(originx + -0.008 * resize, originy + 0.197 * resize);
    glEnd();
    // Triangle 16
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.008 * resize, originy + 0.197 * resize);
    glVertex2f(originx + -0.003 * resize, originy + 0.257 * resize);
    glVertex2f(originx + -0.072 * resize, originy + 0.395 * resize);
    glEnd();
    // Triangle 17
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.003 * resize, originy + 0.257 * resize);
    glVertex2f(originx + -0.019 * resize, originy + 0.317 * resize);
    glVertex2f(originx + -0.072 * resize, originy + 0.395 * resize);
    glEnd();
    // Triangle 18
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.097 * resize, originy + 0.167 * resize);
    glVertex2f(originx + -0.145 * resize, originy + 0.109 * resize);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glEnd();
    // Triangle 19
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.097 * resize, originy + 0.167 * resize);
    glVertex2f(originx + -0.008 * resize, originy + 0.197 * resize);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glEnd();
    // Triangle 20
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glVertex2f(originx + -0.094 * resize, originy + 0.035 * resize);
    glVertex2f(originx + -0.008 * resize, originy + 0.197 * resize);
    glEnd();
    // Triangle 21
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.008 * resize, originy + 0.197 * resize);
    glVertex2f(originx + -0.094 * resize, originy + 0.035 * resize);
    glVertex2f(originx + -0.037 * resize, originy + 0.116 * resize);
    glEnd();
    // Triangle 22
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glVertex2f(originx + -0.270 * resize, originy + -0.107 * resize);
    glVertex2f(originx + -0.352 * resize, originy + 0.091 * resize);
    glEnd();
    // Triangle 23
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.352 * resize, originy + 0.091 * resize);
    glVertex2f(originx + -0.231 * resize, originy + 0.082 * resize);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glEnd();
    // Triangle 24
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.231 * resize, originy + 0.082 * resize);
    glVertex2f(originx + -0.195 * resize, originy + 0.088 * resize);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glEnd();
    // Triangle 25
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.195 * resize, originy + 0.088 * resize);
    glVertex2f(originx + -0.145 * resize, originy + 0.109 * resize);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glEnd();
    // Triangle 26
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.352 * resize, originy + 0.091 * resize);
    glVertex2f(originx + -0.336 * resize, originy + 0.019 * resize);
    glVertex2f(originx + -0.270 * resize, originy + -0.107 * resize);
    glEnd();
    // Triangle 27
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.270 * resize, originy + -0.107 * resize);
    glVertex2f(originx + -0.161 * resize, originy + -0.105 * resize);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glEnd();
    // Triangle 28
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.161 * resize, originy + -0.105 * resize);
    glVertex2f(originx + -0.101 * resize, originy + -0.135 * resize);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glEnd();
    // Triangle 29
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.101 * resize, originy + -0.135 * resize);
    glVertex2f(originx + -0.069 * resize, originy + -0.204 * resize);
    glVertex2f(originx + 0.008 * resize, originy + -0.094 * resize);
    glEnd();
    // Triangle 30
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glVertex2f(originx + -0.101 * resize, originy + -0.135 * resize);
    glVertex2f(originx + 0.008 * resize, originy + -0.094 * resize);
    glEnd();
    // Triangle 31
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.140 * resize, originy + 0.008 * resize);
    glVertex2f(originx + -0.058 * resize, originy + -0.029 * resize);
    glVertex2f(originx + 0.008 * resize, originy + -0.094 * resize);
    glEnd();
    // Triangle 32
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.008 * resize, originy + -0.094 * resize);
    glVertex2f(originx + 0.042 * resize, originy + -0.197 * resize);
    glVertex2f(originx + -0.069 * resize, originy + -0.204 * resize);
    glEnd();
    // Triangle 33
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.069 * resize, originy + -0.204 * resize);
    glVertex2f(originx + -0.074 * resize, originy + -0.536 * resize);
    glVertex2f(originx + 0.042 * resize, originy + -0.197 * resize);
    glEnd();
    // Triangle 34
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.042 * resize, originy + -0.197 * resize);
    glVertex2f(originx + 0.047 * resize, originy + -0.326 * resize);
    glVertex2f(originx + -0.074 * resize, originy + -0.536 * resize);
    glEnd();
    // Triangle 35
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.047 * resize, originy + -0.326 * resize);
    glVertex2f(originx + 0.029 * resize, originy + -0.405 * resize);
    glVertex2f(originx + -0.074 * resize, originy + -0.536 * resize);
    glEnd();
    // Triangle 36
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.029 * resize, originy + -0.405 * resize);
    glVertex2f(originx + -0.008 * resize, originy + -0.474 * resize);
    glVertex2f(originx + -0.074 * resize, originy + -0.536 * resize);
    glEnd();
    // Triangle 37
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.058 * resize, originy + -0.029 * resize);
    glVertex2f(originx + 0.182 * resize, originy + 0.024 * resize);
    glVertex2f(originx + 0.008 * resize, originy + -0.094 * resize);
    glEnd();
    // Triangle 38
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.008 * resize, originy + -0.094 * resize);
    glVertex2f(originx + 0.125 * resize, originy + -0.094 * resize);
    glVertex2f(originx + 0.182 * resize, originy + 0.024 * resize);
    glEnd();
    // Triangle 39
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.182 * resize, originy + 0.024 * resize);
    glVertex2f(originx + 0.243 * resize, originy + 0.015 * resize);
    glVertex2f(originx + 0.125 * resize, originy + -0.094 * resize);
    glEnd();
    // Triangle 40
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.243 * resize, originy + 0.015 * resize);
    glVertex2f(originx + 0.410 * resize, originy + 0.270 * resize);
    glVertex2f(originx + 0.195 * resize, originy + 0.241 * resize);
    glEnd();
    // Triangle 41
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.182 * resize, originy + 0.024 * resize);
    glVertex2f(originx + 0.017 * resize, originy + -0.013 * resize);
    glVertex2f(originx + 0.195 * resize, originy + 0.241 * resize);
    glEnd();
    // Triangle 42
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.182 * resize, originy + 0.024 * resize);
    glVertex2f(originx + 0.243 * resize, originy + 0.015 * resize);
    glVertex2f(originx + 0.195 * resize, originy + 0.241 * resize);
    glEnd();
    // Triangle 43
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.195 * resize, originy + 0.241 * resize);
    glVertex2f(originx + 0.277 * resize, originy + 0.277 * resize);
    glVertex2f(originx + 0.410 * resize, originy + 0.270 * resize);
    glEnd();
    // Triangle 44
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.410 * resize, originy + 0.270 * resize);
    glVertex2f(originx + 0.512 * resize, originy + 0.197 * resize);
    glVertex2f(originx + 0.421 * resize, originy + 0.162 * resize);
    glEnd();
    // Triangle 45
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.421 * resize, originy + 0.162 * resize);
    glVertex2f(originx + 0.380 * resize, originy + 0.165 * resize);
    glVertex2f(originx + 0.410 * resize, originy + 0.270 * resize);
    glEnd();
    // Triangle 46
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.380 * resize, originy + 0.165 * resize);
    glVertex2f(originx + 0.318 * resize, originy + 0.130 * resize);
    glVertex2f(originx + 0.410 * resize, originy + 0.270 * resize);
    glEnd();
    // Triangle 47
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.421 * resize, originy + 0.162 * resize);
    glVertex2f(originx + 0.471 * resize, originy + 0.148 * resize);
    glVertex2f(originx + 0.512 * resize, originy + 0.197 * resize);
    glEnd();
    // Triangle 48
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.471 * resize, originy + 0.148 * resize);
    glVertex2f(originx + 0.505 * resize, originy + 0.088 * resize);
    glVertex2f(originx + 0.512 * resize, originy + 0.197 * resize);
    glEnd();
    // Triangle 49
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.505 * resize, originy + 0.088 * resize);
    glVertex2f(originx + 0.585 * resize, originy + 0.033 * resize);
    glVertex2f(originx + 0.512 * resize, originy + 0.197 * resize);
    glEnd();
    // Triangle 50
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.505 * resize, originy + 0.088 * resize);
    glVertex2f(originx + 0.510 * resize, originy + -0.105 * resize);
    glVertex2f(originx + 0.585 * resize, originy + 0.033 * resize);
    glEnd();
    // Triangle 51
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.585 * resize, originy + 0.033 * resize);
    glVertex2f(originx + 0.597 * resize, originy + -0.128 * resize);
    glVertex2f(originx + 0.510 * resize, originy + -0.105 * resize);
    glEnd();
    // Triangle 52
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.510 * resize, originy + -0.105 * resize);
    glVertex2f(originx + 0.471 * resize, originy + -0.183 * resize);
    glVertex2f(originx + 0.597 * resize, originy + -0.128 * resize);
    glEnd();
    // Triangle 53
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.471 * resize, originy + -0.183 * resize);
    glVertex2f(originx + 0.492 * resize, originy + -0.409 * resize);
    glVertex2f(originx + 0.597 * resize, originy + -0.128 * resize);
    glEnd();
    // Triangle 54
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.597 * resize, originy + -0.128 * resize);
    glVertex2f(originx + 0.569 * resize, originy + -0.289 * resize);
    glVertex2f(originx + 0.492 * resize, originy + -0.409 * resize);
    glEnd();
    // Triangle 55
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.471 * resize, originy + -0.183 * resize);
    glVertex2f(originx + 0.398 * resize, originy + -0.246 * resize);
    glVertex2f(originx + 0.492 * resize, originy + -0.409 * resize);
    glEnd();
    // Triangle 56
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.492 * resize, originy + -0.409 * resize);
    glVertex2f(originx + 0.403 * resize, originy + -0.471 * resize);
    glVertex2f(originx + 0.398 * resize, originy + -0.246 * resize);
    glEnd();
    // Triangle 57
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.398 * resize, originy + -0.246 * resize);
    glVertex2f(originx + 0.302 * resize, originy + -0.278 * resize);
    glVertex2f(originx + 0.403 * resize, originy + -0.471 * resize);
    glEnd();
    // Triangle 58
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.403 * resize, originy + -0.471 * resize);
    glVertex2f(originx + 0.280 * resize, originy + -0.467 * resize);
    glVertex2f(originx + 0.302 * resize, originy + -0.278 * resize);
    glEnd();
    // Triangle 59
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.280 * resize, originy + -0.467 * resize);
    glVertex2f(originx + 0.188 * resize, originy + -0.416 * resize);
    glVertex2f(originx + 0.302 * resize, originy + -0.278 * resize);
    glEnd();
    // Triangle 60
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.302 * resize, originy + -0.278 * resize);
    glVertex2f(originx + 0.225 * resize, originy + -0.269 * resize);
    glVertex2f(originx + 0.188 * resize, originy + -0.416 * resize);
    glEnd();
    // Triangle 61
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.225 * resize, originy + -0.269 * resize);
    glVertex2f(originx + 0.150 * resize, originy + -0.172 * resize);
    glVertex2f(originx + 0.188 * resize, originy + -0.416 * resize);
    glEnd();
    // Triangle 62
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.150 * resize, originy + -0.172 * resize);
    glVertex2f(originx + 0.138 * resize, originy + -0.137 * resize);
    glVertex2f(originx + 0.120 * resize, originy + -0.230 * resize);
    glEnd();
    // Triangle 63
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.120 * resize, originy + -0.230 * resize);
    glVertex2f(originx + 0.188 * resize, originy + -0.416 * resize);
    glVertex2f(originx + 0.150 * resize, originy + -0.172 * resize);
    glEnd();
    // Triangle 64
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.069 * resize, originy + -0.289 * resize);
    glVertex2f(originx + -0.167 * resize, originy + -0.382 * resize);
    glVertex2f(originx + -0.074 * resize, originy + -0.536 * resize);
    glEnd();
    // Triangle 65
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.074 * resize, originy + -0.536 * resize);
    glVertex2f(originx + -0.135 * resize, originy + -0.568 * resize);
    glVertex2f(originx + -0.167 * resize, originy + -0.382 * resize);
    glEnd();
    // Triangle 66
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.167 * resize, originy + -0.382 * resize);
    glVertex2f(originx + -0.519 * resize, originy + -0.428 * resize);
    glVertex2f(originx + -0.135 * resize, originy + -0.568 * resize);
    glEnd();
    // Triangle 67
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.135 * resize, originy + -0.568 * resize);
    glVertex2f(originx + -0.270 * resize, originy + -0.577 * resize);
    glVertex2f(originx + -0.519 * resize, originy + -0.428 * resize);
    glEnd();
    // Triangle 68
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.270 * resize, originy + -0.577 * resize);
    glVertex2f(originx + -0.363 * resize, originy + -0.554 * resize);
    glVertex2f(originx + -0.519 * resize, originy + -0.428 * resize);
    glEnd();
    // Triangle 69
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.519 * resize, originy + -0.428 * resize);
    glVertex2f(originx + -0.452 * resize, originy + -0.345 * resize);
    glVertex2f(originx + -0.279 * resize, originy + -0.395 * resize);
    glEnd();
    // Triangle 70
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.452 * resize, originy + -0.345 * resize);
    glVertex2f(originx + -0.537 * resize, originy + -0.246 * resize);
    glVertex2f(originx + -0.519 * resize, originy + -0.428 * resize);
    glEnd();
    // Triangle 71
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.519 * resize, originy + -0.428 * resize);
    glVertex2f(originx + -0.605 * resize, originy + -0.259 * resize);
    glVertex2f(originx + -0.537 * resize, originy + -0.246 * resize);
    glEnd();
    // Triangle 72
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.605 * resize, originy + -0.259 * resize);
    glVertex2f(originx + -0.628 * resize, originy + -0.068 * resize);
    glVertex2f(originx + -0.537 * resize, originy + -0.246 * resize);
    glEnd();
    // Triangle 73
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.628 * resize, originy + -0.068 * resize);
    glVertex2f(originx + -0.621 * resize, originy + -0.015 * resize);
    glVertex2f(originx + -0.537 * resize, originy + -0.246 * resize);
    glEnd();
    // Triangle 74
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.092 * resize, originy + 0.607 * resize);
    glVertex2f(originx + -0.085 * resize, originy + 0.496 * resize);
    glVertex2f(originx + -0.037 * resize, originy + 0.526 * resize);
    glEnd();
    // Triangle 75
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.085 * resize, originy + 0.496 * resize);
    glVertex2f(originx + -0.012 * resize, originy + 0.395 * resize);
    glVertex2f(originx + 0.040 * resize, originy + 0.464 * resize);
    glEnd();
    // Triangle 76
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.037 * resize, originy + 0.526 * resize);
    glVertex2f(originx + -0.085 * resize, originy + 0.496 * resize);
    glVertex2f(originx + 0.040 * resize, originy + 0.464 * resize);
    glEnd();
    // Triangle 77
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + -0.012 * resize, originy + 0.395 * resize);
    glVertex2f(originx + 0.074 * resize, originy + 0.326 * resize);
    glVertex2f(originx + 0.040 * resize, originy + 0.464 * resize);
    glEnd();
    // Triangle 78
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.040 * resize, originy + 0.464 * resize);
    glVertex2f(originx + 0.143 * resize, originy + 0.439 * resize);
    glVertex2f(originx + 0.074 * resize, originy + 0.326 * resize);
    glEnd();
    // Triangle 79
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.074 * resize, originy + 0.326 * resize);
    glVertex2f(originx + 0.136 * resize, originy + 0.310 * resize);
    glVertex2f(originx + 0.143 * resize, originy + 0.439 * resize);
    glEnd();
    // Triangle 80
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.143 * resize, originy + 0.439 * resize);
    glVertex2f(originx + 0.239 * resize, originy + 0.457 * resize);
    glVertex2f(originx + 0.136 * resize, originy + 0.310 * resize);
    glEnd();
    // Triangle 81
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.136 * resize, originy + 0.310 * resize);
    glVertex2f(originx + 0.207 * resize, originy + 0.307 * resize);
    glVertex2f(originx + 0.239 * resize, originy + 0.457 * resize);
    glEnd();
    // Triangle 82
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.239 * resize, originy + 0.457 * resize);
    glVertex2f(originx + 0.396 * resize, originy + 0.561 * resize);
    glVertex2f(originx + 0.483 * resize, originy + 0.425 * resize);
    glEnd();
    // Triangle 83
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.483 * resize, originy + 0.425 * resize);
    glVertex2f(originx + 0.332 * resize, originy + 0.333 * resize);
    glVertex2f(originx + 0.239 * resize, originy + 0.457 * resize);
    glEnd();
    // Triangle 84
    glBegin(GL_TRIANGLES);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.332 * resize, originy + 0.333 * resize);
    glVertex2f(originx + 0.207 * resize, originy + 0.307 * resize);
    glVertex2f(originx + 0.239 * resize, originy + 0.457 * resize);
    glEnd();
    // Polygon 1
    glBegin(GL_POLYGON);
    glColor3f(OM_COLOR);
    glVertex2f(originx + 0.138 * resize, originy + 0.699 * resize);
    glVertex2f(originx + 0.024 * resize, originy + 0.577 * resize);
    glVertex2f(originx + 0.138 * resize, originy + 0.469 * resize);
    glVertex2f(originx + 0.259 * resize, originy + 0.586 * resize);
    glEnd();
}
