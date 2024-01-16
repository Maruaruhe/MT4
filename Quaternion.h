#pragma once
#include <math.h>
#include	 <Novice.h>
#include "main.h"
#include "Vec3.h"
#include "Matrix.h"

struct Vector3;
struct Matrix4x4;

struct Quaternion {
	float x;
	float y;
	float z;
	float w;
};

Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
Quaternion IdentityQurtenion();
Quaternion Conjugate(const Quaternion& quartenion);
float Norm(const Quaternion& quartenion);
Quaternion Normalize(const Quaternion& quartenion);
Quaternion Inverse(const Quaternion& quartenion);

Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle);

void QuaternionScreenPrint(int x, int y, const Quaternion& q, const char* label);