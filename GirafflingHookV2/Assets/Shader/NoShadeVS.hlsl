/*
* Direct3D11対応の陰影なしべた塗頂点シェーダ
* オープンソースなDXライブラリ様のシェーダをそのまま持ってきただけ
* https://dxlib.xsrv.jp/dxdload.html
*/


// 頂点シェーダーの入力
struct VS_INPUT
{
	float3 Position : POSITION;  // 座標( ローカル空間 )
	float3 Normal : NORMAL0;  // 法線( ローカル空間 )
	float4 Diffuse : COLOR0;  // ディフューズカラー
	float4 Specular : COLOR1;  // スペキュラカラー
	float4 TexCoords0 : TEXCOORD0;  // テクスチャ座標
	float4 TexCoords1 : TEXCOORD1;  // サブテクスチャ座標
};

// 頂点シェーダーの出力
struct VS_OUTPUT
{
	float4 Diffuse : COLOR0;  // ディフューズカラー
	float4 Specular : COLOR1;  // スペキュラカラー
	float4 TexCoords0_1 : TEXCOORD0;  // xy:テクスチャ座標 zw:サブテクスチャ座標
	float3 VPosition : TEXCOORD1;  // 座標( ビュー空間 )
	float3 VNormal : TEXCOORD2;  // 法線( ビュー空間 )
	float1 Fog : TEXCOORD5;  // フォグパラメータ( x )
	float4 Position : SV_POSITION;  // 座標( プロジェクション空間 )
};

// 基本パラメータ
struct DX_D3D11_VS_CONST_BUFFER_BASE
{
	float4 AntiViewportMatrix[4];  // アンチビューポート行列
	float4 ProjectionMatrix[4];  // ビュー　→　プロジェクション行列
	float4 ViewMatrix[3];  // ワールド　→　ビュー行列
	float4 LocalWorldMatrix[3];  // ローカル　→　ワールド行列

	float4 ToonOutLineSize;  // トゥーンの輪郭線の大きさ
	float DiffuseSource;  // ディフューズカラー( 0.0f:マテリアル  1.0f:頂点 )
	float SpecularSource;  // スペキュラカラー(   0.0f:マテリアル  1.0f:頂点 )
	float MulSpecularColor;  // スペキュラカラー値に乗算する値( スペキュラ無効処理で使用 )
	float Padding;
};

// その他の行列
struct DX_D3D11_VS_CONST_BUFFER_OTHERMATRIX
{
	float4 ShadowMapLightViewProjectionMatrix[3][4];  // シャドウマップ用のライトビュー行列とライト射影行列を乗算したもの
	float4 TextureMatrix[3][2];  // テクスチャ座標操作用行列
};

// 基本パラメータ
cbuffer cbD3D11_CONST_BUFFER_VS_BASE : register(b1)
{
	DX_D3D11_VS_CONST_BUFFER_BASE g_Base;
};

// その他の行列
cbuffer cbD3D11_CONST_BUFFER_VS_OTHERMATRIX : register(b2)
{
	DX_D3D11_VS_CONST_BUFFER_OTHERMATRIX g_OtherMatrix;
};

// main関数
VS_OUTPUT main(VS_INPUT VSInput)
{
	VS_OUTPUT VSOutput;
	float4 lLocalPosition;
	float4 lWorldPosition;
	float4 lViewPosition;
	float3 lViewNrm ;
	float3 lWorldNrm ;

	// ローカル座標のセット
	lLocalPosition.xyz = VSInput.Position;
	lLocalPosition.w = 1.0f;

	// 座標計算( ローカル→ビュー→プロジェクション )
	lWorldPosition.x = dot(lLocalPosition, g_Base.LocalWorldMatrix[0]);
	lWorldPosition.y = dot(lLocalPosition, g_Base.LocalWorldMatrix[1]);
	lWorldPosition.z = dot(lLocalPosition, g_Base.LocalWorldMatrix[2]);
	lWorldPosition.w = 1.0f;

	lViewPosition.x = dot(lWorldPosition, g_Base.ViewMatrix[0]);
	lViewPosition.y = dot(lWorldPosition, g_Base.ViewMatrix[1]);
	lViewPosition.z = dot(lWorldPosition, g_Base.ViewMatrix[2]);
	lViewPosition.w = 1.0f;

	VSOutput.Position.x = dot(lViewPosition, g_Base.ProjectionMatrix[0]);
	VSOutput.Position.y = dot(lViewPosition, g_Base.ProjectionMatrix[1]);
	VSOutput.Position.z = dot(lViewPosition, g_Base.ProjectionMatrix[2]);
	VSOutput.Position.w = dot(lViewPosition, g_Base.ProjectionMatrix[3]);
	
	// 座標(ビュー空間)を保存
	VSOutput.VPosition = lViewPosition.xyz;
	
	// 法線を計算
	lWorldNrm.x = dot(VSInput.Normal, g_Base.LocalWorldMatrix[0].xyz);
	lWorldNrm.y = dot(VSInput.Normal, g_Base.LocalWorldMatrix[1].xyz);
	lWorldNrm.z = dot(VSInput.Normal, g_Base.LocalWorldMatrix[2].xyz);

	lViewNrm.x = dot(lWorldNrm, g_Base.ViewMatrix[0].xyz);
	lViewNrm.y = dot(lWorldNrm, g_Base.ViewMatrix[1].xyz);
	lViewNrm.z = dot(lWorldNrm, g_Base.ViewMatrix[2].xyz);

	// 法線( ビュー空間 )を保存
	VSOutput.VNormal = lViewNrm;
	
	// テクスチャ座標のセット
	VSOutput.TexCoords0_1.x = dot(VSInput.TexCoords0, g_OtherMatrix.TextureMatrix[0][0]);
	VSOutput.TexCoords0_1.y = dot(VSInput.TexCoords0, g_OtherMatrix.TextureMatrix[0][1]);

	VSOutput.TexCoords0_1.z = dot(VSInput.TexCoords1, g_OtherMatrix.TextureMatrix[0][0]);
	VSOutput.TexCoords0_1.w = dot(VSInput.TexCoords1, g_OtherMatrix.TextureMatrix[0][1]);
	
	VSOutput.Diffuse = VSInput.Diffuse;
	VSOutput.Fog.x = 1.0f;

	// 出力パラメータを返す
	return VSOutput;
}
