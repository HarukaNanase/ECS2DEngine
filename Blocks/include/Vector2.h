#pragma once

struct Vector2 {
	int x;
	int y;
	Vector2() { x = 0; y = 0; };
	Vector2(int _x, int _y) { x = _x; y = _y; };
	Vector2(Vector2& _other) { x = _other.x; y = _other.y; }
	void operator*(float _val) {
		x *= _val;
		y *= _val;
	}

	void operator*(int _val) {
		x *= _val;
		y *= _val;
	}

	void operator*(double _val) {
		x *= _val;
		y *= _val;
	}
	
};
