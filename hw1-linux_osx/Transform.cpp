// Transform.cpp: implementation of the Transform class.

#include <iostream>
#include "Transform.h"
#include <cmath>


//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	// YOUR CODE FOR HW1 HERE
	const mat3 eye(1.0f);
	const auto ax = axis.x;
	const auto ay = axis.y;
	const auto az = axis.z;
	const mat3 a_at(ax*ax, ax*ay, ax*az,
		   ax*ay, ay*ay, ay*az,
		   ax*az, ay*az, az*az);
	const mat3 A = mat3(0, -az, ay,
				az, 0, -ax,
				-ay, ax, 0);
	const auto rad = glm::radians(degrees);
	const auto cos_rad = std::cos(rad);
	auto R = cos_rad*eye + (1 - cos_rad)* a_at + std::sin(rad)*A;

	// You will change this return call
	return R;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE 
	const auto RotEye = rotate(degrees, vec3(1, 0, 0));
	// std::cout << RotEye;
	eye = RotEye * eye;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
	// YOUR CODE FOR HW1 HERE

	// You will change this return call
	return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
