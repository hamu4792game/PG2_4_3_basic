#include <Novice.h>
#include <math.h>
#include "Player.h"
#include "Keys.h"

//	矩形の衝突判定処理
bool RectCollision(Vec2 pos, Vec2 size, Vec2 pos2, Vec2 size2) {

	if (pos.x <= pos2.x + size2.x && pos.x + size.x >= pos2.x
		&& pos.y <= pos2.y + size2.y && pos.y + size.y >= pos2.y)
	{
		return true;
	}
	return false;
}

//円の衝突判定
bool BallCollision(Vec2 pos, float radius, Vec2 pos2, float radius2) {
	float A = pos2.x - pos.x;
	float B = pos2.y - pos.y;
	float distance = sqrtf(A * A + B * B);
	if (distance <= radius + radius2)
	{
		return true;
	}
	return false;
}

//	プレイヤー
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

	enemy.pos = { 0,400 };
	enemy.size = { 50,50 };
	enemy.speed = 10.0f;
	enemy.alive = true;
	frame = 0;
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
		if (enemy.alive == true)
		{
			//	衝突判定
			if (RectCollision(bullet[i].pos, bullet[i].size, enemy.pos, enemy.size) == true)
			{
				enemy.alive = false;
				bullet[i].alive = false;
			}
		}

	}

}

void Player::EnemyMove() {
	
	if (enemy.alive == false)
	{
		frame++;
		if (frame >= 60)
		{
			frame = 0;
			enemy.alive = true;
		}
	}
	else
	{
		if (enemy.pos.x + enemy.size.x >= 1280)
		{
			enemy.pos.x = 0;
		}
		else
		{
			enemy.pos.x += enemy.speed;
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
	if (Key::IsPressed(DIK_W))
	{
		player.pos.y += player.speed;
	}
	if (Key::IsPressed(DIK_S))
	{
		player.pos.y -= player.speed;
	}

	if (Key::IsTrigger(DIK_SPACE))
	{
		for (int i = 0; i < MAX_Bullet; i++)
		{
			if (bullet[i].alive == false)
			{
				bullet[i].alive = true;
				bullet[i].pos.x = player.pos.x;
				bullet[i].pos.y = player.pos.y;
				break;
			}
		}
	}
	BulletMove();
}

void Player::Process() {
	EnemyMove();
	PlayerMove();
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


	Vec2 screenEnepos = Change(enemy.pos);
	if (enemy.alive == true)
	{
		Novice::DrawBox(screenEnepos.x, screenEnepos.y, enemy.size.x, enemy.size.y, 0.0f, 0xff0000ff, kFillModeSolid);
		Novice::ScreenPrintf(0, 0, "enemy = true");
	}
	else
	{
		Novice::ScreenPrintf(0, 0, "enemy = false");
	}

}

Vec2 Change(Vec2 pos) {
	Vec2 result;
	result.x = pos.x;
	result.y = (pos.y - 500) * -1;
	return result;
}