#include "globals.hlsli"
struct VSIn
{
    float3 Pos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};

struct VSOut
{
    float4 Pos : SV_Position;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};

float4 main(VSOut In) : SV_TARGET
{
    //return In.Color;
    float4 color = (float) 0.0f;
    
    //if (In.UV.y < 0.2f)
    //{
    //    discard;
    //}
    //else
    //{
    //    color = albedoTexture.Sample(anisotropicSampler, In.UV);
    //}
    
    
    color = albedoTexture.Sample(anisotropicSampler, In.UV);
    
    
    color = albedoTexture.Sample(pointSampler, In.UV);
    
    return color;
}