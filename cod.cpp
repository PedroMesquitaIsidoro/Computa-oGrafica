#include <iostream>
#include <GL/glut.h>

using namespace std;

GLsizei winWidth = 400,
        winHeight = 300;

void init(void)
{
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0, 200.0, 0.0, 150.0, -1.0, 1.0);
}

void displayFcn(void)
{
    //limpa o display
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(10.0);

    glFlush();
}

void plotPoint(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
    {
        int x1 = xMouse;
        int y1 = winHeight - yMouse;
        plotPoint(x1, y1);

        cout << "x1 da funcao" << x1 << endl;
        cout << "y1 da funcao" << y1 << endl;
    }

    glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight), -1.0, 1.0);
    winWidth = newWidth;
    winHeight = newHeight;
    glFlush();
}

int main(int argc, char **argv)
{
    //estabelece a contato com o sistema de janelas
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Pontos usando mouse");

    // Define os parâmetros de Rendering
    init();

    //Desenha o Objeto
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(winReshapeFcn);
    glutMouseFunc(mousePtPlot);

    //Controle de Callbacks
    glutMainLoop();
}
//g++ nomeArq.cpp -o nomeExc -lGL -lGLU -lglut