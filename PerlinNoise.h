#ifndef BridgeRunner_PerlinNoise_h
#define BridgeRunner_PerlinNoise_h

// 1D Perlin noise class for terrain generation
class PerlinNoise
{
public:
    PerlinNoise( float Persistance, int NumberOfOctaves );
    ~PerlinNoise();
    
    float GetNoise( float x );
    
private:
    float Noise( int x );
    float SmoothNoise( float x );
    float CosineInterpolation( float a, float b, float x );
    float InterpolatedNoise( float x );
    
    float p;
    int n;

};

#endif
