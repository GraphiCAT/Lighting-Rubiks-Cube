#include "Cell.h"
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h


Cell::Cell(const Cell& c){
    color = c.color;
    location = c.location;
    normal = c.normal;
}

Cell::Cell(int _color, Point3D _location, Point3D _normal){
    color = _color;
    location = _location;
    normal = _normal;
}

Cell::~Cell(){
}

int Cell::getColor(){
    return color;
}

void Cell::setColor(int _color){
    color = _color;
}

Point3D Cell::getLocation(){
    return location;
}

void Cell::setLocation(Point3D _location){
    location = _location;
}

Point3D Cell::getNormal(){
    return normal;
}

void Cell::setNormal(Point3D _normal){
    normal = _normal;
}
void Cell::setColor(){
    // Set color properties
    GLfloat clRed[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat clGreen[] = {0.0, 1.0, 0.0, 1.0};
    GLfloat clWhite[] = {1.0, 0.0, 1.0, 1.0};
    GLfloat clBlue[] = {0.0, 0.0, 1.0, 1.0};
    GLfloat clOrange[] = {1.0, 0.5, 0.0, 1.0};
    GLfloat clYellow[] = {1.0, 1.0, 0.0, 1.0};
    GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};

    if(color == RED){
        glMaterialfv(GL_FRONT, GL_AMBIENT, clRed);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clRed);
        glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
        glMaterialf(GL_FRONT, GL_SHININESS, 60.0);
    } else if(color == GREEN){
        glMaterialfv(GL_FRONT, GL_AMBIENT, clGreen);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clGreen);
        glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
        glMaterialf(GL_FRONT, GL_SHININESS, 60.0);
    } else if(color == WHITE){
        glMaterialfv(GL_FRONT, GL_AMBIENT, clWhite);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clWhite);
        glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
        glMaterialf(GL_FRONT, GL_SHININESS, 60.0);
    } else if(color == BLUE){
        glMaterialfv(GL_FRONT, GL_AMBIENT, clBlue);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clBlue);
        glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
        glMaterialf(GL_FRONT, GL_SHININESS, 60.0);
    } else if(color == ORANGE){
        glMaterialfv(GL_FRONT, GL_AMBIENT, clOrange);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clOrange);
        glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
        glMaterialf(GL_FRONT, GL_SHININESS, 60.0);
    } else if(color == YELLOW){
        glMaterialfv(GL_FRONT, GL_AMBIENT, clYellow);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clYellow);
        glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
        glMaterialf(GL_FRONT, GL_SHININESS, 60.0);
    }
}

int Cell::getFace(){
    Point3D top(0,-1,0);
    Point3D bottom(0,1,0);
    Point3D right(1,0,0);
    Point3D left(-1,0,0);
    Point3D behind(0,0,-1);
    Point3D infront(0,0,1);
    if (normal.isEquals(top)) {
        return 0;
    } else if (normal.isEquals(bottom)) {
        return 1;
    } else if (normal.isEquals(right)) {
        return 2;
    } else if (normal.isEquals(left)) {
        return 3;
    } else if (normal.isEquals(behind)) {
        return 4;
    } else if (normal.isEquals(infront)) {
        return 5;
    }
}


