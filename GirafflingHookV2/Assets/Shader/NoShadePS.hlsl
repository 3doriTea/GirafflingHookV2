/*
* Direct3D11�Ή��̉A�e�Ȃ��ׂ��h�s�N�Z���V�F�[�_
* �I�[�v���\�[�X��DX���C�u�����l�̃V�F�[�_�����̂܂܎����Ă�������
* https://dxlib.xsrv.jp/dxdload.html
*/


// �s�N�Z���V�F�[�_�[�̓���
struct PS_INPUT
{
	float4 Diffuse : COLOR0;  // �f�B�t���[�Y�J���[
	float4 Specular : COLOR1;  // �X�y�L�����J���[
	float4 TexCoords0_1 : TEXCOORD0;  // xy:�e�N�X�`�����W zw:�T�u�e�N�X�`�����W
	float3 VPosition : TEXCOORD1;  // ���W( �r���[��� )
	float3 VNormal : TEXCOORD2;  // �@��( �r���[��� )
	float1 Fog : TEXCOORD5;  // �t�H�O�p�����[�^( x )
};

// �s�N�Z���V�F�[�_�[�̏o��
struct PS_OUTPUT
{
	float4 Color0 : SV_TARGET0;  // �F
	float4 Normal : SV_TARGET1;  // �@��( �r���[��� )
	float4 Depth : SV_TARGET2;  // �[�x
};

// �萔�o�b�t�@�s�N�Z���V�F�[�_�[��{�p�����[�^
struct DX_D3D11_PS_CONST_BUFFER_BASE
{
	float4 FactorColor;  // �A���t�@�l��

	float MulAlphaColor;  // �J���[�ɃA���t�@�l����Z���邩�ǂ���( 0.0f:��Z���Ȃ�  1.0f:��Z���� )
	float AlphaTestRef;  // �A���t�@�e�X�g�Ŏg�p�����r�l
	float2 Padding1;
	int AlphaTestCmpMode;  // �A���t�@�e�X�g��r���[�h( DX_CMP_NEVER �Ȃ� )
	int3 Padding2;
	float4 IgnoreTextureColor;  // �e�N�X�`���J���[���������p�J���[
};

// ��{�p�����[�^
cbuffer cbD3D11_CONST_BUFFER_PS_BASE : register(b1)
{
	DX_D3D11_PS_CONST_BUFFER_BASE g_Base;
};

SamplerState g_DiffuseMapSampler : register(s0);  // �f�B�t���[�Y�}�b�v�T���v��
Texture2D g_DiffuseMapTexture : register(t0);  // �f�B�t���[�Y�}�b�v�e�N�X�`��

// main�֐�
PS_OUTPUT main(PS_INPUT PSInput)
{
	PS_OUTPUT PSOutput;
	float4 TextureDiffuseColor;

	// �f�B�t���[�Y�e�N�X�`���J���[���擾
	TextureDiffuseColor = g_DiffuseMapTexture.Sample(g_DiffuseMapSampler, PSInput.TexCoords0_1.xy);

	// �o�̓J���[ = �e�N�X�`���J���[
	PSOutput.Color0 = TextureDiffuseColor;  // ���f�B�t���[�Y����

	// �o�̓p�����[�^��Ԃ�
	return PSOutput;
}
