#include "stdafx.h"
#include "GTAmath.h"

#include <math.h>
#include <random>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>


#pragma region Vector31
Vector31::Vector31(float X, float Y, float Z)
	: x1(X), y1(Y), z1(Z)
{
}

Vector31::Vector31()
	: x1(0), y1(0), z1(0)
{
}

Vector31::Vector31(Vector31_t& xyz)
	: x1(xyz.x1), y1(xyz.y1), z1(xyz.z1)
{
}

void Vector31::clear()
{
	*this = Vector31();
}

Vector31 Vector31::Zero()
{
	return Vector31(0.0f, 0.0f, 0.0f);
}

Vector31 Vector31::One()
{
	return Vector31(1.0f, 1.0f, 1.0f);
}

Vector31 Vector31::WorldUp()
{
	return Vector31(0.0f, 0.0f, 1.0f);
}
Vector31 Vector31::WorldDown()
{
	return Vector31(0.0f, 0.0f, -1.0f);
}
Vector31 Vector31::WorldNorth()
{
	return Vector31(0.0f, 1.0f, 0.0f);
}
Vector31 Vector31::WorldSouth()
{
	return Vector31(0.0f, -1.0f, 0.0f);
}
Vector31 Vector31::WorldEast()
{
	return Vector31(1.0f, 0.0f, 0.0f);
}
Vector31 Vector31::WorldWest()
{
	return Vector31(-1.0f, 0.0f, 0.0f);
}

Vector31 Vector31::RelativeRight()
{
	return Vector31(1.0f, 0.0f, 0.0f);
}
Vector31 Vector31::RelativeLeft()
{
	return Vector31(-1.0f, 0.0f, 0.0f);
}
Vector31 Vector31::RelativeFront()
{
	return Vector31(0.0f, 1.0f, 0.0f);
}
Vector31 Vector31::RelativeBack()
{
	return Vector31(0.0f, -1.0f, 0.0f);
}
Vector31 Vector31::RelativeTop()
{
	return Vector31(0.0f, 0.0f, 1.0f);
}
Vector31 Vector31::RelativeBottom()
{
	return Vector31(0.0f, 0.0f, -1.0f);
}

float Vector31::Length() const
{
	return static_cast<float>(sqrt((x1 * x1) + (y1 * y1) + (z1 * z1)));
}
float Vector31::LengthSquared() const
{
	return (x1 * x1) + (y1 * y1) + (z1 * z1);
}

void Vector31::Normalize()
{
	float length = this->Length();
	if (length == 0.0f)
		return;
	float num = 1.0f / length;
	x1 *= num;
	y1 *= num;
	z1 *= num;
}

float Vector31::DistanceTo(const Vector31& position) const
{
	return (position - *this).Length();
}

Vector31 Vector31::Around(float distance) const
{
	return *this + Vector31::RandomXY() * distance;
}

Vector31 Vector31::PointOnCircle(float radius, float angleInDegrees) const
{
	Vector31 point;
	point.x1 = radius * cos(DegreeToRadian(angleInDegrees)) + this->x1;
	point.y1 = radius * sin(DegreeToRadian(angleInDegrees)) + this->y1;
	point.z1 = this->z1;

	return point;
}

void Vector31::PointsOnCircle(std::vector<Vector31>& results, float fullRadius, float angleDifference, float intervalDistance, bool includeCentre) const
{
	//results.clear();

	auto& origin = *this;
	Vector31 current;
	float u, d;

	if (includeCentre)
		results.push_back(origin);
	if (intervalDistance == 0.0f)
		return;

	for (u = 0.0f; u < 360.0f; u += angleDifference)
	{
		for (d = intervalDistance; d < fullRadius; d += intervalDistance)
		{
			current.x1 = d * cos(DegreeToRadian(u)) + origin.x1;
			current.y1 = d * sin(DegreeToRadian(u)) + origin.y1;
			//current.z = origin.z; // this will stay uniform as we're only considering the circle
			results.push_back(current);
		}
	}

}

Vector31 Vector31::PointOnSphere(float radius, float longitude, float latitude) const
{
	float u = DegreeToRadian(longitude);
	float v = DegreeToRadian(latitude);
	Vector31 point;
	point.x1 = radius * sin(u) * cos(v) + this->x1;
	point.y1 = radius * cos(u) * cos(v) + this->y1;
	point.z1 = radius * sin(v) + this->z1;

	return point;
}

