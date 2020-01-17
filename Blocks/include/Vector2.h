#pragma once
#pragma warning(push)
#pragma warning(disable:4101)
struct Vector2 {
	float x;
	float y;
	Vector2() { x = 0; y = 0; };
	Vector2(int _x, int _y) { x = _x; y = _y; };
	Vector2(const Vector2& _other) { x = _other.x; y = _other.y; }
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
	void operator+(const Vector2& _other) {
		this->x += _other.x;
		this->y += _other.y;
	}

	Vector2& operator-(const Vector2& _other) {
		this->x -= _other.x;
		this->y -= _other.y;
		return *this;
	}

	Vector2& operator/(float val) {
		this->x /= val;
		this->y /= val;
		return *this;
	}
	Vector2& operator/(int val) {
		this->x /= val;
		this->y /= val;
		return *this;
	}
	Vector2& operator/(double val) {
		this->x /= val;
		this->y /= val;
		return *this;
	}
};
#pragma warning(pop)