
/*
 * File:   color.cpp
 * Author: Sean Chapel
 *
 * Created on May 26, 2009, 11:42 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <lavish/common/color.hpp>
#include <algorithm>

using namespace std;

namespace lavish
{


Color::Color()
{
    r =0.0f;
    g =0.0f;
    b =0.0f;
    a =0.0f;
}

Color::Color(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}


float Color::GetBrightness()
{
    float minval = (float)min(R(), min(G(), B()));
    float maxval = (float)max(R(), max(G(), B()));

    return (float)(maxval + minval) / 510.0f;
}


float Color::GetSaturation()
{
    float minval = (float)min(R(), min(G(), B()));
    float maxval = (float)max(R(), max(G(), B()));

    if (maxval == minval)
    {
        return 0.0f;
    }
    

    int sum = (int) (maxval + minval);
    
    if (sum > 255)
    {
        sum = 510 - sum;
    }

    return (float)(maxval - minval) / (float)sum;
}


float Color::GetHue()
{
    int r = (int)R();
    int g = (int)G();
    int b = (int)B();

    float minval = (float)min(r, min(g, b));
    float maxval = (float)max(r, max(g, b));

    if (maxval == minval)
    {
        return 0.0f;
    }

    float diff = (float)(maxval - minval);
    float rnorm = (maxval - r) / diff;
    float gnorm = (maxval - g) / diff;
    float bnorm = (maxval - b) / diff;

    float hue = 0.0f;
    if (r == maxval)
    {
        hue = 60.0f * (6.0f + bnorm - gnorm);
    }
    if (g == maxval)
    {
        hue = 60.0f * (2.0f + rnorm - bnorm);
    }
    if (b == maxval)
    {
        hue = 60.0f * (4.0f + gnorm - rnorm);
    }
    if (hue > 360.0f)
    {
        hue = hue - 360.0f;
    }

    return hue;
}


float Color::R()
{
    return r;
}


float Color::G()
{
    return g;
}


float Color::B()
{
    return b;
}


float Color::A()
{
    return a;
}


Color Color::AliceBlue()
{
    return Color(240.0f / 255.0f, 248.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::AntiqueWhite()
{
    return Color(250.0f / 255.0f, 235.0f / 255.0f, 215.0f / 255.0f);
}

Color Color::Aqua()
{
    return Color(0.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::Aquamarine()
{
    return Color(127.0f / 255.0f, 255.0f / 255.0f, 212.0f / 255.0f);
}

Color Color::Azure()
{
    return Color(240.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::Beige()
{
    return Color(245.0f / 255.0f, 245.0f / 255.0f, 220.0f / 255.0f);
}

Color Color::Bisque()
{
    return Color(255.0f / 255.0f, 228.0f / 255.0f, 196.0f / 255.0f);
}

Color Color::Black()
{
    return Color(0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::BlanchedAlmond()
{
    return Color(255.0f / 255.0f, 235.0f / 255.0f, 205.0f / 255.0f);
}

Color Color::Blue()
{
    return Color(0.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::BlueViolet()
{
    return Color(138.0f / 255.0f, 43.0f / 255.0f, 226.0f / 255.0f);
}

Color Color::Brown()
{
    return Color(165.0f / 255.0f, 42.0f / 255.0f, 42.0f / 255.0f);
}

Color Color::BurlyWood()
{
    return Color(222.0f / 255.0f, 184.0f / 255.0f, 135.0f / 255.0f);
}

Color Color::CadetBlue()
{
    return Color(95.0f / 255.0f, 158.0f / 255.0f, 160.0f / 255.0f);
}

Color Color::Chartreuse()
{
    return Color(127.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::Chocolate()
{
    return Color(210.0f / 255.0f, 105.0f / 255.0f, 30.0f / 255.0f);
}

Color Color::Coral()
{
    return Color(255.0f / 255.0f, 127.0f / 255.0f, 80.0f / 255.0f);
}

Color Color::CornflowerBlue()
{
    return Color(100.0f / 255.0f, 149.0f / 255.0f, 237.0f / 255.0f);
}

Color Color::Cornsilk()
{
    return Color(255.0f / 255.0f, 248.0f / 255.0f, 220.0f / 255.0f);
}

Color Color::Crimson()
{
    return Color(220.0f / 255.0f, 20.0f / 255.0f, 60.0f / 255.0f);
}

Color Color::Cyan()
{
    return Color(0.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
}


Color Color::DarkBlue()
{
    return Color(0.0f / 255.0f, 0.0f / 255.0f, 139.0f / 255.0f);
}

Color Color::DarkCyan()
{
    return Color(0.0f / 255.0f, 139.0f / 255.0f, 139.0f / 255.0f);
}

Color Color::DarkGoldenrod()
{
    return Color(184.0f / 255.0f, 134.0f / 255.0f, 11.0f / 255.0f);
}

Color Color::DarkGray()
{
    return Color(169.0f / 255.0f, 169.0f / 255.0f, 169.0f / 255.0f);
}

Color Color::DarkGreen()
{
    return Color(0.0f / 255.0f, 100.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::DarkKhaki()
{
    return Color(189.0f / 255.0f, 183.0f / 255.0f, 107.0f / 255.0f);
}

Color Color::DarkMagenta()
{
    return Color(139.0f / 255.0f, 0.0f / 255.0f, 139.0f / 255.0f);
}

Color Color::DarkOliveGreen()
{
    return Color(85.0f / 255.0f, 107.0f / 255.0f, 47.0f / 255.0f);
}

Color Color::DarkOrange()
{
    return Color(255.0f / 255.0f, 140.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::DarkOrchid()
{
    return Color(153.0f / 255.0f, 50.0f / 255.0f, 204.0f / 255.0f);
}

Color Color::DarkRed()
{
    return Color(139.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::DarkSalmon()
{
    return Color(233.0f / 255.0f, 150.0f / 255.0f, 122.0f / 255.0f);
}

Color Color::DarkSeaGreen()
{
    return Color(143.0f / 255.0f, 188.0f / 255.0f, 139.0f / 255.0f);
}

Color Color::DarkSlateBlue()
{
    return Color(72.0f / 255.0f, 61.0f / 255.0f, 139.0f / 255.0f);
}

Color Color::DarkSlateGray()
{
    return Color(47.0f / 255.0f, 79.0f / 255.0f, 79.0f / 255.0f);
}

Color Color::DarkTurquoise()
{
    return Color(0.0f / 255.0f, 206.0f / 255.0f, 209.0f / 255.0f);
}

Color Color::DarkViolet()
{
    return Color(148.0f / 255.0f, 0.0f / 255.0f, 211.0f / 255.0f);
}

Color Color::DeepPink()
{
    return Color(255.0f / 255.0f, 20.0f / 255.0f, 147.0f / 255.0f);
}

Color Color::DeepSkyBlue()
{
    return Color(0.0f / 255.0f, 191.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::DimGray()
{
    return Color(105.0f / 255.0f, 105.0f / 255.0f, 105.0f / 255.0f);
}

Color Color::DodgerBlue()
{
    return Color(30.0f / 255.0f, 144.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::Firebrick()
{
    return Color(178.0f / 255.0f, 34.0f / 255.0f, 34.0f / 255.0f);
}

Color Color::FloralWhite()
{
    return Color(255.0f / 255.0f, 250.0f / 255.0f, 240.0f / 255.0f);
}

Color Color::ForestGreen()
{
    return Color(34.0f / 255.0f, 139.0f / 255.0f, 34.0f / 255.0f);
}

Color Color::Fuchsia()
{
    return Color(255.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::Gainsboro()
{
    return Color(220.0f / 255.0f, 220.0f / 255.0f, 220.0f / 255.0f);
}

Color Color::GhostWhite()
{
    return Color(248.0f / 255.0f, 248.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::Gold()
{
    return Color(255.0f / 255.0f, 215.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::Goldenrod()
{
    return Color(218.0f / 255.0f, 165.0f / 255.0f, 32.0f / 255.0f);
}

Color Color::Gray()
{
    return Color(128.0f / 255.0f, 128.0f / 255.0f, 128.0f / 255.0f);
}

Color Color::Green()
{
    return Color(0.0f / 255.0f, 128.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::GreenYellow()
{
    return Color(173.0f / 255.0f, 255.0f / 255.0f, 47.0f / 255.0f);
}

Color Color::Honeydew()
{
    return Color(240.0f / 255.0f, 255.0f / 255.0f, 240.0f / 255.0f);
}

Color Color::HotPink()
{
    return Color(255.0f / 255.0f, 105.0f / 255.0f, 180.0f / 255.0f);
}

Color Color::IndianRed()
{
    return Color(205.0f / 255.0f, 92.0f / 255.0f, 92.0f / 255.0f);
}

Color Color::Indigo()
{
    return Color(75.0f / 255.0f, 0.0f / 255.0f, 130.0f / 255.0f);
}

Color Color::Ivory()
{
    return Color(255.0f / 255.0f, 255.0f / 255.0f, 240.0f / 255.0f);
}

Color Color::Khaki()
{
    return Color(240.0f / 255.0f, 230.0f / 255.0f, 140.0f / 255.0f);
}

Color Color::Lavender()
{
    return Color(230.0f / 255.0f, 230.0f / 255.0f, 250.0f / 255.0f);
}


Color Color::LavenderBlush()
{
    return Color(255.0f / 255.0f, 240.0f / 255.0f, 245.0f / 255.0f);
}

Color Color::LawnGreen()
{
    return Color(124.0f / 255.0f, 252.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::LemonChiffon()
{
    return Color(255.0f / 255.0f, 250.0f / 255.0f, 205.0f / 255.0f);
}

Color Color::LightBlue()
{
    return Color(173.0f / 255.0f, 216.0f / 255.0f, 230.0f / 255.0f);
}

Color Color::LightCoral()
{
    return Color(240.0f / 255.0f, 128.0f / 255.0f, 128.0f / 255.0f);
}

Color Color::LightCyan()
{
    return Color(224.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::LightGoldenrodYellow()
{
    return Color(250.0f / 255.0f, 250.0f / 255.0f, 210.0f / 255.0f);
}

Color Color::LightGreen()
{
    return Color(144.0f / 255.0f, 238.0f / 255.0f, 144.0f / 255.0f);
}

Color Color::LightGray()
{
    return Color(211.0f / 255.0f, 211.0f / 255.0f, 211.0f / 255.0f);
}

Color Color::LightPink()
{
    return Color(255.0f / 255.0f, 182.0f / 255.0f, 193.0f / 255.0f);
}

Color Color::LightSalmon()
{
    return Color(255.0f / 255.0f, 160.0f / 255.0f, 122.0f / 255.0f);
}

Color Color::LightSeaGreen()
{
    return Color(32.0f / 255.0f, 178.0f / 255.0f, 170.0f / 255.0f);
}

Color Color::LightSkyBlue()
{
    return Color(135.0f / 255.0f, 206.0f / 255.0f, 250.0f / 255.0f);
}

Color Color::LightSlateGray()
{
    return Color(119.0f / 255.0f, 136.0f / 255.0f, 153.0f / 255.0f);
}

Color Color::LightSteelBlue()
{
    return Color(176.0f / 255.0f, 196.0f / 255.0f, 222.0f / 255.0f);
}

Color Color::LightYellow()
{
    return Color(255.0f / 255.0f, 255.0f / 255.0f, 224.0f / 255.0f);
}

Color Color::Lime()
{
    return Color(0.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::LimeGreen()
{
    return Color(50.0f / 255.0f, 205.0f / 255.0f, 50.0f / 255.0f);
}

Color Color::Linen()
{
    return Color(250.0f / 255.0f, 240.0f / 255.0f, 230.0f / 255.0f);
}

Color Color::Magenta()
{
    return Color(255.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f);
}

Color Color::Maroon()
{
    return Color(128.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::MediumAquamarine()
{
    return Color(102.0f / 255.0f, 205.0f / 255.0f, 170.0f / 255.0f);
}

Color Color::MediumBlue()
{
    return Color(0.0f / 255.0f, 0.0f / 255.0f, 205.0f / 255.0f);
}

Color Color::MediumOrchid()
{
    return Color(186.0f / 255.0f, 85.0f / 255.0f, 211.0f / 255.0f);
}

Color Color::MediumPurple()
{
    return Color(147.0f / 255.0f, 112.0f / 255.0f, 219.0f / 255.0f);
}

Color Color::MediumSeaGreen()
{
    return Color(60.0f / 255.0f, 179.0f / 255.0f, 113.0f / 255.0f);
}

Color Color::MediumSlateBlue()
{
    return Color(123.0f / 255.0f, 104.0f / 255.0f, 238.0f / 255.0f);
}

Color Color::MediumSpringGreen()
{
    return Color(0.0f / 255.0f, 250.0f / 255.0f, 154.0f / 255.0f);
}

Color Color::MediumTurquoise()
{
    return Color(72.0f / 255.0f, 209.0f / 255.0f, 204.0f / 255.0f);
}

Color Color::MediumVioletRed()
{
    return Color(199.0f / 255.0f, 21.0f / 255.0f, 133.0f / 255.0f);
}

Color Color::MidnightBlue()
{
    return Color(25.0f / 255.0f, 25.0f / 255.0f, 112.0f / 255.0f);
}

Color Color::MintCream()
{
    return Color(245.0f / 255.0f, 255.0f / 255.0f, 250.0f / 255.0f);
}

Color Color::MistyRose()
{
    return Color(255.0f / 255.0f, 228.0f / 255.0f, 225.0f / 255.0f);
}

Color Color::Moccasin()
{
    return Color(255.0f / 255.0f, 228.0f / 255.0f, 181.0f / 255.0f);
}

Color Color::NavajoWhite()
{
    return Color(255.0f / 255.0f, 222.0f / 255.0f, 173.0f / 255.0f);
}

Color Color::Navy()
{
    return Color(0.0f / 255.0f, 0.0f / 255.0f, 128.0f / 255.0f);
}

Color Color::OldLace()
{
    return Color(253.0f / 255.0f, 245.0f / 255.0f, 230.0f / 255.0f);
}

Color Color::Olive()
{
    return Color(128.0f / 255.0f, 128.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::OliveDrab()
{
    return Color(107.0f / 255.0f, 142.0f / 255.0f, 35.0f / 255.0f);
}

Color Color::Orange()
{
    return Color(255.0f / 255.0f, 165.0f / 255.0f, 0.0f / 255.0f);
}


Color Color::OrangeRed()
{
    return Color(255.0f / 255.0f, 69.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::Orchid()
{
    return Color(218.0f / 255.0f, 112.0f / 255.0f, 214.0f / 255.0f);
}

Color Color::PaleGoldenrod()
{
    return Color(238.0f / 255.0f, 232.0f / 255.0f, 170.0f / 255.0f);
}

Color Color::PaleGreen()
{
    return Color(152.0f / 255.0f, 251.0f / 255.0f, 152.0f / 255.0f);
}

Color Color::PaleTurquoise()
{
    return Color(175.0f / 255.0f, 238.0f / 255.0f, 238.0f / 255.0f);
}

Color Color::PaleVioletRed()
{
    return Color(219.0f / 255.0f, 112.0f / 255.0f, 147.0f / 255.0f);
}

Color Color::PapayaWhip()
{
    return Color(255.0f / 255.0f, 239.0f / 255.0f, 213.0f / 255.0f);
}

Color Color::PeachPuff()
{
    return Color(255.0f / 255.0f, 218.0f / 255.0f, 185.0f / 255.0f);
}

Color Color::Peru()
{
    return Color(205.0f / 255.0f, 133.0f / 255.0f, 63.0f / 255.0f);
}

Color Color::Pink()
{
    return Color(255.0f / 255.0f, 192.0f / 255.0f, 203.0f / 255.0f);
}

Color Color::Plum()
{
    return Color(221.0f / 255.0f, 160.0f / 255.0f, 221.0f / 255.0f);
}

Color Color::PowderBlue()
{
    return Color(176.0f / 255.0f, 224.0f / 255.0f, 230.0f / 255.0f);
}

Color Color::Purple()
{
    return Color(128.0f / 255.0f, 0.0f / 255.0f, 128.0f / 255.0f);
}

Color Color::Red()
{
    return Color(255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::RosyBrown()
{
    return Color(188.0f / 255.0f, 143.0f / 255.0f, 143.0f / 255.0f);
}

Color Color::RoyalBlue()
{
    return Color(65.0f / 255.0f, 105.0f / 255.0f, 225.0f / 255.0f);
}

Color Color::SaddleBrown()
{
    return Color(139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f);
}

Color Color::Salmon()
{
    return Color(250.0f / 255.0f, 128.0f / 255.0f, 114.0f / 255.0f);
}

Color Color::SandyBrown()
{
    return Color(244.0f / 255.0f, 164.0f / 255.0f, 96.0f / 255.0f);
}

Color Color::SeaGreen()
{
    return Color(46.0f / 255.0f, 139.0f / 255.0f, 87.0f / 255.0f);
}

Color Color::SeaShell()
{
    return Color(255.0f / 255.0f, 245.0f / 255.0f, 238.0f / 255.0f);
}

Color Color::Sienna()
{
    return Color(160.0f / 255.0f, 82.0f / 255.0f, 45.0f / 255.0f);
}

Color Color::Silver()
{
    return Color(192.0f / 255.0f, 192.0f / 255.0f, 192.0f / 255.0f);
}

Color Color::SkyBlue()
{
    return Color(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f);
}

Color Color::SlateBlue()
{
    return Color(106.0f / 255.0f, 90.0f / 255.0f, 205.0f / 255.0f);
}

Color Color::SlateGray()
{
    return Color(112.0f / 255.0f, 128.0f / 255.0f, 144.0f / 255.0f);
}

Color Color::Snow()
{
    return Color(255.0f / 255.0f, 250.0f / 255.0f, 250.0f / 255.0f);
}

Color Color::SpringGreen()
{
    return Color(0.0f / 255.0f, 255.0f / 255.0f, 127.0f / 255.0f);
}

Color Color::SteelBlue()
{
    return Color(70.0f / 255.0f, 130.0f / 255.0f, 180.0f / 255.0f);
}

Color Color::Tan()
{
    return Color(210.0f / 255.0f, 180.0f / 255.0f, 140.0f / 255.0f);
}

Color Color::Teal()
{
    return Color(0.0f / 255.0f, 128.0f / 255.0f, 128.0f / 255.0f);
}

Color Color::Thistle()
{
    return Color(216.0f / 255.0f, 191.0f / 255.0f, 216.0f / 255.0f);
}

Color Color::Tomato()
{
    return Color(255.0f / 255.0f, 99.0f / 255.0f, 71.0f / 255.0f);
}

Color Color::Turquoise()
{
    return Color(64.0f / 255.0f, 224.0f / 255.0f, 208.0f / 255.0f);
}

Color Color::Violet()
{
    return Color(238.0f / 255.0f, 130.0f / 255.0f, 238.0f / 255.0f);
}

Color Color::Wheat()
{
    return Color(245.0f / 255.0f, 222.0f / 255.0f, 179.0f / 255.0f);
}

Color Color::White()
{
    return Color(1.0f, 1.0f, 1.0f);
}

Color Color::WhiteSmoke()
{
    return Color(245.0f / 255.0f, 245.0f / 255.0f, 245.0f / 255.0f);
}

Color Color::Yellow()
{
    return Color(255.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f);
}

Color Color::YellowGreen()
{
    return Color(154.0f / 255.0f, 205.0f / 255.0f, 50.0f / 255.0f);
}

} /* namespace lavish */

