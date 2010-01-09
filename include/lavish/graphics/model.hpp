/* 
 * File:   model.hpp
 * Author: Sean Chapel
 *
 * Created on Jan 08, 2010, 4:36 PM
 * Copyright 2010 Seoushi Games. All rights reserved.
 */

#ifndef _MODEL_HPP
#define	_MODEL_HPP

#include <string>
#include <lavish/resource.hpp>
#include <lavish/renderable.hpp>
#include <lavish/platform.hpp>

namespace lavish
{	
	/**
	 * A class that defines a model
	 */
	class LAVISH_DECLSPEC Model : public Resource, public Renderable
	{
    public:
		
        /**
         * A default constructor
         */
        Model();
		
        
        /**
         * A constructor that takes a path to a file
         * This will throw an exception if the file cannot be loaded successfully
		 * @param the file name
         */
        Model(std::string filename);
		
        
        /**
         * A default destructor
         */
        ~Model();
		
		
        /**
         * Loads a model from a file
         * @param the path to the file
         * @return if the model was loaded successfully
         */
        bool Load(std::string filename);
		
		
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
		 * Renders the model
		 * @param the transformation of the model
		 */
		void Render(Matrix4* transformations);

		
		VertexBuffer* vertices;
		VertexBuffer* normals;
		VertexBuffer* texCoords;
		
    protected:
		
		bool loadObj();

		std::string file;
	};
	
} /* lavish */

#endif	/* _MODEL_HPP */

