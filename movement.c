
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>

GLfloat angle = 0.0;

GLint key;

GLfloat Sx=1.0;
GLfloat Sy=1.0;
GLfloat Sz=1.0;

GLfloat tx=0.0;
GLfloat ty=0.0;
GLfloat tz=0.0;

GLfloat eyex=5.0;
GLfloat eyey=5.0;
GLfloat eyez=20.0;

GLfloat lookx=5.0;
GLfloat looky=5.0;
GLfloat lookz=0.0;

GLfloat gx=1.0;
GLfloat gy=1.0;
GLfloat gz=1.0;

GLfloat theta=45.0;
GLfloat phi=45.0;
GLfloat r=sqrt(20.0*20.0*3.0);
//diffuse light color variables
GLfloat dlr = 1.0;
GLfloat dlg = 1.0;
GLfloat dlb = 1.0;

//ambient light color variables
GLfloat alr = 1.0;
GLfloat alg = 1.0;
GLfloat alb = 1.0;

//light position variables
GLfloat lx = 7.5;
GLfloat ly = 4.0;
GLfloat lz = 7.5;
GLfloat lw = 1.0;

GLfloat density = 0.0;

GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};

void room(void)
{

     glColor4f(1.0,0.0,0.0,1.0);
     glBegin(GL_QUADS);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(15.0,0.0,0.0);
     glVertex3f(15.0,15.0,0.0);
     glVertex3f(0.0,15.0,0.0);

     glColor4f(0.0,0.0,1.0,1.0);
     glBegin(GL_QUADS);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(0.0,15.0,0.0);
     glVertex3f(0.0,15.0,15.0);
     glVertex3f(0.0,0.0,15.0);

    glColor4f(0.0,1.0,0.0,1.0);
     glBegin(GL_QUADS);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(15.0,0.0,0.0);
     glVertex3f(15.0,0.0,15.0);
     glVertex3f(0.0,0.0,15.0);


     glColor4f(1.0,1.0,0.0,1.0);
     glBegin(GL_QUADS);
     glVertex3f(15.0,0.0,0.0);
     glVertex3f(15.0,15.0,0.0);
     glVertex3f(15.0,15.0,15.0);
     glVertex3f(15.0,0.0,15.0);
glEnd();
}

void sphere()
{
    glTranslatef(7.5,4.0,7.5);
    //   GLfloat mat_specular[] = { 1.0, 1.0, 0.0, 1.0 };
   GLfloat mat_shininess[] = { 0.05,0.05,0.05,0.05 };

   // glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_shininess);
 //   glColor4f(1.0,1.0,0.0,1.0);
    glutSolidSphere(0.5,100,100);
}
void cube2(void)
{
    glScalef(Sx,Sy,Sz);
    glTranslatef(tx,ty,tz);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glRotatef(angle, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glutSolidCube(2);

}

void cube (void) {
    glScalef(Sx,Sy,Sz);
    glTranslatef(tx,ty,tz);

    glRotatef(angle, 0.0, 1.0, 0.0);
    glRotatef(angle, 1.0, 0.0, 0.0);
   // glRotatef(angle, 0.0, 0.0, 1.0);

glColor4f(1.0, 0.0, 0.0,0.5);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(0.5, 0.5,0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);

glColor4f(0.0, 1.0, 0.0,0.5);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);

glColor4f(0.0, 0.0, 1.0,0.5);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);

glColor4f(1.0, 1.0, 0.0,0.5);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);

glColor4f(1.0, 0.0, 1.0,0.5);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);

glColor4f(0.0, 1.0, 1.0,0.5);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(0.5, 0.5,0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(0.5, 0.5, 0.5);
glVertex3f(-0.5, -0.5, 0.5);
    glEnd();
}

/*void menudisp()
{
    printf("\n Straffing is implemented");
}
*/
void cube3 (void) {

    glScalef(Sx,Sy,Sz);
    glTranslatef(tx,ty,tz);



glColor4f(1.0, 1.0, 0.0, 1.0);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(gx-0.5, gy-0.5, gz+0.5);
glVertex3f(gx-0.5, gy+0.5, gz+0.5);
glVertex3f(gx+0.5, gy+0.5, gz+0.5);
glVertex3f(gx+0.5, gy-0.5, gz+0.5);

glColor4f(0.0, 1.0, 0.0, 1.0);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(gx-0.5, gy-0.5, gz-0.5);
glVertex3f(gx-0.5, gy+0.5, gz-0.5);
glVertex3f(gx+0.5, gy+0.5, gz-0.5);
glVertex3f(gx+0.5, gy-0.5, gz-0.5);

glColor4f(0.0, 0.0, 1.0 ,1.0);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(gx+0.5, gy-0.5, gz-0.5);
glVertex3f(gx+0.5, gy-0.5, gz+0.5);
glVertex3f(gx+0.5, gy+0.5, gz+0.5);
glVertex3f(gx+0.5, gy+0.5, gz-0.5);

glColor4f(1.0, 0.0, 0.0, 1.0);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(gx-0.5, gy-0.5, gz-0.5);
glVertex3f(gx-0.5, gy-0.5, gz+0.5);
glVertex3f(gx-0.5, gy+0.5, gz+0.5);
glVertex3f(gx-0.5, gy+0.5, gz-0.5);

glColor4f(1.0, 0.0, 1.0, 1.0);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(gx-0.5, gy+0.5, gz-0.5);
glVertex3f(gx+0.5, gy+0.5, gz-0.5);
glVertex3f(gx+0.5, gy+0.5, gz+0.5);
glVertex3f(gx-0.5, gy+0.5, gz+0.5);

glColor4f(0.0, 1.0, 1.0, 1.0);
glBegin(GL_QUADS); //begin the four sided shape
glVertex3f(gx-0.5, gy-0.5,gz-0.5);
glVertex3f(gx+0.5, gy-0.5, gz-0.5);
glVertex3f(gx+0.5, gy-0.5, gz+0.5);
glVertex3f(gx-0.5, gy-0.5, gz+0.5);
    glEnd();
}

