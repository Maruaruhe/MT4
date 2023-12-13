#pragma once
#include <math.h>
#include	 <Novice.h>
#include "main.h"

struct Quartenion {
	float x;
	float y;
	float z;
	float w;
};

Quartenion Multiply(const Quartenion& lhs, const Quartenion& rhs);
Quartenion IdentityQurtenion();
Quartenion Conjugate(const Quartenion& quartenion);
float Norm(const Quartenion& quartenion);
Quartenion Normalize(const Quartenion& quartenion);
Quartenion Inverse(const Quartenion& quartenion);

void QuartenionScreenPrint(int x, int y, const Quartenion& q, const char* label);