Vector31_t Vector31::ToTypeStruct() const
{
	Vector31_t Return;
	Return.x1 = this->x1;
	Return.y1 = this->y1;
	Return.z1 = this->z1;
	return Return;
}

void Vector31::ToArray(float* out) const
{
	out[0] = this->x1;
	out[1] = this->y1;
	out[2] = this->z1;
}

std::array<float, 3> Vector31::ToArray() const
{
	return{ { this->x1, this->y1, this->z1 } };
}

bool Vector31::IsZero() const
{
	return (this->x1 == 0 && this->y1 == 0 && this->z1 == 0);
}

Vector31 Vector31::RandomXY()
{
	Vector31 v;
	v.x1 = get_random_float_in_range(0.0f, 1.0f) - 0.5f;
	v.y1 = get_random_float_in_range(0.0f, 1.0f) - 0.5f;
	v.z1 = 0.0f;
	v.Normalize();
	return v;
}
Vector31 Vector31::RandomXYZ()
{
	Vector31 v;
	v.x1 = get_random_float_in_range(0.0f, 1.0f) - 0.5f;
	v.y1 = get_random_float_in_range(0.0f, 1.0f) - 0.5f;
	v.z1 = get_random_float_in_range(0.0f, 1.0f) - 0.5f;
	v.Normalize();
	return v;
}

Vector31 Vector31::Add(Vector31 left, Vector31 right)
{
	return Vector31(left.x1 + right.x1, left.y1 + right.y1, left.z1 + right.z1);
}

Vector31 Vector31::Subtract(Vector31 left, Vector31 right)
{
	return Vector31(left.x1 - right.x1, left.y1 - right.y1, left.z1 - right.z1);
}

Vector31 Vector31::Multiply(Vector31 value, float scale)
{
	return Vector31(value.x1 * scale, value.y1 * scale, value.z1 * scale);
}

Vector31 Vector31::Modulate(Vector31 left, Vector31 right)
{
	return Vector31(left.x1 * right.x1, left.y1 * right.y1, left.z1 * right.z1);
}

Vector31 Vector31::Divide(Vector31 value, float scale)
{
	return Vector31(value.x1 / scale, value.y1 / scale, value.z1 / scale);
}

Vector31 Vector31::Negate(Vector31 value)
{
	return Vector31(-value.x1, -value.y1, -value.z1);
}

Vector31 Vector31::Clamp(Vector31 value, Vector31 min, Vector31 max)
{
	float x = value.x1;
	x = (x > max.x1) ? max.x1 : x;
	x = (x < min.x1) ? min.x1 : x;

	float y = value.y1;
	y = (y > max.y1) ? max.y1 : y;
	y = (y < min.y1) ? min.y1 : y;

	float z = value.z1;
	z = (z > max.z1) ? max.z1 : z;
	z = (z < min.z1) ? min.z1 : z;

	return Vector31(x, y, z);
}

Vector31 Vector31::Lerp(Vector31 start, Vector31 end, float amount)
{
	Vector31 vector;

	vector.x1 = start.x1 + ((end.x1 - start.x1) * amount);
	vector.y1 = start.y1 + ((end.y1 - start.y1) * amount);
	vector.z1 = start.z1 + ((end.z1 - start.z1) * amount);

	return vector;
}

Vector31 Vector31::Normalize(Vector31 vector)
{
	vector.Normalize();
	return vector;
}

float Vector31::Dot(Vector31 left, Vector31 right)
{
	return (left.x1 * right.x1 + left.y1 * right.y1 + left.z1 * right.z1);
}

Vector31 Vector31::Cross(Vector31 left, Vector31 right)
{
	Vector31 result;
	result.x1 = left.y1 * right.z1 - left.z1 * right.y1;
	result.y1 = left.z1 * right.x1 - left.x1 * right.z1;
	result.z1 = left.x1 * right.y1 - left.y1 * right.x1;
	return result;
}

Vector31 Vector31::Reflect(Vector31 vector, Vector31 normal)
{
	Vector31 result;
	float dot = ((vector.x1 * normal.x1) + (vector.y1 * normal.y1)) + (vector.z1 * normal.z1);

	result.x1 = vector.x1 - ((2.0f * dot) * normal.x1);
	result.y1 = vector.y1 - ((2.0f * dot) * normal.y1);
	result.z1 = vector.z1 - ((2.0f * dot) * normal.z1);

	return result;
}

