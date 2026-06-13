#include "../include/matrix.h"

#include <cassert>

int main()
{
    Matrix A(2, 2);
    Matrix B(2, 2);

    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;

    B(0, 0) = 5;
    B(0, 1) = 6;
    B(1, 0) = 7;
    B(1, 1) = 8;

    // Addition
    Matrix C = A + B;

    assert(C(0, 0) == 6);
    assert(C(0, 1) == 8);
    assert(C(1, 0) == 10);
    assert(C(1, 1) == 12);

    // Subtraction
    Matrix D = B - A;

    assert(D(0, 0) == 4);
    assert(D(0, 1) == 4);
    assert(D(1, 0) == 4);
    assert(D(1, 1) == 4);

    // Scalar multiplication
    Matrix E = A * 2.0f;

    assert(E(0, 0) == 2);
    assert(E(0, 1) == 4);
    assert(E(1, 0) == 6);
    assert(E(1, 1) == 8);

    // Matrix multiplication
    Matrix F = A.matmul(B);

    assert(F(0, 0) == 19);
    assert(F(0, 1) == 22);
    assert(F(1, 0) == 43);
    assert(F(1, 1) == 50);

    return 0;
}