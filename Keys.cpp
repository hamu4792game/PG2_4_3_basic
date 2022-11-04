#include "Keys.h"
#include <Novice.h>

//	Key用
char Key::keys[256] = { 0 };
char Key::preKeys[256] = { 0 };

// キー入力を受け取る
void Key::Input()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

//	キーが押された時
bool Key::IsTrigger(char keycord)
{
	return keys[keycord] && !preKeys[keycord];
}

//	キーが押されている時
bool Key::IsPressed(char keycord)
{
	return keys[keycord];
}

