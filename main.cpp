#include <Windows.h>
#include <tchar.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl/client.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using namespace Microsoft::WRL;

#pragma comment(lib, "d3d11")
#pragma comment(lib, "d3dcompiler")

#define DUMP_DESC_MEMBER(member) out << #member << " : " << desc.member << endl

ostream & operator<<(ostream & out, const D3D11_SHADER_DESC & desc)
{
	DUMP_DESC_MEMBER(Version);
	DUMP_DESC_MEMBER(Creator);
	DUMP_DESC_MEMBER(Flags);
	DUMP_DESC_MEMBER(ConstantBuffers);
	DUMP_DESC_MEMBER(BoundResources);
	DUMP_DESC_MEMBER(InputParameters);
	DUMP_DESC_MEMBER(OutputParameters);
	DUMP_DESC_MEMBER(TempRegisterCount);
	DUMP_DESC_MEMBER(TempArrayCount);
	DUMP_DESC_MEMBER(DefCount);
	DUMP_DESC_MEMBER(TextureNormalInstructions);
	DUMP_DESC_MEMBER(TextureLoadInstructions);
	DUMP_DESC_MEMBER(TextureCompInstructions);
	DUMP_DESC_MEMBER(TextureBiasInstructions);
	DUMP_DESC_MEMBER(TextureGradientInstructions);
	DUMP_DESC_MEMBER(FloatInstructionCount);
	DUMP_DESC_MEMBER(IntInstructionCount);
	DUMP_DESC_MEMBER(UintInstructionCount);
	DUMP_DESC_MEMBER(StaticFlowControlCount);
	DUMP_DESC_MEMBER(DynamicFlowControlCount);
	DUMP_DESC_MEMBER(MacroInstructionCount);
	DUMP_DESC_MEMBER(ArrayInstructionCount);
	DUMP_DESC_MEMBER(CutInstructionCount);
	DUMP_DESC_MEMBER(EmitInstructionCount);
	DUMP_DESC_MEMBER(GSOutputTopology);
	DUMP_DESC_MEMBER(GSMaxOutputVertexCount);
	DUMP_DESC_MEMBER(InputPrimitive);
	DUMP_DESC_MEMBER(PatchConstantParameters);
	DUMP_DESC_MEMBER(cGSInstanceCount);
	DUMP_DESC_MEMBER(cControlPoints);
	DUMP_DESC_MEMBER(HSOutputPrimitive);
	DUMP_DESC_MEMBER(HSPartitioning);
	DUMP_DESC_MEMBER(TessellatorDomain);
	DUMP_DESC_MEMBER(cBarrierInstructions);
	DUMP_DESC_MEMBER(cInterlockedInstructions);
	DUMP_DESC_MEMBER(cTextureStoreInstructions);

	return out;
}

ostream & operator<<(ostream & out, const D3D_REGISTER_COMPONENT_TYPE type)
{
	const char * pTypeNames[] =
	{
		"D3D_REGISTER_COMPONENT_TYPE_UNKNOWN",
		"D3D_REGISTER_COMPONENT_TYPE_UINT32",
		"D3D_REGISTER_COMPONENT_TYPE_SINT32",
		"D3D_REGISTER_COMPONENT_TYPE_FLOAT32",
	};

	out << pTypeNames[type];

	return out;
}

ostream & operator<<(ostream & out, const D3D11_INPUT_CLASSIFICATION classification)
{
	const char * pClassificationNames[] =
	{
		"D3D11_INPUT_PER_VERTEX_DATA",
		"D3D11_INPUT_PER_INSTANCE_DATA",
	};

	out << pClassificationNames[classification];

	return out;
}


ostream & operator<<(ostream & out, const D3D11_SIGNATURE_PARAMETER_DESC & desc)
{
	DUMP_DESC_MEMBER(SemanticName);
	DUMP_DESC_MEMBER(SemanticIndex);
	DUMP_DESC_MEMBER(Register);
	DUMP_DESC_MEMBER(SystemValueType);
	DUMP_DESC_MEMBER(ComponentType);
	out << "Mask : " << hex << static_cast<uint32_t>(desc.Mask) << endl;
	out << "ReadWriteMask : " << hex << static_cast<uint32_t>(desc.ReadWriteMask) << endl;
	DUMP_DESC_MEMBER(Stream);
	DUMP_DESC_MEMBER(MinPrecision);

	return out;
}

