#include <lavish/core/display.hpp>
#include <lavish/graphics/Font.hpp>

#include <iostream>

#include <AppKit/AppKit.h>


using namespace lavish;

int main(int argc, char** argv)
{
	int ScreenWidth = 800;
	int ScreenHeight = 600;
	
	// TODO: this needs to be integrated during intialization of the library
	[[NSFileManager defaultManager] changeCurrentDirectoryPath:[[NSBundle mainBundle] resourcePath]];
	
    Display d;
	
    d.Initialize(ScreenWidth, ScreenHeight, 24, "Sample 06");
	
    if( d.Show() == false )
    {
        std::cout << "Failed to open window, exiting." << std::endl;
        return 1;
    }

	Font font;
	font.Load("arial-32.lfd", "arial-32.png");

    d.ClearColor( Color::Blue() );
		
	
	std::wstring text = L"The quick brown fox jumps over the lazy dog.!@#$%^&*()";
	Matrix4 textPos = Matrix4::Translate((ScreenWidth / 2) - (font.StringWidth(text) / 2), 
										 ScreenHeight / 2,
										 0);
	
    while(d.Listener()->Update())
    {
        d.ClearScreen();
		d.Setup2d();

		font.DrawString(text, &textPos);
		
        d.SwapBuffers();		
    }
	
    return 0;
}