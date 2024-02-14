#include "SDL_GL_Helper.h"

//pointer for general purpose quadric for rendering spheres
GLUquadricObj *q;
	double xres;   //to store x resolution
	double yres;   //to store y resolution to 480


void StartSDL()
{
	SDL_Init(SDL_INIT_VIDEO);  //initialise SDL & the video subsystem


	//Ask for anti-aliasing
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

	//Set the video mode, the first three values are:
	//	x resolution
	//	y resolution
	//	color depth
	//passing 0 uses desktop values
	//
	//SDL_OPENGL creates an OpenGL rendering context
	//SDL_HWSURFACE creates the surface in video memory, rather than system memory
	//SDL_FULLSCREEN sets full screen mode
	SDL_SetVideoMode(0, 0, 0, SDL_OPENGL | SDL_HWSURFACE | SDL_FULLSCREEN );
	SDL_EnableKeyRepeat(100, 10);
	SDL_ShowCursor(SDL_DISABLE);
	//SDL_WM_GrabInput(SDL_GRAB_ON);
}

void ConfigureOpenGL()
{
	SDL_Surface* myVideoSurface = NULL;
	double aspect_ratio; // width/height ratio

	//get the video information so we can learn how big the OpenGL screen is
	myVideoSurface = SDL_GetVideoSurface();
	xres = myVideoSurface->w;
	yres = myVideoSurface->h;
	// aspect ratio keeps the picture from distorting on different screen sizes
	aspect_ratio = (GLdouble)xres/(GLdouble)yres;
	glViewport(0,0,xres,yres);        //set OpenGL to render to the whole screen
	glClearColor(1.0,1.0,1.0,0.0);	  //set the clear colour to black (black background)
	glClearDepth(1.0);                //set the depth buffer to clear to 1

	glEnable(GL_DEPTH_TEST);          //enable depth testing according to glDepthFunc
	glShadeModel(GL_SMOOTH);          //interpolate colour values through the polygon

	//Enable transparancy effects
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Don't draw the backs of things
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	// select the projection matrix and clear it
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// set the viewing volume
	gluPerspective( 40.0, aspect_ratio, 0.1, 20.0 );

	// switch back to the modelview matrix
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	// now set eye position
	//          x    y    z
	gluLookAt( 0.0, 2.0, 4.0,  // Eye position
		0.0, 1.0, 0.0,  // Point to look at
		0.0, 1.0, 0.0); // Up direction

	// turn on the lights
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	float light_position[4] = {0.0f, 3.0f, 1.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// make things shiny
	float specular_color[4] = {0.7f, 0.7f, 0.7f, 1.0f};
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_color);
	glMaterialf(GL_FRONT, GL_SHININESS, 100);
	
	// create a general purpose quadric generator
	q = gluNewQuadric();
}



//Simplifies the process of drawing a sphere at a set of 3D coordinates.
void DrawSphere(double x, double y, double z, double radius)
{
	glPushMatrix();
	glTranslated(x,y,z);
	gluSphere(q,radius,30,15);
	glPopMatrix();
}


//Swaps a pair of doubles
void swap(double& a, double& b)
{	
	double temp;
	temp = a;
	a = b;
	b = temp;
}

//Draws a texture and lighting ready rectangular prism anywhere in space 
//when provided a pair of 3D points in any order.
void DrawBox(double x, double y, double z, double x2, double y2, double z2)
{
  if (x > x2)
	  swap(x,x2);
  if(y > y2)
	  swap(y,y2);
  if(z > z2)
	  swap(z,z2);

  glBegin(GL_QUADS);
   // Front Face
   glNormal3d( 0.0f, 0.0f, 1.0f);// Normal Pointing Towards Viewer
   glTexCoord2d(0.0f, 0.0f); glVertex3d( x,  y, z2);// Point 1 (Front)
   glTexCoord2d(1.0f, 0.0f); glVertex3d(x2,  y, z2);// Point 2 (Front)
   glTexCoord2d(1.0f, 1.0f); glVertex3d(x2, y2, z2);// Point 3 (Front)
   glTexCoord2d(0.0f, 1.0f); glVertex3d( x, y2, z2);// Point 4 (Front)
   // Back Face
   glNormal3d( 0.0f, 0.0f,-1.0f);// Normal Pointing Away From Viewer
   glTexCoord2d(1.0f, 0.0f); glVertex3d( x,  y,  z);// Point 1 (Back)
   glTexCoord2d(1.0f, 1.0f); glVertex3d( x, y2,  z);// Point 2 (Back)
   glTexCoord2d(0.0f, 1.0f); glVertex3d(x2, y2,  z);// Point 3 (Back)
   glTexCoord2d(0.0f, 0.0f); glVertex3d(x2,  y,  z);// Point 4 (Back)
   // Top Face
   glNormal3d( 0.0f, 1.0f, 0.0f);// Normal Pointing Up
   glTexCoord2d(0.0f, 1.0f); glVertex3d( x, y2,  z);// Point 1 (Top)
   glTexCoord2d(0.0f, 0.0f); glVertex3d( x, y2, z2);// Point 2 (Top)
   glTexCoord2d(1.0f, 0.0f); glVertex3d(x2, y2, z2);// Point 3 (Top)
   glTexCoord2d(1.0f, 1.0f); glVertex3d(x2, y2,  z);// Point 4 (Top)
   // Bottom Face
   glNormal3d( 0.0f,-1.0f, 0.0f);// Normal Pointing Down
   glTexCoord2d(1.0f, 1.0f); glVertex3d( x,  y,  z);// Point 1 (Bottom)
   glTexCoord2d(0.0f, 1.0f); glVertex3d(x2,  y,  z);// Point 2 (Bottom)
   glTexCoord2d(0.0f, 0.0f); glVertex3d(x2,  y, z2);// Point 3 (Bottom)
   glTexCoord2d(1.0f, 0.0f); glVertex3d( x,  y, z2);// Point 4 (Bottom)
   // Right face
   glNormal3d( 1.0f, 0.0f, 0.0f);// Normal Pointing Right
   glTexCoord2d(1.0f, 0.0f); glVertex3d(x2,  y,  z);// Point 1 (Right)
   glTexCoord2d(1.0f, 1.0f); glVertex3d(x2, y2,  z);// Point 2 (Right)
   glTexCoord2d(0.0f, 1.0f); glVertex3d(x2, y2, z2);// Point 3 (Right)
   glTexCoord2d(0.0f, 0.0f); glVertex3d(x2,  y, z2);// Point 4 (Right)
   // Left Face
   glNormal3d(-1.0f, 0.0f, 0.0f);// Normal Pointing Left
   glTexCoord2d(0.0f, 0.0f); glVertex3d( x,  y,  z);// Point 1 (Left)
   glTexCoord2d(1.0f, 0.0f); glVertex3d( x,  y, z2);// Point 2 (Left)
   glTexCoord2d(1.0f, 1.0f); glVertex3d( x, y2, z2);// Point 3 (Left)
   glTexCoord2d(0.0f, 1.0f); glVertex3d( x, y2,  z);// Point 4 (Left)
  glEnd();// Done Drawing Quads
}




#ifndef __FIXSDL 
#define __FIXSDL
extern "C" { FILE __iob_func[3] = { *stdin,*stdout,*stderr }; } //fixes out of date SDL issue
#endif