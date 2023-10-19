#pragma once

#include <immintrin.h>
#include <cmath>


namespace simd
{
	struct alignas(16) Vec3
	{
		Vec3();
		Vec3(float x, float y, float z);
		Vec3(__m128 the_data);

		union
		{
			__m128 data_;
			struct
			{
				float x, y, z;
			};
			struct
			{
				float r, g, b;
			};
		};

	};

    //bool operator==(const Vec3& left, const Vec3& right) {
    //    __m128 result = _mm_cmpeq_ps(left.data_, right.data_);
    //    int mask = _mm_movemask_ps(result);
    //    return mask == 0xF;
    //}

    // 두 DataUnion 객체를 더하는 연산자 오버로딩
	Vec3 operator+(const Vec3& left, const Vec3& right);
}
