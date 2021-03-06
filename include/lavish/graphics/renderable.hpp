/* 
 * File:   renderable.hpp
 * Author: Sean Chapel
 *
 * Created on May 29, 2009, 10:38 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _RENDERABLE_HPP
#define	_RENDERABLE_HPP

#include <memory>

#include <lavish/math/matrix4.hpp>
#include <lavish/core/platform.hpp>

namespace lavish
{
	
    
	/**
	 * An interface class that defines a Render method
	 */
	class Renderable
	{
    public:
		
        /**
         * A default constructor
         */
        Renderable(){};
		
		
        /**
         * A virtual destructor
         */
        virtual ~Renderable(){};
		
		
        /**
         * A virtual function that should draw an object
         */
        virtual void Render(std::shared_ptr<Matrix4> transformations = 0) = 0;
	};
	
	
} /* lavish */


#endif	/* _RENDERABLE_HPP */

