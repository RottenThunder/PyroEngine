#pragma once
#include "stdint.h"

namespace PyroEngine
{
	struct Colour
	{
		float red;
		float green;
		float blue;
		float alpha;

		Colour() = default;
		Colour(float c, float a = 1.0f) : red(c), green(c), blue(c), alpha(a) {}
		Colour(float r, float g, float b, float a = 1.0f) : red(r), green(g), blue(b), alpha(a) {}

		uint8_t GetPixelValueRed() { return red * 255.0f; }
		uint8_t GetPixelValueGreen() { return green * 255.0f; }
		uint8_t GetPixelValueBlue() { return blue * 255.0f; }
		uint8_t GetPixelValueAlpha() { return alpha * 255.0f; }
		uint32_t GetPixelValue()
		{ 
			uint32_t pixel = 0;
			pixel |= GetPixelValueRed();
			pixel <<= 24;
			pixel |= GetPixelValueGreen();
			pixel <<= 16;
			pixel |= GetPixelValueBlue();
			pixel <<= 8;
			pixel |= GetPixelValueAlpha();
			return pixel;
		}
	};
}