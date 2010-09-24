#include <lavish/core/display.hpp>
#include <iostream>

using namespace lavish;

int main(int argc, char** argv)
{
    Display d;
	
    d.Initialize(800, 600, 24, "Sample 01");
    
    if( d.Show() == false )
    {
        std::cout << "Failed to open window, exiting." << std::endl;
        return 1;
    }
	
    d.ClearColor( Color::White() );
	
    
    while(d.Listener()->Update())
    {
        d.ClearScreen();
		
        d.SetupPerspective(45.0f, 0.1f, 100.0f);
		
        d.SwapBuffers();
    }
	
    return 0;
}