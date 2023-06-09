//structBuffer

struct VSIn
{
    float3 Pos : POSITION;
    float4 Color : COLOR;
};

struct VSOut
{
    float4 Pos : SV_Position;
    float4 Color : COLOR;
};



cbuffer Transform : register(b0)
{
    float4 pos;
    
}

cbuffer Color : register(b1)
{
    float4 color;
    
}


VSOut main(VSIn In)
{
    VSOut Out = (VSOut)0.0f;

    Out.Pos = float4(In.Pos * pos.z , 1.0f);
    Out.Pos.x += pos.x;
    Out.Pos.y += pos.y;
    Out.Color = color;

    return Out;
}