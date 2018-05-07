#pragma once

#include <cmath>

// 1D Perlin noise class for terrain generation
class PerlinNoise
{
public:
 PerlinNoise(float persistance, int number_of_octaves)
   : p(persistance), n(number_of_octaves) {}

  float get_noise(float x) const
  {
    float total = 0.0;

    for(unsigned int i = 0; i < n; ++i)
    {
      unsigned int freqency = 1<<i; // 2^i
      float amplitude = pow(p, i);

      total += interpolated_noise(x * freqency) * amplitude;
    }

    return total;
  }

 private:
  float noise(int x) const
  {
    x = (x << 13) ^ x;
    return (1.0 - ((x*(x*x*15731+789221)+1376312589) & 0x7fffffff) / 1073741824.0);
  }

  float smooth_noise(float x) const
  {
    return noise(x)*0.5 + (noise(x - 1) + noise(x + 1))*0.25;
  }

  float cosine_interpolation(float a, float b, float x) const
  {
    float ft = x * M_PI;
    float f  = (1 - cos( ft )) * 0.5;
    
    return  a * (1 - f) + b * f;
  }

  float interpolated_noise(float x) const
  {
    double frac_part, int_part;
    frac_part = modf(x, &int_part);

    float v1 = smooth_noise(int_part);
    float v2 = smooth_noise(int_part + 1);

    return cosine_interpolation(v1, v2, frac_part);
  }

  float p;
  int n;
};
