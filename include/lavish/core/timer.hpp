/* 
 * File:   timer.hpp
 * Author: Sean Chapel
 *
 * Created on May 29, 2009, 2:22 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _TIMER_HPP
#define	_TIMER_HPP

#include <lavish/core/platform.hpp>

namespace lavish
{

/**
 * A class for simpler timers.
 * Time is represented as an unsigned int, the value 1000 is 1 second.
 */
class LAVISH_DECLSPEC Timer
{
    public:

        /**
         * A default constructor.
         * The default interval is 0
         */
        Timer();

        
        /**
         * A constructor that takes an interval.
         * @param interval
         */
        Timer(unsigned int interval);


        /**
         * A default destructor
         */
        ~Timer();

        
        /**
         * Changes the timer interval
         * It will also automatically reset the timer
         * @param the new interval
         */
        void SetInterval(unsigned int interval);


        /**
         * Resets the timer
         */
        void Reset();

        /**
         * Tells if the timer has past the interval given
         * @return if the timer is passed the interval or not
         */
        bool IsTimeUp();


        /**
         * A static function that gets the time passed since the game has started
         * @return
         */
        static unsigned int GetCurrentGameTime();

    private:
        unsigned int lastTime;  /**< Holds when the timer was last reset/created	*/
        unsigned int interval;	/**< Holds how long the interval till timer triggers 	*/

};


} /* lavish */

#endif	/* _TIMER_HPP */

