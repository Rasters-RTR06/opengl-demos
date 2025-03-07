# march24-opengl-demo

# OpenGL Drawing Project

This project demonstrates how to draw basic shapes using OpenGL, including polygons, triangles, and circles.

## Setup Instructions

1. Install OpenGL 
2. Clone this repository:
   ```bash
   git clone <repository_url>
   cd <repository_folder>
   ```
3. Compile and run the project:
   ```bash
   g++ main.cpp -o opengl_demo -lGL -lGLU -lglut
   ./opengl_demo
   ```

## Drawing Shapes in OpenGL

### 1. **Drawing a Triangle**
```cpp
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
```
This code creates a simple triangle.

### 2. **Drawing a Rectangle**
```cpp
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
```
This code defines a rectangle using four vertices.

### 3. **Drawing a Circle using `GL_POLYGON`**
```cpp
    glBegin(GL_POLYGON);
    glVertex2f(-0.150f, 0.640f); // Center
    glVertex2f(-0.150f + 0.05f, 0.640f);
    glVertex2f(-0.150f, 0.640f + 0.05f);
    glVertex2f(-0.150f - 0.05f, 0.640f);
    glVertex2f(-0.150f, 0.640f - 0.05f);
    glEnd();
```
This approximates a small circle at **(-0.150, 0.640)** with a radius of **0.05**.

## Contributing
1. Create a new branch:
   ```bash
   git checkout -b bheem
   ```
2. Make changes and commit:
   ```bash
   git add .
   git commit -m "Added new shapes"
   ```
3. Push changes:
   ```bash
   git push origin bheem
   ```

## License
This project is open-source and available for modification.

