#include "SIMDVec3.hpp"

namespace simd
{
	Vec3::Vec3()
	{
		data_ = _mm_setzero_ps();
	}
	Vec3::Vec3(__m128 the_data)
		:data_(the_data)
	{}
	Vec3::Vec3(float x, float y, float z)
	{
		//data_ = _mm_set_ps(0.0f, z, y, x);
		data_ = _mm_setr_ps(x, y, z, 0.0f);
	}

	Vec3 operator+(const Vec3& left, const Vec3& right)
	{
		return Vec3{ _mm_add_ps(left.data_, right.data_) };
	}
}