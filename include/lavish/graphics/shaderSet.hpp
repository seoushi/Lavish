/* 
 * File:   shaderSet.hpp
 * Author: Sean Chapel
 *
 * Created on Dec 22, 2009, 1:30 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _SHADER_SET_HPP
#define	_SHADER_SET_HPP

#include <string>
#include <lavish/platform.hpp>
#include <lavish/shader.hpp>

namespace lavish
{
	
	/**
	 * A class that defines a shader
	 */
	class LAVISH_DECLSPEC ShaderSet
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
		void AddShader(Shader* shader);
		
		/**
         * Removes a shader from the set.
		 * @param the shader to remove from the set
         */
		void RemoveShader(Shader* shader);
		
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
		
    protected:
		
		unsigned int glId;	/**< Holds the opengl shader program id        */
	};
	
} /* lavish */

#endif	/* _SHADER_SET_HPP */

