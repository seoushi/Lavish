#include <lavish/core/display.hpp>
#include <lavish/graphics/font.hpp>

#include <iostream>


using namespace lavish;

int main(int argc, char** argv)
{
	int ScreenWidth = 800;
	int ScreenHeight = 600;

	Display d;

	d.Initialize(ScreenWidth, ScreenHeight, 24, "Sample 06");

	if( d.Show() == false )
	{
		std::cout << "Failed to open window, exiting." << std::endl;
		return 1;
	}

	Font font;
	font.Load("data/arial-32.lfd", "data/arial-32.png");

	d.ClearColor( Color::Blue() );
		
	
	std::wstring text = L"The quick brown fox jumps over the lazy dog.!@#$%^&*()";
	auto textPos = Matrix4::Translate((float)(ScreenWidth / 2) - (font.StringWidth(text) / 2), 
										 (float)ScreenHeight / 2,
										 0);
	
    while(d.Listener()->Update())
	{
		d.ClearScreen();
		d.Setup2d();

		font.DrawString(text, textPos);
		
		d.SwapBuffers();
    }
	
    return 0;
}
