#include "glwidget.h"

glwidget::glwidget() : QGLWidget(){
    world = new World;
    resize(DEFAULTWIDTH,DEFAULTHEIGHT);
    SetPixelModif(DEFAULTWIDTH,DEFAULTHEIGHT);
}

glwidget::glwidget(const glwidget& SourceWidget) : QGLWidget(){
    world = SourceWidget.world;
}

glwidget& glwidget::operator =(const glwidget& SourceWidget){
    Delete();
    world = SourceWidget.world;
    return *this;
}

glwidget::~glwidget(){
    Delete();
}

void glwidget::initializeGL(){
    glClearColor(1, 1, 1, 0);
    glDisable(GL_DEPTH_TEST);
}

void glwidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = 0; i < MAXLENGTH + 2; i++){
        for(int j = 0; j < MAXHEIGHT + 2; j++){
            if(!(world -> Get(i,j))){
                DrawCreature(i,j,.96,.96,.96);
            }
            else if((world -> Get(i,j)) -> GetType() == WALLTYPE){
                DrawCreature(i,j,0,0,0);
            }
            else if((world -> Get(i,j)) -> GetType() == PREYTYPE){
                DrawCreature(i,j,0,.95,0);
            }
            else if((world -> Get(i,j)) -> GetType() == PREDATORTYPE){
                DrawCreature(i,j,.95,0,0);
            }
            else if((world -> Get(i,j)) -> GetType() == HUNTERTYPE){
                DrawCreature(i,j,0,0,.95);
            }
            else if((world -> Get(i,j)) -> GetType() == INFECTEDTYPE){
                DrawCreature(i,j,.44,.46,.44);
            }
        }
    }
}

void glwidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    SetPixelModif(w,h);
}

void glwidget::SetPixelModif(int w, int h){
    float mid = (w + h)/2.0;
    float cellMid = 4.0/(MAXHEIGHT + MAXLENGTH + 4);
    PixelSize = mid * PIXELCONSTANT * cellMid;
}

void glwidget::DrawCreature(int i, int j, float r, float g, float b){
    float cellHeight = 2.0/(MAXHEIGHT + 2), cellLength = 2.0/(MAXLENGTH + 2);
    glColor4f(r,g,b,0.9);
    glPointSize(PixelSize);
    glBegin(GL_POINTS);
        glVertex2f(-0.995 + (cellLength * i),-0.989 + (cellHeight * j));
    glEnd();
}

void glwidget::Delete(){
    delete world;
}

void glwidget::Reset(){
    Delete();
    world = new World;
}
