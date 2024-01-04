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
	const auto RotEye = rotate(-degrees, up);
	eye = RotEye * eye;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE
	static float up_angle = 0;
	up_angle += degrees;

	auto axis = glm::normalize(glm::cross(up, eye));
	const auto RotEye = rotate(degrees, axis);
	// std::cout << RotEye;
	eye = RotEye * eye;
	std::cout << up_angle << "º\n";
	up = RotEye * up;
}

// Your implementation of the glm::lookAt matrix
using namespace glm;
mat4 Transform::lookAt(vec3 eye, vec3 up)
{	
	// YOUR CODE FO HW1 HERE
	vec3 zaxis = normalize(eye);
	vec3 yaxis = normalize(up);
	vec3 xaxis = cross(yaxis, zaxis);

	// zaxis = -zaxis;

	mat4 viewMatrix(
		xaxis.x, xaxis.y, xaxis.z, -dot(xaxis, eye),
		yaxis.x, yaxis.y, yaxis.z, -dot(yaxis, eye),
		zaxis.x, zaxis.y, zaxis.z, -dot(zaxis, eye),
		0, 0, 0, 1);

	return glm::transpose(viewMatrix);
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
