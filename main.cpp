/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */
GLint walkX=0,walkY=0;

void Boat(double x,double y,double z,double a){
glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(2,1,slices,stacks);
    glPopMatrix();
}
void Foot(double x,double y,double z){
 glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,0,0);
        glutSolidCube(2);
    glPopMatrix();

}

void Leg(double x,double y,double z,double a){
        glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,0,0);
        glRotated(a,0,0,1);
        gluCylinder(gluNewQuadric(),.5,.5,7,slices,stacks);
    glPopMatrix();

}
void Body(double x,double y,double z){
glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,0,0);
        glutSolidCube(10);

    glPopMatrix();
}

void Nose(double x,double y,double z,double a){
glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,0,0);
        glRotated(a,1,0,0);
        glutSolidOctahedron();
    glPopMatrix();
}
void Eye(double x,double y,double z,double a){
 glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,0,0);
        glScalef(1.5,1.5,1.5);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
    glPopMatrix();
}
void Mouth(double x,double y,double z,double a){
    glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,1,10);
        glRotated(a,0,0,1);
        glutSolidTorus(.25,1,slices,stacks);
    glPopMatrix();
}
void Cap(double x,double y,double z){
glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(-1.25,8,-30);
        glRotated(90,1,0,0);
        glScalef(5.5,5,6);
        glutSolidOctahedron();

        glPopMatrix();
}
void ShoulderTemp(double x,double y,double z,double a){
glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,10,1);
        glRotated(a,0,0,1);
         gluCylinder(gluNewQuadric(),.5,.5,10,slices,stacks);
    glPopMatrix();


}
void Shoulder(double x,double y,double z,double a){
glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,0,0);
        glutSolidCube(3);
    glPopMatrix();

}
void Arm(double x,double y,double z,double a){
glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,0,0);
        glRotated(a,0,0,1);
        gluCylinder(gluNewQuadric(),.5,.5,7,slices,stacks);
    glPopMatrix();
}

void Hand(double x,double y,double z,double a){
glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(x,y,z);
        glRotated(90,1,0,0);
        glRotated(a,0,0,1);
        glScalef(2,2,2);
        glutSolidIcosahedron();
    glPopMatrix();

}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(walkX,-1,walkY);

        Boat(2.5,-10,-30,a);
        Boat(-5.5,-10,-30,a);

        Foot(2.5,-7,-30);
        Foot(-5.5,-7,-30);

        Leg(2.5,.5,-30,a);
        Leg(-5.5,.5,-30,a);

        Body(-1.25,5,-30);

        Nose(-1.25,5,-25,a);

        Eye(1,8,-25,a);
        Eye(-3.5,8,-25,a);

        Mouth(-1.2,2,-24,a);

        Cap(-1.25,8,-30);

        ShoulderTemp(-10,6,-28,a);
        ShoulderTemp(-3,6,-28,a);

        Shoulder(7.8,6,-28,a);
        Shoulder(-10.8,6,-28,a);

        Arm(8,5,-28,a);
        Arm(-11,5,-28,a);

        Hand(-11,-2,-28,a);
        Hand(8,-2,-28,a);


glPopMatrix();

    glutSwapBuffers();
}
void walk(int key,int x,int y)                                      //change positions using arrow keys
{
    if(key==GLUT_KEY_UP)    walkY+=1;
    if(key==GLUT_KEY_DOWN)  walkY-=1;
    if(key==GLUT_KEY_RIGHT) walkX+=1;
    if(key==GLUT_KEY_LEFT)  walkX-=1;

}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
     glutSpecialFunc(walk);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
