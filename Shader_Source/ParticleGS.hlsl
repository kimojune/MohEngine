#include "globals.hlsli"

struct VSOut
{
    float4 LocalPos : SV_POSITION;
    uint Instance : SV_InstanceID;
};

struct GSOut
{
    float4 Pos : SV_Position;
    float2 UV : TEXCOORD;	
};



[maxvertexcount(6)]
void main(point VSOut In[1], inout TriangleStream<GSOut> output)
{
    GSOut Out[4] = { (GSOut) 0.0f, (GSOut) 0.0f, (GSOut) 0.0f, (GSOut) 0.0f };
    
    if (particles[In[0].Instance].active == 0)
        return;
    
    float3 worldPos = (In[0].LocalPos.xyz) + particles[In[0].Instance].position.xyz;
    float3 viewPos = mul(float4(worldPos, 1.0f), ViewMatrix).xyz;
    float3 mScale = float3(5.0f, 5.0f, 0.0f);
    float3 NewPos[4] =
    {
        viewPos - float3(-0.5f, 0.5f, 0.0f) * mScale,
        viewPos - float3(0.5f, 0.5f, 0.0f) * mScale,
        viewPos - float3(0.5f, -0.5f, 0.0f) * mScale,
        viewPos - float3(-0.5f, -0.5f, 0.0f) * mScale

    };
    
    for (int i = 0; i < 4; ++i)
    {
        Out[i].Pos = mul(float4(NewPos[i], 1.0f), ProjectionMatrix);
    }
    
    Out[0].UV = float2(0.0f, 0.0f);
    Out[1].UV = float2(1.0f, 0.0f);
    Out[2].UV = float2(1.0f, 1.0f);
    Out[3].UV = float2(0.0f, 1.0f);
    
    // 0 -- 1
    // | \  |
    // 3 -- 2
    output.Append(Out[0]);
    output.Append(Out[1]);
    output.Append(Out[2]);
    output.RestartStrip();

    output.Append(Out[0]);
    output.Append(Out[2]);
    output.Append(Out[3]);
    output.RestartStrip();
}
  