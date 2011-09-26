/* 
 * File:   shaderSet.hpp
 * Author: Sean Chapel
 *
 * Created on Dec 22, 2009, 1:30 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _SHADER_SET_HPP
#define	_SHADER_SET_HPP

#include <memory>
#include <string>
#include <lavish/core/platform.hpp>
#include <lavish/graphics/shader.hpp>

namespace lavish
{
	
	/**
	 * A class that defines a shader
	 */
	class ShaderSet
	{
    public:
		
        /**
         * A default constructor
         */
        ShaderSet();
        
        /**
         * A default destructor
         */
        ~ShaderSet();
		
		
		/**
         * Adds a shader to the set for use.
		 * @param the shader to add to the set
         */
		void AddShader(std::shared_ptr<Shader> shader);
		
		/**
         * Removes a shader from the set.
		 * @param the shader to remove from the set
         */
		void RemoveShader(std::shared_ptr<Shader> shader);
		
		/**
         * After all shaders have been added, finalize needs to be called.
         */
		void Finalize();
		
		/**
         * Sets the current shader set to use
         */
		void Bind();
		
		/**
         * Changes the current shader set to use the fixed function pipeline
         */
		void Unbind();
		
		/**
		 * Gets the uniform id given a name
		 * @param the uniform name
		 * @return the uniform id
		 */
		GLint GetUniformId(std::string uniform);
		
    protected:
		
		unsigned int glId;	/**< Holds the opengl shader program id        */
	};
	
} /* lavish */

#endif	/* _SHADER_SET_HPP */

