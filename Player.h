#pragma once

struct Vec2 {
	float x, y;
};

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

public:
	void BulletReset();
	void BulletMove();
	void PlayerMove();

	void Draw();
};

Vec2 Change(Vec2 pos);