ostream & operator<<(ostream & out, const DXGI_FORMAT format)
{
#define DUMP_FORMAT(format) case format: out << #format; break
	switch(format)
	{
		DUMP_FORMAT(DXGI_FORMAT_UNKNOWN);
		DUMP_FORMAT(DXGI_FORMAT_R32G32B32A32_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R32G32B32A32_FLOAT);
		DUMP_FORMAT(DXGI_FORMAT_R32G32B32A32_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R32G32B32A32_SINT);
		DUMP_FORMAT(DXGI_FORMAT_R32G32B32_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R32G32B32_FLOAT);
		DUMP_FORMAT(DXGI_FORMAT_R32G32B32_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R32G32B32_SINT);
		DUMP_FORMAT(DXGI_FORMAT_R16G16B16A16_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R16G16B16A16_FLOAT);
		DUMP_FORMAT(DXGI_FORMAT_R16G16B16A16_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R16G16B16A16_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R16G16B16A16_SNORM);
		DUMP_FORMAT(DXGI_FORMAT_R16G16B16A16_SINT);
		DUMP_FORMAT(DXGI_FORMAT_R32G32_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R32G32_FLOAT);
		DUMP_FORMAT(DXGI_FORMAT_R32G32_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R32G32_SINT);
		DUMP_FORMAT(DXGI_FORMAT_R32G8X24_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_D32_FLOAT_S8X24_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_X32_TYPELESS_G8X24_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R10G10B10A2_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R10G10B10A2_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R10G10B10A2_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R11G11B10_FLOAT);
		DUMP_FORMAT(DXGI_FORMAT_R8G8B8A8_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R8G8B8A8_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R8G8B8A8_UNORM_SRGB);
		DUMP_FORMAT(DXGI_FORMAT_R8G8B8A8_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R8G8B8A8_SNORM);
		DUMP_FORMAT(DXGI_FORMAT_R8G8B8A8_SINT);
		DUMP_FORMAT(DXGI_FORMAT_R16G16_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R16G16_FLOAT);
		DUMP_FORMAT(DXGI_FORMAT_R16G16_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R16G16_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R16G16_SNORM);
		DUMP_FORMAT(DXGI_FORMAT_R16G16_SINT);
		DUMP_FORMAT(DXGI_FORMAT_R32_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_D32_FLOAT);
		DUMP_FORMAT(DXGI_FORMAT_R32_FLOAT);
		DUMP_FORMAT(DXGI_FORMAT_R32_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R32_SINT);
		DUMP_FORMAT(DXGI_FORMAT_R24G8_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_D24_UNORM_S8_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R24_UNORM_X8_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_X24_TYPELESS_G8_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R8G8_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R8G8_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R8G8_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R8G8_SNORM);
		DUMP_FORMAT(DXGI_FORMAT_R8G8_SINT);
		DUMP_FORMAT(DXGI_FORMAT_R16_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R16_FLOAT);
		DUMP_FORMAT(DXGI_FORMAT_D16_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R16_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R16_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R16_SNORM);
		DUMP_FORMAT(DXGI_FORMAT_R16_SINT);
		DUMP_FORMAT(DXGI_FORMAT_R8_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_R8_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R8_UINT);
		DUMP_FORMAT(DXGI_FORMAT_R8_SNORM);
		DUMP_FORMAT(DXGI_FORMAT_R8_SINT);
		DUMP_FORMAT(DXGI_FORMAT_A8_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R1_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R9G9B9E5_SHAREDEXP);
		DUMP_FORMAT(DXGI_FORMAT_R8G8_B8G8_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_G8R8_G8B8_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_BC1_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_BC1_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_BC1_UNORM_SRGB);
		DUMP_FORMAT(DXGI_FORMAT_BC2_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_BC2_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_BC2_UNORM_SRGB);
		DUMP_FORMAT(DXGI_FORMAT_BC3_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_BC3_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_BC3_UNORM_SRGB);
		DUMP_FORMAT(DXGI_FORMAT_BC4_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_BC4_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_BC4_SNORM);
		DUMP_FORMAT(DXGI_FORMAT_BC5_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_BC5_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_BC5_SNORM);
		DUMP_FORMAT(DXGI_FORMAT_B5G6R5_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_B5G5R5A1_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_B8G8R8A8_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_B8G8R8X8_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_B8G8R8A8_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_B8G8R8A8_UNORM_SRGB);
		DUMP_FORMAT(DXGI_FORMAT_B8G8R8X8_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_B8G8R8X8_UNORM_SRGB);
		DUMP_FORMAT(DXGI_FORMAT_BC6H_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_BC6H_UF16);
		DUMP_FORMAT(DXGI_FORMAT_BC6H_SF16);
		DUMP_FORMAT(DXGI_FORMAT_BC7_TYPELESS);
		DUMP_FORMAT(DXGI_FORMAT_BC7_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_BC7_UNORM_SRGB);
		DUMP_FORMAT(DXGI_FORMAT_AYUV);
		DUMP_FORMAT(DXGI_FORMAT_Y410);
		DUMP_FORMAT(DXGI_FORMAT_Y416);
		DUMP_FORMAT(DXGI_FORMAT_NV12);
		DUMP_FORMAT(DXGI_FORMAT_P010);
		DUMP_FORMAT(DXGI_FORMAT_P016);
		DUMP_FORMAT(DXGI_FORMAT_420_OPAQUE);
		DUMP_FORMAT(DXGI_FORMAT_YUY2);
		DUMP_FORMAT(DXGI_FORMAT_Y210);
		DUMP_FORMAT(DXGI_FORMAT_Y216);
		DUMP_FORMAT(DXGI_FORMAT_NV11);
		DUMP_FORMAT(DXGI_FORMAT_AI44);
		DUMP_FORMAT(DXGI_FORMAT_IA44);
		DUMP_FORMAT(DXGI_FORMAT_P8);
		DUMP_FORMAT(DXGI_FORMAT_A8P8);
		DUMP_FORMAT(DXGI_FORMAT_B4G4R4A4_UNORM);
		DUMP_FORMAT(DXGI_FORMAT_P208);
		DUMP_FORMAT(DXGI_FORMAT_V208);
		DUMP_FORMAT(DXGI_FORMAT_V408);
		DUMP_FORMAT(DXGI_FORMAT_FORCE_UINT);
	default:
		out << "Unknown";
		break;
	}

	return out;
}

