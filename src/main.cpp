#include "../include/matrix.h"

int main()
{
    Matrix A(2, 2);

    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;

    A.print();

    return 0;
}