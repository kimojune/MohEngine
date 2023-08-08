#include "globals.hlsli"


struct GSOut
{
    float4 Pos : SV_Position;
    float2 UV : TEXCOORD;
};

float4 main(GSOut In) : SV_TARGET
{
    float4 Out = (float4) 0.0f;
    
    Out = float4(1.0f, 0.0f, 1.0f, 1.0f);
    
    Out = albedoTexture.Sample(pointSampler, In.UV);

    if (Out.a <= 0.0f)
        discard;
    
    
    return Out;

}