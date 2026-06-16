#include "../include/tensor.h"

#include <iostream>

int main()
{
    Tensor A({2, 3});

    for (int i = 0; i < A.size(); i++)
    {
        A[i] = i + 1;
    }

    Tensor B = A * 2.0f;

    A.printShape();

    for (int i = 0; i < B.size(); i++)
    {
        std::cout << B[i] << " ";
    }

    std::cout << '\n';

    B.reshape({3, 2});

    B.printShape();

    return 0;
}