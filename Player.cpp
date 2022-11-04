#include <Novice.h>
#include "Player.h"
#include "Keys.h"

Player::Player() {
	player.pos = { 0,0 };
	player.size = { 50,50 };
	player.speed = 10.0f;
	player.alive = true;

	for (int i = 0; i < MAX_Bullet; i++)
	{
		bullet[i].pos = { -100,0 };
		bullet[i].size = { 10,10 };
		bullet[i].speed = 20.0f;
		bullet[i].alive = false;
	}
	
}

void Player::BulletReset() {

	for (int i = 0; i < MAX_Bullet; i++)
	{
		if (bullet[i].pos.y + bullet[i].size.y >= 500)
		{
			bullet[i].alive = false;
		}
	}
}

void Player::BulletMove() {
	for (int i = 0; i < MAX_Bullet; i++)
	{
		if (bullet[i].alive == true)
		{
			bullet[i].pos.y += bullet[i].speed;
		}
		else
		{
			bullet[i].pos.x = -100;
			bullet[i].pos.y = 0;
		}
	}
}

void Player::PlayerMove() {
	BulletReset();

	if (Key::IsPressed(DIK_D))
	{
		player.pos.x += player.speed;
	}
	if (Key::IsPressed(DIK_A))
	{
		player.pos.x -= player.speed;
	}

	if (Key::IsTrigger(DIK_SPACE))
	{
		for (int i = 0; i < MAX_Bullet; i++)
		{
			if (bullet[i].alive == false)
			{
				bullet[i].alive = true;
				bullet[i].pos.x = player.pos.x;
				break;
			}
		}
	}
	BulletMove();
}

void Player::Draw() {
	Vec2 screenPos = Change(player.pos);
	Vec2 screenBulletPos[MAX_Bullet];
	for (int i = 0; i < MAX_Bullet; i++)
	{
		screenBulletPos[i] = Change(bullet[i].pos);
	}

	Novice::DrawEllipse((int)screenPos.x, (int)screenPos.y, (int)player.size.x, (int)player.size.y, 0.0f, 0xff0000ff, kFillModeSolid);
	for (int i = 0; i < MAX_Bullet; i++)
	{
		Novice::DrawEllipse((int)screenBulletPos[i].x, (int)screenBulletPos[i].y,
			(int)bullet[i].size.x, (int)bullet[i].size.y, 0.0f, 0xffffffff, kFillModeSolid);
	}

	Novice::ScreenPrintf(0, 0, "%f", screenBulletPos[0].x);
	Novice::ScreenPrintf(0, 20, "%f", screenBulletPos[0].y);

}

Vec2 Change(Vec2 pos) {
	Vec2 result;
	result.x = pos.x;
	result.y = (pos.y - 500) * -1;
	return result;
}