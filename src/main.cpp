#include "../include/matrix.h"

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

    Matrix C = A + B;

    C.print();

    return 0;
}