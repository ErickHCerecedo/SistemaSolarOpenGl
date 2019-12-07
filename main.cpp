//
//  main.cpp
//  SistemaSolarErick
//
//  Created by Erick de Jesus Hernandez Cerecedo on 11/12/19.
//  Copyright © 2019 Erick de Jesus Hernandez Cerecedo. All rights reserved.
//

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "math.h"

//GLfloat anguloSolX = 0.0f;
GLfloat anguloSol = 0.0f;

GLfloat anguloMercurio = 0.0f;
GLfloat anguloVenus = 0.0f;
GLfloat anguloTierra = 0.0f;
GLfloat anguloMarte = 0.0f;
GLfloat anguloJupiter = 0.0f;
GLfloat anguloSaturno = 0.0f;
GLfloat anguloUrano = 0.0f;
GLfloat anguloNeptuno = 0.0f;
GLfloat anguloPluton = 0.0f;


GLfloat anguloLuna = 0.0f;

GLint ancho, alto;
int hazPerspectiva = 1;

//Variables para definir la posicion del observador
//gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z)
float EYE_X=0.0;
float EYE_Y=40.0;
float EYE_Z=80.0;
float CENTER_X=0;
float CENTER_Y=0;
float CENTER_Z=0;
float UP_X=0;
float UP_Y=1;
float UP_Z=0;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if(hazPerspectiva)
  gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 200.0f);
  else
  glOrtho(-6, 6, -6, 6, 1, 20);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
  ancho = width;
  alto = height;
}

void AnilloS(int sides, double radius)
{

    glBegin(GL_LINE_LOOP);
      for (int a = 0; a < 360; a += 360 / sides)
      {
        double heading = a * 3.1415926535897932384626433832795 / 180;
        glVertex3d(cos(heading) * radius, 0, sin(heading) * radius);
      }
    glEnd();
}

void AnilloSol(int sides, double radius)
{

    glBegin(GL_LINE_LOOP);
      for (int a = 0; a < 360; a += 360 / sides)
      {
        double heading = a * 3.1415926535897932384626433832795 / 180;
        glVertex3d(cos(heading) * radius, sin(heading) * radius, 0);
      }
    glEnd();
}

void Sol()
{
  glPushMatrix();
  glRotatef(90, 1.0f, 0.0f, 0.0f);
  glRotatef(anguloSol, 0.0f, 0.0f, 1.0f);
  glColor3f(0.953, 0.624, 0.094);
  glutWireSphere(5.0f,20,20);
    glColor3f(0.682, 0.714, 0.69);
    AnilloSol(20, 8);
    AnilloSol(25, 16);
    AnilloSol(30, 24);
    AnilloSol(35, 32);
    AnilloSol(40, 40);
    AnilloSol(45, 48);
    AnilloSol(50, 56);
    AnilloSol(55, 64);
    AnilloSol(60, 72);
  glPopMatrix();
}

void Mercurio()
{
  glPushMatrix();
  glRotatef(anguloMercurio,0,1,0); //Angulos de Rotacion
  glTranslatef(8,0.0,0.0);     //Distanciamiento del Eje
  glColor3f(0.467, 0.663, 0.722);        //Color
  glutWireSphere(1.0f,10,10);
  glPopMatrix();
}

void Venus()
{
  glPushMatrix();
  glRotatef(anguloVenus,0,1,0); //Angulos de Rotacion
  glTranslatef(16,0.0,0.0);     //Distanciamiento del Eje
  glColor3f(0.545, 0.49, 0.51);        //Color
  glutWireSphere(2.0f,10,10);
  //LunaTierra();
  glPopMatrix();
}

