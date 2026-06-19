#include "../include/relu.h"

Tensor ReLU::forward(
    const Tensor& input
) const
{
    Tensor output =
        input;

    for (int i = 0; i < output.size(); i++)
    {
        if (output[i] < 0.0f)
        {
            output[i] = 0.0f;
        }
    }

    return output;
}