#include "MT.h"
#include <algorithm>

void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
    Vector3 point[8];

    point[0] = { aabb.min.x, aabb.min.y, aabb.min.z };

    point[1] = { aabb.max.x, aabb.min.y, aabb.min.z };

    point[2] = { aabb.min.x, aabb.max.y, aabb.min.z };

    point[3] = { aabb.min.x, aabb.min.y, aabb.max.z };

    point[4] = { aabb.max.x, aabb.max.y, aabb.min.z };

    point[5] = { aabb.max.x, aabb.min.y, aabb.max.z };

    point[6] = { aabb.min.x, aabb.max.y, aabb.max.z };

    point[7] = { aabb.max.x, aabb.max.y, aabb.max.z };

    Segment segment[12] = { 0 };
    segment[0].origin = point[0];
    segment[0].diff = Subtract(point[1], point[0]);
    segment[1].origin = point[2];
    segment[1].diff = Subtract(point[4], point[2]);
    segment[2].origin = point[3];
    segment[2].diff = Subtract(point[5], point[3]);
    segment[3].origin = point[6];
    segment[3].diff = Subtract(point[7], point[6]);

    segment[4].origin = point[0];
    segment[4].diff = Subtract(point[3], point[0]);
    segment[5].origin = point[1];
    segment[5].diff = Subtract(point[5], point[1]);
    segment[6].origin = point[2];
    segment[6].diff = Subtract(point[6], point[2]);
    segment[7].origin = point[4];
    segment[7].diff = Subtract(point[7], point[4]);

    segment[8].origin = point[0];
    segment[8].diff = Subtract(point[2], point[0]);
    segment[9].origin = point[1];
    segment[9].diff = Subtract(point[4], point[1]);
    segment[10].origin = point[3];
    segment[10].diff = Subtract(point[6], point[3]);
    segment[11].origin = point[5];
    segment[11].diff = Subtract(point[7], point[5]);

    for (int i = 0; i < 12; i++) {
        DrawLine(segment[i], viewProjectionMatrix, viewportMatrix, color);
    }
}

bool IsCollision(const AABB& a, const AABB& b) {
    if ((a.min.x <= b.max.x && a.max.x >= b.min.x) &&
        (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
        (a.min.z <= b.max.z && a.max.z >= b.min.z)) {
        return true;
    }
    return false;
}

void DrawLine(const Segment& segment, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
    Vector3 start = Transform(Transform(segment.origin, viewProjectionMatrix), viewportMatrix);
    Vector3 end = Transform(Transform(Add(segment.origin, segment.diff), viewProjectionMatrix), viewportMatrix);
    Novice::DrawLine(int(start.x), int(start.y), int(end.x), int(end.y), color);
}

bool IsCollision(const AABB& aabb, const Segment& line) {

    //x
    float txMin = (aabb.min.x - line.origin.x) / line.diff.x;
    float txMax = (aabb.max.x - line.origin.x) / line.diff.x;

    float tNearX = Min(txMin, txMax);
    float tFarX = Max(txMin, txMax);

    //y
    float tyMin = (aabb.min.y - line.origin.y) / line.diff.y;
    float tyMax = (aabb.max.y - line.origin.y) / line.diff.y;

    float tNearY = Min(tyMin, tyMax);
    float tFarY = Max(tyMin, tyMax);


    //z
    float tzMin = (aabb.min.z - line.origin.z) / line.diff.z;
    float tzMax = (aabb.max.z - line.origin.z) / line.diff.z;

    float tNearZ = Min(tzMin, tzMax);
    float tFarZ = Max(tzMin, tzMax);

    float tMin = Max(Max(tNearX, tNearY), tNearZ);
    float tMax = Min(Min(tFarX, tFarY), tFarZ);

    if (tMin <= tMax) {
        return true;
    }
    else {
        return false;
    }
}

float Min(float a, float b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}
float Max(float a, float b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

bool colLineSegment(const AABB& box, const Segment& line) {
    Vector3 dir = Add(line.origin, line.diff) - line.origin;

    if (std::abs(dir.x) < 0.001f) {
        if (line.origin.x < box.min.x || line.origin.x > box.max.x) {
            return false;
        }
    }
    else {
        float invDir = 1.0f / dir.x;
        float t1 = (box.min.x - line.origin.x) * invDir;
        float t2 = (box.max.x - line.origin.x) * invDir;

        float tMin = Min(t1, t2);
        float tMax = Max(t1, t2);

        if (tMin > 1.0f || tMax < 0.0f) {
            return false;
        }
    }

    if (std::abs(dir.y) < 0.001f) {
        if (line.origin.y < box.min.y || line.origin.y > box.max.y) {
            return false;
        }
    }
    else {
        float invDir = 1.0f / dir.y;
        float t1 = (box.min.y - line.origin.y) * invDir;
        float t2 = (box.max.y - line.origin.y) * invDir;

        float tMin = Min(t1, t2);
        float tMax = Max(t1, t2);

        if (tMin > 1.0f || tMax < 0.0f) {
            return false;
        }
    }

    if (std::abs(dir.z) < 0.001f) {
        if (line.origin.z < box.min.z || line.origin.z > box.max.z) {
            return false;
        }
    }
    else {
        float invDir = 1.0f / dir.z;
        float t1 = (box.min.z - line.origin.z) * invDir;
        float t2 = (box.max.z - line.origin.z) * invDir;

        float tMin = Min(t1, t2);
        float tMax = Max(t1, t2);

        if (tMin > 1.0f || tMax < 0.0f) {
            return false;
        }
    }

    return true;
}