ostream & operator<<(ostream & out, const D3D11_INPUT_ELEMENT_DESC & desc)
{
	out << "{ ";
	out << desc.SemanticName << ", ";
	out << desc.SemanticIndex << ", ";
	out << desc.Format << ", ";
	out << desc.InputSlot << ", ";
	if(desc.AlignedByteOffset == D3D11_APPEND_ALIGNED_ELEMENT)
	{
		out << "D3D11_APPEND_ALIGNED_ELEMENT, ";
	}
	else
	{
		out << desc.AlignedByteOffset << ", ";
	}
	out << desc.InputSlotClass;
	out << " }";

	return out;
}

int main()
{
	ComPtr<ID3DBlob> pVS;
	ComPtr<ID3DBlob> pError;

	HRESULT hr = D3DCompileFromFile(
		L"shader.hlsl",
		nullptr,
		nullptr,
		"VS",
		"vs_5_0",
		0,
		0,
		&pVS,
		&pError
	);
	if(FAILED(hr))
	{
		cerr << "頂点シェーダのコンパイルに失敗" << endl;
		cerr.write(
			static_cast<const char *>(pError->GetBufferPointer()),
			pError->GetBufferSize()
		) << endl;
		return -1;
	}

	ComPtr<ID3D11ShaderReflection> pShaderReflection;
	hr = D3DReflect(
		pVS->GetBufferPointer(),
		pVS->GetBufferSize(),
		IID_PPV_ARGS(&pShaderReflection)
	);

	if(FAILED(hr))
	{
		cerr << "シェーダーリフレクションの取得に失敗" << endl;
		return -1;
	}

	D3D11_SHADER_DESC ShaderDesc = {};

	hr = pShaderReflection->GetDesc(&ShaderDesc);
	if(FAILED(hr))
	{
		cerr << "シェーダーデスクリプションの取得に失敗" << endl;
		return -1;
	}

	cout << ShaderDesc << endl;

	vector<D3D11_SIGNATURE_PARAMETER_DESC> SignatureParameterDescs(ShaderDesc.InputParameters);
	for(uint32_t i = 0; i < ShaderDesc.InputParameters; ++i)
	{
		hr = pShaderReflection->GetInputParameterDesc(i, &SignatureParameterDescs[i]);
		cout << SignatureParameterDescs[i] << endl;
	}

	cout << "D3D11_INPUT_ELEMENT_DESC inputLayout[] = {" << endl;
	for(uint32_t i = 0; i < ShaderDesc.InputParameters; ++i)
	{
		D3D11_INPUT_ELEMENT_DESC InputElementDesc = {};
		InputElementDesc.SemanticName = SignatureParameterDescs[i].SemanticName;
		InputElementDesc.SemanticIndex = SignatureParameterDescs[i].SemanticIndex;

		BYTE mask = SignatureParameterDescs[i].Mask;
		D3D_REGISTER_COMPONENT_TYPE type = SignatureParameterDescs[i].ComponentType;

		if(
			(mask & D3D_COMPONENT_MASK_X) &&
			(mask & D3D_COMPONENT_MASK_Y) &&
			(mask & D3D_COMPONENT_MASK_Z) &&
			(mask & D3D_COMPONENT_MASK_W)
		)
		{
			switch(type)
			{
			case D3D_REGISTER_COMPONENT_UINT32:
				InputElementDesc.Format = DXGI_FORMAT_R32G32B32A32_UINT;
				break;
			case D3D_REGISTER_COMPONENT_SINT32:
				InputElementDesc.Format = DXGI_FORMAT_R32G32B32A32_SINT;
				break;
			case D3D_REGISTER_COMPONENT_FLOAT32:
				InputElementDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
				break;
			}
		}
		else if(
			(mask & D3D_COMPONENT_MASK_X) &&
			(mask & D3D_COMPONENT_MASK_Y) &&
			(mask & D3D_COMPONENT_MASK_Z)
		)
		{
			switch(type)
			{
			case D3D_REGISTER_COMPONENT_UINT32:
				InputElementDesc.Format = DXGI_FORMAT_R32G32B32_UINT;
				break;
			case D3D_REGISTER_COMPONENT_SINT32:
				InputElementDesc.Format = DXGI_FORMAT_R32G32B32_SINT;
				break;
			case D3D_REGISTER_COMPONENT_FLOAT32:
				InputElementDesc.Format = DXGI_FORMAT_R32G32B32_FLOAT;
				break;
			}
		}
		else if(
			(mask & D3D_COMPONENT_MASK_X) &&
			(mask & D3D_COMPONENT_MASK_Y)
		)
		{
			switch(type)
			{
			case D3D_REGISTER_COMPONENT_UINT32:
				InputElementDesc.Format = DXGI_FORMAT_R32G32_UINT;
				break;
			case D3D_REGISTER_COMPONENT_SINT32:
				InputElementDesc.Format = DXGI_FORMAT_R32G32_SINT;
				break;
			case D3D_REGISTER_COMPONENT_FLOAT32:
				InputElementDesc.Format = DXGI_FORMAT_R32G32_FLOAT;
				break;
			}
		}
		else if((mask & D3D_COMPONENT_MASK_X))
		{
			switch(type)
			{
			case D3D_REGISTER_COMPONENT_UINT32:
				InputElementDesc.Format = DXGI_FORMAT_R32_UINT;
				break;
			case D3D_REGISTER_COMPONENT_SINT32:
				InputElementDesc.Format = DXGI_FORMAT_R32_SINT;
				break;
			case D3D_REGISTER_COMPONENT_FLOAT32:
				InputElementDesc.Format = DXGI_FORMAT_R32_FLOAT;
				break;
			}
		}

		InputElementDesc.Format;

		InputElementDesc.InputSlot = 0;
		InputElementDesc.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
		InputElementDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		InputElementDesc.InstanceDataStepRate = 0;

		cout << "\t" << InputElementDesc << (i > 0 ? "," : "") << endl;
	}
	cout << "};" << endl;

	return 0;
}