Vector31 Vector31::Minimize(Vector31 value1, Vector31 value2)
{
	Vector31 vector;
	vector.x1 = (value1.x1 < value2.x1) ? value1.x1 : value2.x1;
	vector.y1 = (value1.y1 < value2.y1) ? value1.y1 : value2.y1;
	vector.z1 = (value1.z1 < value2.z1) ? value1.z1 : value2.z1;
	return vector;
}

Vector31 Vector31::Maximize(Vector31 value1, Vector31 value2)
{
	Vector31 vector;
	vector.x1 = (value1.x1 > value2.x1) ? value1.x1 : value2.x1;
	vector.y1 = (value1.y1 > value2.y1) ? value1.y1 : value2.y1;
	vector.z1 = (value1.z1 > value2.z1) ? value1.z1 : value2.z1;
	return vector;
}

Vector31 operator + (Vector31 const& left, Vector31 const& right)
{
	return Vector31(left.x1 + right.x1, left.y1 + right.y1, left.z1 + right.z1);
}

Vector31 operator - (Vector31 const& left, Vector31 const& right)
{
	return Vector31(left.x1 - right.x1, left.y1 - right.y1, left.z1 - right.z1);
}

Vector31 operator - (Vector31 const& value)
{
	return Vector31(-value.x1, -value.y1, -value.z1);
}

Vector31 operator * (Vector31 const& left, Vector31 const& right)
{
	return Vector31(left.x1 * right.x1, left.y1 * right.y1, left.z1 * right.z1);
}

Vector31 operator * (Vector31 const& value, float const& scale)
{
	return Vector31(value.x1 * scale, value.y1 * scale, value.z1 * scale);
}

Vector31 operator * (float const& scale, Vector31 const& value)
{
	return Vector31(value.x1 * scale, value.y1 * scale, value.z1 * scale);
}

Vector31 operator *= (Vector31& value, float const& scale)
{
	value.x1 *= scale;
	value.y1 *= scale;
	value.z1 *= scale;
	return value;
}

Vector31 operator / (Vector31 const& left, Vector31 const& right)
{
	return Vector31(left.x1 / right.x1, left.y1 / right.y1, left.z1 / right.z1);
}

Vector31 operator / (Vector31 const& value, float const& scale)
{
	return Vector31(value.x1 / scale, value.y1 / scale, value.z1 / scale);
}

Vector31 operator /= (Vector31& value, float const& scale)
{
	value.x1 /= scale;
	value.y1 /= scale;
	value.z1 /= scale;
	return value;
}

bool operator == (Vector31 const& left, Vector31 const& right)
{
	return Vector31::Equals(left, right);
}

bool operator != (Vector31 const& left, Vector31 const& right)
{
	return !Vector31::Equals(left, right);
}


std::string Vector31::ToString() const
{
	std::stringstream ss;
	ss << "X:" << std::setprecision(4) << std::fixed << this->x1;
	ss << " Y:" << std::setprecision(4) << std::fixed << this->y1;
	ss << " Z:" << std::setprecision(4) << std::fixed << this->z1;
	return ss.str();
}

bool Vector31::Equals(const Vector31& other) const
{
	return (x1 == other.x1 && y1 == other.y1 && z1 == other.z1);
}

bool Vector31::Equals(const Vector31_t& other) const
{
	return (x1 == other.x1 && y1 == other.y1 && z1 == other.z1);
}

bool Vector31::Equals(const Vector31& value1, const Vector31& value2)
{
	return (value1.x1 == value2.x1 && value1.y1 == value2.y1 && value1.z1 == value2.z1);
}


float Vector31::DistanceBetween(const Vector31& value1, const Vector31& value2)
{
	return (value1 - value2).Length();
}

Vector31 Vector31::RotationToDirection(const Vector31& rotation)
{
	float retz = rotation.z1 * 0.0174532924F; // Degree to radian
	float retx = rotation.x1 * 0.0174532924F;
	float absx = abs(cos(retx));
	return Vector31(-sin(retz) * absx, cos(retz) * absx, sin(retx));
}
Vector31 Vector31::DirectionToRotation(Vector31 direction)
{
	direction.Normalize();
	float xx = atan2(direction.z1, direction.y1) / 0.0174532924F; // Radian to degree
	float yy = 0;
	float zz = -atan2(direction.x1, direction.y1) / 0.0174532924F;
	return Vector31(xx, yy, zz);
}

