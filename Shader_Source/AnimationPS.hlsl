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
    float3 WorldPos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};


float4 main(VSOut In) : SV_TARGET
{
    float4 color = (float4) 0.0f;
    
    // 1200 1032 // 120 130
    // 1080 -> 540
    // -540 + 1200 

    
    if (animationType == 1)
    {
        
        float2 diff = (outputSize - SpriteSize) / 2.0f;
        float2 UV = (SpriteLeftTop - diff - SpriteOffset)
                + (outputSize * In.UV);
    
        if (UV.x < SpriteLeftTop.x || UV.x > SpriteLeftTop.x + SpriteSize.x
        || UV.y < SpriteLeftTop.y || UV.y > SpriteLeftTop.y + SpriteSize.y)
            discard;
        
        UV.x = -1 * UV.x;
        color = atlasTexture.Sample(pointSampler, UV);
    }
    
    if(animationType == 2)
    {
        float2 diff = (outputSize - SpriteSize) / 2.0f;
        float2 UV = (SpriteLeftTop - diff - SpriteOffset)
                + (outputSize * In.UV);
    
        if (UV.x < SpriteLeftTop.x || UV.x > SpriteLeftTop.x + SpriteSize.x
        || UV.y < SpriteLeftTop.y || UV.y > SpriteLeftTop.y + SpriteSize.y)
            discard;
        
        //UV.x = -1 * UV.x;
        UV.y = -1 * UV.y;
        color = atlasTexture.Sample(pointSampler, UV);
    }
    
    if (animationType == 0)
    {
        float2 diff = (outputSize - SpriteSize) / 2.0f;
        float2 UV = (SpriteLeftTop - diff - SpriteOffset)
                + (outputSize * In.UV);
    
        if (UV.x < SpriteLeftTop.x || UV.x > SpriteLeftTop.x + SpriteSize.x
        || UV.y < SpriteLeftTop.y || UV.y > SpriteLeftTop.y + SpriteSize.y)
            discard;
        
        color = atlasTexture.Sample(pointSampler, UV);
    }

    float4 lightColor = float4(1.0f, 1.0f, 1.0f, 1.0f);
    
    for (int i = 0; i < 2; i++)
    {
        CalculateLight2D(lightColor, In.WorldPos, i);
    }
    
    color *= lightColor;
    
    return color;
}