#include <Novice.h>
#include <math.h>
#include "Player.h"
#include "Keys.h"

//	‹éŒ`‚ÌÕ“Ë”»’èˆ—
bool RectCollision(Vec2 pos, Vec2 size, Vec2 pos2, Vec2 size2) {

	if (pos.x <= pos2.x + size2.x && pos.x + size.x >= pos2.x
		&& pos.y <= pos2.y + size2.y && pos.y + size.y >= pos2.y)
	{
		return true;
	}
	return false;
}

//‰~‚ÌÕ“Ë”»’è
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

//	À•W•ÏŠ·
Vec2 Change(Vec2 pos) {
	Vec2 result;
	result.x = pos.x;
	result.y = (pos.y - 720) * -1;
	return result;
}

void PlayerMove(Object* p, char* keys) {
	
	if (keys[DIK_D])
	{
		p->pos.x += p->speed;
	}
	if (keys[DIK_A])
	{
		p->pos.x -= p->speed;
	}
	if (keys[DIK_W])
	{
		p->pos.y += p->speed;
	}
	if (keys[DIK_S])
	{
		p->pos.y -= p->speed;
	}
}

void MoveLimit(Object* p) {
	if (p->pos.x - p->size.x <= 0)
	{
		p->pos.x = 0 + p->size.x;
	}
	else if (p->pos.x + p->size.x >= 1280)
	{
		p->pos.x = 1280 - p->size.x;
	}

	if (p->pos.y + p->size.y >= 720)
	{
		p->pos.y = 720 - p->size.y;
	}
	else if (p->pos.y - p->size.y <= 0)
	{
		p->pos.y = 0 + p->size.y;
	}
}

void PlayerDraw(Object* p) {
	Vec2 screenPos = Change(p->pos);

	Novice::DrawEllipse((int)screenPos.x, (int)screenPos.y, (int)p->size.x, (int)p->size.y, 0.0f, 0xff0000ff, kFillModeSolid);
}

