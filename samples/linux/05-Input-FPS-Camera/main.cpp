#include <lavish/graphics/vertexBuffer.hpp>
#include <lavish/core/display.hpp>
#include <lavish/graphics/model.hpp>
#include <lavish/core/timer.hpp>

#include <iostream>

#include "FPSCamera.hpp"

/*
 * input is mouse for looking and WASD for movement, press Escape to quit
 */


using namespace lavish;

int main(int argc, char** argv)
{
	FPSCamera camera;
    Display d;
	
    d.Initialize(800, 600, 24, "Sample 05");
	
    if( d.Show() == false )
    {
        std::cout << "Failed to open window, exiting." << std::endl;
        return 1;
    }
	
	// default fps like behavior
	d.GrabInput(true);
	d.ShowMouseCursor(false);

	// have the camera register mouse and keyboard events
	d.Listener()->AttachMouseListener(&camera);
	d.Listener()->AttachKeyboardListener(&camera);

    d.ClearColor( Color::Blue() );
	
	// load the texture
	Texture* tex = new Texture("../../grid.png");
	Texture::Enable(true);

	// load the plane
	Model* m = new Model("../../data/plane.obj");
	
	uint time = Timer::GetCurrentGameTime();
	
	Matrix4 modelTransformations;
	
	float angle;
	
	
	//clear the input before the scene was loaded and reset the camera to it's default view
	d.Listener()->Update();
	camera.Reset();
	
    while(d.Listener()->Update())
    {
		camera.Update();
		
		// apply the camera and move the cube into a good default position
		modelTransformations = camera.CameraMatrix();
	
		time = Timer::GetCurrentGameTime();


        d.ClearScreen();
        d.SetupPerspective(45.0f, 0.1f, 100.0f);
		
		tex->bind();
		m->Render(&modelTransformations);
		
        d.SwapBuffers();
		
		if(camera.ShouldQuit()) // should quit should probably be in it's own input listener
		{
			break;
		}
    }
	
    return 0;
}
