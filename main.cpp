/*********************************************/
#include "point.h"
/*********************************************/
#define WIDTH 1000
#define HEIGHT 1000
/*********************************************/
Point Point_IMG;
GLfloat Xmouse,Ymouse;
GLfloat MATRIXX[16] = {1, 0, 0, 0,
                       0, 1, 0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1};

void IMG_PUNTOS(){
    for(auto &it : Point_IMG.picture_)it.display();
    Point procesadorImagenes;
    //Point_IMG.verPicture("../IMG/img.txt", 100);
    Point_IMG.verPicture("../IMG/img_brain.txt", 100);
    //Point_IMG.verPicture("../IMG/img_new.txt", 100);
    cout<<"Se lee las images"<<endl;

    Point_IMG.point_out(7.0);
    Point_IMG.guardar_point("../IMG/puntos.txt");
    //Cargar
    Point_IMG.load_file("../IMG/puntos.txt");
}

void Reshape(int width, int height) {
    float range = (float)width/0.4;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((float)-width, (float)width, (float)-height, (float)height, -range, range);
    glMatrixMode(GL_MODELVIEW);
}

void vista() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POINTS);
    for (auto &img : Point_IMG.point_) {
        for (auto &point : img) {
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(point.x_, point.y_, point.z_);
        }
    }
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void MOve(int x, int y) {
    GLint Width = glutGet(GLUT_WINDOW_WIDTH);
    GLint Height = glutGet(GLUT_WINDOW_HEIGHT);

    auto rayo = (Width > Height) ? ((GLfloat)Width * (GLfloat)Width / 2) : ((GLfloat)Height * (GLfloat)Height / 2);
    //Origen
    Xmouse -= (GLfloat)Width / 2;
    GLfloat posicionX = (GLfloat)x - (GLfloat)Width / 2;
    Ymouse = (GLfloat)Height / 2 - Ymouse;
    GLfloat Ymouse = (GLfloat)Height / 2 - (GLfloat)y;

    // Other Z
    GLfloat cuadradoMouse = pow(Xmouse,2) + pow(Ymouse,2);
    GLfloat cuadradoPosicion = pow(Xmouse,2) + pow(Ymouse,2);

    if (cuadradoMouse < rayo && cuadradoPosicion < rayo) {
        GLfloat posicionMouseZ = sqrt(rayo - cuadradoMouse);
        GLfloat Zmouse = sqrt(rayo - cuadradoPosicion);

        GLfloat Vector_Giro[3];
        Vector_Giro[0] = -posicionMouseZ * Ymouse + Ymouse * Zmouse;
        Vector_Giro[1] = posicionMouseZ * posicionX - Xmouse * Zmouse;
        Vector_Giro[2] = -Ymouse * posicionX + Xmouse * Ymouse;

        GLfloat anguloRotacion = atan(sqrt( pow(Vector_Giro[0],2) + pow(Vector_Giro[0],1) + pow(Vector_Giro[2],2)));

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(anguloRotacion, Vector_Giro[0], Vector_Giro[1], Vector_Giro[2]);
        glMultMatrixf(MATRIXX);
        glGetFloatv(GL_MODELVIEW_MATRIX, MATRIXX);
    }
    Xmouse = (GLfloat)x;
    Ymouse = (GLfloat)y;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    cout << "INICIO-Main" << endl;
    IMG_PUNTOS();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    int POS_X = (glutGet(GLUT_SCREEN_WIDTH) - WIDTH) >> 1;
    int POS_Y = (glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) >> 1;
    glutInitWindowPosition(POS_X, POS_Y);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Proyecto3_Lazo");
    glutReshapeFunc(Reshape);
    glutDisplayFunc(vista);
    glutMotionFunc(MOve);
    glEnable(GL_DEPTH_TEST);
    glPointSize(1.0);
    glutMainLoop();

    cout << "FIN-Main" << endl;
    return 0;
}