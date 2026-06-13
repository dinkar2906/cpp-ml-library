#include <iostream>
#include "../include/tensor.h"

int main()
{
    Tensor t({2, 3, 4});

    std::cout << t.size() << std::endl;
}