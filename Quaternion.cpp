#include "Quaternion.h"

Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs) {
	Quaternion result;
	result.x = lhs.w * rhs.x - lhs.z * rhs.y + lhs.y * rhs.z + lhs.x * rhs.w;
	result.y= lhs.z * rhs.x + lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w;
	result.z= -lhs.y * rhs.x + lhs.x * rhs.y + lhs.w * rhs.z + lhs.z * rhs.w;
	result.w= -lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z + lhs.w * rhs.w;

	return result;
}

Quaternion IdentityQurtenion() {
	return { 0.0f,0.0f,0.0f,1.0f };
}

Quaternion Conjugate(const Quaternion& quartenion) {
	return { -quartenion.x,-quartenion.y,-quartenion.z,quartenion.w };
}

float Norm(const Quaternion& quartenion) {
	float result = pow(quartenion.w, 2) + pow(quartenion.x, 2) + pow(quartenion.y, 2) + pow(quartenion.z, 2);
	result = sqrt(result);
	return result;
}
Quaternion Normalize(const Quaternion& quartenion) {
	Quaternion result;
	float norm = Norm(quartenion);
	result.x = quartenion.x / norm;
	result.y = quartenion.y / norm;
	result.z = quartenion.z / norm;
	result.w = quartenion.w / norm;

	return result;
}
Quaternion Inverse(const Quaternion& quartenion) {
	Quaternion result;

	Quaternion conjugate = Conjugate(quartenion);
	float norm = Norm(quartenion);

	result.x = conjugate.x / pow(norm, 2);
	result.y = conjugate.y / pow(norm, 2);
	result.z = conjugate.z / pow(norm, 2);
	result.w = conjugate.w / pow(norm, 2);

	return result;
}

Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle) {
	Quaternion result;
	result.x = axis.x * sinf(angle / 2.0f);
	result.y = axis.y * sinf(angle / 2.0f);
	result.z = axis.z * sinf(angle / 2.0f);
	result.w = cosf(angle / 2.0f);

	return result;
}

Quaternion Slerp(const Quaternion& q0, const Quaternion& q1, float t) {
	Quaternion result;

	float dot = Dot({ q0.x,q0.y,q0.z }, { q1.x,q1.y,q1.z });
	if (dot < 0) {
		q0 = -1 * q0;
		dot = -dot;
	}

	return result;
}

void QuaternionScreenPrint(int x, int y, const Quaternion& q, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", q.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", q.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", q.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%.02f", q.w);
	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}

Quaternion operator+(const Quaternion& num1, const Quaternion& num2) {
	Quaternion num;

	num.w = num1.w + num2.w;
	num.x = num1.x + num2.x;
	num.y = num1.y + num2.y;
	num.z = num1.z + num2.z;

	return num;
}

Quaternion operator-(const Quaternion& num1, const Quaternion& num2) {
	Quaternion num;

	num.w = num1.w - num2.w;
	num.x = num1.x - num2.x;
	num.y = num1.y - num2.y;
	num.z = num1.z - num2.z;

	return num;
}

Quaternion operator*(const Quaternion& num1, const float num2) {
	Quaternion num;

	num.w = num1.w * num2;
	num.x = num1.x * num2;
	num.y = num1.y * num2;
	num.z = num1.z * num2;

	return num;
}

Quaternion operator*=(const Quaternion& num1, const float num2) {
	num1.w = num2;
	num1.x *= num1.x * num2;
	num1.y *= num1.y * num2;
	num1.z *= num1.z * num2;0.0
}
