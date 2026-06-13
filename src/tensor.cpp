#include "../include/tensor.h"

Tensor::Tensor(const std::vector<int>& shape)
    : shape(shape)
{
    int totalSize = 1;

    for (int dim : shape)
    {
        totalSize *= dim;
    }

    data.resize(totalSize, 0.0f);
}

int Tensor::size() const
{
    return data.size();
}

const std::vector<int>& Tensor::getShape() const
{
    return shape;
}