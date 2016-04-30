#pragma once

namespace MyMaths
{
	float RoundToTenth(float num)
	{
		float a = num;
		float b = a - (int)a;
		int c = b * 10;
		float e = (float)c / 10;

		return e;
	}
	float RoundToWhole(float num)
	{
		float a = num;
		float b = a - (int)a;
		if (b >= 0.5) return (int)a + 1;
		else return (int)a;
	}
	float Root(float num, float power)
	{
		float pwr = num;
		for (int i = 1; i < power; i++)
		{
			pwr *= num;
		}
		return pwr;
	}
	float SqrArea(float w, float h)
	{
		return w * h;
	}
	float SqrPerim(float w, float h)
	{
		return 2 * (w + h);
	}
	float CircCumferenceR(float r)
	{
		return 2 * r * 3.14159;
	}
	float CircCumferenceD(float d)
	{
		return d * 3.14159;
	}
	float CircAreaR(float r)
	{
		return r * r * 3.14159;
	}
	float CircAreaD(float d)
	{
		return 2 * d * d * 3.14159;
	}
	float CylAreaR(float r, float h)
	{
		return (2 * r * 3.14159 * h) + (2 * r * r * 3.14159);
	}
	float CylAreaD(float d, float h)
	{
		return (d * 3.14159 * h) + (d * (d / 2) * 3.14159);
	}
	float SphAreaR(float r)
	{
		return (4 / 3) * 3.14159 * r * r * r;
	}
	float SphAreaD(float d)
	{
		return (4 / 3) * 3.14159 * (d / 2) * (d / 2) * (d / 2);
	}
}
