#ifndef ALEX_SDL_HELPER
#define ALEX_SDL_HELPER

#include <GL/glu.h>
#include <SDL/SDL.h>   //the main SDL header file
#include <SDL/SDL_opengl.h>
#include <cmath>
#include <iostream>

#include <list>
using namespace std;
extern	double xres;   //to store x resolution
extern	double yres;   //to store y resolution

void StartSDL();
void ConfigureOpenGL();
void DrawSphere(double x, double y, double z, double radius); 
void DrawBox(double x, double y, double z, double x2, double y2, double z2);


//Basic 3D vector class for point/vector math.
//Look up GLM math library for better, faster, more complete solution
class vec3
{
public:
	double x, y, z;
	vec3() : x(0), y(0), z(0) {}
	vec3(double x, double y, double z) { this->x = x; this->z = z; this->y = y; }
	vec3 operator-(vec3 b) { return vec3(x-b.x, y-b.y, z-b.z); }
	vec3 operator/(double b) { return vec3(x / b, y / b, z / b); }
	vec3 operator*(double b) { return vec3(x*b, y*b, z*b); }
	vec3 operator+(vec3 b) { return vec3(x + b.x, y + b.y, z + b.z); }
	double length() { return sqrt(x*x + y*y + z*z); }
	vec3 normalize() { return vec3(*this / length()); }
	friend vec3 crossProd(vec3 u, vec3 v) { return vec3(u.y*v.z - u.z*v.y, u.z*v.x - u.x*v.z, u.x*v.y - u.y*v.x); }
	friend double dotProd(vec3 u, vec3 v) { return u.x*v.x + u.y*v.y + u.z*v.z; }
	friend vec3 normalFromTriangle(vec3 a, vec3 b, vec3 c) { return crossProd(a - b, c - b).normalize(); }
	GLdouble * data() { return (GLdouble*)(this); }
};

typedef vec3 point3;

#endif