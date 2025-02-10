#pragma once
#include "Vector2Int.h"

/// <summary>
/// ��ʊ֌W
/// </summary>
class Screen final
{
	/*
	* �r���[�|�[�g���W�F���������_�̍��W�n
	* �X�N���[�����W�F���オ���_�̍��W�n
	*/
public:
	/// <summary>
	/// �X�N���[�����W���r���[�|�[�g���W�ɕϊ�����
	/// </summary>
	/// <param name="screenX">�X�N���[�����W��x</param>
	/// <param name="screenY">�X�N���[�����W��y</param>
	/// <returns>�r���[�|�[�g���W</returns>
	static Vector2Int ToViewportPosition(const int& screenX, const int& screenY);
	/// <summary>
	/// �X�N���[�����W���r���[�|�[�g���W�ɕϊ�����
	/// </summary>
	/// <param name="screen">�X�N���[�����W</param>
	/// <returns>�r���[�|�[�g���W</returns>
	static Vector2Int ToViewportPosition(const Vector2Int& screen);

public:
	static const int WIDTH;  // ����
	static const int HEIGHT;  // ����
	static const int COLOR_DEPTH;  // �g���J���[�r�b�g��
};
