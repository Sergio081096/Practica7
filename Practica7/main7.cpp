//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Cano Olguin Luis Sergio				******//
//*************			Visual Studio 2012				******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio=0;
int venus=0;
int tierra=0,luna=0;
int marte=0;
int jupiter=0;
int saturno=0;
int urano=0;
int neptuno=0;

float camaraZ = 0.0;
float camaraX = 0.0;
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;

float LightAngle = 30.0f;

bool	light = false;		// Luz ON/OFF
bool	positional = true;

static int spin = 0;


GLfloat LightAmbient[]= { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[]= { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[]= { 0.0f, 0.0f, -2.0f };			// Light Position

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background---r-g-b--default(alfa)
GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest

GLfloat mat_ambient1[] = { 0.0, 0.0, 1.0, 1.0 };					// Color background---r-g-b---default
GLfloat mat_diffuse1[] = { 1.0, 0.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular1[] = { 0.0, 1.0, 0.0, 1.0 };				// Specular color
GLfloat mat_shininess1[] = { 100.0 };				

///////////////////////////////////////////////////////////////////////////////
GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat AniDiffuse[]= { 1.0f, 0.8f, 1.0f, 1.0f };			// Anillo
GLfloat AniSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat AniShininess[] = { 100.0 };


GLfloat MarsDiffuse[]= { 0.8f, 0.3f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat MerDiffuse[]= { 1.0f, 0.0f, 0.0f, 1.0f };			// Mercurio
GLfloat MerSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MerShininess[] = { 50.0 };

GLfloat VeDiffuse[]= { 0.957,0.643,0.376, 1.0f };			// Venus
GLfloat VeSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat VeShininess[] = { 50.0 };

GLfloat JupDiffuse[]= { 1.0,0.7,0.2, 1.0f };			// Jupiter
GLfloat JupSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JupShininess[] = { 50.0 };

GLfloat SatDiffuse[]= { 0.0,0.0,1.0, 1.0f };			// Saturno
GLfloat SatSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat SatShininess[] = { 50.0 };

GLfloat UraDiffuse[]= { 0.0,0.32,1.0, 1.0f };			// Urano
GLfloat UraSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UraShininess[] = { 50.0 };

GLfloat NepDiffuse[]= { 0.2,0.5,1.0, 1.0f };			// Urano
GLfloat NepSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NepShininess[] = { 50.0 };


void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,SunDiffuse);	
	glLightfv(GL_LIGHT1,GL_SPECULAR,SunSpecular);
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	glPushMatrix();	
		glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
		glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
		glLightfv(GL_LIGHT1,GL_POSITION,SunPosition);
		glDisable(GL_LIGHTING);
		glutSolidSphere(2.0,12,12);  //Draw Sun (radio,H,V);---Alambre
		glEnable(GL_LIGHTING);
	glPopMatrix();
	//mercurio
	glPushMatrix();
	glRotatef(mercurio-5,0.0,1.0,0.0);
		glColor3f(0.545,0.271,0.075);
		glTranslatef(2.5,0.2,0.2);
		glRotatef(mercurio,0.0,1.0,0.0);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,MerDiffuse);//color en material
		glMaterialfv(GL_FRONT,GL_SPECULAR,MerSpecular);//color en material
		glMaterialfv(GL_FRONT,GL_SHININESS,MerShininess);//color en material
		glutSolidSphere(0.3,10,10); 
	glPopMatrix();
	//venus
	glPushMatrix();
	glRotatef(venus-5,0.0,-1.0,0.0);
		glColor3f(0.957,0.643,0.376);
		glTranslatef(3.5,0.2,0.2);
		glRotatef(venus,0.0,1.0,0.0);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,VeDiffuse);//color en material
		glMaterialfv(GL_FRONT,GL_SPECULAR,VeSpecular);//color en material
		glMaterialfv(GL_FRONT,GL_SHININESS,VeShininess);//color en material
		glutSolidSphere(0.4,10,10); 
	glPopMatrix();
	//tierra
	glPushMatrix();
	glRotatef(tierra-5,0.0,1.0,-1.0);
		glColor3f(0.0,0.0,1.0);
		glTranslatef(4.8,0.2,0.2);		
		glPushMatrix();
			glRotatef(tierra,0.0,1.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,EarthDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,EarthSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,EarthShininess);//color en material
			glutSolidSphere(0.6,10,10); 
		glPopMatrix();	
		//luna
		glPushMatrix();
			glColor3f(0.957,0.643,0.376);			
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(0.7,0.2,0.2);
			glRotatef(luna+2,1.0,0.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);//color en material
			glutSolidSphere(0.1,10,10); 
		glPopMatrix();
	glPopMatrix();
	//marte
	glPushMatrix();
	glRotatef(marte-5,0.0,-1.0,1.0);
		glColor3f(1.0,0.0,0.0);
		glTranslatef(6.5,0.2,0.2);
		glPushMatrix();
			glRotatef(marte,0.0,1.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MarsDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,MarsSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,MarsShininess);//color en material
			glutSolidSphere(0.55,10,10); 
		glPopMatrix();		
		//luna
		glPushMatrix();
			glColor3f(0.957,0.643,0.376);
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(0.65,0.2,0.3);
			glRotatef(luna+2,1.0,0.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);//color en material
			glutSolidSphere(0.1,10,10); 
		glPopMatrix();
		//luna
		glPushMatrix();
			glColor3f(0.957,0.643,0.376);
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(-0.65,0.2,0.3);
			glRotatef(luna+2,1.0,0.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);//color en material
			glutSolidSphere(0.1,10,10); 
		glPopMatrix();
	glPopMatrix();
	//jupiter
	glPushMatrix();
	glRotatef(jupiter-5,0.0,1.0,0.0);
		glColor3f(1.0,0.5,0.0);
		glTranslatef(8.5,0.2,0.2);
		glPushMatrix();
			glRotatef(jupiter,0.0,1.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,JupDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,JupSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,JupShininess);//color en material
			glutSolidSphere(0.9,10,10); 
		glPopMatrix();
		//luna
		glPushMatrix();
			glColor3f(0.957,0.643,0.376);
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(0.95,0.2,0.3);			
			glRotatef(luna+2,1.0,0.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);//color en material
			glutSolidSphere(0.1,10,10); 
		glPopMatrix();
		//luna
		glPushMatrix();
			glColor3f(0.957,0.643,0.376);
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(-0.95,0.2,0.3);
			glRotatef(luna+2,1.0,0.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);//color en material
			glutSolidSphere(0.1,10,10); 
		glPopMatrix();
		//luna
		glPushMatrix();
			glColor3f(0.957,0.643,0.376);
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(0.95,0.5,0.3);
			glRotatef(luna+2,1.0,0.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);//color en material
			glutSolidSphere(0.1,10,10); 
		glPopMatrix();
	glPopMatrix();
	//saturno
	glPushMatrix();
	glRotatef(saturno-7,0.0,1.0,1.0);
		glColor3f(0.0,0.0,1.0);
		glTranslatef(11.5,0.2,0.2);	
		glRotatef(90,1.0,0.0,0.0);
		glPushMatrix();
			glRotatef(saturno,0.0,1.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,SatDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,SatSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,SatShininess);//color en material
			glutSolidSphere(0.82,10,10); 
		glPopMatrix();	
		//anillo
		glPushMatrix();
			glColor3f(0.957,0.643,0.376);			
			glRotatef(luna,0.0,0.0,1.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,AniDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,AniSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,AniShininess);//color en material
			glutSolidTorus(0.1,1.0,10.0,10.0);
		glPopMatrix();
		//anillo
		glPushMatrix();
			glColor3f(0.957,0.0,0.376);			
			glRotatef(luna+5,0.0,0.0,1.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,AniDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,AniSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,AniShininess);//color en material
			glutSolidTorus(0.1,1.3,20.0,20.0);
		glPopMatrix();
		//luna
		glPushMatrix();
			glColor3f(0.957,0.643,0.376);
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(1.45,0.2,0.3);
			glRotatef(luna+2,1.0,0.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);//color en material
			glutSolidSphere(0.1,10,10); 
		glPopMatrix();
		//luna
		glPushMatrix();
			glColor3f(0.957,0.643,0.376);
			glRotatef(luna,0.0,0.0,1.0);
			glTranslatef(-1.45,0.2,0.3);
			glRotatef(luna+2,1.0,0.0,0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);//color en material
			glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);//color en material
			glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);//color en material
			glutSolidSphere(0.1,10,10); 
		glPopMatrix();
	glPopMatrix();
	//urano
	glPushMatrix();
	glRotatef(urano-5,0.0,1.0,0.0);
		glColor3f(0.0,0.32,1.0);
		glTranslatef(13.5,0.2,0.2);
		glRotatef(urano,0.0,1.0,0.0);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,UraDiffuse);//color en material
		glMaterialfv(GL_FRONT,GL_SPECULAR,UraSpecular);//color en material
		glMaterialfv(GL_FRONT,GL_SHININESS,UraShininess);//color en material
		glutSolidSphere(0.4,10,10); 
	glPopMatrix();
	//neptuno
	glPushMatrix();
	glRotatef(urano-2,0.0,-1.0,1.0);
		glColor3f(0.0,0.5,1.0);
		glTranslatef(14.8,0.2,0.2);
		glRotatef(urano,0.0,1.0,0.0);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,NepDiffuse);//color en material
		glMaterialfv(GL_FRONT,GL_SPECULAR,NepSpecular);//color en material
		glMaterialfv(GL_FRONT,GL_SHININESS,NepShininess);//color en material
		glutSolidSphere(0.35,10,10); 
	glPopMatrix();

	//glPopMatrix();
	glutSwapBuffers ( );
	//glutSolidTorus

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()--contador
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio=(mercurio - 8) % 360;
		venus = (venus - 5) % 360;
		tierra = (tierra - 5) % 360;
		luna = (luna - 3) % 360;
		marte = (marte - 4) % 360;
		jupiter = (jupiter - 2) % 360;
		saturno = (saturno - 2) % 360;
		urano = (urano - 5) % 360;
		neptuno = (neptuno - 5) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );//llammado de la funcion
  glutMainLoop        ( );          // 

  return 0;
}