void init (void) {
    glClearDepth(1);
    glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHTING);
  //  glColorMaterial ( GL_FRONT_AND_BACK, GL_DIFFUSE ) ;

    glEnable(GL_COLOR_MATERIAL);
    glEnable (GL_LIGHT0);
    glEnable (GL_LIGHT1);
   // glEnable(GL_FOG);
    glEnable(GL_BLEND);
    glShadeModel(GL_SMOOTH);
}

void display (void) {
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   //  GLfloat mat_shininess[] = { 50.0 };


/*GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat position[] = { -1.5f, 1.0f, -4.0f, 1.0f };
glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
glLightfv(GL_LIGHT0, GL_POSITION, position);
*/

    GLfloat DiffuseLight[] = {dlr, dlg, dlb}; //set DiffuseLight[] to the specified values
    GLfloat AmbientLight[] = {alr, alg, alb}; //set AmbientLight[] to the specified values
    glLightfv (GL_LIGHT0, GL_DIFFUSE, DiffuseLight); //change the light accordingly
   // glLightfv (GL_LIGHT1, GL_SPECULAR, AmbientLight); //change the light accordingly
    GLfloat LightPosition[] = {lx,ly,lz,lw}; //set the LightPosition to the specified values
   // GLfloat LightPosition2[] = {15.0, 15.0, 0.0, 1.0};
    glLightfv (GL_LIGHT0, GL_POSITION, LightPosition); //change the light accordingly
    //glLightfv (GL_LIGHT1, GL_POSITION, LightPosition2);
    //glFogi(GL_FOG_MODE, GL_EXP2);
    //glFogfv(GL_FOG_COLOR,fogColor);
    //glFogf (GL_FOG_DENSITY, density);
    //glFogf(GL_FOG_START, 1);
    //glHint(GL_FOG_HINT,GL_NICEST);


    gluLookAt(eyex,eyey,eyez,lookx,looky,lookz,0.0,1.0,0.0);

        //   cube2();

     room();
   //  sphere();
    cube3();

    glutSwapBuffers();
    angle=angle+0.05;

}


void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glEnable(GL_BLEND); //enable the blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //set the blend function
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode (GL_MODELVIEW);
}

void keyboard (unsigned char key, int x, int y) {
    if (key==114) {
        dlr = 1.0; //change light to red
        dlg = 0.0;
        dlb = 0.0;
    }
    if (key==103) {
        dlr = 0.0; //change light to green
        dlg = 1.0;
        dlb = 0.0;
    }
    if (key==98) {
        dlr = 0.0; //change light to blue
        dlg = 0.0;
        dlb = 1.0;
    }
    if (key=='z') {
        dlr=dlg=dlb=1.0;
    }
    if (key==119) {
        ly += 10.0; //move the light up
    }
    if (key==115) {
        ly -= 10.0; //move the light down
    }
    if (key==97) {
        lx -= 10.0; //move the light left
    }
    if (key==100) {
        lx += 10.0; //move the light right
    }
    if(key=='+') {
        Sx+=0.01;
        Sy+=0.01;
        Sz+=0.01;
    }
    if(key=='-') {
        Sx-=0.01;
        Sy-=0.01;
        Sz-=0.01;
    }
    if(key==108) {
        if(gx<=14.5)
        gx+=0.05;
    }
    if(key==106) {
        if(gx>=0.5)
        gx-=0.05;
    }
    if(key==107) {
        if(gy>=0.5)
        gy-=0.05;
    }
    if(key==105) {
        gy+=0.05;
    }
        if(key=='f') {
        ly+=0.05;
    }
    if(key=='h') {
        lx-=0.05;
    }
    if(key=='v') {
        ly-=0.05;
    }
    if(key=='t') {
        ly+=0.05;
    }
    if(key=='b') {
        lz+=0.15;
    }
    if(key=='n') {
        lz-=0.15;
    }
    if(key=='6') {
        eyex+=0.1;
        lookx+=0.1;
    }
    if(key=='4') {
        eyex-=0.1;
        lookx-=0.1;
    }
    if(key=='2') {
        eyez+=0.1;
        lookz+=0.1;
    }
    if(key=='8') {
        eyez-=0.1;
        lookz-=0.1;
    }
    if(key==99){
        eyez+=10.0;
        lookz+=10.0;
    }

}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize (1000, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("A basic OpenGL Window");
    init ();
    glutDisplayFunc (display);
    glutIdleFunc (display);
    //glutIdleFunc (cube2);
    glutReshapeFunc (reshape);
    glutKeyboardFunc (keyboard);
    glutMainLoop ();
    return 0;
}
