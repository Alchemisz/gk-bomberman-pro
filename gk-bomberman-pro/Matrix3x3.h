#pragma once
class Matrix3x3
{
	public:
		float mat[3][3];
		Matrix3x3(float mat[3][3]);
		float det();
};

