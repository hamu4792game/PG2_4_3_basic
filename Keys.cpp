#include "Keys.h"
#include <Novice.h>

//	Key�p
char Key::keys[256] = { 0 };
char Key::preKeys[256] = { 0 };

// �L�[���͂��󂯎��
void Key::Input()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

//	�L�[�������ꂽ��
bool Key::IsTrigger(char keycord)
{
	return keys[keycord] && !preKeys[keycord];
}

//	�L�[��������Ă��鎞
bool Key::IsPressed(char keycord)
{
	return keys[keycord];
}

