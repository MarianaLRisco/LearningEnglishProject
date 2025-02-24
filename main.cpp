#include <gl\glut.h>
#include <iostream>

using namespace std;

GLUquadricObj *p = gluNewQuadric();

///VARIABLES GLOBALES
float anguloTronco = 90;
float anguloBrazo1 = 0;
float anguloAntebrazo1 = 0;
float anguloMano1 = 0;
float anguloMenique1 = 2;
float anguloIndice1 = 0;
float anguloAnular1 = 0;
float anguloBrazo2 = 0;
float anguloAntebrazo2 = 0;
float anguloMano2 = 0;
float anguloMenique2 = 2;
float anguloIndice2 = 0;
float anguloAnular2 = 0;
float anguloPierna1 =0;
float anguloPantorrilla1 = 0;
float anguloPie1 = 90;
float anguloPierna2 = 0;
float anguloPantorrilla2 = 0;
float anguloPie2 = 90;
bool f = true, f1 = true, f2=true, f3 = true ;

///ILUMINACI�N
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 5.0f, 0.0f, 3.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


///SPOTLIGHT
const GLfloat light1_ambient[ ]={0.2f, 0.2f, 0.2f, 1.0f};
const GLfloat light1_diffuse[ ]={1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light1_specular[ ]={1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light1_position[ ]={-2.0f, 2.0f, 1.0f, 1.0f};
const GLfloat spot_direction[ ]={-1.0f, -1.0f, 0.0f};

const GLfloat mat1_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat1_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat1_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high1_shininess[] = { 100.0f };

/// VARIABLES PARA LA C�MARA
float aX = 0,aZ = 30,cX = 50.25, cY = 12, cZ = 30, x = 12, z = 11;
bool b = true, b1 = true;

void inicializar()
{
    glClearColor(0.5,1,0.7,0.1);
    glEnable(GL_DEPTH_TEST);
    gluQuadricDrawStyle(p,GLU_FILL);
}

void graficarEjes()
{
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(40,0,0);

        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,40,0);

        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,40);
    glEnd();
}

