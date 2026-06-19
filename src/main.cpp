#include "../include/linear.h"

#include <iostream>

int main()
{
    Linear fc1(4, 3);

    Tensor input({1, 4});

    input.at({0,0}) = 1;
    input.at({0,1}) = 2;
    input.at({0,2}) = 3;
    input.at({0,3}) = 4;

    Tensor output =
        fc1.forward(input);

    output.printShape();

    return 0;
}