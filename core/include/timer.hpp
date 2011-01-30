/* 
 * File:   timer.hpp
 *
 * Copyright © 2011, Sean Chapel
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _TIMER_HPP
#define	_TIMER_HPP

#include "types.hpp"

namespace lavish
{


/**
 * A class for simpler timers.
 * Time is represented in milliseconds.
 */
class Timer
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
        Timer(uint32 interval);


        /**
         * A default destructor
         */
        ~Timer();

        
        /**
         * Changes the timer interval
         * It will also automatically reset the timer
         * @param the new interval
         */
        void setInterval(uint32 interval);


        /**
         * Resets the timer
         */
        void reset();

        /**
         * Tells if the timer has past the interval given
         * @return if the timer is passed the interval or not
         */
        bool isTimeUp();


        /**
         * A static function that gets the current time
         * @return the current time in milliseconds
         */
        static uint32 now();

    private:
        uint32 _lastTime; /**< Holds when the timer was last reset/created    */
        uint32 _interval; /**< Holds how long till timer triggers             */

};


} /* lavish namespace */

#endif	/* _TIMER_HPP */

