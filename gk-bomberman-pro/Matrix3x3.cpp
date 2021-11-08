#include "Matrix3x3.h"

Matrix3x3::Matrix3x3(float mat[3][3])
{
    for (int rows = 0; rows < 3; rows++)
    {
        for (int columns = 0; columns < 3; columns++)
        {
            this->mat[rows][columns] = mat[rows][columns];
        }
    }
}

float Matrix3x3::det()
{
    float x = ((mat[1][1] * mat[2][2]) - (mat[2][1] * mat[1][2]));
    float y = ((mat[1][0] * mat[2][2]) - (mat[2][0] * mat[1][2]));
    float z = ((mat[1][0] * mat[2][1]) - (mat[2][0] * mat[1][1]));

    return ((mat[0][0] * x) - (mat[0][1] * y) + (mat[0][2] * z));
}
