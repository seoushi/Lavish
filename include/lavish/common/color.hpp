/* 
 * File:   color.hpp
 * Author: Sean Chapel
 *
 * Created on May 26, 2009, 11:42 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _COLOR_HPP
#define	_COLOR_HPP

#include <lavish/core/platform.hpp>
#include <lavish/common/types.hpp>

namespace lavish
{


/**
 * The Color class represents a color with red, blue, green and alpha.
 * a color is represented by an unsigned int color components ranging from 0 to 255
 */
class Color
{
    public:

        /**
         * A default constructor
         */
        Color();
        
        /**
         * A constructor will all color components.
         * alpha defaults to fully visable
         * @param r the red component
         * @param g the green component
         * @param b the blue component
         * @param a the alpha component (Optional: default is 1.0f)
         */
        Color(float r, float g, float b, float a = 1.0f);


        //TODO: add vector4 and vector3 constructors

        
        /**
         * @return color's brightness
         */
        float GetBrightness();


        /**
         * @return color's saturation
         */
        float GetSaturation();


        /**
         * @return color's hue
         */
        float GetHue();


        /**
         * @return color's red component
         */
        float R();


        /**
         * @return color's green component
         */
        float G();


        /**
         * @return color's blue component
         */
        float B();


        /**
         * @return color's alpha component
         */
        float A();
        

    private:

        float r; /**< color's red component     */
        float g; /**< color's green component   */
        float b; /**< color's blue component    */
        float a; /**< color's alpha component   */

        
    public:


        /* begin colors, they are uncommented do to the number */

        static Color AliceBlue();

        static Color AntiqueWhite();

        static Color Aqua();

        static Color Aquamarine();

        static Color Azure();

        static Color Beige();

        static Color Bisque();

        static Color Black();

        static Color BlanchedAlmond();

        static Color Blue();

        static Color BlueViolet();

        static Color Brown();

        static Color BurlyWood();

        static Color CadetBlue();

        static Color Chartreuse();

        static Color Chocolate();

        static Color Coral();

        static Color CornflowerBlue();

        static Color Cornsilk();

        static Color Crimson();

        static Color Cyan();

        static Color DarkBlue();

        static Color DarkCyan();

        static Color DarkGoldenrod();

        static Color DarkGray();

        static Color DarkGreen();

        static Color DarkKhaki();

        static Color DarkMagenta();

        static Color DarkOliveGreen();

        static Color DarkOrange();

        static Color DarkOrchid();

        static Color DarkRed();

        static Color DarkSalmon();

        static Color DarkSeaGreen();

        static Color DarkSlateBlue();

        static Color DarkSlateGray();

        static Color DarkTurquoise();

        static Color DarkViolet();

        static Color DeepPink();

        static Color DeepSkyBlue();

        static Color DimGray();

        static Color DodgerBlue();

        static Color Firebrick();

        static Color FloralWhite();

        static Color ForestGreen();

        static Color Fuchsia();

        static Color Gainsboro();

        static Color GhostWhite();

        static Color Gold();

        static Color Goldenrod();

        static Color Gray();

        static Color Green();

        static Color GreenYellow();

        static Color Honeydew();

        static Color HotPink();

        static Color IndianRed();

        static Color Indigo();

        static Color Ivory();

        static Color Khaki();

        static Color Lavender();

        static Color LavenderBlush();

        static Color LawnGreen();

        static Color LemonChiffon();

        static Color LightBlue();

        static Color LightCoral();

        static Color LightCyan();

        static Color LightGoldenrodYellow();

        static Color LightGreen();

        static Color LightGray();

        static Color LightPink();

        static Color LightSalmon();

        static Color LightSeaGreen();

        static Color LightSkyBlue();

        static Color LightSlateGray();

        static Color LightSteelBlue();

        static Color LightYellow();

        static Color Lime();

        static Color LimeGreen();

        static Color Linen();

        static Color Magenta();

        static Color Maroon();

        static Color MediumAquamarine();

        static Color MediumBlue();

        static Color MediumOrchid();

        static Color MediumPurple();

        static Color MediumSeaGreen();

        static Color MediumSlateBlue();

        static Color MediumSpringGreen();

        static Color MediumTurquoise();

        static Color MediumVioletRed();

        static Color MidnightBlue();

        static Color MintCream();

        static Color MistyRose();

        static Color Moccasin();

        static Color NavajoWhite();

        static Color Navy();

        static Color OldLace();

        static Color Olive();

        static Color OliveDrab();

        static Color Orange();

        static Color OrangeRed();

        static Color Orchid();

        static Color PaleGoldenrod();

        static Color PaleGreen();

        static Color PaleTurquoise();

        static Color PaleVioletRed();

        static Color PapayaWhip();

        static Color PeachPuff();

        static Color Peru();

        static Color Pink();

        static Color Plum();

        static Color PowderBlue();

        static Color Purple();

        static Color Red();

        static Color RosyBrown();

        static Color RoyalBlue();

        static Color SaddleBrown();

        static Color Salmon();

        static Color SandyBrown();

        static Color SeaGreen();

        static Color SeaShell();

        static Color Sienna();

        static Color Silver();

        static Color SkyBlue();

        static Color SlateBlue();

        static Color SlateGray();

        static Color Snow();

        static Color SpringGreen();

        static Color SteelBlue();

        static Color Tan();

        static Color Teal();

        static Color Thistle();

        static Color Tomato();

        static Color Turquoise();

        static Color Violet();

        static Color Wheat();

        static Color White();

        static Color WhiteSmoke();

        static Color Yellow();

        static Color YellowGreen();
};

} /* namespace lavish */

#endif	/* _COLOR_HPP */

