
#include <cmath>
#include <vector>
#include <memory>

#include "Camera.h"
#include "Ray.h"
#include "Tracer.h"

#include "MCG_GFX_Lib.h"

#include <iostream>

#include <thread>
#include <mutex>

void doStuff(int startX, int endX, glm::ivec2 windowSize, std::shared_ptr<Camera> camera);

int main( int argc, char *argv[] )
{
	// Variable for storing window dimensions
	glm::ivec2 windowSize( 640, 480);

	// Call MCG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if( !MCG::Init( windowSize ) )
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGBA, numbers are from 0 to 255
	MCG::SetBackground( glm::ivec3(0,0,0) );

	// Preparing a position to draw a pixel
	glm::ivec2 pixelPosition = windowSize / 2; 
	

	// Preparing a colour to draw
	// Colours are RGB, each value ranges between 0 and 255
	//glm::ivec3 pixelColour( 255, 0, 0 );


	// Draws a single pixel at the specified coordinates in the specified colour!
	//MCG::DrawPixel( pixelPosition, pixelColour );
	
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	int threadCount = 1; 
	std::vector<std::thread> threadVector; 
	for (int i = 0; i <= windowSize.x; i += (windowSize.x / threadCount))
	{
		//create a number of threads to deal with each screen width
		threadVector.push_back(std::thread(doStuff, i, i + (windowSize.x/threadCount), camera));
		std::cout << "newthread" << std::endl;
	}
	//doStuff(1, 1, windowSize, camera);

	/*std::shared_ptr<Camera> camera = std::make_shared<Camera>(); 
	
	for (int screenX = 0; screenX < windowSize.x; screenX++)
	{
		for (int screenY = 0; screenY < windowSize.y; screenY++)
		{
			//looping all onscreen pixels, act on pixels here
			glm::ivec2 currentPixel = glm::ivec2(screenX, screenY);
			std::shared_ptr<Ray> ray = camera->returnRay(currentPixel);
			//std::cout << screenX << " " << screenY << std::endl;
			std::shared_ptr<Tracer> tracer = std::make_shared<Tracer>();
			glm::vec3 pixelColor = tracer->traceRay(ray);
			//std::cout << ray->getOrigin().x << " " << ray->getOrigin().y << std::endl;

			MCG::DrawPixel(currentPixel, pixelColor);
		}
	}*/






	// Do any other DrawPixel calls here
	// ...

	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	return MCG::ShowAndHold();





	// Advanced access - comment out the above DrawPixel and MCG::ShowAndHold lines, then uncomment the following:

	/*
	// Variable to keep track of time
	float timer = 0.0f;

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while( MCG::ProcessFrame() )
	{
		// Set every pixel to the same colour
		MCG::SetBackground( glm::ivec3( 0, 0, 0 ) );

		// Change our pixel's X coordinate according to time
		pixelPosition.x = (windowSize.x / 2) + (int)(sin(timer) * 100.0f);
		// Update our time variable
		timer += 1.0f / 60.0f;

		// Draw the pixel to the screen
		MCG::DrawPixel( pixelPosition, pixelColour );

	}

	return 0;
	*/

}


void doStuff(int startX, int endX, glm::ivec2 windowSize, std::shared_ptr<Camera> camera)
{
	
	std::mutex mutex;
	for (int screenX = 0; screenX < windowSize.x; screenX++)
	{
		for (int screenY = 0; screenY < windowSize.y; screenY++)
		{
			//looping all onscreen pixels, act on pixels here
			glm::ivec2 currentPixel = glm::ivec2(screenX, screenY);
			std::shared_ptr<Ray> ray = camera->returnRay(currentPixel);
			//std::cout << screenX << " " << screenY << std::endl;
			std::shared_ptr<Tracer> tracer = std::make_shared<Tracer>();
			glm::vec3 pixelColor = tracer->traceRay(ray);
			//std::cout << ray->getOrigin().x << " " << ray->getOrigin().y << std::endl;
			mutex.lock();
			MCG::DrawPixel(currentPixel, pixelColor);
			mutex.unlock();
		}
	}
}