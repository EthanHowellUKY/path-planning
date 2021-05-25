
#include <gtest/gtest.h>
#include "PathPlanning/Matrix.h"

// CASE VARIABLES
Matrix m1 = Matrix({
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0}
});

Matrix m2 = Matrix({
    {1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0},
});

// SOLUTION VARIABLES
Matrix addition_solution = Matrix({
    {2.0, 1.0, 1.0},
    {1.0, 2.0, 1.0},
    {1.0, 1.0, 2.0}
});

Matrix subtraction_solution_m1subm2 = Matrix({
    {0.0, -1.0, -1.0},
    {-1.0, 0.0, -1.0},
    {-1.0, -1.0, 0.0}
});

Matrix subtraction_solution_m2subm1 = Matrix({
    {0.0, 1.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 1.0, 0.0}
});

TEST(MatrixTest, Addition)
{
    ASSERT_EQ(addition_solution, m1+m2);
}

TEST(MatrixTest, Subtraction)
{
    ASSERT_EQ(subtraction_solution_m1subm2, m1-m2);
    ASSERT_EQ(subtraction_solution_m2subm1, m2-m1);
}

TEST(MatrixTest, Transpose)
{
    ASSERT_EQ(m1, m1.transpose());
}
