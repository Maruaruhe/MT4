#include "Quartenion.h"

Quartenion Multiply(const Quartenion& lhs, const Quartenion& rhs) {
	Quartenion result;
	result.x = lhs.w * rhs.x - lhs.z * rhs.y + lhs.y * rhs.z + lhs.x * rhs.w;
	result.y= lhs.z * rhs.x + lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w;
	result.z= -lhs.y * rhs.x + lhs.x * rhs.y + lhs.w * rhs.z + lhs.z * rhs.w;
	result.w= -lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z + lhs.w * rhs.w;

	return result;
}

Quartenion IdentityQurtenion() {
	return { 0.0f,0.0f,0.0f,1.0f };
}

Quartenion Conjugate(const Quartenion& quartenion) {
	return { -quartenion.x,-quartenion.y,-quartenion.z,quartenion.w };
}

float Norm(const Quartenion& quartenion) {
	float result = pow(quartenion.w, 2) + pow(quartenion.x, 2) + pow(quartenion.y, 2) + pow(quartenion.z, 2);
	result = sqrt(result);
	return result;
}
Quartenion Normalize(const Quartenion& quartenion) {
	Quartenion result;
	float norm = Norm(quartenion);
	result.x = quartenion.x / norm;
	result.y = quartenion.y / norm;
	result.z = quartenion.z / norm;
	result.w = quartenion.w / norm;

	return result;
}
Quartenion Inverse(const Quartenion& quartenion) {
	Quartenion result;

	Quartenion conjugate = Conjugate(quartenion);
	float norm = Norm(quartenion);

	result.x = conjugate.x / pow(norm, 2);
	result.y = conjugate.y / pow(norm, 2);
	result.z = conjugate.z / pow(norm, 2);
	result.w = conjugate.w / pow(norm, 2);

	return result;
}

void QuartenionScreenPrint(int x, int y, const Quartenion& q, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", q.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", q.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", q.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%.02f", q.w);
	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}