void Cell::drawCell() {
    float size = 0.9f;
    float blackspace = 1.0f;
    float x = location.getX()*2.25;
    float y = location.getY()*2.25;
    float z = location.getZ()*2.25;
    GLfloat clBlack[] = {0.0, 0.0, 0.0, 1.0};


  //glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

    glBegin(GL_QUADS);		// Draw The Cube Using quads
    glNormal3f((GLfloat)normal.getX(),(GLfloat)normal.getY(),(GLfloat)normal.getZ());
    if (getFace() == 0) {
        //glNormal3f(0.0f,-1.0f,0.0f);
        glMaterialfv(GL_FRONT, GL_AMBIENT, clBlack);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clBlack);
        glVertex3f(x+blackspace, y+blackspace, z-blackspace);	// Top Right Of The Quad (Top)
        glVertex3f(x-blackspace, y+blackspace, z-blackspace);	// Top Left Of The Quad (Top)
        glVertex3f(x-blackspace, y+blackspace, z+blackspace);	// Bottom Left Of The Quad (Top)
        glVertex3f(x+blackspace, y+blackspace, z+blackspace);	// Bottom Right Of The Quad (Top)
        glEnd();

        glBegin(GL_QUADS);		// Draw The Cube Using quads
        setColor();
        //glNormal3f(0.0f,-1.0f,0.0f);
        glNormal3f((GLfloat)normal.getX(),(GLfloat)normal.getY(),(GLfloat)normal.getZ());
        glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Top)
        glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Top)
        glVertex3f(x-size, y+size, z+size);	// Bottom Left Of The Quad (Top)
        glVertex3f(x+size, y+size, z+size);	// Bottom Right Of The Quad (Top)

    } else if (getFace() == 1) {
        //glNormal3f(0.0f,1.0f,0.0f);
        glMaterialfv(GL_FRONT, GL_AMBIENT, clBlack);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clBlack);
        glVertex3f(x+blackspace, y-blackspace, z+blackspace);	// Top Right Of The Quad (Bottom)
        glVertex3f(x-blackspace, y-blackspace, z+blackspace);	// Top Left Of The Quad (Bottom)
        glVertex3f(x-blackspace, y-blackspace, z-blackspace);	// Bottom Left Of The Quad (Bottom)
        glVertex3f(x+blackspace, y-blackspace, z-blackspace);	// Bottom Right Of The Quad (Bottom)
        glEnd();

        glBegin(GL_QUADS);		// Draw The Cube Using quads
        setColor();
        //glNormal3f(0.0f,1.0f,0.0f);
        glNormal3f((GLfloat)normal.getX(),(GLfloat)normal.getY(),(GLfloat)normal.getZ());
        glVertex3f(x+size, y-size, z+size);	// Top Right Of The Quad (Bottom)
        glVertex3f(x-size, y-size, z+size);	// Top Left Of The Quad (Bottom)
        glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Bottom)
        glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Bottom)
    } else if (getFace() == 2) {
        //glNormal3f(1.0f,0.0f,0.0f);
        glMaterialfv(GL_FRONT, GL_AMBIENT, clBlack);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clBlack);
        glVertex3f(x+blackspace-0.2, y+blackspace, z-blackspace);	// Top Right Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y+blackspace, z+blackspace);	// Top Left Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y-blackspace, z+blackspace);	// Bottom Left Of The Quad (Right)
        glVertex3f(x+blackspace-0.2, y-blackspace, z-blackspace);	// Bottom Right Of The Quad (Right)
        glEnd();

        glBegin(GL_QUADS);		// Draw The Cube Using quads
        setColor();
        //glNormal3f(1.0f,0.0f,0.0f);
        glNormal3f((GLfloat)normal.getX(),(GLfloat)normal.getY(),(GLfloat)normal.getZ());
        glVertex3f(x+size, y+size, z-size);	// Top Right Of The Quad (Right)
        glVertex3f(x+size, y+size, z+size);	// Top Left Of The Quad (Right)
        glVertex3f(x+size, y-size, z+size);	// Bottom Left Of The Quad (Right)
        glVertex3f(x+size, y-size, z-size);	// Bottom Right Of The Quad (Right)
    } else if (getFace() == 3) {
        //glNormal3f(-1.0f,0.0f,0.0f);
        glMaterialfv(GL_FRONT, GL_AMBIENT, clBlack);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clBlack);
        glVertex3f(x-blackspace+0.2, y+blackspace, z+blackspace);	// Top Right Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y+blackspace, z-blackspace);	// Top Left Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y-blackspace, z-blackspace);	// Bottom Left Of The Quad (Left)
        glVertex3f(x-blackspace+0.2, y-blackspace, z+blackspace);	// Bottom Right Of The Quad (Left)
        glEnd();

        glBegin(GL_QUADS);		// Draw The Cube Using quads
        setColor();
        glNormal3f(-1.0f,0.0f,0.0f);
        //glNormal3f((GLfloat)normal.getX(),(GLfloat)normal.getY(),(GLfloat)normal.getZ());
        glVertex3f(x-size, y+size, z+size);	// Top Right Of The Quad (Left)
        glVertex3f(x-size, y+size, z-size);	// Top Left Of The Quad (Left)
        glVertex3f(x-size, y-size, z-size);	// Bottom Left Of The Quad (Left)
        glVertex3f(x-size, y-size, z+size);	// Bottom Right Of The Quad (Left)
    } else if (getFace() == 4) {
        //glNormal3f(0.0f,0.0f,-1.0f);
        glMaterialfv(GL_FRONT, GL_AMBIENT, clBlack);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clBlack);
        glVertex3f(x+blackspace, y-blackspace, z-blackspace+0.2);	// Top Right Of The Quad (Back)
        glVertex3f(x-blackspace, y-blackspace, z-blackspace+0.2);	// Top Left Of The Quad (Back)
        glVertex3f(x-blackspace, y+blackspace, z-blackspace+0.2);	// Bottom Left Of The Quad (Back)
        glVertex3f(x+blackspace, y+blackspace, z-blackspace+0.2);	// Bottom Right Of The Quad (Back)
        glEnd();

        glBegin(GL_QUADS);		// Draw The Cube Using quads
        setColor();
        glNormal3f(0.0f,0.0f,-1.0f);
        glNormal3f((GLfloat)normal.getX(),(GLfloat)normal.getY(),(GLfloat)normal.getZ());
        glVertex3f(x+size, y-size, z-size);	// Top Right Of The Quad (Back)
        glVertex3f(x-size, y-size, z-size);	// Top Left Of The Quad (Back)
        glVertex3f(x-size, y+size, z-size);	// Bottom Left Of The Quad (Back)
        glVertex3f(x+size, y+size, z-size);	// Bottom Right Of The Quad (Back)
    } else if (getFace() == 5) {
        //glNormal3f(0.0f,0.0f,1.0f);
        glMaterialfv(GL_FRONT, GL_AMBIENT, clBlack);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, clBlack);
        glVertex3f(x+blackspace, y+blackspace, z+blackspace-0.2);	// Top Right Of The Quad (Front)
        glVertex3f(x-blackspace, y+blackspace, z+blackspace-0.2);	// Top Left Of The Quad (Front)
        glVertex3f(x-blackspace, y-blackspace, z+blackspace-0.2);	// Bottom Left Of The Quad (Front)
        glVertex3f(x+blackspace, y-blackspace, z+blackspace-0.2);	// Bottom Right Of The Quad (Front)
        glEnd();

        glBegin(GL_QUADS);		// Draw The Cube Using quads
        setColor();
        //glNormal3f(0.0f,0.0f,1.0f);
        glNormal3f((GLfloat)normal.getX(),(GLfloat)normal.getY(),(GLfloat)normal.getZ());
        glVertex3f(x+size, y+size, z+size);	// Top Right Of The Quad (Front)
        glVertex3f(x-size, y+size, z+size);	// Top Left Of The Quad (Front)
        glVertex3f(x-size, y-size, z+size);	// Bottom Left Of The Quad (Front)
        glVertex3f(x+size, y-size, z+size);	// Bottom Right Of The Quad (Front)
    }
    glEnd();
}
