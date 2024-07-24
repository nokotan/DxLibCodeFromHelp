#include "DxLib.h"

int main()
{
	SOUND3D_REVERB_PARAM ReverbParam ;
	int Color ;

	// ＤＸライブラリの初期化
	if( DxLib_Init() < 0 ) return -1;

	// リバーブエフェクトパラメータのプリセット「水面下」を取得
	Get3DPresetReverbParamSoundMem( &ReverbParam, DX_REVERB_PRESET_UNDERWATER ) ;

	// リバーブエフェクトパラメータを画面に描画
	Color = GetColor( 255,255,255 ) ;
	DrawFormatString( 0,   0, Color, "WetDryMix          :%f", ReverbParam.WetDryMix ) ;
	DrawFormatString( 0,  16, Color, "ReflectionsDelay   :%d", ReverbParam.ReflectionsDelay ) ;
	DrawFormatString( 0,  32, Color, "ReverbDelay        :%d", ReverbParam.ReverbDelay ) ;
	DrawFormatString( 0,  48, Color, "RearDelay          :%d", ReverbParam.RearDelay ) ;
	DrawFormatString( 0,  64, Color, "PositionLeft       :%d", ReverbParam.PositionLeft ) ;
	DrawFormatString( 0,  80, Color, "PositionRight      :%d", ReverbParam.PositionRight ) ;
	DrawFormatString( 0,  96, Color, "PositionMatrixLeft :%d", ReverbParam.PositionMatrixLeft ) ;
	DrawFormatString( 0, 112, Color, "PositionMatrixRight:%d", ReverbParam.PositionMatrixRight ) ;
	DrawFormatString( 0, 128, Color, "EarlyDiffusion     :%d", ReverbParam.EarlyDiffusion ) ;
	DrawFormatString( 0, 144, Color, "LateDiffusion      :%d", ReverbParam.LateDiffusion ) ;
	DrawFormatString( 0, 160, Color, "LowEQGain          :%d", ReverbParam.LowEQGain ) ;
	DrawFormatString( 0, 176, Color, "LowEQCutoff        :%d", ReverbParam.LowEQCutoff ) ;
	DrawFormatString( 0, 192, Color, "HighEQGain         :%d", ReverbParam.HighEQGain ) ;
	DrawFormatString( 0, 208, Color, "HighEQCutoff       :%d", ReverbParam.HighEQCutoff ) ;
	DrawFormatString( 0, 224, Color, "RoomFilterFreq     :%f", ReverbParam.RoomFilterFreq ) ;
	DrawFormatString( 0, 240, Color, "RoomFilterMain     :%f", ReverbParam.RoomFilterMain ) ;
	DrawFormatString( 0, 256, Color, "RoomFilterHF       :%f", ReverbParam.RoomFilterHF ) ;
	DrawFormatString( 0, 272, Color, "ReflectionsGain    :%f", ReverbParam.ReflectionsGain ) ;
	DrawFormatString( 0, 288, Color, "ReverbGain         :%f", ReverbParam.ReverbGain ) ;
	DrawFormatString( 0, 304, Color, "DecayTime          :%f", ReverbParam.DecayTime ) ;
	DrawFormatString( 0, 320, Color, "Density            :%f", ReverbParam.Density ) ;
	DrawFormatString( 0, 336, Color, "RoomSize           :%f", ReverbParam.RoomSize ) ;

	// 何かキーが押されるまで待つ
	WaitKey() ;

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}
