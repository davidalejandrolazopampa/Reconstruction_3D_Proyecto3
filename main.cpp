/*********************************************/
#include "Principal.h"
/*********************************************/

int main(int argc, char** argv) {
    //Verificar error
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//glutD
    glutInitWindowPosition(720, 720);
    glutInitWindowSize(720, 720);
    glutCreateWindow("Cerebro-Craneo 3D");

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}