
cbuffer Projection : register(b0)
{
	float4x4 GProjectionMatrix;
};

cbuffer cbMtl : register(b0)
{
    float4 BaseColor;
    float Roughness;
    float Metalic;
    float Specular;
    float Alpha;
    float Emissive;
}


float4 VS(float4 position : POSITION) : SV_POSITION
{
	return position;
}
