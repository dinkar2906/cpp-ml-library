#include "../include/tensor.h"

#include <iostream>

int main()
{
    Tensor t({2, 3, 4});

    t[0] = 10;
    t[1] = 20;

    t.printShape();

    std::cout << "Total elements: "
              << t.size()
              << '\n';

    std::cout << t[0] << '\n';
    std::cout << t[1] << '\n';

    return 0;
}