void graficar()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(cX, cY, cZ, 6, 6, 7, 0, 1, 0); /// Mover c�mara

    graficarEjes();

    ///HUMANOIDE
    //-------------------------------------------------------------------------------------------------------
    glPushMatrix();
    glTranslated(aX,8,aZ);
        ///Tronco
        glTranslatef(0,1,-4);
        glColor3f(0,0,0);
        glRotated(anguloTronco,1,0,0);
        gluCylinder(p,2,2,6,15,16);
     //-----------------------------
        glPushMatrix();
            ///Cabeza
            glColor3f(0,1,0);
            glTranslatef(0,0,-2);
            glutSolidSphere(2,16,16);
            glColor3f(0,0,0);
            glTranslatef(1.1,-1.4,0);
            glutSolidSphere(0.5,12,12);
            glTranslatef(0.8,1,0);
            glutSolidSphere(0.5,12,12);
        glPopMatrix();
     //-------------------------------
        glPushMatrix();
         ///Brazo Izquierdo
            glColor3f(1,1,0);
            glTranslatef(1.5,2,0.6);
            glRotatef(anguloBrazo1,0,1,0);
            glutSolidSphere(0.6,16,16);
            glColor3f(1,0,0);
            glTranslatef(0,0.1,0.2);
            gluCylinder(p,0.6,0.5,3,12,12);
            //-------------------------------
            glPushMatrix();
                ///Antebrazo Izquierdo
                glColor3f(1,1,0);
                glTranslatef(0,0,3);
                glRotatef(anguloAntebrazo1,0,1,0);
                glutSolidSphere(0.4,16,16);
                glColor3f(1,0,1);
                gluCylinder(p,0.5,0.5,2.6,12,12);
                //-------------------------------
                glPushMatrix();
                    ///Mano 1
                    glColor3f(0,1,1);
                    glTranslated(0,0,2.7);
                    glRotatef(anguloMano1,0,1,0);
                    glutSolidSphere(0.5,12,12);
                    //-------------------------------
                    glPushMatrix();
                        ///Pulgar 1
                        glColor3f(0,1,1);
                        glTranslated(0.1,0.3,-0.1);
                        glRotated(anguloMenique1, 0,1,0);
                        gluCylinder(p,0.2,0.1,0.7,12,12);
                        ///Indice 1
                        glColor3f(0,1,1);
                        glTranslated(0.1,-0.3,0.2);
                        glRotated(anguloIndice1,0,1,0);
                        gluCylinder(p,0.2,0.1,0.8,12,12);
                        ///Anular 1
                        glColor3f(0,1,1);
                        glTranslated(-0.1,-0.3,0.1);
                        glRotated(anguloAnular1,0,1,0);
                        gluCylinder(p,0.2,0.1,0.7,12,12);
                    glPopMatrix();
                    //-------------------------------
                glPopMatrix();
                //-------------------------------
            glPopMatrix();
            //-------------------------------
         glPopMatrix();
        //-------------------------------
         glPushMatrix();
        //--------------------------
         ///Brazo Derecho
            glColor3f(1,1,0);
            glTranslatef(-1.4,-2,0.6);
            glRotatef(anguloBrazo2,0,1,0);
            glutSolidSphere(0.6,16,16);
            glColor3f(1,0,0);
            glTranslatef(0,0,0.4);
            gluCylinder(p,0.6,0.5,3,12,12);
             //--------------------------
            glPushMatrix();
                ///Antebrazo Derecho
                glColor3f(1,1,0);
                glTranslatef(0,0,3);
                glRotatef(anguloAntebrazo2,0,1,0);
                glutSolidSphere(0.4,16,16);
                glColor3f(1,0,1);
                gluCylinder(p,0.5,0.5,2.6,12,12);
                //--------------------------
                 glPushMatrix();
                    ///Mano 2
                    glColor3f(0,1,1);
                    glTranslated(0,0,2.7);
                    glRotatef(anguloMano2,0,1,0);
                    glutSolidSphere(0.5,12,12);
                    //--------------------------
                    glPushMatrix();
                        ///Pulgar 2
                        glColor3f(0,1,1);
                        glTranslated(0.1,0.3,-0.1);
                        glRotated(anguloMenique2, 0,1,0);
                        gluCylinder(p,0.2,0.1,0.7,12,12);
                        ///Indice 2
                        glColor3f(0,1,1);
                        glTranslated(0.1,-0.3,0.2);
                        glRotated(anguloIndice2,0,1,0);
                        gluCylinder(p,0.2,0.1,0.8,12,12);
                        ///Anular 2
                        glColor3f(0,1,1);
                        glTranslated(-0.1,-0.3,0.1);
                        glRotated(anguloAnular2,0,1,0);
                        gluCylinder(p,0.2,0.1,0.7,12,12);
                    glPopMatrix();
                    //-------------------------------
                glPopMatrix();
                //------------------------------
            glPopMatrix();
            //--------------------------
         glPopMatrix();
         //--------------------------
         glPushMatrix();
         //--------------------------
         ///Pierna Derecha
            glColor3f(1,1,0);
            glTranslatef(0.5,1,6);
            glRotatef(anguloPierna1,0,1,0);
            glutSolidSphere(0.7,16,16);
            glTranslatef(0,0,0.3);
            glColor3f(0,0,0);
            gluCylinder(p,0.7,0.6,3,12,12);
            //--------------------------
            glPushMatrix();
                ///Pantorrilla Derecha
                glColor3f(1,1,0);
                glTranslatef(0,0,3);
                glRotatef(anguloPantorrilla1,0,1,0);
                glutSolidSphere(0.5,16,16);
                glColor3f(0.2,0,0);
                gluCylinder(p,0.6,0.6,2,12,12);
                //--------------------------
                glPushMatrix();
                    ///Pie 1
                    glColor3f(0,0,0);
                    glRotatef(anguloPie1,0,1,0);
                    glTranslatef(-2,0,0.2);
                    glutSolidSphere(0.6,16,16);
                    glTranslatef(0,0,0.3);
                    gluCylinder(p,0.5,0.3,1,12,12);
                    glTranslatef(0,0,0.7);
                    glColor3f(0,0,0);
                    glutSolidSphere(0.3,16,16);
                glPopMatrix();
                //--------------------------
            glPopMatrix();
            //--------------------------
         glPopMatrix();
         //--------------------------
         glPushMatrix();
         //--------------------------
        ///Pierna Izquierda
            glColor3f(1,1,0);
            glTranslatef(-0.4,-1,6.2);
            glRotatef(anguloPierna2,0,1,0);
            glutSolidSphere(0.7,16,16);
            glTranslatef(0,0,0.3);
            glColor3f(0,0,0);
            gluCylinder(p,0.7,0.6,3,12,12);
            //--------------------------
            glPushMatrix();
                ///Pantorrilla Izquierda
                glColor3f(1,1,0);
                glTranslatef(0,0,3);
                glRotatef(anguloPantorrilla2,0,1,0);
                glutSolidSphere(0.5,16,16);
                glColor3f(0.2,0,0);
                gluCylinder(p,0.6,0.6,2,12,12);
                //--------------------------
                glPushMatrix();
                    ///Pie 2
                    glColor3f(0,0,0);
                    glRotatef(anguloPie2,0,1,0);
                    glTranslatef(-2,0,0.2);
                    glutSolidSphere(0.6,16,16);
                    glTranslatef(0,0,0.3);
                    gluCylinder(p,0.5,0.3,1,12,12);
                    glTranslatef(0,0,0.7);
                    glColor3f(0,0,0);
                    glutSolidSphere(0.3,16,16);
                glPopMatrix();
                //--------------------------
            glPopMatrix();
            //--------------------------
        glPopMatrix();
        //--------------------------
    glPopMatrix();
    //------------------------------------------------------------------------------------------------------
    glutSwapBuffers();
}

