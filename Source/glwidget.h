#ifndef GLWIDGET_H
#define GLWIDGET_H
#include "world.h"
#include <QGLWidget>

class glwidget : public QGLWidget{
    Q_OBJECT
    friend class Window;
public:
    glwidget();
    glwidget(const glwidget& SourceWidget);
    glwidget& operator =(const glwidget& SourceWidget);
    ~glwidget();
    void initializeGL();

    void resizeGL(int w, int h);
    void Reset();
        World* world;
signals:
public slots:
            void paintGL();
private:

    float PixelSize;
    void SetPixelModif(int w, int h);
    void DrawCreature(int i, int j, float r, float g, float b);
    void Delete();
};

#endif // GLWIDGET_H
