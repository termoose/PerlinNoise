//
//  PerlinNoise.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 10/2/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "PerlinNoise.h"

#include <math.h>

PerlinNoise::PerlinNoise( float Persistance, int NumberOfOctaves ) : p( Persistance ), n( NumberOfOctaves )
{    
}

PerlinNoise::~PerlinNoise()
{
}

float PerlinNoise::GetNoise( float x )
{
    float Total = 0.0;
    float p = 0.25; // Persistence
    int n = 16; // Number of octaves
    
    for( unsigned int i = 0; i < n; ++i )
    {
        int Freqency = 1<<i; // 2^i
        float Amplitude = pow( p, i );
        
        Total += InterpolatedNoise( x * Freqency ) * Amplitude;
    }
    
    return Total;
}

float PerlinNoise::InterpolatedNoise( float x )
{
    int IntX = (int)x;
    float FraqX = x - IntX;
    
    float v1 = SmoothNoise( IntX );
    float v2 = SmoothNoise( IntX + 1 );
    
    return CosineInterpolation( v1, v2, FraqX );
}

float PerlinNoise::Noise( int x )
{
    x = (x << 13) ^ x;

    return ( 1.0 - ( (x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}

float PerlinNoise::CosineInterpolation( float a, float b, float x )
{
    float ft = x * M_PI;
    float f  = (1 - cos( ft )) * 0.5;
    
    return  a * (1 - f) + b * f;
}

float PerlinNoise::SmoothNoise( float x )
{
    return Noise( x )*0.5 + (Noise( x - 1 ) + Noise( x + 1 ))*0.25;
}