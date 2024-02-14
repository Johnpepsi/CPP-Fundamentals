// Bounce Physics Simulation
// File: main.cpp
// Author: Alex Clarke
// Company: University of Regina CS Labs
// Date: June 30, 2009
// Ported to repl.it: February 20, 2021
//
// Provides a first look at interactive graphics based programming
// Take a look around to learn more about SDL and OpenGL.
// The comments contain tips that will allow you to tweak parts of the program
// such as table color, gravity, and ball mass.

#include "SDL_GL_Helper.h"

void ThrowBall();
void RenderScene();
void HandleBalls();
void HandleSimulationKeys(char key);

// Physics constants
/*Acceleration from gravity in metric units
 *Values for "nearby" places: */
const double Earth = -9.81;
const double Mercury = -3.59;
const double Venus = -8.87;
const double Moon = -1.62;
const double Mars = -3.77;
const double Jupiter = -25.95;

const double A_gravity = Earth;
const double default_radius = 0.05; // controls ball radius
const double default_mass = 0.15;

// Defines a ball's state.
class Ball {
public:
	// Ball related variables
	double mass; // Affects how much impact throw force has on the ball.
	double radius;
	double pos_x;
	double pos_y;
	double vel_x;
	double vel_y;
	double F_gravity; // force on ball from gravity.
	Ball(
		double init_pos_x,
		double init_pos_y,
		double throw_force_x,
		double throw_force_y) {
		pos_x = init_pos_x;
		pos_y = init_pos_y;
		mass = default_mass;
		vel_x = throw_force_x / this->mass;
		vel_y = throw_force_y / this->mass;
		F_gravity = A_gravity * this->mass;
		radius = default_radius;
	}
};

list<Ball> balls;

// Ball throw control variables
double pos_x_init = 0;
double pos_y_init = 2.0;
double throw_force_x = 0.0;
double throw_force_y = 0.0;

// Simulation time keepers
int last_time;
int current_time;

// Calls initialization functions and contains main event loop
int main(int argc, char *argv[]) {
	SDL_Event event; // create event structure so we can detect keypresses

	StartSDL();
	ConfigureOpenGL();

	last_time = SDL_GetTicks(); // get an initial time

	while (SDL_PollEvent(&event))
		;

	bool done = false; // define flag to end loop
	while (done != true) {
		RenderScene();
		HandleBalls();
		SDL_GL_SwapBuffers();

		while (SDL_PollEvent(&event)) // while there are events in the queue
		{
			// Event handler
			//
			// This if/else sequence with nested if/else statements is typical
			// of user interface code.
			//
			// The type of events depends on the package you are using, whether
			// it be MFC for Windows, Carbon for Mac or SDL for games, but the
			// idea is always the same:
			//
			//    1) What type of thing am I being asked to do
			//    2) Are there any details I'm interested in?
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE)
					done = true;
				else
					// There are many possible keys so we will handle them
					// with a function.
					HandleSimulationKeys(event.key.keysym.sym);
			} else if (event.type == SDL_KEYUP) {
				// There is a separate signal for pressing
				// and releasing a key
				if (event.key.keysym.sym == 'f') {
					ThrowBall();
				}
			} else if (event.type == SDL_MOUSEMOTION) {
				throw_force_x = (event.motion.x / xres - .5) * 3;
				throw_force_y = ((yres - event.motion.y) / yres - .5) * 3;
			} else if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					ThrowBall();
				}
			} else if (event.type == SDL_QUIT) {
				done = true;
			}

		} // end event loop
	}	 // end of main loop

	SDL_Quit();
	return (0);
}

// HandleBall
//
// Physics code. Applies physics calculations to the ball's global
// state variables and draws the ball when the simulation is running.
void HandleBalls() {
	double dt; // delta time (elapsed time)

	// How long has it been since the last update?
	current_time = SDL_GetTicks();
	dt = (current_time - last_time) / 1000.0;
	last_time = current_time;

	// Go through the list of balls
	auto cur = balls.begin();
	while (cur != balls.end()) {
		// Extract data from ball
		double mass =
			cur->mass; // Affects how much impact throw force has on the ball.
		double radius = cur->radius;
		double pos_x = cur->pos_x;
		double pos_y = cur->pos_y;
		double vel_x = cur->vel_x;
		double vel_y = cur->vel_y;
		double F_gravity = cur->F_gravity; // force on ball from gravity.

		// Save the last position of the ball
		double last_pos_x;
		double last_pos_y;
		last_pos_y = pos_y;
		last_pos_x = pos_x;

		// Apply the force of gravity
		// Gravity only pulls down, so it only ever applies to y direction
		vel_y += F_gravity / mass * dt;

		// Update position of Ball based on previous speed
		pos_x += vel_x * dt;
		pos_y += vel_y * dt;

		// Table top collision code:
		// If the bottom of the ball is below the table top
		// and the ball was above the table last time we checked
		if ((pos_y - radius < 1.0) && (last_pos_y - radius >= 1.0)) {
			// And if the ball is not past either edge of the table
			if (pos_x < 1.5 && pos_x > -1.5) {
				// Then reverse the ball's velocity and steal some kinetic
				// energy
				vel_y = -vel_y * 0.9; // Energy lost to "Elastic Collision"

				// and set its bottom on the table
				pos_y = 1.0 + radius;

				// Energy is also lost to "Rolling Friction"
				if (vel_x > 0)
					vel_x = vel_x - 0.01 * mass * dt;
				else if (vel_x < 0)
					vel_x = vel_x + 0.01 * mass * dt;
			}
		}

		// Make the current color red
		glColor3d(0.9, 0.1, 0.1);
		// Draw the ball
		DrawSphere(pos_x, pos_y, 0.0, radius);

		// Save changed position back to ball
		cur->pos_x = pos_x;
		cur->pos_y = pos_y;
		cur->vel_x = vel_x;
		cur->vel_y = vel_y;

		// If the ball goes too far off the screen, remove it from the
		// simulation
		auto erase = cur;
		cur++;
		if (pos_y < -10 || pos_x > 10 || pos_x < -10) {
			balls.erase(erase);
		}
	}
}

