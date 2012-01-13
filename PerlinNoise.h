#ifndef PerlinNoise_h
#define PerlinNoise_h

// 1D Perlin noise class for terrain generation
class PerlinNoise
{
public:
    PerlinNoise( float Persistance, int NumberOfOctaves );
    ~PerlinNoise();
    
    float GetNoise( float x ) const;
    
private:
    float Noise( int x ) const;
    float SmoothNoise( float x ) const;
    float CosineInterpolation( float a, float b, float x ) const;
    float InterpolatedNoise( float x ) const;
    
    float p;
    int n;

};

#endif