#pragma endregion

#pragma region Vector21
Vector21::Vector21(float X, float Y)
	: x1(X), y1(Y)
{
}

Vector21::Vector21()
	: x1(0), y1(0)
{
}

void Vector21::clear()
{
	*this = Vector21(0.0f, 0.0f);
}

Vector21 Vector21::Zero()
{
	return Vector21(0.0f, 0.0f);
}

Vector21 Vector21::One()
{
	return Vector21(1.0f, 1.0f);
}

Vector21 Vector21::Up()
{
	return Vector21(0.0f, 1.0);
}

Vector21 Vector21::Down()
{
	return Vector21(0.0f, -1.0f);
}

Vector21 Vector21::Right()
{
	return Vector21(1.0f, 0.0f);
}

Vector21 Vector21::Left()
{
	return Vector21(-1.0f, 0.0f);
}

float Vector21::Length() const
{
	return sqrt((x1 * x1) + (y1 * y1));
}

Vector21 Vector21::PointOnCircle(float radius, float angleInDegrees) const
{
	Vector21 point;
	point.x1 = radius * cos(DegreeToRadian(angleInDegrees)) + this->x1;
	point.y1 = radius * sin(DegreeToRadian(angleInDegrees)) + this->y1;

	return point;
}

void Vector21::PointsOnCircle(std::vector<Vector21>& results, float fullRadius, float angleInDegrees, float intervalDistance, bool includeCentre) const
{
	//results.clear();

	auto& origin = *this;
	Vector21 current;
	float u, d;

	if (includeCentre) results.push_back(origin);
	if (intervalDistance == 0.0f) return;

	for (u = 0.0f; u < 360.0f; u += angleInDegrees)
	{
		for (d = intervalDistance; d < fullRadius; d += intervalDistance)
		{
			current.x1 = d * cos(DegreeToRadian(u)) + origin.x1;
			current.y1 = d * sin(DegreeToRadian(u)) + origin.y1;
			results.push_back(current);
		}
	}
}

float Vector21::LengthSquared() const
{
	return (x1 * x1) + (y1 * y1);
}

void Vector21::Normalize()
{
	float length = Length();
	if (length == 0.0f)
		return;
	float num = 1.0f / length;
	x1 *= num;
	y1 *= num;
}

float Vector21::DistanceTo(const Vector21& position) const
{
	return (position - *this).Length();
}

std::array<float, 2> Vector21::ToArray() const
{
	return{ {this->x1, this->y1} };
}

bool Vector21::IsZero() const
{
	return (this->x1 == 0 && this->y1 == 0);
}

Vector21 Vector21::RandomXY()
{
	Vector21 v;
	v.x1 = get_random_float_in_range(0.0f, 1.0f) - 0.5f;
	v.y1 = get_random_float_in_range(0.0f, 1.0f) - 0.5f;
	v.Normalize();
	return v;
}

Vector21 Vector21::Add(Vector21 const& left, Vector21 const& right)
{
	return Vector21(left.x1 + right.x1, left.y1 + right.y1);
}

Vector21 Vector21::Subtract(Vector21 const& left, Vector21 const& right)
{
	return Vector21(left.x1 - right.x1, left.y1 - right.y1);
}

Vector21 Vector21::Multiply(Vector21 const& value, float const& scale)
{
	return Vector21(value.x1 * scale, value.y1 * scale);
}

Vector21 Vector21::Modulate(Vector21 const& left, Vector21 const& right)
{
	return Vector21(left.x1 * right.x1, left.y1 * right.y1);
}

Vector21 Vector21::Divide(Vector21 const& value, float const& scale)
{
	return Vector21(value.x1 / scale, value.y1 / scale);
}

Vector21 Vector21::Negate(Vector21 const& value)
{
	return Vector21(-value.x1, -value.y1);
}

Vector21 Vector21::Clamp(Vector21 const& value, Vector21 const& min, Vector21 const& max)
{
	float ex = value.x1;
	ex = (ex > max.x1) ? max.x1 : ex;
	ex = (ex < min.x1) ? min.x1 : ex;

	float why = value.y1;
	why = (why > max.y1) ? max.y1 : why;
	why = (why < min.y1) ? min.y1 : why;

	return Vector21(ex, why);
}