void redimensionar(int w,int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    ///glOrtho(-10,30,-40,40,-40,40);
    gluPerspective(45,(float)w/(float)h,1,100);

}
void rotarTronco(int i)
{
    anguloTronco = anguloTronco + 4;
    glutPostRedisplay();
    glutTimerFunc(500,rotarTronco,2);
}

//----------------------------MOVIMIENTOS------------------------------
//------------------PARA TECLAS F# -> FIN + F#  -----------------------

void movimiento(int key, int x, int y)
{  switch(key){

               //----------------------------ANTEBRAZO IZQUIERDO ROTANDO HACIA ARRIBA------------------------------
           case GLUT_KEY_F1:{
                if(anguloAntebrazo1<90 && key == GLUT_KEY_F1){
                    anguloAntebrazo1 = anguloAntebrazo1 + 3;
                }else{
                    key = 0;
                }
                break;
           }
            //----------------------------ANTEBRAZO IZQUIERDO EN POSE NORMAL------------------------------
           case GLUT_KEY_F2:{
                if(anguloAntebrazo1>0 && key ==GLUT_KEY_F2){
                    anguloAntebrazo1 = anguloAntebrazo1 - 3;
                }else{
                    key = 0;
                }
                break;
           }
              //----------------------------ANTEBRAZO DERECHO ROTANDO HACIA ARRIBA------------------------------
           case GLUT_KEY_F3:{
                if(anguloAntebrazo2<90 && key == GLUT_KEY_F3){
                    anguloAntebrazo2 = anguloAntebrazo2 + 3;
                }else{
                    key = 0;
                }
                break;
           }
            //----------------------------ANTEBRAZO DERECHO EN POSE NORMAL------------------------------
           case GLUT_KEY_F4:{
                if(anguloAntebrazo2>0 && key ==GLUT_KEY_F4){
                    anguloAntebrazo2 = anguloAntebrazo2 - 3;
                }else{
                    key = 0;
                }
                break;
           }

              //----------------------------MANO IZQUIERDA ROTANDO HACIA ARRIBA------------------------------
           case GLUT_KEY_F5:{
               if(key == GLUT_KEY_F5){
                    if(anguloMano1<50){
                        anguloMano1 = anguloMano1 + 6;
               }else{
                key = 0;
               }

            } break;
           }

           //----------------------------MANO IZQUIERDA EN POSE NORMAL------------------------------
           case GLUT_KEY_F6:{
               if(key == GLUT_KEY_F6){
                    if(anguloMano1>0){
                        anguloMano1 = anguloMano1 - 2;
               }else{
                key = 0;
               }

            } break;
           }

           //----------------------------MANO DERECHA ROTANDO HACIA ARRIBA------------------------------
           case GLUT_KEY_F7:{
               if(key == GLUT_KEY_F7){
                    if(anguloMano2<50){
                        anguloMano2 = anguloMano2 + 6;
               }else{
                key = 0;
               }

            } break;
           }

            //----------------------------MANO DERECHA EN POSE NORMAL------------------------------
           case GLUT_KEY_F8:{
               if(key == GLUT_KEY_F8){
                    if(anguloMano2>0){
                        anguloMano2 = anguloMano2 - 6;
               }else{
                key = 0;
               }

            } break;
           }

             //----------------------------PRENDER LUZ------------------------------
           case GLUT_KEY_F12:{
               if(key == GLUT_KEY_F12){
                    ///iluminacion1
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
               }else{
                   key = 0;
                }
                    break;
           }

         //----------------------------APAGAR LA LUZ------------------------------
        case GLUT_KEY_F11: {
            if(key == GLUT_KEY_F11){
                     //desactivar iluminacion
                    glDisable(GL_LIGHT0);
                    glDisable(GL_NORMALIZE);
                    glDisable(GL_COLOR_MATERIAL);
                    glDisable(GL_LIGHTING);

                    glDisable(GL_LIGHT1);
                    glDisable(GL_NORMALIZE);
                    glDisable(GL_COLOR_MATERIAL);
                    glDisable(GL_LIGHTING);
            }else{
                key = 0;
            }
                    break;
        }

         //----------------------------SPOTLIGHT------------------------------
       case GLUT_KEY_F9:{
                if(key == GLUT_KEY_F9){
                    //spotlight
                    glEnable(GL_LIGHT1);
                    glEnable(GL_NORMALIZE);
                    glEnable(GL_COLOR_MATERIAL);
                    glEnable(GL_LIGHTING);

                    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
                    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
                    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
                    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
                    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
                    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
                    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);
                    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
                    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spot_direction);
                    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

                }else{
                    key = 0;
                }

                    break;
       }

       //----------------------------CAMINANDO------------------------------
        case GLUT_KEY_UP: {
            if(aX<32 && aZ>5 && key == GLUT_KEY_UP){
                aX = aX + 0.25;
                aZ = aZ - 0.2;
                if(anguloBrazo2< 29 && anguloBrazo1>-29  && f == true ){
                    anguloBrazo2 = anguloBrazo2 + 3;
                    anguloBrazo1 = anguloBrazo1 - 3;

                }else{
                    f = false;
                    anguloBrazo2 = anguloBrazo2 - 3;
                    anguloBrazo1 = anguloBrazo1 + 3;

                    if(anguloBrazo2 == -15 && anguloBrazo1 == 15){
                        f = true;
                    }
                }
                if(anguloPierna1< 30 && anguloPierna2>-30 && anguloPantorrilla1>-30 && anguloPantorrilla2< 30 && f1 ==true){
                    ///Pierna 1
                    anguloPierna1 = anguloPierna1 + 3;
                    anguloPantorrilla2 = anguloPantorrilla2 + 2;
                    ///Pierna 2
                    anguloPierna2 = anguloPierna2 - 3;
                    anguloPantorrilla1 = anguloPantorrilla1 - 2;
                }else{
                    f1 = false;
                    ///Pierna 1
                    anguloPierna1 = anguloPierna1 - 3;
                    anguloPantorrilla2 = anguloPantorrilla2 - 2;
                    ///Pierna 2
                    anguloPierna2 = anguloPierna2 + 3;
                    anguloPantorrilla1 = anguloPantorrilla1 + 2;
                    if(anguloPierna1 == -15 && anguloPierna2 == 15 && anguloPantorrilla1== 10  && anguloPantorrilla2 == -10){
                        f1 = true;
                    }
                }
            }else{
                key = 0;
            } break;
        }

         //----------------------------RETROCEDIENDO------------------------------
        case GLUT_KEY_DOWN:{
               if(aX> 0 && aZ<30 && key == GLUT_KEY_DOWN){
                   aX = aX - 0.25;
                   aZ = aZ + 0.2;
                    if(anguloBrazo2< 29 && anguloBrazo1>-29  && f == true){
                       anguloBrazo2 = anguloBrazo2 + 3;
                       anguloBrazo1 = anguloBrazo1 - 3;
                    }else{
                       f = false;
                       anguloBrazo2 = anguloBrazo2 - 3;
                       anguloBrazo1 = anguloBrazo1 + 3;
                       if(anguloBrazo2 == -15 && anguloBrazo1 == 15){
                           f = true;
                       }
                   }
                   if(anguloPierna1< 30 && anguloPierna2>-30 && anguloPantorrilla1>-30 && anguloPantorrilla2< 30 && f1 ==true){
                       anguloPierna1 = anguloPierna1 + 3;
                       anguloPantorrilla1 = anguloPantorrilla1 - 2;
                       anguloPierna2 = anguloPierna2 - 3;
                       anguloPantorrilla2 = anguloPantorrilla2 + 2;
                   }else{
                       f1 = false;
                       anguloPierna1 = anguloPierna1 - 3;
                       anguloPantorrilla2 = anguloPantorrilla2 - 2;
                       anguloPierna2 = anguloPierna2 + 3;
                       anguloPantorrilla1 = anguloPantorrilla1 + 2;
                       if(anguloPierna1 == -15 && anguloPierna2 == 15 && anguloPantorrilla1== 10  && anguloPantorrilla2 == -10){
                           f1 = true;
                       }
                   }
               }else{
                key = 0;
               }
               break;
           }

          //----------------------------SALUDANDO CON MANO IZQUIERDA------------------------------
           case GLUT_KEY_LEFT:{
                if(key == GLUT_KEY_LEFT){
                    if(anguloAntebrazo1<170 && anguloMano1<50 ){
                        anguloAntebrazo1 = anguloAntebrazo1 + 14;
                        anguloMano1 = anguloMano1 + 6;
                    }
                    if(key == GLUT_KEY_LEFT && anguloAnular1>-30 && anguloMenique1<32 && f2 == true){
                        anguloAnular1 = anguloAnular1 - 5;
                        anguloMenique1 = anguloMenique1 + 5;
                    }else{
                        f2 = false;
                        anguloAnular1 = anguloAnular1 + 5;
                        anguloMenique1 = anguloMenique1 - 5;

                        if(anguloAnular1 == 0 && anguloMenique1 == 2){
                            f2 = true;
                        }
                   }
                }else{
                    key = 0;
                }
                break;
           }

             //----------------------------SALUDANDO CON MANO DERECHA------------------------------
            case GLUT_KEY_RIGHT:{
                if(key == GLUT_KEY_RIGHT){
                    if(anguloAntebrazo2<170 && anguloMano2<50 ){
                        anguloAntebrazo2 = anguloAntebrazo2 + 14;
                        anguloMano2 = anguloMano2 + 6;
                    }
                    if(key == GLUT_KEY_RIGHT && anguloAnular2>-30 && anguloMenique2<32 && f3 == true){
                        anguloAnular2 = anguloAnular2 - 5;
                        anguloMenique2 = anguloMenique2 + 5;
                    }else{
                        f3 = false;
                        anguloAnular2 = anguloAnular2 + 5;
                        anguloMenique2 = anguloMenique2 - 5;

                        if(anguloAnular2 == 0 && anguloMenique2 == 2){
                            f3 = true;
                        }
                   }
                }else{
                    key = 0;
                }
                break;
           }


    }
    glutPostRedisplay();
}

//----------MOVIENDO LA C�MARA---------------
void teclado(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'a':
			if (cY >= -50)
				cY = cY - 0.25;
			break;

		case 'q':
			if (cY <= 50)
				cY = cY + 0.25;
			break;

		case 'd':
			if (cX >= -50)
				cX = cX - 0.25;
			break;

		case 'e':
			if (cX <= 50)
				cX = cX + 0.25;
			 break;

		case 'w':
			if (cZ <= 50)
				cZ = cZ + 0.25;
			break;

		case 's':
			if (cZ >= -50)
				cZ = cZ - 0.25;
			break;
	}
	glutPostRedisplay();
}

//-------------------PROGRAMA PRINCIPAL-----------------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(100,200);
    glutCreateWindow("Holi Boli");

    inicializar();

    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);
    glutSpecialFunc(movimiento);
    glutKeyboardFunc(teclado);


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

    return 0;
}