void LunaTierra()
{
  glPushMatrix();
  glRotatef(anguloLuna,0,1,0);
  glTranslatef(4,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glutWireSphere(0.5f,10,10);
  glPopMatrix();
}

void Tierra()
{
  glPushMatrix();
  glRotatef(anguloTierra,0,1,0); //Angulos de Rotacion
  glTranslatef(24,0.0,0.0);     //Distanciamiento del Eje
  glColor3f(0.0,0.0,1.0);        //Color
  glutWireSphere(2.5f,10,10);
  LunaTierra();
  glPopMatrix();
}

void LunaMarte_1()
{
  glPushMatrix();
  glRotatef(anguloLuna,0,1,0);
  glTranslatef(4,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glutWireSphere(0.5f,10,10);
  glPopMatrix();
}

void LunaMarte_2()
{
  glPushMatrix();
  glRotatef(anguloLuna,0,0,1);
  glTranslatef(4.0,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glutWireSphere(0.5f,10,10);
  glPopMatrix();
}

void Marte()
{
  glPushMatrix();
  glRotatef(anguloMarte,0,1,0); //Angulos de Rotacion
  glTranslatef(32,0.0,0.0);     //Distanciamiento del Eje
  glColor3f(1.0, 0.0, 0.0);        //Color
  glutWireSphere(1.5f,10,10);
  LunaMarte_2();
  LunaMarte_1();
  glPopMatrix();
}

void LunaJupiter_1()
{
  glPushMatrix();
  glRotatef(anguloJupiter,0,1,0);
  glTranslatef(5,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glutWireSphere(0.5f,10,10);
  glPopMatrix();
}

void LunaJupiter_2()
{
  glPushMatrix();
  glRotatef(anguloJupiter,0,0,1);
  glTranslatef(5.0,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glutWireSphere(0.5f,10,10);
  glPopMatrix();
}

void Jupiter()
{
  glPushMatrix();
  glRotatef(anguloJupiter,0,1,0); //Angulos de Rotacion
  glTranslatef(40,0.0,0.0);     //Distanciamiento del Eje
  glColor3f(0.545, 0.247, 0.286);        //Color
  glutWireSphere(3.5f,10,10);
  LunaJupiter_1();
  LunaJupiter_2();
  glPopMatrix();
}

void LunaSaturno_1()
{
  glPushMatrix();
  glRotatef(anguloSaturno,0,1,0);
  glTranslatef(5,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glutWireSphere(0.5f,10,10);
  glPopMatrix();
}

void LunaSaturno_2()
{
  glPushMatrix();
  glRotatef(anguloSaturno,0,0,1);
  glTranslatef(5.0,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glutWireSphere(0.5f,10,10);
  glPopMatrix();
}

void LunaSaturno_3()
{
  glPushMatrix();
  glRotatef(anguloSaturno,0,4,4);
  glTranslatef(5,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glutWireSphere(0.5f,10,10);
  glPopMatrix();
}

void Saturno()
{
  glPushMatrix();
  glRotatef(anguloSaturno,0,1,0); //Angulos de Rotacion
  glTranslatef(48,0.0,0.0);     //Distanciamiento del Eje
  glColor3f(0.482, 0.565, 0.627);        //Color
  glutWireSphere(3.0f,10,10);
    AnilloS(10, 4.5);
    AnilloS(15, 4.6);
    AnilloS(10, 4.7);
    AnilloS(15, 4.8);
    AnilloS(10, 4.9);
  LunaSaturno_1();
  LunaSaturno_2();
  LunaSaturno_3();
  glPopMatrix();
}

void Urano()
{
  glPushMatrix();
  glRotatef(anguloUrano,0,1,0); //Angulos de Rotacion
  glTranslatef(56,0.0,0.0);     //Distanciamiento del Eje
  glColor3f(0.224, 0.235, 0.239);        //Color
  glutWireSphere(2.7f,10,10);
    AnilloS(10, 3.4);
    AnilloS(15, 3.5);
    AnilloS(10, 3.6);
    AnilloS(15, 3.7);
    AnilloS(10, 3.8);
    AnilloS(15, 3.9);
    AnilloS(10, 4);
  //LunaTierra();
  glPopMatrix();
}

void Neptuno()
{
  glPushMatrix();
  glRotatef(anguloNeptuno,0,1,0); //Angulos de Rotacion
  glTranslatef(64,0.0,0.0);     //Distanciamiento del Eje
  glColor3f(0, 0.145, 0.42);        //Color
  glutWireSphere(2.7f,10,10);
  AnilloS(10, 3.4);
  AnilloS(15, 3.6);
  AnilloS(10, 3.8);
  glPopMatrix();
}

void LunaPluton()
{
  glPushMatrix();
  glRotatef(anguloLuna,0,1,0);
  glTranslatef(4,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glutWireSphere(0.5f,10,10);
  glPopMatrix();
}

void Pluton()
{
  glPushMatrix();
  glRotatef(anguloPluton,0,1,0); //Angulos de Rotacion
  glTranslatef(72,0.0,0.0);     //Distanciamiento del Eje
  glColor3f(0.812, 0.839, 0.843);        //Color
  glutWireSphere(1.0f,10,10);
  LunaPluton();
  glPopMatrix();
}

static void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0f, 0.0f, 0.0f);
  Sol();
  Mercurio();
  Venus();
  Tierra();
    Marte();
    Jupiter();
    Saturno();
    Urano();
    Neptuno();
    Pluton();


  glutSwapBuffers();

  anguloSol+=0.1f;

  anguloMercurio+=0.8f;
  anguloVenus+=0.7f;
  anguloTierra+=0.6f;
  anguloMarte+=0.5f;
  anguloJupiter+=0.4f;
  anguloSaturno+=0.3f;
  anguloUrano+=0.2f;
  anguloNeptuno+=0.1f;
  anguloPluton+=0.08f;

  anguloLuna+=1.0f;

}

void init()
{
  glClearColor(0.063, 0.071, 0.075, 1);
  glEnable(GL_DEPTH_TEST);
  ancho = 1500;
  alto = 700;
}

void idle()
{
  display();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
      case 'p':
      case 'P':
        hazPerspectiva=1;
        resize(ancho,alto);
        break;

      case 'o':
      case 'O':
        hazPerspectiva=0;
        resize(ancho,alto);
        break;

      case 27:   // escape
        exit(0);
        break;
    }
}

/* Program entry point */

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(1500, 700);
  glutCreateWindow("Planetario");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutIdleFunc(idle);
  glutKeyboardFunc(key);
  glutMainLoop();
  return 0;
}