// Handles movement keys
//
// Key handler. Uses a switch statement to modify global state variable
// in response to certain keys
void HandleSimulationKeys(char key) {
	switch (key) {
	case SDLK_d: // move ball right
		pos_x_init += 0.01;
		break;
	case SDLK_a: // move ball left
		pos_x_init -= 0.01;
		break;

	}
}

// Throw Ball
//
// Adds a ball to the simulation,
// Sets up gravity,
// applies an initial force to the ball
// and establishes simulation start time.
void ThrowBall() {
	balls.push_back(Ball(pos_x_init, pos_y_init, throw_force_x, throw_force_y));
}

// Draw a colorful tiled table and the control ball
void RenderScene() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set the randomizer to a known sequence
	srand(2);

	// Define points for tile vertices
	point3 v0, v1, v2, v3, v4, v5, v6, v7;

	// Control the tiles' size and shape
	double tile_width = 0.1;
	double bevel = 0.005;

	// Draw coloured tiles for table top
	double tile_color[3];
	tile_color[0] = 0.0;  // Red. Set randomly later.
	tile_color[1] = 0.65; // Green. Default is 0.65. Switch it to 0.4 for
						  // blue/purple colours
	tile_color[2] =
		0.8; // Blue. Default is 0.8. Switch it to 0.3 for "UofR" colors

	v0.y = v1.y = v2.y = v3.y = 1.0;
	v4.y = v5.y = v6.y = v7.y = 1.0 - bevel;

	glBegin(GL_QUADS);
	for (double x = -1.5; x <= 1.5 - tile_width + .001; x += tile_width) {
		for (double z = -0.8; z <= .8 - tile_width + .001; z += tile_width) {
			// Randomly vary the red color channel between 0 and 0.65
			tile_color[0] = 0.65 - double(rand()) / RAND_MAX / 1.5;
			glColor3dv(tile_color);

			// Set up the points (vertices) that define a tile:
			// v7--------v6
			// |\        /|
			// | v3----v2 |
			// |  |    |  |
			// |  |    |  |
			// | v0----v1 |
			// |/        \|
			// v4--------v5
			v0.x = x + bevel;
			v0.z = z + bevel;
			v1.x = x + tile_width - bevel;
			v1.z = z + bevel;
			v2.x = x + tile_width - bevel;
			v2.z = z + tile_width - bevel;
			v3.x = x + bevel;
			v3.z = z + tile_width - bevel;
			v4.x = x;
			v4.z = z;
			v5.x = x + tile_width;
			v5.z = z;
			v6.x = x + tile_width;
			v6.z = z + tile_width;
			v7.x = x;
			v7.z = z + tile_width;

			// front
			glNormal3dv(normalFromTriangle(v0, v2, v3).data());
			glVertex3dv(v0.data());
			glVertex3dv(v3.data());
			glVertex3dv(v2.data());
			glVertex3dv(v1.data());

			// back
			glNormal3dv(normalFromTriangle(v4, v6, v5).data());
			glVertex3dv(v4.data());
			glVertex3dv(v5.data());
			glVertex3dv(v6.data());
			glVertex3dv(v7.data());

			// left
			glNormal3dv(normalFromTriangle(v4, v3, v7).data());
			glVertex3dv(v4.data());
			glVertex3dv(v7.data());
			glVertex3dv(v3.data());
			glVertex3dv(v0.data());

			// right
			glNormal3dv(normalFromTriangle(v1, v6, v2).data());
			glVertex3dv(v1.data());
			glVertex3dv(v2.data());
			glVertex3dv(v6.data());
			glVertex3dv(v5.data());

			// bottom
			glNormal3dv(normalFromTriangle(v4, v1, v0).data());
			glVertex3dv(v4.data());
			glVertex3dv(v0.data());
			glVertex3dv(v1.data());
			glVertex3dv(v5.data());

			// top
			glNormal3dv(normalFromTriangle(v3, v6, v7).data());
			glVertex3dv(v3.data());
			glVertex3dv(v7.data());
			glVertex3dv(v6.data());
			glVertex3dv(v2.data());
		}
	}
	glEnd();

	// Top of table
	glColor3d(0.7, 0.7, 0.7);
	DrawBox(-1.50, 0.95, -0.8, 1.50, 1.0 - 2.0 * bevel / 3.0, 0.8);

	// Legs of table
	glColor3d(0.8, 0.5, 0.1);
	DrawBox(-1.40, 0.00, -0.70, -1.30, 0.95, -0.60);
	DrawBox(1.40, 0.00, 0.70, 1.30, 0.95, 0.60);
	DrawBox(-1.40, 0.00, 0.70, -1.30, 0.95, 0.60);
	DrawBox(1.40, 0.00, -0.70, 1.30, 0.95, -0.60);

	// Draw control ball
	glColor4d(1.0, 0.0, 0.0, 0.5);
	DrawSphere(pos_x_init, pos_y_init, -0.01, default_radius);

	// Draw initial throw force vector
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glVertex3d(pos_x_init, pos_y_init, 0.0);
	glVertex3d(pos_x_init + throw_force_x, pos_y_init + throw_force_y, 0.0);
	glEnd();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
}
