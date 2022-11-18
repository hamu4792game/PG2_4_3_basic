#pragma once

struct Vec2 {
	float x, y;
};
//	‹éŒ`‚ÌÕ“Ë”»’è
bool RectCollision(Vec2 pos, Vec2 size, Vec2 pos2, Vec2 size2);
//‰~‚ÌÕ“Ë”»’è
bool BallCollision(Vec2 pos, float radius, Vec2 pos2, float radius2);
//	À•W•ÏŠ·
Vec2 Change(Vec2 pos);


struct Object
{
public:
	Vec2 pos;
	Vec2 size;
	float speed;
	bool alive;
};

void PlayerMove(Object* p, char* keys);

void PlayerDraw(Object* p);

void MoveLimit(Object* p);