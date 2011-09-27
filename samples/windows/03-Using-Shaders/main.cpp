#include <lavish/graphics/vertexBuffer.hpp>
#include <lavish/core/display.hpp>
#include <lavish/graphics/shaderSet.hpp>
#include <lavish/core/timer.hpp>
#include <lavish/resource/resourceManager.hpp>
#include <lavish/resource/textureResourceLoader.hpp>

#include <fstream>
#include <iostream>
#include <memory>

using namespace lavish;

int main(int argc, char** argv)
{
	std::ofstream fout("output.txt");
    std::cout.rdbuf(fout.rdbuf());


    Display d;
	ResourceManager resMan;

	
    d.Initialize(800, 600, 24, "Sample 03");
	
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
	

	resMan.AddResourceLoader( std::make_shared<TextureResourceLoader>() );
	resMan.Load("data/resources.lrf");
	


	//load shaders
	auto ss = std::make_shared<ShaderSet>();
	auto vert = std::make_shared<Shader>("data/Shader.vert", shader::Vertex);
	auto frag = std::make_shared<Shader>("data/Shader.frag", shader::Fragment);
	
	ss->AddShader(vert);
	ss->AddShader(frag);
	
	ss->Finalize();
	
	GLint uniformId = ss->GetUniformId("translate");
	float transY = 0.0f;
	
	uint time = Timer::GetCurrentGameTime();
	
    while(d.Listener()->Update())
    {
        d.ClearScreen();
		
        d.SetupPerspective(45.0f, 0.1f, 100.0f);
        
		ss->Bind();
		
		// update the shader translation
		transY += ((float)(Timer::GetCurrentGameTime() - time)) / 200.0f;
		time = Timer::GetCurrentGameTime();
		glUniform1f(uniformId, transY);

		
        vbo.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        vbo.Unbind();
		
		ss->Unbind();
		
        d.SwapBuffers();
    }
	
    return 0;
}
