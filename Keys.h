#pragma once

class Key
{
private:

	// �L�[���͌��ʂ��󂯎�锠
	//	�v���g�^�C�v�錾�Ɠ���
	static char keys[256];
	static char preKeys[256];

public:

	// �L�[���͂��󂯎��
	static void Input();

	//	�L�[�������ꂽ��
	static bool IsTrigger(char keycord);

	//	�L�[��������Ă��鎞
	static bool IsPressed(char keycord);

};

