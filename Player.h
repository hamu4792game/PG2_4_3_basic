#pragma once

struct Vec2 {
	float x, y;
};
//	‹éŒ`‚ÌÕ“Ë”»’è
bool RectCollision(Vec2 pos, Vec2 size, Vec2 pos2, Vec2 size2);
//‰~‚ÌÕ“Ë”»’è
bool BallCollision(Vec2 pos, float radius, Vec2 pos2, float radius2);

class Player
{
public:
	struct Object
	{
	public:
		Vec2 pos;
		Vec2 size;
		float speed;
		bool alive;
	};

public:
	Player();

private:
	static const int MAX_Bullet = 10;

	Object player;
	Object bullet[MAX_Bullet];

	Object enemy;
	int frame;

private:
	void BulletReset();
	void BulletMove();
	void PlayerMove();
	void EnemyMove();

public:
	void Process();
	void Draw();
};

Vec2 Change(Vec2 pos);
