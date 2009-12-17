#include <lavish/vertexBuffer.hpp>
#include <lavish/display.hpp>

#include <iostream>

using namespace lavish;

int main(int argc, char** argv)
{
    Display d;
	
    d.Initialize(800, 600, 24, "Tutorial 2");
	
    if( d.Show() == false )
    {
        std::cout << "Failed to open window, exiting." << std::endl;
        return 1;
    }
	
    d.ClearColor( Color::White() );
	
	
    VertexBuffer<VertexColor> vbo(3);
	
    vbo.AddElement( VertexColor( Vector3(0.0f, 0.5f, -2.0f),
                                Color::Red()));
    vbo.AddElement( VertexColor( Vector3(0.5f, -0.5f, -2.0f),
                                Color::Green()));
    vbo.AddElement( VertexColor( Vector3(-0.5f, -0.5f, -2.0f),
                                Color::Blue()));
    
    vbo.Generate();
	
	
	
    while(d.Listener()->Update())
    {
        d.ClearScreen();
		
        d.SetupPerspective(45.0f, 0.1f, 100.0f);
        
        vbo.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        vbo.Unbind();
		
        d.SwapBuffers();
    }
	
    return 0;
}