Vector21 Vector21::Lerp(Vector21 const& start, Vector21 const& end, float const& amount)
{
	Vector21 vector;

	vector.x1 = start.x1 + ((end.x1 - start.x1) * amount);
	vector.y1 = start.y1 + ((end.y1 - start.y1) * amount);

	return vector;
}

Vector21 Vector21::Normalize(Vector21 value)
{
	value.Normalize();
	return value;
}

float Vector21::Dot(Vector21 const& left, Vector21 const& right)
{
	return (left.x1 * right.x1 + left.y1 * right.y1);
}

Vector21 Vector21::Reflect(Vector21 const& vector, Vector21 const& normal)
{
	Vector21 result;
	float dot = ((vector.x1 * normal.x1) + (vector.y1 * normal.y1));

	result.x1 = vector.x1 - ((2.0f * dot) * normal.x1);
	result.y1 = vector.y1 - ((2.0f * dot) * normal.y1);

	return result;
}

Vector21 Vector21::Minimize(Vector21 const& value1, Vector21 const& value2)
{
	Vector21 vector;
	vector.x1 = (value1.x1 < value2.x1) ? value1.x1 : value2.x1;
	vector.y1 = (value1.y1 < value2.y1) ? value1.y1 : value2.y1;
	return vector;
}

Vector21 Vector21::Maximize(Vector21 value1, Vector21 value2)
{
	Vector21 vector;
	vector.x1 = (value1.x1 > value2.x1) ? value1.x1 : value2.x1;
	vector.y1 = (value1.y1 > value2.y1) ? value1.y1 : value2.y1;
	return vector;
}

Vector21 operator + (Vector21 const& left, Vector21 const& right)
{
	return Vector21(left.x1 + right.x1, left.y1 + right.y1);
}

Vector21 operator - (Vector21 const& left, Vector21 const& right)
{
	return Vector21(left.x1 - right.x1, left.y1 - right.y1);
}

Vector21 operator - (Vector21 const& value)
{
	return Vector21(-value.x1, -value.y1);
}

Vector21 operator * (Vector21 const& vec, float const& scale)
{
	return Vector21(vec.x1 * scale, vec.y1 * scale);
}

Vector21 operator * (float const& scale, Vector21 const& vec)
{
	return vec * scale;
}

Vector21 operator / (Vector21 const& vec, float const& scale)
{
	return Vector21(vec.x1 / scale, vec.y1 / scale);
}

bool operator == (Vector21 const& left, Vector21 const& right)
{
	return Vector21::Equals(left, right);
}

bool operator != (Vector21 const& left, Vector21 const& right)
{
	return !Vector21::Equals(left, right);
}


std::string Vector21::ToString() const
{
	//return "X:" + std::to_string(x) + " Y:" + std::to_string(y);
	std::stringstream ss;
	ss << "X:" << std::setprecision(4) << std::fixed << this->x1;
	ss << " Y:" << std::setprecision(4) << std::fixed << this->y1;
	return ss.str();
}


bool Vector21::Equals(const Vector21& other) const
{
	return (x1 == other.x1 && y1 == other.y1);
}

bool Vector21::Equals(Vector21 value1, Vector21 value2)
{
	return (value1.x1 == value2.x1 && value1.y1 == value2.y1);
}
#pragma endregion


int get_random_int_in_range(int min, int max)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> u(min, max); // inclusive
	return u(rng);
}
float get_random_float_in_range(float min, float max)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	//boost::uniform_real<float> u(min, max);
	std::uniform_real_distribution<float> u(min, max); // inclusive
	//boost::variate_generator< boost::mt19937&, boost::uniform_real<float> > gen(rng, u);
	return u(rng);
	//return gen();
}

float DegreeToRadian(float angle)
{
	return angle * 0.0174532925199433F;
}
float RadianToDegree(float angle)
{
	return angle / 0.0174532925199433F;
}

Vector31 DegreeToRadian(const Vector31& angles)
{
	return Vector31(angles.x1 * 0.0174532925199433F, angles.y1 * 0.0174532925199433F, angles.z1 * 0.0174532925199433F);
}
float GetHeadingFromCoords(const Vector31& source, const Vector31& target)
{
	return atan2((target.y1 - source.y1), (target.x1 - source.x1));
}

