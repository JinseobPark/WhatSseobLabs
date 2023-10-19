#include <iostream>
#include "SIMDVec3.hpp"

std::ostream& operator<<(std::ostream& os,
	const simd::Vec3& v)
{
	os << "{" << v.x << ", " << v.y << ", "
		<< v.z << "}";

	return os;
}
int main(void)
{
	using namespace std;
	auto one = simd::Vec3{ 1.0f, 2.0f, 3.0f };
	auto two = simd::Vec3{ 2.0f, 2.0f, 2.0f };

	auto three = one + two;

	cout << one << " + " << two << ":\n";

	cout << "{x:" << three.x << ", y:" << three.y
		<< ", z:" << three.z << "}\n";
	cout << "{r:" << three.r << ", g:" << three.g
		<< ", b:" << three.b << "}\n";

	return 0;
}