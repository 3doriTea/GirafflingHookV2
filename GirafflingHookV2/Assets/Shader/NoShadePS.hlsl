/*
* Direct3D11対応の陰影なしべた塗ピクセルシェーダ
* オープンソースなDXライブラリ様のシェーダをそのまま持ってきただけ
* https://dxlib.xsrv.jp/dxdload.html
*/


// ピクセルシェーダーの入力
struct PS_INPUT
{
	float4 Diffuse : COLOR0;  // ディフューズカラー
	float4 Specular : COLOR1;  // スペキュラカラー
	float4 TexCoords0_1 : TEXCOORD0;  // xy:テクスチャ座標 zw:サブテクスチャ座標
	float3 VPosition : TEXCOORD1;  // 座標( ビュー空間 )
	float3 VNormal : TEXCOORD2;  // 法線( ビュー空間 )
	float1 Fog : TEXCOORD5;  // フォグパラメータ( x )
};

// ピクセルシェーダーの出力
struct PS_OUTPUT
{
	float4 Color0 : SV_TARGET0;  // 色
	float4 Normal : SV_TARGET1;  // 法線( ビュー空間 )
	float4 Depth : SV_TARGET2;  // 深度
};

// 定数バッファピクセルシェーダー基本パラメータ
struct DX_D3D11_PS_CONST_BUFFER_BASE
{
	float4 FactorColor;  // アルファ値等

	float MulAlphaColor;  // カラーにアルファ値を乗算するかどうか( 0.0f:乗算しない  1.0f:乗算する )
	float AlphaTestRef;  // アルファテストで使用する比較値
	float2 Padding1;
	int AlphaTestCmpMode;  // アルファテスト比較モード( DX_CMP_NEVER など )
	int3 Padding2;
	float4 IgnoreTextureColor;  // テクスチャカラー無視処理用カラー
};

// 基本パラメータ
cbuffer cbD3D11_CONST_BUFFER_PS_BASE : register(b1)
{
	DX_D3D11_PS_CONST_BUFFER_BASE g_Base;
};

SamplerState g_DiffuseMapSampler : register(s0);  // ディフューズマップサンプラ
Texture2D g_DiffuseMapTexture : register(t0);  // ディフューズマップテクスチャ

// main関数
PS_OUTPUT main(PS_INPUT PSInput)
{
	PS_OUTPUT PSOutput;
	float4 TextureDiffuseColor;

	// ディフューズテクスチャカラーを取得
	TextureDiffuseColor = g_DiffuseMapTexture.Sample(g_DiffuseMapSampler, PSInput.TexCoords0_1.xy);

	// 出力カラー = テクスチャカラー
	PSOutput.Color0 = TextureDiffuseColor;  // ※ディフューズ無視

	// 出力パラメータを返す
	return PSOutput;
}
