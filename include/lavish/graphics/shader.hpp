/* 
 * File:   shader.hpp
 * Author: Sean Chapel
 *
 * Created on Dec 21, 2009, 5:18 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _SHADER_HPP
#define	_SHADER_HPP

#include <string>
#include <lavish/core/resource.hpp>
#include <lavish/core/platform.hpp>

namespace lavish
{
	namespace shader
	{
		typedef enum
		{
			Vertex = GL_VERTEX_SHADER,
			Fragment = GL_FRAGMENT_SHADER,
		}Type;
	}
	
	// forward declaration
	class ShaderSet;
	
	/**
	 * A class that defines a shader
	 */
	class LAVISH_DECLSPEC Shader : public Resource
	{
		friend class ShaderSet;
		
    public:
		
        /**
         * A default constructor
         */
        Shader();
		
        
        /**
         * A constructor that takes a path to a file and a type
         * This will throw an exception if the file cannot be loaded successfully
         */
        Shader(std::string filename, shader::Type type);
		
        
        /**
         * A default destructor
         */
        ~Shader();
		
		
        /**
         * Loads a shader from a file
         * @param the path to the file
		 * @param the type of shader, fragment or vertex
         * @return if the shader was loaded successfully
         */
        bool Load(std::string filename, shader::Type type);
		
		
        /**
         * Virtual function from the resource class
         */
        virtual void Dispose();
		
		
        /**
         * Reloads the shader from file
         * @return if the shader was loaded successfully
         */
        bool Reload();
		
		
		/**
         * Gets the type of the shader
         * @return type of the shader
         */
		shader::Type Type();
		
    protected:
		
		unsigned int glId;	/**< Holds the opengl shader id        */
		shader::Type type;
	};
	
} /* lavish */

#endif	/* _SHADER_HPP */

