#include "globals.hlsli"
RWStructuredBuffer<Particle> ParticleBuffer : register(u0);
RWStructuredBuffer<ParticleShared> ParticleSharedBuffer : register(u1);

[numthreads(128, 1, 1)]
void main(uint3 DTid : SV_DispatchThreadID)
{
    if (elementCount <= DTid.x)
        return;
    
       if(ParticleBuffer[DTid.x].active == 0)
       {
            while (0 < ParticleSharedBuffer[0].ActiveSharedCount)
            {
                int origin = ParticleSharedBuffer[0].ActiveSharedCount;
                int exchange = origin - 1;
            
            InterlockedCompareExchange(ParticleSharedBuffer[0].ActiveSharedCount
                , origin, exchange, exchange);
            
                if(origin == exchange)
                {
                    ParticleBuffer[DTid.x].active = 1;
                    break;
                }
            
            }
                
        if (ParticleBuffer[DTid.x].active == 1)
        {
            // 랜덤값으로 위치와 방향을 설정한다.
            // 샘플링을 시도할 UV 를 계산한다.
            float4 vRandom = (float4) 0.f;

            float2 vUV = float2((float) DTid.x / elementCount, 0.5f);
            vUV.x += elapsedTime;
            vUV.y += sin((vUV.x + elapsedTime) * 3.141592f + 2.f * 10.f) * 0.5f;

            vRandom = float4
            (
                  GaussianBlur(vUV + float2(0.f, 0.f)).x
                , GaussianBlur(vUV + float2(0.1f, 0.f)).x
                , GaussianBlur(vUV + float2(0.2f, 0.f)).x
                , GaussianBlur(vUV + float2(0.3f, 0.f)).x
            );
            
            ParticleBuffer[DTid.x].position.xyz = vRandom.xyz * 50.0f;
            ParticleBuffer[DTid.x].position.x -= 10.0f;
            ParticleBuffer[DTid.x].position.y -= 20.0f;
            ParticleBuffer[DTid.x].position.z = 0.0f;
          
            ParticleBuffer[DTid.x].speed *= vRandom * 5.0f;
            ParticleBuffer[DTid.x].endTime *= vRandom * elapsedTime;

        }
        
        }
    
    else
    {
        ParticleBuffer[DTid.x].position 
        += ParticleBuffer[DTid.x].direction * ParticleBuffer[DTid.x].speed * deltaTime;
        
        if (ParticleBuffer[DTid.x].endTime < elapsedTime)
        {
            ParticleBuffer[DTid.x].active = 0;
        }

    }
    
}