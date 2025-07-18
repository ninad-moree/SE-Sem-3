#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
typedef float Matrix_reloaded [4][4];
Matrix_reloaded theMatrix;
static GLfloat input[8][3]= {
    {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},
    {30,30,0},{80,30,0},{80,80,0},{30,80,0}
};

float output[8][3];
float tx,ty,tz;
float sx,sy,sz;
float angle;
int choice,choicex;

void setIdentityx(Matrix_reloaded m) {
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    m[i][j]=(i==j);
}

void translatxl(int tx,int ty,int tz) {
    for(int i=0;i<8;i++) {
        output[i][0]=input[i][0]+tx;
        output[i][1]=input[i][1]-ty;
        output[i][2]=input[i][2]+tz;
    }
}

void scalxl(int sx,int sy,int sz) {
    theMatrix[0][0]=sx;
    theMatrix[1][1]=sy;
    theMatrix[2][2]=sz;
}

void RotatXl(float angle) {
    angle = angle*3.142/180;
    theMatrix[1][1] = cos(angle);
    theMatrix[1][2] = -sin(angle);
    theMatrix[2][1] = sin(angle);
    theMatrix[2][2] = cos(angle);
}

void RotatYl(float angle) {
    angle = angle*3.14/180;
    theMatrix[0][0] = cos(angle);
    theMatrix[0][2] = -sin(angle);

    theMatrix[2][0] = sin(angle);
    theMatrix[2][2] = cos(angle);
}

void RotatZl(float angle) {
    angle = angle*3.14/180;
    theMatrix[0][0] = cos(angle);
    theMatrix[0][1] = sin(angle);
    theMatrix[1][0] = -sin(angle);
    theMatrix[1][1] = cos(angle);
}

void multiplyx() {
    for(int i=0;i<8;i++) {
        for(int j=0;j<3;j++) {
            output[i][j]=0;
            for(int k=0;k<3;k++)
                output[i][j]=output[i][j]+input[i][k]*theMatrix[k][j];
        }
    }
}

void Axes(void) {
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2s(-1000 ,0);
    glVertex2s( 1000 ,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2s(0 ,-1000);
    glVertex2s(0 , 1000);
    glEnd();
}

void drawingx(float a[8][3]) {
    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0.5);
    glVertex3fv(a[0]);
    glVertex3fv(a[1]);
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);
    glColor3f(0.8,0.2,0.4);
    glVertex3fv(a[0]);
    glVertex3fv(a[1]);
    glVertex3fv(a[5]);
    glVertex3fv(a[4]);
    glColor3f(0.3,0.6,0.7);
    glVertex3fv(a[0]);
    glVertex3fv(a[4]);
    glVertex3fv(a[7]);
    glVertex3fv(a[3]);
    glColor3f(0.2,0.8,0.2);
    glVertex3fv(a[1]);
    glVertex3fv(a[2]);
    glVertex3fv(a[6]);
    glVertex3fv(a[5]);

    glColor3f(0.7,0.7,0.2);
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);
    glVertex3fv(a[7]);
    glVertex3fv(a[6]);
    glColor3f(1.0,0.1,0.1);
    glVertex3fv(a[4]);
    glVertex3fv(a[5]);
    glVertex3fv(a[6]);
    glVertex3fv(a[7]);
    glEnd();
}

void init() {
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    Axes();
    glColor3f(1.0,0.0,0.0);
    drawingx(input);
    setIdentityx(theMatrix);
    switch(choice) {
        case 1:
            translatxl(tx,ty,tz);
            break;
        case 2:
            scalxl(sx,sy,sz);
            multiplyx();
            break;
        case 3:
            switch (choicex) {
            case 1:
            RotatXl(angle);
            break;
        case 2: RotatYl(angle);
            break;
        case 3:
            RotatZl(angle);
            break;
        default:
            break;
        }
        multiplyx();
        break;
    }
    drawingx(output);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1362,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Open gl 3d Transformations");

    init();
    cout<<"Enter your choice
    number:\n1.Translation\n2.Scaling\n3.Rotation\n=>";
    cin>>choice;

    switch (choice) {
        case 1:
            cout<<"\nEnter Tx,Ty &Tz: \n";
            cin>>tx>>ty>>tz;
            break;
        case 2:
            cout<<"\nEnter Sx,Sy & Sz: \n";
            cin>>sx>>sy>>sz;
            break;
        case 3:
            cout<<"Enter your choice for Rotation about axis:\n1.parallel to X-axis."
            <<"(y& z)\n2.parallel to Y-axis.(x& z)\n3.parallel to Z-axis."
            <<"(x& y)\n =>";
            cin>>choicex;
            switch (choicex) {
                case 1:
                    cout<<"\nENter Rotation angle: ";
                    cin>>angle;
                    break;
                case 2:
                    cout<<"\nENter Rotation angle: ";
                    cin>>angle;
                    break;
                case 3:
                    cout<<"\nENter Rotation angle: ";
                    cin>>angle;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}