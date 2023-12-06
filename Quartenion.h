#pragma once

struct Quartenion {
	float x;
	float y;
	float z;
	float w;
};

Quartenion Multiply(const Quartenion& lhs, const Quartenion& rhs);
Quartenion IdentityQurtenion();
Quartenion Conjugate(const Quartenion& qurtenion);
float Norm(const Quartenion& qurtenion);
Quartenion Normalize(const Quartenion& qurtenion);
Quartenion Inverse(const Quartenion& qurtenion);