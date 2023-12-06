#include "Vec3.h"

Vector3 Add(Vector3 v1, Vector3 v2) {
	Vector3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

Vector3 Subtract(Vector3 v1, Vector3 v2) {
	Vector3 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 v3 = { 0, 0, 0 };

	v3.x = scalar * v.x;

	v3.y = scalar * v.y;

	v3.z = scalar * v.z;

	return v3;
}

float Length(const Vector3& v) {
	float length = 0;

	length = sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2));

	return length;
}

Vector3 Normalize(const Vector3& v1) {
	Vector3 v2 = { 0, 0, 0 };
	float length = Length(v1);

	v2.x = v1.x / length;
	v2.y = v1.y / length;
	v2.z = v1.z / length;

	return v2;
}

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}
float Dot(const Vector3& v1, const Vector3& v2) {
	float dot = 0.0f;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return dot;
}

Vector3 Cross(const Vector3& vector1, const Vector3& vector2) {
	Vector3 result;
	result.x = vector1.y * vector2.z - vector1.z * vector2.y;
	result.y = vector1.z * vector2.x - vector1.x * vector2.z;
	result.z = vector1.x * vector2.y - vector1.y * vector2.x;
	return result;
}

Vector3 Project(const Vector3& v1, const Vector3& v2) {
	float scalar = Dot(v1, Normalize(v2));

	return Multiply(scalar, Normalize(v2));
}
Vector3 ClosestPoint(const Vector3& point, const Segment& segment) {
	Vector3 project = Project(Subtract(point, segment.origin), segment.diff);
	Vector3 cp = Add(segment.origin, project);
	return cp;
}

void VectorScreenPrint(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

Vector3 operator+(const Vector3& num1, const Vector3& num2) {
	Vector3 num3;

	num3.x = num1.x + num2.x;
	num3.y = num1.y + num2.y;
	num3.z = num1.z + num2.z;

	return num3;
}

Vector3 operator-(const Vector3& num1, const Vector3& num2) {
	Vector3 num3;

	num3.x = num1.x - num2.x;
	num3.y = num1.y - num2.y;
	num3.z = num1.z - num2.z;

	return num3;
}

Vector3 operator*(const Vector3& num1, const float num2) {
	Vector3 num3;

	num3.x = num1.x * num2;
	num3.y = num1.y * num2;
	num3.z = num1.z * num2;

	return num3;
}

Vector3 operator*(const float num1, const Vector3& num2) {
	Vector3 num3;

	num3.x = num1 * num2.x;
	num3.y = num1 * num2.y;
	num3.z = num1 * num2.z;

	return num3;
}

Vector3 operator*(const Vector3& num1, const Vector3& num2) {
	Vector3 num3;

	num3.x = num1.x * num2.x;
	num3.y = num1.y * num2.y;
	num3.z = num1.z * num2.z;

	return num3;
}

Vector3 operator/(const Vector3& num1, const float num2) {
	Vector3 num3;

	num3.x = num1.x * num2;
	num3.y = num1.y * num2;
	num3.z = num1.z * num2;

	return num3;
}

Vector3 operator+=(Vector3& num1, const Vector3& num2) {

	num1.x += num2.x;
	num1.y += num2.y;
	num1.z += num2.z;

	return num1;
}

Vector3 operator-=(Vector3& num1, const Vector3& num2) {

	num1.x -= num2.x;
	num1.y -= num2.y;
	num1.z -= num2.z;

	return num1;
}

Vector3 operator*=(Vector3& num1, const float num2) {

	num1.x *= num2;
	num1.y *= num2;
	num1.z *= num2;

	return num1;
}

Vector3 operator*=(Vector3& num1, const Vector3& num2) {

	num1.x *= num2.x;
	num1.y *= num2.y;
	num1.z *= num2.z;

	return num1;
}

Vector3 operator/=(Vector3& num1, const Vector3& num2) {

	num1.x /= num2.x;
	num1.y /= num2.y;
	num1.z /= num2.z;

	return num1;
}

Vector3 operator/=(Vector3& num1, const float num2) {

	num1.x = num1.x * num2;
	num1.y = num1.y * num2;
	num1.z = num1.z * num2;

	return num1;
}